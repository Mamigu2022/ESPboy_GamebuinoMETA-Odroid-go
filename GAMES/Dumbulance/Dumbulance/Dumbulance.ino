// "Dumbulance" by Juice Lizard
// Ludum Dare 46 "Keep it alive"
// 18-04-2020 to 20-04-2020

#include <Gamebuino-Meta.h>

const PROGMEM uint8_t ambulanceData[] = {18, 13, 1, 0, 1, 0x0E, 1, 0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00, 0xee,0xee, 0x07,0x77, 0x77,0x77, 0x77,0x70, 0x80,0xee, 0xee,0x08, 0x67,0x77, 0x77,0x76, 0x80,0x00, 0x0e,0xee, 0x07,0x77, 0x87,0x75, 0x57,0x70, 0x57,0x00, 0xee,0x07, 0x78,0x88, 0x75,0x57, 0x76,0x55, 0x70,0x0e, 0x07,0x77, 0x87,0x77, 0x77,0x76, 0x55,0x57, 0x00,0x07, 0x77,0x77, 0x77,0x77, 0x70,0x77, 0x77,0x70, 0x08,0x77, 0x77,0x77, 0x76,0x70, 0x76,0x77, 0x90,0x08, 0x66,0x66, 0x67,0x77, 0x70,0x77, 0x77,0x90, 0x06,0x65, 0x55,0x66, 0x66,0x60, 0x75,0x55, 0x70,0x00, 0x05,0x65, 0x00,0x00, 0x00,0x05, 0x65,0x00, 0xee,0x00, 0x50,0x0e, 0xee,0xee, 0x00,0x50, 0x0e,0xee, 0xe0,0x00, 0xee,0xee, 0xee,0xe0, 0x00,0x00ee};
Image ambulance = Image(ambulanceData);

const PROGMEM uint8_t gyrophareData[] = {2, 1, 6, 0, 2, 0x0E, 1, 0x8e, 0x9e,0xae, 0x7e,0xae, 0x9e};
Image gyrophare = Image(gyrophareData);

const PROGMEM uint8_t wheelData[] = {4, 3, 4, 0, 1, 0x0E, 1, 0x6e, 0xee,0xee, 0xee,0xee, 0x5e,0xe6, 0xee,0xee, 0xee,0xe6, 0xee,0xee, 0x6e,0xee, 0xee,0x5e, 0xee,0xee, 0xee,0x6e, 0x6e,0xee, 0xee};
Image wheel = Image(wheelData);

const PROGMEM uint8_t leftWheelData[] = {4, 3, 8, 0, 1, 0x0E, 1, 0xee, 0xee,0xee, 0xee,0xee, 0x5e,0xee, 0xee,0xee, 0xee,0xe6, 0xee,0xee, 0xee,0xee, 0xee,0x5e, 0xee,0xee, 0xee,0x6e, 0xee,0xee, 0xee,0x6e, 0xee,0xee, 0xee,0xee, 0xee,0xe6, 0xee,0xee, 0xee,0xee, 0xee,0xee, 0x6e,0xee, 0xee,0xee, 0xee,0xee, 0xee,0xee, 0x6e,0xee, 0xee};
Image leftWheel = Image(leftWheelData);

const PROGMEM uint8_t rightWheelData[] = {4, 3, 8, 0, 1, 0x0E, 1, 0x6e, 0xee,0xee, 0xee,0xee, 0xee,0xe6, 0xee,0xee, 0xee,0xee, 0xee,0xee, 0x6e,0xee, 0xee,0xee, 0xee,0xee, 0xee,0xee, 0x6e,0xee, 0xee,0xee, 0xee,0xee, 0xee,0xee, 0x5e,0xee, 0xee,0xee, 0xee,0xe6, 0xee,0xee, 0xee,0xee, 0xee,0x5e, 0xee,0xee, 0xee,0x6e, 0xee,0xee, 0xee};
Image rightWheel = Image(rightWheelData);

const PROGMEM uint8_t miniAmbulanceData[] = {6, 6, 1, 0, 1, 0x0E, 1, 0xe7, 0x77,0xee, 0x77,0x87, 0x7e,0x78, 0x88,0x75, 0x77,0x87, 0x75,0xe7, 0x77,0x55, 0xee,0x55, 0x5e};
Image miniAmbulance = Image(miniAmbulanceData);

const PROGMEM uint8_t miniHospitalData[] = {6, 6, 1, 0, 1, 0x0E, 1, 0x11, 0x11,0x1e, 0x17,0x17, 0x15,0x17, 0x77,0x15, 0x17,0x17, 0x15,0x11, 0x11,0x15, 0xe5,0x55, 0x55};
Image miniHospital = Image(miniHospitalData);

