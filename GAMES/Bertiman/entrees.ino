boolean ButonPressed() {
  if ( gb.buttons.pressed(BUTTON_LEFT) |
       gb.buttons.pressed(BUTTON_RIGHT) |
       gb.buttons.pressed(BUTTON_UP) |
       gb.buttons.pressed(BUTTON_DOWN) |
       gb.buttons.pressed(BUTTON_A) |
       gb.buttons.pressed(BUTTON_B) ) {
        
    return true;
  }
  return false;
}


void entrees() {

  Bertiman_static.setFrame(position_joueur - 1);


  switch ( statut_menu ) {

    case 0 : // BERTIMAN
      if ( ButonPressed() ) {
        statut_menu = 1;
        temps = TEMPS_MAX;
        gb.sound.playOK();
      }
      break;

    case 1 : // IN GAME
      if (gb.buttons.pressed(BUTTON_LEFT) || gb.buttons.pressed(BUTTON_A)) {
        position_joueur = GAUCHE;
        Bertiman_static.setFrame(position_joueur - 1);
        Bertiman_hit.setFrame(position_joueur - 1);
        animation = 2;

        //gb.lights.setColor(0, 200, 0);
        //gb.lights.fillRect(0, 1, 1, 2);


      } else if (gb.buttons.pressed(BUTTON_RIGHT) || gb.buttons.pressed(BUTTON_B)) {
        position_joueur = DROITE;
        Bertiman_static.setFrame(position_joueur - 1);
        Bertiman_hit.setFrame(position_joueur - 1);
        animation = 2;

        //gb.lights.setColor(0, 200, 0);
        //gb.lights.fillRect(1, 1, 1, 2);
      }
      break;

    case 2 : // GAME OVER
      //gb.lights.setColor(180, 0, 0);
      //gb.lights.fillRect(0, 0, 2, 4);

      if (  ButonPressed() ) {
        statut_menu = 0;
        score = 0;
        Nouvelle_Partie();
      }
      break;
  }
}
