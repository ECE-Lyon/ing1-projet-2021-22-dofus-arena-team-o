#include "sorts.h"

void barreSort (ALLEGRO_BITMAP* barreSort, InfoEcran ecran) {
    al_draw_scaled_bitmap(barreSort, 0, 0, 1000, 2000, ecran.width / 1.6, 79 * ecran.height / 90, ecran.width / 1.92,
                          269 * ecran.height / 360, 0);
    al_draw_scaled_bitmap(barreSort, 0, 0, 1000, 2000, 0, 79 * ecran.height / 90, ecran.width / 1.92,
                          269 * ecran.height / 360, 0);
}

void drawSortKIRBY( ALLEGRO_FONT* gameFont, Jeux jeu, InfoEcran ecran) {
    if ((float) ecran.mouse_x < 235 * ecran.width / 288 && ecran.mouse_x > 73 * ecran.width / 96 &&
        (float) ecran.mouse_y < 59 * ecran.height / 60 && ecran.mouse_y > ecran.height / 1.125) {
        al_draw_scaled_bitmap(jeu.classes[KIRBY].sortADisposition[POING].iconeSort, 0, 0, 2000, 2000,
                              109 * ecran.width / 144, ecran.height / 1.125, 67 * ecran.width / 144,
                              67 * ecran.height / 90, 0);
        al_draw_text(gameFont, al_map_rgb(100, 100, 100), 2300, 1400,
                     ALLEGRO_ALIGN_CENTER, "SORT POING");
    } else {
        al_draw_scaled_bitmap(jeu.classes[KIRBY].sortADisposition[POING].iconeSort, 0, 0, 2000, 2000,
                              109 * ecran.width / 144, ecran.height / 1.125, 43 * ecran.width / 96,
                              43 * ecran.height / 60, 0);
    }

    if ((float) ecran.mouse_x < 427 * ecran.width / 576 && ecran.mouse_x > 409 * ecran.width / 576 &&
        (float) ecran.mouse_y < 353 * ecran.height / 360 && ecran.mouse_y > 9 * ecran.height / 10) {
        al_draw_scaled_bitmap(jeu.classes[KIRBY].sortADisposition[COUPDEPIED].iconeSort, 0, 0, 2000, 2000,
                              ecran.width / 1.44, 79 * ecran.height / 90, 47 * ecran.width / 96, 47 * ecran.height / 60,
                              0);
        al_draw_text(gameFont, al_map_rgb(100, 100, 100), 2300, 1400,
                     ALLEGRO_ALIGN_CENTER, "SORT COUP DE PIED");
    } else {
        al_draw_scaled_bitmap(jeu.classes[KIRBY].sortADisposition[COUPDEPIED].iconeSort, 0, 0, 2000, 2000,
                              ecran.width / 1.44, 79 * ecran.height / 90, 17 * ecran.width / 36, 34 * ecran.height / 45,
                              0);
    }

    if ((float) ecran.mouse_x < ecran.width / 1.152 && ecran.mouse_x > 119 * ecran.width / 144 &&
        (float) ecran.mouse_y < 353 * ecran.height / 360 && ecran.mouse_y > 9 * ecran.height / 10) {
        al_draw_scaled_bitmap(jeu.classes[KIRBY].sortADisposition[FLAMME].iconeSort, 0, 0, 2000, 2000,
                              239 * ecran.width / 288, 319 * ecran.height / 360, 85 * ecran.width / 288,
                              17 * ecran.height / 36, 0);
        al_draw_text(gameFont, al_map_rgb(100, 100, 100), 2300, 1400,
                     ALLEGRO_ALIGN_CENTER, "SORT FLAMME ");
    } else {
        al_draw_scaled_bitmap(jeu.classes[KIRBY].sortADisposition[FLAMME].iconeSort, 0, 0, 2000, 2000,
                              239 * ecran.width / 288, 319 * ecran.height / 360, ecran.width / 3.6, ecran.height / 2.25,
                              0);
    }
}

void drawSortMARIO( ALLEGRO_FONT* gameFont, Jeux jeu, InfoEcran ecran) {
    if ((float) ecran.mouse_x < 119 * ecran.width / 144 && ecran.mouse_x > 73 * ecran.width / 96 &&
        (float) ecran.mouse_y < 59 * ecran.height / 60 && ecran.mouse_y > ecran.height / 1.125) {
        al_draw_scaled_bitmap(jeu.classes[MARIO].sortADisposition[CORONA].iconeSort, 0, 0, 2000, 2000,
                              73 * ecran.width / 96, 79 * ecran.height / 90, 127 * ecran.width / 288,
                              127 * ecran.height / 180, 0);
        al_draw_text(gameFont, al_map_rgb(100, 100, 100), 2300, 1400,
                     ALLEGRO_ALIGN_CENTER, "SORT CORONA");
    } else {
        al_draw_scaled_bitmap(jeu.classes[MARIO].sortADisposition[CORONA].iconeSort, 0, 0, 2000, 2000,
                              73 * ecran.width / 96, 79 * ecran.height / 90, 61 * ecran.width / 144,
                              61 * ecran.height / 90, 0);
    }

    if ((float) ecran.mouse_x < 427 * ecran.width / 576 && ecran.mouse_x > 409 * ecran.width / 576 &&
        (float) ecran.mouse_y < 353 * ecran.height / 360 && ecran.mouse_y > 9 * ecran.height / 10) {
        al_draw_scaled_bitmap(jeu.classes[MARIO].sortADisposition[FLAMME].iconeSort, 0, 0, 2000, 2000,
                              ecran.width / 1.44, 319 * ecran.height / 360, 85 * ecran.width / 288,
                              17 * ecran.height / 36, 0);
        al_draw_text(gameFont, al_map_rgb(100, 100, 100), 2300, 1400,
                     ALLEGRO_ALIGN_CENTER, "SORT FLAMME");
    } else {
        al_draw_scaled_bitmap(jeu.classes[MARIO].sortADisposition[FLAMME].iconeSort, 0, 0, 2000, 2000,
                              ecran.width / 1.44, 319 * ecran.height / 360, ecran.width / 3.6, ecran.height / 2.25, 0);
    }

    if ((float) ecran.mouse_x < 253 * ecran.width / 288 && ecran.mouse_x > 161 * ecran.width / 192 &&
        (float) ecran.mouse_y < 353 * ecran.height / 360 && ecran.mouse_y > 9 * ecran.height / 10) {
        al_draw_scaled_bitmap(jeu.classes[MARIO].sortADisposition[POING2].iconeSort, 0, 0, 2000, 2000,
                              161 * ecran.width / 192, 319 * ecran.height / 360, 113 * ecran.width / 288,
                              113 * ecran.height / 180, 0);
        al_draw_text(gameFont, al_map_rgb(100, 100, 100), 2300, 1400,
                     ALLEGRO_ALIGN_CENTER, "SORT POING 2 ");
    } else {
        al_draw_scaled_bitmap(jeu.classes[MARIO].sortADisposition[POING2].iconeSort, 0, 0, 2000, 2000,
                              161 * ecran.width / 192, 319 * ecran.height / 360, 3 * ecran.width / 8,
                              3 * ecran.height / 5, 0);
    }
}

