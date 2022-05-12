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


            //al_draw_filled_triangle(map[i][j].x - scalex, map[i][j].y, map[i][j].x, map[i][j].y + scaley, map[i][j].x, map[i][j].y -scaley, white);
            //al_draw_filled_triangle(map[i][j].x + scalex, map[i][j].y, map[i][j].x, map[i][j].y + scaley, map[i][j].x, map[i][j].y -scaley, white);
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

        if (joueur[0].caseY<joueur[0].yArrive ){
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

        if (joueur[0].caseX < joueur[0].xArrive && joueur[0].caseY == joueur[0].yArrive ){
            depX = 1;
            depY = -scaley/scalex;
        }

        if (joueur[0].caseX == joueur[0].xArrive && joueur[0].caseY < joueur[0].yArrive ){
            depX = 1;
            depY = scaley/scalex;
        }

        if (joueur[0].caseX > joueur[0].xArrive && joueur[0].caseY == joueur[0].yArrive ){
            depX = -1;
            depY = scaley/scalex;
        }

        if (joueur[0].caseX == joueur[0].xArrive && joueur[0].caseY > joueur[0].yArrive ){
            depX = -1;
            depY = -scaley/scalex;
        }

        caseJoueur(joueur,map);

        joueur[0].y = joueur[0].y + depY;
        joueur[0].x = joueur[0].x + depX;


        if (joueur[0].caseX == joueur[0].xArrive && joueur[0].caseY==joueur[0].yArrive){joueur[0].dep=0;joueur[0].caseXDepart= joueur[0].caseX;
            joueur[0].caseYDepart= joueur[0].caseY;}
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

void drawSort( ALLEGRO_FONT* gameFont, Jeux jeu, InfoEcran ecran){  //il faudra ajouter dans les parametres la var du nbJoueur pour la boucle de for


    ///////////////   AFFICHACHAGE  BARRE SORTS //////////////
    al_draw_scaled_bitmap(jeu.classes->sortADisposition[BARRE].iconeSort, 0, 0, 1000, 2000, 85*ecran.width/144, 79*ecran.height/90, 95*ecran.width/144 ,269*ecran.height/360,  0) ;
    al_draw_scaled_bitmap(jeu.classes->sortADisposition[PV].iconeSort, 0, 0, 1000, 2000, 55*ecran.width/72, 0, ecran.width/1.8 ,13*ecran.height/18,  0) ;

    ///////// On prend pour l'instant en compte que la Classe KIRBY Pour Exemple ///////////////  pck nsm ça marche pas cette merde

    // il faut modifier la police, l'emplacement du texte
    if ((float) ecran.mouse_x < 449*ecran.width/576 && ecran.mouse_x > 71*ecran.width/96 && (float) ecran.mouse_y < 59*ecran.height/60 && ecran.mouse_y > 9*ecran.height/10 ){
        al_draw_scaled_bitmap(jeu.classes->sortADisposition[STOP].iconeSort, 0, 0, 2000, 2000, 231*ecran.width/320, 9*ecran.height/10, 85*ecran.width/288 ,17*ecran.height/36,  0) ;
        al_draw_text(gameFont, al_map_rgb( 100, 100, 100), 73*ecran.width/288, 83*ecran.height/90 , ALLEGRO_ALIGN_CENTER, "SORT STOP - empechez votre adversaire de jouer au prochain tour ") ;
    } else { al_draw_scaled_bitmap(jeu.classes->sortADisposition[STOP].iconeSort, 0, 0, 2000, 2000, 231*ecran.width/320, 9*ecran.height/10, ecran.width/3.6 ,ecran.height/2.25,  0) ;}

    if ((float) ecran.mouse_x < 413*ecran.width/576 && ecran.mouse_x > 49*ecran.width/72 && (float) ecran.mouse_y < 353*ecran.height/360 && ecran.mouse_y > 9*ecran.height/10 ){
        al_draw_scaled_bitmap(jeu.classes->sortADisposition[SPECIAL].iconeSort, 0, 0, 2000, 2000, 95*ecran.width/144, 161*ecran.height/180, 193*ecran.width/576 ,193*ecran.height/360,  0) ;
        al_draw_text(gameFont, al_map_rgb( 100, 100, 100), 73*ecran.width/288, 83*ecran.height/90 , ALLEGRO_ALIGN_CENTER, "SORT SPECIAL - TESTEZ LE SUR VOS ADVERSAIRES ") ;
    } else { al_draw_scaled_bitmap(jeu.classes->sortADisposition[SPECIAL].iconeSort, 0, 0, 2000, 2000, 95*ecran.width/144, 161*ecran.height/180, 61*ecran.width/192 ,61*ecran.height/120,  0) ;}

    if ((float) ecran.mouse_x < ecran.width/1.2 && ecran.mouse_x > 19*ecran.width/24 && (float) ecran.mouse_y < 353*ecran.height/360 && ecran.mouse_y > 9*ecran.height/10 ){
        al_draw_scaled_bitmap(jeu.classes->sortADisposition[FLAMME].iconeSort, 0, 0, 2000, 2000, 451*ecran.width/576, 319*ecran.height/360, 221*ecran.width/720 ,221*ecran.height/450,  0) ;
        al_draw_text(gameFont, al_map_rgb( 100, 100, 100), 73*ecran.width/288, 83*ecran.height/90 , ALLEGRO_ALIGN_CENTER, "SORT FLAMME - ENLEVEZ UN POINT DE VIE A VOTRE ADVERSAIRE ") ;
    } else { al_draw_scaled_bitmap(jeu.classes->sortADisposition[FLAMME].iconeSort, 0, 0, 2000, 2000, 451*ecran.width/576, 319*ecran.height/360, 139*ecran.width/480 ,139*ecran.height/300,  0) ;}

    if ((float) ecran.mouse_x < 515*ecran.width/576 && ecran.mouse_x > 245*ecran.width/288 && (float) ecran.mouse_y < 353*ecran.height/360&& ecran.mouse_y > 9*ecran.height/10) {
        al_draw_scaled_bitmap(jeu.classes->sortADisposition[RALENTIR].iconeSort, 0, 0, 2000, 2000, 27*ecran.width/32, ecran.height/1.125, 889*ecran.width/2880 ,889*ecran.height/1800,  0);
        al_draw_text(gameFont, al_map_rgb( 100, 100, 100), 73*ecran.width/288, 83*ecran.height/90 , ALLEGRO_ALIGN_CENTER, "SORT RALENTIR - RALENTIR SON ADVERSAIRE ") ;
    }else { al_draw_scaled_bitmap(jeu.classes->sortADisposition[RALENTIR].iconeSort, 0, 0, 2000, 2000, 27*ecran.width/32, ecran.height/1.125, 839*ecran.width/2880 ,839*ecran.height/1800,  0) ;}

    if ((float) ecran.mouse_x < 271*ecran.width/288 && ecran.mouse_x > 521*ecran.width/576 && (float) ecran.mouse_y < 353*ecran.height/360 && ecran.mouse_y > 9*ecran.height/10 ) {
        al_draw_scaled_bitmap(jeu.classes->sortADisposition[FATAL].iconeSort, 0, 0, 2000, 2000, 1283*ecran.width/1440, 323*ecran.height/360, 31*ecran.width/96 ,31*ecran.height/60,  0) ;
        al_draw_text(gameFont, al_map_rgb(100, 100, 100), 73*ecran.width/288, 83*ecran.height/90, ALLEGRO_ALIGN_CENTER,
                     "SORT FATAL - ASSOMMEZ VOTRE ADVERSAIRE EN LUI ENLEVANT 3 POINT DE VIR D'UN COUP ");
    } else { al_draw_scaled_bitmap(jeu.classes->sortADisposition[FATAL].iconeSort, 0, 0, 2000, 2000, 1283*ecran.width/1440, 323*ecran.height/360, 11*ecran.width/36 ,22*ecran.height/45,  0) ;}




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
    }

}