const PROGMEM uint8_t SquareNoseRightData[] = {10, 12, 1, 0, 1, 0x03, 1, 0x33, 0x00,0x00, 0x03,0x33, 0x30,0x04, 0x04,0x00, 0x33,0x00, 0x44,0x44, 0x40,0x00, 0x04,0x40, 0x40,0x40, 0x80,0x04, 0x44,0x44, 0x44,0x00, 0x04,0x44, 0x77,0x40, 0x03,0x00, 0x44,0x44, 0x00,0x33, 0x04,0x44, 0x44,0x40, 0x33,0x00, 0x44,0x44, 0x00,0x33, 0x30,0x40, 0x04,0x00, 0x33,0x30, 0x44,0x04, 0x40,0x33, 0x30,0x00, 0x00,0x00, 0x33};
Image SquareNoseRight = Image(SquareNoseRightData);

const PROGMEM uint8_t birdLeftData[] = {12, 8, 2, 0, 4, 0x0E, 1, 0xee, 0xee,0xee, 0x00,0x00, 0xee,0xe0, 0x00,0x00, 0x07,0x70, 0x0e,0x00, 0x77,0x70, 0x76,0x67, 0x0e,0x0a, 0x76,0x67, 0x66,0x70, 0x0e,0x00, 0x77,0x76, 0x67,0x00, 0xee,0xe0, 0x00,0x07, 0x70,0x00, 0xee,0xee, 0xee,0x00, 0x07,0x70, 0xee,0xee, 0xee,0xee, 0x00,0x00, 0xee,0xee, 0xee,0xee, 0xee,0xee, 0xee,0xe0, 0x00,0x00, 0x00,0x0e, 0xee,0x00, 0x77,0x70, 0x77,0x00, 0xee,0x0a, 0x76,0x67, 0x66,0x70, 0x0e,0x00, 0x77,0x76, 0x67,0x77, 0x0e,0xe0, 0x00,0x07, 0x70,0x00, 0x0e,0xee, 0xee,0x00, 0x07,0x70, 0xee,0xee, 0xee,0xee, 0x00,0x00, 0xee};
Image birdLeft = Image(birdLeftData);

const PROGMEM uint8_t bugRightData[] = {10, 7, 2, 0, 3, 0x0E, 1, 0xe0, 0x00,0x00, 0xee,0xee, 0x00,0xcc, 0xc0,0x00, 0x0e,0x0c, 0xdd,0xdc, 0xcc,0x0e, 0x0c,0xdd, 0xdc,0x1c, 0x0e,0x0c, 0xcc,0xcc, 0xcc,0x0e, 0x00,0xc0, 0x00,0xc0, 0x0e,0xe0, 0x00,0xe0, 0x00,0xee, 0xe0,0x00, 0x00,0xee, 0xee,0x00, 0xcc,0xc0, 0x00,0x0e, 0x0c,0xdd, 0xdc,0xcc, 0x0e,0x0c, 0xdd,0xdc, 0x1c,0x0e, 0x0c,0xcc, 0xcc,0xcc, 0x0e,0x00, 0x00,0xc0, 0x00,0x0e, 0xee,0xe0, 0x00,0xee, 0xee};
Image bugRight = Image(bugRightData);

const PROGMEM uint8_t frogGroundData[] = {12, 12, 1, 0, 1, 0x0C, 1, 0xcc, 0x00,0x00, 0x00,0x00, 0xcc,0xcc, 0x0b,0xb0, 0x0b,0xb0, 0xcc,0xc0, 0x0b,0x1b, 0xb1,0xb0, 0x0c,0xc0, 0xbb,0xbb, 0xbb,0xbb, 0x0c,0xc0, 0xbb,0xee, 0xee,0xbb, 0x0c,0xc0, 0xbb,0xbb, 0xbb,0xbb, 0x0c,0x00, 0x0b,0xbb, 0xbb,0xb0, 0x00,0x0b, 0xbb,0xb3, 0x3b,0xbb, 0xb0,0x0b, 0xb3,0xbb, 0xbb,0x3b, 0xb0,0x00, 0xbb,0x3b, 0xb3,0xbb, 0x00,0x0b, 0xbb,0xb0, 0x0b,0xbb, 0xb0,0x00, 0x00,0x00, 0x00,0x00, 0x00};
Image frogGround = Image(frogGroundData);

const PROGMEM uint8_t frogAirData[] = {12, 14, 1, 0, 1, 0x0C, 1, 0xcc, 0x00,0x00, 0x00,0x00, 0xcc,0xcc, 0x0b,0xb0, 0x0b,0xb0, 0xcc,0xc0, 0x0b,0x1b, 0xb1,0xb0, 0x0c,0xc0, 0xbb,0xbb, 0xbb,0xbb, 0x0c,0xc0, 0xbb,0xee, 0xee,0xbb, 0x0c,0xc0, 0xbb,0xee, 0xee,0xbb, 0x0c,0x00, 0x0b,0xbb, 0xbb,0xb0, 0x00,0x0b, 0xbb,0xb3, 0x3b,0xbb, 0xb0,0x00, 0x0b,0xbb, 0xbb,0xb0, 0x00,0xc0, 0xbb,0xbb, 0xbb,0xbb, 0x0c,0xc0, 0xbb,0xb0, 0x0b,0xbb, 0x0c,0x00, 0xbb,0x00, 0x00,0xbb, 0x00,0x0b, 0xbb,0x0c, 0xc0,0xbb, 0xb0,0x00, 0x00,0x0c, 0xc0,0x00, 0x00};
Image frogAir = Image(frogAirData);

