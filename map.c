#include "map.h"

bool collisionCercle(int x,int y,Map map[20][20],int i,int j,double width){
    int d2 = (x-map[i][j].x)*(x-map[i][j].x) + (y- map[i][j].y)*(y-map[i][j].y);
    if (d2>(width/60*width/60))
        return false;
    else
        return true;
}

void drawPlay(Joueurs *joueur,Map map[20][20],int mouse_x,int mouse_y,double width, double height, double scalex, double scaley, ALLEGRO_DISPLAY *display,ALLEGRO_COLOR white, ALLEGRO_COLOR black, ALLEGRO_COLOR gris,ALLEGRO_COLOR vert,ALLEGRO_COLOR red) {
    caseJoueur(joueur,map);
    for (int j=0;j<mapY;j++) {
        for (int i = 0; i < mapX; i++) {


            al_draw_filled_triangle(map[i][j].x - scalex, map[i][j].y, map[i][j].x, map[i][j].y + scaley, map[i][j].x, map[i][j].y -
                                                                                                                       scaley, white);
            al_draw_filled_triangle(map[i][j].x + scalex, map[i][j].y, map[i][j].x, map[i][j].y + scaley, map[i][j].x, map[i][j].y -
            scaley, white);
        }
    }


    for (int j=0;j<mapY;j++) {
        for (int i = 0; i < mapX; i++) {
            if(collisionCercle(mouse_x, mouse_y, map, i, j,width) == true ){
                al_draw_filled_triangle(map[i][j].x - scalex, map[i][j].y, map[i][j].x, map[i][j].y + scaley, map[i][j].x, map[i][j].y -
                                                                                                                           scaley, black);
                al_draw_filled_triangle(map[i][j].x + scalex, map[i][j].y, map[i][j].x, map[i][j].y + scaley, map[i][j].x, map[i][j].y -
                                                                                                                           scaley, black);

                if(map[0][0].t == 1 && joueur[0].dep == 0){

                    joueur[0].caseXDepart= joueur[0].caseX;
                    joueur[0].caseYDepart= joueur[0].caseY;
                    joueur[0].dep=1;
                    joueur[0].xArrive=i;
                    joueur[0].yArrive=j;
                    joueur[0].actif=1;
                    al_draw_filled_triangle(map[i][j].x - scalex, map[i][j].y, map[i][j].x, map[i][j].y + scaley, map[i][j].x, map[i][j].y -
                                                                                                                               scaley, red);
                    al_draw_filled_triangle(map[i][j].x + scalex, map[i][j].y, map[i][j].x, map[i][j].y + scaley, map[i][j].x, map[i][j].y -
                                                                                                                               scaley, red);
                }
                if (joueur[0].dep == 0){
                    joueur[0].xArrive=i;
                    joueur[0].yArrive=j;
                }

            }

        }
    }
}

void caseJoueur(Joueurs *joueur,Map map[20][20]){
    for (int j=0;j<mapY;j++) {
        for (int i = 0; i < mapX; i++) {
            if (joueur[0].x>map[i][j].x-1 && joueur[0].x<map[i][j].x+1 && joueur[0].y>map[i][j].y-1 && joueur[0].y<map[i][j].y+1 ){
                joueur[0].caseX=i;
                joueur[0].caseY=j;
                printf(" t : %d\n",map[0][0].t);
                //printf(" CaseXa: %d , CaseYa: %d\n",joueur[0].caseXDepart,joueur[0].caseYDepart);
            }
        }
    }
}

