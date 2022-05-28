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
        al_draw_filled_rectangle(ecran.width / 1.41, 72 * ecran.height / 90, ecran.width / 1.13, 79 * ecran.height / 90,al_map_rgb(200, 200, 200)) ;
        al_draw_scaled_bitmap(jeu.classes[KIRBY].sortADisposition[POING].iconeSort, 0, 0, 2000, 2000,
                              109 * ecran.width / 144, ecran.height / 1.125, 67 * ecran.width / 144,
                              67 * ecran.height / 90, 0);
        al_draw_filled_triangle(ecran.width / 1.27, 79 * ecran.height / 90, ecran.width / 1.25, 79 * ecran.height / 90, ecran.width / 1.26 ,80 * ecran.height / 90, al_map_rgb(200, 200, 200)) ;
        al_draw_text(gameFont, al_map_rgb(100, 100, 100), ecran.width / 1.36, 73 * ecran.height / 90,ALLEGRO_ALIGN_CENTER, "POING");
        al_draw_textf(gameFont, al_map_rgb(100, 100, 100), ecran.width / 1.165, 75 * ecran.height / 90,ALLEGRO_ALIGN_CENTER, "%d PV", jeu.classes[KIRBY].sortADisposition[POING].degatsOUsoin);
        al_draw_textf(gameFont, al_map_rgb(100, 100, 100), ecran.width / 1.23, 75 * ecran.height / 90,ALLEGRO_ALIGN_CENTER, "%d PA", jeu.classes[KIRBY].sortADisposition[POING].PA);

    } else {
        al_draw_scaled_bitmap(jeu.classes[KIRBY].sortADisposition[POING].iconeSort, 0, 0, 2000, 2000,
                              109 * ecran.width / 144, ecran.height / 1.125, 43 * ecran.width / 96,
                              43 * ecran.height / 60, 0);
    }

    if ((float) ecran.mouse_x < 427 * ecran.width / 576 && ecran.mouse_x > 409 * ecran.width / 576 &&
        (float) ecran.mouse_y < 353 * ecran.height / 360 && ecran.mouse_y > 9 * ecran.height / 10) {
        al_draw_filled_rectangle(ecran.width / 1.41, 72 * ecran.height / 90, ecran.width / 1.13, 79 * ecran.height / 90,al_map_rgb(200, 200, 200)) ;
        al_draw_scaled_bitmap(jeu.classes[KIRBY].sortADisposition[COUPDEPIED].iconeSort, 0, 0, 2000, 2000,
                              ecran.width / 1.44, 79 * ecran.height / 90, 47 * ecran.width / 96, 47 * ecran.height / 60,
                              0);
        al_draw_text(gameFont, al_map_rgb(100, 100, 100), ecran.width / 1.32, 73 * ecran.height / 90,ALLEGRO_ALIGN_CENTER, "COUP DE PIED");
        al_draw_textf(gameFont, al_map_rgb(100, 100, 100), ecran.width / 1.165, 75 * ecran.height / 90,ALLEGRO_ALIGN_CENTER, "%d PV", jeu.classes[KIRBY].sortADisposition[COUPDEPIED].degatsOUsoin);
        al_draw_textf(gameFont, al_map_rgb(100, 100, 100), ecran.width / 1.23, 75 * ecran.height / 90,ALLEGRO_ALIGN_CENTER, "%d PA", jeu.classes[KIRBY].sortADisposition[COUPDEPIED].PA);
        al_draw_filled_triangle(ecran.width / 1.39, 79 * ecran.height / 90, ecran.width / 1.37, 79 * ecran.height / 90, ecran.width / 1.38 ,80 * ecran.height / 90, al_map_rgb(200, 200, 200)) ;
    } else {
        al_draw_scaled_bitmap(jeu.classes[KIRBY].sortADisposition[COUPDEPIED].iconeSort, 0, 0, 2000, 2000,
                              ecran.width / 1.44, 79 * ecran.height / 90, 17 * ecran.width / 36, 34 * ecran.height / 45,
                              0);
    }

    if ((float) ecran.mouse_x < ecran.width / 1.152 && ecran.mouse_x > 119 * ecran.width / 144 &&
        (float) ecran.mouse_y < 353 * ecran.height / 360 && ecran.mouse_y > 9 * ecran.height / 10) {
        al_draw_filled_rectangle(ecran.width / 1.41, 72 * ecran.height / 90, ecran.width / 1.13, 79 * ecran.height / 90,al_map_rgb(200, 200, 200)) ;

        al_draw_scaled_bitmap(jeu.classes[KIRBY].sortADisposition[FLAMME].iconeSort, 0, 0, 2000, 2000,
                              239 * ecran.width / 288, 319 * ecran.height / 360, 85 * ecran.width / 288,
                              17 * ecran.height / 36, 0);
        al_draw_text(gameFont, al_map_rgb(100, 100, 100), ecran.width / 1.36, 73 * ecran.height / 90,ALLEGRO_ALIGN_CENTER, "FLAMME");
        al_draw_textf(gameFont, al_map_rgb(100, 100, 100), ecran.width / 1.165, 75 * ecran.height / 90,ALLEGRO_ALIGN_CENTER, "%d PV", jeu.classes[KIRBY].sortADisposition[FLAMME].degatsOUsoin);
        al_draw_textf(gameFont, al_map_rgb(100, 100, 100), ecran.width / 1.23, 75 * ecran.height / 90,ALLEGRO_ALIGN_CENTER, "%d PA", jeu.classes[KIRBY].sortADisposition[FLAMME].PA);

        al_draw_filled_triangle(ecran.width / 1.17, 79 * ecran.height / 90, ecran.width / 1.15, 79 * ecran.height / 90, ecran.width / 1.16 ,80 * ecran.height / 90, al_map_rgb(200, 200, 200)) ;

    } else {
        al_draw_scaled_bitmap(jeu.classes[KIRBY].sortADisposition[FLAMME].iconeSort, 0, 0, 2000, 2000,
                              239 * ecran.width / 288, 319 * ecran.height / 360, ecran.width / 3.6, ecran.height / 2.25,
                              0);
    }
}

