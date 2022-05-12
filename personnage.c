#include "personnage.h"

void initialiserImageAnimationsKirby(Animation animations[]) {
                /// ANIMATION 1 ///
    animations[MARCHER].nbImages = 10 ;
    for(int i = 0 ; i < animations[MARCHER].nbImages ; i++) {
        animations[MARCHER].images[i].y = 58 * 3.2 ;
        animations[MARCHER].images[i].height = 26 * 3.2 ;
    }
    ///IMAGE 1
    animations[MARCHER].images[0].x = 0 * 3.2 ;
    animations[MARCHER].images[0].width = 26 * 3.2 ;

    ///IMAGE 2
    animations[MARCHER].images[1].x = 26 * 3.2 ;
    animations[MARCHER].images[1].width = 25 * 3.2 ;

    ///IMAGE 3
    animations[MARCHER].images[2].x = 51 * 3.2 ;
    animations[MARCHER].images[2].width = 27 * 3.2 ;

    ///IMAGE 4
    animations[MARCHER].images[3].x = 78 * 3.2 ;
    animations[MARCHER].images[3].width = 24 * 3.2 ;

    ///IMAGE 5
    animations[MARCHER].images[4].x = 102 * 3.2 ;
    animations[MARCHER].images[4].width = 21 * 3.2 ;

    ///IMAGE 6
    animations[MARCHER].images[5].x = 123 * 3.2 ;
    animations[MARCHER].images[5].width = 22 * 3.2 ;

    ///IMAGE 7
    animations[MARCHER].images[6].x = 145 * 3.2 ;
    animations[MARCHER].images[6].width = 28 * 3.2 ;;

    ///IMAGE 8
    animations[MARCHER].images[7].x = 173 * 3.2 ;
    animations[MARCHER].images[7].width = 29 * 3.2 ;

    ///IMAGE 9
    animations[MARCHER].images[8].x = 202 * 3.2 ;
    animations[MARCHER].images[8].width = 26 * 3.2 ;

    ///IMAGE 10
    animations[MARCHER].images[9].x = 228 * 3.2 ;
    animations[MARCHER].images[9].width = 24 * 3.2 ;

                 /// ANIMATION 2 ///
    animations[ATTAQUE1].nbImages = 12 ;
    for(int i = 0 ; i < animations[ATTAQUE1].nbImages ; i++) {
        animations[ATTAQUE1].images[i].y = 206 * 3.2;
        animations[ATTAQUE1].images[i].height = 42 * 3.2;
    }
    ///IMAGE 1
    animations[ATTAQUE1].images[0].x = 0 * 3.2;
    animations[ATTAQUE1].images[0].width = 36 * 3.2;

    ///IMAGE 2
    animations[ATTAQUE1].images[1].x = 36 * 3.2;
    animations[ATTAQUE1].images[1].width = 36 * 3.2;

    ///IMAGE 3
    animations[ATTAQUE1].images[2].x = 72* 3.2 ;
    animations[ATTAQUE1].images[2].width = 26* 3.2 ;

    ///IMAGE 4
    animations[ATTAQUE1].images[3].x = 96 * 3.2;
    animations[ATTAQUE1].images[3].width = 33 * 3.2;

    ///IMAGE 5
    animations[ATTAQUE1].images[4].x = 131 * 3.2;
    animations[ATTAQUE1].images[4].width = 36 * 3.2;

    ///IMAGE 6
    animations[ATTAQUE1].images[5].x = 167 * 3.2;
    animations[ATTAQUE1].images[5].width = 32 * 3.2;

    ///IMAGE 7
    animations[ATTAQUE1].images[6].x = 199 * 3.2;
    animations[ATTAQUE1].images[6].width = 24 * 3.2;

    ///IMAGE 8
    animations[ATTAQUE1].images[7].x = 223 * 3.2;
    animations[ATTAQUE1].images[7].width = 26 * 3.2;

    ///IMAGE 9
    animations[ATTAQUE1].images[8].x = 249 * 3.2;
    animations[ATTAQUE1].images[8].width = 26 * 3.2;

    ///IMAGE 10
    animations[ATTAQUE1].images[9].x = 275 * 3.2;
    animations[ATTAQUE1].images[9].width = 27 * 3.2;

    ///IMAGE 11
    animations[ATTAQUE1].images[10].x = 302 * 3.2;
    animations[ATTAQUE1].images[10].width = 27 * 3.2;

    ///IMAGE 12
    animations[ATTAQUE1].images[11].x = 329 * 3.2;
    animations[ATTAQUE1].images[11].width = 24 * 3.2;

                /// ANIMATION 3 ///
    animations[RESPIRATION].nbImages = 15 ;
    for(int i = 0 ; i < animations[RESPIRATION].nbImages ; i++) {
        animations[RESPIRATION].images[i].y = 0 * 3.2;
        animations[RESPIRATION].images[i].height = 24 * 3.2;
    }
    ///IMAGE 1
    animations[RESPIRATION].images[0].x = 0 * 3.2;
    animations[RESPIRATION].images[0].width = 28 * 3.2;

    ///IMAGE 2
    animations[RESPIRATION].images[1].x = 28 * 3.2;
    animations[RESPIRATION].images[1].width = 27 * 3.2;

    ///IMAGE 3
    animations[RESPIRATION].images[2].x = 55 * 3.2;
    animations[RESPIRATION].images[2].width = 30 * 3.2;

    ///IMAGE 4
    animations[RESPIRATION].images[3].x = 85 * 3.2;
    animations[RESPIRATION].images[3].width = 26 * 3.2;

    ///IMAGE 5
    animations[RESPIRATION].images[4].x = 111 * 3.2;
    animations[RESPIRATION].images[4].width = 26 * 3.2;

    ///IMAGE 6
    animations[RESPIRATION].images[5].x = 137 * 3.2;
    animations[RESPIRATION].images[5].width = 29 * 3.2;

    ///IMAGE 7
    animations[RESPIRATION].images[6].x = 166 * 3.2;
    animations[RESPIRATION].images[6].width = 28 * 3.2;

    ///IMAGE 8
    animations[RESPIRATION].images[7].x = 194 * 3.2;
    animations[RESPIRATION].images[7].width = 29 * 3.2;

    ///IMAGE 9
    animations[RESPIRATION].images[8].x = 223 * 3.2;
    animations[RESPIRATION].images[8].width = 28 * 3.2;

    ///IMAGE 10
    animations[RESPIRATION].images[9].x = 251 * 3.2;
    animations[RESPIRATION].images[9].width = 29 * 3.2;

    ///IMAGE 10
    animations[RESPIRATION].images[10].x = 280 * 3.2;
    animations[RESPIRATION].images[10].width = 27 * 3.2;

    ///IMAGE 12
    animations[RESPIRATION].images[11].x = 307 * 3.2;
    animations[RESPIRATION].images[11].width = 25 * 3.2;

    ///IMAGE 13
    animations[RESPIRATION].images[12].x = 332 * 3.2;
    animations[RESPIRATION].images[12].width = 25 * 3.2;

    ///IMAGE 14
    animations[RESPIRATION].images[13].x = 357 * 3.2;
    animations[RESPIRATION].images[13].width = 27 * 3.2;

    ///IMAGE 15
    animations[RESPIRATION].images[14].x = 384 * 3.2;
    animations[RESPIRATION].images[14].width = 25 * 3.2;

    ///IMAGE 16
    animations[RESPIRATION].images[15].x = 409 * 3.2;
    animations[RESPIRATION].images[15].width = 25 * 3.2;

    ///IMAGE 17
    animations[RESPIRATION].images[16].x = 434 * 3.2;
    animations[RESPIRATION].images[16].width = 28 * 3.2;

}
void initialiserImageAnimationsPacman(Animation animations[]) {
                 /// ANIMATION 1
    animations[MARCHER].nbImages = 10 ;
    for(int i = 0 ; i < animations[MARCHER].nbImages ; i++) {
        animations[MARCHER].images[i].y = 34 * 3;
        animations[MARCHER].images[i].height = 37 * 3;
    }
    ///IMAGE 1
    animations[MARCHER].images[0].x = 0 * 3;
    animations[MARCHER].images[0].width = 35 * 3;

    ///IMAGE 2
    animations[MARCHER].images[1].x = 35 * 3;
    animations[MARCHER].images[1].width = 31 * 3;

    ///IMAGE 3
    animations[MARCHER].images[2].x = 66 * 3;
    animations[MARCHER].images[2].width = 25 * 3;

    ///IMAGE 4
    animations[MARCHER].images[3].x = 91 * 3;
    animations[MARCHER].images[3].width = 26 * 3;

    ///IMAGE 5
    animations[MARCHER].images[4].x = 117 * 3;
    animations[MARCHER].images[4].width = 27 * 3;

    ///IMAGE 6
    animations[MARCHER].images[5].x = 144 * 3;
    animations[MARCHER].images[5].width = 29 * 3;

    ///IMAGE 7
    animations[MARCHER].images[6].x = 173 * 3;
    animations[MARCHER].images[6].width = 26 * 3;

    ///IMAGE 8
    animations[MARCHER].images[7].x = 199 * 3;
    animations[MARCHER].images[7].width = 25 * 3;

    ///IMAGE 9
    animations[MARCHER].images[8].x = 224 * 3;
    animations[MARCHER].images[8].width = 28 * 3;

    ///IMAGE 10
    animations[MARCHER].images[9].x = 252 * 3;
    animations[MARCHER].images[9].width = 35 * 3;

                 /// ANIMATION 2
    animations[RESPIRATION].nbImages = 7 ;
    for(int i = 0 ; i < animations[RESPIRATION].nbImages ; i++) {
        animations[RESPIRATION].images[i].y = 360 * 3;
        animations[RESPIRATION].images[i].height = 40 * 3;
    }
    ///IMAGE 1
    animations[RESPIRATION].images[0].x = 390 * 3;
    animations[RESPIRATION].images[0].width = 28 * 3;

    ///IMAGE 2
    animations[RESPIRATION].images[1].x = 418 * 3;
    animations[RESPIRATION].images[1].width = 35 * 3;

    ///IMAGE 3
    animations[RESPIRATION].images[2].x = 453 * 3;
    animations[RESPIRATION].images[2].width = 37 * 3;

    ///IMAGE 4
    animations[RESPIRATION].images[3].x = 490 * 3;
    animations[RESPIRATION].images[3].width = 31 * 3;

    ///IMAGE 5
    animations[RESPIRATION].images[4].x = 521 * 3;
    animations[RESPIRATION].images[4].width = 33 * 3;

    ///IMAGE 6
    animations[RESPIRATION].images[5].x = 554 * 3;
    animations[RESPIRATION].images[5].width = 35 * 3;

    ///IMAGE 7
    animations[RESPIRATION].images[6].x = 589 * 3;
    animations[RESPIRATION].images[6].width = 38 * 3;

}
void initialiserImageAnimationsPeach(Animation animations[]) {
              /// ANIMATION 1 ///
    animations[MARCHER].nbImages = 6 ;
    for(int i = 0 ; i < animations[MARCHER].nbImages ; i++) {
        animations[MARCHER].images[i].y = 114 * 2;
        animations[MARCHER].images[i].height = 40 * 2;
        animations[MARCHER].images[i].width = 29 * 2;

    }
    ///IMAGE 1
    animations[MARCHER].images[0].x = 130 * 2;

    ///IMAGE 2
    animations[MARCHER].images[1].x = 159 * 2;

    ///IMAGE 3
    animations[MARCHER].images[2].x = 188 * 2;

    ///IMAGE 4
    animations[MARCHER].images[3].x = 217 * 2;

    ///IMAGE 5
    animations[MARCHER].images[4].x = 246 * 2;

    ///IMAGE 6
    animations[MARCHER].images[5].x = 275 * 2;

                /// ANIMATION 2 ///
    animations[RESPIRATION].nbImages = 4 ;
    for(int i = 0 ; i < animations[RESPIRATION].nbImages ; i++) {
        animations[RESPIRATION].images[i].y = 29 * 2;
        animations[RESPIRATION].images[i].height = 41 * 2;
        animations[RESPIRATION].images[i].width = 24 * 2;
    }
    ///IMAGE 1
    animations[RESPIRATION].images[0].x = 5 * 2;

    ///IMAGE 2
    animations[RESPIRATION].images[1].x = 29 * 2;

    ///IMAGE 3
    animations[RESPIRATION].images[2].x = 53 * 2;

    ///IMAGE 4
    animations[RESPIRATION].images[3].x = 77 * 2;

}
void initialiserImageAnimationsMario(Animation animations[]) {
           /// ANIMATION 1 ///
    animations[MARCHER].nbImages = 8 ;
    for(int i = 0 ; i < animations[MARCHER].nbImages ; i++) {
        animations[MARCHER].images[i].y = 51 * 2.5;
        animations[MARCHER].images[i].height = 37 * 2.5;
    }
    ///IMAGE 1
    animations[MARCHER].images[0].x = 12 * 2.5;
    animations[MARCHER].images[0].width = 24 * 2.5;

    ///IMAGE 2
    animations[MARCHER].images[1].x = 36 * 2.5;
    animations[MARCHER].images[1].width = 31 * 2.5;

    ///IMAGE 3
    animations[MARCHER].images[2].x = 67 * 2.5;
    animations[MARCHER].images[2].width = 34 * 2.5;

    ///IMAGE 4
    animations[MARCHER].images[3].x = 101 * 2.5;
    animations[MARCHER].images[3].width = 27 * 2.5;

    ///IMAGE 5
    animations[MARCHER].images[4].x = 128 * 2.5;
    animations[MARCHER].images[4].width = 26 * 2.5;

    ///IMAGE 6
    animations[MARCHER].images[5].x = 154 * 2.5;
    animations[MARCHER].images[5].width = 30 * 2.5;

    ///IMAGE 7
    animations[MARCHER].images[6].x = 184 * 2.5;
    animations[MARCHER].images[6].width = 32 * 2.5;

    ///IMAGE 8
    animations[MARCHER].images[7].x = 216 * 2.5;
    animations[MARCHER].images[7].width = 28 * 2.5;

                    /// ANIMATION 2 ///
    animations[RESPIRATION].nbImages = 4 ;
    for(int i = 0 ; i < animations[RESPIRATION].nbImages ; i++) {
        animations[RESPIRATION].images[i].y = 9 * 2.5;
        animations[RESPIRATION].images[i].height = 37 * 2.5;
        animations[RESPIRATION].images[i].width = 25 * 2.5;
    }
    ///IMAGE 1
    animations[RESPIRATION].images[0].x = 9 * 2.5;

    ///IMAGE 2
    animations[RESPIRATION].images[1].x = 34 * 2.5;

    ///IMAGE 3
    animations[RESPIRATION].images[2].x = 59 * 2.5;

    ///IMAGE 4
    animations[RESPIRATION].images[3].x = 84 * 2.5;

                    /// ANIMATION 3 ///
    animations[ATTAQUE1].nbImages = 6 ;
    for(int i = 0 ; i < animations[ATTAQUE1].nbImages ; i++) {
        animations[ATTAQUE1].images[i].y = 305 * 2.5;
        animations[ATTAQUE1].images[i].height = 35 * 2.5;
    }
    ///IMAGE 1
    animations[ATTAQUE1].images[0].x = 13 * 2.5;
    animations[ATTAQUE1].images[0].width = 33 * 2.5;

    ///IMAGE 1
    animations[ATTAQUE1].images[1].x = 13 * 2.5;
    animations[ATTAQUE1].images[1].width = 33 * 2.5;

    ///IMAGE 1
    animations[ATTAQUE1].images[2].x = 13 * 2.5;
    animations[ATTAQUE1].images[2].width = 33 * 2.5;


}
void initialiserImageAnimationsDK(Animation animations[]) {
             /// ANIMATION 1 ///
    animations[MARCHER].nbImages = 8 ;
    for(int i = 0 ; i < animations[MARCHER].nbImages ; i++) {
        animations[MARCHER].images[i].y = 0 * 2.6;
        animations[MARCHER].images[i].height = 36 * 2.6;
    }
    ///IMAGE 1
    animations[MARCHER].images[0].x = 255 * 2.6;
    animations[MARCHER].images[0].width = 30 * 2.6;

    ///IMAGE 2
    animations[MARCHER].images[1].x = 285 * 2.6;
    animations[MARCHER].images[1].width = 28 * 2.6;

    ///IMAGE 3
    animations[MARCHER].images[2].x = 313 * 2.6;
    animations[MARCHER].images[2].width = 31 * 2.6;

    ///IMAGE 4
    animations[MARCHER].images[3].x = 344 * 2.6;
    animations[MARCHER].images[3].width = 33 * 2.6;

    ///IMAGE 5
    animations[MARCHER].images[4].x = 377 * 2.6;
    animations[MARCHER].images[4].width = 31 * 2.6;

    ///IMAGE 6
    animations[MARCHER].images[5].x = 408 * 2.6;
    animations[MARCHER].images[5].width = 28 * 2.6;

    ///IMAGE 7
    animations[MARCHER].images[6].x = 436 * 2.6;
    animations[MARCHER].images[6].width = 28 * 2.6;

    ///IMAGE 8
    animations[MARCHER].images[7].x = 464 * 2.6;
    animations[MARCHER].images[7].width = 29 * 2.6;

            /// ANIMATION 1 ///
    animations[RESPIRATION].nbImages = 8 ;
    for(int i = 0 ; i < animations[RESPIRATION].nbImages ; i++) {
        animations[RESPIRATION].images[i].y = 107 * 2.6;
        animations[RESPIRATION].images[i].height = 44 * 2.6;
    }
    ///IMAGE 1
    animations[RESPIRATION].images[0].x = 277 * 2.6;
    animations[RESPIRATION].images[0].width = 27 * 2.6;

    ///IMAGE 2
    animations[RESPIRATION].images[1].x = 304 * 2.6;
    animations[RESPIRATION].images[1].width = 32 * 2.6;

    ///IMAGE 3
    animations[RESPIRATION].images[2].x = 336 * 2.6;
    animations[RESPIRATION].images[2].width = 34 * 2.6;

    ///IMAGE 4
    animations[RESPIRATION].images[3].x = 370 * 2.6;
    animations[RESPIRATION].images[3].width = 28 * 2.6;

    ///IMAGE 5
    animations[RESPIRATION].images[4].x = 398 * 2.6;
    animations[RESPIRATION].images[4].width = 24 * 2.6;

    ///IMAGE 6
    animations[RESPIRATION].images[5].x = 422 * 2.6;
    animations[RESPIRATION].images[5].width = 32 * 2.6;

    ///IMAGE 7
    animations[RESPIRATION].images[6].x = 454 * 2.6;
    animations[RESPIRATION].images[6].width = 35 * 2.6;

    ///IMAGE 8
    animations[RESPIRATION].images[7].x = 489 * 2.6;
    animations[RESPIRATION].images[7].width = 29 * 2.6;
}