void deplacementJoueur(Joueurs *joueur, Map map[20][20],double scalex,double scaley){
    ALLEGRO_COLOR vert = al_map_rgba(93, 127, 51, 255);
    ALLEGRO_COLOR vert2 = al_map_rgba(93, 127, 51, 150);
    double depX=0;
    double depY=0;

    caseJoueur(joueur,map);

    if (joueur[0].dep==0) {
        for (int j=0;j<4;j++) {
            for (int i = 0; i < 4; i++) {
                if (i+ j <=3 ){
                    al_draw_filled_triangle(map[joueur[0].caseXDepart + i][joueur[0].caseYDepart + j].x - scalex,
                                            map[joueur[0].caseXDepart + i][joueur[0].caseYDepart + j].y,
                                            map[joueur[0].caseXDepart + i][joueur[0].caseYDepart + j].x,
                                            map[joueur[0].caseXDepart + i][joueur[0].caseYDepart + j].y + scaley,
                                            map[joueur[0].caseXDepart + i][joueur[0].caseYDepart + j].x,
                                            map[joueur[0].caseXDepart + i][joueur[0].caseYDepart + j].y -
                                            scaley, vert2);
                    al_draw_filled_triangle(map[joueur[0].caseXDepart + i][joueur[0].caseYDepart + j].x + scalex,
                                            map[joueur[0].caseXDepart + i][joueur[0].caseYDepart + j].y,
                                            map[joueur[0].caseXDepart + i][joueur[0].caseYDepart + j].x,
                                            map[joueur[0].caseXDepart + i][joueur[0].caseYDepart + j].y + scaley,
                                            map[joueur[0].caseXDepart + i][joueur[0].caseYDepart + j].x,
                                            map[joueur[0].caseXDepart + i][joueur[0].caseYDepart + j].y -
                                            scaley, vert2);

                    al_draw_filled_triangle(map[joueur[0].caseXDepart - i][joueur[0].caseYDepart - j].x - scalex,
                                            map[joueur[0].caseXDepart - i][joueur[0].caseYDepart - j].y,
                                            map[joueur[0].caseXDepart - i][joueur[0].caseYDepart - j].x,
                                            map[joueur[0].caseXDepart - i][joueur[0].caseYDepart - j].y + scaley,
                                            map[joueur[0].caseXDepart - i][joueur[0].caseYDepart - j].x,
                                            map[joueur[0].caseXDepart - i][joueur[0].caseYDepart - j].y -
                                            scaley, vert2);
                    al_draw_filled_triangle(map[joueur[0].caseXDepart - i][joueur[0].caseYDepart - j].x + scalex,
                                            map[joueur[0].caseXDepart - i][joueur[0].caseYDepart - j].y,
                                            map[joueur[0].caseXDepart - i][joueur[0].caseYDepart - j].x,
                                            map[joueur[0].caseXDepart - i][joueur[0].caseYDepart - j].y + scaley,
                                            map[joueur[0].caseXDepart - i][joueur[0].caseYDepart - j].x,
                                            map[joueur[0].caseXDepart - i][joueur[0].caseYDepart - j].y -
                                            scaley, vert2);

                    al_draw_filled_triangle(map[joueur[0].caseXDepart + i][joueur[0].caseYDepart - j].x - scalex,
                                            map[joueur[0].caseXDepart + i][joueur[0].caseYDepart - j].y,
                                            map[joueur[0].caseXDepart + i][joueur[0].caseYDepart - j].x,
                                            map[joueur[0].caseXDepart + i][joueur[0].caseYDepart - j].y + scaley,
                                            map[joueur[0].caseXDepart + i][joueur[0].caseYDepart - j].x,
                                            map[joueur[0].caseXDepart + i][joueur[0].caseYDepart - j].y -
                                            scaley, vert2);
                    al_draw_filled_triangle(map[joueur[0].caseXDepart + i][joueur[0].caseYDepart - j].x + scalex,
                                            map[joueur[0].caseXDepart + i][joueur[0].caseYDepart - j].y,
                                            map[joueur[0].caseXDepart + i][joueur[0].caseYDepart - j].x,
                                            map[joueur[0].caseXDepart + i][joueur[0].caseYDepart - j].y + scaley,
                                            map[joueur[0].caseXDepart + i][joueur[0].caseYDepart - j].x,
                                            map[joueur[0].caseXDepart + i][joueur[0].caseYDepart - j].y -
                                            scaley, vert2);
                    al_draw_filled_triangle(map[joueur[0].caseXDepart - i][joueur[0].caseYDepart + j].x - scalex,
                                            map[joueur[0].caseXDepart - i][joueur[0].caseYDepart + j].y,
                                            map[joueur[0].caseXDepart - i][joueur[0].caseYDepart + j].x,
                                            map[joueur[0].caseXDepart - i][joueur[0].caseYDepart + j].y + scaley,
                                            map[joueur[0].caseXDepart - i][joueur[0].caseYDepart + j].x,
                                            map[joueur[0].caseXDepart - i][joueur[0].caseYDepart + j].y -
                                            scaley, vert2);
                    al_draw_filled_triangle(map[joueur[0].caseXDepart - i][joueur[0].caseYDepart + j].x + scalex,
                                            map[joueur[0].caseXDepart - i][joueur[0].caseYDepart + j].y,
                                            map[joueur[0].caseXDepart - i][joueur[0].caseYDepart + j].x,
                                            map[joueur[0].caseXDepart - i][joueur[0].caseYDepart + j].y + scaley,
                                            map[joueur[0].caseXDepart - i][joueur[0].caseYDepart + j].x,
                                            map[joueur[0].caseXDepart - i][joueur[0].caseYDepart + j].y -
                                            scaley, vert2);
                }
            }
        }

    if ( abs(joueur[0].xArrive-joueur[0].caseXDepart)+abs(joueur[0].yArrive-joueur[0].caseYDepart)<=4 ){
        if (joueur[0].caseX>joueur[0].xArrive){
            // Boucle sur x
            for (int i =0; i < -joueur[0].xArrive + joueur[0].caseXDepart; i++) {
                al_draw_filled_triangle(map[joueur[0].caseXDepart - i][joueur[0].yArrive].x - scalex,
                                        map[joueur[0].caseXDepart - i][joueur[0].yArrive].y,
                                        map[joueur[0].caseXDepart - i][joueur[0].yArrive].x,
                                        map[joueur[0].caseXDepart - i][joueur[0].yArrive].y + scaley,
                                        map[joueur[0].caseXDepart - i][joueur[0].yArrive].x,
                                        map[joueur[0].caseXDepart - i][joueur[0].yArrive].y -
                                        scaley, vert);
                al_draw_filled_triangle(map[joueur[0].caseXDepart - i][joueur[0].yArrive].x + scalex,
                                        map[joueur[0].caseXDepart - i][joueur[0].yArrive].y,
                                        map[joueur[0].caseXDepart - i][joueur[0].yArrive].x,
                                        map[joueur[0].caseXDepart - i][joueur[0].yArrive].y + scaley,
                                        map[joueur[0].caseXDepart - i][joueur[0].yArrive].x,
                                        map[joueur[0].caseXDepart - i][joueur[0].yArrive].y -
                                        scaley, vert);

            }
        }
        if (joueur[0].caseY>joueur[0].yArrive) {
            // Boucle sur y
            for (int j = 0; j < -joueur[0].yArrive + joueur[0].caseYDepart; j++) {

                al_draw_filled_triangle(map[joueur[0].caseXDepart][joueur[0].caseYDepart - j].x - scalex,
                                        map[joueur[0].caseXDepart][joueur[0].caseYDepart - j].y,
                                        map[joueur[0].caseXDepart][joueur[0].caseYDepart - j].x,
                                        map[joueur[0].caseXDepart][joueur[0].caseYDepart - j].y + scaley,
                                        map[joueur[0].caseXDepart][joueur[0].caseYDepart - j].x,
                                        map[joueur[0].caseXDepart][joueur[0].caseYDepart - j].y -
                                        scaley, vert);
                al_draw_filled_triangle(map[joueur[0].caseXDepart][joueur[0].caseYDepart - j].x + scalex,
                                        map[joueur[0].caseXDepart][joueur[0].caseYDepart - j].y,
                                        map[joueur[0].caseXDepart][joueur[0].caseYDepart - j].x,
                                        map[joueur[0].caseXDepart][joueur[0].caseYDepart - j].y + scaley,
                                        map[joueur[0].caseXDepart][joueur[0].caseYDepart - j].x,
                                        map[joueur[0].caseXDepart][joueur[0].caseYDepart - j].y -
                                        scaley, vert);


            }
        }

        if (joueur[0].caseY<joueur[0].yArrive){
            // Boucle sur y
            for (int j = 0; j < joueur[0].yArrive-joueur[0].caseYDepart; j++) {

                al_draw_filled_triangle(map[joueur[0].caseX][joueur[0].caseY + j].x - scalex,
                                        map[joueur[0].caseX][joueur[0].caseY + j].y,
                                        map[joueur[0].caseX][joueur[0].caseY + j].x,
                                        map[joueur[0].caseX][joueur[0].caseY + j].y + scaley,
                                        map[joueur[0].caseX][joueur[0].caseY + j].x,
                                        map[joueur[0].caseX][joueur[0].caseY + j].y -
                                        scaley, vert);
                al_draw_filled_triangle(map[joueur[0].caseX][joueur[0].caseY + j].x + scalex,
                                        map[joueur[0].caseX][joueur[0].caseY + j].y,
                                        map[joueur[0].caseX][joueur[0].caseY + j].x,
                                        map[joueur[0].caseX][joueur[0].caseY + j].y + scaley,
                                        map[joueur[0].caseX][joueur[0].caseY + j].x,
                                        map[joueur[0].caseX][joueur[0].caseY + j].y -
                                        scaley, vert);


            }
        }

        if (joueur[0].caseX==joueur[0].xArrive && joueur[0].caseY==joueur[0].yArrive){
            al_draw_filled_triangle(map[joueur[0].caseX][joueur[0].caseY].x - scalex,
                                    map[joueur[0].caseX][joueur[0].caseY].y,
                                    map[joueur[0].caseX][joueur[0].caseY].x,
                                    map[joueur[0].caseX][joueur[0].caseY].y + scaley,
                                    map[joueur[0].caseX][joueur[0].caseY].x,
                                    map[joueur[0].caseX][joueur[0].caseY].y -
                                    scaley, vert);
            al_draw_filled_triangle(map[joueur[0].caseX][joueur[0].caseY].x + scalex,
                                    map[joueur[0].caseX][joueur[0].caseY].y,
                                    map[joueur[0].caseX][joueur[0].caseY].x,
                                    map[joueur[0].caseX][joueur[0].caseY].y + scaley,
                                    map[joueur[0].caseX][joueur[0].caseY].x,
                                    map[joueur[0].caseX][joueur[0].caseY].y -
                                    scaley, vert);

        }

        if (joueur[0].caseX<joueur[0].xArrive){
            // Boucle sur x
            for (int i = 0; i < joueur[0].xArrive-joueur[0].caseXDepart ; i++) {
                al_draw_filled_triangle(map[joueur[0].caseXDepart + i][joueur[0].yArrive].x - scalex,
                                        map[joueur[0].caseXDepart + i][joueur[0].yArrive].y,
                                        map[joueur[0].caseXDepart + i][joueur[0].yArrive].x,
                                        map[joueur[0].caseXDepart + i][joueur[0].yArrive].y + scaley,
                                        map[joueur[0].caseXDepart + i][joueur[0].yArrive].x,
                                        map[joueur[0].caseXDepart + i][joueur[0].yArrive].y -
                                        scaley, vert);
                al_draw_filled_triangle(map[joueur[0].caseXDepart + i][joueur[0].yArrive].x + scalex,
                                        map[joueur[0].caseXDepart + i][joueur[0].yArrive].y,
                                        map[joueur[0].caseXDepart + i][joueur[0].yArrive].x,
                                        map[joueur[0].caseXDepart + i][joueur[0].yArrive].y + scaley,
                                        map[joueur[0].caseXDepart + i][joueur[0].yArrive].x,
                                        map[joueur[0].caseXDepart + i][joueur[0].yArrive].y -
                                        scaley, vert);

            }
        }
    }
    }



           /* if (joueur[0].caseY<joueur[0].yArrive){

                // Boucle sur y
                for (int j = 0; j < joueur[0].yArrive; j++) {

                    al_draw_filled_triangle(map[joueur[0].caseX][joueur[0].caseY + j].x - scalex,
                                            map[joueur[0].caseX][joueur[0].caseY + j].y,
                                            map[joueur[0].caseX][joueur[0].caseY + j].x,
                                            map[joueur[0].caseX][joueur[0].caseY + j].y + scaley,map[joueur[0].caseX][joueur[0].caseY + j].x,
                                            map[joueur[0].caseX][joueur[0].caseY + j].y -
                                            scaley, vert);
                    al_draw_filled_triangle(map[joueur[0].caseX][joueur[0].caseY + j].x + scalex,
                                            map[joueur[0].caseX][joueur[0].caseY + j].y,
                                            map[joueur[0].caseX][joueur[0].caseY + j].x,
                                            map[joueur[0].caseX][joueur[0].caseY + j].y + scaley,
                                            map[joueur[0].caseX][joueur[0].caseY + j].x,
                                            map[joueur[0].caseX][joueur[0].caseY + j].y -
                                             scaley, vert);


            }
        }*/

            /*if (joueur[0].caseY>joueur[0].yArrive){
                // Boucle sur y
                for (int j = joueur[0].yArrive - joueur[0].caseYDepart; j <joueur[0].caseXDepart ; j++) {

                    al_draw_filled_triangle(map[joueur[0].caseX][joueur[0].caseY + j].x - scalex,
                                            map[joueur[0].caseX][joueur[0].caseY + j].y,
                                            map[joueur[0].caseX][joueur[0].caseY + j].x,
                                            map[joueur[0].caseX][joueur[0].caseY + j].y + scaley,
                                            map[joueur[0].caseX][joueur[0].caseY + j].x,
                                            map[joueur[0].caseX][joueur[0].caseY + j].y -
                                        scaley, vert);

                    al_draw_filled_triangle(map[joueur[0].caseX][joueur[0].caseY + j].x + scalex,
                                            map[joueur[0].caseX][joueur[0].caseY + j].y,
                                            map[joueur[0].caseX][joueur[0].caseY + j].x,
                                            map[joueur[0].caseX][joueur[0].caseY + j].y + scaley,
                                            map[joueur[0].caseX][joueur[0].caseY + j].x,
                                            map[joueur[0].caseX][joueur[0].caseY + j].y -
                                        scaley, vert);


            }
        }*/



    if(joueur[0].actif==1 && joueur[0].dep==1) {
        if (joueur[0].caseX<joueur[0].xArrive){
            depX = 1;
        }

        if (joueur[0].caseX>joueur[0].xArrive){
            depX = -1;
        }

        if (joueur[0].caseY<joueur[0].yArrive){
            depY = scaley/scalex;
        }

        if (joueur[0].caseY>joueur[0].yArrive){
            depY = -scaley/scalex;
        }

        if (joueur[0].caseX == joueur[0].xArrive && joueur[0].caseY < joueur[0].yArrive ){
            depX = 1;
            depY = scaley/scalex;
        }

        if (joueur[0].caseX == joueur[0].xArrive && joueur[0].caseY > joueur[0].yArrive ){
            depX = -1;
            depY = -scaley/scalex;
        }

        if (joueur[0].caseX < joueur[0].xArrive && joueur[0].caseY == joueur[0].yArrive ){
            depX = 1;
            depY = -scaley/scalex;
        }

        if (joueur[0].caseX > joueur[0].xArrive && joueur[0].caseY == joueur[0].yArrive ){
            depX = -1;
            depY = scaley/scalex;
        }

        caseJoueur(joueur,map);


        joueur[0].x = joueur[0].x + depX;
        joueur[0].y = joueur[0].y + depY;


        if (joueur[0].caseX == joueur[0].xArrive && joueur[0].caseY==joueur[0].yArrive){joueur[0].dep=0;joueur[0].caseXDepart= joueur[0].caseX;
            joueur[0].caseYDepart= joueur[0].caseY;}
    }
}

