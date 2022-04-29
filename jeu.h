#ifndef ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_O_JEU_H
#define ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_O_JEU_H

#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>

#define RULESPAGEMAX 5

enum gameMode {PLAY, RULES, TEAM, MENU, END};

void drawRules(int* pages, float height, float width);
void drawTeam(float height, float width);
void drawMenu(int rect1, int rect2, int rect3, float height, float width);

#endif