void drawSortPEACH( ALLEGRO_FONT* gameFont, Jeux jeu, InfoEcran ecran) {
    if ((float) ecran.mouse_x < 235 * ecran.width / 288 && ecran.mouse_x > 73 * ecran.width / 96 &&
        (float) ecran.mouse_y < 59 * ecran.height / 60 && ecran.mouse_y > ecran.height / 1.125) {
        al_draw_scaled_bitmap(jeu.classes[PEACH].sortADisposition[SORTFLEUR].iconeSort, 0, 0, 2000, 2000,
                              55 * ecran.width / 72, 809 * ecran.height / 900, 29 * ecran.width / 72,
                              29 * ecran.height / 45, 0);
        al_draw_text(gameFont, al_map_rgb(100, 100, 100), 2300, 1400,
                     ALLEGRO_ALIGN_CENTER, "SORT FLEUR");
    } else {
        al_draw_scaled_bitmap(jeu.classes[PEACH].sortADisposition[SORTFLEUR].iconeSort, 0, 0, 2000, 2000,
                              55 * ecran.width / 72, 809 * ecran.height / 900, 37 * ecran.width / 96,
                              37 * ecran.height / 60, 0);
    }

    if ((float) ecran.mouse_x < 427 * ecran.width / 576 && ecran.mouse_x > 409 * ecran.width / 576 &&
        (float) ecran.mouse_y < 353 * ecran.height / 360 && ecran.mouse_y > 9 * ecran.height / 10) {
        al_draw_scaled_bitmap(jeu.classes[PEACH].sortADisposition[COUPDEPIED].iconeSort, 0, 0, 2000, 2000,
                              ecran.width / 1.44, 79 * ecran.height / 90, 47 * ecran.width / 96, 47 * ecran.height / 60,
                              0);
        al_draw_text(gameFont, al_map_rgb(100, 100, 100), 2300, 1400,
                     ALLEGRO_ALIGN_CENTER, "SORT COUP DE PIED ");
    } else {
        al_draw_scaled_bitmap(jeu.classes[PEACH].sortADisposition[COUPDEPIED].iconeSort, 0, 0, 2000, 2000,
                              ecran.width / 1.44, 79 * ecran.height / 90, 17 * ecran.width / 36, 34 * ecran.height / 45,
                              0);
    }

    if ((float) ecran.mouse_x < 253 * ecran.width / 288 && ecran.mouse_x > 161 * ecran.width / 192 &&
        (float) ecran.mouse_y < 353 * ecran.height / 360 && ecran.mouse_y > 9 * ecran.height / 10) {
        al_draw_scaled_bitmap(jeu.classes[PEACH].sortADisposition[SORTSOIN].iconeSort, 0, 0, 2000, 2000,
                              161 * ecran.width / 192, 323 * ecran.height / 360, 113 * ecran.width / 288,
                              113 * ecran.height / 180, 0);
        al_draw_text(gameFont, al_map_rgb(100, 100, 100), 2300, 1400,
                     ALLEGRO_ALIGN_CENTER, " SORT SOIN");
    } else {
        al_draw_scaled_bitmap(jeu.classes[PEACH].sortADisposition[SORTSOIN].iconeSort, 0, 0, 2000, 2000,
                              161 * ecran.width / 192, 323 * ecran.height / 360, 3 * ecran.width / 8,
                              3 * ecran.height / 5, 0);
    }
}

void drawSortPACMAN( ALLEGRO_FONT* gameFont, Jeux jeu, InfoEcran ecran) {
    if ((float) ecran.mouse_x < 235 * ecran.width / 288 && ecran.mouse_x > 73 * ecran.width / 96 &&
        (float) ecran.mouse_y < 59 * ecran.height / 60 && ecran.mouse_y > ecran.height / 1.125) {
        al_draw_scaled_bitmap(jeu.classes[PACMAN].sortADisposition[RECULERADVERSAIRE].iconeSort, 0, 0, 2000, 2000,
                              109 * ecran.width / 144, ecran.height / 1.125, 67 * ecran.width / 144,
                              67 * ecran.height / 90, 0);
        al_draw_text(gameFont, al_map_rgb(100, 100, 100), 2300, 1400,
                     ALLEGRO_ALIGN_CENTER, "SORT RECULER ADVERSAIRE");
    } else {
        al_draw_scaled_bitmap(jeu.classes[PACMAN].sortADisposition[RECULERADVERSAIRE].iconeSort, 0, 0, 2000, 2000,
                              109 * ecran.width / 144, ecran.height / 1.125, 43 * ecran.width / 96,
                              43 * ecran.height / 60, 0);
    }

    if ((float) ecran.mouse_x < 427 * ecran.width / 576 && ecran.mouse_x > 409 * ecran.width / 576 &&(float) ecran.mouse_y < 353 * ecran.height / 360 && ecran.mouse_y > 9 * ecran.height / 10) {
        al_draw_scaled_bitmap(jeu.classes[PACMAN].sortADisposition[SORTDEFENCE].iconeSort, 0, 0, 2000, 2000,ecran.width / 1.44, 79 * ecran.height / 90, 15 * ecran.width / 32, 3 * ecran.height / 4,0);
        al_draw_text(gameFont, al_map_rgb(100, 100, 100), 2300, 1400,
                     ALLEGRO_ALIGN_CENTER, "SORT DEFENCE ");
    } else {
        al_draw_scaled_bitmap(jeu.classes[PACMAN].sortADisposition[SORTDEFENCE].iconeSort, 0, 0, 2000, 2000,
                              ecran.width / 1.44, 79 * ecran.height / 90, 65 * ecran.width / 144,
                              13 * ecran.height / 18, 0);
    }

    if ((float) ecran.mouse_x < ecran.width / 1.152 && ecran.mouse_x > 119 * ecran.width / 144 &&
        (float) ecran.mouse_y < 353 * ecran.height / 360 && ecran.mouse_y > 9 * ecran.height / 10) {
        al_draw_scaled_bitmap(jeu.classes[PACMAN].sortADisposition[FLAMME].iconeSort, 0, 0, 2000, 2000,
                              239 * ecran.width / 288, 319 * ecran.height / 360, 85 * ecran.width / 288,
                              17 * ecran.height / 36, 0);
        al_draw_text(gameFont, al_map_rgb(100, 100, 100), 2300, 1400,
                     ALLEGRO_ALIGN_CENTER, "SORT FLAMME ");
    } else {
        al_draw_scaled_bitmap(jeu.classes[PACMAN].sortADisposition[FLAMME].iconeSort, 0, 0, 2000, 2000,
                              239 * ecran.width / 288, 319 * ecran.height / 360, ecran.width / 3.6, ecran.height / 2.25,
                              0);
    }
}