void dessinerQuadrillage(double  width, double height,double scalex,double scaley,ALLEGRO_COLOR black){
    for (int i = 0; i < mapX+1; i++) {
        al_draw_line(i * scalex, height/1.8 - i * scaley, width/2.25+i*scalex , height - i * scaley, black, 2);
    }
    for (int i=0;i<mapY+1;i++){
        al_draw_line(width/1.8+i*scalex,i*scaley,i*scalex,height/1.8+scaley*i, black,2);
    }
}


void barreSort (ALLEGRO_BITMAP* barreSort){
    al_draw_scaled_bitmap(barreSort, 0, 0, 1000, 2000, 1800, 1580, 1500, 1345, 0);
    al_draw_scaled_bitmap(barreSort, 0, 0, 1000, 2000, 0, 1580, 1500, 1345, 0);
}

void drawSortKIRBY( ALLEGRO_FONT* gameFont, Jeux jeu, InfoEcran ecran) {

    if ((float) ecran.mouse_x < 2350 && ecran.mouse_x > 2190 && (float) ecran.mouse_y < 1770 && ecran.mouse_y > 1600) {
        al_draw_scaled_bitmap(jeu.classes[KIRBY].sortADisposition[POING].iconeSort, 0, 0, 2000, 2000, 2180, 1600, 1340,
                              1340, 0);
        al_draw_text(gameFont, al_map_rgb(100, 100, 100), 730, 1660, ALLEGRO_ALIGN_CENTER,
                     "COUP DE POING QUI FAIT SUPER MAL");
    } else {
        al_draw_scaled_bitmap(jeu.classes[KIRBY].sortADisposition[POING].iconeSort, 0, 0, 2000, 2000, 2180, 1600, 1290,
                              1290, 0);
    }

    if ((float) ecran.mouse_x < 2135 && ecran.mouse_x > 2045 && (float) ecran.mouse_y < 1765 && ecran.mouse_y > 1620) {
        al_draw_scaled_bitmap(jeu.classes[KIRBY].sortADisposition[COUPDEPIED].iconeSort, 0, 0, 2000, 2000, 2000, 1580,
                              1410, 1410, 0);
        al_draw_text(gameFont, al_map_rgb(100, 100, 100), 730, 1660, ALLEGRO_ALIGN_CENTER, "COUP DE PIED DE L'ENFER ");
    } else {
        al_draw_scaled_bitmap(jeu.classes[KIRBY].sortADisposition[COUPDEPIED].iconeSort, 0, 0, 2000, 2000, 2000, 1580,
                              1360, 1360, 0);
    }

    if ((float) ecran.mouse_x < 2500 && ecran.mouse_x > 2380 && (float) ecran.mouse_y < 1765 && ecran.mouse_y > 1620) {
        al_draw_scaled_bitmap(jeu.classes[KIRBY].sortADisposition[FLAMME].iconeSort, 0, 0, 2000, 2000, 2390, 1595, 850,
                              850, 0);
        al_draw_text(gameFont, al_map_rgb(100, 100, 100), 730, 1660, ALLEGRO_ALIGN_CENTER,
                     "SORT FLEMME - ENLEVEZ UN POINT DE VIE A VOTRE ADVERSAIRE ");
    } else {
        al_draw_scaled_bitmap(jeu.classes[KIRBY].sortADisposition[FLAMME].iconeSort, 0, 0, 2000, 2000, 2390, 1595, 800,
                              800, 0);
    }
}

