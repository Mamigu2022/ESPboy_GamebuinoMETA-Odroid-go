void Nouvelle_Partie() {
  // Spawn d'un arbre aléatoire, un branche est vide 1/2
  for ( int i = 0; i < TAILLE_ARBRE; ++i ) {
    if ( i % 2 == 0 ) {
      arbre[i] = SANS_BRANCHE;
    } else {
      arbre[i] = random(BRANCHE_GAUCHE, BRANCHE_GAUCHE + 1);
    }
  }

  position_joueur = random(GAUCHE, DROITE + 1 ); // Spawn du joueur aléatoire
}

void mises_a_jour() {

  switch (statut_menu ) {
    case 1 : // IN GAME
      temps -= score * 0.1 + 1;

      // mort
      if ( temps <= 0 ) {
        statut_menu = 2;
        Update_Best_Score(score);
        gb.sound.playCancel();
        break;
      }
  }
}



void Coupe() {

  // test mort ou réussite
  if ( arbre[1] != position_joueur && arbre[0] != position_joueur) { // réussite
    ++score ;
    gb.sound.playTick();
  } else { // mort
    statut_menu = 2;
    arbre[1] = 0;
    Update_Best_Score(score);
    gb.sound.playCancel();
  }

  // décalage vers le bas
  for ( int i = 0; i < TAILLE_ARBRE - 1; ++i ) {
    arbre[i] = arbre[i + 1];
  }
  // nouvelle branche
  if ( arbre[TAILLE_ARBRE - 2] == SANS_BRANCHE ) {
    arbre[TAILLE_ARBRE - 1] = random(BRANCHE_GAUCHE, BRANCHE_GAUCHE + 1);
  } else {
    arbre[TAILLE_ARBRE - 1] = SANS_BRANCHE;
  }

  // le joueur a joué
  temps = TEMPS_MAX;
}

void Update_Best_Score(int score) {
  if ( bestscore < score ) {
    bestscore = score;
    gb.save.del(0);
    gb.save.set(0, score);
  }
}


