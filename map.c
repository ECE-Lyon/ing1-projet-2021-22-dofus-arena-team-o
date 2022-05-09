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
    double depX=0;
    double depY=0;
    //if (joueur[0].xArrive-joueur[0].caseXDepart>=4){joueur[0].xArrive=4+joueur[0].caseXDepart;}
    //if (joueur[0].yArrive-joueur[0].caseYDepart>=4){joueur[0].yArrive=4+joueur[0].caseYDepart;}
    //if (joueur[0].xArrive+joueur[0].yArrive-joueur[0].caseXDepart-joueur[0].caseYDepart>=4){joueur[0].yArrive=joueur[0].caseYDepart;joueur[0].xArrive=4+joueur[0].caseXDepart;}
    //if (joueur[0].yArrive>4+joueur[0].caseYDepart){joueur[0].xArrive=0;}

    caseJoueur(joueur,map);
    if (joueur[0].xArrive-joueur[0].caseXDepart+joueur[0].yArrive-joueur[0].caseYDepart<=4){
    if (joueur[0].dep==0) {
        if (joueur[0].caseX>joueur[0].xArrive){
            // Boucle sur x
            for (int i =0; i < joueur[0].xArrive; i++) {
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

        if (joueur[0].caseY<joueur[0].yArrive){
            // Boucle sur y
            for (int j = 0; j < joueur[0].yArrive; j++) {

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
        if (joueur[0].caseY>joueur[0].yArrive){
            // Boucle sur y
            for (int j = 0; j < joueur[0].yArrive;j++){

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



            if (joueur[0].caseY<joueur[0].yArrive){

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
        }

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

    }}


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

void drawSort( ALLEGRO_FONT* gameFont, Jeux jeu, InfoEcran ecran){  //il faudra ajouter dans les parametres la var du nbJoueur pour la boucle de for


    ///////////////   AFFICHACHAGE  BARRE SORTS //////////////
    al_draw_scaled_bitmap(jeu.classes->sortADisposition[BARRE].iconeSort, 0, 0, 1000, 2000, 1700, 1580, 1900 ,1345,  0) ;
    al_draw_scaled_bitmap(jeu.classes->sortADisposition[PV].iconeSort, 0, 0, 1000, 2000, 2200, 0, 1600 ,1300,  0) ;

    ///////// On prend pour l'instant en compte que la Classe KIRBY Pour Exemple ///////////////  pck nsm ça marche pas cette merde

    if ((float) ecran.mouse_x < 2245 && ecran.mouse_x > 2130 && (float) ecran.mouse_y < 1770 && ecran.mouse_y > 1620 ){
        al_draw_scaled_bitmap(jeu.classes->sortADisposition[STOP].iconeSort, 0, 0, 2000, 2000, 2079, 1620, 850 ,850,  0) ;
        al_draw_text(gameFont, al_map_rgb( 100, 100, 100), 730, 1660 , ALLEGRO_ALIGN_CENTER, "SORT STOP - empechez votre adversaire de jouer au prochain tour ") ;
    } else { al_draw_scaled_bitmap(jeu.classes->sortADisposition[STOP].iconeSort, 0, 0, 2000, 2000, 2079, 1620, 800 ,800,  0) ;}

    if ((float) ecran.mouse_x < 2065 && ecran.mouse_x > 1960 && (float) ecran.mouse_y < 1765 && ecran.mouse_y > 1620 ){
        al_draw_scaled_bitmap(jeu.classes->sortADisposition[SPECIAL].iconeSort, 0, 0, 2000, 2000, 1900, 1610, 965 ,965,  0) ;
        al_draw_text(gameFont, al_map_rgb( 100, 100, 100), 730, 1660 , ALLEGRO_ALIGN_CENTER, "SORT SPECIAL - TESTEZ LE SUR VOS ADVERSAIRES ") ;
    } else { al_draw_scaled_bitmap(jeu.classes->sortADisposition[SPECIAL].iconeSort, 0, 0, 2000, 2000, 1900, 1610, 915 ,915,  0) ;}

    if ((float) ecran.mouse_x < 2400 && ecran.mouse_x > 2280 && (float) ecran.mouse_y < 1765 && ecran.mouse_y > 1620 ){
        al_draw_scaled_bitmap(jeu.classes->sortADisposition[FLEMME].iconeSort, 0, 0, 2000, 2000, 2255, 1595, 884 ,884,  0) ;
        al_draw_text(gameFont, al_map_rgb( 100, 100, 100), 730, 1660 , ALLEGRO_ALIGN_CENTER, "SORT FLEMME - ENLEVEZ UN POINT DE VIE A VOTRE ADVERSAIRE ") ;
    } else { al_draw_scaled_bitmap(jeu.classes->sortADisposition[FLEMME].iconeSort, 0, 0, 2000, 2000, 2255, 1595, 834 ,834,  0) ;}

    if ((float) ecran.mouse_x < 2575 && ecran.mouse_x > 2450 && (float) ecran.mouse_y < 1765 && ecran.mouse_y > 1620 ) {
        al_draw_scaled_bitmap(jeu.classes->sortADisposition[RALENTIR].iconeSort, 0, 0, 2000, 2000, 2430, 1600, 889 ,889,  0);
        al_draw_text(gameFont, al_map_rgb( 100, 100, 100), 730, 1660 , ALLEGRO_ALIGN_CENTER, "SORT RALENTIR - RALENTIR SON ADVERSAIRE ") ;
    }else { al_draw_scaled_bitmap(jeu.classes->sortADisposition[RALENTIR].iconeSort, 0, 0, 2000, 2000, 2430, 1600, 839 ,839,  0) ;}

    if ((float) ecran.mouse_x < 2710 && ecran.mouse_x > 2605 && (float) ecran.mouse_y < 1765 && ecran.mouse_y > 1620 ) {
        al_draw_scaled_bitmap(jeu.classes->sortADisposition[FATAL].iconeSort, 0, 0, 2000, 2000, 2566, 1615, 930 ,930,  0) ;
        al_draw_text(gameFont, al_map_rgb(100, 100, 100), 730, 1660, ALLEGRO_ALIGN_CENTER,
                     "SORT FATAL - ASSOMMEZ VOTRE ADVERSAIRE EN LUI ENLEVANT 3 POINT DE VIR D'UN COUP ");
    } else { al_draw_scaled_bitmap(jeu.classes->sortADisposition[FATAL].iconeSort, 0, 0, 2000, 2000, 2566, 1615, 880 ,880,  0) ;}



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
