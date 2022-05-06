#include "map.h"

bool collisionCercle(int x,int y,Map map[20][20],int i,int j,double width){
    int d2 = (x-map[i][j].x)*(x-map[i][j].x) + (y- map[i][j].y)*(y-map[i][j].y);
    if (d2>(width/60*width/60))
        return false;
    else
        return true;
}

void drawPlay(Joueur joueur[],Map map[20][20],ALLEGRO_EVENT event,int mouse_x,int mouse_y,ALLEGRO_DISPLAY *display,ALLEGRO_COLOR white, ALLEGRO_COLOR black, ALLEGRO_COLOR gris,ALLEGRO_COLOR vert,ALLEGRO_COLOR red) {
    double height = al_get_display_height(display);
    double width = al_get_display_width(display);
    double scalex = 50.0*width/1800.0;
    double scaley = 50.0*height/1800.0;
    float police = 50;
    ALLEGRO_COLOR gameColor = al_map_rgb(222, 35, 35);
    ALLEGRO_COLOR ecriture = al_map_rgb(20, 20, 20);
    ALLEGRO_FONT *gameFont2 = al_load_ttf_font("../Font/MagicCardsNormal.ttf", police, ALLEGRO_ALIGN_LEFT);

    for (int j=0;j<mapY;j++) {
        for (int i = 0; i < mapX; i++) {


            al_draw_filled_triangle(map[i][j].x - scalex, map[i][j].y, map[i][j].x, map[i][j].y + scaley, map[i][j].x, map[i][j].y -
                                                                                                                       scaley, white);
            al_draw_filled_triangle(map[i][j].x + scalex, map[i][j].y, map[i][j].x, map[i][j].y + scaley, map[i][j].x, map[i][j].y -
                                                                                                                       scaley, white);
            //al_draw_textf(gameFont2, gameColor, map[i][j].x-20 , map[i][j].y-30, ALLEGRO_ALIGN_CENTER, " %d / %d",i,j) ;

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
                if(map[0][0].t == 1 && joueur[0].s == 0){
                    joueur[0].s=1;
                    joueur[0].a=i;
                    joueur[0].b=j;
                    joueur[0].t=1;
                    al_draw_filled_triangle(map[i][j].x - scalex, map[i][j].y, map[i][j].x, map[i][j].y + scaley, map[i][j].x, map[i][j].y -
                                                                                                                               scaley, red);
                    al_draw_filled_triangle(map[i][j].x + scalex, map[i][j].y, map[i][j].x, map[i][j].y + scaley, map[i][j].x, map[i][j].y -
                                                                                                                               scaley, red);
                }
            }

        }
    }
    al_destroy_font(gameFont2);
}

void caseJoueur(Joueur joueur[],Map map[20][20]){
    for (int j=0;j<mapY;j++) {
        for (int i = 0; i < mapX; i++) {
            if (joueur[0].xp>map[i][j].x-40 && joueur[0].xp<map[i][j].x+40 && joueur[0].yp>map[i][j].y-40 && joueur[0].yp<map[i][j].y+40 ){
                joueur[0].caseX=i;
                joueur[0].caseY=j;
                printf("%d , %d\n",joueur[0].caseX,joueur[0].caseY);
            }
        }
    }
}

void deplacementJoueur(Joueur joueur[], Map map[20][20],double scalex,double scaley){
    double depX=0;
    double depY=0;


    if(joueur[0].t==1 && joueur[0].s==1) {
        if (joueur[0].caseX<joueur[0].a){
            depX = 1;
        }

        if (joueur[0].caseX>joueur[0].a){
            depX = -1;
        }

        if (joueur[0].caseY<joueur[0].b){
            depY = scaley/scalex;
        }

        if (joueur[0].caseY>joueur[0].b){
            depY = -scaley/scalex;
        }

        if (joueur[0].caseX == joueur[0].a && joueur[0].caseY < joueur[0].b ){
            depX = 1;
            depY = scaley/scalex;
        }

        if (joueur[0].caseX == joueur[0].a && joueur[0].caseY > joueur[0].b ){
            depX = -1;
            depY = -scaley/scalex;
        }

        if (joueur[0].caseX < joueur[0].a && joueur[0].caseY == joueur[0].b ){
            depX = 1;
            depY = -scaley/scalex;
        }

        if (joueur[0].caseX > joueur[0].a && joueur[0].caseY == joueur[0].b ){
            depX = -1;
            depY = scaley/scalex;
        }

        for (int j=0;j<mapY;j++) {
            for (int i = 0; i < mapX; i++) {
                if (joueur[0].xp>map[i][j].x-2 && joueur[0].xp<map[i][j].x+2 && joueur[0].yp>map[i][j].y-2 && joueur[0].yp<map[i][j].y+2 ){
                    joueur[0].caseX=i;
                    joueur[0].caseY=j;
                    printf("%d , %d\n",joueur[0].caseX,joueur[0].caseY);

                }
            }
        }



        joueur[0].xp = joueur[0].xp + depX;
        joueur[0].yp = joueur[0].yp + depY;


        if (joueur[0].caseX == joueur[0].a && joueur[0].caseY==joueur[0].b){joueur[0].s=0;}
    }

}