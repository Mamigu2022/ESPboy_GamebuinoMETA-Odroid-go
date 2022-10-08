/*
   Copyright (C) 2016 Ignacio Vina (@igvina)

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

#include "Customlib.h"


extern uint8_t rand8();

// store current and previous buttons state for frame based button events
// you should be using nextFrame() in almost all cases, not calling this
// directly
#ifdef ARDUBOY_2
Customlib::Customlib(Arduboy2 &a) {
  arduboy = &a;
  sBuffer = arduboy->getBuffer();
}
#endif

#ifdef GAMEBUINO_META
Customlib::Customlib() {
}
#endif


void Customlib::poll() {
  previousButtonState = currentButtonState;
#ifdef ARDUBOY_2
  currentButtonState = arduboy->buttonsState();
#endif
}
// returns true if a button has just been pressed
// if the button has been held down for multiple frames this will return
// false.  You should only use this to poll a single button.
boolean Customlib::justPressed(uint8_t button) {
  return (!(previousButtonState & button) && (currentButtonState & button));
}

boolean Customlib::pressed(uint8_t buttons) {
  return (currentButtonState & buttons) == buttons;
}

boolean Customlib::notPressed(uint8_t buttons) {
  return (currentButtonState & buttons) == 0;
}

#ifdef ARDUBOY_2
void Customlib::drawBitmap(int8_t x, int8_t y, const uint8_t *bitmap, uint8_t w, uint8_t h, uint8_t mirror) {
  drawMaskedBitmap(x,  y, bitmap, NULL, w,  h, mirror);
}

void Customlib::drawBitmap(int8_t x, int8_t y, const uint8_t *bitmap, uint8_t w, uint8_t h, uint8_t maxW, uint8_t mirror) {
  // no need to dar at all of we're offscreen
  drawBitmap(x, y, bitmap, w, h, mirror);
  if (maxW > w) maxW = w;
  arduboy->fillRect(x + maxW, y, w - maxW , h, BLACK);
}

#endif  

#ifdef GAMEBUINO_META

void Customlib::drawBitmap(int16_t x, int16_t y, Image *bitmap, int16_t w, int16_t h, uint8_t mirror) {
  gb.display.drawImage(x, y, *bitmap, mirror? -w : w , h);
}

void Customlib::drawBitmap(int16_t x, int16_t y, Image *bitmap, int16_t w, int16_t h, uint8_t maxW, uint8_t mirror) {
  gb.display.drawImage(x, y, *bitmap, 0, 0, maxW, h);
}

void Customlib::drawMaskedBitmap(int16_t x, int16_t y, Image *bitmap, const uint8_t *mask, int16_t w, int16_t h, uint8_t mirror) {
  gb.display.drawImage(x, y, *bitmap, mirror? -w : w , h);
}
#endif  

#ifdef ARDUBOY_2

void Customlib::drawMaskedBitmap(int8_t x, int8_t y, const uint8_t *bitmap, const uint8_t *mask, uint8_t w, uint8_t h, uint8_t mirror) {
  // no need to dar at all of we're offscreen
  if (x + w < 0 || x > WIDTH - 1 || y + h < 0 || y > HEIGHT - 1)
    return;

  // Kudos to Team a.r.g for this ultra fast drawBitmap mode (added horizontal mirror mode)
  if (bitmap == NULL)
    return;

  // xOffset technically doesn't need to be 16 bit but the math operations
  // are measurably faster if it is
  uint16_t xOffset, ofs;
  int8_t yOffset = abs(y) % 8;
  int8_t sRow = y / 8;
  uint8_t loop_h, start_h, rendered_width;

  if (y < 0 && yOffset > 0) {
    sRow--;
    yOffset = 8 - yOffset;
  }

  // if the left side of the render is offscreen skip those loops
  if (x < 0) {
    xOffset = abs(x);
  } else {
    xOffset = 0;
  }

  // if the right side of the render is offscreen skip those loops
  if (x + w > WIDTH - 1) {
    rendered_width = ((WIDTH - x) - xOffset);
  } else {
    rendered_width = (w - xOffset);
  }

  // if the top side of the render is offscreen skip those loops
  if (sRow < -1) {
    start_h = abs(sRow) - 1;
  } else {
    start_h = 0;
  }

  loop_h = h / 8 + (h % 8 > 0 ? 1 : 0); // divide, then round up

  // if (sRow + loop_h - 1 > (HEIGHT/8)-1)
  if (sRow + loop_h > (HEIGHT / 8)) {
    loop_h = (HEIGHT / 8) - sRow;
  } 

  // prepare variables for loops later so we can compare with 0
  // instead of comparing two variables
  loop_h -= start_h;

  sRow += start_h;
  ofs = (sRow * WIDTH) + x + xOffset;
  if (mirror)  ofs += rendered_width - 1;
  uint8_t *bofs = (uint8_t *)bitmap + (start_h * w) + xOffset;
  uint8_t *mask_ofs;
  if (mask != 0) {
    mask_ofs = (uint8_t *)mask + (start_h * w) + xOffset;
    if (mirror)  mask_ofs += rendered_width - 1;
  }

  uint8_t data;

  uint8_t mul_amt = 1 << yOffset;
  uint16_t mask_data;
  uint16_t bitmap_data;

  for (uint8_t a = 0; a < loop_h; a++) {
    for (uint8_t iCol = 0; iCol < rendered_width; iCol++) {
      // NOTE: you might think in the yOffset==0 case that this results
      // in more effort, but in all my testing the compiler was forcing
      // 16-bit math to happen here anyways, so this isn't actually
      // compiling to more code than it otherwise would. If the offset
      // is 0 the high part of the word will just never be used.

      // load data and bit shift
      // mask needs to be bit flipped
      mask_data = ~(pgm_read_byte(mask_ofs) * mul_amt);
      bitmap_data = pgm_read_byte(bofs) * mul_amt;

      if (sRow >= 0) {
        data = sBuffer[ofs];
        data &= (uint8_t)(mask_data);
        data |= (uint8_t)(bitmap_data);
        sBuffer[ofs] = data;
      }
      if (yOffset != 0 && sRow < 7) {
        data = sBuffer[ofs + WIDTH];
        data &= (*((unsigned char *) (&mask_data) + 1));
        data |= (*((unsigned char *) (&bitmap_data) + 1));
        sBuffer[ofs + WIDTH] = data;
      }
      if (mirror) {
        ofs--;
        mask_ofs--;
      } else {
        ofs++;
        mask_ofs++;
      }
      bofs++;
    }
    sRow++;
    bofs += w - rendered_width;

    if (mirror) {
      mask_ofs += w +  rendered_width;
      ofs += WIDTH + rendered_width;
    } else {
      mask_ofs += w - rendered_width;
      ofs += WIDTH - rendered_width;
    }
  }
}

#endif  

void Customlib::drawNoiseCircle(uint8_t x0, uint8_t y0, uint8_t r)
{
  
  int16_t f = 1 - r;
  int16_t ddF_x = 1;
  int16_t ddF_y = -2 * r;
  int16_t x = 0;
  int16_t y = r;
  const uint8_t SHIELD_NOISE = 2;
  
#ifdef ARDUBOY_2   
  arduboy->drawPixel(x0, y0-r, WHITE);
#endif  

#ifdef GAMEBUINO_META   
  gb.display.setColor(WHITE);
  gb.display.drawPixel(x0, y0-r);
#endif  
 

  while (x<y)
  {
    if (f >= 0)
    {
      y--;
      ddF_y += 2;
      f += ddF_y;
    }

    x++;
    ddF_x += 2;
    f += ddF_x;

    int8_t noise[4];
  
    for (uint8_t i = 0; i < 4; i++){

    for (uint8_t j = 0; j < 4; j++){
            noise[j] = - SHIELD_NOISE / 2 + rand8()%SHIELD_NOISE;  
    }

    int8_t xMod = x;
    int8_t yMod = y;

    int8_t xMod2 = x;
    int8_t yMod2 = y;

    if (i > 1){
      xMod = -x;
      yMod = -y;
    }

    
    if (i%2 == 0){
      xMod2 = -x;
      yMod2 = -y;
    }

#ifdef ARDUBOY_2  
    arduboy->drawPixel(x0 + xMod + noise[0], y0 + yMod2 + noise[1], WHITE);
    arduboy->drawPixel(x0 + yMod + noise[2], y0 + xMod2 + noise[3], WHITE);
#endif  

#ifdef GAMEBUINO_META   
    gb.display.drawPixel(x0 + xMod + noise[0], y0 + yMod2 + noise[1]);
    gb.display.drawPixel(x0 + yMod + noise[2], y0 + xMod2 + noise[3]);
#endif  
    }
  }
}

void Customlib::display() {

#ifdef ARDUBOY_2
  //arduboy->paintScreen(sBuffer);
  arduboy->display();
#endif
#ifdef GAMEBUINO_META
  gb.updateDisplay();
#endif  
#ifdef SCREEN_CAST
  Serial.write(sBuffer, 128 * 64 / 8);
#endif
}

void Customlib::print (uint8_t number) {

#ifdef ARDUBOY_2
  arduboy->print(number);
#endif  

#ifdef GAMEBUINO_META
  gb.display.setFont(font5x7);
  gb.display.setColor(WHITE);
  gb.display.print(number);
#endif  
}


void Customlib::print (const char* text, uint8_t x, uint8_t y) {

#ifdef ARDUBOY_2
  arduboy->setCursor(x, y);
  int textLength = strlen_P(text);
  uint8_t i;
  char myChar;
  for (i = 0; i < textLength; i++) {
    myChar =  pgm_read_byte(text + i);
    arduboy->print(myChar);
  }
#endif  

#ifdef GAMEBUINO_META
  gb.display.cursorX = x;
  gb.display.cursorY = y;
  gb.display.setFont(font5x7);
  gb.display.setColor(WHITE);
  gb.display.print(text);
#endif  
}


void Customlib::addNoise(int noise) {

  createNoiseArray(noise);

#ifdef ARDUBOY_2  
  for (int i = 0 ; i < WIDTH * HEIGHT / 8 ; i++) {
    sBuffer[i] ^= noiseArray[rand8() % NOISE_SIZE];
  }
#endif 

#ifdef GAMEBUINO_META
  sBuffer = (uint8_t*)gb.display._buffer;
  for (int i = 0 ; i < WIDTH / 2 * HEIGHT ; i++) { 
    sBuffer[i]^= noiseArray[rand8() % NOISE_SIZE];
  }
#endif
}

void Customlib::createNoiseArray(int noise) {

  if (noise == noiseLevel) return;

  // Recreate noise array if noise level changes
  int i, j;
  noiseLevel = noise;
  memset(noiseArray, 0, sizeof noiseArray);
  for (i = 0; i < NOISE_SIZE; i++) {

#ifdef ARDUBOY_2
    for (j = 0; j < 8; j++ ) {
      noiseArray[i] |= ((rand8() % noise == 0) ? (B00000001 << j) : 0);
    }
#endif 

#ifdef GAMEBUINO_META
    for (j = 0; j < 2; j++ ) {
      noiseArray[i] |= ((rand8() % noise == 0) ? (B00000111 << (4 * j)) : 0);
    }
#endif 
  }
}

void Customlib::mirrorScreen() {

  uint16_t pos1, pos2;
  uint8_t temp;
  uint16_t i,j;

#ifdef ARDUBOY_2
  for (i = 0 ; i < WIDTH / 2 * HEIGHT / 8 ; i++) {
    pos1 = (((2 * i) / WIDTH) * WIDTH) + (uint8_t) i % (WIDTH / 2);
    pos2 = (((2 * i) / WIDTH) * WIDTH) + (uint8_t)(WIDTH - 1 - i % (WIDTH / 2));
    temp = sBuffer[pos1];
    sBuffer[pos1] = sBuffer[pos2];
    sBuffer[pos2] = temp;
  }
#endif

#ifdef GAMEBUINO_META
  sBuffer = (uint8_t*)gb.display._buffer;
  for (j = 0 ; j < HEIGHT ; j++) {
    for (i = 0 ; i < WIDTH / 4;i++) {
      pos1 = i + j * (WIDTH / 2);
      pos2 = (WIDTH/2 - i - 1) + j * (WIDTH / 2);
      temp = (sBuffer[pos1] << 4) | (sBuffer[pos1] >> 4); 
      sBuffer[pos1] =(sBuffer[pos2] << 4) | (sBuffer[pos2] >> 4); 
      sBuffer[pos2] = temp;
    }
  }
#endif
}

bool Customlib::everyXFrames(uint8_t frames){
#ifdef ARDUBOY_2
  return arduboy->everyXFrames(frames);
#endif

#ifdef GAMEBUINO_META
  return gb.frameCount % frames == 0;
#endif

}

void Customlib::setFrameRate(int rate) {
#ifdef ARDUBOY_2
  arduboy->setFrameRate(rate);
#endif

#ifdef GAMEBUINO_META
  gb.setFrameRate(rate);
#endif
}

void Customlib::invert(boolean inv){

#ifdef ARDUBOY_2
  return arduboy->invert(inv);
#endif

#ifdef GAMEBUINO_META
  if (inv){
    sBuffer = (uint8_t*)gb.display._buffer;
    for (int i = 0 ; i < HEIGHT * WIDTH / 2; i++) {
      sBuffer[i]^= 0x77;
    }
  }
#endif  
}