void afficherPersonnage(Jeux jeu, double scalex, double scaley) {
    for (int i = 0; i < jeu.info.nbJoueur; i++) {
        switch (jeu.joueur[i].classe) {
            case KIRBY : {
                al_draw_bitmap_region(jeu.classes[KIRBY].SpriteSheet, jeu.classes[KIRBY].animations[jeu.joueur[i].quelAnimation].images[jeu.info.compteur%jeu.classes[KIRBY].animations[jeu.joueur[i].quelAnimation].nbImages].x, jeu.classes[KIRBY].animations[jeu.joueur[i].quelAnimation].images[jeu.info.compteur%jeu.classes[KIRBY].animations[jeu.joueur[i].quelAnimation].nbImages].y, jeu.classes[KIRBY].animations[jeu.joueur[i].quelAnimation].images[jeu.info.compteur%jeu.classes[KIRBY].animations[jeu.joueur[i].quelAnimation].nbImages].width, jeu.classes[KIRBY].animations[jeu.joueur[i].quelAnimation].images[jeu.info.compteur%jeu.classes[KIRBY].animations[jeu.joueur[i].quelAnimation].nbImages].height, jeu.joueur[i].x - jeu.classes[KIRBY].animations[jeu.joueur[i].quelAnimation].images[jeu.info.compteur%jeu.classes[KIRBY].animations[jeu.joueur[i].quelAnimation].nbImages].width + 3*scalex/4, jeu.joueur[i].y - jeu.classes[KIRBY].animations[jeu.joueur[i].quelAnimation].images[jeu.info.compteur%jeu.classes[KIRBY].animations[jeu.joueur[i].quelAnimation].nbImages].height +  3*scaley/4, jeu.classes[PACMAN].animations->direction) ;
                break ;
            }
            case MARIO : {
                al_draw_bitmap_region(jeu.classes[MARIO].SpriteSheet, jeu.classes[MARIO].animations[jeu.joueur[i].quelAnimation].images[jeu.info.compteur%jeu.classes[MARIO].animations[jeu.joueur[i].quelAnimation].nbImages].x, jeu.classes[MARIO].animations[jeu.joueur[i].quelAnimation].images[jeu.info.compteur%jeu.classes[MARIO].animations[jeu.joueur[i].quelAnimation].nbImages].y, jeu.classes[MARIO].animations[jeu.joueur[i].quelAnimation].images[jeu.info.compteur%jeu.classes[MARIO].animations[jeu.joueur[i].quelAnimation].nbImages].width, jeu.classes[MARIO].animations[jeu.joueur[i].quelAnimation].images[jeu.info.compteur%jeu.classes[MARIO].animations[jeu.joueur[i].quelAnimation].nbImages].height, jeu.joueur[i].x - jeu.classes[MARIO].animations[jeu.joueur[i].quelAnimation].images[jeu.info.compteur%jeu.classes[MARIO].animations[jeu.joueur[i].quelAnimation].nbImages].width + scalex/2, jeu.joueur[i].y - jeu.classes[MARIO].animations[jeu.joueur[i].quelAnimation].images[jeu.info.compteur%jeu.classes[MARIO].animations[jeu.joueur[i].quelAnimation].nbImages].height +  scaley/2, jeu.classes[PACMAN].animations->direction) ;
                break ;
            }
            case PACMAN : {
                al_draw_bitmap_region(jeu.classes[PACMAN].SpriteSheet, jeu.classes[PACMAN].animations[jeu.joueur[i].quelAnimation].images[jeu.info.compteur%jeu.classes[PACMAN].animations[jeu.joueur[i].quelAnimation].nbImages].x, jeu.classes[PACMAN].animations[jeu.joueur[i].quelAnimation].images[jeu.info.compteur%jeu.classes[PACMAN].animations[jeu.joueur[i].quelAnimation].nbImages].y, jeu.classes[PACMAN].animations[jeu.joueur[i].quelAnimation].images[jeu.info.compteur%jeu.classes[PACMAN].animations[jeu.joueur[i].quelAnimation].nbImages].width, jeu.classes[PACMAN].animations[jeu.joueur[i].quelAnimation].images[jeu.info.compteur%jeu.classes[PACMAN].animations[jeu.joueur[i].quelAnimation].nbImages].height, jeu.joueur[i].x - jeu.classes[PACMAN].animations[jeu.joueur[i].quelAnimation].images[jeu.info.compteur%jeu.classes[PACMAN].animations[jeu.joueur[i].quelAnimation].nbImages].width + 3*scalex/4, jeu.joueur[i].y - jeu.classes[PACMAN].animations[jeu.joueur[i].quelAnimation].images[jeu.info.compteur%jeu.classes[PACMAN].animations[jeu.joueur[i].quelAnimation].nbImages].height +  3*scaley/4, jeu.classes[PACMAN].animations->direction) ;
                break ;
            }
            case PEACH : {
                al_draw_bitmap_region(jeu.classes[PEACH].SpriteSheet, jeu.classes[PEACH].animations[jeu.joueur[i].quelAnimation].images[jeu.info.compteur%jeu.classes[PEACH].animations[jeu.joueur[i].quelAnimation].nbImages].x, jeu.classes[PEACH].animations[jeu.joueur[i].quelAnimation].images[jeu.info.compteur%jeu.classes[PEACH].animations[jeu.joueur[i].quelAnimation].nbImages].y, jeu.classes[PEACH].animations[jeu.joueur[i].quelAnimation].images[jeu.info.compteur%jeu.classes[PEACH].animations[jeu.joueur[i].quelAnimation].nbImages].width, jeu.classes[PEACH].animations[jeu.joueur[i].quelAnimation].images[jeu.info.compteur%jeu.classes[PEACH].animations[jeu.joueur[i].quelAnimation].nbImages].height, jeu.joueur[i].x - jeu.classes[PEACH].animations[jeu.joueur[i].quelAnimation].images[jeu.info.compteur%jeu.classes[PEACH].animations[jeu.joueur[i].quelAnimation].nbImages].width + scalex/2, jeu.joueur[i].y - jeu.classes[PEACH].animations[jeu.joueur[i].quelAnimation].images[jeu.info.compteur%jeu.classes[PEACH].animations[jeu.joueur[i].quelAnimation].nbImages].height +  scaley/2, jeu.classes[PACMAN].animations->direction) ;
                break ;
            }
            case DONKEY_KONG : {
                al_draw_bitmap_region(jeu.classes[DONKEY_KONG].SpriteSheet, jeu.classes[DONKEY_KONG].animations[jeu.joueur[i].quelAnimation].images[jeu.info.compteur%jeu.classes[DONKEY_KONG].animations[jeu.joueur[i].quelAnimation].nbImages].x, jeu.classes[DONKEY_KONG].animations[jeu.joueur[i].quelAnimation].images[jeu.info.compteur%jeu.classes[DONKEY_KONG].animations[jeu.joueur[i].quelAnimation].nbImages].y, jeu.classes[DONKEY_KONG].animations[jeu.joueur[i].quelAnimation].images[jeu.info.compteur%jeu.classes[DONKEY_KONG].animations[jeu.joueur[i].quelAnimation].nbImages].width, jeu.classes[DONKEY_KONG].animations[jeu.joueur[i].quelAnimation].images[jeu.info.compteur%jeu.classes[DONKEY_KONG].animations[jeu.joueur[i].quelAnimation].nbImages].height, jeu.joueur[i].x - jeu.classes[DONKEY_KONG].animations[jeu.joueur[i].quelAnimation].images[jeu.info.compteur%jeu.classes[DONKEY_KONG].animations[jeu.joueur[i].quelAnimation].nbImages].width + 3*scalex/4, jeu.joueur[i].y - jeu.classes[DONKEY_KONG].animations[jeu.joueur[i].quelAnimation].images[jeu.info.compteur%jeu.classes[DONKEY_KONG].animations[jeu.joueur[i].quelAnimation].nbImages].height  +  3*scaley/4, jeu.classes[PACMAN].animations->direction) ;
                break ;
            }
        }
    }
}
