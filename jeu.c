#include "jeu.h"

void drawRules(int* pages, float height, float width, int mouse_x, int mouse_y, ALLEGRO_FONT* gameFontRegles, ALLEGRO_FONT* gameFont) {
    int police = 2*width/55 ;
    int policeRegles = 40;
    float thickness = (5*height/6 - height/6) / 40 ;
    ALLEGRO_COLOR vert = al_map_rgb(200, 255, 50) ;
    ALLEGRO_COLOR gameColor = al_map_rgb(20, 20, 20) ;

    ///FOND D'ECRAN GRISATRE
    al_draw_filled_rectangle(0, 0, width, height, al_map_rgba(150, 150, 150, 150)) ;

    ///ON FAIT SURBRILLER LES CASES RETURN ET LES BOUTONS SI LA SOURIS SE TROUVE DESSUS
    if ((float) mouse_x < 5*width/32 && mouse_x > width/384 && (float) mouse_y < 2*height/27 && mouse_y > height/216) {
        al_draw_filled_rectangle(width/384, height/216, 5*width/32, 2*height/27, al_map_rgb(200,200,200)) ;
    }
    else   al_draw_filled_rectangle(width/384, height/216, 5*width/32, 2*height/27, al_map_rgb(250,250,250)) ;
    if(*pages < RULESPAGEMAX) {
        if ((mouse_x - 13 * width / 15) * (mouse_x - 13 * width / 15) +
            (mouse_y - 11 * height / 13) * (mouse_y - 11 * height / 13) < width / 38.4 * width / 38.4) {
            al_draw_filled_circle(13 * width / 15, 11 * height / 13, width / 38.4, al_map_rgb(200, 200, 200));
        }
        else al_draw_filled_circle(13*width/15, 11*height/13, width/38.4, al_map_rgb(250,250,250)) ;
    }
    if(*pages > 1) {
        if ((mouse_x - 2 * width / 15) * (mouse_x - 2 * width / 15) +
            (mouse_y - 11 * height / 13) * (mouse_y - 11 * height / 13) < width / 38.4 * width / 38.4) {
            al_draw_filled_circle(2 * width / 15, 11 * height / 13, width / 38.4, al_map_rgb(200, 200, 200));
        }
        else al_draw_filled_circle(2 * width / 15, 11 * height / 13, width / 38.4, al_map_rgb(250, 250, 250));
    }

    ///GRAND RECTANGLE AU MILIEU
    /*for(int i = 0 ; i < 40 ; i++) {
        al_draw_line(width/5, height/6 + thickness*i,4*width/5, height/6 + thickness*i, al_map_rgb(219 - 3*i, 182 - 2*i, 193 - i), thickness);
    }*/
    al_draw_filled_rectangle(width/5, height/6, 4 * (width /5), 5 * (height/6) , al_map_rgba(219, 112, 147, 200));

    ///FLECHE DROITE
    if(*pages < RULESPAGEMAX) {
        al_draw_circle(13*width/15, 11*height/13, width/38.4, gameColor, 4) ;
        al_draw_line(13*width/15 - width/64 , 11*height/13, 13*width/15 + width/64, 11*height/13, gameColor, 3);
        al_draw_line(13*width/15 + width/64, 11*height/13, 13*width/15 + width/192, 11*height/13 - height/43.2 , gameColor, 3);
        al_draw_line(13*width/15 + width/64, 11*height/13, 13*width/15 + width/192, 11*height/13 + height/43.2 , gameColor, 3);
    }

    ///FLECHE GAUCHE
    if(*pages > 1) {
        al_draw_circle(2*width/15, 11*height/13, width/38.4, gameColor, 4) ;
        al_draw_line(2*width/15 - width/64, 11*height/13, 2*width/15 + width/64, 11*height/13, gameColor, 3) ;
        al_draw_line(2*width/15 - width/64, 11*height/13, 2*width/15 - width/192 , 11*height/13 - height/43.2, gameColor, 3) ;
        al_draw_line(2*width/15 - width/64, 11*height/13, 2*width/15 - width/192 , 11*height/13 + height/43.2, gameColor, 3) ;
    }

    al_draw_filled_circle(7.46* width / 15, 11 * height / 13 + 1.5*height / 18, police, al_map_rgb(250, 250, 250)) ;
    al_draw_circle(7.46* width / 15, 11 * height / 13 + 1.5*height / 18, police, gameColor, 3) ;


    ///DIFFERENTES PAGES DES REGLES
    afficherPages(*pages, gameFontRegles, gameColor) ;

    ///BOUTON RETURN
    al_draw_text(gameFont, gameColor, (5*width/32 - width/384)/2 + police/10, (2*height/27-height/216)/2 - police/3, ALLEGRO_ALIGN_CENTER, "RETURN") ;
    al_draw_rectangle(width/384, height/216, 5*width/32, 2*height/27, gameColor, 3) ;
    al_draw_textf(gameFont, gameColor, 7.5 * width / 15, 11 * height / 13 + height / 18, ALLEGRO_ALIGN_CENTER, "%d / %d", *pages, RULESPAGEMAX) ;
}

