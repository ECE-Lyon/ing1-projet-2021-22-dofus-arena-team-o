#ifndef ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_O_JEU_H
#define ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_O_JEU_H

#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>

#define RULESPAGEMAX 7

#define PI 3.141592

enum gameMode {PLAY, RULES, TEAM, MENU, END};

typedef struct {
    int playRect, rulesRect, teamRect ;
    float startTheta, endTheta, currentTheta, currentEndTheta ;
    int gameMode ;
    } Menu;

void drawRules(int* pages, float height, float width, int mouse_x, int mouse_y);
void drawTeam(float height, float width, int mouse_x, int mouse_y);
void drawMenu(int rect1, int rect2, int rect3, float height, float width);
void drawMenuV2(Menu* mainMenu, float height, float width);
void moveGameModeArc(Menu** mainMenu) ;
void menuClick(Menu* mainMenu, float height, float width, int mouse_x, int mouse_y) ;

#endif
