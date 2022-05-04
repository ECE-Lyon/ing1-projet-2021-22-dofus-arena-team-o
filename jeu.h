#ifndef ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_O_JEU_H
#define ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_O_JEU_H

#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>

#define RULESPAGEMAX 7
#define mapX 20
#define mapY 16

#define PI 3.141592

enum gameMode {PLAY, RULES, TEAM, MENU, END};

typedef struct {
    int mouse_x, mouse_y ;
    float height, width ;
} infoEcran;


typedef struct {
    float startTheta, endTheta, currentTheta, currentEndTheta ;
} ArcDeCercle ;

/// A METTRE DANS UN FICHIER .C/.H CAR GRANDE STRUCTURE
typedef struct {
    int playRect, rulesRect, teamRect, gameMode;
    ArcDeCercle arc ;
    infoEcran ecran ;
} Menu;

typedef struct {
    int pages;
    infoEcran ecran ;
} Rules;


void drawRules(int* pages, float height, float width, int mouse_x, int mouse_y, ALLEGRO_FONT* gameFontRegles, ALLEGRO_FONT* gameFont);
typedef struct {
    double x,y;
    int t;
} Map;


void drawRules(int* pages, float height, float width, int mouse_x, int mouse_y, ALLEGRO_FONT* gameFontRegles, ALLEGRO_FONT *gameFont);
void drawTeam(float height, float width, int mouse_x, int mouse_y, ALLEGRO_FONT *gameFont);
void drawPlay(Map map[20][20],ALLEGRO_EVENT event,int mouse_x,int mouse_y,ALLEGRO_DISPLAY *display);
void drawMenuV2(Menu* mainMenu, ALLEGRO_FONT *gameFont);
void moveGameModeArc(Menu** mainMenu) ;
void menuSouris(Menu* mainMenu, float height, float width, int mouse_x, int mouse_y) ;
void drawPlay2(float width, float height, int mouse_x, int mouse_y) ;
bool collisionCercle(int x,int y,Map map[20][20],int i,int j);

#endif
