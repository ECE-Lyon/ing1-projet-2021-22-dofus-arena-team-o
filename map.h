#ifndef ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_O_MAP_H
#define ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_O_MAP_H

#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <time.h>
#include "jeu.h"
#define mapX 20
#define mapY 16

typedef struct {
    double x,y;
    int t;
} Map;

///FONCTION DU QUADRILLAGE DE LA MAP
void drawPlay(InfosJoueur *joueur,Map map[20][20],int mouse_x,int mouse_y,double width, double height, double scalex, double scaley,ALLEGRO_DISPLAY *display, ALLEGRO_COLOR white, ALLEGRO_COLOR black, ALLEGRO_COLOR gris,ALLEGRO_COLOR vert,ALLEGRO_COLOR red);
void deplacementJoueur(InfosJoueur *joueur,Map map[20][20],double scalex,double scaley);
void caseJoueur(InfosJoueur *joueur,Map map[20][20]);
bool collisionCercle(int x,int y,Map map[20][20],int i,int j,double width);

#endif //ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_O_MAP_H
