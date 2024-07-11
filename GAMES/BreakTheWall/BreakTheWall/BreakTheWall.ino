// "Break the wall" by Juice Lizard, 2024
// Gamebuino Meta prototype before Dreamcast game

#include <Gamebuino-Meta.h>

#include "assets.h"
#include "levels.h"

int xPlayer = 27;
int yPlayer = 136;

int xBall = 39;
int yBall = 136;

int xPrevious = 27;
int yPrevious = 136;

int ballPosition = 6;

int rotationCounter = 0;

int diagonalDistance = 10;
int rightDistance = 12;
int thirdDistance = 11;

bool isJumping = false;

int playerColor = 4;
int ballColor = 1;
int previousColor = 4;

bool grip = true;

int xSpeed = 0;
int ySpeed = 0;

int gravityCounter = 0;

int xErase = 0;
int yErase = 0;

bool startGame = true;
int firstGripCounter = 0;
bool firstGrip = false;

bool gameOver = false;

int remainingBalls = 4;

int blueBallAlive = 1;
int orangeBallAlive = 1;
int greenBallAlive = 1;
int redBallAlive = 1;

bool outOfScreen = false;

bool levelFinished = false;

void setup() {
  Serial.begin(74880);
  gb.begin();
  gb.setFrameRate(30);
}

void loop() {
  while(!gb.update());

  gb.display.clear();

  //gb.lights.clear();

  gb.display.drawImage(0, 0, tropical);

  if((gb.buttons.pressed(BUTTON_A)) || (startGame == true) || (firstGrip == true)) {
    if(isJumping == false) {
      gb.sound.playTick();
      eraseSquare();
      xPrevious = xPlayer;
      yPrevious = yPlayer;
      xPlayer = xBall;
      yPlayer = yBall;
      setPlayerSpeed();
      startGame = false;
      chooseColors();
      isJumping = true;
    } else {
      isBallOnBlock();
      if(grip == true) {
        gb.sound.fx(skeletonBreak);
        eraseSquare();
        chooseColors();
        isJumping = false;
      } else {
        gb.sound.playCancel();
      }
      firstGrip = false;
    }
  }

  if(firstGripCounter < 16) {
    firstGripCounter = firstGripCounter + 1;
    if(firstGripCounter > 15) {
      firstGrip = true;
    }
  }

  drawLevel();

  if(gameOver == false) {
    if(isJumping == false) {
      drawPlayer();

      rotateBall();

      drawBall();
    } else {
      xPlayer = xPlayer + xSpeed;

      gravityCounter = gravityCounter + 1;
      if(gravityCounter > 1) {
        gravityCounter = 0;
      }
      if(gravityCounter == 0) {
        ySpeed = ySpeed + 1;
      }
      yPlayer = yPlayer + ySpeed;

      drawPreviousPlayer();

      drawPlayer();
    }
  }

  if((isJumping == true) && ((xPlayer < -2) || (xPlayer > 162) || (yPlayer < -2) || (yPlayer > 130)) && (firstGrip == false)) {
    gb.sound.playCancel();
    killOneBall();
    xPlayer = xPrevious;
    yPlayer = yPrevious;
    outOfScreen = true;
    chooseColors();
    outOfScreen = false;
    isJumping = false;
  }

  if((blueBallAlive + orangeBallAlive + greenBallAlive + redBallAlive) < 2) {
    gameOver = true;
    levelFinished = isLevelCleared();
  }

  if(gameOver == true) {
    if(levelFinished == true) {
      //gb.lights.drawImage(0, 0, rainbow);
    } else {
      drawGameOver();
    }
  }
  
  if((gb.buttons.pressed(BUTTON_B)) || ((gameOver == true) && (gb.buttons.pressed(BUTTON_A)))) {
    reset();    
  }

/*
  if(gb.buttons.pressed(BUTTON_UP)) {
    blueBallAlive = 1;
    orangeBallAlive = 1;
    greenBallAlive = 1;
    redBallAlive = 1;
  }
*/
}
