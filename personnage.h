#ifndef ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_O_PERSONNAGE_H
#define ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_O_PERSONNAGE_H
#include "jeu.h"



void initialiserImageAnimationsKirby(Animation animations[]) ;
void initialiserImageAnimationsMario(Animation animations[]) ;
void initialiserImageAnimationsPacman(Animation animations[]) ;
void initialiserImageAnimationsDK(Animation animations[]) ;
void initialiserImageAnimationsPeach(Animation animations[]) ;
void afficherPersonnage(Jeux jeu, Map map[30][30], InfoEcran ecran, Timer* timerJeu2, double scalex, double scaley, ALLEGRO_BITMAP* shield ,ALLEGRO_BITMAP* effect, ALLEGRO_FONT* gameFont) ;
void determinerDirection(Jeux jeu) ;


#endif //ING1_PROJET_2021_22_DOFUS_ARENA_TEAM_O_PERSONNAGE_H