void drawSortDONKEYKONG(ALLEGRO_FONT* gameFont, Jeux jeu, InfoEcran ecran) {
    if ((float) ecran.mouse_x < 235 * ecran.width / 288 && ecran.mouse_x > 73 * ecran.width / 96 &&
        (float) ecran.mouse_y < 59 * ecran.height / 60 && ecran.mouse_y > ecran.height / 1.125) {
        al_draw_scaled_bitmap(jeu.classes[DONKEY_KONG].sortADisposition[MORTEL].iconeSort, 0, 0, 2000, 2000,
                              242 * ecran.width / 320, 53 * ecran.height / 60, 131 * ecran.width / 288,
                              131 * ecran.height / 180, 0);
        al_draw_text(gameFont, al_map_rgb(100, 100, 100), 2300, 1400,
                     ALLEGRO_ALIGN_CENTER, "SORT MORTEL");
    } else {
        al_draw_scaled_bitmap(jeu.classes[DONKEY_KONG].sortADisposition[MORTEL].iconeSort, 0, 0, 2000, 2000,
                              242 * ecran.width / 320, 53 * ecran.height / 60, 127 * ecran.width / 288,
                              127 * ecran.height / 180, 0);
    }

    if ((float) ecran.mouse_x < 427 * ecran.width / 576 && ecran.mouse_x > 409 * ecran.width / 576 &&
        (float) ecran.mouse_y < 353 * ecran.height / 360 && ecran.mouse_y > 9 * ecran.height / 10) {
        al_draw_scaled_bitmap(jeu.classes[DONKEY_KONG].sortADisposition[POINGGANT].iconeSort, 0, 0, 2000, 2000,
                              ecran.width / 1.44, ecran.height / 1.125, 15 * ecran.width / 32, 3 * ecran.height / 4, 0);
        al_draw_text(gameFont, al_map_rgb(100, 100, 100), 2300, 1400,
                     ALLEGRO_ALIGN_CENTER, "SORT POING GANT ");
    } else {
        al_draw_scaled_bitmap(jeu.classes[DONKEY_KONG].sortADisposition[POINGGANT].iconeSort, 0, 0, 2000, 2000,
                              ecran.width / 1.44, ecran.height / 1.125, 65 * ecran.width / 144, 13 * ecran.height / 18,
                              0);
    }

    if ((float) ecran.mouse_x < 85 * ecran.width / 96 && ecran.mouse_x > 799 * ecran.width / 960 &&
        (float) ecran.mouse_y < 353 * ecran.height / 360 && ecran.mouse_y > 9 * ecran.height / 10) {
        al_draw_scaled_bitmap(jeu.classes[DONKEY_KONG].sortADisposition[SAUT].iconeSort, 0, 0, 2000, 2000,
                              ecran.width / 1.2, 7 * ecran.height / 8, 139 * ecran.width / 288,
                              139 * ecran.height / 180, 0);
        al_draw_text(gameFont, al_map_rgb(100, 100, 100), 2300, 1400,
                     ALLEGRO_ALIGN_CENTER, "SORT SAUT");
    } else {
        al_draw_scaled_bitmap(jeu.classes[DONKEY_KONG].sortADisposition[SAUT].iconeSort, 0, 0, 2000, 2000,
                              ecran.width / 1.2, 7 * ecran.height / 8, 67 * ecran.width / 144, 67 * ecran.height / 90,
                              0);
    }
}
void sortEnFonctionDesClasses(ALLEGRO_FONT* gameFont, ALLEGRO_FONT* smallameFont, Jeux jeu, InfoEcran ecran, int joueurQuiJoue){
    if(jeu.joueur[joueurQuiJoue].sortAppuye != 3) {
        if ((float) ecran.mouse_x < 11 * ecran.width / 13 && ecran.mouse_x > 6 * ecran.width / 8 &&
            (float) ecran.mouse_y < 80 * ecran.height / 90 && ecran.mouse_y > 75 * ecran.height / 90) {
            al_draw_filled_rectangle(6 * ecran.width / 8, 75 * ecran.height / 90, 11 * ecran.width / 13,
                                     80 * ecran.height / 90, al_map_rgb(200, 200, 200));
        } else {
            al_draw_filled_rectangle(6 * ecran.width / 8, 75 * ecran.height / 90, 11 * ecran.width / 13,
                                     80 * ecran.height / 90, al_map_rgb(240, 240, 240));
        }
        al_draw_text(smallameFont, al_map_rgb(20, 20, 20), 11.95 * ecran.width / 15,76 * ecran.height / 90, ALLEGRO_ALIGN_CENTER, "BOUGER") ;
    }
    switch (jeu.joueur[joueurQuiJoue].classe) {
        case KIRBY :
            drawSortKIRBY(gameFont, jeu, ecran);
            break;
        case PACMAN :
            drawSortPACMAN(gameFont, jeu, ecran);
            break;
        case MARIO :
            drawSortMARIO(gameFont, jeu, ecran);
            break;
        case DONKEY_KONG :
            drawSortDONKEYKONG(gameFont, jeu, ecran);
            break;
        case PEACH :
            drawSortPEACH(gameFont, jeu, ecran);
            break;
    }
}
void actionSortFLAMME (Jeux* jeu, int joueurQuiJoue, Map map[30][30]){
    int PASort = 4;
    int quelJoueurSurLaCase = map[jeu->info.collisionSourisMap[0][0]][jeu->info.collisionSourisMap[1][0]].joueurPresentDessus ;
    int possibiliteDeJouer = 0;
    //possibiliteDeJouer = verifierPADuJoueur(jeu, joueurQuiJoue, jeu.joueur[joueurQuiJoue].PA, PASort);
    // if (possibiliteDeJouer == 0){
    if (verifierPorteeLigne(*jeu, jeu->joueur[joueurQuiJoue].sortAppuye) && quelJoueurSurLaCase != 0) {
        jeu->joueur[quelJoueurSurLaCase-1].PV -= 40 ;
        jeu->joueur[joueurQuiJoue].sortAppuye = 3 ;

    }
    jeu->joueur[joueurQuiJoue].PA -= PASort;
    // }
}
void actionSortCOUPCORONA (Jeux jeu, int joueurQuiJoue){
    int PASort = 4;
    int possibiliteDeJouer = 0;
    //possibiliteDeJouer = verifierPADuJoueur(jeu, joueurQuiJoue, jeu.joueur[joueurQuiJoue].PA, PASort);

    //if (possibiliteDeJouer == 0){
    for(int i = 0; i < jeu.info.nbJoueur; i++){
        if (i != jeu.info.joueurQuiJoue){
            if(((jeu.joueur[i].caseX == jeu.joueur[joueurQuiJoue].caseX +5) && (jeu.joueur[i].caseY == jeu.joueur[joueurQuiJoue].caseY))
               || ((jeu.joueur[i].caseX == jeu.joueur[joueurQuiJoue].caseX - 5) && (jeu.joueur[i].caseY == jeu.joueur[joueurQuiJoue].caseY))
               || ((jeu.joueur[i].caseY == jeu.joueur[joueurQuiJoue].caseY + 5 ) && (jeu.joueur[i].caseX == jeu.joueur[joueurQuiJoue].caseX))
               || ((jeu.joueur[i].caseY == jeu.joueur[joueurQuiJoue].caseY - 5) && (jeu.joueur[i].caseX == jeu.joueur[joueurQuiJoue].caseX))){
                jeu.joueur[i].PV -= 40;
            }
        }
    }
    jeu.joueur[joueurQuiJoue].PA -= PASort;
    //}
}
void actionSortFLEUR (Jeux jeu, int joueurQuiJoue){
    int PASort = 4;
    int possibiliteDeJouer = 0;
    possibiliteDeJouer = verifierPADuJoueur(jeu, joueurQuiJoue, jeu.joueur[joueurQuiJoue].PA, PASort);

    if (possibiliteDeJouer == 0){
        for(int i = 0; i < jeu.info.nbJoueur; i++){
            if (i != jeu.info.joueurQuiJoue){
                if(((jeu.joueur[i].caseX == jeu.joueur[joueurQuiJoue].caseX +3) && (jeu.joueur[i].caseY == jeu.joueur[joueurQuiJoue].caseY))
                   || ((jeu.joueur[i].caseX == jeu.joueur[joueurQuiJoue].caseX - 3) && (jeu.joueur[i].caseY == jeu.joueur[joueurQuiJoue].caseY))
                   || ((jeu.joueur[i].caseY == jeu.joueur[joueurQuiJoue].caseY +3 ) && (jeu.joueur[i].caseX == jeu.joueur[joueurQuiJoue].caseX))
                   || ((jeu.joueur[i].caseY == jeu.joueur[joueurQuiJoue].caseY - 3) && (jeu.joueur[i].caseX == jeu.joueur[joueurQuiJoue].caseX))){
                    jeu.joueur[i].PV -= 40;
                }
            }
        }
        jeu.joueur[joueurQuiJoue].PA -= 4;
    }
}
void actionSortPOING (Jeux jeu, int joueurQuiJoue, InfoEcran ecran){
    int PASort = 2;
    int possibiliteDeJouer = 0;
    //possibiliteDeJouer = verifierPADuJoueur(jeu, joueurQuiJoue, jeu.joueur[joueurQuiJoue].PA, PASort);

    //if (possibiliteDeJouer == 0){
    for(int i = 0; i < jeu.info.nbJoueur; i++){
        if (i != jeu.info.joueurQuiJoue){
            if(((jeu.joueur[i].caseX == jeu.joueur[joueurQuiJoue].caseX +1) && (jeu.joueur[i].caseY == jeu.joueur[joueurQuiJoue].caseY))
               || ((jeu.joueur[i].caseX == jeu.joueur[joueurQuiJoue].caseX - 1) && (jeu.joueur[i].caseY == jeu.joueur[joueurQuiJoue].caseY))
               || ((jeu.joueur[i].caseY == jeu.joueur[joueurQuiJoue].caseY +1 ) && (jeu.joueur[i].caseX == jeu.joueur[joueurQuiJoue].caseX))
               || ((jeu.joueur[i].caseY == jeu.joueur[joueurQuiJoue].caseY - 1) && (jeu.joueur[i].caseX == jeu.joueur[joueurQuiJoue].caseX))){
                jeu.joueur[i].PV -= 30;
            }
        }
    }
    jeu.joueur[joueurQuiJoue].PA -= PASort;
    // }
}
void actionSortCOUPDEPIED (Jeux jeu, int joueurQuiJoue, Map joueur[30][30], InfoEcran ecran){
    int PASort = 3;
    int possibiliteDeJouer = 0;
    //possibiliteDeJouer = verifierPADuJoueur(jeu, joueurQuiJoue, jeu.joueur[joueurQuiJoue].PA, PASort);

    //if (possibiliteDeJouer == 0){
    for(int i = 0; i < jeu.info.nbJoueur; i++){
        if (i != jeu.info.joueurQuiJoue){
            if(((jeu.joueur[i].caseX == jeu.joueur[joueurQuiJoue].caseX + 1) && (jeu.joueur[i].caseY == jeu.joueur[joueurQuiJoue].caseY))
               || ((jeu.joueur[i].caseX == jeu.joueur[joueurQuiJoue].caseX - 1) && (jeu.joueur[i].caseY == jeu.joueur[joueurQuiJoue].caseY))
               || ((jeu.joueur[i].caseY == jeu.joueur[joueurQuiJoue].caseY + 1 ) && (jeu.joueur[i].caseX == jeu.joueur[joueurQuiJoue].caseX))
               || ((jeu.joueur[i].caseY == jeu.joueur[joueurQuiJoue].caseY - 1) && (jeu.joueur[i].caseX == jeu.joueur[joueurQuiJoue].caseX))) {
                jeu.joueur[i].PV -= 20;
                if (jeu.joueur[i].caseX == jeu.joueur[joueurQuiJoue].caseX + 1) {
                    if (joueur[jeu.joueur[i].caseX + 1][jeu.joueur[i].caseY].obstacle != 1 && jeu.joueur[i].caseX <= 18) {
                        jeu.joueur[i].caseX++;
                    }
                    else if(joueur[jeu.joueur[i].caseX][jeu.joueur[i].caseY+1].obstacle != 1 && jeu.joueur[i].caseY <= 13){
                        jeu.joueur[i].caseY++;
                    }
                    else if(joueur[jeu.joueur[i].caseX][jeu.joueur[i].caseY - 1].obstacle != 1 && jeu.joueur[i].caseY >= 1){
                        jeu.joueur[i].caseY--;
                    }
                } else if (jeu.joueur[i].caseX == jeu.joueur[joueurQuiJoue].caseX - 1) {
                    if (joueur[jeu.joueur[i].caseX - 1][jeu.joueur[i].caseY].obstacle != 1 && jeu.joueur[i].caseX >= 1) {
                        jeu.joueur[i].caseX--;
                    }
                    else if(joueur[jeu.joueur[i].caseX][jeu.joueur[i].caseY+1].obstacle != 1 && jeu.joueur[i].caseY <= 13){
                        jeu.joueur[i].caseY++;
                    }
                    else if(joueur[jeu.joueur[i].caseX][jeu.joueur[i].caseY - 1].obstacle != 1 && jeu.joueur[i].caseY <= 1){
                        jeu.joueur[i].caseY--;
                    }
                } else if (jeu.joueur[i].caseY == jeu.joueur[joueurQuiJoue].caseY + 1) {
                    if (joueur[jeu.joueur[i].caseX][jeu.joueur[i].caseY + 1].obstacle != 1 && jeu.joueur[i].caseY <= 13) {
                        jeu.joueur[i].caseY++;
                    }
                    else if (joueur[jeu.joueur[i].caseX - 1][jeu.joueur[i].caseY].obstacle != 1 && jeu.joueur[i].caseX >= 1) {
                        jeu.joueur[i].caseX--;
                    }
                    else if (joueur[jeu.joueur[i].caseX + 1][jeu.joueur[i].caseY].obstacle != 1 && jeu.joueur[i].caseX <= 18) {
                        jeu.joueur[i].caseX++;
                    }
                } else if (jeu.joueur[i].caseY == jeu.joueur[joueurQuiJoue].caseY - 1) {
                    if (joueur[jeu.joueur[i].caseX][jeu.joueur[i].caseY - 1].obstacle != 1 && jeu.joueur[i].caseY >= 1) {
                        jeu.joueur[i].caseY--;
                    }
                    else if(joueur[jeu.joueur[i].caseX - 1][jeu.joueur[i].caseY].obstacle != 1 && jeu.joueur[i].caseX >= 1) {
                        jeu.joueur[i].caseX--;
                    }
                    else if (joueur[jeu.joueur[i].caseX + 1][jeu.joueur[i].caseY].obstacle != 1 && jeu.joueur[i].caseX <= 18) {
                        jeu.joueur[i].caseX++;
                    }
                }
            }
        }
    }
    jeu.joueur[joueurQuiJoue].PA -= PASort;
    //}
}
void actionSortRECULERADVERSAIRE (Jeux jeu, int joueurQuiJoue, Map joueur[30][30]) {
    int PASort = 2;
    int possibiliteDeJouer = 0;
    //possibiliteDeJouer = verifierPADuJoueur(jeu, joueurQuiJoue, jeu.joueur[joueurQuiJoue].PA, PASort);

    //if (possibiliteDeJouer == 0){
    for (int i = 0; i < jeu.info.nbJoueur; i++) {
        if (i != jeu.info.joueurQuiJoue) {
            if (((jeu.joueur[i].caseX == jeu.joueur[joueurQuiJoue].caseX + 1) &&
                 (jeu.joueur[i].caseY == jeu.joueur[joueurQuiJoue].caseY))
                || ((jeu.joueur[i].caseX == jeu.joueur[joueurQuiJoue].caseX - 1) &&
                    (jeu.joueur[i].caseY == jeu.joueur[joueurQuiJoue].caseY))
                || ((jeu.joueur[i].caseY == jeu.joueur[joueurQuiJoue].caseY + 1) &&
                    (jeu.joueur[i].caseX == jeu.joueur[joueurQuiJoue].caseX))
                || ((jeu.joueur[i].caseY == jeu.joueur[joueurQuiJoue].caseY - 1) &&
                    (jeu.joueur[i].caseX == jeu.joueur[joueurQuiJoue].caseX))) {
                jeu.joueur[i].PV -= 10;
                if (jeu.joueur[i].caseX == jeu.joueur[joueurQuiJoue].caseX + 1) {
                    if (joueur[jeu.joueur[i].caseX + 5][jeu.joueur[i].caseY].obstacle != 1 &&
                        jeu.joueur[i].caseX <= 14) {
                        jeu.joueur[i].caseX = jeu.joueur[i].caseX + 5;
                    } else if (joueur[jeu.joueur[i].caseX][jeu.joueur[i].caseY + 5].obstacle != 1 &&
                               jeu.joueur[i].caseY <= 9) {
                        jeu.joueur[i].caseY = jeu.joueur[i].caseY + 5;
                    } else if (joueur[jeu.joueur[i].caseX][jeu.joueur[i].caseY - 5].obstacle != 1 &&
                               jeu.joueur[i].caseY >= 5) {
                        jeu.joueur[i].caseY = jeu.joueur[i].caseY - 5;
                    }
                } else if (jeu.joueur[i].caseX == jeu.joueur[joueurQuiJoue].caseX - 1) {
                    if (joueur[jeu.joueur[i].caseX - 5][jeu.joueur[i].caseY].obstacle != 1 &&
                        jeu.joueur[i].caseX >= 5) {
                        jeu.joueur[i].caseX = jeu.joueur[i].caseX - 5;
                    } else if (joueur[jeu.joueur[i].caseX][jeu.joueur[i].caseY + 5].obstacle != 1 &&
                               jeu.joueur[i].caseY <= 9) {
                        jeu.joueur[i].caseY = jeu.joueur[i].caseY;
                    } else if (joueur[jeu.joueur[i].caseX][jeu.joueur[i].caseY - 5].obstacle != 1 &&
                               jeu.joueur[i].caseY <= 5) {
                        jeu.joueur[i].caseY = jeu.joueur[i].caseY - 5;
                    }
                } else if (jeu.joueur[i].caseY == jeu.joueur[joueurQuiJoue].caseY + 1) {
                    if (joueur[jeu.joueur[i].caseX][jeu.joueur[i].caseY + 5].obstacle != 1 &&
                        jeu.joueur[i].caseY <= 9) {
                        jeu.joueur[i].caseY = jeu.joueur[i].caseY + 5;
                    } else if (joueur[jeu.joueur[i].caseX - 5][jeu.joueur[i].caseY].obstacle != 1 &&
                               jeu.joueur[i].caseX >= 5) {
                        jeu.joueur[i].caseX = jeu.joueur[i].caseX - 5;
                    } else if (joueur[jeu.joueur[i].caseX + 5][jeu.joueur[i].caseY].obstacle != 1 &&
                               jeu.joueur[i].caseX <= 14) {
                        jeu.joueur[i].caseX += 5;
                    }
                } else if (jeu.joueur[i].caseY == jeu.joueur[joueurQuiJoue].caseY - 1) {
                    if (joueur[jeu.joueur[i].caseX][jeu.joueur[i].caseY - 5].obstacle != 1 &&
                        jeu.joueur[i].caseY >= 5) {
                        jeu.joueur[i].caseY -= 5;
                    } else if (joueur[jeu.joueur[i].caseX - 5][jeu.joueur[i].caseY].obstacle != 1 &&
                               jeu.joueur[i].caseX >= 5) {
                        jeu.joueur[i].caseX -=5;
                    } else if (joueur[jeu.joueur[i].caseX + 5][jeu.joueur[i].caseY].obstacle != 1 &&
                               jeu.joueur[i].caseX <= 14) {
                        jeu.joueur[i].caseX += 5;
                    }
                }
            }
        }
    }
    jeu.joueur[joueurQuiJoue].PA -= PASort;
    //}
}
void actionSortPOING2 (Jeux jeu, int joueurQuiJoue){
    int PASort = 2;
    int possibiliteDeJouer = 0;
    //possibiliteDeJouer = verifierPADuJoueur(jeu, joueurQuiJoue, jeu.joueur[joueurQuiJoue].PA, PASort);

    //if (possibiliteDeJouer == 0){
    for(int i = 0; i < jeu.info.nbJoueur; i++){
        if (i != jeu.info.joueurQuiJoue){
            if(((jeu.joueur[i].caseX == jeu.joueur[joueurQuiJoue].caseX +1) && (jeu.joueur[i].caseY == jeu.joueur[joueurQuiJoue].caseY))
               || ((jeu.joueur[i].caseX == jeu.joueur[joueurQuiJoue].caseX - 1) && (jeu.joueur[i].caseY == jeu.joueur[joueurQuiJoue].caseY))
               || ((jeu.joueur[i].caseY == jeu.joueur[joueurQuiJoue].caseY +1 ) && (jeu.joueur[i].caseX == jeu.joueur[joueurQuiJoue].caseX))
               || ((jeu.joueur[i].caseY == jeu.joueur[joueurQuiJoue].caseY - 1) && (jeu.joueur[i].caseX == jeu.joueur[joueurQuiJoue].caseX))){
                jeu.joueur[i].PV -= 10;
            }
        }
    }
    jeu.joueur[joueurQuiJoue].PA -= PASort;
    //}
}
void actionSortPIEDPEACH (Jeux jeu, int joueurQuiJoue, InfoEcran ecran){
    int PASort = 2;
    int possibiliteDeJouer = 0;
    //possibiliteDeJouer = verifierPADuJoueur(jeu, joueurQuiJoue, jeu.joueur[joueurQuiJoue].PA, PASort);
    //if (possibiliteDeJouer == 0){
    for(int i = 0; i < jeu.info.nbJoueur; i++){
        if (i != jeu.info.joueurQuiJoue){
            if(((jeu.joueur[i].caseX == jeu.joueur[joueurQuiJoue].caseX +1) && (jeu.joueur[i].caseY == jeu.joueur[joueurQuiJoue].caseY))
               || ((jeu.joueur[i].caseX == jeu.joueur[joueurQuiJoue].caseX - 1) && (jeu.joueur[i].caseY == jeu.joueur[joueurQuiJoue].caseY))
               || ((jeu.joueur[i].caseY == jeu.joueur[joueurQuiJoue].caseY +1 ) && (jeu.joueur[i].caseX == jeu.joueur[joueurQuiJoue].caseX))
               || ((jeu.joueur[i].caseY == jeu.joueur[joueurQuiJoue].caseY - 1) && (jeu.joueur[i].caseX == jeu.joueur[joueurQuiJoue].caseX))){
                jeu.joueur[i].PV -= 20;
            }
        }
    }
    jeu.joueur[joueurQuiJoue].PA -= PASort;
    // }
}
void actionSortSOIN (Jeux jeu, int joueurQuiJoue){
    int PASort = 4;
    int possibiliteDeJouer = 0;
    //possibiliteDeJouer = verifierPADuJoueur(jeu, joueurQuiJoue, jeu.joueur[joueurQuiJoue].PA, PASort);

    //if (possibiliteDeJouer == 0){
    jeu.joueur[joueurQuiJoue].PV = jeu.joueur[joueurQuiJoue].PV + 25;
    jeu.joueur[joueurQuiJoue].PA = jeu.joueur[joueurQuiJoue].PA - PASort;
    //}
}
void actionSortPOINGGANT (Jeux jeu, int joueurQuiJoue){
    int PASort = 3;
    int possibiliteDeJouer = 0;
    //possibiliteDeJouer = verifierPADuJoueur(jeu, joueurQuiJoue, jeu.joueur[joueurQuiJoue].PA, PASort);

    //if (possibiliteDeJouer == 0){
    for(int i = 0; i < jeu.info.nbJoueur; i++){
        if (i != jeu.info.joueurQuiJoue){
            if(((jeu.joueur[i].caseX == jeu.joueur[joueurQuiJoue].caseX +1) && (jeu.joueur[i].caseY == jeu.joueur[joueurQuiJoue].caseY))
               || ((jeu.joueur[i].caseX == jeu.joueur[joueurQuiJoue].caseX - 1) && (jeu.joueur[i].caseY == jeu.joueur[joueurQuiJoue].caseY))
               || ((jeu.joueur[i].caseY == jeu.joueur[joueurQuiJoue].caseY + 1) && (jeu.joueur[i].caseX == jeu.joueur[joueurQuiJoue].caseX))
               || ((jeu.joueur[i].caseY == jeu.joueur[joueurQuiJoue].caseY - 1) && (jeu.joueur[i].caseX == jeu.joueur[joueurQuiJoue].caseX))){
                jeu.joueur[i].PV -= 25;
            }
        }
    }
    jeu.joueur[joueurQuiJoue].PA -= PASort;
    //}
}
void actionSortMORTEL (Jeux jeu, int joueurQuiJoue){
    int PASort = 6;
    int possibiliteDeJouer = 0;
    //possibiliteDeJouer = verifierPADuJoueur(jeu, joueurQuiJoue, jeu.joueur[joueurQuiJoue].PA, PASort);

    // if (possibiliteDeJouer == 0){
    for(int i = 0; i < jeu.info.nbJoueur; i++){
        if (i != jeu.info.joueurQuiJoue){
            if(((jeu.joueur[i].caseX == jeu.joueur[joueurQuiJoue].caseX +1) && (jeu.joueur[i].caseY == jeu.joueur[joueurQuiJoue].caseY))
               || ((jeu.joueur[i].caseX == jeu.joueur[joueurQuiJoue].caseX - 1) && (jeu.joueur[i].caseY == jeu.joueur[joueurQuiJoue].caseY))
               || ((jeu.joueur[i].caseY == jeu.joueur[joueurQuiJoue].caseY + 1) && (jeu.joueur[i].caseX == jeu.joueur[joueurQuiJoue].caseX))
               || ((jeu.joueur[i].caseY == jeu.joueur[joueurQuiJoue].caseY - 1) && (jeu.joueur[i].caseX == jeu.joueur[joueurQuiJoue].caseX))){
                jeu.joueur[i].PV -= 60;
            }
        }
    }
    jeu.joueur[joueurQuiJoue].PA -= PASort;
    //}
}
void actionSortSAUTDONKEYKONG (Jeux jeu, int joueurQuiJoue, int mouse_x, int mouse_y, Map map[30][30], InfoEcran ecran){
    int PASort = 3;
    int possibiliteDeJouer = 0;
    //possibiliteDeJouer = verifierPADuJoueur(jeu, joueurQuiJoue, jeu.joueur[joueurQuiJoue].PA, PASort);

    //if (possibiliteDeJouer == 0){
    for(int j = 0; j < mapY; j++){
        for(int i = 0; i<mapX; i++){
            if(collisionCercle(mouse_x, mouse_y, map, i, j, ecran.width) == true){
                jeu.joueur[joueurQuiJoue].caseX = map[i][j].x;
                jeu.joueur[joueurQuiJoue].caseY = map[i][j].y;
            }
        }
    }
    jeu.joueur[joueurQuiJoue].PA -= PASort;
    // }
}
int verifierPADuJoueur (Jeux jeu, int joueurQuiJoue, int PADuJoueur, int PADuSort) {
    int action = 0;
    verifierPV(jeu, joueurQuiJoue);
    if (jeu.joueur[joueurQuiJoue].etat != 1) {
        if (PADuJoueur < PADuSort) {
            action = 1;
            return action;  //action == 1 : on ne peut pas utiliser le sort
            //al_draw_text(gameFont, al_map_rgb(100, 100, 100), 280, 200, ALLEGRO_ALIGN_CENTER, "VOUS N'AVEZ PAS ASSEZ DE POINT D'ATTAQUE POUR UTILISER CE SORT ");
        }
        return action;  //action == 0  le joueur peut utiliser le sort
    }
}