void afficherPages(int pages, ALLEGRO_FONT* gameFontRegles, ALLEGRO_COLOR gameColor) {
    switch(pages){
        case 1 : {
            //x1 : width/5, y1 : height/6 , x2: 4*width/5 , y2 : 5*height/6
            al_draw_text(gameFontRegles, gameColor, 950 , 200, ALLEGRO_ALIGN_CENTER, "Regles ") ;
            al_draw_textf(gameFontRegles, gameColor, 400 , 300, ALLEGRO_ALIGN_LEFT, "       Classes :  ") ;
            al_draw_textf(gameFontRegles, gameColor, 400 , 350, ALLEGRO_ALIGN_LEFT, " Au debut du jeu, chaque joueur a le choix entre plusieurs Classes. ") ;
            al_draw_textf(gameFontRegles, gameColor, 400 , 400, ALLEGRO_ALIGN_LEFT, " La classe d'un personnage definit son apparence et les sorts dont il dispose. ") ;
            al_draw_textf(gameFontRegles, gameColor, 400 , 500, ALLEGRO_ALIGN_LEFT, "       Tour : ");
            al_draw_textf(gameFontRegles, gameColor, 400 , 550, ALLEGRO_ALIGN_LEFT, " Lorsque c'est a un joueur de jouer, il dispose de 15 secondes pour faire ses ");
            al_draw_textf(gameFontRegles, gameColor, 400 , 600, ALLEGRO_ALIGN_LEFT, " actions, dans n'importe quel ordre : ");
            al_draw_textf(gameFontRegles, gameColor, 400 , 650, ALLEGRO_ALIGN_LEFT, " - Se deplacer, dans la limite de ses PM, ");
            al_draw_textf(gameFontRegles, gameColor, 400 , 700, ALLEGRO_ALIGN_LEFT, " - Attaquer, dans la limite de ses PA, ");
            al_draw_textf(gameFontRegles, gameColor, 400 , 750, ALLEGRO_ALIGN_LEFT, " - Passer son tour. ");
            break;
        }
        case 2 : {
            al_draw_text(gameFontRegles, gameColor, 950 , 200, ALLEGRO_ALIGN_CENTER, "Suite ") ;
            al_draw_textf(gameFontRegles, gameColor, 400 , 300, ALLEGRO_ALIGN_LEFT, " Au bout de 15 secondes, le jeu passe automatiquement au personnage ") ;
            al_draw_textf(gameFontRegles, gameColor, 400 , 350, ALLEGRO_ALIGN_LEFT, " suivant. Si le joueur termine ses actions avant les 15s, il peut cliquer sur") ;
            al_draw_textf(gameFontRegles, gameColor, 400 , 400, ALLEGRO_ALIGN_LEFT, " le bouton Personnage suivant") ;
            al_draw_textf(gameFontRegles, gameColor, 400 , 500, ALLEGRO_ALIGN_LEFT, "       Attaques : ") ;
            al_draw_textf(gameFontRegles, gameColor, 400 , 550, ALLEGRO_ALIGN_LEFT, " Le but du jeu etant de gagner la bataille, chaque joueur, peut, lorsque c'est ");
            al_draw_textf(gameFontRegles, gameColor, 400 , 600, ALLEGRO_ALIGN_LEFT, " son tour, lancer des sorts ou attaquer au corps a corps. Lorsqu'un ");
            al_draw_textf(gameFontRegles, gameColor, 400 , 650, ALLEGRO_ALIGN_LEFT, " personnage subit une attaque, il perd des PV calcules aleatoirement ");
            al_draw_textf(gameFontRegles, gameColor, 400 , 700, ALLEGRO_ALIGN_LEFT, " en fonction de la puissance de l'attaque. Par exemple une attaque ");
            al_draw_textf(gameFontRegles, gameColor, 400 , 750, ALLEGRO_ALIGN_LEFT, " enleve 8 PV, plus ou moins 4 PV, et elle a une chance sur 12 d'echouer.");
            break;
        }
        case 3 : {
            al_draw_text(gameFontRegles, gameColor, 950 , 200, ALLEGRO_ALIGN_CENTER, "Suite ") ;
            al_draw_textf(gameFontRegles, gameColor, 400 , 300, ALLEGRO_ALIGN_LEFT, "       Attaque au corps a corps : ") ;
            al_draw_textf(gameFontRegles, gameColor, 400 , 350, ALLEGRO_ALIGN_LEFT, " L'attaque au corps a corps n'est possible que sur les cases adjacentes ") ;
            al_draw_textf(gameFontRegles, gameColor, 400 , 400, ALLEGRO_ALIGN_LEFT, " (voisines). Elles sont beaucoup moins puissantes qu'un sort, mais ne coutent") ;
            al_draw_textf(gameFontRegles, gameColor, 400 , 450, ALLEGRO_ALIGN_LEFT, " que 2 PA. Elles peuvent enlever entre 1 et 5 PV a l'ennemi, avec 1 chance ") ;
            al_draw_textf(gameFontRegles, gameColor, 400 , 500, ALLEGRO_ALIGN_LEFT, " sur 10 d'echouer (et donc n'enlever aucun PV).") ;
            break;
        }
    }
}


