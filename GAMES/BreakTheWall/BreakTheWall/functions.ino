// functions

void drawPlayer() {
    switch (playerColor) {
      case 1:
      gb.display.drawImage(xPlayer - 4, yPlayer - 4, blueBall);
      break;
      case 2:
      gb.display.drawImage(xPlayer - 4, yPlayer - 4, orangeBall);
      break;
      case 3:
      gb.display.drawImage(xPlayer - 4, yPlayer - 4, greenBall);
      break;
      case 4:
      gb.display.drawImage(xPlayer - 4, yPlayer - 4, redBall);
      break;
    }
//  }
}

void rotateBall() {
  rotationCounter = rotationCounter + 1;
  if(rotationCounter > 31) {
    rotationCounter = 0;
  }
  ballPosition = rotationCounter / 2;
  switch (ballPosition) {
    case 0:
      xBall = xPlayer - 9;
      yBall = yPlayer + 9;
      break;
    case 1:
      xBall = xPlayer - 5;
      yBall = yPlayer + 11;
      break;
    case 2:
      xBall = xPlayer;
      yBall = yPlayer + 12;
      break;
    case 3:
      xBall = xPlayer + 5;
      yBall = yPlayer + 11;
      break;
    case 4:
      xBall = xPlayer + 9;
      yBall = yPlayer + 9;
      break;
    case 5:
      xBall = xPlayer + 11;
      yBall = yPlayer + 5;
      break;
    case 6:
      xBall = xPlayer + 12;
      yBall = yPlayer;
      break;
    case 7:
      xBall = xPlayer + 11;
      yBall = yPlayer - 5;
      break;
    case 8:
      xBall = xPlayer + 9;
      yBall = yPlayer - 9;
      break;
    case 9:
      xBall = xPlayer + 5;
      yBall = yPlayer - 11;
      break;
    case 10:
      xBall = xPlayer;
      yBall = yPlayer - 12;
      break;
    case 11:
      xBall = xPlayer - 5;
      yBall = yPlayer - 11;
      break;
    case 12:
      xBall = xPlayer - 9;
      yBall = yPlayer - 9;
      break;
    case 13:
      xBall = xPlayer - 11;
      yBall = yPlayer - 5;
      break;
    case 14:
      xBall = xPlayer - 12;
      yBall = yPlayer;
      break;
    case 15:
      xBall = xPlayer - 11;
      yBall = yPlayer + 5;
      break;
  }
}

void drawBall() {
  switch (ballColor) {
    case 1:
    gb.display.drawImage(xBall - 4, yBall - 4, blueBall);
    break;
    case 2:
    gb.display.drawImage(xBall - 4, yBall - 4, orangeBall);
    break;
    case 3:
    gb.display.drawImage(xBall - 4, yBall - 4, greenBall);
    break;
    case 4:
    gb.display.drawImage(xBall - 4, yBall - 4, redBall);
    break;
  }
}

void setPlayerSpeed() {
  switch (ballPosition) {
    case 0:
      xSpeed = 4;
      ySpeed = 4;
      break;
    case 1:
      xSpeed = 5;
      ySpeed = 2;
      break;  
    case 2:
      xSpeed = 6;
      ySpeed = 0;
      break;
    case 3:
      xSpeed = 5;
      ySpeed = -2;
      break;
    case 4:
      xSpeed = 4;
      ySpeed = -4;
      break;
    case 5:
      xSpeed = 2;
      ySpeed = -5;
      break;
    case 6:
      xSpeed = 0;
      ySpeed = -6;
      break;
    case 7:
      xSpeed = -2;
      ySpeed = -5;
      break;
    case 8:
      xSpeed = -4;
      ySpeed = -4;
      break;
    case 9:
      xSpeed = -5;
      ySpeed = -2;
      break;
    case 10:
      xSpeed = -6;
      ySpeed = 0;
      break;
    case 11:
      xSpeed = -5;
      ySpeed = 2;
      break;
    case 12:
      xSpeed = -4;
      ySpeed = 4;
      break;
    case 13:
      xSpeed = -2;
      ySpeed = 5;
      break;
    case 14:
      xSpeed = 0;
      ySpeed = 6;
      break;
    case 15:
      xSpeed = 2;
      ySpeed = 5;
      break;
  }
}