void drawSortMARIO( ALLEGRO_FONT* gameFont, Jeux jeu, InfoEcran ecran) {
    if ((float) ecran.mouse_x < 119 * ecran.width / 144 && ecran.mouse_x > 73 * ecran.width / 96 &&
        (float) ecran.mouse_y < 59 * ecran.height / 60 && ecran.mouse_y > ecran.height / 1.125) {
        al_draw_filled_rectangle(ecran.width / 1.41, 72 * ecran.height / 90, ecran.width / 1.13, 79 * ecran.height / 90,al_map_rgb(200, 200, 200)) ;
        al_draw_scaled_bitmap(jeu.classes[MARIO].sortADisposition[CORONA].iconeSort, 0, 0, 2000, 2000,
                              73 * ecran.width / 96, 79 * ecran.height / 90, 127 * ecran.width / 288,
                              127 * ecran.height / 180, 0);
        al_draw_text(gameFont, al_map_rgb(100, 100, 100), ecran.width / 1.36, 73 * ecran.height / 90,ALLEGRO_ALIGN_CENTER, "CORONA");
        al_draw_textf(gameFont, al_map_rgb(100, 100, 100), ecran.width / 1.165, 75 * ecran.height / 90,ALLEGRO_ALIGN_CENTER, "%d PV", jeu.classes[MARIO].sortADisposition[CORONA].degatsOUsoin);
        al_draw_textf(gameFont, al_map_rgb(100, 100, 100), ecran.width / 1.23, 75 * ecran.height / 90,ALLEGRO_ALIGN_CENTER, "%d PA", jeu.classes[MARIO].sortADisposition[CORONA].PA);

        al_draw_filled_triangle(ecran.width / 1.27, 79 * ecran.height / 90, ecran.width / 1.25, 79 * ecran.height / 90, ecran.width / 1.26 ,80 * ecran.height / 90, al_map_rgb(200, 200, 200)) ;

    } else {
        al_draw_scaled_bitmap(jeu.classes[MARIO].sortADisposition[CORONA].iconeSort, 0, 0, 2000, 2000,
                              73 * ecran.width / 96, 79 * ecran.height / 90, 61 * ecran.width / 144,
                              61 * ecran.height / 90, 0);
    }
    if ((float) ecran.mouse_x < ecran.width / 1.152 && ecran.mouse_x > 119 * ecran.width / 144 &&
        (float) ecran.mouse_y < 353 * ecran.height / 360 && ecran.mouse_y > 9 * ecran.height / 10) {
        al_draw_filled_rectangle(ecran.width / 1.41, 72 * ecran.height / 90, ecran.width / 1.13, 79 * ecran.height / 90,al_map_rgb(200, 200, 200)) ;
        al_draw_scaled_bitmap(jeu.classes[KIRBY].sortADisposition[FLAMME].iconeSort, 0, 0, 2000, 2000,
                              239 * ecran.width / 288, 319 * ecran.height / 360, 85 * ecran.width / 288,
                              17 * ecran.height / 36, 0);
        al_draw_text(gameFont, al_map_rgb(100, 100, 100), ecran.width / 1.36, 73 * ecran.height / 90,ALLEGRO_ALIGN_CENTER, "FLAMME");
        al_draw_textf(gameFont, al_map_rgb(100, 100, 100), ecran.width / 1.165, 75 * ecran.height / 90,ALLEGRO_ALIGN_CENTER, "%d PV", jeu.classes[MARIO].sortADisposition[FLAMME].degatsOUsoin);
        al_draw_textf(gameFont, al_map_rgb(100, 100, 100), ecran.width / 1.23, 75 * ecran.height / 90,ALLEGRO_ALIGN_CENTER, "%d PA", jeu.classes[MARIO].sortADisposition[FLAMME].PA);
        al_draw_filled_triangle(ecran.width / 1.17, 79 * ecran.height / 90, ecran.width / 1.15, 79 * ecran.height / 90, ecran.width / 1.16 ,80 * ecran.height / 90, al_map_rgb(200, 200, 200)) ;

    } else {
        al_draw_scaled_bitmap(jeu.classes[KIRBY].sortADisposition[FLAMME].iconeSort, 0, 0, 2000, 2000,
                              239 * ecran.width / 288, 319 * ecran.height / 360, ecran.width / 3.6, ecran.height / 2.25,
                              0);
    }

    if ((float) ecran.mouse_x < 427 * ecran.width / 576 && ecran.mouse_x > 409 * ecran.width / 576 &&
        (float) ecran.mouse_y < 353 * ecran.height / 360 && ecran.mouse_y > 9 * ecran.height / 10) {
        al_draw_filled_rectangle(ecran.width / 1.41, 72 * ecran.height / 90, ecran.width / 1.13, 79 * ecran.height / 90,al_map_rgb(200, 200, 200)) ;
        al_draw_scaled_bitmap(jeu.classes[MARIO].sortADisposition[POING2].iconeSort, 0, 0, 2000, 2000,
                              ecran.width / 1.43, 315 * ecran.height / 360,  15*ecran.width/32,
                              20*ecran.height/27, 0);
        al_draw_text(gameFont, al_map_rgb(100, 100, 100), ecran.width / 1.36, 73 * ecran.height / 90,ALLEGRO_ALIGN_CENTER, "POING");
        al_draw_textf(gameFont, al_map_rgb(100, 100, 100), ecran.width / 1.165, 75 * ecran.height / 90,ALLEGRO_ALIGN_CENTER, "%d PV", jeu.classes[MARIO].sortADisposition[POING2].degatsOUsoin);
        al_draw_textf(gameFont, al_map_rgb(100, 100, 100), ecran.width / 1.23, 75 * ecran.height / 90,ALLEGRO_ALIGN_CENTER, "%d PA", jeu.classes[MARIO].sortADisposition[POING2].PA);
        al_draw_filled_triangle(ecran.width / 1.39, 79 * ecran.height / 90, ecran.width / 1.37, 79 * ecran.height / 90, ecran.width / 1.38 ,80 * ecran.height / 90, al_map_rgb(200, 200, 200)) ;
    } else {
        al_draw_scaled_bitmap(jeu.classes[MARIO].sortADisposition[POING2].iconeSort, 0, 0, 2000, 2000,
                              ecran.width / 1.43, 315 * ecran.height / 360, 43 * ecran.width / 96,
                              43 * ecran.height / 60, 0);
    }
}

