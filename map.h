#ifndef ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_O_MAP_H
#define ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_O_MAP_H
#include "personnage.h"
#include "jeu.h"

///FONCTION DU QUADRILLAGE DE LA MAP
void drawPlay(Joueurs *joueur,Map map[30][30], int joueurQuiJoue, int mouse_x,int mouse_y,double width, double height, double scalex, double scaley,ALLEGRO_DISPLAY *display, ALLEGRO_COLOR white, ALLEGRO_COLOR black, ALLEGRO_COLOR gris,ALLEGRO_COLOR vert,ALLEGRO_COLOR red);
void deplacementJoueur(Joueurs *joueur,Map map[30][30], int joueurQuiJoue, double scalex,double scaley, int* direction);
void caseJoueur(Joueurs *joueur,Map map[30][30], int joueurQuiJoue);
bool collisionCercle(int x,int y,Map map[30][30],int i,int j,double width);
void dessinerQuadrillage(double  width, double height,double scalex,double scaley,ALLEGRO_COLOR black);


///FONCTION DES SORTS
void barreSort (ALLEGRO_BITMAP* barreSort, InfoEcran ecran);
void drawSortDONKEYKONG( ALLEGRO_FONT* gameFont, Jeux jeu, InfoEcran ecran);
void drawSortPACMAN( ALLEGRO_FONT* gameFont, Jeux jeu, InfoEcran ecran) ;
void drawSortPEACH( ALLEGRO_FONT* gameFont, Jeux jeu, InfoEcran ecran);
void drawSortMARIO( ALLEGRO_FONT* gameFont, Jeux jeu, InfoEcran ecran);
void drawSortKIRBY( ALLEGRO_FONT* gameFont, Jeux jeu, InfoEcran ecran);
void sortEnFonctionDesClasses(ALLEGRO_FONT* gameFont, Jeux jeu, InfoEcran ecran, int joueurQuiJoue);
void initialiserSortEnFonctionDeLeurPosition (Jeux jeu, int joueurQuiJoue, InfoEcran ecran, int sort, Map joueur[30][30]);
int sortChoisi (InfoEcran ecran);
void verifierPADuJoueur (Jeux jeu, ALLEGRO_FONT* gameFont, InfoEcran ecran, int joueurQuiJoue, int PADuJoueur, int PADuSort);


void actionSortSAUTDONKEYKONG (Jeux jeu, int joueurQuiJoue, int mouse_x, int mouse_y, Map map[30][30], InfoEcran ecran);
void actionSortMORTEL (Jeux jeu, int joueurQuiJoue);
void actionSortPOINGGANT (Jeux jeu, int joueurQuiJoue);
void actionSortSOIN (Jeux jeu, int joueurQuiJoue);
void actionSortFLEUR (Jeux jeu, int joueurQuiJoue);
void actionSortPIEDPEACH (Jeux jeu, int joueurQuiJoue);
void actionSortPOING2 (Jeux jeu, int joueurQuiJoue);
void actionSortCOUPCORONA (Jeux jeu, int joueurQuiJoue);
void actionSortRECULERADVERSAIRE (Jeux jeu, int joueurQuiJoue, Map joueur[30][30]);
void actionSortCOUPDEPIED (Jeux jeu, int joueurQuiJoue, Map joueur[30][30]);
void actionSortPOING (Jeux jeu, int joueurQuiJoue);
void actionSortFLAMME (Jeux jeu, int joueurQuiJoue);


#endif //ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_O_MAP_H
