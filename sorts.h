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
void initialiserSortEnFonctionDeLeurPosition (Jeux* jeu, int joueurQuiJoue, InfoEcran ecran, int sort, Map joueur[30][30]);
void sortChoisi (InfoEcran ecran, int* sortAppuye);
int verifierPADuJoueur (Jeux jeu, int joueurQuiJoue, int PADuJoueur, int PADuSort);
void verifierPV (Jeux jeu, int joueurQuiJoue);


void actionSortSAUTDONKEYKONG (Jeux jeu, int joueurQuiJoue, int mouse_x, int mouse_y, Map map[30][30], InfoEcran ecran);
void actionSortMORTEL (Jeux jeu, int joueurQuiJoue);
void actionSortPOINGGANT (Jeux jeu, int joueurQuiJoue);
void actionSortSOIN (Jeux jeu, int joueurQuiJoue);
void actionSortFLEUR (Jeux jeu, int joueurQuiJoue);
void actionSortPIEDPEACH (Jeux jeu, int joueurQuiJoue, InfoEcran ecran);
void actionSortPOING2 (Jeux jeu, int joueurQuiJoue);
void actionSortCOUPCORONA (Jeux jeu, int joueurQuiJoue);
void actionSortRECULERADVERSAIRE (Jeux jeu, int joueurQuiJoue, Map joueur[30][30]);
void actionSortCOUPDEPIED (Jeux jeu, int joueurQuiJoue, Map joueur[30][30], InfoEcran ecran);
void actionSortPOING (Jeux jeu, int joueurQuiJoue, InfoEcran ecran);
void actionSortFLAMME (Jeux* jeu, int joueurQuiJoue, Map map[30][30]);

void dessinerPorteeSortLigne(Map map[30][30], double scalex, double scaley, Jeux jeu, int sortAppuye) ;
void dessinerPorteeSortRect(Map map[30][30], double scalex, double scaley, Jeux jeu, int sortAppuye) ;
void afficherPortee(Map map[30][30], double scalex, double scaley, Jeux jeu, int joueurQuiJoue) ;
bool verifierPorteeLigne(Jeux jeu, int sortAppuye) ;
bool verifierPorteeRect(Jeux jeu, int sortAppuye) ;
void appliquerSort(Jeux* jeu, int joueurQuiJoue, Map map[30][30]) ;
void appuyerSortSurMap(Jeux* jeu, Map map[30][30]) ;

#endif //ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_O_SORTS_H
