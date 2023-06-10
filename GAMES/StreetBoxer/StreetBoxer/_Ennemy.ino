void ennemy_init(){
  padPlayer2.btnUP_pressed = false;
  padPlayer2.btnDOWN_pressed = false;
  padPlayer2.btnLEFT_pressed = false;
  padPlayer2.btnRIGHT_pressed = false;
  padPlayer2.btnA_pressed = false;
  padPlayer2.btnB_pressed = false;
  padPlayer2.btnUP_released = 0;
  padPlayer2.btnDOWN_released = 0;
  padPlayer2.btnLEFT_released = 0;
  padPlayer2.btnRIGHT_released = 0;
  padPlayer2.btnA_released = 0;
  padPlayer2.btnB_released = 0;
  iaData.strategyTimer = 0;  
  iaData.currentStrategy = 0;
  iaData.currentMove = 0;

  ennemy_strategiesInit();
}


void ennemy_initGame(){
  padPlayer2.btnUP_pressed = false;
  padPlayer2.btnDOWN_pressed = false;
  padPlayer2.btnLEFT_pressed = false;
  padPlayer2.btnRIGHT_pressed = false;
  padPlayer2.btnA_pressed = false;
  padPlayer2.btnB_pressed = false;
  padPlayer2.btnUP_released = 0;
  padPlayer2.btnDOWN_released = 0;
  padPlayer2.btnLEFT_released = 0;
  padPlayer2.btnRIGHT_released = 0;
  padPlayer2.btnA_released = 0;
  padPlayer2.btnB_released = 0;
  iaData.strategyTimer = 0;  
  iaData.currentStrategy = game.globalLoopCounter % 5;
  iaData.currentMove = 0;
}


void ennemy_manageStrategy(){
  iaData.currentMove = iaData.currentMove + 1;
  if(strategies[iaData.currentStrategy][iaData.currentMove]==99){iaData.currentMove = 0;}
  padPlayer2.btnUP_pressed = false;
  padPlayer2.btnDOWN_pressed = false;
  padPlayer2.btnLEFT_pressed = false;
  padPlayer2.btnRIGHT_pressed = false;
  padPlayer2.btnA_pressed = false;
  padPlayer2.btnB_pressed = false;
  padPlayer2.btnUP_released = 0;
  padPlayer2.btnDOWN_released = 0;
  padPlayer2.btnLEFT_released = 0;
  padPlayer2.btnRIGHT_released = 0;
  padPlayer2.btnA_released = 0;
  padPlayer2.btnB_released = 0;
  iaData.strategyTimer = 0; 
}


void ennemy_ia(){
  if(player2.x>=player1.x-7 && player2.x<=player1.x+8){
    int waitTimer = 1;

    switch(strategies[iaData.currentStrategy][iaData.currentMove]){
      
      //do nothing
      case 0:
      break;

      //protect
      case 1:
        padPlayer2.btnUP_released = padPlayer2.btnUP_released + 1;
      break;


      //SIMPLE attack
      case 2:
        padPlayer2.btnUP_released = 0;
        padPlayer2.btnB_pressed = false;
        if(player2.x-1>=player1.x+0 && player2.x-1<=player1.x+6){
          if(iaData.strategyTimer<10){
            if(iaData.strategyTimer==0){ padPlayer2.btnB_pressed = true; }
            iaData.strategyTimer = iaData.strategyTimer + 1;
          }
        }
      break;  

      //DOUBLE attack
      case 3:
        padPlayer2.btnUP_released = 0;
        padPlayer2.btnB_pressed = false;
        if(player2.x-1>=player1.x+0 && player2.x-1<=player1.x+6){
          if(iaData.strategyTimer<10){
            if(iaData.strategyTimer==0){ padPlayer2.btnB_pressed = true; }
            if(iaData.strategyTimer==3){ padPlayer2.btnB_pressed = true; }
            iaData.strategyTimer = iaData.strategyTimer + 1;
          }
        }
      break;  
      
      //TRIPLE attack
      case 4:
        padPlayer2.btnUP_released = 0;
        padPlayer2.btnB_pressed = false;
        if(player2.x-1>=player1.x+0 && player2.x-1<=player1.x+6){
          if(iaData.strategyTimer<10){
            if(iaData.strategyTimer==0){ padPlayer2.btnB_pressed = true; }
            if(iaData.strategyTimer==3){ padPlayer2.btnB_pressed = true; }
            if(iaData.strategyTimer==6){ padPlayer2.btnB_pressed = true; }
            iaData.strategyTimer = iaData.strategyTimer + 1;
          }
        }
      break;       
    }

  }else{
    padPlayer2.btnUP_pressed = false;
    padPlayer2.btnDOWN_pressed = false;
    padPlayer2.btnLEFT_pressed = false;
    padPlayer2.btnRIGHT_pressed = false;
    padPlayer2.btnA_pressed = false;
    padPlayer2.btnB_pressed = false;
    padPlayer2.btnUP_released = 0;
    padPlayer2.btnDOWN_released = 0;
    padPlayer2.btnLEFT_released = 0;
    padPlayer2.btnRIGHT_released = 0;
    padPlayer2.btnA_released = 0;
    padPlayer2.btnB_released = 0;  
    iaData.strategyTimer = 0;
  }
}


void ennemy_strategiesInit(){
  strategies[0][0] = 0;//do nothing
  strategies[0][1] = 1;//only protect
  strategies[0][2] = 4;//protect then attack
  strategies[0][3] = 3;//attack then protect
  strategies[0][4] = 3;//attack then protect
  strategies[0][5] = 1;//only protect
  strategies[0][6] = 2;//wait and attack
  strategies[0][7] = 2;//wait and attack
  strategies[0][8] = 0;//do nothing
  strategies[0][9] = 99;

  strategies[1][0] = 0;//do nothing
  strategies[1][1] = 2;//wait and attack
  strategies[1][2] = 2;//wait and attack
  strategies[1][3] = 1;//only protect
  strategies[1][4] = 2;//wait and attack
  strategies[1][5] = 1;//only protect
  strategies[1][6] = 2;//wait and attack
  strategies[1][7] = 1;//only protect
  strategies[1][8] = 4;//protect then attack
  strategies[1][9] = 99; 

  strategies[2][0] = 0;//do nothing 
  strategies[2][1] = 1;//only protect
  strategies[2][2] = 2;//wait and attack
  strategies[2][3] = 2;//wait and attack
  strategies[2][4] = 1;//only protect
  strategies[2][5] = 2;//wait and attack
  strategies[2][6] = 2;//wait and attack
  strategies[2][7] = 1;//only protect
  strategies[2][8] = 2;//wait and attack
  strategies[2][9] = 99;

  strategies[3][0] = 0;//do nothing 
  strategies[3][1] = 2;//wait and attack
  strategies[3][2] = 3;//attack then protect
  strategies[3][3] = 4;//protect then attack
  strategies[3][4] = 1;//only protect
  strategies[3][5] = 2;//wait and attack
  strategies[3][6] = 3;//attack then protect
  strategies[3][7] = 4;//protect then attack
  strategies[3][8] = 1;//only protect
  strategies[3][9] = 99;

  strategies[4][0] = 0;//do nothing
  strategies[4][1] = 4;//protect then attack
  strategies[4][2] = 4;//protect then attack
  strategies[4][3] = 1;//only protect
  strategies[4][4] = 0;//do nothing
  strategies[4][5] = 4;//protect then attack
  strategies[4][6] = 4;//protect then attack
  strategies[4][7] = 2;//wait and attack
  strategies[4][8] = 3;//attack then protect
  strategies[4][9] = 99;
}