const PROGMEM uint8_t SquiddyData[] = {10, 10, 1, 0, 1, 0x0E, 1, 0x00, 0x00,0x00, 0x00,0x00, 0x08,0x80, 0x88,0x08, 0x80,0x00, 0x88,0x77, 0x88,0x00, 0xe0,0x87, 0x00,0x78, 0x0e,0xe0, 0x88,0x77, 0x88,0x0e, 0xe0,0x08, 0x88,0x80, 0x0e,0xe0, 0x80,0x88, 0x08,0x0e, 0x00,0x80, 0x88,0x08, 0x00,0x08, 0x88,0x00, 0x88,0x80, 0x00,0x00, 0x00,0x00, 0x00};
Image Squiddy = Image(SquiddyData);

const PROGMEM uint8_t SquareNoseBallData[] = {10, 10, 1, 0, 1, 0x0E, 1, 0xee, 0xe0,0x00, 0x0e,0xee, 0xe0,0x00, 0x44,0x00, 0x0e,0xe0, 0x44,0x4f, 0x44,0x0e, 0x00,0x44, 0x44,0xf4, 0x00,0x04, 0x44,0x44, 0x44,0x40, 0x04,0x44, 0x44,0x44, 0x40,0x00, 0x44,0x44, 0x44,0x00, 0xe0,0x44, 0x44,0x44, 0x0e,0xe0, 0x00,0x44, 0x00,0x0e, 0xee,0xe0, 0x00,0x0e, 0xee};
Image SquareNoseBall = Image(SquareNoseBallData);

const PROGMEM uint8_t heartData[] = {8, 7, 1, 0, 1, 0x03, 1, 0x3e, 0xe5,0xee, 0x53,0xee, 0xee,0xee, 0xe5,0xee, 0xee,0xee, 0xe5,0x5e, 0xee,0xee, 0x55,0x35, 0xee,0xe5, 0x53,0x33, 0x5e,0x55, 0x33,0x33, 0x35,0x53, 0x33};
Image heart = Image(heartData);

const PROGMEM uint8_t emptyHeartData[] = {8, 7, 1, 0, 1, 0x03, 1, 0x33, 0x35,0x33, 0x53,0x33, 0x33,0x33, 0x35,0x33, 0x33,0x33, 0x35,0x53, 0x33,0x33, 0x55,0x35, 0x33,0x35, 0x53,0x33, 0x53,0x55, 0x33,0x33, 0x35,0x53, 0x33};
Image emptyHeart = Image(emptyHeartData);

const PROGMEM uint8_t openHandData[] = {22, 22, 1, 0, 1, 0x0D, 1, 0xd0, 0xff,0xff, 0xff,0xff, 0xff,0x0d, 0xdd,0xdd, 0xdd,0xdd, 0x00,0xff, 0xff,0xff, 0xff,0xff, 0x00,0xdd, 0xdd,0xdd, 0xdd,0x0f, 0xff,0xff, 0xff,0xff, 0xff,0xf0, 0x0d,0xdd, 0xdd,0xdd, 0x0f,0xff, 0xff,0xff, 0xff,0xff, 0xff,0x00, 0xdd,0xdd, 0xdd,0x0f, 0xff,0xff, 0xff,0xff, 0xff,0xff, 0xf0,0x0d, 0xdd,0xdd, 0x0f,0xff, 0xff,0xff, 0xff,0xff, 0xff,0xff, 0x00,0xdd, 0xdd,0x0f, 0xff,0xff, 0xff,0xff, 0xff,0xff, 0xff,0xf0, 0x0d,0xdd, 0x0f,0xff, 0xff,0xff, 0xff,0xff, 0xff,0xff, 0xff,0x00, 0xdd,0x0f, 0xff,0xff, 0xff,0xff, 0xff,0x00, 0x0f,0xff, 0xe0,0x0d, 0x0f,0xff, 0xff,0xff, 0xff,0xff, 0x0d,0x00, 0xff,0xee, 0x00,0x0f, 0xff,0xff, 0xff,0xff, 0xff,0x0d, 0xd0,0x0f, 0xfe,0xe0, 0x0f,0xf0, 0xff,0x0f, 0xf0,0xff, 0x0d,0xdd, 0x00,0xff, 0x00,0x0f, 0xf0,0xff, 0x0f,0xf0, 0xff,0x0d, 0xdd,0xd0, 0x00,0x0d, 0x0f,0xf0, 0xff,0x0f, 0xf0,0xff, 0x0d,0xdd, 0xdd,0xdd, 0xdd,0x0f, 0xf0,0xff, 0x0f,0xf0, 0xff,0x0d, 0xdd,0xdd, 0xdd,0xdd, 0x0f,0xf0, 0xff,0x0f, 0xf0,0xff, 0x0d,0xdd, 0xdd,0xdd, 0xdd,0x0f, 0xf0,0xff, 0x0f,0xf0, 0xff,0x0d, 0xdd,0xdd, 0xdd,0xdd, 0x0e,0xe0, 0xff,0x0f, 0xf0,0xff, 0x0d,0xdd, 0xdd,0xdd, 0xdd,0x0e, 0xe0,0xee, 0x0f,0xf0, 0xee,0x0d, 0xdd,0xdd, 0xdd,0xdd, 0x00,0x00, 0xee,0x0e, 0xe0,0xee, 0x0d,0xdd, 0xdd,0xdd, 0xdd,0xdd, 0xd0,0x00, 0x0e,0xe0, 0x00,0x0d, 0xdd,0xdd, 0xdd,0xdd, 0xdd,0xdd, 0xdd,0x00, 0x00,0xdd, 0xdd,0xdd, 0xdd,0xdd, 0xdd};
Image openHand = Image(openHandData);

