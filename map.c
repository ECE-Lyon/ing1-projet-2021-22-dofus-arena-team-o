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

void drawSort( ALLEGRO_FONT* gameFont, Jeux jeu, InfoEcran ecran, ALLEGRO_BITMAP* barreSort) {  //il faudra ajouter dans les parametres la var du nbJoueur pour la boucle de for


    ///////////////   AFFICHACHAGE  BARRE SORTS //////////////
    al_draw_scaled_bitmap(barreSort, 0, 0, 1000, 2000, ecran.width/1.6, 79*ecran.height/90, ecran.width/1.92 ,269*ecran.height/360,  0) ;
    al_draw_scaled_bitmap(barreSort, 0, 0, 1000, 2000, 0, 79*ecran.height/90, ecran.width/1.92 ,269*ecran.height/360,  0) ;

///KIRBY
/*
    if ((float) ecran.mouse_x < 235*ecran.width/288 && ecran.mouse_x > 73*ecran.width/96 && (float) ecran.mouse_y < 59*ecran.height/60 && ecran.mouse_y > ecran.height/1.125 ){
        al_draw_scaled_bitmap(jeu.classes[KIRBY].sortADisposition[POING].iconeSort, 0, 0, 2000, 2000, 109*ecran.width/144, ecran.height/1.125, 67*ecran.width/144 ,67*ecran.height/90,  0) ;
        al_draw_text(gameFont, al_map_rgb( 100, 100, 100), 73*ecran.width/288, 83*ecran.height/90 , ALLEGRO_ALIGN_CENTER, "COUP DE POING QUI FAIT SUPER MAL") ;
    } else { al_draw_scaled_bitmap(jeu.classes[KIRBY].sortADisposition[POING].iconeSort, 0, 0, 2000, 2000, 109*ecran.width/144, ecran.height/1.125, 43*ecran.width/96 ,43*ecran.height/60,  0) ;}

    if ((float) ecran.mouse_x < 427*ecran.width/576 && ecran.mouse_x > 409*ecran.width/576 && (float) ecran.mouse_y < 353*ecran.height/360 && ecran.mouse_y > 9*ecran.height/10 ){
        al_draw_scaled_bitmap(jeu.classes[KIRBY].sortADisposition[COUPDEPIED].iconeSort, 0, 0, 2000, 2000, ecran.width/1.44, 79*ecran.height/90, 47*ecran.width/96 ,47*ecran.height/60,  0) ;
        al_draw_text(gameFont, al_map_rgb( 100, 100, 100), 73*ecran.width/288, 83*ecran.height/90 , ALLEGRO_ALIGN_CENTER, "COUP DE PIED DE L'ENFER ") ;
    } else { al_draw_scaled_bitmap(jeu.classes[KIRBY].sortADisposition[COUPDEPIED].iconeSort, 0, 0, 2000, 2000, ecran.width/1.44, 79*ecran.height/90, 17*ecran.width/36 ,34*ecran.height/45,  0) ;}

    if ((float) ecran.mouse_x < ecran.width/1.152 && ecran.mouse_x > 119*ecran.width/144 && (float) ecran.mouse_y < 353*ecran.height/360 && ecran.mouse_y > 9*ecran.height/10 ){
        al_draw_scaled_bitmap(jeu.classes[KIRBY].sortADisposition[FLAMME].iconeSort, 0, 0, 2000, 2000, 239*ecran.width/288, 319*ecran.height/360, 85*ecran.width/288 ,17*ecran.height/36,  0) ;
        al_draw_text(gameFont, al_map_rgb( 100, 100, 100), 73*ecran.width/288, 83*ecran.height/90 , ALLEGRO_ALIGN_CENTER, "SORT FLEMME - ENLEVEZ UN POINT DE VIE A VOTRE ADVERSAIRE ") ;
    } else { al_draw_scaled_bitmap(jeu.classes[KIRBY].sortADisposition[FLAMME].iconeSort, 0, 0, 2000, 2000, 239*ecran.width/288, 319*ecran.height/360, ecran.width/3.6 ,ecran.height/2.25,  0) ;}
*/

///MARIO
/*
    if ((float) ecran.mouse_x < 119*ecran.width/144 && ecran.mouse_x >  73*ecran.width/96 && (float) ecran.mouse_y < 59*ecran.height/60 && ecran.mouse_y > ecran.height/1.125 ){
        al_draw_scaled_bitmap(jeu.classes[MARIO].sortADisposition[CORONA].iconeSort, 0, 0, 2000, 2000, 73*ecran.width/96, 79*ecran.height/90, 127*ecran.width/288 ,127*ecran.height/180,  0) ;
        al_draw_text(gameFont, al_map_rgb( 100, 100, 100), 73*ecran.width/288, 83*ecran.height/90 , ALLEGRO_ALIGN_CENTER, "VIRUS CORONA (15 00 000 morts)") ;
    } else { al_draw_scaled_bitmap(jeu.classes[MARIO].sortADisposition[CORONA].iconeSort, 0, 0, 2000, 2000, 73*ecran.width/96, 79*ecran.height/90, 61*ecran.width/144 ,61*ecran.height/90,  0) ;}

    if ((float) ecran.mouse_x < 427*ecran.width/576 && ecran.mouse_x > 409*ecran.width/576 && (float) ecran.mouse_y < 353*ecran.height/360 && ecran.mouse_y > 9*ecran.height/10 ){
        al_draw_scaled_bitmap(jeu.classes[MARIO].sortADisposition[FLAMME].iconeSort, 0, 0, 2000, 2000, ecran.width/1.44, 319*ecran.height/360, 85*ecran.width/288 ,17*ecran.height/36,  0) ;
        al_draw_text(gameFont, al_map_rgb( 100, 100, 100), 73*ecran.width/288, 83*ecran.height/90 , ALLEGRO_ALIGN_CENTER, "FLAMME : BRULER VOS ADVERSAIRES") ;
    } else { al_draw_scaled_bitmap(jeu.classes[MARIO].sortADisposition[FLAMME].iconeSort, 0, 0, 2000, 2000, ecran.width/1.44, 319*ecran.height/360, ecran.width/3.6 ,ecran.height/2.25,  0) ;}

    if ((float) ecran.mouse_x < 253*ecran.width/288 && ecran.mouse_x > 161*ecran.width/192 && (float) ecran.mouse_y < 353*ecran.height/360 && ecran.mouse_y > 9*ecran.height/10 ){
        al_draw_scaled_bitmap(jeu.classes[MARIO].sortADisposition[POING2].iconeSort, 0, 0, 2000, 2000, 161*ecran.width/192,  319*ecran.height/360, 113*ecran.width/288 ,113*ecran.height/180,  0) ;
        al_draw_text(gameFont, al_map_rgb( 100, 100, 100), 73*ecran.width/288, 83*ecran.height/90 , ALLEGRO_ALIGN_CENTER, " COUP DE POING ") ;
    } else { al_draw_scaled_bitmap(jeu.classes[MARIO].sortADisposition[POING2].iconeSort, 0, 0, 2000, 2000, 161*ecran.width/192,  319*ecran.height/360, 3*ecran.width/8 ,3*ecran.height/5,  0) ;}
*/

///PEACH
/*
    if ((float) ecran.mouse_x < 235*ecran.width/288 && ecran.mouse_x > 73*ecran.width/96 && (float) ecran.mouse_y < 59*ecran.height/60 && ecran.mouse_y > ecran.height/1.125 ){
        al_draw_scaled_bitmap(jeu.classes[PEACH].sortADisposition[SORTFLEUR].iconeSort, 0, 0, 2000, 2000, 55*ecran.width/72, 809*ecran.height/900, 29*ecran.width/72 ,29*ecran.height/45,  0) ;
        al_draw_text(gameFont, al_map_rgb( 100, 100, 100), 73*ecran.width/288, 83*ecran.height/90 , ALLEGRO_ALIGN_CENTER, "Attaque de FLEURS !!!") ;
    } else { al_draw_scaled_bitmap(jeu.classes[PEACH].sortADisposition[SORTFLEUR].iconeSort, 0, 0, 2000, 2000, 55*ecran.width/72, 809*ecran.height/900, 37*ecran.width/96 ,37*ecran.height/60,  0) ;}

    if ((float) ecran.mouse_x < 427*ecran.width/576 && ecran.mouse_x > 409*ecran.width/576 && (float) ecran.mouse_y < 353*ecran.height/360 && ecran.mouse_y > 9*ecran.height/10 ){
        al_draw_scaled_bitmap(jeu.classes[PEACH].sortADisposition[COUPDEPIED].iconeSort, 0, 0, 2000, 2000, ecran.width/1.44, 79*ecran.height/90, 47*ecran.width/96 ,47*ecran.height/60,  0) ;
        al_draw_text(gameFont, al_map_rgb( 100, 100, 100), 73*ecran.width/288, 83*ecran.height/90 , ALLEGRO_ALIGN_CENTER, "COUP DE PIED DE L'ENFER ") ;
    } else { al_draw_scaled_bitmap(jeu.classes[PEACH].sortADisposition[COUPDEPIED].iconeSort, 0, 0, 2000, 2000, ecran.width/1.44, 79*ecran.height/90, 17*ecran.width/36 ,34*ecran.height/45,  0) ;}

    if ((float) ecran.mouse_x < 253*ecran.width/288 && ecran.mouse_x > 161*ecran.width/192 && (float) ecran.mouse_y < 353*ecran.height/360 && ecran.mouse_y > 9*ecran.height/10 ){
        al_draw_scaled_bitmap(jeu.classes[PEACH].sortADisposition[SORTSOIN].iconeSort, 0, 0, 2000, 2000, 161*ecran.width/192, 323*ecran.height/360, 113*ecran.width/288 ,113*ecran.height/180,  0) ;
        al_draw_text(gameFont, al_map_rgb( 100, 100, 100), 73*ecran.width/288, 83*ecran.height/90 , ALLEGRO_ALIGN_CENTER, " Et si on mettait un pansements sur vos bobos ") ;
    } else { al_draw_scaled_bitmap(jeu.classes[PEACH].sortADisposition[SORTSOIN].iconeSort, 0, 0, 2000, 2000, 161*ecran.width/192, 323*ecran.height/360, 3*ecran.width/8 ,3*ecran.height/5,  0) ;}
*/

///PACMAN
/*
    if ((float) ecran.mouse_x < 235*ecran.width/288 && ecran.mouse_x > 73*ecran.width/96 && (float) ecran.mouse_y < 59*ecran.height/60 && ecran.mouse_y >  ecran.height/1.125 ){
        al_draw_scaled_bitmap(jeu.classes[PACMAN].sortADisposition[RECULERADVERSAIRE].iconeSort, 0, 0, 2000, 2000, 109*ecran.width/144,  ecran.height/1.125, 67*ecran.width/144 ,67*ecran.height/90,  0) ;
        al_draw_text(gameFont, al_map_rgb( 100, 100, 100), 73*ecran.width/288, 83*ecran.height/90 , ALLEGRO_ALIGN_CENTER, "COUP DE POING QUI FAIT VOYAGER SON ADVERSAIRE (CARREMENT)") ;
    } else { al_draw_scaled_bitmap(jeu.classes[PACMAN].sortADisposition[RECULERADVERSAIRE].iconeSort, 0, 0, 2000, 2000, 109*ecran.width/144, ecran.height/1.125, 43*ecran.width/96 ,43*ecran.height/60,  0) ;}

    if ((float) ecran.mouse_x < 427*ecran.width/576 && ecran.mouse_x > 409*ecran.width/576 && (float) ecran.mouse_y < 353*ecran.height/360 && ecran.mouse_y > 9*ecran.height/10  ){
        al_draw_scaled_bitmap(jeu.classes[PACMAN].sortADisposition[SORTDEFENCE].iconeSort, 0, 0, 2000, 2000, ecran.width/1.44, 79*ecran.height/90, 15*ecran.width/32 ,3*ecran.height/4,  0) ;
        al_draw_text(gameFont, al_map_rgb( 100, 100, 100), 73*ecran.width/288, 83*ecran.height/90 , ALLEGRO_ALIGN_CENTER, "SORT DEFENCE ") ;
    } else { al_draw_scaled_bitmap(jeu.classes[PACMAN].sortADisposition[SORTDEFENCE].iconeSort, 0, 0, 2000, 2000, ecran.width/1.44, 79*ecran.height/90, 65*ecran.width/144 ,13*ecran.height/18,  0) ;}

    if ((float) ecran.mouse_x < ecran.width/1.152 && ecran.mouse_x > 119*ecran.width/144 && (float) ecran.mouse_y < 353*ecran.height/360 && ecran.mouse_y > 9*ecran.height/10 ){
        al_draw_scaled_bitmap(jeu.classes[PACMAN].sortADisposition[FLAMME].iconeSort, 0, 0, 2000, 2000, 239*ecran.width/288, 319*ecran.height/360, 85*ecran.width/288 ,17*ecran.height/36,  0) ;
        al_draw_text(gameFont, al_map_rgb( 100, 100, 100), 73*ecran.width/288, 83*ecran.height/90 , ALLEGRO_ALIGN_CENTER, "SORT FLEMME - ENLEVEZ UN POINT DE VIE A VOTRE ADVERSAIRE ") ;
    } else { al_draw_scaled_bitmap(jeu.classes[PACMAN].sortADisposition[FLAMME].iconeSort, 0, 0, 2000, 2000, 239*ecran.width/288, 319*ecran.height/360, ecran.width/3.6 ,ecran.height/2.25,  0) ;}
 */

/// DONKEY KONG

    if ((float) ecran.mouse_x < 235*ecran.width/288 && ecran.mouse_x > 73*ecran.width/96 && (float) ecran.mouse_y < 59*ecran.height/60 && ecran.mouse_y > ecran.height/1.125 ){
        al_draw_scaled_bitmap(jeu.classes[DONKEY_KONG].sortADisposition[MORTEL].iconeSort, 0, 0, 2000, 2000, 242*ecran.width/320, 53*ecran.height/60, 131*ecran.width/288 ,131*ecran.height/180,  0) ;
        al_draw_text(gameFont, al_map_rgb( 100, 100, 100), 73*ecran.width/288, 83*ecran.height/90 , ALLEGRO_ALIGN_CENTER, "COUP DE POING QUI FAIT VOYAGER SON ADVERSAIRE (CARREMENT)") ;
    } else { al_draw_scaled_bitmap(jeu.classes[DONKEY_KONG].sortADisposition[MORTEL].iconeSort, 0, 0, 2000, 2000, 242*ecran.width/320, 53*ecran.height/60, 127*ecran.width/288 ,127*ecran.height/180,  0) ;}

    if ((float) ecran.mouse_x < 427*ecran.width/576 && ecran.mouse_x > 409*ecran.width/576 && (float) ecran.mouse_y < 353*ecran.height/360 && ecran.mouse_y > 9*ecran.height/10 ){
        al_draw_scaled_bitmap(jeu.classes[DONKEY_KONG].sortADisposition[POINGGANT].iconeSort, 0, 0, 2000, 2000, ecran.width/1.44, ecran.height/1.125, 15*ecran.width/32 ,3*ecran.height/4,  0) ;
        al_draw_text(gameFont, al_map_rgb( 100, 100, 100), 73*ecran.width/288, 83*ecran.height/90 , ALLEGRO_ALIGN_CENTER, "SORT DEFENCE ") ;
    } else { al_draw_scaled_bitmap(jeu.classes[DONKEY_KONG].sortADisposition[POINGGANT].iconeSort, 0, 0, 2000, 2000, ecran.width/1.44, ecran.height/1.125, 65*ecran.width/144 ,13*ecran.height/18,  0) ;}

    if ((float) ecran.mouse_x < 85*ecran.width/96 && ecran.mouse_x > 799*ecran.width/960 && (float) ecran.mouse_y < 353*ecran.height/360 && ecran.mouse_y > 9*ecran.height/10 ){
        al_draw_scaled_bitmap(jeu.classes[DONKEY_KONG].sortADisposition[SAUT].iconeSort, 0, 0, 2000, 2000, ecran.width/1.2, 7*ecran.height/8, 139*ecran.width/288 ,139*ecran.height/180,  0) ;
        al_draw_text(gameFont, al_map_rgb( 100, 100, 100), 73*ecran.width/288, 83*ecran.height/90 , ALLEGRO_ALIGN_CENTER, "SORT FLEMME - ENLEVEZ UN POINT DE VIE A VOTRE ADVERSAIRE ") ;
    } else { al_draw_scaled_bitmap(jeu.classes[DONKEY_KONG].sortADisposition[SAUT].iconeSort, 0, 0, 2000, 2000, ecran.width/1.2, 7*ecran.height/8, 67*ecran.width/144 ,67*ecran.height/90,  0) ;}

/*
    int nbJoueur = 3;  // o prend par exemple 3 joueurs qui jouent
    for (int i = nbJoueur; i < nbJoueur; i++) {
        al_draw_scaled_bitmap(jeu.classes[KIRBY].image, 0, 0, 800, 800, 500, 1000, 1000, 900, 0);

        if ((float) ecran.mouse_x < 2245 && ecran.mouse_x > 2130 && (float) ecran.mouse_y < 1770 &&
            ecran.mouse_y > 1620) {
            al_draw_scaled_bitmap(jeu.classes[i].sortADisposition[STOP].iconeSort, 0, 0, 2000, 2000, 2079, 1620, 850,
                                  850, 0);
            al_draw_text(gameFont, al_map_rgb(100, 100, 100), 730, 1660, ALLEGRO_ALIGN_CENTER,
                         "SORT STOP - empechez votre adversaire de jouer au prochain tour ");
        } else {
            al_draw_scaled_bitmap(jeu.classes[i].sortADisposition[STOP].iconeSort, 0, 0, 2000, 2000, 2079, 1620, 800, 800,
                                  0);
        }
    }*/

}
