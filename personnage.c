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
    animations[RESPIRATION].nbImages = 17 ;
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

                /// ANIMATION 4///
    animations[ATTAQUE2].nbImages = 15 ;
    for(int i = 0 ; i < animations[ATTAQUE2].nbImages ; i++) {
        animations[ATTAQUE2].images[i].y = 283 * 3.2;
        animations[ATTAQUE2].images[i].height = 32 * 3.2;
    }
    ///IMAGE 1
    animations[ATTAQUE2].images[0].x = 2 * 3.2;
    animations[ATTAQUE2].images[0].width = 27 * 3.2;

    ///IMAGE 2
    animations[ATTAQUE2].images[1].x = 29 * 3.2;
    animations[ATTAQUE2].images[1].width = 28 * 3.2;

    ///IMAGE 3
    animations[ATTAQUE2].images[2].x = 57 * 3.2;
    animations[ATTAQUE2].images[2].width = 28 * 3.2;

    ///IMAGE 4
    animations[ATTAQUE2].images[3].x = 85 * 3.2;
    animations[ATTAQUE2].images[3].width = 32 * 3.2;

    ///IMAGE 5
    animations[ATTAQUE2].images[4].x = 117 * 3.2;
    animations[ATTAQUE2].images[4].width = 32 * 3.2;

    ///IMAGE 6
    animations[ATTAQUE2].images[5].x = 149 * 3.2;
    animations[ATTAQUE2].images[5].width = 27 * 3.2;

    ///IMAGE 7
    animations[ATTAQUE2].images[6].x = 204 * 3.2;
    animations[ATTAQUE2].images[6].width = 23 * 3.2;

    ///IMAGE 8
    animations[ATTAQUE2].images[7].x = 256 * 3.2;
    animations[ATTAQUE2].images[7].width = 26 * 3.2;

    ///IMAGE 9
    animations[ATTAQUE2].images[8].x = 282 * 3.2;
    animations[ATTAQUE2].images[8].width = 27 * 3.2;

    ///IMAGE 10
    animations[ATTAQUE2].images[9].x = 309 * 3.2;
    animations[ATTAQUE2].images[9].width = 26 * 3.2;

    ///IMAGE 11
    animations[ATTAQUE2].images[10].x = 335 * 3.2;
    animations[ATTAQUE2].images[10].width = 24 * 3.2;

    ///IMAGE 12
    animations[ATTAQUE2].images[11].x = 359 * 3.2;
    animations[ATTAQUE2].images[11].width = 26 * 3.2;

    ///IMAGE 13
    animations[ATTAQUE2].images[12].x = 385 * 3.2;
    animations[ATTAQUE2].images[12].width = 27 * 3.2;

    ///IMAGE 14
    animations[ATTAQUE2].images[13].x = 412 * 3.2;
    animations[ATTAQUE2].images[13].width = 27 * 3.2;

    ///IMAGE 15
    animations[ATTAQUE2].images[14].x = 439 * 3.2;
    animations[ATTAQUE2].images[14].width = 24 * 3.2;

                /// ANIMATION 5 ///
    animations[ATTAQUE3].nbImages = 6 ;
    for(int i = 0 ; i < animations[ATTAQUE3].nbImages ; i++) {
        animations[ATTAQUE3].images[i].y = 376 * 3.2;
        animations[ATTAQUE3].images[i].height = 40 * 3.2;
    }
    ///IMAGE 1
    animations[ATTAQUE3].images[0].x = 293 * 3.2;
    animations[ATTAQUE3].images[0].width = 24 * 3.2;

    ///IMAGE 2
    animations[ATTAQUE3].images[1].x = 317 * 3.2;
    animations[ATTAQUE3].images[1].width = 26 * 3.2;

    ///IMAGE 3
    animations[ATTAQUE3].images[2].x = 343 * 3.2;
    animations[ATTAQUE3].images[2].width = 36 * 3.2;

    ///IMAGE 4
    animations[ATTAQUE3].images[3].x = 379 * 3.2;
    animations[ATTAQUE3].images[3].width = 30 * 3.2;

    ///IMAGE 5
    animations[ATTAQUE3].images[4].x = 409 * 3.2;
    animations[ATTAQUE3].images[4].width = 29 * 3.2;

    ///IMAGE 6
    animations[ATTAQUE3].images[5].x = 438 * 3.2;
    animations[ATTAQUE3].images[5].width = 28 * 3.2;

                /// ANIMATION 6 ///
    animations[EFFET].nbImages = 3 ;

    ///IMAGE 1
    animations[EFFET].images[0].x = 470 * 3.2;
    animations[EFFET].images[0].width = 28 * 3.2;
    animations[EFFET].images[0].y = 357 * 3.2;
    animations[EFFET].images[0].height = 40 * 3.2;

    ///IMAGE 2
    animations[EFFET].images[1].x = 500 * 3.2;
    animations[EFFET].images[1].width = 31 * 3.2;
    animations[EFFET].images[1].y = 357 * 3.2;
    animations[EFFET].images[1].height = 50 * 3.2;

    ///IMAGE 3
    animations[EFFET].images[2].x = 534 * 3.2;
    animations[EFFET].images[2].width = 20 * 3.2;
    animations[EFFET].images[2].y = 366 * 3.2;
    animations[EFFET].images[2].height = 37 * 3.2;
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

                 /// ANIMATION 3
    animations[ATTAQUE2].nbImages = 8 ;
    for(int i = 0 ; i < animations[ATTAQUE2].nbImages ; i++) {
        animations[ATTAQUE2].images[i].y = 214 * 3;
        animations[ATTAQUE2].images[i].height = 64 * 3;
    }
    ///IMAGE 1
    animations[ATTAQUE2].images[0].x = 0 * 3;
    animations[ATTAQUE2].images[0].width = 34 * 3;

    ///IMAGE 2
    animations[ATTAQUE2].images[1].x = 34 * 3;
    animations[ATTAQUE2].images[1].width = 33 * 3;

    ///IMAGE 3
    animations[ATTAQUE2].images[2].x = 67 * 3;
    animations[ATTAQUE2].images[2].width = 41 * 3;

    ///IMAGE 4
    animations[ATTAQUE2].images[3].x = 108 * 3;
    animations[ATTAQUE2].images[3].width = 50 * 3;

    ///IMAGE 5
    animations[ATTAQUE2].images[4].x = 158 * 3;
    animations[ATTAQUE2].images[4].width = 54 * 3;

    ///IMAGE 6
    animations[ATTAQUE2].images[5].x = 212 * 3;
    animations[ATTAQUE2].images[5].width = 58 * 3;

    ///IMAGE 7
    animations[ATTAQUE2].images[6].x = 270 * 3;
    animations[ATTAQUE2].images[6].width = 58 * 3;

    ///IMAGE 8
    animations[ATTAQUE2].images[7].x = 328 * 3;
    animations[ATTAQUE2].images[7].width = 59 * 3;

                    /// ANIMATION 4
    animations[ATTAQUE3].nbImages = 6 ;
    for(int i = 0 ; i < animations[ATTAQUE3].nbImages ; i++) {
        animations[ATTAQUE3].images[i].y = 172 * 3;
        animations[ATTAQUE3].images[i].height = 33 * 3;
        animations[ATTAQUE3].images[i].width = 49 * 3;
    }
    ///IMAGE 1
    animations[ATTAQUE3].images[0].x = 0 * 3;

    ///IMAGE 2
    animations[ATTAQUE3].images[1].x = 49 * 3;

    ///IMAGE 3
    animations[ATTAQUE3].images[2].x = 0 * 3;

    ///IMAGE 4
    animations[ATTAQUE3].images[3].x = 49 * 3;

    ///IMAGE 5
    animations[ATTAQUE3].images[4].x = 0 * 3;

    ///IMAGE 6
    animations[ATTAQUE3].images[5].x = 49 * 3;

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

                    /// ANIMATION 3 ///
    animations[ATTAQUE1].nbImages = 4 ;
    for(int i = 0 ; i < animations[ATTAQUE1].nbImages ; i++) {
        animations[ATTAQUE1].images[i].y = 1817 * 2;
        animations[ATTAQUE1].images[i].height = 41 * 2;
    }
    ///IMAGE 1
    animations[ATTAQUE1].images[0].x = 6 * 2;
    animations[ATTAQUE1].images[0].width = 28 * 2;

    ///IMAGE 2
    animations[ATTAQUE1].images[1].x = 34 * 2;
    animations[ATTAQUE1].images[1].width = 31 * 2;

    ///IMAGE 3
    animations[ATTAQUE1].images[2].x = 65 * 2;
    animations[ATTAQUE1].images[2].width = 35 * 2;

    ///IMAGE 4
    animations[ATTAQUE1].images[3].x = 100 * 2;
    animations[ATTAQUE1].images[3].width = 36 * 2;

                      /// ANIMATION 4 ///
    animations[ATTAQUE2].nbImages = 4 ;
    for(int i = 0 ; i < animations[ATTAQUE2].nbImages ; i++) {
        animations[ATTAQUE2].images[i].y = 1297 * 2;
        animations[ATTAQUE2].images[i].height = 40 * 2;
    }
    ///IMAGE 1
    animations[ATTAQUE2].images[0].x = 466 * 2;
    animations[ATTAQUE2].images[0].width = 29 * 2;

    ///IMAGE 2
    animations[ATTAQUE2].images[1].x = 495 * 2;
    animations[ATTAQUE2].images[1].width = 26 * 2;

    ///IMAGE 3
    animations[ATTAQUE2].images[2].x = 521 * 2;
    animations[ATTAQUE2].images[2].width = 36 * 2;

    ///IMAGE 4
    animations[ATTAQUE2].images[3].x = 557 * 2;
    animations[ATTAQUE2].images[3].width = 27 * 2;

                    /// ANIMATION 5 ///
    animations[ATTAQUE3].nbImages = 4 ;
    for(int i = 0 ; i < animations[ATTAQUE3].nbImages ; i++) {
        animations[ATTAQUE3].images[i].y = 258 * 2;
        animations[ATTAQUE3].images[i].height = 42 * 2;
        animations[ATTAQUE3].images[i].width = 24 * 2;
    }
    ///IMAGE 1
    animations[ATTAQUE3].images[0].x = 10 * 2;

    ///IMAGE 2
    animations[ATTAQUE3].images[1].x = 36 * 2;

    ///IMAGE 3
    animations[ATTAQUE3].images[2].x = 60 * 2;

    ///IMAGE 4
    animations[ATTAQUE3].images[3].x = 87 * 2;

                /// ANIMATION 6 ///
    animations[EFFET].nbImages = 4 ;
    for(int i = 0 ; i < animations[EFFET].nbImages ; i++) {
        animations[EFFET].images[i].y = 368 * 2;
        animations[EFFET].images[i].height = 33 * 2;
    }
    ///IMAGE 1
    animations[EFFET].images[0].x = 299 * 2;
    animations[EFFET].images[0].width = 19 * 2;

    ///IMAGE 2
    animations[EFFET].images[1].x = 334 * 2;
    animations[EFFET].images[1].width = 17 * 2;

    ///IMAGE 3
    animations[EFFET].images[2].x = 369 * 2;
    animations[EFFET].images[2].width = 30 * 2;

    ///IMAGE 4
    animations[EFFET].images[3].x = 399 * 2;
    animations[EFFET].images[3].width = 33 * 2;

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
    animations[ATTAQUE1].nbImages = 12 ;
    for(int i = 0 ; i < animations[ATTAQUE1].nbImages ; i++) {
        animations[ATTAQUE1].images[i].y = 222 * 2.5;
        animations[ATTAQUE1].images[i].height = 37 * 2.5;
    }
    ///IMAGE 1
    animations[ATTAQUE1].images[0].x = 12 * 2.5;
    animations[ATTAQUE1].images[0].width = 25 * 2.5;

    ///IMAGE 2
    animations[ATTAQUE1].images[1].x = 37 * 2.5;
    animations[ATTAQUE1].images[1].width = 40 * 2.5;

    ///IMAGE 3
    animations[ATTAQUE1].images[2].x = 77 * 2.5;
    animations[ATTAQUE1].images[2].width = 40 * 2.5;

    ///IMAGE 4
    animations[ATTAQUE1].images[3].x = 117 * 2.5;
    animations[ATTAQUE1].images[3].width = 33 * 2.5;

    ///IMAGE 5
    animations[ATTAQUE1].images[4].x = 150 * 2.5;
    animations[ATTAQUE1].images[4].width = 37 * 2.5;

    ///IMAGE 6
    animations[ATTAQUE1].images[5].x = 187 * 2.5;
    animations[ATTAQUE1].images[5].width = 42 * 2.5;

    ///IMAGE 7
    animations[ATTAQUE1].images[6].x = 229 * 2.5;
    animations[ATTAQUE1].images[6].width = 41 * 2.5;

    ///IMAGE 8
    animations[ATTAQUE1].images[7].x = 270 * 2.5;
    animations[ATTAQUE1].images[7].width = 32* 2.5;

    ///IMAGE 9
    animations[ATTAQUE1].images[8].x = 302 * 2.5;
    animations[ATTAQUE1].images[8].width = 38 * 2.5;

    ///IMAGE 10
    animations[ATTAQUE1].images[9].x = 340 * 2.5;
    animations[ATTAQUE1].images[9].width = 32 * 2.5;

    ///IMAGE 11
    animations[ATTAQUE1].images[10].x = 372 * 2.5;
    animations[ATTAQUE1].images[10].width = 36 * 2.5;

    ///IMAGE 12
    animations[ATTAQUE1].images[11].x = 408 * 2.5;
    animations[ATTAQUE1].images[11].width = 34 * 2.5;

                    /// ANIMATION 4 ///
    animations[ATTAQUE2].nbImages = 6 ;
    for(int i = 0 ; i < animations[ATTAQUE2].nbImages ; i++) {
        animations[ATTAQUE2].images[i].y = 305 * 2.5;
        animations[ATTAQUE2].images[i].height = 37 * 2.5;
    }
    ///IMAGE 1
    animations[ATTAQUE2].images[0].x = 15 * 2.5;
    animations[ATTAQUE2].images[0].width = 30 * 2.5;

    ///IMAGE 2
    animations[ATTAQUE2].images[1].x = 45 * 2.5;
    animations[ATTAQUE2].images[1].width = 36 * 2.5;

    ///IMAGE 3
    animations[ATTAQUE2].images[2].x = 81 * 2.5;
    animations[ATTAQUE2].images[2].width = 38 * 2.5;

    ///IMAGE 4
    animations[ATTAQUE2].images[3].x = 119 * 2.5;
    animations[ATTAQUE2].images[3].width = 33 * 2.5;

    ///IMAGE 5
    animations[ATTAQUE2].images[4].x = 151 * 2.5;
    animations[ATTAQUE2].images[4].width = 31 * 2.5;

    ///IMAGE 6
    animations[ATTAQUE2].images[5].x = 183 * 2.5;
    animations[ATTAQUE2].images[5].width = 31 * 2.5;

             /// ANIMATION 5 ///
    animations[ATTAQUE3].nbImages = 4 ;
    for(int i = 0 ; i < animations[ATTAQUE3].nbImages ; i++) {
        animations[ATTAQUE3].images[i].y = 509 * 2.5;
        animations[ATTAQUE3].images[i].height = 34 * 2.5;
    }
    ///IMAGE 1
    animations[ATTAQUE3].images[0].x = 582 * 2.5;
    animations[ATTAQUE3].images[0].width = 43 * 2.5;

    ///IMAGE 2
    animations[ATTAQUE3].images[1].x = 625 * 2.5;
    animations[ATTAQUE3].images[1].width = 39 * 2.5;

    ///IMAGE 3
    animations[ATTAQUE3].images[2].x = 664 * 2.5;
    animations[ATTAQUE3].images[2].width = 42 * 2.5;

    ///IMAGE 4
    animations[ATTAQUE3].images[3].x = 706 * 2.5;
    animations[ATTAQUE3].images[3].width = 33 * 2.5;

                    /// ANIMATION 6 ///
    animations[EFFET].nbImages = 4 ;
    for(int i = 0 ; i < animations[EFFET].nbImages ; i++) {
        animations[EFFET].images[i].y = 302 * 2;
        animations[EFFET].images[i].height = 33 * 2;
    }
    ///IMAGE 1
    animations[EFFET].images[0].x = 299 * 2;
    animations[EFFET].images[0].width = 19 * 2;

    ///IMAGE 2
    animations[EFFET].images[1].x = 334 * 2;
    animations[EFFET].images[1].width = 17 * 2;

    ///IMAGE 3
    animations[EFFET].images[2].x = 369 * 2;
    animations[EFFET].images[2].width = 30 * 2;

    ///IMAGE 4
    animations[EFFET].images[3].x = 399 * 2;
    animations[EFFET].images[3].width = 33 * 2;


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

            /// ANIMATION 2 ///
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

                /// ANIMATION 3 ///
    animations[ATTAQUE1].nbImages = 7 ;
    for(int i = 0 ; i < animations[ATTAQUE1].nbImages ; i++) {
        animations[ATTAQUE1].images[i].y = 38 * 2.6;
        animations[ATTAQUE1].images[i].height = 37 * 2.6;
    }
    ///IMAGE 1
    animations[ATTAQUE1].images[0].x = 272 * 2.6;
    animations[ATTAQUE1].images[0].width = 30 * 2.6;

    ///IMAGE 2
    animations[ATTAQUE1].images[1].x = 302 * 2.6;
    animations[ATTAQUE1].images[1].width = 30 * 2.6;

    ///IMAGE 3
    animations[ATTAQUE1].images[2].x = 332 * 2.6;
    animations[ATTAQUE1].images[2].width = 35 * 2.6;

    ///IMAGE 4
    animations[ATTAQUE1].images[3].x = 367 * 2.6;
    animations[ATTAQUE1].images[3].width = 39 * 2.6;

    ///IMAGE 5
    animations[ATTAQUE1].images[4].x = 406 * 2.6;
    animations[ATTAQUE1].images[4].width = 38 * 2.6;

    ///IMAGE 6
    animations[ATTAQUE1].images[5].x = 444 * 2.6;
    animations[ATTAQUE1].images[5].width = 40 * 2.6;

    ///IMAGE 7
    animations[ATTAQUE1].images[6].x = 484 * 2.6;
    animations[ATTAQUE1].images[6].width = 37 * 2.6;

                    /// ANIMATION 4 ///
    animations[ATTAQUE2].nbImages = 9 ;
    for(int i = 0 ; i < animations[ATTAQUE2].nbImages ; i++) {
        animations[ATTAQUE2].images[i].y = 312 * 2.6;
        animations[ATTAQUE2].images[i].height = 46 * 2.6;
    }
    ///IMAGE 1
    animations[ATTAQUE2].images[0].x = 261 * 2.6;
    animations[ATTAQUE2].images[0].width = 29 * 2.6;

    ///IMAGE 2
    animations[ATTAQUE2].images[1].x = 290 * 2.6;
    animations[ATTAQUE2].images[1].width = 33 * 2.6;

    ///IMAGE 3
    animations[ATTAQUE2].images[2].x = 323 * 2.6;
    animations[ATTAQUE2].images[2].width = 37 * 2.6;

    ///IMAGE 4
    animations[ATTAQUE2].images[3].x = 360 * 2.6;
    animations[ATTAQUE2].images[3].width = 34 * 2.6;

    ///IMAGE 5
    animations[ATTAQUE2].images[4].x = 394 * 2.6;
    animations[ATTAQUE2].images[4].width = 42 * 2.6;

    ///IMAGE 6
    animations[ATTAQUE2].images[5].x = 436 * 2.6;
    animations[ATTAQUE2].images[5].width = 37 * 2.6;

    ///IMAGE 7
    animations[ATTAQUE2].images[6].x = 473 * 2.6;
    animations[ATTAQUE2].images[6].width = 39 * 2.6;

    ///IMAGE 8
    animations[ATTAQUE2].images[7].x = 512 * 2.6;
    animations[ATTAQUE2].images[7].width = 36 * 2.6;

    ///IMAGE 9
    animations[ATTAQUE2].images[8].x = 548 * 2.6;
    animations[ATTAQUE2].images[8].width = 31 * 2.6;

    /// ANIMATION 5 ///
    animations[ATTAQUE3].nbImages = 8 ;
    for(int i = 0 ; i < animations[ATTAQUE3].nbImages ; i++) {
        animations[ATTAQUE3].images[i].y = 155 * 2.6;
        animations[ATTAQUE3].images[i].height = 39 * 2.6;
    }
    ///IMAGE 1
    animations[ATTAQUE3].images[0].x = 247 * 2.6;
    animations[ATTAQUE3].images[0].width = 29 * 2.6;

    ///IMAGE 2
    animations[ATTAQUE3].images[1].x = 276 * 2.6;
    animations[ATTAQUE3].images[1].width = 31 * 2.6;

    ///IMAGE 3
    animations[ATTAQUE3].images[2].x = 307 * 2.6;
    animations[ATTAQUE3].images[2].width = 34 * 2.6;

    ///IMAGE 4
    animations[ATTAQUE3].images[3].x = 341 * 2.6;
    animations[ATTAQUE3].images[3].width = 37 * 2.6;

    ///IMAGE 5
    animations[ATTAQUE3].images[4].x = 378 * 2.6;
    animations[ATTAQUE3].images[4].width = 41 * 2.6;

    ///IMAGE 6
    animations[ATTAQUE3].images[5].x = 419 * 2.6;
    animations[ATTAQUE3].images[5].width = 45 * 2.6;

    ///IMAGE 7
    animations[ATTAQUE3].images[6].x = 464 * 2.6;
    animations[ATTAQUE3].images[6].width = 48 * 2.6;

    ///IMAGE 8
    animations[ATTAQUE3].images[7].x = 512 * 2.6;
    animations[ATTAQUE3].images[7].width = 51 * 2.6;
}



