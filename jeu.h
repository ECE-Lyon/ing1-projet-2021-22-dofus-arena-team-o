#ifndef ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_O_JEU_H
#define ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_O_JEU_H

#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <time.h>

#define RULESPAGEMAX 3
#define mapX 19
#define mapY 14
#define MAXNOM 11

#define PI 3.141592

enum gameMode {PLAY, RULES, TEAM, MENU, CHOIXPERSO, END};
enum personnage {MARIO, PACMAN, KIRBY, PEACH, DONKEY_KONG, VIDE};
enum play {CHOIXNBJOUEUR, CHOIXCLASSE, PLATE, JEU};
enum sort {AUCUN, FLAMME, FATAL, RALENTIR, SPECIAL, STOP, RECULER, BARRE, PV};

typedef struct {
    int mouse_x, mouse_y ;
    double height, width ;
} InfoEcran;

typedef struct {
    int nbJoueur, joueurQuiJoue ;
    bool entrerPseudo ;
} InfosSurLesJoueurs;


typedef struct {
    ALLEGRO_BITMAP* iconeSort;
    int sort;
    int animation;
    int nbSort;
}Sort;

typedef struct {
    ALLEGRO_BITMAP* image;
    Sort sortADisposition[9];
}Classe;

typedef struct Info{
    double x,y;
    int xArrive, yArrive, caseX, caseY,caseXDepart,caseYDepart, actif, dep;
    char pseudo[MAXNOM];
    int nbLettrePseudo ;
    int PV, PM, PA, aChoisiClasse;
    int classe;//1 : mario      2 : Luigi     3 : Kirby     4: Peach     5 : Zelda
    int ordre;
}Joueurs;


///STRUCTURE PRINCIPALE DU JEU
typedef struct {
    InfosSurLesJoueurs info ;
    Joueurs* joueur ;
    Classe classes[5] ;
    int gameMode ;
}Jeux;

typedef struct {
    double x,y;
    int t;
    int obstacle;
} Map;

void initialiserIconeClasse(ALLEGRO_BITMAP* pacman, ALLEGRO_BITMAP* kirby, ALLEGRO_BITMAP* peach, ALLEGRO_BITMAP* mario, ALLEGRO_BITMAP* donkey_kong, Classe* classes);
void initialiserEcran (InfoEcran* ecran, double width, double height) ;
void initialiserJeu(Jeux* jeu) ;
void initialiserJoueur(Jeux* jeu, Map map[20][20]) ;
void initialiserSort (Classe* classe, ALLEGRO_BITMAP* sortFatal, ALLEGRO_BITMAP* sortFlamme, ALLEGRO_BITMAP* sortRalentir, ALLEGRO_BITMAP* sortSpecial, ALLEGRO_BITMAP* sortStop, ALLEGRO_BITMAP* sortReculer, ALLEGRO_BITMAP* afficherSort, ALLEGRO_BITMAP* afficherPV);

///FONCTION POUR COMMENCER A JOUER
void choixJoueur(float width, float height, int mouse_x, int mouse_y, ALLEGRO_FONT * gameFont, InfosSurLesJoueurs* infojoueur) ;
void drawChooseCharacter(InfoEcran ecran, ALLEGRO_FONT* gameFont, Jeux jeu, ALLEGRO_FONT* bigGameFont);

///RENTRER UN PSEUDO
char alphabet (int keycode, int* nbLettre) ;
void mettrePseudo(Joueurs** joueur, char lettre, int quelJoueurEstSelectionne, int* nbLettre) ;
void afficherPseudo(Jeux jeu, float width, float height, ALLEGRO_FONT* gameFont) ;

#endif
