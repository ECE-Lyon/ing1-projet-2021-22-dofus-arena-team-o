#include "map.h"

bool collisionCercle(int x,int y,Map map[20][20],int i,int j,double width){
    int d2 = (x-map[i][j].x)*(x-map[i][j].x) + (y- map[i][j].y)*(y-map[i][j].y);
    if (d2>(width/60*width/60))
        return false;
    else
        return true;
}

void drawPlay(InfosJoueur *joueur,Map map[20][20],int mouse_x,int mouse_y,double width, double height, double scalex, double scaley, ALLEGRO_DISPLAY *display,ALLEGRO_COLOR white, ALLEGRO_COLOR black, ALLEGRO_COLOR gris,ALLEGRO_COLOR vert,ALLEGRO_COLOR red) {

    for (int j=0;j<mapY;j++) {
        for (int i = 0; i < mapX; i++) {


            al_draw_filled_triangle(map[i][j].x - scalex, map[i][j].y, map[i][j].x, map[i][j].y + scaley, map[i][j].x, map[i][j].y -
                                                                                                                       scaley, white);
            al_draw_filled_triangle(map[i][j].x + scalex, map[i][j].y, map[i][j].x, map[i][j].y + scaley, map[i][j].x, map[i][j].y -
                                                                                                                       scaley, white);
        }
    }
    for (int i = 0; i < mapX+1; i++) {
        al_draw_line(i * scalex, height/1.8 - i * scaley, width/2.25+i*scalex , height - i * scaley, black, 2);
    }
    for (int i=0;i<mapY+1;i++){
        al_draw_line(width/1.8+i*scalex,i*scaley,i*scalex,height/1.8+scaley*i, black,2);
    }

    for (int j=0;j<mapY;j++) {
        for (int i = 0; i < mapX; i++) {
            if(collisionCercle(mouse_x, mouse_y, map, i, j,width) == true ){
                al_draw_filled_triangle(map[i][j].x - scalex, map[i][j].y, map[i][j].x, map[i][j].y + scaley, map[i][j].x, map[i][j].y -
                                                                                                                           scaley, vert);
                al_draw_filled_triangle(map[i][j].x + scalex, map[i][j].y, map[i][j].x, map[i][j].y + scaley, map[i][j].x, map[i][j].y -
                                                                                                                           scaley, vert);
                if(map[0][0].t == 1 && joueur[0].dep == 0){
                    joueur[0].dep=1;
                    joueur[0].xArrive=i;
                    joueur[0].yArrive=j;
                    joueur[0].actif=1;
                    al_draw_filled_triangle(map[i][j].x - scalex, map[i][j].y, map[i][j].x, map[i][j].y + scaley, map[i][j].x, map[i][j].y -
                                                                                                                               scaley, red);
                    al_draw_filled_triangle(map[i][j].x + scalex, map[i][j].y, map[i][j].x, map[i][j].y + scaley, map[i][j].x, map[i][j].y -
                                                                                                                               scaley, red);
                }
            }

        }
    }
}

void caseJoueur(InfosJoueur *joueur,Map map[20][20]){
    for (int j=0;j<mapY;j++) {
        for (int i = 0; i < mapX; i++) {
            if (joueur[0].x>map[i][j].x-2 && joueur[0].x<map[i][j].x+2 && joueur[0].y>map[i][j].y-2 && joueur[0].y<map[i][j].y+2 ){
                joueur[0].caseX=i;
                joueur[0].caseY=j;
                printf("%d , %d\n",joueur[0].caseX,joueur[0].caseY);
            }
        }
    }
}

void deplacementJoueur(InfosJoueur *joueur, Map map[20][20],double scalex,double scaley){
    double depX=0;
    double depY=0;

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


        if (joueur[0].caseX == joueur[0].xArrive && joueur[0].caseY==joueur[0].yArrive){joueur[0].dep=0;}
    }

}