void afficherPersonnage(Jeux jeu, Map map[30][30], InfoEcran ecran, Timer* timerJeu2, double scalex, double scaley, ALLEGRO_BITMAP* shield, ALLEGRO_BITMAP* effect, ALLEGRO_FONT* gameFont) {
    int ordreAffichageJoueur[5] = {0}, k = 0;
    for (int i = 0; i < mapX; i++) {
        for (int j = 0; j < mapY; j++) {
            if (map[mapX - 1 - i][j].joueurPresentDessus != 0) {
                ordreAffichageJoueur[k] = map[mapX - 1 - i][j].joueurPresentDessus - 1;
                k++;
            }
        }
    }
    for (int i = 0; i < jeu.info.nbJoueur; i++) {
        if (jeu.joueur[ordreAffichageJoueur[i]].etat != 1) {
            switch (jeu.joueur[ordreAffichageJoueur[i]].classe) {
                case KIRBY : {
                    al_draw_bitmap_region(jeu.classes[KIRBY].SpriteSheet,
                                          jeu.classes[KIRBY].animations[jeu.joueur[ordreAffichageJoueur[i]].quelAnimation].images[
                                                  jeu.info.compteur %
                                                  jeu.classes[KIRBY].animations[jeu.joueur[ordreAffichageJoueur[i]].quelAnimation].nbImages].x,
                                          jeu.classes[KIRBY].animations[jeu.joueur[ordreAffichageJoueur[i]].quelAnimation].images[
                                                  jeu.info.compteur %
                                                  jeu.classes[KIRBY].animations[jeu.joueur[ordreAffichageJoueur[i]].quelAnimation].nbImages].y,
                                          jeu.classes[KIRBY].animations[jeu.joueur[ordreAffichageJoueur[i]].quelAnimation].images[
                                                  jeu.info.compteur %
                                                  jeu.classes[KIRBY].animations[jeu.joueur[ordreAffichageJoueur[i]].quelAnimation].nbImages].width,
                                          jeu.classes[KIRBY].animations[jeu.joueur[ordreAffichageJoueur[i]].quelAnimation].images[
                                                  jeu.info.compteur %
                                                  jeu.classes[KIRBY].animations[jeu.joueur[ordreAffichageJoueur[i]].quelAnimation].nbImages].height,
                                          jeu.joueur[ordreAffichageJoueur[i]].x -
                                          jeu.classes[KIRBY].animations[jeu.joueur[ordreAffichageJoueur[i]].quelAnimation].images[
                                                  jeu.info.compteur %
                                                  jeu.classes[KIRBY].animations[jeu.joueur[ordreAffichageJoueur[i]].quelAnimation].nbImages].width +
                                          3 * scalex / 4, jeu.joueur[ordreAffichageJoueur[i]].y -
                                                          jeu.classes[KIRBY].animations[jeu.joueur[ordreAffichageJoueur[i]].quelAnimation].images[
                                                                  jeu.info.compteur %
                                                                  jeu.classes[KIRBY].animations[jeu.joueur[ordreAffichageJoueur[i]].quelAnimation].nbImages].height +
                                                          3 * scaley / 4,
                                          jeu.joueur[ordreAffichageJoueur[i]].direction);
                    if (jeu.joueur[ordreAffichageJoueur[i]].quelAnimation == ATTAQUE3 && jeu.info.compteur > 2) {
                        int x = jeu.joueur[ordreAffichageJoueur[i]].x -
                                jeu.classes[KIRBY].animations[EFFET].images[0].width;
                        int y = jeu.joueur[ordreAffichageJoueur[i]].y -
                                jeu.classes[KIRBY].animations[EFFET].images[0].height;
                        al_draw_bitmap_region(jeu.classes[KIRBY].SpriteSheet,
                                              jeu.classes[KIRBY].animations[EFFET].images[(jeu.info.compteur - 3) %
                                                                                          3].x,
                                              jeu.classes[KIRBY].animations[EFFET].images[(jeu.info.compteur - 3) %
                                                                                          3].y,
                                              jeu.classes[KIRBY].animations[EFFET].images[(jeu.info.compteur - 3) %
                                                                                          3].width,
                                              jeu.classes[KIRBY].animations[EFFET].images[(jeu.info.compteur - 3) %
                                                                                          3].height, x + 3 * scalex / 4,
                                              y + 3 * scaley / 4, jeu.joueur[ordreAffichageJoueur[i]].direction);
                    }
                    break;
                }
                case MARIO : {
                    al_draw_bitmap_region(jeu.classes[MARIO].SpriteSheet,
                                          jeu.classes[MARIO].animations[jeu.joueur[ordreAffichageJoueur[i]].quelAnimation].images[
                                                  jeu.info.compteur %
                                                  jeu.classes[MARIO].animations[jeu.joueur[ordreAffichageJoueur[i]].quelAnimation].nbImages].x,
                                          jeu.classes[MARIO].animations[jeu.joueur[ordreAffichageJoueur[i]].quelAnimation].images[
                                                  jeu.info.compteur %
                                                  jeu.classes[MARIO].animations[jeu.joueur[ordreAffichageJoueur[i]].quelAnimation].nbImages].y,
                                          jeu.classes[MARIO].animations[jeu.joueur[ordreAffichageJoueur[i]].quelAnimation].images[
                                                  jeu.info.compteur %
                                                  jeu.classes[MARIO].animations[jeu.joueur[ordreAffichageJoueur[i]].quelAnimation].nbImages].width,
                                          jeu.classes[MARIO].animations[jeu.joueur[ordreAffichageJoueur[i]].quelAnimation].images[
                                                  jeu.info.compteur %
                                                  jeu.classes[MARIO].animations[jeu.joueur[ordreAffichageJoueur[i]].quelAnimation].nbImages].height,
                                          jeu.joueur[ordreAffichageJoueur[i]].x -
                                          jeu.classes[MARIO].animations[jeu.joueur[ordreAffichageJoueur[i]].quelAnimation].images[
                                                  jeu.info.compteur %
                                                  jeu.classes[MARIO].animations[jeu.joueur[ordreAffichageJoueur[i]].quelAnimation].nbImages].width +
                                          scalex / 2, jeu.joueur[ordreAffichageJoueur[i]].y -
                                                      jeu.classes[MARIO].animations[jeu.joueur[ordreAffichageJoueur[i]].quelAnimation].images[
                                                              jeu.info.compteur %
                                                              jeu.classes[MARIO].animations[jeu.joueur[ordreAffichageJoueur[i]].quelAnimation].nbImages].height +
                                                      scaley / 2, jeu.joueur[ordreAffichageJoueur[i]].direction);
                    if (jeu.joueur[ordreAffichageJoueur[i]].quelAnimation == ATTAQUE2 && jeu.info.compteur > 2) {
                        al_draw_bitmap_region(effect,
                                              jeu.classes[MARIO].animations[EFFET].images[(jeu.info.compteur - 3) %
                                                                                          4].x,
                                              jeu.classes[MARIO].animations[EFFET].images[(jeu.info.compteur - 3) %
                                                                                          4].y,
                                              jeu.classes[MARIO].animations[EFFET].images[(jeu.info.compteur - 3) %
                                                                                          4].width,
                                              jeu.classes[MARIO].animations[EFFET].images[(jeu.info.compteur - 3) %
                                                                                          4].height,
                                              map[jeu.info.xClick][jeu.info.yClick].x -
                                              jeu.classes[MARIO].animations[EFFET].images[(jeu.info.compteur - 3) %
                                                                                          4].width + scalex / 2,
                                              map[jeu.info.xClick][jeu.info.yClick].y -
                                              jeu.classes[MARIO].animations[EFFET].images[(jeu.info.compteur - 3) %
                                                                                          4].height + scaley / 2, 0);
                    }
                    break;
                }
                case PACMAN : {
                    al_draw_bitmap_region(jeu.classes[PACMAN].SpriteSheet,
                                          jeu.classes[PACMAN].animations[jeu.joueur[ordreAffichageJoueur[i]].quelAnimation].images[
                                                  jeu.info.compteur %
                                                  jeu.classes[PACMAN].animations[jeu.joueur[ordreAffichageJoueur[i]].quelAnimation].nbImages].x,
                                          jeu.classes[PACMAN].animations[jeu.joueur[ordreAffichageJoueur[i]].quelAnimation].images[
                                                  jeu.info.compteur %
                                                  jeu.classes[PACMAN].animations[jeu.joueur[ordreAffichageJoueur[i]].quelAnimation].nbImages].y,
                                          jeu.classes[PACMAN].animations[jeu.joueur[ordreAffichageJoueur[i]].quelAnimation].images[
                                                  jeu.info.compteur %
                                                  jeu.classes[PACMAN].animations[jeu.joueur[ordreAffichageJoueur[i]].quelAnimation].nbImages].width,
                                          jeu.classes[PACMAN].animations[jeu.joueur[ordreAffichageJoueur[i]].quelAnimation].images[
                                                  jeu.info.compteur %
                                                  jeu.classes[PACMAN].animations[jeu.joueur[ordreAffichageJoueur[i]].quelAnimation].nbImages].height,
                                          jeu.joueur[ordreAffichageJoueur[i]].x -
                                          jeu.classes[PACMAN].animations[jeu.joueur[ordreAffichageJoueur[i]].quelAnimation].images[
                                                  jeu.info.compteur %
                                                  jeu.classes[PACMAN].animations[jeu.joueur[ordreAffichageJoueur[i]].quelAnimation].nbImages].width +
                                          3 * scalex / 4, jeu.joueur[ordreAffichageJoueur[i]].y -
                                                          jeu.classes[PACMAN].animations[jeu.joueur[ordreAffichageJoueur[i]].quelAnimation].images[
                                                                  jeu.info.compteur %
                                                                  jeu.classes[PACMAN].animations[jeu.joueur[ordreAffichageJoueur[i]].quelAnimation].nbImages].height +
                                                          3 * scaley / 4,
                                          jeu.joueur[ordreAffichageJoueur[i]].direction);
                    if (jeu.joueur[ordreAffichageJoueur[i]].sortSpecial == 1) {
                        al_draw_scaled_bitmap(shield, 0, 0, 556, 556,
                                              jeu.joueur[ordreAffichageJoueur[i]].x - 5 * ecran.width / 192,
                                              jeu.joueur[ordreAffichageJoueur[i]].y - 5 * ecran.height / 54,
                                              5 * ecran.width / 96, 5 * ecran.height / 54, 0);
                    }
                    break;
                }
                case PEACH : {
                    al_draw_bitmap_region(jeu.classes[PEACH].SpriteSheet,
                                          jeu.classes[PEACH].animations[jeu.joueur[ordreAffichageJoueur[i]].quelAnimation].images[
                                                  jeu.info.compteur %
                                                  jeu.classes[PEACH].animations[jeu.joueur[ordreAffichageJoueur[i]].quelAnimation].nbImages].x,
                                          jeu.classes[PEACH].animations[jeu.joueur[ordreAffichageJoueur[i]].quelAnimation].images[
                                                  jeu.info.compteur %
                                                  jeu.classes[PEACH].animations[jeu.joueur[ordreAffichageJoueur[i]].quelAnimation].nbImages].y,
                                          jeu.classes[PEACH].animations[jeu.joueur[ordreAffichageJoueur[i]].quelAnimation].images[
                                                  jeu.info.compteur %
                                                  jeu.classes[PEACH].animations[jeu.joueur[ordreAffichageJoueur[i]].quelAnimation].nbImages].width,
                                          jeu.classes[PEACH].animations[jeu.joueur[ordreAffichageJoueur[i]].quelAnimation].images[
                                                  jeu.info.compteur %
                                                  jeu.classes[PEACH].animations[jeu.joueur[ordreAffichageJoueur[i]].quelAnimation].nbImages].height,
                                          jeu.joueur[ordreAffichageJoueur[i]].x -
                                          jeu.classes[PEACH].animations[jeu.joueur[ordreAffichageJoueur[i]].quelAnimation].images[
                                                  jeu.info.compteur %
                                                  jeu.classes[PEACH].animations[jeu.joueur[ordreAffichageJoueur[i]].quelAnimation].nbImages].width +
                                          scalex / 2, jeu.joueur[ordreAffichageJoueur[i]].y -
                                                      jeu.classes[PEACH].animations[jeu.joueur[ordreAffichageJoueur[i]].quelAnimation].images[
                                                              jeu.info.compteur %
                                                              jeu.classes[PEACH].animations[jeu.joueur[ordreAffichageJoueur[i]].quelAnimation].nbImages].height +
                                                      scaley / 2, jeu.joueur[ordreAffichageJoueur[i]].direction);
                    if (jeu.joueur[ordreAffichageJoueur[i]].quelAnimation == ATTAQUE2) {
                        al_draw_bitmap_region(effect,
                                              jeu.classes[PEACH].animations[EFFET].images[jeu.info.compteur % 4].x,
                                              jeu.classes[PEACH].animations[EFFET].images[jeu.info.compteur % 4].y,
                                              jeu.classes[PEACH].animations[EFFET].images[jeu.info.compteur % 4].width,
                                              jeu.classes[PEACH].animations[EFFET].images[jeu.info.compteur % 4].height,
                                              map[jeu.info.xClick][jeu.info.yClick].x -
                                              jeu.classes[PEACH].animations[EFFET].images[jeu.info.compteur % 4].width +
                                              scalex / 2, map[jeu.info.xClick][jeu.info.yClick].y -
                                                          jeu.classes[PEACH].animations[EFFET].images[
                                                                  jeu.info.compteur % 4].height + scaley / 2, 0);
                    }
                    break;
                }
                case DONKEY_KONG : {
                    al_draw_bitmap_region(jeu.classes[DONKEY_KONG].SpriteSheet,
                                          jeu.classes[DONKEY_KONG].animations[jeu.joueur[ordreAffichageJoueur[i]].quelAnimation].images[
                                                  jeu.info.compteur %
                                                  jeu.classes[DONKEY_KONG].animations[jeu.joueur[ordreAffichageJoueur[i]].quelAnimation].nbImages].x,
                                          jeu.classes[DONKEY_KONG].animations[jeu.joueur[ordreAffichageJoueur[i]].quelAnimation].images[
                                                  jeu.info.compteur %
                                                  jeu.classes[DONKEY_KONG].animations[jeu.joueur[ordreAffichageJoueur[i]].quelAnimation].nbImages].y,
                                          jeu.classes[DONKEY_KONG].animations[jeu.joueur[ordreAffichageJoueur[i]].quelAnimation].images[
                                                  jeu.info.compteur %
                                                  jeu.classes[DONKEY_KONG].animations[jeu.joueur[ordreAffichageJoueur[i]].quelAnimation].nbImages].width,
                                          jeu.classes[DONKEY_KONG].animations[jeu.joueur[ordreAffichageJoueur[i]].quelAnimation].images[
                                                  jeu.info.compteur %
                                                  jeu.classes[DONKEY_KONG].animations[jeu.joueur[ordreAffichageJoueur[i]].quelAnimation].nbImages].height,
                                          jeu.joueur[ordreAffichageJoueur[i]].x -
                                          jeu.classes[DONKEY_KONG].animations[jeu.joueur[ordreAffichageJoueur[i]].quelAnimation].images[
                                                  jeu.info.compteur %
                                                  jeu.classes[DONKEY_KONG].animations[jeu.joueur[ordreAffichageJoueur[i]].quelAnimation].nbImages].width +
                                          3 * scalex / 4, jeu.joueur[ordreAffichageJoueur[i]].y -
                                                          jeu.classes[DONKEY_KONG].animations[jeu.joueur[ordreAffichageJoueur[i]].quelAnimation].images[
                                                                  jeu.info.compteur %
                                                                  jeu.classes[DONKEY_KONG].animations[jeu.joueur[ordreAffichageJoueur[i]].quelAnimation].nbImages].height +
                                                          3 * scaley / 4,
                                          jeu.joueur[ordreAffichageJoueur[i]].direction);
                    break;
                }
            }
            if (jeu.info.compteur == jeu.classes[jeu.joueur[jeu.info.joueurQuiJoue].classe].animations[jeu.joueur[jeu.info.joueurQuiJoue].quelAnimation].nbImages) {
                if (jeu.joueur[jeu.info.joueurQuiJoue].quelAnimation != RESPIRATION && jeu.joueur[jeu.info.joueurQuiJoue].quelAnimation != MARCHER) {
                    if(jeu.joueur[jeu.info.joueurQuiJoue].classe == DONKEY_KONG && jeu.joueur[jeu.info.joueurQuiJoue].quelAnimation == ATTAQUE3) {
                        if(jeu.joueur[jeu.info.joueurQuiJoue].dep == 0) {
                            jeu.joueur[jeu.info.joueurQuiJoue].quelAnimation = RESPIRATION;
                        }
                    }
                    else {
                        jeu.joueur[jeu.info.joueurQuiJoue].quelAnimation = RESPIRATION;
                    }
                }
            }

            if(timerJeu2->startTimer == 1) {
                timerJeu2->secondes = (float) timerJeu2->compteur / (float) 50;
                if (timerJeu2->secondes < 5 && timerJeu2->joueurAttaque != -1) {
                    if(jeu.joueur[jeu.info.joueurQuiJoue].classe == PEACH && jeu.joueur[jeu.info.joueurQuiJoue].sortAppuye ==2) {
                        al_draw_textf(gameFont, al_map_rgb(0, 255, 0), jeu.joueur[timerJeu2->joueurAttaque].x + timerJeu2->compteur/5, jeu.joueur[timerJeu2->joueurAttaque].y + timerJeu2->compteur/5, ALLEGRO_ALIGN_LEFT, "%d PV", jeu.classes[jeu.joueur[jeu.info.joueurQuiJoue].classe].sortADisposition[jeu.joueur[jeu.info.joueurQuiJoue].sortAppuye].degatsOUsoin) ;
                    }
                    else if(jeu.joueur[jeu.info.joueurQuiJoue].classe == PACMAN && jeu.joueur[jeu.info.joueurQuiJoue].sortAppuye == 0) {
                        al_draw_text(gameFont, al_map_rgb(0, 255, 0), jeu.joueur[timerJeu2->joueurAttaque].x + timerJeu2->compteur/5, jeu.joueur[timerJeu2->joueurAttaque].y + timerJeu2->compteur/5, ALLEGRO_ALIGN_LEFT, "IMMUNISE !") ;
                    }
                    else if(jeu.joueur[jeu.info.joueurQuiJoue].classe == DONKEY_KONG && jeu.joueur[jeu.info.joueurQuiJoue].sortAppuye == 2) {
                        al_draw_text(gameFont, al_map_rgb(0, 255, 0), jeu.joueur[timerJeu2->joueurAttaque].x + timerJeu2->compteur/5, jeu.joueur[timerJeu2->joueurAttaque].y + timerJeu2->compteur/5, ALLEGRO_ALIGN_LEFT, "SAUT !") ;
                    }
                    else al_draw_textf(gameFont, al_map_rgb(255, 0, 0), jeu.joueur[timerJeu2->joueurAttaque].x + timerJeu2->compteur/5, jeu.joueur[timerJeu2->joueurAttaque].y + timerJeu2->compteur/5, ALLEGRO_ALIGN_LEFT, "%d PV", jeu.classes[jeu.joueur[jeu.info.joueurQuiJoue].classe].sortADisposition[jeu.joueur[jeu.info.joueurQuiJoue].sortAppuye].degatsOUsoin) ;
                }
                else {
                    timerJeu2->startTimer = 0;
                    timerJeu2->secondes = 0 ;
                    timerJeu2->compteur = 0 ;
                    jeu.joueur[jeu.info.joueurQuiJoue].sortAppuye = 3;
                }
                timerJeu2->compteur++;
            }
        }
    }
}

