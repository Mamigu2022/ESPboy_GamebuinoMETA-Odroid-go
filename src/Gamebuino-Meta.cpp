/*
This file is part of the Gamebuino-Meta library,
Copyright (c) Aadalie 2014, 2016-2017
 - Aurelien Rodot
 - Sorunome
*/

#include "Gamebuino-Meta.h"


const uint8_t PROGMEM gamebuinoLogo[] = {80,10,
	0b00111100,0b00111111,0b00111111,0b11110011,0b11110011,0b11110011,0b00110011,0b00111111,0b00111111,0b00011100,
	0b00111100,0b00111111,0b00111111,0b11110011,0b11110011,0b11110011,0b00110011,0b00111111,0b00111111,0b00100110,
	0b00110000,0b00110011,0b00110011,0b00110011,0b00000011,0b00110011,0b00110011,0b00110011,0b00110011,0b00100110,
	0b00110000,0b00110011,0b00110011,0b00110011,0b00000011,0b00110011,0b00110011,0b00110011,0b00110011,0b00101010,
	0b00110011,0b00111111,0b00110011,0b00110011,0b11110011,0b11000011,0b00110011,0b00110011,0b00110011,0b00011100,
	0b00110011,0b00111111,0b00110011,0b00110011,0b11110011,0b11000011,0b00110011,0b00110011,0b00110011,0b00000000,
	0b00110011,0b00110011,0b00110011,0b00110011,0b00000011,0b00110011,0b00110011,0b00110011,0b00110011,0b00000000,
	0b00110011,0b00110011,0b00110011,0b00110011,0b00000011,0b00110011,0b00110011,0b00110011,0b00110011,0b00000000,
	0b00111111,0b00110011,0b00110011,0b00110011,0b11110011,0b11110011,0b11110011,0b00110011,0b00111111,0b00000000,
	0b00111111,0b00110011,0b00110011,0b00110011,0b11110011,0b11110011,0b11110011,0b00110011,0b00111111,0b00000000,
};


