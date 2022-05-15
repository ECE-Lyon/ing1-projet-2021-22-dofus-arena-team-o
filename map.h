#ifndef ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_O_MAP_H
#define ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_O_MAP_H
#include "personnage.h"
#include "jeu.h"

///FONCTION DU QUADRILLAGE DE LA MAP
void drawPlay(Joueurs *joueur,Map map[30][30], int joueurQuiJoue, int mouse_x,int mouse_y,double width, double height, double scalex, double scaley, ALLEGRO_COLOR white, ALLEGRO_COLOR black, ALLEGRO_COLOR gris,ALLEGRO_COLOR vert,ALLEGRO_COLOR red);
void deplacementJoueur(Joueurs *joueur,Map map[30][30], int joueurQuiJoue, double scalex,double scaley, int* direction);
void caseJoueur(Joueurs *joueur,Map map[30][30], int joueurQuiJoue);
bool collisionCercle(int x,int y,Map map[30][30],int i,int j,double width);
void dessinerQuadrillage(double  width, double height,double scalex,double scaley,ALLEGRO_COLOR black);


void dessinerCase(Map map[30][30], int caseX, int caseY, double scalex, double scaley) ;


#endif //ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_O_MAP_H