void determinerDirection(Jeux jeu) {
    if(jeu.info.collisionSourisMap[0][0] != 30 && jeu.info.collisionSourisMap[1][0] != 30) {  ///en gros si on click sur une case de la map, sinon, ces valeurs seront à 30
        if(jeu.info.collisionSourisMap[0][0] > jeu.joueur[jeu.info.joueurQuiJoue].caseX) {
            jeu.joueur[jeu.info.joueurQuiJoue].direction = 0 ;
        }
        else if(jeu.info.collisionSourisMap[0][0] < jeu.joueur[jeu.info.joueurQuiJoue].caseX) {
            jeu.joueur[jeu.info.joueurQuiJoue].direction = 1 ;
        }
        else if(jeu.info.collisionSourisMap[1][0] == jeu.joueur[jeu.info.joueurQuiJoue].caseY && jeu.info.collisionSourisMap[0][0] > jeu.joueur[jeu.info.joueurQuiJoue].caseX) {
            jeu.joueur[jeu.info.joueurQuiJoue].direction = 0 ;
        }
        else if(jeu.info.collisionSourisMap[1][0] > jeu.joueur[jeu.info.joueurQuiJoue].caseY && jeu.info.collisionSourisMap[0][0] == jeu.joueur[jeu.info.joueurQuiJoue].caseX) {
            jeu.joueur[jeu.info.joueurQuiJoue].direction = 0 ;
        }
        else if(jeu.info.collisionSourisMap[1][0] == jeu.joueur[jeu.info.joueurQuiJoue].caseY && jeu.info.collisionSourisMap[0][0] < jeu.joueur[jeu.info.joueurQuiJoue].caseX) {
            jeu.joueur[jeu.info.joueurQuiJoue].direction = 1 ;
        }
        else if(jeu.info.collisionSourisMap[1][0] < jeu.joueur[jeu.info.joueurQuiJoue].caseY && jeu.info.collisionSourisMap[0][0] == jeu.joueur[jeu.info.joueurQuiJoue].caseX) {
            jeu.joueur[jeu.info.joueurQuiJoue].direction = 1 ;
        }
    }
}