void drawTeam(float height, float width, int mouse_x, int mouse_y, ALLEGRO_FONT *gameFont, ALLEGRO_BITMAP* team) {
    float police = 2*width/55 ;
    ALLEGRO_COLOR gameColor = al_map_rgb(20, 20, 20) ;

    ///FOND D'ECRAN GRISATRE
    al_draw_filled_rectangle(0, 0, width, height, al_map_rgba(150, 150, 150, 150)) ;

    al_draw_filled_rectangle(width/5, height/6, 4 * (width /5), 5 * (height/6) , al_map_rgba(219, 112, 147, 200));

    al_draw_scaled_bitmap(team, 0, 0, 1034, 704, width/5 + 180, height/5 + 40, 1034*1.05, 704*1.05, 0) ;
    ///ON FAIT SURBRILLER LES CASES RETURN ET LES BOUTONS SI LA SOURIS SE TROUVE DESSUS
    if ((float) mouse_x < 5*width/32 && mouse_x > width/384 && (float) mouse_y < 2*height/27 && mouse_y > height/216) {
        al_draw_filled_rectangle(width/384, height/216, 5*width/32, 2*height/27, al_map_rgb(200,200,200)) ;
    }
    else   al_draw_filled_rectangle(width/384, height/216, 5*width/32, 2*height/27, al_map_rgb(250,250,250)) ;

    ///Zelie
    al_draw_text(gameFont, gameColor, width/4 , 200, ALLEGRO_ALIGN_CENTER, "Zelie") ;

    ///Nel
    al_draw_text(gameFont, gameColor, 3*width/4 , 200, ALLEGRO_ALIGN_CENTER, "Nel") ;

    ///FARES
    al_draw_text(gameFont, gameColor, width / 4 , 800, ALLEGRO_ALIGN_CENTER, "Fares") ;

    ///ILAYDA
    al_draw_text(gameFont, gameColor, 3*width/4 , 800, ALLEGRO_ALIGN_CENTER, "Ilayda") ;

    ///BOUTON RETURN
    al_draw_text(gameFont, gameColor, (5*width/32 - width/384)/2 + police/10, (2*height/27-height/216)/2 - police/3, ALLEGRO_ALIGN_CENTER, "RETURN") ;
    al_draw_rectangle(width/384, height/216, 5*width/32, 2*height/27, gameColor, 3) ;
}

