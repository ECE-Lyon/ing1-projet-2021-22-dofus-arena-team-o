#include "map.h"

bool collisionCercle(int x,int y,Map map[30][30],int i,int j,double width){
    int d2 = (x-map[i][j].x)*(x-map[i][j].x) + (y- map[i][j].y)*(y-map[i][j].y);
    if (d2>(width/60*width/60))
        return false;
    else
        return true;
}

void drawPlay(Joueurs *joueur,Map map[30][30], int joueurQuiJoue, int mouse_x,int mouse_y,double width, double scalex, double scaley, ALLEGRO_COLOR black,ALLEGRO_COLOR red) {

    ALLEGRO_COLOR vert2 = al_map_rgba(93, 127, 51, 200);
    caseJoueur(joueur,map, joueurQuiJoue);

    /*for (int j=0;j<mapY;j++) {
    /*for (int j=0;j<mapY;j++) {
        for (int i = 0; i < mapX; i++) {
            if (map[i][j].obstacle==1){
            al_draw_filled_triangle(map[i][j].x - scalex, map[i][j].y, map[i][j].x, map[i][j].y + scaley, map[i][j].x, map[i][j].y -scaley, white);
            al_draw_filled_triangle(map[i][j].x + scalex, map[i][j].y, map[i][j].x, map[i][j].y + scaley, map[i][j].x, map[i][j].y -scaley, white);
        }
        }
    }*/

    }*/
    if (joueur[joueurQuiJoue].dep==0 && joueur[joueurQuiJoue].sortAppuye == 3) {
        for (int j = 0; j < joueur[joueurQuiJoue].PM+1; j++) {
            for (int i = 0; i < joueur[joueurQuiJoue].PM+1; i++) {
                if (i + j <= joueur[joueurQuiJoue].PM ) {
                    al_draw_filled_triangle(map[joueur[joueurQuiJoue].caseXDepart + i][joueur[joueurQuiJoue].caseYDepart + j].x - scalex,
                                            map[joueur[joueurQuiJoue].caseXDepart + i][joueur[joueurQuiJoue].caseYDepart + j].y,
                                            map[joueur[joueurQuiJoue].caseXDepart + i][joueur[joueurQuiJoue].caseYDepart + j].x,
                                            map[joueur[joueurQuiJoue].caseXDepart + i][joueur[joueurQuiJoue].caseYDepart + j].y + scaley,
                                            map[joueur[joueurQuiJoue].caseXDepart + i][joueur[joueurQuiJoue].caseYDepart + j].x,
                                            map[joueur[joueurQuiJoue].caseXDepart + i][joueur[joueurQuiJoue].caseYDepart + j].y -
                                            scaley, vert2);
                    al_draw_filled_triangle(map[joueur[joueurQuiJoue].caseXDepart + i][joueur[joueurQuiJoue].caseYDepart + j].x + scalex,
                                            map[joueur[joueurQuiJoue].caseXDepart + i][joueur[joueurQuiJoue].caseYDepart + j].y,
                                            map[joueur[joueurQuiJoue].caseXDepart + i][joueur[joueurQuiJoue].caseYDepart + j].x,
                                            map[joueur[joueurQuiJoue].caseXDepart + i][joueur[joueurQuiJoue].caseYDepart + j].y + scaley,
                                            map[joueur[joueurQuiJoue].caseXDepart + i][joueur[joueurQuiJoue].caseYDepart + j].x,
                                            map[joueur[joueurQuiJoue].caseXDepart + i][joueur[joueurQuiJoue].caseYDepart + j].y -
                                            scaley, vert2);
                    al_draw_filled_triangle(
                            map[joueur[joueurQuiJoue].caseXDepart - i][joueur[joueurQuiJoue].caseYDepart - j].x -
                            scalex,
                            map[joueur[joueurQuiJoue].caseXDepart - i][joueur[joueurQuiJoue].caseYDepart - j].y,
                            map[joueur[joueurQuiJoue].caseXDepart - i][joueur[joueurQuiJoue].caseYDepart - j].x,
                            map[joueur[joueurQuiJoue].caseXDepart - i][joueur[joueurQuiJoue].caseYDepart - j].y +
                            scaley,
                            map[joueur[joueurQuiJoue].caseXDepart - i][joueur[joueurQuiJoue].caseYDepart - j].x,
                            map[joueur[joueurQuiJoue].caseXDepart - i][joueur[joueurQuiJoue].caseYDepart - j].y -
                            scaley, vert2);
                    al_draw_filled_triangle(
                            map[joueur[joueurQuiJoue].caseXDepart - i][joueur[joueurQuiJoue].caseYDepart - j].x +
                            scalex,
                            map[joueur[joueurQuiJoue].caseXDepart - i][joueur[joueurQuiJoue].caseYDepart - j].y,
                            map[joueur[joueurQuiJoue].caseXDepart - i][joueur[joueurQuiJoue].caseYDepart - j].x,
                            map[joueur[joueurQuiJoue].caseXDepart - i][joueur[joueurQuiJoue].caseYDepart - j].y +
                            scaley,
                            map[joueur[joueurQuiJoue].caseXDepart - i][joueur[joueurQuiJoue].caseYDepart - j].x,
                            map[joueur[joueurQuiJoue].caseXDepart - i][joueur[joueurQuiJoue].caseYDepart - j].y -
                            scaley, vert2);

                    al_draw_filled_triangle(
                            map[joueur[joueurQuiJoue].caseXDepart + i][joueur[joueurQuiJoue].caseYDepart - j].x -
                            scalex,
                            map[joueur[joueurQuiJoue].caseXDepart + i][joueur[joueurQuiJoue].caseYDepart - j].y,
                            map[joueur[joueurQuiJoue].caseXDepart + i][joueur[joueurQuiJoue].caseYDepart - j].x,
                            map[joueur[joueurQuiJoue].caseXDepart + i][joueur[joueurQuiJoue].caseYDepart - j].y +
                            scaley,
                            map[joueur[joueurQuiJoue].caseXDepart + i][joueur[joueurQuiJoue].caseYDepart - j].x,
                            map[joueur[joueurQuiJoue].caseXDepart + i][joueur[joueurQuiJoue].caseYDepart - j].y -
                            scaley, vert2);
                    al_draw_filled_triangle(
                            map[joueur[joueurQuiJoue].caseXDepart + i][joueur[joueurQuiJoue].caseYDepart - j].x +
                            scalex,
                            map[joueur[joueurQuiJoue].caseXDepart + i][joueur[joueurQuiJoue].caseYDepart - j].y,
                            map[joueur[joueurQuiJoue].caseXDepart + i][joueur[joueurQuiJoue].caseYDepart - j].x,
                            map[joueur[joueurQuiJoue].caseXDepart + i][joueur[joueurQuiJoue].caseYDepart - j].y +
                            scaley,
                            map[joueur[joueurQuiJoue].caseXDepart + i][joueur[joueurQuiJoue].caseYDepart - j].x,
                            map[joueur[joueurQuiJoue].caseXDepart + i][joueur[joueurQuiJoue].caseYDepart - j].y -
                            scaley, vert2);
                    al_draw_filled_triangle(
                            map[joueur[joueurQuiJoue].caseXDepart - i][joueur[joueurQuiJoue].caseYDepart + j].x -
                            scalex,
                            map[joueur[joueurQuiJoue].caseXDepart - i][joueur[joueurQuiJoue].caseYDepart + j].y,
                            map[joueur[joueurQuiJoue].caseXDepart - i][joueur[joueurQuiJoue].caseYDepart + j].x,
                            map[joueur[joueurQuiJoue].caseXDepart - i][joueur[joueurQuiJoue].caseYDepart + j].y +
                            scaley,
                            map[joueur[joueurQuiJoue].caseXDepart - i][joueur[joueurQuiJoue].caseYDepart + j].x,
                            map[joueur[joueurQuiJoue].caseXDepart - i][joueur[joueurQuiJoue].caseYDepart + j].y -
                            scaley, vert2);
                    al_draw_filled_triangle(
                            map[joueur[joueurQuiJoue].caseXDepart - i][joueur[joueurQuiJoue].caseYDepart + j].x +
                            scalex,
                            map[joueur[joueurQuiJoue].caseXDepart - i][joueur[joueurQuiJoue].caseYDepart + j].y,
                            map[joueur[joueurQuiJoue].caseXDepart - i][joueur[joueurQuiJoue].caseYDepart + j].x,
                            map[joueur[joueurQuiJoue].caseXDepart - i][joueur[joueurQuiJoue].caseYDepart + j].y +
                            scaley,
                            map[joueur[joueurQuiJoue].caseXDepart - i][joueur[joueurQuiJoue].caseYDepart + j].x,
                            map[joueur[joueurQuiJoue].caseXDepart - i][joueur[joueurQuiJoue].caseYDepart + j].y -
                            scaley, vert2);
                }
            }
        }
    }

    for (int j=0;j<mapY;j++) {
        for (int i = 0; i < mapX; i++) {
            if(collisionCercle(mouse_x, mouse_y, map, i, j,width) == true){
                al_draw_filled_triangle(map[i][j].x - scalex, map[i][j].y, map[i][j].x, map[i][j].y + scaley, map[i][j].x, map[i][j].y -
                                                                                                                           scaley, black);
                al_draw_filled_triangle(map[i][j].x + scalex, map[i][j].y, map[i][j].x, map[i][j].y + scaley, map[i][j].x, map[i][j].y -
                                                                                                                           scaley, black);

                if(map[0][0].t == 1 && joueur[joueurQuiJoue].dep == 0 && abs(joueur[joueurQuiJoue].xArrive-joueur[joueurQuiJoue].caseXDepart)+abs(joueur[joueurQuiJoue].yArrive-joueur[joueurQuiJoue].caseYDepart)<=3 && map[joueur[joueurQuiJoue].xArrive][joueur[joueurQuiJoue].yArrive].obstacle!=1 && joueur[joueurQuiJoue].PM>0 && joueur[joueurQuiJoue].obstacle==0){
                    joueur[joueurQuiJoue].caseXDepart= joueur[joueurQuiJoue].caseX;
                    joueur[joueurQuiJoue].caseYDepart= joueur[joueurQuiJoue].caseY;
                    joueur[joueurQuiJoue].dep=1;
                    joueur[joueurQuiJoue].quelAnimation = MARCHER ;
                    joueur[joueurQuiJoue].xArrive=i;
                    joueur[joueurQuiJoue].yArrive=j;
                    joueur[joueurQuiJoue].actif=1;
                    al_draw_filled_triangle(map[i][j].x - scalex, map[i][j].y, map[i][j].x, map[i][j].y + scaley, map[i][j].x, map[i][j].y -
                                                                                                                               scaley, red);
                    al_draw_filled_triangle(map[i][j].x + scalex, map[i][j].y, map[i][j].x, map[i][j].y + scaley, map[i][j].x, map[i][j].y -
                                                                                                                               scaley, red);
                }
                if (joueur[joueurQuiJoue].dep == 0){
                    joueur[joueurQuiJoue].xArrive=i;
                    joueur[joueurQuiJoue].yArrive=j;
                }

            }

        }
    }
}