void verifierPV (Jeux jeu, int joueurQuiJoue) {
    if (jeu.joueur[joueurQuiJoue].PV <= 0) {
        jeu.joueur[joueurQuiJoue].etat = 1; //etat 1 joueur meurt     // etat 0 : joueur en vie > 0 PV
    }
}

void initialiserSortEnFonctionDeLeurPosition(Jeux* jeu, int joueurQuiJoue, InfoEcran ecran, int sort, Map map[30][30]) {
    if (sort == 0) {
        if (jeu->joueur[joueurQuiJoue].classe == KIRBY) {
            actionSortCOUPDEPIED(*jeu, joueurQuiJoue, map, ecran);
        }
        if (jeu->joueur[joueurQuiJoue].classe == MARIO) {
            actionSortPOING2 (*jeu, joueurQuiJoue);
        }
        if (jeu->joueur[joueurQuiJoue].classe == DONKEY_KONG) {
            actionSortPOINGGANT (*jeu, joueurQuiJoue);
        }
        if (jeu->joueur[joueurQuiJoue].classe == PEACH) {
            actionSortPIEDPEACH(*jeu, joueurQuiJoue, ecran);
        }
    }
    else if (sort == 1) {
        if (jeu->joueur[joueurQuiJoue].classe == KIRBY) {
            actionSortPOING(*jeu, joueurQuiJoue, ecran);
        }
        if (jeu->joueur[joueurQuiJoue].classe == MARIO) {
            actionSortCOUPCORONA (*jeu, joueurQuiJoue);
        }
        if (jeu->joueur[joueurQuiJoue].classe == PACMAN) {
            actionSortRECULERADVERSAIRE (*jeu, joueurQuiJoue, map);
        }
        if (jeu->joueur[joueurQuiJoue].classe == DONKEY_KONG) {
            actionSortMORTEL (*jeu, joueurQuiJoue);
        }
        if (jeu->joueur[joueurQuiJoue].classe == PEACH) {
            actionSortFLEUR (*jeu, joueurQuiJoue);
        }
    }
    if (sort == 2){
        if (jeu->joueur[joueurQuiJoue].classe == KIRBY){
            actionSortFLAMME (jeu, joueurQuiJoue, map);
        }
        if (jeu->joueur[joueurQuiJoue].classe == MARIO){
            actionSortFLAMME(jeu, joueurQuiJoue, map);
        }
        if (jeu->joueur[joueurQuiJoue].classe == PACMAN){
            actionSortFLAMME (jeu, joueurQuiJoue, map);
        }
        if (jeu->joueur[joueurQuiJoue].classe == DONKEY_KONG){
            actionSortSAUTDONKEYKONG (*jeu, joueurQuiJoue, ecran.mouse_x, ecran.mouse_y, map, ecran);
        }
        if (jeu->joueur[joueurQuiJoue].classe == PEACH){
            actionSortSOIN (*jeu, joueurQuiJoue);
        }
    }
}