void drawSortPEACH( ALLEGRO_FONT* gameFont, Jeux jeu, InfoEcran ecran) {
    if ((float) ecran.mouse_x < 235 * ecran.width / 288 && ecran.mouse_x > 73 * ecran.width / 96 &&
        (float) ecran.mouse_y < 59 * ecran.height / 60 && ecran.mouse_y > ecran.height / 1.125) {
        al_draw_filled_rectangle(ecran.width / 1.41, 72 * ecran.height / 90, ecran.width / 1.13, 79 * ecran.height / 90,al_map_rgb(200, 200, 200)) ;
        al_draw_scaled_bitmap(jeu.classes[PEACH].sortADisposition[SORTFLEUR].iconeSort, 0, 0, 2000, 2000,
                              55 * ecran.width / 72, 809 * ecran.height / 900, 29 * ecran.width / 72,
                              29 * ecran.height / 45, 0);
        al_draw_text(gameFont, al_map_rgb(100, 100, 100), ecran.width / 1.36, 73 * ecran.height / 90,ALLEGRO_ALIGN_CENTER, "FLEUR");
        al_draw_textf(gameFont, al_map_rgb(100, 100, 100), ecran.width / 1.165, 75 * ecran.height / 90,ALLEGRO_ALIGN_CENTER, "%d PV", jeu.classes[PEACH].sortADisposition[SORTFLEUR].degatsOUsoin);
        al_draw_textf(gameFont, al_map_rgb(100, 100, 100), ecran.width / 1.23, 75 * ecran.height / 90,ALLEGRO_ALIGN_CENTER, "%d PA", jeu.classes[PEACH].sortADisposition[SORTFLEUR].PA);
        al_draw_filled_triangle(ecran.width / 1.27, 79 * ecran.height / 90, ecran.width / 1.25, 79 * ecran.height / 90, ecran.width / 1.26 ,80 * ecran.height / 90, al_map_rgb(200, 200, 200)) ;
    } else {
        al_draw_scaled_bitmap(jeu.classes[PEACH].sortADisposition[SORTFLEUR].iconeSort, 0, 0, 2000, 2000,
                              55 * ecran.width / 72, 809 * ecran.height / 900, 37 * ecran.width / 96,
                              37 * ecran.height / 60, 0);
    }

    if ((float) ecran.mouse_x < 427 * ecran.width / 576 && ecran.mouse_x > 409 * ecran.width / 576 &&
        (float) ecran.mouse_y < 353 * ecran.height / 360 && ecran.mouse_y > 9 * ecran.height / 10) {
        al_draw_filled_rectangle(ecran.width / 1.41, 72 * ecran.height / 90, ecran.width / 1.13, 79 * ecran.height / 90,al_map_rgb(200, 200, 200)) ;
        al_draw_scaled_bitmap(jeu.classes[PEACH].sortADisposition[COUPDEPIED].iconeSort, 0, 0, 2000, 2000,
                              ecran.width / 1.44, 79 * ecran.height / 90, 47 * ecran.width / 96, 47 * ecran.height / 60,
                              0);
        al_draw_text(gameFont, al_map_rgb(100, 100, 100), ecran.width / 1.32, 73 * ecran.height / 90,ALLEGRO_ALIGN_CENTER, "COUP DE PIED");
        al_draw_textf(gameFont, al_map_rgb(100, 100, 100), ecran.width / 1.165, 75 * ecran.height / 90,ALLEGRO_ALIGN_CENTER, "%d PV", jeu.classes[PEACH].sortADisposition[COUPDEPIED].degatsOUsoin);
        al_draw_textf(gameFont, al_map_rgb(100, 100, 100), ecran.width / 1.23, 75 * ecran.height / 90,ALLEGRO_ALIGN_CENTER, "%d PA", jeu.classes[PEACH].sortADisposition[COUPDEPIED].PA);
        al_draw_filled_triangle(ecran.width / 1.39, 79 * ecran.height / 90, ecran.width / 1.37, 79 * ecran.height / 90, ecran.width / 1.38 ,80 * ecran.height / 90, al_map_rgb(200, 200, 200)) ;

    } else {
        al_draw_scaled_bitmap(jeu.classes[PEACH].sortADisposition[COUPDEPIED].iconeSort, 0, 0, 2000, 2000,
                              ecran.width / 1.44, 79 * ecran.height / 90, 17 * ecran.width / 36, 34 * ecran.height / 45,
                              0);
    }

    if ((float) ecran.mouse_x < 253 * ecran.width / 288 && ecran.mouse_x > 161 * ecran.width / 192 &&
        (float) ecran.mouse_y < 353 * ecran.height / 360 && ecran.mouse_y > 9 * ecran.height / 10) {
        al_draw_filled_rectangle(ecran.width / 1.41, 72 * ecran.height / 90, ecran.width / 1.13, 79 * ecran.height / 90,al_map_rgb(200, 200, 200)) ;
        al_draw_scaled_bitmap(jeu.classes[PEACH].sortADisposition[SORTSOIN].iconeSort, 0, 0, 2000, 2000,
                              159 * ecran.width / 192, 323 * ecran.height / 360, 113 * ecran.width / 288,
                              113 * ecran.height / 180, 0);
        al_draw_text(gameFont, al_map_rgb(100, 100, 100), ecran.width / 1.36, 73 * ecran.height / 90,ALLEGRO_ALIGN_CENTER, "SOIN");
        al_draw_textf(gameFont, al_map_rgb(100, 100, 100), ecran.width / 1.165, 75 * ecran.height / 90,ALLEGRO_ALIGN_CENTER, "%d PV", jeu.classes[PEACH].sortADisposition[SORTSOIN].degatsOUsoin);
        al_draw_textf(gameFont, al_map_rgb(100, 100, 100), ecran.width / 1.23, 75 * ecran.height / 90,ALLEGRO_ALIGN_CENTER, "%d PA", jeu.classes[PEACH].sortADisposition[SORTSOIN].PA);
        al_draw_filled_triangle(ecran.width / 1.17, 79 * ecran.height / 90, ecran.width / 1.15, 79 * ecran.height / 90, ecran.width / 1.16 ,80 * ecran.height / 90, al_map_rgb(200, 200, 200)) ;

    } else {
        al_draw_scaled_bitmap(jeu.classes[PEACH].sortADisposition[SORTSOIN].iconeSort, 0, 0, 2000, 2000,
                              159 * ecran.width / 192, 323 * ecran.height / 360, 3 * ecran.width / 8,
                              3 * ecran.height / 5, 0);
    }
}