void drawSortMARIO( ALLEGRO_FONT* gameFont, Jeux jeu, InfoEcran ecran) {

    if ((float) ecran.mouse_x < 2350 && ecran.mouse_x > 2190 && (float) ecran.mouse_y < 1770 && ecran.mouse_y > 1600) {
        al_draw_scaled_bitmap(jeu.classes[MARIO].sortADisposition[CORONA].iconeSort, 0, 0, 2000, 2000, 2190, 1580, 1270,
                              1270, 0);
        al_draw_text(gameFont, al_map_rgb(100, 100, 100), 730, 1660, ALLEGRO_ALIGN_CENTER,
                     "VIRUS CORONA (15 00 000 morts)");
    } else {
        al_draw_scaled_bitmap(jeu.classes[MARIO].sortADisposition[CORONA].iconeSort, 0, 0, 2000, 2000, 2190, 1580, 1220,
                              1220, 0);
    }

    if ((float) ecran.mouse_x < 2135 && ecran.mouse_x > 2045 && (float) ecran.mouse_y < 1765 && ecran.mouse_y > 1620) {
        al_draw_scaled_bitmap(jeu.classes[MARIO].sortADisposition[FLAMME].iconeSort, 0, 0, 2000, 2000, 2000, 1595, 850,
                              850, 0);
        al_draw_text(gameFont, al_map_rgb(100, 100, 100), 730, 1660, ALLEGRO_ALIGN_CENTER,
                     "FLAMME : BRULER VOS ADVERSAIRES");
    } else {
        al_draw_scaled_bitmap(jeu.classes[MARIO].sortADisposition[FLAMME].iconeSort, 0, 0, 2000, 2000, 2000, 1595, 800,
                              800, 0);
    }

    if ((float) ecran.mouse_x < 2530 && ecran.mouse_x > 2415 && (float) ecran.mouse_y < 1765 && ecran.mouse_y > 1620) {
        al_draw_scaled_bitmap(jeu.classes[MARIO].sortADisposition[POING2].iconeSort, 0, 0, 2000, 2000, 2415, 1595, 1130,
                              1130, 0);
        al_draw_text(gameFont, al_map_rgb(100, 100, 100), 730, 1660, ALLEGRO_ALIGN_CENTER, " COUP DE POING ");
    } else {
        al_draw_scaled_bitmap(jeu.classes[MARIO].sortADisposition[POING2].iconeSort, 0, 0, 2000, 2000, 2415, 1595, 1080,
                              1080, 0);
    }
}