void drawMenuV2(Menu* mainMenu, ALLEGRO_FONT *gameFont) {
    float thickness1 = (322*mainMenu->ecran.height/495 - 4*mainMenu->ecran.height/9) / 40 ;
    float thickness2 = (38*mainMenu->ecran.height/99 - 7*mainMenu->ecran.height/80) / 40 ;
    ALLEGRO_COLOR blueLogo = al_map_rgb(222, 35, 35) ;
    ALLEGRO_COLOR ecriture = al_map_rgb(20, 20, 20) ;

    ///FAIRE BOUGER L'ARC
    moveGameModeArc(&mainMenu) ;

    ///ON FAIT BOUGER L'ARC SI LA SOURIS SE TROUVE DESSUS
    if(mainMenu->rulesRect) {
        al_draw_filled_rectangle(2 * mainMenu->ecran.width / 11, 3 * mainMenu->ecran.height / 7, 5 * mainMenu->ecran.width / 11, 6 * mainMenu->ecran.height / 9, al_map_rgb(0, 0, 0));
        //al_draw_rectangle(21*width/110, 4*height/9, 49*width/110, 322*height/495, al_map_rgb(255, 255, 255), thickness1*2) ;
    }
    if(mainMenu->teamRect) {
        al_draw_filled_rectangle(6 * mainMenu->ecran.width / 11, 3 * mainMenu->ecran.height / 7, 9 * mainMenu->ecran.width / 11, 6 * mainMenu->ecran.height / 9, al_map_rgb(0, 0, 0));
        //al_draw_rectangle(61*width/110, 4*height/9, 89*width/110, 322*height/495, al_map_rgb(255, 255, 255), thickness1*2) ;
    }
    if(mainMenu->playRect) {
        al_draw_filled_rectangle(4.2 *mainMenu->ecran. width / 10, mainMenu->ecran.height / 14, 5.8 * mainMenu->ecran.width / 10, 4 * mainMenu->ecran.height / 10, al_map_rgb(0, 0, 0));
        //al_draw_rectangle(118*width/275, 7*height/80, 157*width/275, 38*height/99, al_map_rgb(255, 255, 255), thickness2*1.5) ;
    }

    ///DESSINER LES 3 RECTANGLES DES MENUS
    for (float i = 0; i < 41; i++) {
        al_draw_line(21*mainMenu->ecran.width/110, 4*mainMenu->ecran.height/9 + thickness1*i, 49*mainMenu->ecran.width/110, 4*mainMenu->ecran.height/9 + thickness1*i, al_map_rgb(255 - 4*i, 255, 0), thickness1) ;
        al_draw_line(61*mainMenu->ecran.width/110, 4*mainMenu->ecran.height/9 + thickness1*i, 89*mainMenu->ecran.width/110, 4*mainMenu->ecran.height/9 + thickness1*i, al_map_rgb(0, 100 + 3*i , 255), thickness1) ;
        al_draw_line(118*mainMenu->ecran.width/275, 7*mainMenu->ecran.height/80 + thickness2*i, 157*mainMenu->ecran.width/275, 7*mainMenu->ecran.height/80 + thickness2*i, al_map_rgb(255, 50 + 4*i , 0), thickness2) ;
    }

    ///DESSIN DU LOGO SMASH AU MILIEU
    al_draw_filled_circle(mainMenu->ecran.width/2, mainMenu->ecran.height/2, mainMenu->ecran.height/6, al_map_rgb(250, 250, 250)) ;
    al_draw_filled_rectangle(61*mainMenu->ecran.width/128, 61*mainMenu->ecran.height/90, 56*mainMenu->ecran.width/128, 29*mainMenu->ecran.height/90, blueLogo) ;
    al_draw_filled_rectangle(13*mainMenu->ecran.width/32, 19*mainMenu->ecran.height/36, 19*mainMenu->ecran.width/32, 20.5*mainMenu->ecran.height/36, blueLogo) ;
    al_draw_circle(mainMenu->ecran.width/2, mainMenu->ecran.height/2, 26*mainMenu->ecran.height/135, al_map_rgb(0, 0, 0), (2.95*mainMenu->ecran.height/16 - mainMenu->ecran.height/6.5)) ;
    al_draw_circle(mainMenu->ecran.width/2, mainMenu->ecran.height/2, 3*mainMenu->ecran.height/16 - (2.95*mainMenu->ecran.height/16 - mainMenu->ecran.height/6), blueLogo, (2.95*mainMenu->ecran.height/16 - mainMenu->ecran.height/6)) ;
    ///DESSIN DE L'ARC
    al_draw_arc(mainMenu->ecran.width / 2, mainMenu->ecran.height / 2, 3 * mainMenu->ecran.height / 16, mainMenu->arc.currentTheta, mainMenu->arc.currentEndTheta, blueLogo, 2.95 * mainMenu->ecran.height / 16 - mainMenu->ecran.height / 6);

    ///ECRITURE DES MODES DE JEUX
    al_draw_textf(gameFont, ecriture, 21*mainMenu->ecran.width/110 + (49*mainMenu->ecran.width/110 - 21*mainMenu->ecran.width/110)/2.5,  4*mainMenu->ecran.height/9 + (322*mainMenu->ecran.height/495 - 4*mainMenu->ecran.height/9)/3, ALLEGRO_ALIGN_CENTER, "Rules") ;
    al_draw_textf(gameFont, ecriture, 61*mainMenu->ecran.width/110 + (89*mainMenu->ecran.width/110 - 61*mainMenu->ecran.width/110)/1.5,  4*mainMenu->ecran.height/9 + (322*mainMenu->ecran.height/495 - 4*mainMenu->ecran.height/9)/3, ALLEGRO_ALIGN_CENTER, "Team") ;
    al_draw_textf(gameFont, ecriture, 118*mainMenu->ecran.width/275 + (157*mainMenu->ecran.width/275 - 118*mainMenu->ecran.width/275)/2,  7*mainMenu->ecran.height/80 + (38*mainMenu->ecran.height/99 - 7*mainMenu->ecran.height/80)/3.5, ALLEGRO_ALIGN_CENTER, "PLAY") ;
}