void drawSortPACMAN( ALLEGRO_FONT* gameFont, Jeux jeu, InfoEcran ecran) {
    if ((float) ecran.mouse_x < 235 * ecran.width / 288 && ecran.mouse_x > 73 * ecran.width / 96 &&
        (float) ecran.mouse_y < 59 * ecran.height / 60 && ecran.mouse_y > ecran.height / 1.125) {
        al_draw_filled_rectangle(ecran.width / 1.41, 72 * ecran.height / 90, ecran.width / 1.13, 79 * ecran.height / 90,al_map_rgb(200, 200, 200)) ;
        al_draw_scaled_bitmap(jeu.classes[PACMAN].sortADisposition[RECULERADVERSAIRE].iconeSort, 0, 0, 2000, 2000,
                              109 * ecran.width / 144, ecran.height / 1.125, 67 * ecran.width / 144,
                              67 * ecran.height / 90, 0);
        al_draw_filled_triangle(ecran.width / 1.27, 79 * ecran.height / 90, ecran.width / 1.25, 79 * ecran.height / 90, ecran.width / 1.26 ,80 * ecran.height / 90, al_map_rgb(200, 200, 200)) ;

        al_draw_text(gameFont, al_map_rgb(100, 100, 100), ecran.width / 1.35, 73 * ecran.height / 90,ALLEGRO_ALIGN_CENTER, "POUSSER");
        al_draw_textf(gameFont, al_map_rgb(100, 100, 100), ecran.width / 1.165, 75 * ecran.height / 90,ALLEGRO_ALIGN_CENTER, "%d PV", jeu.classes[PACMAN].sortADisposition[RECULERADVERSAIRE].degatsOUsoin);
        al_draw_textf(gameFont, al_map_rgb(100, 100, 100), ecran.width / 1.23, 75 * ecran.height / 90,ALLEGRO_ALIGN_CENTER, "%d PA", jeu.classes[PACMAN].sortADisposition[RECULERADVERSAIRE].PA);
    } else {
        al_draw_scaled_bitmap(jeu.classes[PACMAN].sortADisposition[RECULERADVERSAIRE].iconeSort, 0, 0, 2000, 2000,
                              109 * ecran.width / 144, ecran.height / 1.125, 43 * ecran.width / 96,
                              43 * ecran.height / 60, 0);
    }

    if ((float) ecran.mouse_x < 427 * ecran.width / 576 && ecran.mouse_x > 409 * ecran.width / 576 &&(float) ecran.mouse_y < 353 * ecran.height / 360 && ecran.mouse_y > 9 * ecran.height / 10) {
        al_draw_filled_rectangle(ecran.width / 1.41, 72 * ecran.height / 90, ecran.width / 1.13, 79 * ecran.height / 90,al_map_rgb(200, 200, 200)) ;
        al_draw_scaled_bitmap(jeu.classes[PACMAN].sortADisposition[SORTDEFENCE].iconeSort, 0, 0, 2000, 2000,ecran.width / 1.44, 79 * ecran.height / 90, 15 * ecran.width / 32, 3 * ecran.height / 4,0);

        al_draw_text(gameFont, al_map_rgb(100, 100, 100), ecran.width / 1.35, 73 * ecran.height / 90,ALLEGRO_ALIGN_CENTER, "IMMUNITE");
        al_draw_textf(gameFont, al_map_rgb(100, 100, 100), ecran.width / 1.165, 75 * ecran.height / 90,ALLEGRO_ALIGN_CENTER, "%d PV", jeu.classes[PACMAN].sortADisposition[SORTDEFENCE].degatsOUsoin);
        al_draw_textf(gameFont, al_map_rgb(100, 100, 100), ecran.width / 1.23, 75 * ecran.height / 90,ALLEGRO_ALIGN_CENTER, "%d PA", jeu.classes[PACMAN].sortADisposition[SORTDEFENCE].PA);
        al_draw_filled_triangle(ecran.width / 1.39, 79 * ecran.height / 90, ecran.width / 1.37, 79 * ecran.height / 90, ecran.width / 1.38 ,80 * ecran.height / 90, al_map_rgb(200, 200, 200)) ;
    } else {
        al_draw_scaled_bitmap(jeu.classes[PACMAN].sortADisposition[SORTDEFENCE].iconeSort, 0, 0, 2000, 2000,
                              ecran.width / 1.44, 79 * ecran.height / 90, 65 * ecran.width / 144,
                              13 * ecran.height / 18, 0);
    }

    if ((float) ecran.mouse_x < ecran.width / 1.152 && ecran.mouse_x > 119 * ecran.width / 144 &&
        (float) ecran.mouse_y < 353 * ecran.height / 360 && ecran.mouse_y > 9 * ecran.height / 10) {
        al_draw_filled_rectangle(ecran.width / 1.41, 72 * ecran.height / 90, ecran.width / 1.13, 79 * ecran.height / 90,al_map_rgb(200, 200, 200)) ;
        al_draw_scaled_bitmap(jeu.classes[PACMAN].sortADisposition[FLAMME].iconeSort, 0, 0, 2000, 2000,
                              239 * ecran.width / 288, 319 * ecran.height / 360, 85 * ecran.width / 288,
                              17 * ecran.height / 36, 0);
        al_draw_text(gameFont, al_map_rgb(100, 100, 100), ecran.width / 1.36, 73 * ecran.height / 90,ALLEGRO_ALIGN_CENTER, "FLAMME");
        al_draw_textf(gameFont, al_map_rgb(100, 100, 100), ecran.width / 1.165, 75 * ecran.height / 90,ALLEGRO_ALIGN_CENTER, "%d PV", jeu.classes[PACMAN].sortADisposition[FLAMME].degatsOUsoin);
        al_draw_textf(gameFont, al_map_rgb(100, 100, 100), ecran.width / 1.23, 75 * ecran.height / 90,ALLEGRO_ALIGN_CENTER, "%d PA", jeu.classes[PACMAN].sortADisposition[FLAMME].PA);
        al_draw_filled_triangle(ecran.width / 1.17, 79 * ecran.height / 90, ecran.width / 1.15, 79 * ecran.height / 90, ecran.width / 1.16 ,80 * ecran.height / 90, al_map_rgb(200, 200, 200)) ;

    } else {
        al_draw_scaled_bitmap(jeu.classes[PACMAN].sortADisposition[FLAMME].iconeSort, 0, 0, 2000, 2000,
                              239 * ecran.width / 288, 319 * ecran.height / 360, ecran.width / 3.6, ecran.height / 2.25,
                              0);
    }
}

