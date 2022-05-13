#include "map.h"

bool collisionCercle(int x,int y,Map map[30][30],int i,int j,double width){
    int d2 = (x-map[i][j].x)*(x-map[i][j].x) + (y- map[i][j].y)*(y-map[i][j].y);
    if (d2>(width/60*width/60))
        return false;
    else
        return true;
}

void drawPlay(Joueurs *joueur,Map map[30][30], int joueurQuiJoue, int mouse_x,int mouse_y,double width, double height, double scalex, double scaley, ALLEGRO_DISPLAY *display,ALLEGRO_COLOR white, ALLEGRO_COLOR black, ALLEGRO_COLOR gris,ALLEGRO_COLOR vert,ALLEGRO_COLOR red) {

    ALLEGRO_COLOR vert2 = al_map_rgba(93, 127, 51, 200);
    caseJoueur(joueur,map, joueurQuiJoue);
    for (int j=0;j<mapY;j++) {
        for (int i = 0; i < mapX; i++) {
            if (map[i][j].obstacle==1){
            al_draw_filled_triangle(map[i][j].x - scalex, map[i][j].y, map[i][j].x, map[i][j].y + scaley, map[i][j].x, map[i][j].y -scaley, white);
            al_draw_filled_triangle(map[i][j].x + scalex, map[i][j].y, map[i][j].x, map[i][j].y + scaley, map[i][j].x, map[i][j].y -scaley, white);
        }
        }
    }
    if (joueur[joueurQuiJoue].dep==0) {
        for (int j = 0; j < 4; j++) {
            for (int i = 0; i < 4; i++) {
                if (i + j <= 3) {
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
            //printf(" x : %d, y : %d\n",mouse_x,mouse_y);
            if(collisionCercle(mouse_x, mouse_y, map, i, j,width) == true ){
                al_draw_filled_triangle(map[i][j].x - scalex, map[i][j].y, map[i][j].x, map[i][j].y + scaley, map[i][j].x, map[i][j].y -
                                                                                                                           scaley, black);
                al_draw_filled_triangle(map[i][j].x + scalex, map[i][j].y, map[i][j].x, map[i][j].y + scaley, map[i][j].x, map[i][j].y -
                                                                                                                           scaley, black);

                if(map[0][0].t == 1 && joueur[joueurQuiJoue].dep == 0 && abs(joueur[joueurQuiJoue].xArrive-joueur[joueurQuiJoue].caseXDepart)+abs(joueur[joueurQuiJoue].yArrive-joueur[joueurQuiJoue].caseYDepart)<=3 && map[joueur[joueurQuiJoue].xArrive][joueur[joueurQuiJoue].yArrive].obstacle!=1){

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
                //printf(" CaseXa: %d , CaseYa: %d\n",joueur[0].caseXDepart,joueur[0].caseYDepart);
            }
        }
    }
}

void deplacementJoueur(Joueurs *joueur, Map map[30][30], int joueurQuiJoue, double scalex,double scaley, int* direction) {
    ALLEGRO_COLOR vert = al_map_rgba(93, 127, 51, 255);
    ALLEGRO_COLOR vert2 = al_map_rgba(93, 127, 51, 200);
    double depX = 0;
    double depY = 0;

    caseJoueur(joueur, map, joueurQuiJoue);

    if (abs(joueur[joueurQuiJoue].xArrive - joueur[joueurQuiJoue].caseXDepart) + abs(joueur[joueurQuiJoue].yArrive - joueur[joueurQuiJoue].caseYDepart) <= 4) {
        if (joueur[joueurQuiJoue].caseX > joueur[joueurQuiJoue].xArrive) {
            // Boucle sur x
            for (int i = 0; i < -joueur[joueurQuiJoue].xArrive + joueur[joueurQuiJoue].caseXDepart; i++) {
                al_draw_filled_triangle(map[joueur[joueurQuiJoue].caseXDepart - i][joueur[joueurQuiJoue].yArrive].x - scalex,
                                        map[joueur[joueurQuiJoue].caseXDepart - i][joueur[joueurQuiJoue].yArrive].y,
                                        map[joueur[joueurQuiJoue].caseXDepart - i][joueur[joueurQuiJoue].yArrive].x,
                                        map[joueur[joueurQuiJoue].caseXDepart - i][joueur[joueurQuiJoue].yArrive].y + scaley,
                                        map[joueur[joueurQuiJoue].caseXDepart - i][joueur[joueurQuiJoue].yArrive].x,
                                        map[joueur[joueurQuiJoue].caseXDepart - i][joueur[joueurQuiJoue].yArrive].y -
                                        scaley, vert);
                al_draw_filled_triangle(map[joueur[joueurQuiJoue].caseXDepart - i][joueur[joueurQuiJoue].yArrive].x + scalex,
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
                al_draw_filled_triangle(map[joueur[joueurQuiJoue].caseXDepart + i][joueur[joueurQuiJoue].yArrive].x - scalex,
                                        map[joueur[joueurQuiJoue].caseXDepart + i][joueur[joueurQuiJoue].yArrive].y,
                                        map[joueur[joueurQuiJoue].caseXDepart + i][joueur[joueurQuiJoue].yArrive].x,
                                        map[joueur[joueurQuiJoue].caseXDepart + i][joueur[joueurQuiJoue].yArrive].y + scaley,
                                        map[joueur[joueurQuiJoue].caseXDepart + i][joueur[joueurQuiJoue].yArrive].x,
                                        map[joueur[joueurQuiJoue].caseXDepart + i][joueur[joueurQuiJoue].yArrive].y -
                                        scaley, vert);
                al_draw_filled_triangle(map[joueur[joueurQuiJoue].caseXDepart + i][joueur[joueurQuiJoue].yArrive].x + scalex,
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

    if (joueur[joueurQuiJoue].caseX == joueur[joueurQuiJoue].xArrive && joueur[joueurQuiJoue].caseY == joueur[joueurQuiJoue].yArrive) {
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

        if (joueur[joueurQuiJoue].actif == 1 && joueur[joueurQuiJoue].dep == 1) {

        if (joueur[joueurQuiJoue].caseX < joueur[joueurQuiJoue].xArrive) {
            depX = 1;
            *direction = 0;
        }

        if (joueur[joueurQuiJoue].caseX > joueur[joueurQuiJoue].xArrive) {
            depX = -1;
            *direction = 1;
        }

        if (joueur[joueurQuiJoue].caseY < joueur[joueurQuiJoue].yArrive) {
            depY = scaley / scalex;
        }

        if (joueur[joueurQuiJoue].caseY > joueur[joueurQuiJoue].yArrive) {
            depY = -scaley / scalex;
        }

        if (joueur[joueurQuiJoue].caseX < joueur[joueurQuiJoue].xArrive && joueur[joueurQuiJoue].caseY == joueur[joueurQuiJoue].yArrive) {
            depX = 1;
            depY = -scaley / scalex;
            *direction = 0;
        }

        if (joueur[joueurQuiJoue].caseX == joueur[joueurQuiJoue].xArrive && joueur[joueurQuiJoue].caseY < joueur[joueurQuiJoue].yArrive) {
            depX = 1;
            depY = scaley / scalex;
            *direction = 0;
        }

        if (joueur[joueurQuiJoue].caseX > joueur[joueurQuiJoue].xArrive && joueur[joueurQuiJoue].caseY == joueur[joueurQuiJoue].yArrive) {
            depX = -1;
            depY = scaley / scalex;
            *direction = 1;
        }

        if (joueur[joueurQuiJoue].caseX == joueur[joueurQuiJoue].xArrive && joueur[joueurQuiJoue].caseY > joueur[joueurQuiJoue].yArrive) {
            depX = -1;
            depY = -scaley / scalex;
            *direction = 1;
        }

        caseJoueur(joueur, map, joueurQuiJoue);

        joueur[joueurQuiJoue].y = joueur[joueurQuiJoue].y + depY;
        joueur[joueurQuiJoue].x = joueur[joueurQuiJoue].x + depX;


        if (joueur[joueurQuiJoue].caseX == joueur[joueurQuiJoue].xArrive && joueur[joueurQuiJoue].caseY == joueur[joueurQuiJoue].yArrive) {
            joueur[joueurQuiJoue].dep = 0;
            joueur[joueurQuiJoue].quelAnimation = RESPIRATION ;
            joueur[joueurQuiJoue].caseXDepart = joueur[joueurQuiJoue].caseX;
            joueur[joueurQuiJoue].caseYDepart = joueur[joueurQuiJoue].caseY;
        }
    }
}



void dessinerQuadrillage(double  width, double height,double scalex,double scaley,ALLEGRO_COLOR black){
    for (int i = 0; i < mapX+1; i++) {
        al_draw_line(i * scalex+50, height/1.95 - i * scaley, width/2.25+i*scalex +50 , height - i * scaley, black, 2);
    }
    for (int i=0;i<mapY+1;i++){
        al_draw_line(width/1.8+i*scalex+50,i*scaley,i*scalex+50,height/1.95+scaley*i, black,2);
    }
}



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
        al_draw_text(gameFont, al_map_rgb(100, 100, 100), 73 * ecran.width / 288, 83 * ecran.height / 90,
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
        al_draw_text(gameFont, al_map_rgb(100, 100, 100), 73 * ecran.width / 288, 83 * ecran.height / 90,
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
        al_draw_text(gameFont, al_map_rgb(100, 100, 100), 73 * ecran.width / 288, 83 * ecran.height / 90,
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
        al_draw_text(gameFont, al_map_rgb(100, 100, 100), 73 * ecran.width / 288, 83 * ecran.height / 90,
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
        al_draw_text(gameFont, al_map_rgb(100, 100, 100), 73 * ecran.width / 288, 83 * ecran.height / 90,
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
        al_draw_text(gameFont, al_map_rgb(100, 100, 100), 73 * ecran.width / 288, 83 * ecran.height / 90,
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
        al_draw_text(gameFont, al_map_rgb(100, 100, 100), 73 * ecran.width / 288, 83 * ecran.height / 90,
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
        al_draw_text(gameFont, al_map_rgb(100, 100, 100), 73 * ecran.width / 288, 83 * ecran.height / 90,
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
        al_draw_text(gameFont, al_map_rgb(100, 100, 100), 73 * ecran.width / 288, 83 * ecran.height / 90,
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
        al_draw_text(gameFont, al_map_rgb(100, 100, 100), 73 * ecran.width / 288, 83 * ecran.height / 90,
                     ALLEGRO_ALIGN_CENTER, "SORT RECULER ADVERSAIRE");
    } else {
        al_draw_scaled_bitmap(jeu.classes[PACMAN].sortADisposition[RECULERADVERSAIRE].iconeSort, 0, 0, 2000, 2000,
                              109 * ecran.width / 144, ecran.height / 1.125, 43 * ecran.width / 96,
                              43 * ecran.height / 60, 0);
    }

    if ((float) ecran.mouse_x < 427 * ecran.width / 576 && ecran.mouse_x > 409 * ecran.width / 576 &&(float) ecran.mouse_y < 353 * ecran.height / 360 && ecran.mouse_y > 9 * ecran.height / 10) {
        al_draw_scaled_bitmap(jeu.classes[PACMAN].sortADisposition[SORTDEFENCE].iconeSort, 0, 0, 2000, 2000,ecran.width / 1.44, 79 * ecran.height / 90, 15 * ecran.width / 32, 3 * ecran.height / 4,0);
        al_draw_text(gameFont, al_map_rgb(100, 100, 100), 73 * ecran.width / 288, 83 * ecran.height / 90,
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
        al_draw_text(gameFont, al_map_rgb(100, 100, 100), 73 * ecran.width / 288, 83 * ecran.height / 90,
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
        al_draw_text(gameFont, al_map_rgb(100, 100, 100), 73 * ecran.width / 288, 83 * ecran.height / 90,
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
        al_draw_text(gameFont, al_map_rgb(100, 100, 100), 73 * ecran.width / 288, 83 * ecran.height / 90,
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
        al_draw_text(gameFont, al_map_rgb(100, 100, 100), 73 * ecran.width / 288, 83 * ecran.height / 90,
                     ALLEGRO_ALIGN_CENTER, "SORT SAUT");
    } else {
        al_draw_scaled_bitmap(jeu.classes[DONKEY_KONG].sortADisposition[SAUT].iconeSort, 0, 0, 2000, 2000,
                              ecran.width / 1.2, 7 * ecran.height / 8, 67 * ecran.width / 144, 67 * ecran.height / 90,
                              0);
    }
}




void sortEnFonctionDesClasses(ALLEGRO_FONT* gameFont, Jeux jeu, InfoEcran ecran, int joueurQuiJoue){

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


int sortChoisi (InfoEcran ecran) {
    int positionSort = 0;
    //573 --> 191

    if ((float) ecran.mouse_x < 121*ecran.width/160 && ecran.mouse_x > 1987*ecran.width/2880 && (float) ecran.mouse_y < 23*ecran.height/24 && ecran.mouse_y > 79*ecran.height/90) {
        positionSort = 0;
    }
    if ((float) ecran.mouse_x < 2369*ecran.width/2880 && ecran.mouse_x > 121*ecran.width/160 && (float) ecran.mouse_y < 23*ecran.height/24 && ecran.mouse_y > 79*ecran.height/90) {
        positionSort = 1;
    }
    if ((float) ecran.mouse_x < 65*ecran.width/72 && ecran.mouse_x > ecran.width/1.2 && (float) ecran.mouse_y < 23*ecran.height/24 && ecran.mouse_y > 79*ecran.height/90) {
        positionSort = 2;
    }
    return positionSort;
}



void actionSortFLAMME (Jeux jeu, int joueurQuiJoue, InfoEcran ecran){
    int PASort = 4;
    int possibiliteDeJouer = 0;
    //possibiliteDeJouer = verifierPADuJoueur(jeu, joueurQuiJoue, jeu.joueur[joueurQuiJoue].PA, PASort);

   // if (possibiliteDeJouer == 0){
        for(int i = 0; i < jeu.info.nbJoueur; i++){
            if (i != jeu.info.joueurQuiJoue){
                if(((jeu.joueur[i].caseX == jeu.joueur[joueurQuiJoue].caseX + 4) && (jeu.joueur[i].caseY == jeu.joueur[joueurQuiJoue].caseY))
                   || ((jeu.joueur[i].caseX == jeu.joueur[joueurQuiJoue].caseX - 4) && (jeu.joueur[i].caseY == jeu.joueur[joueurQuiJoue].caseY))
                   || ((jeu.joueur[i].caseY == jeu.joueur[joueurQuiJoue].caseY + 4 ) && (jeu.joueur[i].caseX == jeu.joueur[joueurQuiJoue].caseX))
                   || ((jeu.joueur[i].caseY == jeu.joueur[joueurQuiJoue].caseY - 4) && (jeu.joueur[i].caseX == jeu.joueur[joueurQuiJoue].caseX))){
                    jeu.joueur[i].PV -= 40;
                }
            }
        }
        jeu.joueur[joueurQuiJoue].PA -= PASort;
   // }
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
                if(((jeu.joueur[i].caseX == jeu.joueur[joueurQuiJoue].caseX +1) && (jeu.joueur[i].caseY == jeu.joueur[joueurQuiJoue].caseY))
                   || ((jeu.joueur[i].caseX == jeu.joueur[joueurQuiJoue].caseX - 1) && (jeu.joueur[i].caseY == jeu.joueur[joueurQuiJoue].caseY))
                   || ((jeu.joueur[i].caseY == jeu.joueur[joueurQuiJoue].caseY +1 ) && (jeu.joueur[i].caseX == jeu.joueur[joueurQuiJoue].caseX))
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

void initialiserSortEnFonctionDeLeurPosition(Jeux jeu, int joueurQuiJoue, InfoEcran ecran, int sort, Map map[30][30]) {
    if (sort == 0) {
        if (jeu.joueur[joueurQuiJoue].classe == KIRBY) {
            jeu.joueur[joueurQuiJoue].sortAppuye = 0;
            actionSortCOUPDEPIED(jeu, joueurQuiJoue, map, ecran);
        }
        if (jeu.joueur[joueurQuiJoue].classe == MARIO) {
            jeu.joueur[joueurQuiJoue].sortAppuye = 0;
            actionSortFLAMME(jeu, joueurQuiJoue, ecran);
        }
        if (jeu.joueur[joueurQuiJoue].classe == PACMAN) {
            jeu.joueur[joueurQuiJoue].sortAppuye = 0;
            //mettre la fonction du sort
            // sort defense
        }
        if (jeu.joueur[joueurQuiJoue].classe == DONKEY_KONG) {
            jeu.joueur[joueurQuiJoue].sortAppuye = 0;
            actionSortPOINGGANT (jeu, joueurQuiJoue);
        }
        if (jeu.joueur[joueurQuiJoue].classe == PEACH) {
            jeu.joueur[joueurQuiJoue].sortAppuye = 0;
            actionSortPIEDPEACH(jeu, joueurQuiJoue, ecran);
        }
    }
    if (sort == 1) {
        if (jeu.joueur[joueurQuiJoue].classe == KIRBY) {
            jeu.joueur[joueurQuiJoue].sortAppuye = 1;
            actionSortPOING(jeu, joueurQuiJoue, ecran);
        }
        if (jeu.joueur[joueurQuiJoue].classe == MARIO) {
            jeu.joueur[joueurQuiJoue].sortAppuye = 1;
            actionSortCOUPCORONA (jeu, joueurQuiJoue);
        }
        if (jeu.joueur[joueurQuiJoue].classe == PACMAN) {
            jeu.joueur[joueurQuiJoue].sortAppuye = 1;
            actionSortRECULERADVERSAIRE (jeu, joueurQuiJoue, map);
        }
        if (jeu.joueur[joueurQuiJoue].classe == DONKEY_KONG) {
            jeu.joueur[joueurQuiJoue].sortAppuye = 1;
            actionSortMORTEL (jeu, joueurQuiJoue);
        }
        if (jeu.joueur[joueurQuiJoue].classe == PEACH) {
            jeu.joueur[joueurQuiJoue].sortAppuye = 1;
            actionSortFLEUR (jeu, joueurQuiJoue);
        }
    }
    if (sort == 2){
        if (jeu.joueur[joueurQuiJoue].classe == KIRBY){
            jeu.joueur[joueurQuiJoue].sortAppuye = 2;
            actionSortFLAMME (jeu, joueurQuiJoue, ecran);
        }
        if (jeu.joueur[joueurQuiJoue].classe == MARIO){
            jeu.joueur[joueurQuiJoue].sortAppuye = 2;
            actionSortPOING2 (jeu, joueurQuiJoue);
        }
        if (jeu.joueur[joueurQuiJoue].classe == PACMAN){
            jeu.joueur[joueurQuiJoue].sortAppuye = 2;
            actionSortFLAMME (jeu, joueurQuiJoue, ecran);
        }
        if (jeu.joueur[joueurQuiJoue].classe == DONKEY_KONG){
            jeu.joueur[joueurQuiJoue].sortAppuye = 2;
            actionSortSAUTDONKEYKONG (jeu, joueurQuiJoue, ecran.mouse_x, ecran.mouse_y, map, ecran);
        }
        if (jeu.joueur[joueurQuiJoue].classe == PEACH){
            jeu.joueur[joueurQuiJoue].sortAppuye = 2;
            actionSortSOIN (jeu, joueurQuiJoue);
        }
    }
}

void realisationDesSorts ();