void caseJoueur(Joueurs *joueur,Map map[30][30], int joueurQuiJoue){
    for (int j=0;j<mapY;j++) {
        for (int i = 0; i < mapX; i++) {
            if (joueur[joueurQuiJoue].x>map[i][j].x-1 && joueur[joueurQuiJoue].x<map[i][j].x+1 && joueur[joueurQuiJoue].y>map[i][j].y-1 && joueur[joueurQuiJoue].y<map[i][j].y+1 ){
                joueur[joueurQuiJoue].caseX=i;
                joueur[joueurQuiJoue].caseY=j;

                }
                //printf(" CaseXa: %d , CaseYa: %d\n",joueur[0].caseXDepart,joueur[0].caseYDepart);
            }
        }
    }

void deplacementJoueur(Joueurs *joueur, Map map[30][30], int joueurQuiJoue, double scalex,double scaley, int* direction) {
    ALLEGRO_COLOR vert = al_map_rgba(93, 127, 51, 255);
    double depX = 0;
    double depY = 0;

    caseJoueur(joueur, map, joueurQuiJoue);
    /*for (int i=0; i<joueur[joueurQuiJoue].xArrive; i++){
        if (map[i][0].obstacle==1){
            joueur[joueurQuiJoue].dep=0;
            joueur[joueurQuiJoue].actif=0;

        }
    }*/

    if (joueur[joueurQuiJoue].PM>0){
    if (abs(joueur[joueurQuiJoue].xArrive - joueur[joueurQuiJoue].caseXDepart) +
        abs(joueur[joueurQuiJoue].yArrive - joueur[joueurQuiJoue].caseYDepart) <= joueur[joueurQuiJoue].PM+1 &&
        joueur[joueurQuiJoue].sortAppuye == 3) {
        if (joueur[joueurQuiJoue].caseX > joueur[joueurQuiJoue].xArrive) {
            // Boucle sur x
            for (int i = 0; i < -joueur[joueurQuiJoue].xArrive + joueur[joueurQuiJoue].caseXDepart; i++) {
                if (map[joueur[joueurQuiJoue].caseXDepart - i][joueur[joueurQuiJoue].yArrive].obstacle==1){joueur[joueurQuiJoue].obstacle=1;}
                else joueur[joueurQuiJoue].obstacle=0;
                al_draw_filled_triangle(
                        map[joueur[joueurQuiJoue].caseXDepart - i][joueur[joueurQuiJoue].yArrive].x - scalex,
                        map[joueur[joueurQuiJoue].caseXDepart - i][joueur[joueurQuiJoue].yArrive].y,
                        map[joueur[joueurQuiJoue].caseXDepart - i][joueur[joueurQuiJoue].yArrive].x,
                        map[joueur[joueurQuiJoue].caseXDepart - i][joueur[joueurQuiJoue].yArrive].y + scaley,
                        map[joueur[joueurQuiJoue].caseXDepart - i][joueur[joueurQuiJoue].yArrive].x,
                        map[joueur[joueurQuiJoue].caseXDepart - i][joueur[joueurQuiJoue].yArrive].y -
                        scaley, vert);
                al_draw_filled_triangle(
                        map[joueur[joueurQuiJoue].caseXDepart - i][joueur[joueurQuiJoue].yArrive].x + scalex,
                        map[joueur[joueurQuiJoue].caseXDepart - i][joueur[joueurQuiJoue].yArrive].y,
                        map[joueur[joueurQuiJoue].caseXDepart - i][joueur[joueurQuiJoue].yArrive].x,
                        map[joueur[joueurQuiJoue].caseXDepart - i][joueur[joueurQuiJoue].yArrive].y + scaley,
                        map[joueur[joueurQuiJoue].caseXDepart - i][joueur[joueurQuiJoue].yArrive].x,
                        map[joueur[joueurQuiJoue].caseXDepart - i][joueur[joueurQuiJoue].yArrive].y -
                        scaley, vert);

            }
        }
        if (joueur[joueurQuiJoue].caseX < joueur[joueurQuiJoue].xArrive) {
            // Boucle sur x
            for (int i = 0; i < joueur[joueurQuiJoue].xArrive - joueur[joueurQuiJoue].caseXDepart; i++) {
                if (map[joueur[joueurQuiJoue].caseXDepart + i][joueur[joueurQuiJoue].yArrive].obstacle==1){joueur[joueurQuiJoue].obstacle=1;}
                else joueur[joueurQuiJoue].obstacle=0;
                al_draw_filled_triangle(
                        map[joueur[joueurQuiJoue].caseXDepart + i][joueur[joueurQuiJoue].yArrive].x - scalex,
                        map[joueur[joueurQuiJoue].caseXDepart + i][joueur[joueurQuiJoue].yArrive].y,
                        map[joueur[joueurQuiJoue].caseXDepart + i][joueur[joueurQuiJoue].yArrive].x,
                        map[joueur[joueurQuiJoue].caseXDepart + i][joueur[joueurQuiJoue].yArrive].y + scaley,
                        map[joueur[joueurQuiJoue].caseXDepart + i][joueur[joueurQuiJoue].yArrive].x,
                        map[joueur[joueurQuiJoue].caseXDepart + i][joueur[joueurQuiJoue].yArrive].y -
                        scaley, vert);
                al_draw_filled_triangle(
                        map[joueur[joueurQuiJoue].caseXDepart + i][joueur[joueurQuiJoue].yArrive].x + scalex,
                        map[joueur[joueurQuiJoue].caseXDepart + i][joueur[joueurQuiJoue].yArrive].y,
                        map[joueur[joueurQuiJoue].caseXDepart + i][joueur[joueurQuiJoue].yArrive].x,
                        map[joueur[joueurQuiJoue].caseXDepart + i][joueur[joueurQuiJoue].yArrive].y + scaley,
                        map[joueur[joueurQuiJoue].caseXDepart + i][joueur[joueurQuiJoue].yArrive].x,
                        map[joueur[joueurQuiJoue].caseXDepart + i][joueur[joueurQuiJoue].yArrive].y -
                        scaley, vert);

            }
        }
        if (joueur[joueurQuiJoue].caseY > joueur[joueurQuiJoue].yArrive) {
            // Boucle sur y
            for (int j = 0; j < -joueur[joueurQuiJoue].yArrive + joueur[joueurQuiJoue].caseYDepart; j++) {
                if (map[joueur[joueurQuiJoue].caseXDepart][joueur[joueurQuiJoue].yArrive-j].obstacle==1){joueur[joueurQuiJoue].obstacle=1;}
                else joueur[joueurQuiJoue].obstacle=0;

                al_draw_filled_triangle(
                        map[joueur[joueurQuiJoue].caseXDepart][joueur[joueurQuiJoue].caseYDepart - j].x - scalex,
                        map[joueur[joueurQuiJoue].caseXDepart][joueur[joueurQuiJoue].caseYDepart - j].y,
                        map[joueur[joueurQuiJoue].caseXDepart][joueur[joueurQuiJoue].caseYDepart - j].x,
                        map[joueur[joueurQuiJoue].caseXDepart][joueur[joueurQuiJoue].caseYDepart - j].y + scaley,
                        map[joueur[joueurQuiJoue].caseXDepart][joueur[joueurQuiJoue].caseYDepart - j].x,
                        map[joueur[joueurQuiJoue].caseXDepart][joueur[joueurQuiJoue].caseYDepart - j].y -
                        scaley, vert);
                al_draw_filled_triangle(
                        map[joueur[joueurQuiJoue].caseXDepart][joueur[joueurQuiJoue].caseYDepart - j].x + scalex,
                        map[joueur[joueurQuiJoue].caseXDepart][joueur[joueurQuiJoue].caseYDepart - j].y,
                        map[joueur[joueurQuiJoue].caseXDepart][joueur[joueurQuiJoue].caseYDepart - j].x,
                        map[joueur[joueurQuiJoue].caseXDepart][joueur[joueurQuiJoue].caseYDepart - j].y + scaley,
                        map[joueur[joueurQuiJoue].caseXDepart][joueur[joueurQuiJoue].caseYDepart - j].x,
                        map[joueur[joueurQuiJoue].caseXDepart][joueur[joueurQuiJoue].caseYDepart - j].y -
                        scaley, vert);


            }
        }

        if (joueur[joueurQuiJoue].caseY < joueur[joueurQuiJoue].yArrive) {
            // Boucle sur y
            for (int j = 0; j < joueur[joueurQuiJoue].yArrive - joueur[joueurQuiJoue].caseYDepart; j++) {
                if (map[joueur[joueurQuiJoue].caseXDepart][joueur[joueurQuiJoue].yArrive+j].obstacle==1){joueur[joueurQuiJoue].obstacle=1;}
                else joueur[joueurQuiJoue].obstacle=0;
                al_draw_filled_triangle(map[joueur[joueurQuiJoue].caseX][joueur[joueurQuiJoue].caseY + j].x - scalex,
                                        map[joueur[joueurQuiJoue].caseX][joueur[joueurQuiJoue].caseY + j].y,
                                        map[joueur[joueurQuiJoue].caseX][joueur[joueurQuiJoue].caseY + j].x,
                                        map[joueur[joueurQuiJoue].caseX][joueur[joueurQuiJoue].caseY + j].y + scaley,
                                        map[joueur[joueurQuiJoue].caseX][joueur[joueurQuiJoue].caseY + j].x,
                                        map[joueur[joueurQuiJoue].caseX][joueur[joueurQuiJoue].caseY + j].y -
                                        scaley, vert);
                al_draw_filled_triangle(map[joueur[joueurQuiJoue].caseX][joueur[joueurQuiJoue].caseY + j].x + scalex,
                                        map[joueur[joueurQuiJoue].caseX][joueur[joueurQuiJoue].caseY + j].y,
                                        map[joueur[joueurQuiJoue].caseX][joueur[joueurQuiJoue].caseY + j].x,
                                        map[joueur[joueurQuiJoue].caseX][joueur[joueurQuiJoue].caseY + j].y + scaley,
                                        map[joueur[joueurQuiJoue].caseX][joueur[joueurQuiJoue].caseY + j].x,
                                        map[joueur[joueurQuiJoue].caseX][joueur[joueurQuiJoue].caseY + j].y -
                                        scaley, vert);
            }
        }

        if (joueur[joueurQuiJoue].caseX == joueur[joueurQuiJoue].xArrive &&
            joueur[joueurQuiJoue].caseY == joueur[joueurQuiJoue].yArrive) {
            al_draw_filled_triangle(map[joueur[joueurQuiJoue].caseX][joueur[joueurQuiJoue].caseY].x - scalex,
                                    map[joueur[joueurQuiJoue].caseX][joueur[joueurQuiJoue].caseY].y,
                                    map[joueur[joueurQuiJoue].caseX][joueur[joueurQuiJoue].caseY].x,
                                    map[joueur[joueurQuiJoue].caseX][joueur[joueurQuiJoue].caseY].y + scaley,
                                    map[joueur[joueurQuiJoue].caseX][joueur[joueurQuiJoue].caseY].x,
                                    map[joueur[joueurQuiJoue].caseX][joueur[joueurQuiJoue].caseY].y -
                                    scaley, vert);
            al_draw_filled_triangle(map[joueur[joueurQuiJoue].caseX][joueur[joueurQuiJoue].caseY].x + scalex,
                                    map[joueur[joueurQuiJoue].caseX][joueur[joueurQuiJoue].caseY].y,
                                    map[joueur[joueurQuiJoue].caseX][joueur[joueurQuiJoue].caseY].x,
                                    map[joueur[joueurQuiJoue].caseX][joueur[joueurQuiJoue].caseY].y + scaley,
                                    map[joueur[joueurQuiJoue].caseX][joueur[joueurQuiJoue].caseY].x,
                                    map[joueur[joueurQuiJoue].caseX][joueur[joueurQuiJoue].caseY].y -
                                    scaley, vert);


        }
    }

    if (joueur[joueurQuiJoue].caseX == joueur[joueurQuiJoue].xArrive &&
        joueur[joueurQuiJoue].caseY == joueur[joueurQuiJoue].yArrive) {
        al_draw_filled_triangle(map[joueur[joueurQuiJoue].caseX][joueur[joueurQuiJoue].caseY].x - scalex,
                                map[joueur[joueurQuiJoue].caseX][joueur[joueurQuiJoue].caseY].y,
                                map[joueur[joueurQuiJoue].caseX][joueur[joueurQuiJoue].caseY].x,
                                map[joueur[joueurQuiJoue].caseX][joueur[joueurQuiJoue].caseY].y + scaley,
                                map[joueur[joueurQuiJoue].caseX][joueur[joueurQuiJoue].caseY].x,
                                map[joueur[joueurQuiJoue].caseX][joueur[joueurQuiJoue].caseY].y -
                                scaley, vert);
        al_draw_filled_triangle(map[joueur[joueurQuiJoue].caseX][joueur[joueurQuiJoue].caseY].x + scalex,
                                map[joueur[joueurQuiJoue].caseX][joueur[joueurQuiJoue].caseY].y,
                                map[joueur[joueurQuiJoue].caseX][joueur[joueurQuiJoue].caseY].x,
                                map[joueur[joueurQuiJoue].caseX][joueur[joueurQuiJoue].caseY].y + scaley,
                                map[joueur[joueurQuiJoue].caseX][joueur[joueurQuiJoue].caseY].x,
                                map[joueur[joueurQuiJoue].caseX][joueur[joueurQuiJoue].caseY].y -
                                scaley, vert);

    }

    if (joueur[joueurQuiJoue].actif == 1 && joueur[joueurQuiJoue].dep == 1  && joueur[joueurQuiJoue].PM>0 && joueur[joueurQuiJoue].sortAppuye == 3 && joueur[joueurQuiJoue].PM+1>=abs(abs(joueur[joueurQuiJoue].xArrive - joueur[joueurQuiJoue].caseXDepart) + abs(joueur[joueurQuiJoue].yArrive - joueur[joueurQuiJoue].caseYDepart)) && joueur[joueurQuiJoue].obstacle==0){
    if (joueur[joueurQuiJoue].actif == 1 && joueur[joueurQuiJoue].dep == 1  && joueur[joueurQuiJoue].PM>0 && joueur[joueurQuiJoue].sortAppuye == 3 && joueur[joueurQuiJoue].PM+1>=abs(abs(joueur[joueurQuiJoue].xArrive - joueur[joueurQuiJoue].caseXDepart) + abs(joueur[joueurQuiJoue].yArrive - joueur[joueurQuiJoue].caseYDepart))){
        // && a ==0

            if (joueur[joueurQuiJoue].caseX < joueur[joueurQuiJoue].xArrive) {
                depX = 1;
                joueur[joueurQuiJoue].direction = 0;
            }

            if (joueur[joueurQuiJoue].caseX > joueur[joueurQuiJoue].xArrive) {
                depX = -1;
                joueur[joueurQuiJoue].direction = 1;
            }

            if (joueur[joueurQuiJoue].caseY < joueur[joueurQuiJoue].yArrive) {
                depY = scaley / scalex;
            }

            if (joueur[joueurQuiJoue].caseY > joueur[joueurQuiJoue].yArrive) {
                depY = -scaley / scalex;
            }

            if (joueur[joueurQuiJoue].caseX < joueur[joueurQuiJoue].xArrive &&
                joueur[joueurQuiJoue].caseY == joueur[joueurQuiJoue].yArrive) {
                depX = 1;
                depY = -scaley / scalex;
                joueur[joueurQuiJoue].direction = 0;
            }

            if (joueur[joueurQuiJoue].caseX == joueur[joueurQuiJoue].xArrive &&
                joueur[joueurQuiJoue].caseY < joueur[joueurQuiJoue].yArrive) {
                depX = 1;
                depY = scaley / scalex;
                joueur[joueurQuiJoue].direction = 0;
            }

            if (joueur[joueurQuiJoue].caseX > joueur[joueurQuiJoue].xArrive &&
                joueur[joueurQuiJoue].caseY == joueur[joueurQuiJoue].yArrive) {
                depX = -1;
                depY = scaley / scalex;
                joueur[joueurQuiJoue].direction = 1;
            }

            if (joueur[joueurQuiJoue].caseX == joueur[joueurQuiJoue].xArrive &&
                joueur[joueurQuiJoue].caseY > joueur[joueurQuiJoue].yArrive) {
                depX = -1;
                depY = -scaley / scalex;
                joueur[joueurQuiJoue].direction = 1;
            }

        caseJoueur(joueur, map, joueurQuiJoue);

        joueur[joueurQuiJoue].y = joueur[joueurQuiJoue].y + depY;
        joueur[joueurQuiJoue].x = joueur[joueurQuiJoue].x + depX;

        /*if (joueur[joueurQuiJoue].dep==1){

            if (map[joueur[joueurQuiJoue].caseX][joueur[joueurQuiJoue].caseY+1].obstacle==1){joueur[joueurQuiJoue].obstacle=1;}
            else joueur[joueurQuiJoue].obstacle=0;
            if (map[joueur[joueurQuiJoue].caseX-1][joueur[joueurQuiJoue].caseY].obstacle==1){joueur[joueurQuiJoue].obstacle=1;}
            else joueur[joueurQuiJoue].obstacle=0;
            if (map[joueur[joueurQuiJoue].caseX][joueur[joueurQuiJoue].caseY-1].obstacle==1){joueur[joueurQuiJoue].obstacle=1;}
            joueur[joueurQuiJoue].obstacle=0;
        }*/


        if (joueur[joueurQuiJoue].caseX == joueur[joueurQuiJoue].xArrive &&
            joueur[joueurQuiJoue].caseY == joueur[joueurQuiJoue].yArrive) {
            joueur[joueurQuiJoue].dep = 0;
            if (abs(joueur[joueurQuiJoue].xArrive - joueur[joueurQuiJoue].caseXDepart) +
                abs(joueur[joueurQuiJoue].yArrive - joueur[joueurQuiJoue].caseYDepart<=joueur[joueurQuiJoue].PM)){
                joueur[joueurQuiJoue].PM=joueur[joueurQuiJoue].PM-abs(abs(joueur[joueurQuiJoue].xArrive - joueur[joueurQuiJoue].caseXDepart) +
                                     abs(joueur[joueurQuiJoue].yArrive - joueur[joueurQuiJoue].caseYDepart));
            }
            joueur[joueurQuiJoue].quelAnimation = RESPIRATION;
            map[joueur[joueurQuiJoue].caseXDepart][joueur[joueurQuiJoue].caseYDepart].joueurPresentDessus = 0;
            map[joueur[joueurQuiJoue].caseX][joueur[joueurQuiJoue].caseY].joueurPresentDessus = joueurQuiJoue + 1;
            joueur[joueurQuiJoue].caseXDepart = joueur[joueurQuiJoue].caseX;
            joueur[joueurQuiJoue].caseYDepart = joueur[joueurQuiJoue].caseY;
        }
    }

}
}

void dessinerCase(Map map[30][30], int caseX, int caseY, double scalex, double scaley) {
    ALLEGRO_COLOR red = al_map_rgba(255, 50, 50, 100);
    if (map[caseX][caseY].obstacle != 1) {
        al_draw_filled_triangle(map[caseX][caseY].x - scalex, map[caseX][caseY].y, map[caseX][caseY].x,
                                map[caseX][caseY].y + scaley, map[caseX][caseY].x, map[caseX][caseY].y -
                                                                                   scaley, red);
        al_draw_filled_triangle(map[caseX][caseY].x + scalex, map[caseX][caseY].y, map[caseX][caseY].x,
                                map[caseX][caseY].y + scaley, map[caseX][caseY].x, map[caseX][caseY].y -
                                                                                   scaley, red);
    }
}