namespace Gamebuino_Meta {

int8_t tone_identifier = -1;
Gamebuino* gbptr = nullptr;

Gamebuino::Gamebuino(){
  gbptr = this;
};



void Gamebuino::begin() {  
  //Serial.begin(115200); 
  
  dac.begin(MCP4725address);
  dac.setVoltage(0, false);
    
  timePerFrame = 40; //25 FPS
  frameEndFlag = true;
  mcp.begin(MCP23017address);
  delay(100);
  mcp.pinMode(CSTFTPIN, OUTPUT);
  delay(100);
  mcp.digitalWrite(CSTFTPIN, LOW);
  buttons.begin(&mcp);
  
  tft.init();
  tft.setRotation(Rotation::left);	 

  tft.fillScreen(TFT_BLACK);
  tft.drawXBitmap(30,24, g_espboy, 68, 64, TFT_YELLOW);
  tft.setTextSize(1);
  tft.setTextColor(TFT_YELLOW);
  tft.drawString (PSTR("Gamebuino META"), 21, 102);

  for(uint8_t i=0; i<200; i++) {dac.setVoltage(i*10, false); delay(10);}
  dac.setVoltage(4095, true);

  //Check OTA2
/* 
  if (getKeys()&PAD_ACT || getKeys()&PAD_ESC) { 
    //Serial.println();
    //Serial.println(ESP.getFreeHeap()); 
    display.delFrameHandler(); 
    //Serial.println(ESP.getFreeHeap()); 
    terminalGUIobj = new ESPboyTerminalGUI(&tft._tft, &mcp);
    OTA2obj = new ESPboyOTA2(terminalGUIobj);
    OTA2obj -> checkOTA();
  }
 */ 
  WiFi.mode(WIFI_OFF); 

  #if USE_LITTLEFS
  LittleFS.begin();
  #endif
  
  myLED.begin(&mcp);
  myLED.setRGB(5,0,0); delay(200);
  myLED.setRGB(0,5,0); delay(200);
  myLED.setRGB(0,0,5); delay(200);
  myLED.setRGB(0,0,0);

  
  display.fill(Color::black);
  display.fontSize = SYSTEM_DEFAULT_FONT_SIZE;
  
  updateDisplay();
  
  startScreen();
  sound.begin();
  save.begin();	
  display.clear();
  inited = true;
}


void Gamebuino::getDefaultName(char* string){
   strcpy(string, "ESPboy");
}


uint16_t Gamebuino::createColor(uint8_t r, uint8_t g, uint8_t b) {

   uint16_t rr = (r << 8) & 0xF800;
   uint16_t gg = (g << 3) & 0x07E0;
   uint16_t bb = (b >> 3) & 0x001F;
    
   return (rr | gg | bb);
}



void Gamebuino::drawLogo(Graphics& g, int8_t x, int8_t y, uint8_t scale) {
	Image logo(78, 10, ColorMode::index);
	logo.clear();
	logo.drawBitmap(-2, 0, gamebuinoLogo);
	g.drawImage(x*scale, y*scale, logo, 78*scale, 10*scale);
}



void Gamebuino::startScreen(){
	int8_t i = 24;
	update();
	while (i) {
		while(!update());
		i--;
		display.clear();
		display.fontSize = SYSTEM_DEFAULT_FONT_SIZE;
		drawLogo(display, (display._width-78)/2, min(0, i-10), 1);
	}
	update();
}


bool Gamebuino::update() {
    delay(0);
	if (((nextFrameMillis - millis()) > timePerFrame) && frameEndFlag) { //if time to render a new frame is reached and the frame end has ran once
		nextFrameMillis = millis() + timePerFrame;
		frameCount++;
		frameEndFlag = false;
		frameStartMicros = micros();
		buttons.update();
		return true;
	}
	
	if (frameEndFlag) { return false; }
	sound.update(); // update sound stuff once per frame
	gui.updatePopup();
    updateDisplay();
	frameDurationMicros = micros() - frameStartMicros;
	frameEndFlag = true; // we are at end of frame
	return false;
}


void Gamebuino::waitForUpdate() {
	while(!update());
}



void IRAM_ATTR Gamebuino::updateDisplay() {
#if DISPLAY_MODE != DISPLAY_MODE_INDEX 
  tft.drawImage(0, 0, (Image&)display, 128, 128);
#else
  static bool flagNewBuf = false;
  static uint16_t *bufPointer;
  static uint16_t *bufline;
  
  if(flagNewBuf == false){
    flagNewBuf = true;
    bufline = (uint16_t *)malloc(256);
  };
  
  tft.setAddrWindow(0, 0, 128, 128); 
  
  uint8_t getPixelX, setPixelX;
  for (uint8_t j=0; j<128; j++){
    getPixelX = 0;
    bufPointer = bufline;
    for (uint8_t k=0; k<32; k++){	
      *bufPointer++ = (uint16_t)display.getPixelColor(getPixelX++,j);
      *bufPointer++ = (uint16_t)display.getPixelColor(getPixelX++,j);
      *bufPointer++ = (uint16_t)display.getPixelColor(getPixelX++,j);
      *bufPointer++ = tft.colorsBlend((uint16_t)display.getPixelColor(getPixelX++,j), (uint16_t)display.getPixelColor(getPixelX++,j));    
    }
    tft.pushColors(bufline, 128);}
#endif
}

void Gamebuino::setFrameRate(uint8_t fps) {
	timePerFrame = 1000 / fps;
}

void Gamebuino::pickRandomSeed(){}

uint8_t Gamebuino::getCpuLoad(){
	return(frameDurationMicros/(10*timePerFrame));
}

uint16_t Gamebuino::getFreeRam() {
	return ESP.getFreeHeap();
}


uint8_t Gamebuino::getTimePerFrame() {
	return timePerFrame;
}

void Gamebuino::setScreenRotation(Rotation r) {
	tft.setRotation(r);
}

Rotation Gamebuino::getScreenRotation() {
	return tft.getRotation();
}

uint8_t Gamebuino::getKeys() { return (~mcp.readGPIOAB() & 255); }


bool Gamebuino::collidePointRect(int16_t x1, int16_t y1 ,int16_t x2 ,int16_t y2, int16_t w, int16_t h){
	return collide.pointRect(x1, y1, x2, y2, w, h);
}

bool Gamebuino::collideRectRect(int16_t x1, int16_t y1, int16_t w1, int16_t h1 ,int16_t x2 ,int16_t y2, int16_t w2, int16_t h2){
	return collide.rectRect(x1, y1, w1, h1, x2, y2, w2, h2);
}

bool Gamebuino::collideBitmapBitmap(int16_t x1, int16_t y1, const uint8_t* b1, int16_t x2, int16_t y2, const uint8_t* b2){
  int16_t w1 = b1[0];
  int16_t h1 = b1[1];
  int16_t w2 = b2[0];
  int16_t h2 = b2[1];

  if(collideRectRect(x1, y1, w1, h1, x2, y2, w2, h2) == false){
    return false;
  }
  
  int16_t xmin = (x1>=x2)? 0 : x2-x1;
  int16_t ymin = (y1>=y2)? 0 : y2-y1;
  int16_t xmax = (x1+w1>=x2+w2)? x2+w2-x1 : w1;
  int16_t ymax = (y1+h1>=y2+h2)? y2+h2-y1 : h1;

  for(uint8_t y = ymin; y < ymax; y++){
    for(uint8_t x = xmin; x < xmax; x++){
      if(display.getBitmapPixel(b1, x, y) && display.getBitmapPixel(b2, x1+x-x2, y1+y-y2)){
        return true;
      }
    }
  }

  return false;
}


} // namespace Gamebuino_Meta


Gamebuino gb;

void tone(uint32_t outputPin, uint32_t frequency, uint32_t duration) {
	if (Gamebuino_Meta::gbptr) {
		if (Gamebuino_Meta::tone_identifier != -1) {
			Gamebuino_Meta::gbptr->sound.stop(Gamebuino_Meta::tone_identifier);
		}
		Gamebuino_Meta::tone_identifier = Gamebuino_Meta::gbptr->sound.tone(frequency, duration);
	}
}

void noTone(uint32_t outputPin) {
	if (Gamebuino_Meta::gbptr) {
		Gamebuino_Meta::gbptr->sound.stop(Gamebuino_Meta::tone_identifier);
		Gamebuino_Meta::tone_identifier = -1;
	}
}