void moveGameModeArc(Menu** mainMenu) {
    if((*mainMenu)->arc.currentTheta != (*mainMenu)->arc.startTheta) {
        if((*mainMenu)->arc.currentTheta < (*mainMenu)->arc.startTheta) {
            (*mainMenu)->arc.currentTheta += PI/20 ;
        }
        if((*mainMenu)->arc.currentTheta > (*mainMenu)->arc.startTheta) {
            (*mainMenu)->arc.currentTheta -= PI/20 ;
        }
    }
    if((*mainMenu)->arc.currentEndTheta != (*mainMenu)->arc.endTheta) {
        if((*mainMenu)->arc.currentEndTheta < (*mainMenu)->arc.endTheta) {
            (*mainMenu)->arc.currentEndTheta += PI/20;
        }
        if((*mainMenu)->arc.currentEndTheta > (*mainMenu)->arc.endTheta) {
            (*mainMenu)->arc.currentEndTheta -= PI/20 ;
        }
    }
}

void menuSouris(Menu* mainMenu, float height, float width, int mouse_x, int mouse_y) {
    if (mouse_x < 157*width/275 && mouse_x > 118*width/275 && mouse_y < 38*height/99 && mouse_y > 7*height/80) {
        mainMenu->playRect = 1 ;
        mainMenu->arc.startTheta = 4*PI/3 ;
        mainMenu->arc.endTheta = 2*PI/5 ;
    }
    else if (mouse_x < 49*width/110 && mouse_x > 21*width/110 && mouse_y < 322*height/495 && mouse_y > 4*height/9) {
        mainMenu->rulesRect = 1 ;
        mainMenu->arc.startTheta = 3*PI/4 ;
        mainMenu->arc.endTheta = 4*PI/11 ;
    }
    else if (mouse_x < 89*width/110 && mouse_x > 61*width/110 && mouse_y < 322*height/495 && mouse_y > 4*height/9) {
        mainMenu->teamRect = 1 ;
        mainMenu->arc.startTheta = 23*PI/12 ;
        mainMenu->arc.endTheta = 4*PI/11 ;
    }
    else {
        mainMenu->playRect = 0;
        mainMenu->rulesRect = 0;
        mainMenu->teamRect = 0;
        mainMenu->arc.startTheta = 0 ;
        mainMenu->arc.endTheta = 2*PI ;
    }
}

