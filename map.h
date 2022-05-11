#ifndef ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_O_MAP_H
#define ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_O_MAP_H

#include "jeu.h"
#define mapX 20
#define mapY 16

///FONCTION DU QUADRILLAGE DE LA MAP
void drawPlay(Joueurs *joueur,Map map[20][20],int mouse_x,int mouse_y,double width, double height, double scalex, double scaley,ALLEGRO_DISPLAY *display, ALLEGRO_COLOR white, ALLEGRO_COLOR black, ALLEGRO_COLOR gris,ALLEGRO_COLOR vert,ALLEGRO_COLOR red);
void deplacementJoueur(Joueurs *joueur,Map map[20][20],double scalex,double scaley);
void caseJoueur(Joueurs *joueur,Map map[20][20]);
bool collisionCercle(int x,int y,Map map[20][20],int i,int j,double width);
void dessinerQuadrillage(double  width, double height,double scalex,double scaley,ALLEGRO_COLOR black);
void barreSort (ALLEGRO_BITMAP* barreSort, InfoEcran ecran);
void drawSortDONKEYKONG( ALLEGRO_FONT* gameFont, Jeux jeu, InfoEcran ecran);
void drawSortPACMAN( ALLEGRO_FONT* gameFont, Jeux jeu, InfoEcran ecran) ;
void drawSortPEACH( ALLEGRO_FONT* gameFont, Jeux jeu, InfoEcran ecran);
void drawSortMARIO( ALLEGRO_FONT* gameFont, Jeux jeu, InfoEcran ecran);
void drawSortKIRBY( ALLEGRO_FONT* gameFont, Jeux jeu, InfoEcran ecran);
void sortEnFonctionDesClasses(ALLEGRO_FONT* gameFont, Jeux jeu, InfoEcran ecran, int joueurQuiJoue,  ALLEGRO_BITMAP* barreSort);

void sortChoisi (Jeux jeu, InfoEcran ecran);




#endif //ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_O_MAP_H
