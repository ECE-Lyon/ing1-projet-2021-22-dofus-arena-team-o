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
enum play {CHOIXNBJOUEUR, CHOIXCLASSE, JEU};


typedef struct {
    int mouse_x, mouse_y ;
    double height, width ;
} InfoEcran;

typedef struct {
    int nbJoueur, joueurQuiJoue ;
} InfosSurLesJoueurs;

typedef struct {
    //enum personnage type = MARIO;
    ALLEGRO_BITMAP* image;
    int sort ;
}Classe;




typedef struct Info{
    double x,y;
    int xArrive, yArrive, caseX, caseY,caseXDepart,caseYDepart, actif, dep;
    char pseudo[MAXNOM];
    int nbLettrePseudo ;
    int PV, PM, PA;
    Classe classe; //1 : mario      2 : Luigi     3 : Kirby     4: Peach     5 : Zelda
}Joueurs;

typedef struct {
    InfosSurLesJoueurs info ;
    Joueurs* joueur ;
    Classe classes[5] ;
}Jeu;

void initialiserEcran (InfoEcran* ecran, double width, double height) ;
void initialiserJoueur(Joueurs* joueur, InfosSurLesJoueurs* infoJoueur) ;

///FONCTION POUR COMMENCER A JOUER
void choixJoueur(float width, float height, int mouse_x, int mouse_y, ALLEGRO_FONT * gameFont, InfosSurLesJoueurs* infojoueur) ;
void drawChooseCharacter(InfoEcran ecran, ALLEGRO_FONT* gameFont, int* nbJoueur, Joueurs** joueur, ALLEGRO_BITMAP* kirby, ALLEGRO_BITMAP* pacman);

///RENTRER UN PSEUDO
char alphabet (int keycode, int* nbLettre) ;
void mettrePseudo(Joueurs** joueur, char lettre, int quelJoueurEstSelectionne, int* nbLettre) ;
void afficherPseudo(Joueurs* joueur, float width, float height, ALLEGRO_FONT* gameFont, int nbJoueur) ;


#endif