void drawPlay2(float width, float height, int mouse_x, int mouse_y, ALLEGRO_FONT * gameFont, ALLEGRO_FONT *gameFontRegles, int* nbJoueur) {

    al_draw_filled_rectangle(0, 0, width, height, al_map_rgba(150, 150, 150, 150));

    float police = 2 * width / 55;
    ALLEGRO_COLOR gameColor = al_map_rgb(222, 35, 35);
    ALLEGRO_COLOR ecriture = al_map_rgb(20, 20, 20);

    al_draw_filled_rectangle(0, 0, width, 5 * height / 27, al_map_rgb(100, 100, 100));
    al_draw_filled_triangle(0, 0, 0, 500, 500, 150, al_map_rgb(100, 100, 100));
    al_draw_filled_rectangle(0, 0, width, 4 * height / 27, al_map_rgb(150, 150, 150));
    al_draw_filled_triangle(0, 0, 0, 410, 370, 150, al_map_rgb(150, 150, 150));


    al_draw_filled_circle(1740, 80, 60, al_map_rgb(100, 100, 100)) ;
    al_draw_filled_rectangle(1680,   90, 1800, 100, al_map_rgb(150, 150, 150)) ;
    al_draw_filled_rectangle(1705,   20, 1735, 140, al_map_rgb(150, 150, 150)) ;

    // bouton return
    if ((float) mouse_x < 5*width/32 && mouse_x > width/384 && (float) mouse_y < 2*height/27 && mouse_y > height/216) {
        al_draw_filled_rectangle(width/384, height/216, 5*width/32, 2*height/27, al_map_rgb(200,200,200)) ;
        al_draw_text(gameFont, al_map_rgb(0, 0, 0), (5*width/32 - width/384)/2 + police/10, (2*height/27-height/216)/2 - police/3, ALLEGRO_ALIGN_CENTER, "RETURN") ;
    }
    else   {
        al_draw_filled_rectangle(width/384, height/216, 5*width/32, 2*height/27, al_map_rgb(255,255,255)) ;
        al_draw_text(gameFont, al_map_rgb(0, 0, 0), (5*width/32 - width/384)/2 + police/10, (2*height/27-height/216)/2 - police/3, ALLEGRO_ALIGN_CENTER, "RETURN") ;
    }

    // bouton 2, 3, 4
    al_draw_textf(gameFontRegles, al_map_rgb(0, 0, 0), 1000, 75, ALLEGRO_ALIGN_CENTER,"Combien de joueurs etes-vous ?");
    al_draw_filled_circle(400, 500, 100, al_map_rgba(219, 112, 147, 200));
    al_draw_text(gameFontRegles, al_map_rgb(0, 0, 0), 400, 475, ALLEGRO_ALIGN_CENTER, "2");
    al_draw_filled_circle(950, 500, 100, al_map_rgba(219, 112, 147, 200));
    al_draw_text(gameFontRegles, al_map_rgb(0, 0, 0), 950, 475, ALLEGRO_ALIGN_CENTER, "3");
    al_draw_filled_circle(1500, 500, 100, al_map_rgba(219, 112, 147, 200));
    al_draw_text(gameFontRegles, al_map_rgb(0, 0, 0), 1500, 475, ALLEGRO_ALIGN_CENTER, "4");

    // si on est sur la case, elle change de couleur
    if((mouse_x - 400)*(mouse_x - 400) + (mouse_y - 500)*(mouse_y - 500) < 100*100){
        al_draw_filled_circle(400, 500, 100, al_map_rgb(219, 112, 147));
        al_draw_text(gameFontRegles, al_map_rgb(0, 0, 0), 400, 475, ALLEGRO_ALIGN_CENTER, "2");
    }
    else if((mouse_x - 950)*(mouse_x - 950) + (mouse_y - 500)*(mouse_y - 500) < 100*100){
        al_draw_filled_circle(950, 500, 100, al_map_rgb(219, 112, 147));
        al_draw_text(gameFontRegles, al_map_rgb(0, 0, 0), 950, 475, ALLEGRO_ALIGN_CENTER, "3");
    }
    else if((mouse_x - 1500)*(mouse_x - 1500) + (mouse_y - 500)*(mouse_y - 500) < 100*100){
        al_draw_filled_circle(1500, 500, 100, al_map_rgb(219, 112, 147));
        al_draw_text(gameFontRegles, al_map_rgb(0, 0, 0), 1500, 475, ALLEGRO_ALIGN_CENTER, "4");
    }

}

bool collisionCercle(int x,int y,Map map[20][20],int i,int j,double width){
    int d2 = (x-map[i][j].x)*(x-map[i][j].x) + (y- map[i][j].y)*(y-map[i][j].y);
    if (d2>(width/60*width/60))
        return false;
    else
        return true;
}

