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
    int playRect, rulesRect, teamRect ;
    float startTheta, endTheta, currentTheta, currentEndTheta ;
    int gameMode ;
} Menu;

typedef struct {
    double x,y;
    int t;
} Map;

typedef struct {
    int x,y,click;
} Joueur ;


void drawRules(int* pages, float height, float width, int mouse_x, int mouse_y, ALLEGRO_FONT* gameFontRegles);
void drawTeam(float height, float width, int mouse_x, int mouse_y);
void drawMenu(int rect1, int rect2, int rect3, float height, float width);
void drawPlay(Map map[20][20],ALLEGRO_EVENT event,int mouse_x,int mouse_y,ALLEGRO_DISPLAY *display,ALLEGRO_COLOR white,ALLEGRO_COLOR black, ALLEGRO_COLOR gris,ALLEGRO_COLOR vert,ALLEGRO_COLOR red);
void drawMenuV2(Menu* mainMenu, float height, float width);
void moveGameModeArc(Menu** mainMenu) ;
void menuClick(Menu* mainMenu, float height, float width, int mouse_x, int mouse_y) ;
bool collisionCercle(int x,int y,Map map[20][20],int i,int j);

#endif