const PROGMEM uint8_t hospitalLogoData[] = {10, 10, 1, 0, 1, 0xFF, 1, 0x11, 0x11,0x11, 0x11,0x11, 0x11,0x11, 0x11,0x11, 0x11,0x11, 0x77,0x11, 0x77,0x11, 0x11,0x77, 0x11,0x77, 0x11,0x11, 0x77,0x77, 0x77,0x11, 0x11,0x77, 0x77,0x77, 0x11,0x11, 0x77,0x11, 0x77,0x11, 0x11,0x77, 0x11,0x77, 0x11,0x11, 0x11,0x11, 0x11,0x11, 0x11,0x11, 0x11,0x11, 0x11};
Image hospitalLogo = Image(hospitalLogoData);

const PROGMEM uint8_t niceBushData[] = {6, 12, 1, 0, 1, 0x0E, 1, 0xee, 0x3e,0xee, 0xe3,0x33, 0xee,0x33, 0x33,0x3e, 0x33,0x33, 0x3e,0x33, 0x33,0x3e, 0x33,0x33, 0x3e,0xe3, 0x33,0xee, 0xee,0x4e, 0xee,0xee, 0x4e,0xee, 0xe2,0x22, 0xee,0xe2, 0x22,0xee, 0xe2,0x22, 0xee};
Image niceBush = Image(niceBushData);

const PROGMEM uint8_t medicalDudesData[] = {14, 13, 1, 0, 1, 0xFF, 1, 0x22, 0x22,0x22, 0x22,0x22, 0x22,0x22, 0x22,0x22, 0x22,0x22, 0x22,0x22, 0x22,0x22, 0x00,0x02, 0x22,0x2f, 0xff,0xf2, 0x22,0xff, 0xf2,0x22, 0x25,0xf5, 0xf2,0x22, 0x1f,0x12, 0x22,0x2f, 0x4f,0xf2, 0x22,0xff, 0xf2,0x22, 0x2f,0xff, 0x72,0xcc, 0xc7,0xcc, 0xc2,0x77, 0x67,0x77, 0x77,0xcc, 0xc7,0x72, 0x77,0x77, 0x77,0x72, 0xcc,0xc2, 0x72,0x77, 0x77,0x77, 0xf2,0xcc, 0xc2,0xf2, 0xf7,0x77, 0x7f,0x22, 0xc2,0xc2, 0x22,0x2d, 0xd2,0xdd, 0x22,0xc2, 0xc2,0x22, 0x2d,0xd2, 0xdd,0x20, 0x02,0x00, 0x22,0x20, 0x02,0x0000};
Image medicalDudes = Image(medicalDudesData);

int whiteLineX = 0;
int whiteLineY = 0;
int whiteLinecounter = 0;

int ambulanceX = 3;
int ambulanceY = 0;
int ambulanceAngle = 90;

int health = 3;

int obstacle = 1;

int miniAmbulanceX = 33;

int colorNumber = 1;

int passedObstacles = 0;

bool youLose = false;
bool youWin = false;

bool pushable = true;
bool upPressed = false;
bool downPressed = false;
bool buttonWasPressed = false;

int gameState = 1;

int birdX = 84;
int birdY = 20;
bool deadBird = false;

int bugX = 84;
int bugY = 20;
bool deadBug = false;

int frogX = 84;
int frogY = 20;
bool frogIsJumping = false;
int frogJumpHeight = 0;
int frogJumpSpeed = 0;
int frogJumpCounter = 0;
bool deadFrog = false;

