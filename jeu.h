#ifndef ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_O_JEU_H
#define ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_O_JEU_H

#include <stdio.h>
#include <stdlib.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <time.h>

#define RULESPAGEMAX 10
#define mapX 19
#define mapY 14
#define MAXNOM 11

#define PI 3.141592

enum sortPeach {COUPDEPIED, SORTFLEUR, SORTSOIN, NBSORT};
enum sortMario {POING2, CORONA, FLAMME};
enum sortPacman {SORTDEFENCE, RECULERADVERSAIRE, FLAMME1};
enum sortDK {POINGGANT, MORTEL, SAUT};
enum sortKirby {COUPDEPIED1, POING, FLAMME3};

///ENUM NECESSAIRE POUR FACILITER LE CODE ET SA LECTURE
enum gameMode {PLAY, RULES, TEAM, MENU, END};
enum personnage {MARIO, PACMAN, KIRBY, PEACH, DONKEY_KONG, VIDE};
enum play {CHOIXNBJOUEUR, CHOIXCLASSE, JEU, ORDRE, JOUER};
enum animation{RESPIRATION, MARCHER, ATTAQUE1, ATTAQUE2, ATTAQUE3, NBANIMATIONS};
//enum sort{AUCUN, FLAMME, POINGGANT, SAUT, MORTEL, POING2, COUPDEPIED, POING, RECULERADVERSAIRE, SORTDEFENCE, SORTSOIN,  CORONA, SORTFLEUR};


///STRUCTURE QU'ON PEUT METTRE EN PARAMETRES DE FONCTION POUR EVITER TROP DE PARAMETRES
typedef struct {
    int mouse_x, mouse_y ;
    double height, width ;
} InfoEcran;

///STRUCTURE DES PERSONNAGES QU'ON A BESOIN ICI ET DANS LE PERSONNAGE.C
typedef struct {
    ALLEGRO_BITMAP* iconeSort;
    int degatsOUsoin, portee, PA ;
}Sort;


typedef struct {
    double x, y, width, height ;
} Image ;
typedef struct {
    Image images[20] ;
    int nbImages, direction ;
    float x, y ;
} Animation ;

/// TOUTES LES INFOS DU JEU NECESSAIRES
typedef struct {
    int nbJoueur, joueurQuiJoue, compteur ;
    bool entrerPseudo ;
    int ordre[4];
    int collisionSourisMap[2][1] ;
    int clickSouris ;
} InfosSurLesJoueurs;

typedef struct {
    ALLEGRO_BITMAP* image;
    ALLEGRO_BITMAP* icone;
    ALLEGRO_BITMAP* SpriteSheet ;
    Sort sortADisposition[20];
    Animation animations[NBANIMATIONS] ;
}Classe;

typedef struct Info{
    double x,y;
    int xArrive, yArrive, caseX, caseY,caseXDepart,caseYDepart, actif, dep;
    char pseudo[MAXNOM];
    int nbLettrePseudo ;
    int sortAppuye;
    int PV, PM, PA ;
    int classe;
    int quelAnimation, sortSpecial ;
    int etat;
    int obstacle;
    //etat 0 (par defaut) joueur en vie // etat 1 : joueur est mort
}Joueurs;


///STRUCTURE PRINCIPALE DU JEU
typedef struct {
    InfosSurLesJoueurs info ;
    Joueurs* joueur ;
    Classe classes[5] ;
    int gameMode, gameMode2 ;
}Jeux;

///LA CARTE DU JEU
typedef struct {
    double x,y;
    int t;
    int obstacle;
    int joueurPresentDessus ;
} Map;

///INITIALISATION JEU
void initialiserIconeClasse(ALLEGRO_BITMAP* pacman, ALLEGRO_BITMAP* kirby, ALLEGRO_BITMAP* peach, ALLEGRO_BITMAP* mario, ALLEGRO_BITMAP* donkey_kong, ALLEGRO_BITMAP* pacmanRond, ALLEGRO_BITMAP* kirbyRond, ALLEGRO_BITMAP* peachRond, ALLEGRO_BITMAP* marioRond, ALLEGRO_BITMAP* donkey_kongRond, Classe* classes) ;
void initialiserEcran (InfoEcran* ecran, double width, double height) ;
void initialiserJeu(Jeux* jeu) ;
void initialiserJoueur(Jeux* jeu, Map map[30][30]) ;
void initialiserSortClasseKIRBY (Classe* classe, ALLEGRO_BITMAP* coupDePied, ALLEGRO_BITMAP* sortFlemme, ALLEGRO_BITMAP* poing);
void initialiserSortClasseDONKEYKONG (Classe* classe, ALLEGRO_BITMAP* sortMortel, ALLEGRO_BITMAP* poing, ALLEGRO_BITMAP* poing2);
void initialiserSortClassePEACH (Classe* classe, ALLEGRO_BITMAP* sortFleur, ALLEGRO_BITMAP* sortSoin, ALLEGRO_BITMAP* coupDePied);
void initialiserSortClasseMARIO (Classe* classe, ALLEGRO_BITMAP* sortCorona, ALLEGRO_BITMAP* sortFlamme, ALLEGRO_BITMAP* poing2);
void initialiserSortClassePACMAN (Classe* classe, ALLEGRO_BITMAP* reculerAdversaire, ALLEGRO_BITMAP* sortFlamme, ALLEGRO_BITMAP* sortDefence);
void boutonSuivantDansPlay(InfoEcran ecran, ALLEGRO_FONT* gameFont, int mouse_x, int mouse_y);

///FONCTION POUR COMMENCER A JOUER
void choixJoueur(float width, float height, int mouse_x, int mouse_y, ALLEGRO_FONT * gameFont, InfosSurLesJoueurs* infojoueur) ;
void drawChooseCharacter(InfoEcran ecran, ALLEGRO_FONT* gameFont, Jeux jeu, ALLEGRO_FONT* bigGameFont);

///RENTRER UN PSEUDO
char alphabet (int keycode, int* nbLettre) ;
void mettrePseudo(Joueurs** joueur, char lettre, int quelJoueurEstSelectionne, int* nbLettre) ;
void afficherPseudo(Jeux jeu, float width, float height, ALLEGRO_FONT* gameFont) ;

void afficherCaracteristiqueJoueur(Jeux jeu, InfoEcran ecran, int joueurQuiJoue, ALLEGRO_FONT* gameFont) ;

int getRandomInteger(int min, int max) ;
int verifierValeurTableau(int tab[], int valeurAverifier, int cbDeValeur) ;
int ordreDesJoueurs(InfosSurLesJoueurs* joueurs, int nbJoueur);
void afficherOrdre(Jeux jeu, InfoEcran ecran, ALLEGRO_FONT* gameFont) ;


#endif