void drawSortPEACH( ALLEGRO_FONT* gameFont, Jeux jeu, InfoEcran ecran) {

    if ((float) ecran.mouse_x < 2350 && ecran.mouse_x > 2190 && (float) ecran.mouse_y < 1770 && ecran.mouse_y > 1600) {
        al_draw_scaled_bitmap(jeu.classes[PEACH].sortADisposition[SORTFLEUR].iconeSort, 0, 0, 2000, 2000, 2200, 1618,
                              1160, 1160, 0);
        al_draw_text(gameFont, al_map_rgb(100, 100, 100), 730, 1660, ALLEGRO_ALIGN_CENTER, "Attaque de FLEUR !!!");
    } else {
        al_draw_scaled_bitmap(jeu.classes[PEACH].sortADisposition[SORTFLEUR].iconeSort, 0, 0, 2000, 2000, 2200, 1618,
                              1110, 1110, 0);
    }

    if ((float) ecran.mouse_x < 2135 && ecran.mouse_x > 2045 && (float) ecran.mouse_y < 1765 && ecran.mouse_y > 1620) {
        al_draw_scaled_bitmap(jeu.classes[PEACH].sortADisposition[COUPDEPIED].iconeSort, 0, 0, 2000, 2000, 2000, 1580,
                              1410, 1410, 0);
        al_draw_text(gameFont, al_map_rgb(100, 100, 100), 730, 1660, ALLEGRO_ALIGN_CENTER, "COUP DE PIED DE L'ENFER ");
    } else {
        al_draw_scaled_bitmap(jeu.classes[PEACH].sortADisposition[COUPDEPIED].iconeSort, 0, 0, 2000, 2000, 2000, 1580,
                              1360, 1360, 0);
    }

    if ((float) ecran.mouse_x < 2530 && ecran.mouse_x > 2415 && (float) ecran.mouse_y < 1765 && ecran.mouse_y > 1620) {
        al_draw_scaled_bitmap(jeu.classes[PEACH].sortADisposition[SORTSOIN].iconeSort, 0, 0, 2000, 2000, 2415, 1615,
                              1130, 1130, 0);
        al_draw_text(gameFont, al_map_rgb(100, 100, 100), 730, 1660, ALLEGRO_ALIGN_CENTER,
                     " Et si on mettait un pansements sur vos bobos ");
    } else {
        al_draw_scaled_bitmap(jeu.classes[PEACH].sortADisposition[SORTSOIN].iconeSort, 0, 0, 2000, 2000, 2415, 1615,
                              1080, 1080, 0);
    }

}