void drawSortDONKEYKONG(ALLEGRO_FONT* gameFont, Jeux jeu, InfoEcran ecran) {
    if ((float) ecran.mouse_x < 235 * ecran.width / 288 && ecran.mouse_x > 73 * ecran.width / 96 &&
        (float) ecran.mouse_y < 59 * ecran.height / 60 && ecran.mouse_y > ecran.height / 1.125) {
        al_draw_filled_rectangle(ecran.width / 1.41, 72 * ecran.height / 90, ecran.width / 1.13, 79 * ecran.height / 90,al_map_rgb(200, 200, 200)) ;
        al_draw_scaled_bitmap(jeu.classes[DONKEY_KONG].sortADisposition[MORTEL].iconeSort, 0, 0, 2000, 2000,
                              242 * ecran.width / 320, 53 * ecran.height / 60, 131 * ecran.width / 288,
                              131 * ecran.height / 180, 0);
        al_draw_text(gameFont, al_map_rgb(100, 100, 100), ecran.width / 1.36, 73 * ecran.height / 90,ALLEGRO_ALIGN_CENTER, "MORTEL");
        al_draw_textf(gameFont, al_map_rgb(100, 100, 100), ecran.width / 1.165, 75 * ecran.height / 90,ALLEGRO_ALIGN_CENTER, "%d PV", jeu.classes[DONKEY_KONG].sortADisposition[MORTEL].degatsOUsoin);
        al_draw_textf(gameFont, al_map_rgb(100, 100, 100), ecran.width / 1.23, 75 * ecran.height / 90,ALLEGRO_ALIGN_CENTER, "%d PA", jeu.classes[DONKEY_KONG].sortADisposition[MORTEL].PA);
        al_draw_filled_triangle(ecran.width / 1.27, 79 * ecran.height / 90, ecran.width / 1.25, 79 * ecran.height / 90, ecran.width / 1.26 ,80 * ecran.height / 90, al_map_rgb(200, 200, 200)) ;

    } else {
        al_draw_scaled_bitmap(jeu.classes[DONKEY_KONG].sortADisposition[MORTEL].iconeSort, 0, 0, 2000, 2000,
                              242 * ecran.width / 320, 53 * ecran.height / 60, 127 * ecran.width / 288,
                              127 * ecran.height / 180, 0);
    }

    if ((float) ecran.mouse_x < 427 * ecran.width / 576 && ecran.mouse_x > 409 * ecran.width / 576 &&
        (float) ecran.mouse_y < 353 * ecran.height / 360 && ecran.mouse_y > 9 * ecran.height / 10) {
        al_draw_filled_rectangle(ecran.width / 1.41, 72 * ecran.height / 90, ecran.width / 1.13, 79 * ecran.height / 90,al_map_rgb(200, 200, 200)) ;
        al_draw_scaled_bitmap(jeu.classes[DONKEY_KONG].sortADisposition[POINGGANT].iconeSort, 0, 0, 2000, 2000,
                              ecran.width / 1.44, ecran.height / 1.125, 15 * ecran.width / 32, 3 * ecran.height / 4, 0);
        al_draw_text(gameFont, al_map_rgb(100, 100, 100), ecran.width / 1.34, 73 * ecran.height / 90,ALLEGRO_ALIGN_CENTER, "POING GANT");
        al_draw_textf(gameFont, al_map_rgb(100, 100, 100), ecran.width / 1.165, 75 * ecran.height / 90,ALLEGRO_ALIGN_CENTER, "%d PV", jeu.classes[DONKEY_KONG].sortADisposition[POINGGANT].degatsOUsoin);
        al_draw_textf(gameFont, al_map_rgb(100, 100, 100), ecran.width / 1.23, 75 * ecran.height / 90,ALLEGRO_ALIGN_CENTER, "%d PA", jeu.classes[DONKEY_KONG].sortADisposition[POINGGANT].PA);

        al_draw_filled_triangle(ecran.width / 1.39, 79 * ecran.height / 90, ecran.width / 1.37, 79 * ecran.height / 90, ecran.width / 1.38 ,80 * ecran.height / 90, al_map_rgb(200, 200, 200)) ;

    } else {
        al_draw_scaled_bitmap(jeu.classes[DONKEY_KONG].sortADisposition[POINGGANT].iconeSort, 0, 0, 2000, 2000,
                              ecran.width / 1.44, ecran.height / 1.125, 65 * ecran.width / 144, 13 * ecran.height / 18,
                              0);
    }

    if ((float) ecran.mouse_x < 85 * ecran.width / 96 && ecran.mouse_x > 799 * ecran.width / 960 &&
        (float) ecran.mouse_y < 353 * ecran.height / 360 && ecran.mouse_y > 9 * ecran.height / 10) {
        al_draw_filled_rectangle(ecran.width / 1.41, 72 * ecran.height / 90, ecran.width / 1.13, 79 * ecran.height / 90,al_map_rgb(200, 200, 200)) ;
        al_draw_scaled_bitmap(jeu.classes[DONKEY_KONG].sortADisposition[SAUT].iconeSort, 0, 0, 2000, 2000,
                              ecran.width / 1.21, 7 * ecran.height / 8, 139 * ecran.width / 288,
                              139 * ecran.height / 180, 0);
        al_draw_filled_triangle(ecran.width / 1.17, 79 * ecran.height / 90, ecran.width / 1.15, 79 * ecran.height / 90, ecran.width / 1.16 ,80 * ecran.height / 90, al_map_rgb(200, 200, 200)) ;

        al_draw_text(gameFont, al_map_rgb(100, 100, 100), ecran.width / 1.36, 73 * ecran.height / 90,ALLEGRO_ALIGN_CENTER, "SAUT");
        al_draw_textf(gameFont, al_map_rgb(100, 100, 100), ecran.width / 1.165, 75 * ecran.height / 90,ALLEGRO_ALIGN_CENTER, "%d PV", jeu.classes[DONKEY_KONG].sortADisposition[SAUT].degatsOUsoin);
        al_draw_textf(gameFont, al_map_rgb(100, 100, 100), ecran.width / 1.23, 75 * ecran.height / 90,ALLEGRO_ALIGN_CENTER, "%d PA", jeu.classes[DONKEY_KONG].sortADisposition[SAUT].PA);

    } else {
        al_draw_scaled_bitmap(jeu.classes[DONKEY_KONG].sortADisposition[SAUT].iconeSort, 0, 0, 2000, 2000,
                              ecran.width / 1.21, 7 * ecran.height / 8, 67 * ecran.width / 144, 67 * ecran.height / 90,
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
            drawSortKIRBY(smallameFont, jeu, ecran);
            break;
        case PACMAN :
            drawSortPACMAN(smallameFont, jeu, ecran);
            break;
        case MARIO :
            drawSortMARIO(smallameFont, jeu, ecran);
            break;
        case DONKEY_KONG :
            drawSortDONKEYKONG(smallameFont, jeu, ecran);
            break;
        case PEACH :
            drawSortPEACH(smallameFont, jeu, ecran);
            break;
    }
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
}

void appuyerSortSurMap(Jeux* jeu, Map map[30][30], Timer* timerJeu2) {
    if(verifierPorteeLigne(*jeu, jeu->joueur[jeu->info.joueurQuiJoue].sortAppuye) && jeu->joueur[jeu->info.joueurQuiJoue].sortAppuye != 3 && jeu->joueur[jeu->info.joueurQuiJoue].quelAnimation == RESPIRATION) {
        appliquerSort(jeu, jeu->info.joueurQuiJoue, map, timerJeu2) ;
    }
}

void appliquerSort(Jeux* jeu, int joueurQuiJoue, Map map[30][30], Timer* timerJeu2) {
    int quelJoueurSurLaCase = map[jeu->info.collisionSourisMap[0][0]][jeu->info.collisionSourisMap[1][0]].joueurPresentDessus;
    if (jeu->joueur[quelJoueurSurLaCase - 1].sortSpecial != 1 && jeu->joueur[joueurQuiJoue].quelAnimation == RESPIRATION) {
        switch (jeu->joueur[joueurQuiJoue].sortAppuye) {
            case 0 : {
                if (jeu->joueur[joueurQuiJoue].PA >= jeu->classes[jeu->joueur[joueurQuiJoue].classe].sortADisposition[0].PA) {
                    timerJeu2->startTimer = 1 ;
                    timerJeu2->joueurAttaque = quelJoueurSurLaCase - 1 ;
                    if (jeu->joueur[joueurQuiJoue].classe == KIRBY) {
                        if (quelJoueurSurLaCase != joueurQuiJoue + 1) {
                            jeu->joueur[quelJoueurSurLaCase - 1].PV -= jeu->classes[jeu->joueur[joueurQuiJoue].classe].sortADisposition[0].degatsOUsoin;
                            jeu->joueur[joueurQuiJoue].PA -= jeu->classes[jeu->joueur[joueurQuiJoue].classe].sortADisposition[0].PA;
                        }
                        jeu->joueur[joueurQuiJoue].quelAnimation = ATTAQUE1;
                    }
                    else if (jeu->joueur[joueurQuiJoue].classe == PACMAN) {
                        jeu->joueur[joueurQuiJoue].sortSpecial = 1;
                        jeu->joueur[joueurQuiJoue].PA -= jeu->classes[PACMAN].sortADisposition[0].PA;
                    }
                    else {
                        if (quelJoueurSurLaCase != joueurQuiJoue + 1) {
                            jeu->joueur[quelJoueurSurLaCase - 1].PV -= jeu->classes[jeu->joueur[joueurQuiJoue].classe].sortADisposition[0].degatsOUsoin;
                            jeu->joueur[joueurQuiJoue].PA -= jeu->classes[jeu->joueur[joueurQuiJoue].classe].sortADisposition[0].PA;
                        }
                        //animation
                        jeu->joueur[joueurQuiJoue].quelAnimation = ATTAQUE1;
                    }
                }
                break;
            }
            case 1 : {
                if (jeu->joueur[joueurQuiJoue].PA >= jeu->classes[jeu->joueur[joueurQuiJoue].classe].sortADisposition[1].PA) {
                    timerJeu2->startTimer = 1 ;
                    timerJeu2->joueurAttaque = quelJoueurSurLaCase - 1 ;
                    if (jeu->joueur[joueurQuiJoue].classe == PACMAN) {
                        ///RECULERADVERSAIRE
                        jeu->joueur[quelJoueurSurLaCase - 1].PV -= jeu->classes[jeu->joueur[joueurQuiJoue].classe].sortADisposition[1].degatsOUsoin;
                        jeu->joueur[joueurQuiJoue].PA -= jeu->classes[jeu->joueur[joueurQuiJoue].classe].sortADisposition[1].PA;

                    } else {
                        if (quelJoueurSurLaCase != joueurQuiJoue + 1) {
                            jeu->joueur[quelJoueurSurLaCase - 1].PV -= jeu->classes[jeu->joueur[joueurQuiJoue].classe].sortADisposition[1].degatsOUsoin;
                            jeu->joueur[joueurQuiJoue].PA -= jeu->classes[jeu->joueur[joueurQuiJoue].classe].sortADisposition[1].PA;
                        }
                    }
                    jeu->joueur[joueurQuiJoue].quelAnimation = ATTAQUE2;
                }
                break;
            }
            case 2 : {
                if (jeu->joueur[joueurQuiJoue].PA >=
                    jeu->classes[jeu->joueur[joueurQuiJoue].classe].sortADisposition[2].PA) {
                    timerJeu2->startTimer = 1 ;
                    timerJeu2->joueurAttaque = quelJoueurSurLaCase - 1 ;
                    if (jeu->joueur[joueurQuiJoue].classe == DONKEY_KONG) {
                        ///SAUT
                        if (map[jeu->info.collisionSourisMap[0][0]][jeu->info.collisionSourisMap[1][0]].obstacle != 1) {
                            jeu->joueur[joueurQuiJoue].caseXDepart = jeu->joueur[joueurQuiJoue].caseX;
                            jeu->joueur[joueurQuiJoue].caseYDepart = jeu->joueur[joueurQuiJoue].caseY;
                            jeu->joueur[joueurQuiJoue].dep = 1;
                            map[jeu->joueur[joueurQuiJoue].caseX][jeu->joueur[joueurQuiJoue].caseY].joueurPresentDessus = 0;
                            map[jeu->info.collisionSourisMap[0][0]][jeu->info.collisionSourisMap[0][1]].joueurPresentDessus = joueurQuiJoue + 1;
                            jeu->joueur[joueurQuiJoue].quelAnimation = ATTAQUE3;
                            jeu->joueur[joueurQuiJoue].xArrive = jeu->info.collisionSourisMap[0][0];
                            jeu->joueur[joueurQuiJoue].yArrive = jeu->info.collisionSourisMap[0][1];
                            jeu->joueur[joueurQuiJoue].actif = 1;
                            //jeu->joueur[joueurQuiJoue].PM = 0 ;
                            jeu->joueur[joueurQuiJoue].PA -= jeu->classes[jeu->joueur[joueurQuiJoue].classe].sortADisposition[2].PA;
                        }
                    }
                    else {
                        if (jeu->joueur[joueurQuiJoue].classe == PEACH) {
                            if (jeu->joueur[joueurQuiJoue].PV + jeu->classes[jeu->joueur[joueurQuiJoue].classe].sortADisposition[2].degatsOUsoin < 300) {
                                jeu->joueur[joueurQuiJoue].PV += jeu->classes[jeu->joueur[joueurQuiJoue].classe].sortADisposition[2].degatsOUsoin;
                            }
                            else jeu->joueur[joueurQuiJoue].PV = 300;
                        } else {
                            if (quelJoueurSurLaCase != joueurQuiJoue + 1) {
                                jeu->joueur[quelJoueurSurLaCase - 1].PV -= jeu->classes[jeu->joueur[joueurQuiJoue].classe].sortADisposition[2].degatsOUsoin;
                            }
                        }
                        jeu->joueur[joueurQuiJoue].PA -= jeu->classes[jeu->joueur[joueurQuiJoue].classe].sortADisposition[2].PA;
                        jeu->joueur[joueurQuiJoue].quelAnimation = ATTAQUE3;
                    }
                }
            }
                break;
        }
    }
    else if(joueurQuiJoue != quelJoueurSurLaCase - 1){
        jeu->joueur[quelJoueurSurLaCase - 1].sortSpecial = 0;
        jeu->joueur[joueurQuiJoue].PA -= jeu->classes[jeu->joueur[joueurQuiJoue].classe].sortADisposition[jeu->joueur[joueurQuiJoue].sortAppuye].PA;
    }
    if(quelJoueurSurLaCase != 0 && jeu->joueur[quelJoueurSurLaCase-1].PV <= 0) {
        jeu->joueur[quelJoueurSurLaCase-1].etat = 1 ;
        jeu->info.nbJoueurMort ++ ;
        map[jeu->joueur[quelJoueurSurLaCase-1].caseX][jeu->joueur[quelJoueurSurLaCase-1].caseY].joueurPresentDessus = 0 ;
        timerJeu2->startTimer = 1 ;
        timerJeu2->joueurAttaque = quelJoueurSurLaCase - 1 ;
    }
    jeu->info.compteur = 0 ;

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