void sortChoisi (InfoEcran ecran, int* sortAppuye) {
    if ((float) ecran.mouse_x < 121*ecran.width/160 && ecran.mouse_x > 1987*ecran.width/2880 && (float) ecran.mouse_y < 23*ecran.height/24 && ecran.mouse_y > 79*ecran.height/90) {
        *sortAppuye = 0;
    }
    else if ((float) ecran.mouse_x < 2369*ecran.width/2880 && ecran.mouse_x > 121*ecran.width/160 && (float) ecran.mouse_y < 23*ecran.height/24 && ecran.mouse_y > 79*ecran.height/90) {
        *sortAppuye = 1;
    }
    else if ((float) ecran.mouse_x < 65*ecran.width/72 && ecran.mouse_x > ecran.width/1.2 && (float) ecran.mouse_y < 23*ecran.height/24 && ecran.mouse_y > 79*ecran.height/90) {
        *sortAppuye = 2;
    }
}
void afficherPortee(Map map[30][30], double scalex, double scaley, Jeux jeu, int joueurQuiJoue) {
    if(jeu.joueur[joueurQuiJoue].sortAppuye != 3) {
        dessinerPorteeSortLigne(map, scalex, scaley, jeu, jeu.joueur[joueurQuiJoue].sortAppuye);
    }

    /*switch(jeu.joueur[joueurQuiJoue].sortAppuye) {
        case 0 : {
            dessinerPorteeSortLigne(map, scalex, scaley, jeu, 0) ;
            break ;
        }
        case 1 : {
            if(jeu.joueur[joueurQuiJoue].classe == PEACH || jeu.joueur[joueurQuiJoue].classe == MARIO) {
                dessinerPorteeSortRect(map, scalex, scaley, jeu, 1) ;
            }
            else dessinerPorteeSortLigne(map, scalex, scaley, jeu, 1) ;
            break ;
        }
        case 2 : {
            if(jeu.joueur[joueurQuiJoue].classe == PACMAN || jeu.joueur[joueurQuiJoue].classe == MARIO || jeu.joueur[joueurQuiJoue].classe == KIRBY) {
                dessinerPorteeSortRect(map, scalex, scaley, jeu, 2) ;
            }
            else dessinerPorteeSortLigne(map, scalex, scaley, jeu, 2) ;
            break ;
        }
    }*/
}

