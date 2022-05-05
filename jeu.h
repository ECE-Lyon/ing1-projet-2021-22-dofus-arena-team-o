#ifndef ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_O_JEU_H
#define ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_O_JEU_H

#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <time.h>

#define RULESPAGEMAX 3
#define mapX 20
#define mapY 16
#define MAXNOM 11

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

typedef struct {
    double x,y,xp,yp;
    int a,b,t;
} Joueur ;

typedef struct Info{
    int x, y; //position
    char pseudo[MAXNOM];
    int PV, PM, PA;
}InfosJoueur;


void afficherPages(int pages, ALLEGRO_FONT* gameFontRegles, ALLEGRO_COLOR gameColor, float height, float width) ;
void drawRules(int* pages, float height, float width, int mouse_x, int mouse_y, ALLEGRO_FONT* gameFontRegles, ALLEGRO_FONT *gameFont);
void drawTeam(float height, float width, int mouse_x, int mouse_y, ALLEGRO_FONT *gameFont, ALLEGRO_BITMAP* team);
void drawPlay(Map map[20][20],ALLEGRO_EVENT event,int mouse_x,int mouse_y,ALLEGRO_DISPLAY *display, ALLEGRO_COLOR white, ALLEGRO_COLOR black, ALLEGRO_COLOR gris,ALLEGRO_COLOR vert,ALLEGRO_COLOR red);
void drawMenuV2(Menu* mainMenu, ALLEGRO_FONT *gameFont);
void moveGameModeArc(Menu** mainMenu) ;
void deplacementJoueur(Joueur *joueur[],Map map[20][20]);
bool collisionCercle(int x,int y,Map map[20][20],int i,int j,double width);
void menuSouris(Menu* mainMenu, float height, float width, int mouse_x, int mouse_y) ;
void drawPlay2(float width, float height, int mouse_x, int mouse_y, ALLEGRO_FONT * gameFont,ALLEGRO_FONT *gameFontRegles, int* nbJoueur) ;
void drawChooseCharacter(float height, float width, int nbJoueur)  ;

char alphabet (int keycode, int* nbLettre) ;
char* getPseudo(InfosJoueur* joueur) ;

void mettrePseudo(InfosJoueur** joueur, char lettre, int quelJoueurEstSelectionne, int* nbLettre) ;
void afficherPseudo(InfosJoueur* joueur, float width, float height, ALLEGRO_FONT* gameFont, int nbJoueur) ;


#endif