void reset() {
  xPlayer = 27;
  yPlayer = 136;
  xBall = 39;
  yBall = 136;
  xPrevious = 27;
  yPrevious = 136;
  ballPosition = 6;
  rotationCounter = 0;
  diagonalDistance = 10;
  rightDistance = 12;
  thirdDistance = 11;
  isJumping = false;
  playerColor = 4;
  ballColor = 1;
  previousColor = 4;
  grip = true;
  xSpeed = 0;
  ySpeed = 0;
  gravityCounter = 0;
  memcpy(level, level1, sizeof(level));
  startGame = true;
  firstGripCounter = 0;
  gameOver = false;
  blueBallAlive = 1;
  orangeBallAlive = 1;
  greenBallAlive = 1;
  redBallAlive = 1;
  outOfScreen = false;
  levelFinished = false;
}

void drawLevel() {
  gb.display.setColor(GRAY);
  for (int row=0; row<8; row++) {
    for (int column=0; column<10; column++) {
      switch (level[row][column]) {
        case 'M':
//          gb.display.drawImage(column*16, row*16, graySquare);
          gb.display.drawImage(column*16, row*16, cleanBlock);
          break;
        case 'B':
          gb.display.drawImage(column*16, row*16, brokenBlock);
          break;
        case 'V':

          break;
      }
    }
  }
}

void eraseSquare() {
  xErase = xPlayer / 16;
  yErase = yPlayer / 16;
  if((xErase > 0) && (xErase < 10) && (yErase > 0) && (yErase < 8)) {
    if((isJumping == true) && (level[(yErase)][(xErase)] == 'M')) {
      level[(yErase)][(xErase)] = 'B';
    } else {
      level[(yErase)][(xErase)] = 'V';
    }
  }
}

void drawPreviousPlayer() {
      switch (previousColor) {
      case 1:
      gb.display.drawImage(xPrevious - 4, yPrevious - 4, blueBall);
      break;
      case 2:
      gb.display.drawImage(xPrevious - 4, yPrevious - 4, orangeBall);
      break;
      case 3:
      gb.display.drawImage(xPrevious - 4, yPrevious - 4, greenBall);
      break;
      case 4:
      gb.display.drawImage(xPrevious - 4, yPrevious - 4, redBall);
      break;
    }
}

void isBallOnBlock() {
  if(level[yPlayer/16][xPlayer/16] == 'M') {
    grip = true;
  } else {
    grip = false;
  }
}

void killOneBall() {
  switch (playerColor) {
    case 1:
    blueBallAlive = 0;
    break;
    case 2:
    orangeBallAlive = 0;
    break;
    case 3:
    greenBallAlive = 0;
    break;
    case 4:
    redBallAlive = 0;
    break;
  }
}

void chooseColors() {
  if(isJumping == true) {
    if(outOfScreen == true) {
      playerColor = previousColor;
    }
    if(playerColor == 1) {
      if(orangeBallAlive == 1) {
        ballColor = 2;
      } else if(greenBallAlive == 1) {
        ballColor = 3;
      } else if(redBallAlive == 1) {
        ballColor = 4;
      }
    }
    if(playerColor == 2) {
      if(greenBallAlive == 1) {
        ballColor = 3;
      } else if(redBallAlive == 1) {
        ballColor = 4;
      } else if(blueBallAlive == 1) {
        ballColor = 1;
      }
    }
    if(playerColor == 3) {
      if(redBallAlive == 1) {
        ballColor = 4;
      } else if(blueBallAlive == 1) {
        ballColor = 1;
      } else if(orangeBallAlive == 1) {
        ballColor = 2;
      }
    }
    if(playerColor == 4) {
      if(blueBallAlive == 1) {
        ballColor = 1;
      } else if(orangeBallAlive == 1) {
        ballColor = 2;
      } else if(greenBallAlive == 1) {
        ballColor = 3;
      }
    }
    
  } else {
    previousColor = playerColor;
    playerColor = ballColor;
  }
}

void drawGameOver() {
  gb.display.setFontSize(4);

  gb.display.setColor(BLACK);
  gb.display.setCursor(12, 56);
  gb.display.print("GAME OVER");
  gb.display.setCursor(8, 56);
  gb.display.print("GAME OVER");
  gb.display.setCursor(8, 52);
  gb.display.print("GAME OVER");
  gb.display.setCursor(12, 52);
  gb.display.print("GAME OVER");
    
  gb.display.setColor(WHITE);
  gb.display.setCursor(10, 54);
  gb.display.print("GAME OVER");
}

bool isLevelCleared() {
  for (int row=0; row<8; row++) {
    for (int column=0; column<10; column++) {
      if(level[row][column] == 'M') {
        return false;
      }
    }
  }
//  nextLevel = true;

  return true;
}