int SquiddyX = 84;
int SquiddyY = 5;
bool deadSquiddy = false;
int SquareNoseBallX = 84;
int SquareNoseBallY = 41;
bool deadSquareNoseBall = false;
int SquiddyAngle = 270;

int hospitalX = 84;
int doors = 8;

void setup() {
  gb.begin();
}

void loop() {
  while(!gb.update());
  gb.display.clear();

  switch (gameState) {
// intro
    case 1:
      resetValues();
      gameState = 2;
    break;

// in game
    case 2:
// draw the road
// color the ground white light gray
  gb.display.setColor(GRAY);
  gb.display.fillRect(0, 0, 80, 64);

// draw all the moving white lines
  gb.display.setColor(WHITE);
  for(int row = 0; row < 4; row += 1) {
    for(int column = 0; column < 5; column += 1) {
      int brickX = column * 20;
      int brickY = row * 18;
      gb.display.fillRect(whiteLineX + brickX, whiteLineY + brickY, 12, 2);
    }
  }

// move the white lines to the left
  if((youWin == false) && (youLose == false)) {
    whiteLineX -= 2;
    if(whiteLineX < (-19)) {
      whiteLineX = 0;
    }
  
// move the ambulance
    ambulanceAngle -= 2;
      if(ambulanceAngle < 0) {
        ambulanceAngle = 359;
      }
    ambulanceY = 22 + cos(ambulanceAngle * PI / 180) *20;
  }
  
// draw the ambulance
  gb.display.drawImage(ambulanceX, ambulanceY, ambulance);
  gb.display.drawImage(ambulanceX + 12, ambulanceY + 1, gyrophare);
  if((youWin == false) && (youLose == false)) {
    gb.display.drawImage(ambulanceX + 3, ambulanceY + 9, leftWheel);
    gb.display.drawImage(ambulanceX + 13, ambulanceY + 9, rightWheel);
  }

// explosion animation on ambulance
  if(youLose == true) {
    explosion(ambulanceX, ambulanceY, 18, 13);
  }

// UP and DOWN buttons during game
  if((youWin == false) && (youLose == false)) {
    if(pushable == true) {
      if(gb.buttons.pressed(BUTTON_UP)) {
        upPressed = true;
        pushable = false;
        gb.sound.playTick();
      } else {
        if((gb.buttons.pressed(BUTTON_DOWN)) && (obstacle != 3)) {
          downPressed = true;
          pushable = false;
          gb.sound.playTick();
        }
      }
    }

// the different living obstacles (animals) on the road
// and their gameplay
  switch (obstacle) {
// bird
    case 1:
// collision bird and ambulance
      if(((gb.collide.rectRect(ambulanceX + 1, ambulanceY + 1, 11, 10, birdX, birdY, 11, 8)) || (gb.collide.rectRect(ambulanceX + 12, ambulanceY + 6, 5, 5, birdX, birdY, 11, 8))) && (deadBird == false)) {
        health -= 1;
        deadBird = true;
        gb.sound.playCancel();
      }
      
// player moves bird up or down
      if((upPressed == true) && (birdY > 2)) {
        birdY -= 2;
      }
      if((downPressed == true) && (birdY < 46)) {
        birdY += 2;
      }

// draw bird
      gb.display.drawImage(birdX, birdY, birdLeft);
      if(deadBird == true) {
        explosion(birdX, birdY, 11, 8);
      }
      
// bird go to the left
      birdX -= 3;
      
// bird is out of screen at left
      if(birdX < -13) {
        resetValues();
      }
    break;

// bug
    case 2:
// collision bird and ambulance
      if(((gb.collide.rectRect(ambulanceX + 1, ambulanceY + 1, 11, 10, bugX, bugY, 9, 7)) || (gb.collide.rectRect(ambulanceX + 12, ambulanceY + 6, 5, 5, bugX, bugY, 9, 7))) && (deadBug == false)) {
        health -= 1;
        deadBug = true;
        gb.sound.playCancel();
      }

// bug moves up or down
      if((upPressed == true) && (bugY > 2)) {
        bugY -= 1;
      }
      if((downPressed == true) && (bugY < 47)) {
        bugY += 1;
      }

// draw bug
      gb.display.drawImage(bugX, bugY, bugRight);
      if(deadBug == true) {
        explosion(bugX, bugY, 9, 7);
      }
      
// bug moves slowly to the left
      bugX -= 1;

// bug is out of screen at left
      if(bugX < -11) {
        resetValues();
      }
    break;

// frog
    case 3:
// collision frog and ambulance
      if(((gb.collide.rectRect(ambulanceX + 1, ambulanceY + 1, 11, 10, frogX, frogY, 12, 12)) || (gb.collide.rectRect(ambulanceX + 12, ambulanceY + 6, 5, 5, frogX, frogY, 12, 12))) && (deadFrog == false) && (frogIsJumping == false)) {
        health -= 1;
        deadFrog = true;
        gb.sound.playCancel();
      }
    
// the player makes the frog jump
      if((upPressed == true) && (buttonWasPressed == false)) {
        frogIsJumping = true;
        frogJumpSpeed = -4;
        buttonWasPressed = true;
        gb.sound.playTick();
      }
// the frog jumps
      if(frogIsJumping == true) {
        frogJumpHeight = frogJumpHeight + frogJumpSpeed;
        frogJumpCounter += 1;
        if((frogJumpCounter % 4) == 0) {
          frogJumpSpeed += 2;
        }
      }

// stop frog falling when hit the ground
      if(frogJumpHeight > -1) {
        frogIsJumping = false;
        frogJumpCounter = 0;
        frogJumpSpeed = 0;
        frogJumpHeight = 0;
      }

// draw the frog
      if(frogIsJumping == true) {
        gb.display.drawImage(frogX, frogY + frogJumpHeight, frogAir);
      } else {
        gb.display.drawImage(frogX, frogY, frogGround);
        if(deadFrog == true) {
          explosion(frogX, frogY, 12, 12);
        }
      }

// the frog moves to the left
      frogX -= 2;
// frog is out of screen at left
      if(frogX < -15) {
        resetValues();
      }
    break;

// Squiddy and Square Nose Ball
    case 4:
// collision Squiddy and ambulance
      if(((gb.collide.rectRect(ambulanceX + 1, ambulanceY + 1, 11, 10, SquiddyX, SquiddyY, 10, 10)) || (gb.collide.rectRect(ambulanceX + 12, ambulanceY + 6, 5, 5, SquiddyX, SquiddyY, 10, 10))) && (deadSquiddy == false)) {
        health -= 1;
        deadSquiddy = true;
        gb.sound.playCancel();
      }
// collision Square Nose Ball and ambulance
      if(((gb.collide.rectRect(ambulanceX + 1, ambulanceY + 1, 11, 10, SquareNoseBallX, SquareNoseBallY, 10, 10)) || (gb.collide.rectRect(ambulanceX + 12, ambulanceY + 6, 5, 5, SquareNoseBallX, SquareNoseBallY, 10, 10))) && (deadSquareNoseBall == false)) {
        health -= 1;
        deadSquareNoseBall = true;
        gb.sound.playCancel();
      }
      
// rotations
// Square Nose Ball moves to up right
      if((upPressed == true) && (SquareNoseBallY > SquiddyY)) {
        SquiddyAngle += 4;
        SquareNoseBallX = SquiddyX + cos(SquiddyAngle * PI / 180) * 36;
        SquareNoseBallY = SquiddyY - sin(SquiddyAngle * PI / 180) * 36;
      }
// Squiddy moves to down right
      if((downPressed == true) && (SquiddyY < SquareNoseBallY)) {
        SquiddyAngle += 4;
        SquiddyX = SquareNoseBallX + cos(SquiddyAngle * PI / 180) * 36;
        SquiddyY = SquareNoseBallY + sin(SquiddyAngle * PI / 180) * 36;
      }
    
// draw Squiddy and Square Nose Ball
      gb.display.drawImage(SquiddyX, SquiddyY, Squiddy);
      if(deadSquiddy == true) {
        explosion(SquiddyX, SquiddyY, 10, 10);
      }
      gb.display.drawImage(SquareNoseBallX, SquareNoseBallY, SquareNoseBall);
      if(deadSquareNoseBall == true) {
        explosion(SquareNoseBallX, SquareNoseBallY, 10, 10);
      }

// Squiddy and Square Nose Ball go to the left with the road
      SquiddyX -= 2;
      SquareNoseBallX -= 2;

// bring the next obstacle if Squiddy and Square Nose Ball are at left, out of the screen
      if(((SquiddyX < -12) && (SquiddyX >= SquareNoseBallX)) || ((SquareNoseBallX < -12) && (SquareNoseBallX >= SquiddyX))) {
        resetValues();
      }
    break;

// the hospital
    case 5:
// move hospital to the left
      if(hospitalX > 26) {
        hospitalX -= 2;
      } else {
        youWin = true;
      }
// draw hospital
      gb.display.setColor(BLACK);
      gb.display.drawRect(hospitalX - 1, 3, 52, 50);
      gb.display.setColor(WHITE);
      gb.display.fillRect(hospitalX, 4, 50, 48);
      gb.display.drawImage(hospitalX + 20, 21, hospitalLogo);
      gb.display.setColor(LIGHTBLUE);
      gb.display.fillRect(hospitalX + 3, 8, 4, 9);
      gb.display.fillRect(hospitalX + 13, 8, 4, 9);
      gb.display.fillRect(hospitalX + 23, 8, 4, 9);
      gb.display.fillRect(hospitalX + 33, 8, 4, 9);
      gb.display.fillRect(hospitalX + 43, 8, 4, 9);
      gb.display.fillRect(hospitalX + 3, 21, 4, 9);
      gb.display.fillRect(hospitalX + 13, 21, 4, 9);
      gb.display.fillRect(hospitalX + 33, 21, 4, 9);
      gb.display.fillRect(hospitalX + 43, 21, 4, 9);
      gb.display.fillRect(hospitalX + 3, 34, 4, 9);
      gb.display.fillRect(hospitalX + 43, 34, 4, 9);

      gb.display.setColor(DARKGRAY);
      gb.display.drawRect(hospitalX + 3, 8, 4, 9);
      gb.display.drawRect(hospitalX + 13, 8, 4, 9);
      gb.display.drawRect(hospitalX + 23, 8, 4, 9);
      gb.display.drawRect(hospitalX + 33, 8, 4, 9);
      gb.display.drawRect(hospitalX + 43, 8, 4, 9);
      gb.display.drawRect(hospitalX + 3, 21, 4, 9);
      gb.display.drawRect(hospitalX + 13, 21, 4, 9);
      gb.display.drawRect(hospitalX + 33, 21, 4, 9);
      gb.display.drawRect(hospitalX + 43, 21, 4, 9);
      gb.display.drawRect(hospitalX + 3, 34, 4, 9);
      gb.display.drawRect(hospitalX + 43, 34, 4, 9);

      gb.display.setColor(LIGHTBLUE);
      gb.display.fillRect(hospitalX + 17, 38, doors, 15);
      gb.display.fillRect(hospitalX + 33 - doors, 38, doors, 15);
      gb.display.setColor(DARKGRAY);
      gb.display.drawRect(hospitalX + 17, 38, doors, 15);
      gb.display.drawRect(hospitalX + 33 - doors, 38, doors, 15);
    
      gb.display.setColor(DARKGRAY);
      gb.display.drawRect(hospitalX + 14, 34, 22, 5);
      gb.display.drawRect(hospitalX + 17, 39, 16, 14);
      gb.display.drawImage(hospitalX + 10, 41, niceBush);
      gb.display.drawImage(hospitalX + 35, 41, niceBush);
    break;
  }
  }

// draw the hospital
  if(youWin == true) {
    gb.display.setColor(BLACK);
    gb.display.drawRect(hospitalX - 1, 3, 52, 50);
    gb.display.setColor(WHITE);
    gb.display.fillRect(hospitalX, 4, 50, 48);
    gb.display.drawImage(hospitalX + 20, 21, hospitalLogo);
    
    gb.display.setColor(LIGHTBLUE);
// windows at top
    gb.display.fillRect(hospitalX + 3, 8, 4, 9);
    gb.display.fillRect(hospitalX + 13, 8, 4, 9);
    gb.display.fillRect(hospitalX + 23, 8, 4, 9);
    gb.display.fillRect(hospitalX + 33, 8, 4, 9);
    gb.display.fillRect(hospitalX + 43, 8, 4, 9);
// windows in the middle
    gb.display.fillRect(hospitalX + 3, 21, 4, 9);
    gb.display.fillRect(hospitalX + 13, 21, 4, 9);
    gb.display.fillRect(hospitalX + 33, 21, 4, 9);
    gb.display.fillRect(hospitalX + 43, 21, 4, 9);
// windows at bottom
    gb.display.fillRect(hospitalX + 3, 34, 4, 9);
    gb.display.fillRect(hospitalX + 43, 34, 4, 9);
    
    gb.display.setColor(DARKGRAY);
    gb.display.drawRect(hospitalX + 3, 8, 4, 9);
    gb.display.drawRect(hospitalX + 13, 8, 4, 9);
    gb.display.drawRect(hospitalX + 23, 8, 4, 9);
    gb.display.drawRect(hospitalX + 33, 8, 4, 9);
    gb.display.drawRect(hospitalX + 43, 8, 4, 9);
    gb.display.drawRect(hospitalX + 3, 21, 4, 9);
    gb.display.drawRect(hospitalX + 13, 21, 4, 9);
    gb.display.drawRect(hospitalX + 33, 21, 4, 9);
    gb.display.drawRect(hospitalX + 43, 21, 4, 9);
    gb.display.drawRect(hospitalX + 3, 34, 4, 9);
    gb.display.drawRect(hospitalX + 43, 34, 4, 9);
    
    gb.display.setColor(DARKGRAY);
    gb.display.drawRect(hospitalX + 14, 34, 22, 5);
    gb.display.drawRect(hospitalX + 17, 39, 16, 14);
    
    gb.display.drawImage(hospitalX + 10, 41, niceBush);
    gb.display.drawImage(hospitalX + 35, 41, niceBush);

    gb.display.drawImage(hospitalX + 18, 39, medicalDudes);

// hospital doors
    gb.display.setColor(LIGHTBLUE);
    gb.display.fillRect(hospitalX + 17, 38, doors, 15);
    gb.display.fillRect(hospitalX + 33 - doors, 38, doors, 15);
    gb.display.setColor(DARKGRAY);
    gb.display.drawRect(hospitalX + 17, 38, doors, 15);
    gb.display.drawRect(hospitalX + 33 - doors, 38, doors, 15);
   
    if(doors > 1) {
      doors -= 1;
    }
  }

// draw the hearts at the bottom
  if(health > 0) {
    gb.display.drawImage(2, 57, heart);
  } else {
    gb.display.drawImage(2, 57, emptyHeart);
  }
  if(health > 1) {
    gb.display.drawImage(12, 57, heart);
  } else {
    gb.display.drawImage(12, 57, emptyHeart);
  }
  if(health >2) {
    gb.display.drawImage(22, 57, heart);
  } else {
    gb.display.drawImage(22, 57, emptyHeart);
  }

// you lose if the ambulance smashes 3 innocent animals
  if(health < 1) {
    youLose = true;
  }

// print dots between mini ambulance and mini hospital
// shadows
  gb.display.setCursor(37, 56);
  gb.display.setColor(DARKGRAY);
  gb.display.print(".........");
// white dots
  gb.display.setCursor(36, 55);
  gb.display.setColor(WHITE);
  gb.display.print(".........");
  
// draw mini ambulance and mini hospital at the bottom
  gb.display.drawImage(miniAmbulanceX, 57, miniAmbulance);
  gb.display.drawImage(73, 57, miniHospital);

// reset the game
  if((youWin == true) || (youLose == true)) {
    if(gb.buttons.pressed(BUTTON_UP) || (gb.buttons.pressed(BUTTON_DOWN))) {
      gameState = 3;
    }
  }
  break;

// text screen
  case 3:
// background
    gb.display.setColor(RED);
    gb.display.fillRect(0, 0, 80, 12);
    gb.display.setColor(DARKBLUE);
    gb.display.fillRect(0, 12, 80, 21);
    gb.display.fillRect(0, 45, 80, 19);
    gb.display.setColor(BLUE);
    gb.display.fillRect(0, 33, 80, 12);

// text
    gb.display.setColor(WHITE);
    gb.display.setFontSize(2);
    gb.display.print("DUMBULANCE");
    gb.display.setColor(ORANGE);
    gb.display.setFontSize(1);
    gb.display.print("\n\n\n   by Juice Lizard\n  on Gamebuino Meta");
    gb.display.setColor(WHITE);
    gb.display.print("\n\n  Play with UP/DOWN");
    gb.display.setColor(ORANGE);
    gb.display.print("\n\n    Ludum Dare 46\n    Keep it alive");

// go back to game
    if((gb.buttons.pressed(BUTTON_UP)) || (gb.buttons.pressed(BUTTON_DOWN))) {
    gameState = 1;
    }
  break;
}
}