void appuyerSortSurMap(Jeux* jeu, Map map[30][30]) {
    if(verifierPorteeLigne(*jeu, jeu->joueur[jeu->info.joueurQuiJoue].sortAppuye) && jeu->joueur[jeu->info.joueurQuiJoue].sortAppuye != 3) {
        appliquerSort(jeu, jeu->info.joueurQuiJoue, map) ;
    }
}

void appliquerSort(Jeux* jeu, int joueurQuiJoue, Map map[30][30]) {
    int quelJoueurSurLaCase = map[jeu->info.collisionSourisMap[0][0]][jeu->info.collisionSourisMap[1][0]].joueurPresentDessus;
    if(jeu->joueur[quelJoueurSurLaCase - 1].sortSpecial != 1) {
        switch (jeu->joueur[joueurQuiJoue].sortAppuye) {
            case 0 : {
                if (jeu->joueur[joueurQuiJoue].PA >= jeu->classes[jeu->joueur[joueurQuiJoue].classe].sortADisposition[0].PA) {
                    if (jeu->joueur[joueurQuiJoue].classe == KIRBY) {
                        if (quelJoueurSurLaCase != joueurQuiJoue + 1) {
                            ///COUPDEPIED
                            jeu->joueur[quelJoueurSurLaCase - 1].PV -= jeu->classes[jeu->joueur[joueurQuiJoue].classe].sortADisposition[0].degatsOUsoin;
                            jeu->joueur[joueurQuiJoue].PA -= jeu->classes[jeu->joueur[joueurQuiJoue].classe].sortADisposition[0].PA;
                        }
                    } else if (jeu->joueur[joueurQuiJoue].classe == PACMAN) {
                        jeu->joueur[joueurQuiJoue].sortSpecial = 1;
                        jeu->joueur[joueurQuiJoue].PA -= jeu->classes[jeu->joueur[joueurQuiJoue].classe].sortADisposition[0].PA;
                    } else {
                        if (quelJoueurSurLaCase != joueurQuiJoue + 1) {
                            jeu->joueur[quelJoueurSurLaCase - 1].PV -= jeu->classes[jeu->joueur[joueurQuiJoue].classe].sortADisposition[0].degatsOUsoin;
                            jeu->joueur[joueurQuiJoue].PA -= jeu->classes[jeu->joueur[joueurQuiJoue].classe].sortADisposition[0].PA;
                        }
                    }
                }
                break;
            }
            case 1 : {
                if (jeu->joueur[joueurQuiJoue].PA >= jeu->classes[jeu->joueur[joueurQuiJoue].classe].sortADisposition[1].PA) {
                    if (jeu->joueur[joueurQuiJoue].classe == PACMAN) {
                        ///RECULERADVERSAIRE
                        jeu->joueur[quelJoueurSurLaCase - 1].PV -= jeu->classes[jeu->joueur[joueurQuiJoue].classe].sortADisposition[0].degatsOUsoin;
                        jeu->joueur[joueurQuiJoue].PA -= jeu->classes[jeu->joueur[joueurQuiJoue].classe].sortADisposition[0].PA;
                    } else {
                        if (quelJoueurSurLaCase != joueurQuiJoue + 1) {
                            jeu->joueur[quelJoueurSurLaCase - 1].PV -= jeu->classes[jeu->joueur[joueurQuiJoue].classe].sortADisposition[1].degatsOUsoin;
                            jeu->joueur[joueurQuiJoue].PA -= jeu->classes[jeu->joueur[joueurQuiJoue].classe].sortADisposition[1].PA;
                        }
                    }
                }
                break;
            }
            case 2 : {
                if (jeu->joueur[joueurQuiJoue].PA >= jeu->classes[jeu->joueur[joueurQuiJoue].classe].sortADisposition[2].PA) {
                    if (jeu->joueur[joueurQuiJoue].classe == DONKEY_KONG) {
                        ///SAUT
                        if(map[jeu->info.collisionSourisMap[0][0]][jeu->info.collisionSourisMap[1][0]].obstacle != 1) {
                            jeu->joueur[joueurQuiJoue].caseXDepart= jeu->joueur[joueurQuiJoue].caseX;
                            jeu->joueur[joueurQuiJoue].caseYDepart= jeu->joueur[joueurQuiJoue].caseY;
                            jeu->joueur[joueurQuiJoue].dep=1;
                            map[jeu->joueur[joueurQuiJoue].caseX][jeu->joueur[joueurQuiJoue].caseY].joueurPresentDessus = 0 ;
                            jeu->joueur[joueurQuiJoue].quelAnimation = ATTAQUE1 ;
                            jeu->joueur[joueurQuiJoue].xArrive= jeu->info.collisionSourisMap[0][0];
                            jeu->joueur[joueurQuiJoue].yArrive= jeu->info.collisionSourisMap[0][1];
                            jeu->joueur[joueurQuiJoue].actif=1;
                            jeu->joueur[joueurQuiJoue].PM = 0 ;
                            jeu->joueur[joueurQuiJoue].PA -= jeu->classes[jeu->joueur[joueurQuiJoue].classe].sortADisposition[2].PA;
                        }
                    }
                    else {
                        if (jeu->joueur[joueurQuiJoue].classe == PEACH) {
                            if (jeu->joueur[joueurQuiJoue].PV + jeu->classes[jeu->joueur[joueurQuiJoue].classe].sortADisposition[2].degatsOUsoin <300) {
                                jeu->joueur[joueurQuiJoue].PV += jeu->classes[jeu->joueur[joueurQuiJoue].classe].sortADisposition[2].degatsOUsoin;
                            }
                            else jeu->joueur[joueurQuiJoue].PV = 300 ;
                        }
                        else {
                            if (quelJoueurSurLaCase != joueurQuiJoue + 1) {
                                jeu->joueur[quelJoueurSurLaCase - 1].PV -= jeu->classes[jeu->joueur[joueurQuiJoue].classe].sortADisposition[2].degatsOUsoin;
                            }
                        }
                        jeu->joueur[joueurQuiJoue].PA -= jeu->classes[jeu->joueur[joueurQuiJoue].classe].sortADisposition[2].PA;
                    }
                }
                break;
            }
        }
    }
    else {
        jeu->joueur[quelJoueurSurLaCase - 1].sortSpecial = 0 ;
        jeu->joueur[joueurQuiJoue].PA -= jeu->classes[jeu->joueur[joueurQuiJoue].classe].sortADisposition[jeu->joueur[joueurQuiJoue].sortAppuye].PA;

    }
    jeu->joueur[joueurQuiJoue].sortAppuye = 3 ;

}