void drawPlay(Map map[20][20],ALLEGRO_EVENT event,int mouse_x,int mouse_y,ALLEGRO_DISPLAY *display,ALLEGRO_COLOR white, ALLEGRO_COLOR black, ALLEGRO_COLOR gris,ALLEGRO_COLOR vert,ALLEGRO_COLOR red) {
    double height = al_get_display_height(display);
    double width = al_get_display_width(display);
    double scalex = 50.0*width/1800.0;
    double scaley = 50.0*height/1800.0;
    float police = 2 * width / 55;
    ALLEGRO_COLOR gameColor = al_map_rgb(222, 35, 35);
    ALLEGRO_COLOR ecriture = al_map_rgb(20, 20, 20);
    ALLEGRO_FONT *gameFont = al_load_ttf_font("../Font/MagicCardsNormal.ttf", police, ALLEGRO_ALIGN_LEFT);

    for (int j=0;j<mapY;j++) {
        for (int i = 0; i < mapX; i++) {
            map[i][j].x=  scalex + i * scalex + j * scalex;
            map[i][j].y= height/1.8 - i * scaley + j * scaley;
            al_draw_filled_triangle(map[i][j].x - scalex, map[i][j].y, map[i][j].x, map[i][j].y + scaley, map[i][j].x, map[i][j].y -
                                                                                                                       scaley, white);
            al_draw_filled_triangle(map[i][j].x + scalex, map[i][j].y, map[i][j].x, map[i][j].y + scaley, map[i][j].x, map[i][j].y -
                                                                                                                       scaley, white);
        }
    }
    for (int i = 0; i < mapX+1; i++) {
        al_draw_line(i * scalex, height/1.8 - i * scaley, width/2.25 + i * scalex, height - scaley * i, black, 3);
    }
    for (int i=0;i<mapY+1;i++){
        al_draw_line(width/1.8+i*scalex,i*scaley,i*scalex,height/1.8+scaley*i, black,3);
    }

    for (int j=0;j<mapY;j++) {
        for (int i = 0; i < mapX; i++) {
            if(collisionCercle(mouse_x, mouse_y, map, i, j,width) == true ){
                al_draw_filled_triangle(map[i][j].x - scalex, map[i][j].y, map[i][j].x, map[i][j].y + scaley, map[i][j].x, map[i][j].y -
                                                                                                                           scaley, vert);
                al_draw_filled_triangle(map[i][j].x + scalex, map[i][j].y, map[i][j].x, map[i][j].y + scaley, map[i][j].x, map[i][j].y -
                                                                                                                           scaley, vert);
                if(map[0][0].t==1){
                    al_draw_filled_triangle(map[i][j].x - scalex, map[i][j].y, map[i][j].x, map[i][j].y + scaley, map[i][j].x, map[i][j].y -
                                                                                                                               scaley, red);
                    al_draw_filled_triangle(map[i][j].x + scalex, map[i][j].y, map[i][j].x, map[i][j].y + scaley, map[i][j].x, map[i][j].y -
                                                                                                                               scaley, red);

                }
            }

        }
    }
}

void drawChooseCharacter(float height, float width, int nbJoueur) {
    al_draw_filled_rectangle(0, 0, width, height, al_map_rgba(150, 150, 150, 150));

    al_draw_filled_rectangle(0, 0, width, 5 * height / 27, al_map_rgb(100, 100, 100));
    al_draw_filled_triangle(0, 0, 0, 500, 500, 150, al_map_rgb(100, 100, 100));
    al_draw_filled_rectangle(0, 0, width, 4 * height / 27, al_map_rgb(150, 150, 150));
    al_draw_filled_triangle(0, 0, 0, 410, 370, 150, al_map_rgb(150, 150, 150));

    al_draw_filled_circle(1740, 80, 60, al_map_rgb(100, 100, 100)) ;
    al_draw_filled_rectangle(1680,   90, 1800, 100, al_map_rgb(150, 150, 150)) ;
    al_draw_filled_rectangle(1705,   20, 1735, 140, al_map_rgb(150, 150, 150)) ;

    for(int i = 0 ; i < 4 ; i++) {
        al_draw_filled_rounded_rectangle(width/2 - 600 - 250 + i*500, 2*height/3, (width/2 - 600 - 250 + i*500) + 300, height+15, 10, 10,
                                         al_map_rgb(105-10*i, 60*i , 100 + 50*i)) ;
    }
    ///BOUTON RETURN
}