void drawSortPACMAN( ALLEGRO_FONT* gameFont, Jeux jeu, InfoEcran ecran) {

    if ((float) ecran.mouse_x < 2350 && ecran.mouse_x > 2190 && (float) ecran.mouse_y < 1770 && ecran.mouse_y > 1600) {
        al_draw_scaled_bitmap(jeu.classes[PACMAN].sortADisposition[RECULERADVERSAIRE].iconeSort, 0, 0, 2000, 2000, 2180,
                              1600, 1340, 1340, 0);
        al_draw_text(gameFont, al_map_rgb(100, 100, 100), 730, 1660, ALLEGRO_ALIGN_CENTER,
                     "COUP DE POING QUI FAIT VOYAGER SON ADVERSAIRE (CARREMENT)");
    } else {
        al_draw_scaled_bitmap(jeu.classes[PACMAN].sortADisposition[RECULERADVERSAIRE].iconeSort, 0, 0, 2000, 2000, 2180,
                              1600, 1290, 1290, 0);
    }

    if ((float) ecran.mouse_x < 2135 && ecran.mouse_x > 2045 && (float) ecran.mouse_y < 1765 && ecran.mouse_y > 1620) {
        al_draw_scaled_bitmap(jeu.classes[PACMAN].sortADisposition[SORTDEFENCE].iconeSort, 0, 0, 2000, 2000, 2000, 1580,
                              1350, 1350, 0);
        al_draw_text(gameFont, al_map_rgb(100, 100, 100), 730, 1660, ALLEGRO_ALIGN_CENTER, "SORT DEFENCE ");
    } else {
        al_draw_scaled_bitmap(jeu.classes[PACMAN].sortADisposition[SORTDEFENCE].iconeSort, 0, 0, 2000, 2000, 2000, 1580,
                              1300, 1300, 0);
    }

    if ((float) ecran.mouse_x < 2500 && ecran.mouse_x > 2380 && (float) ecran.mouse_y < 1765 && ecran.mouse_y > 1620) {
        al_draw_scaled_bitmap(jeu.classes[PACMAN].sortADisposition[FLAMME].iconeSort, 0, 0, 2000, 2000, 2390, 1595, 850,
                              850, 0);
        al_draw_text(gameFont, al_map_rgb(100, 100, 100), 730, 1660, ALLEGRO_ALIGN_CENTER,
                     "SORT FLEMME - ENLEVEZ UN POINT DE VIE A VOTRE ADVERSAIRE ");
    } else {
        al_draw_scaled_bitmap(jeu.classes[PACMAN].sortADisposition[FLAMME].iconeSort, 0, 0, 2000, 2000, 2390, 1595, 800,
                              800, 0);
    }

}