void dessinerPorteeSortLigne(Map map[30][30], double scalex, double scaley, Jeux jeu, int sortAppuye) {
    for(int i = 1 ; i < jeu.classes[jeu.joueur[jeu.info.joueurQuiJoue].classe].sortADisposition[sortAppuye].portee+1 ; i++) {
        dessinerCase(map, jeu.joueur[jeu.info.joueurQuiJoue].caseX + i, jeu.joueur[jeu.info.joueurQuiJoue].caseY, scalex, scaley) ;
        dessinerCase(map, jeu.joueur[jeu.info.joueurQuiJoue].caseX - i, jeu.joueur[jeu.info.joueurQuiJoue].caseY, scalex, scaley) ;
        dessinerCase(map, jeu.joueur[jeu.info.joueurQuiJoue].caseX, jeu.joueur[jeu.info.joueurQuiJoue].caseY + i, scalex, scaley) ;
        dessinerCase(map, jeu.joueur[jeu.info.joueurQuiJoue].caseX, jeu.joueur[jeu.info.joueurQuiJoue].caseY - i, scalex, scaley) ;

    }
    if(jeu.classes[jeu.joueur[jeu.info.joueurQuiJoue].classe].sortADisposition[sortAppuye].portee == 0) {
        dessinerCase(map, jeu.joueur[jeu.info.joueurQuiJoue].caseX, jeu.joueur[jeu.info.joueurQuiJoue].caseY, scalex, scaley) ;
    }
}
void dessinerPorteeSortRect(Map map[30][30], double scalex, double scaley, Jeux jeu, int sortAppuye) {
    for(int j = jeu.classes[jeu.joueur[jeu.info.joueurQuiJoue].classe].sortADisposition[sortAppuye].portee ; j > 0 ; j--) {
        for (int i = 0; i <= jeu.classes[jeu.joueur[jeu.info.joueurQuiJoue].classe].sortADisposition[sortAppuye].portee; i++) {
            dessinerCase(map, jeu.joueur[jeu.info.joueurQuiJoue].caseX + j,jeu.joueur[jeu.info.joueurQuiJoue].caseY + i, scalex, scaley);
            dessinerCase(map, jeu.joueur[jeu.info.joueurQuiJoue].caseX - j,jeu.joueur[jeu.info.joueurQuiJoue].caseY - i, scalex, scaley);
            dessinerCase(map, jeu.joueur[jeu.info.joueurQuiJoue].caseX - i, jeu.joueur[jeu.info.joueurQuiJoue].caseY + j,scalex, scaley);
            dessinerCase(map, jeu.joueur[jeu.info.joueurQuiJoue].caseX + i, jeu.joueur[jeu.info.joueurQuiJoue].caseY - j,scalex, scaley);
            if (i != 0 && i != j) {
                dessinerCase(map, jeu.joueur[jeu.info.joueurQuiJoue].caseX + j,jeu.joueur[jeu.info.joueurQuiJoue].caseY - i, scalex, scaley);
                dessinerCase(map, jeu.joueur[jeu.info.joueurQuiJoue].caseX - j,jeu.joueur[jeu.info.joueurQuiJoue].caseY + i, scalex, scaley);
                dessinerCase(map, jeu.joueur[jeu.info.joueurQuiJoue].caseX - i,jeu.joueur[jeu.info.joueurQuiJoue].caseY - j,scalex, scaley);
                dessinerCase(map, jeu.joueur[jeu.info.joueurQuiJoue].caseX + i,jeu.joueur[jeu.info.joueurQuiJoue].caseY + j,scalex, scaley);
            }
        }
    }
}
bool verifierPorteeLigne(Jeux jeu, int sortAppuye) {
    for(int i = 0 ; i < jeu.classes[jeu.joueur[jeu.info.joueurQuiJoue].classe].sortADisposition[sortAppuye].portee+1 ; i++) {
        if((jeu.info.collisionSourisMap[0][0] == jeu.joueur[jeu.info.joueurQuiJoue].caseX + i && jeu.info.collisionSourisMap[1][0] == jeu.joueur[jeu.info.joueurQuiJoue].caseY)
           || (jeu.info.collisionSourisMap[0][0] == jeu.joueur[jeu.info.joueurQuiJoue].caseX - i && jeu.info.collisionSourisMap[1][0] == jeu.joueur[jeu.info.joueurQuiJoue].caseY)
           || (jeu.info.collisionSourisMap[0][0] == jeu.joueur[jeu.info.joueurQuiJoue].caseX && jeu.info.collisionSourisMap[1][0] == jeu.joueur[jeu.info.joueurQuiJoue].caseY + i)
           || (jeu.info.collisionSourisMap[0][0] == jeu.joueur[jeu.info.joueurQuiJoue].caseX && jeu.info.collisionSourisMap[1][0] == jeu.joueur[jeu.info.joueurQuiJoue].caseY - i)) {
            return true ;
        }
    }
    return  false ;
}
bool verifierPorteeRect(Jeux jeu, int sortAppuye) {
    for (int j = jeu.classes[jeu.joueur[jeu.info.joueurQuiJoue].classe].sortADisposition[sortAppuye].portee; j > 0; j--) {
        for (int i = 0; i <= jeu.classes[jeu.joueur[jeu.info.joueurQuiJoue].classe].sortADisposition[sortAppuye].portee; i++) {
            if ((jeu.info.collisionSourisMap[0][0] == jeu.joueur[jeu.info.joueurQuiJoue].caseX + j && jeu.info.collisionSourisMap[1][0] == jeu.joueur[jeu.info.joueurQuiJoue].caseY + i)
                || (jeu.info.collisionSourisMap[0][0] == jeu.joueur[jeu.info.joueurQuiJoue].caseX - j && jeu.info.collisionSourisMap[1][0] == jeu.joueur[jeu.info.joueurQuiJoue].caseY - i)
                || (jeu.info.collisionSourisMap[0][0] == jeu.joueur[jeu.info.joueurQuiJoue].caseX - i && jeu.info.collisionSourisMap[1][0] == jeu.joueur[jeu.info.joueurQuiJoue].caseY + j)
                || (jeu.info.collisionSourisMap[0][0] == jeu.joueur[jeu.info.joueurQuiJoue].caseX + i && jeu.info.collisionSourisMap[1][0] == jeu.joueur[jeu.info.joueurQuiJoue].caseY - j)) {
                return true;
            }
            if(i != 0 && i != j) {
                if ((jeu.info.collisionSourisMap[0][0] == jeu.joueur[jeu.info.joueurQuiJoue].caseX + j && jeu.info.collisionSourisMap[1][0] == jeu.joueur[jeu.info.joueurQuiJoue].caseY - i)
                    || (jeu.info.collisionSourisMap[0][0] == jeu.joueur[jeu.info.joueurQuiJoue].caseX - j && jeu.info.collisionSourisMap[1][0] == jeu.joueur[jeu.info.joueurQuiJoue].caseY + i)
                    || (jeu.info.collisionSourisMap[0][0] == jeu.joueur[jeu.info.joueurQuiJoue].caseX - i && jeu.info.collisionSourisMap[1][0] == jeu.joueur[jeu.info.joueurQuiJoue].caseY - j)
                    || (jeu.info.collisionSourisMap[0][0] == jeu.joueur[jeu.info.joueurQuiJoue].caseX + i && jeu.info.collisionSourisMap[1][0] == jeu.joueur[jeu.info.joueurQuiJoue].caseY + j)) {
                    return true;
                }
            }
        }
    }
    return false;
}