#include <Gamebuino-Meta.h> // Importation de la biliothèque GB

// constantes de l'arbre

const int SANS_BRANCHE = 0;
const int BRANCHE_GAUCHE = 1;
const int BRANCHE_DROITE = 2;
const int TAILLE_ARBRE = 5;

  

// constantes du joueur
const int GAUCHE = 1;
const int DROITE = 2;
const int TEMPS_MAX = 380;


int statut_menu = 0; // 0 = BERTIMAN | 1 = en jeu | 2 = GAME OVER
int arbre[TAILLE_ARBRE];  // Type d'arbre : branche à gauche|droite|sans branche
int position_joueur;  // soit GAUCHE, soit DROITE
int temps;
int score = 0;
int bestscore;
int animation = 0;


//const SaveDefault savefileDefaults[] = { 0, SAVETYPE_INT, 0, 0 };
void setup() {
  gb.begin();  // initialisation de la GB
//  gb.save.config(savefileDefaults);
  bestscore = gb.save.get(0); // récupération du best score
  Nouvelle_Partie();

}

void loop() {
  while (!gb.update()); // gestion les boutons et arrière plan + fps
  gb.lights.fill(BLACK);

  // ENTREES //
  entrees();

  // MISE A JOUR //
  mises_a_jour();

  // DRAW //
  draw();

}
