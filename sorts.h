#ifndef ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_O_SORTS_H
#define ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_O_SORTS_H
#include "jeu.h"
#include "map.h"

//enum sortPeach {COUPDEPIED, SORTFLEUR, SORTSOIN, NBSORT};
//enum sortMario {POING2, CORONA, FLAMME};
//enum sortPacman {SORTDEFENCE, RECULERADVERSAIRE, FLAMME};
//enum sortDK {POINGGANT, MORTEL, SAUT};
//enum sortKirby {COUPDEPIED, POING, FLAMME};



///FONCTION DES SORTS
void barreSort (ALLEGRO_BITMAP* barreSort, InfoEcran ecran);
void drawSortDONKEYKONG( ALLEGRO_FONT* gameFont, Jeux jeu, InfoEcran ecran);
void drawSortPACMAN( ALLEGRO_FONT* gameFont, Jeux jeu, InfoEcran ecran) ;
void drawSortPEACH( ALLEGRO_FONT* gameFont, Jeux jeu, InfoEcran ecran);
void drawSortMARIO( ALLEGRO_FONT* gameFont, Jeux jeu, InfoEcran ecran);
void drawSortKIRBY( ALLEGRO_FONT* gameFont, Jeux jeu, InfoEcran ecran);
void sortEnFonctionDesClasses(ALLEGRO_FONT* gameFont,ALLEGRO_FONT* smallameFont, Jeux jeu, InfoEcran ecran, int joueurQuiJoue);
void sortChoisi (InfoEcran ecran, int* sortAppuye);


void actionSortRECULERADVERSAIRE (Jeux jeu, int joueurQuiJoue, Map joueur[30][30]);
void actionSortCOUPDEPIED (Jeux jeu, int joueurQuiJoue, Map joueur[30][30], InfoEcran ecran);


void dessinerPorteeSortLigne(Map map[30][30], double scalex, double scaley, Jeux jeu, int sortAppuye) ;
void dessinerPorteeSortRect(Map map[30][30], double scalex, double scaley, Jeux jeu, int sortAppuye) ;
void afficherPortee(Map map[30][30], double scalex, double scaley, Jeux jeu, int joueurQuiJoue) ;
bool verifierPorteeLigne(Jeux jeu, int sortAppuye) ;
bool verifierPorteeRect(Jeux jeu, int sortAppuye) ;
void appliquerSort(Jeux* jeu, int joueurQuiJoue, Map map[30][30], Timer* timerJeu2) ;
void appuyerSortSurMap(Jeux* jeu, Map map[30][30], Timer* timerJeu2) ;

#endif //ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_O_SORTS_H