void resetValues() {
  if(gameState == 1) {
    ambulanceX = 3;
    ambulanceY = 0;
    ambulanceAngle = 90;
    miniAmbulanceX = 33;
    youWin = false;
    youLose = false;
    health = 3;
    hospitalX = 84;
    doors = 8;
  }

  if(gameState == 2) {
    passedObstacles +=1;
    miniAmbulanceX += 2;
    if((deadBird == false) && (deadBug == false) && (deadFrog == false) && (deadSquiddy == false) && (deadSquareNoseBall == false) && (passedObstacles < 18)) {
      gb.sound.playOK();
    }
  } else {
    passedObstacles = 0;
  }
  
  birdX = 84;
  birdY = random(2, 46);
  deadBird = false;

  bugX = 84;
  bugY = random(2, 47);
  deadBug = false;

  frogX = 84;
  frogY = random(2, 42);
  frogIsJumping = false;
  frogJumpHeight = 0;
  frogJumpSpeed = 0;
  frogJumpCounter = 0;
  buttonWasPressed = false;
  deadFrog = false;

  SquiddyX = 84;
  SquiddyY = 5;
  deadSquiddy = false;

  SquareNoseBallX = 84;
  SquareNoseBallY = 41;
  deadSquareNoseBall = false;

  SquiddyAngle = 270;
  
  if(passedObstacles < 18) {
    obstacle = random(1, 5);
  } else {
    obstacle = 5;
  }

  upPressed = false;
  downPressed = false;
  pushable = true;
}

void explosion(int x, int y, int w, int h) {
  colorNumber = random(4);
  switch (colorNumber) {
    case 0:
      gb.display.setColor(BLACK);
      break;
    case 1:
      gb.display.setColor(YELLOW);
      break;
    case 2:
      gb.display.setColor(ORANGE);
      break;
    case 3:
      gb.display.setColor(RED);
      break;
  }
  gb.display.fillCircle(x + random(w + 1), y + random(h + 1), random(6));
}