void drawSortDONKEYKONG(ALLEGRO_FONT* gameFont, Jeux jeu, InfoEcran ecran) {

    if ((float) ecran.mouse_x < 2350 && ecran.mouse_x > 2190 && (float) ecran.mouse_y < 1770 && ecran.mouse_y > 1600) {
        al_draw_scaled_bitmap(jeu.classes[DONKEY_KONG].sortADisposition[MORTEL].iconeSort, 0, 0, 2000, 2000, 2187, 1590,
                              1310, 1310, 0);
        al_draw_text(gameFont, al_map_rgb(100, 100, 100), 730, 1660, ALLEGRO_ALIGN_CENTER,
                     "COUP DE POING QUI FAIT VOYAGER SON ADVERSAIRE (CARREMENT)");
    } else {
        al_draw_scaled_bitmap(jeu.classes[DONKEY_KONG].sortADisposition[MORTEL].iconeSort, 0, 0, 2000, 2000, 2187, 1590,
                              1270, 1270, 0);
    }

    if ((float) ecran.mouse_x < 2135 && ecran.mouse_x > 2045 && (float) ecran.mouse_y < 1765 && ecran.mouse_y > 1620) {
        al_draw_scaled_bitmap(jeu.classes[DONKEY_KONG].sortADisposition[POINGGANT].iconeSort, 0, 0, 2000, 2000, 2000,
                              1580, 1350, 1350, 0);
        al_draw_text(gameFont, al_map_rgb(100, 100, 100), 730, 1660, ALLEGRO_ALIGN_CENTER, "SORT DEFENCE ");
    } else {
        al_draw_scaled_bitmap(jeu.classes[DONKEY_KONG].sortADisposition[POINGGANT].iconeSort, 0, 0, 2000, 2000, 2000,
                              1580, 1300, 1300, 0);
    }

    if ((float) ecran.mouse_x < 2550 && ecran.mouse_x > 2397 && (float) ecran.mouse_y < 1765 && ecran.mouse_y > 1620) {
        al_draw_scaled_bitmap(jeu.classes[DONKEY_KONG].sortADisposition[SAUT].iconeSort, 0, 0, 2000, 2000, 2400, 1575,
                              1390, 1390, 0);
        al_draw_text(gameFont, al_map_rgb(100, 100, 100), 730, 1660, ALLEGRO_ALIGN_CENTER,
                     "SORT FLEMME - ENLEVEZ UN POINT DE VIE A VOTRE ADVERSAIRE ");
    } else {
        al_draw_scaled_bitmap(jeu.classes[DONKEY_KONG].sortADisposition[SAUT].iconeSort, 0, 0, 2000, 2000, 2400, 1575,
                              1340, 1340, 0);
    }
}

//// c'est jeu.joueur[jeu.info.joueurQuiJoue]


void sortEnFonctionDesClasses(ALLEGRO_FONT* gameFont, Jeux jeu, InfoEcran ecran, int joueurQuiJoue,  ALLEGRO_BITMAP* barreSort){
    al_draw_scaled_bitmap(barreSort, 0, 0, 1000, 2000, 1800, 1580, 1500, 1345, 0);
    al_draw_scaled_bitmap(barreSort, 0, 0, 1000, 2000, 0, 1580, 1500, 1345, 0);

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
/*

void sortChoisi (Jeux jeu, InfoEcran ecran) {
    if ((float) ecran.mouse_x < 2550 && ecran.mouse_x > 2397 && (float) ecran.mouse_y < 1765 && ecran.mouse_y > 1620) {
        al_draw_scaled_bitmap(jeu.classes[DONKEY_KONG].sortADisposition[SAUT].iconeSort, 0, 0, 2000, 2000, 2400, 1575,
                              1390, 1390, 0);
    } else {
        al_draw_scaled_bitmap(jeu.classes[DONKEY_KONG].sortADisposition[SAUT].iconeSort, 0, 0, 2000, 2000, 2400, 1575,
                              1340, 1340, 0);
    }
}
*/
