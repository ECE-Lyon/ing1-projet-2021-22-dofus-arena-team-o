#ifndef ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_O_MENU_H
#define ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_O_MENU_H

#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <time.h>
#include "jeu.h"

#define RULESPAGEMAX 3
#define PI 3.141592

typedef struct {
    float startTheta, endTheta, currentTheta, currentEndTheta ;
} ArcDeCercle ;

/// A METTRE DANS UN FICHIER .C/.H CAR GRANDE STRUCTURE
typedef struct {
    int playRect, rulesRect, teamRect, gameMode;
    ArcDeCercle arc ;
    InfoEcran ecran ;
} Menu;

typedef struct {
    int pages;
    InfoEcran ecran ;
} Rules;

void initialiserMenu(Menu* mainMenu, float width, float height) ;
void drawMenuV2(Menu* mainMenu, ALLEGRO_FONT *gameFont);
void menuSouris(Menu* mainMenu, float height, float width, int mouse_x, int mouse_y) ;
void moveGameModeArc(Menu** mainMenu) ;
void drawRules(int* pages, float height, float width, int mouse_x, int mouse_y, ALLEGRO_FONT* gameFontRegles, ALLEGRO_FONT* gameFont);
void afficherPages(int pages, ALLEGRO_FONT* gameFontRegles, ALLEGRO_COLOR gameColor, float height, float width) ;
void drawTeam(float height, float width, int mouse_x, int mouse_y, ALLEGRO_FONT *gameFont, ALLEGRO_BITMAP* team);


#endif //ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_O_MENU_H