int getRandomInteger(int min, int max){
    int nbAleatoire = rand()%(max-min+1)+min;
    return nbAleatoire;
}

/*void deplacementJoueur(Joueur *joueur[],Map map[20][20]){
    joueur[0]->x = map[0][0].x;
    joueur[0]->y = map[0][0].y;
    if(joueur[0]->t==1) {
        if (joueur[0]->xp< map[joueur[0]->a][joueur[0]->b].x && joueur[0]->xp != map[joueur[0]->a][joueur[0]->b].x){
            joueur[0]->xp = joueur[0]->xp + 1;
        }
        if (joueur[0]->xp>map[joueur[0]->a][joueur[0]->b].x && joueur[0]->xp != map[joueur[0]->a][joueur[0]->b].x){
            joueur[0]->xp = joueur[0]->xp - 1;
        }
*/

char alphabet (int keycode){
    char lettreAppuye;
    switch (keycode) {
        case ALLEGRO_KEY_Q:
            lettreAppuye = 'a';
            break;
        case ALLEGRO_KEY_B:
            lettreAppuye = 'b';
            break;
        case ALLEGRO_KEY_C:
            lettreAppuye = 'c';
            break;
        case ALLEGRO_KEY_D:
            lettreAppuye = 'd';
            break;
        case ALLEGRO_KEY_E:
            lettreAppuye = 'e';
            break;
        case ALLEGRO_KEY_F:
            lettreAppuye = 'f';
            break;
        case ALLEGRO_KEY_G:
            lettreAppuye = 'g';
            break;
        case ALLEGRO_KEY_H:
            lettreAppuye = 'h';
            break;
        case ALLEGRO_KEY_I:
            lettreAppuye = 'i';
            break;
        case ALLEGRO_KEY_J:
            lettreAppuye = 'j';
            break;
        case ALLEGRO_KEY_K:
            lettreAppuye = 'k';
            break;
        case ALLEGRO_KEY_L:
            lettreAppuye = 'l';
            break;
        case ALLEGRO_KEY_M:
            lettreAppuye = 'm';
            break;
        case ALLEGRO_KEY_N:
            lettreAppuye = 'n';
            break;
        case ALLEGRO_KEY_O:
            lettreAppuye = 'o';
            break;
        case ALLEGRO_KEY_P:
            lettreAppuye = 'p';
            break;
        case ALLEGRO_KEY_A:
            lettreAppuye = 'q';
            break;
        case ALLEGRO_KEY_R:
            lettreAppuye = 'r';
            break;
        case ALLEGRO_KEY_S:
            lettreAppuye = 's';
            break;
        case ALLEGRO_KEY_T:
            lettreAppuye = 't';
            break;
        case ALLEGRO_KEY_U:
            lettreAppuye = 'u';
            break;
        case ALLEGRO_KEY_V:
            lettreAppuye = 'v';
            break;
        case ALLEGRO_KEY_Z:
            lettreAppuye = 'w';
            break;
        case ALLEGRO_KEY_X:
            lettreAppuye = 'x';
            break;
        case ALLEGRO_KEY_Y:
            lettreAppuye = 'Y';
            break;
        case ALLEGRO_KEY_W:
            lettreAppuye = 'z';
            break;
    }
    return lettreAppuye;
}

/*
// autre methode pour entrer un nom

void entrerPseudo (ALLEGRO_EVENT* event, InfosJoueur tabJoueur[], int joueurActuel){
    int numCharPseudo = 0;
    if (event.type == ALLEGRO_KEY_DOWN){
        if ( numCharPseudo < MAXNOM && event.keyboard.keycode >= ALLEGRO_KEY_A && event.keyboard.keycode <= ALLEGRO_KEY_Z) {
            tabJoueur[joueurActuel].pseudo[numCharPseudo] = (char) (event.keyboard.keycode + 96);
            numCharPseudo++;
        }
        if (event.keyboard.keycode == ALLEGRO_KEY_BACKSPACE){
            if (numCharPseudo >= 1){
                numCharPseudo--;
                tabJoueur[joueurActuel].pseudo[numCharPseudo] = '\0';
            }
        }
    }
}
