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
enum personnage {VIDE, MARIO,LUIGI,KIRBY,PEACH,ZELDA};


typedef struct {
    //enum personnage type = MARIO;
    ALLEGRO_BITMAP* image;
}Perso;


typedef struct {
    Perso personnage[5];
    int sort;  //par ex       1-> sort "empècher ladversaire de marcher           2-> sort "Tuer son prochain
} Classe;

typedef struct Info{
    double x,y;
    int xArrive, yArrive, caseX, caseY,caseXDepart,caseYDepart, actif, dep;
    char pseudo[MAXNOM];
    int nbLettrePseudo ;
    int PV, PM, PA;
    Classe classe; //1 : mario      2 : Luigi     3 : Kirby     4: Peach     5 : Zelda
}InfosJoueur;

typedef struct {
    int mouse_x, mouse_y ;
    float height, width ;
} infoEcran;



///FONCTION POUR COMMENCER A JOUER
void choixJoueur(float width, float height, int mouse_x, int mouse_y, ALLEGRO_FONT * gameFont, int* nbJoueur) ;
void drawChooseCharacter(float height, float width, ALLEGRO_FONT* gameFont, int* nbJoueur,int mouse_x, int mouse_y, InfosJoueur** joueur);

///RENTRER UN PSEUDO
char alphabet (int keycode, int* nbLettre) ;
void mettrePseudo(InfosJoueur** joueur, char lettre, int quelJoueurEstSelectionne, int* nbLettre) ;
void afficherPseudo(InfosJoueur* joueur, float width, float height, ALLEGRO_FONT* gameFont, int nbJoueur) ;


#endif
