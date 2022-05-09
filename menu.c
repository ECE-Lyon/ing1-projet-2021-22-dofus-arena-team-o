#include "menu.h"

void initialiserMenu(Menu* mainMenu, float width, float height) {
    mainMenu->ecran.width = width ;
    mainMenu->ecran.height = height ;
    mainMenu->gameMode = MENU;
    mainMenu->playRect = 0;
    mainMenu->rulesRect = 0;
    mainMenu->teamRect = 0;
    mainMenu->arc.startTheta = 0;
    mainMenu->arc.endTheta = 2 * PI;
    mainMenu->arc.currentTheta = 0;
    mainMenu->arc.currentEndTheta = 2 * PI;
}

void drawRules(int* pages, float height, float width, int mouse_x, int mouse_y, ALLEGRO_FONT* gameFontRegles, ALLEGRO_FONT* gameFont) {
    int police = 2*width/55 ;
    int policeRegles = 40;
    float thickness = (5*height/6 - height/6) / 40 ;
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
    afficherPages(*pages, gameFontRegles, gameColor, height, width) ;

    ///BOUTON RETURN
    al_draw_text(gameFont, gameColor, (5*width/32 - width/384)/2 + police/10, (2*height/27-height/216)/2 - police/3, ALLEGRO_ALIGN_CENTER, "RETURN") ;
    al_draw_rectangle(width/384, height/216, 5*width/32, 2*height/27, gameColor, 3) ;
    al_draw_textf(gameFont, gameColor, 7.5 * width / 15, 11 * height / 13 + height / 18, ALLEGRO_ALIGN_CENTER, "%d / %d", *pages, RULESPAGEMAX) ;
}

void afficherPages(int pages, ALLEGRO_FONT* gameFontRegles, ALLEGRO_COLOR gameColor, float height, float width ) {
    switch(pages){
        case 1 : {
            //x1 : width/5, y1 : height/6 , x2: 4*width/5 , y2 : 5*height/6
            al_draw_text(gameFontRegles, gameColor, 95 * width / 192 , height/ 5.4, ALLEGRO_ALIGN_CENTER, "Regles ") ;
            al_draw_textf(gameFontRegles, gameColor, width/4.8 , height/ 3.6, ALLEGRO_ALIGN_LEFT, "       Classes :  ") ;
            al_draw_textf(gameFontRegles, gameColor, width/4.8 , 35 * height / 108, ALLEGRO_ALIGN_LEFT, " Au debut du jeu, chaque joueur a le choix entre plusieurs Classes. ") ;
            al_draw_textf(gameFontRegles, gameColor, width/4.8 , height/ 2.7, ALLEGRO_ALIGN_LEFT, " La classe d'un personnage definit son apparence et les sorts dont il dispose. ") ;
            al_draw_textf(gameFontRegles, gameColor, width/4.8 , 25 * height/ 54, ALLEGRO_ALIGN_LEFT, "       Tour : ");
            al_draw_textf(gameFontRegles, gameColor, width/4.8 , 55 * height / 108, ALLEGRO_ALIGN_LEFT, " Lorsque c'est a un joueur de jouer, il dispose de 15 secondes pour faire ses ");
            al_draw_textf(gameFontRegles, gameColor, width/4.8 , height/ 1.8, ALLEGRO_ALIGN_LEFT, " actions, dans n'importe quel ordre : ");
            al_draw_textf(gameFontRegles, gameColor, width/4.8 , 65 * height / 108, ALLEGRO_ALIGN_LEFT, " - Se deplacer, dans la limite de ses PM, ");
            al_draw_textf(gameFontRegles, gameColor, width/4.8 , 35*height/54, ALLEGRO_ALIGN_LEFT, " - Attaquer, dans la limite de ses PA, ");
            al_draw_textf(gameFontRegles, gameColor, width/4.8 , height/1.44, ALLEGRO_ALIGN_LEFT, " - Passer son tour. ");
            break;
        }
        case 2 : {
            al_draw_text(gameFontRegles, gameColor, 95 * width/192 , height/5.4, ALLEGRO_ALIGN_CENTER, "Suite ") ;
            al_draw_textf(gameFontRegles, gameColor, width/4.8 , height/3.6, ALLEGRO_ALIGN_LEFT, " Au bout de 15 secondes, le jeu passe automatiquement au personnage ") ;
            al_draw_textf(gameFontRegles, gameColor, width/4.8 , 35*height/108, ALLEGRO_ALIGN_LEFT, " suivant. Si le joueur termine ses actions avant les 15s, il peut cliquer sur") ;
            al_draw_textf(gameFontRegles, gameColor, width/4.8 , height/2.7, ALLEGRO_ALIGN_LEFT, " le bouton Personnage suivant") ;
            al_draw_textf(gameFontRegles, gameColor, width/4.8 , height/2.16, ALLEGRO_ALIGN_LEFT, "       Attaques : ") ;
            al_draw_textf(gameFontRegles, gameColor, width/4.8 , 55*height/108, ALLEGRO_ALIGN_LEFT, " Le but du jeu etant de gagner la bataille, chaque joueur, peut, lorsque c'est ");
            al_draw_textf(gameFontRegles, gameColor, width/4.8 , height/1.8, ALLEGRO_ALIGN_LEFT, " son tour, lancer des sorts ou attaquer au corps a corps. Lorsqu'un ");
            al_draw_textf(gameFontRegles, gameColor, width/4.8 , 65*height/108, ALLEGRO_ALIGN_LEFT, " personnage subit une attaque, il perd des PV calcules aleatoirement ");
            al_draw_textf(gameFontRegles, gameColor, width/4.8 , 35*height/54, ALLEGRO_ALIGN_LEFT, " en fonction de la puissance de l'attaque. Par exemple une attaque ");
            al_draw_textf(gameFontRegles, gameColor, width/4.8 , height/1.44, ALLEGRO_ALIGN_LEFT, " enleve 8 PV, plus ou moins 4 PV, et elle a une chance sur 12 d'echouer.");
            break;
        }
        case 3 : {
            al_draw_text(gameFontRegles, gameColor, 95*width/192 , height/5.4, ALLEGRO_ALIGN_CENTER, "Suite ") ;
            al_draw_textf(gameFontRegles, gameColor, width/4.8 , height/3.6, ALLEGRO_ALIGN_LEFT, "       Attaque au corps a corps : ") ;
            al_draw_textf(gameFontRegles, gameColor, width/4.8 , 35* height/108, ALLEGRO_ALIGN_LEFT, " L'attaque au corps a corps n'est possible que sur les cases adjacentes ") ;
            al_draw_textf(gameFontRegles, gameColor, width/4.8 , height/2.7, ALLEGRO_ALIGN_LEFT, " (voisines). Elles sont beaucoup moins puissantes qu'un sort, mais ne coutent") ;
            al_draw_textf(gameFontRegles, gameColor, width/4.8 , height/2.4, ALLEGRO_ALIGN_LEFT, " que 2 PA. Elles peuvent enlever entre 1 et 5 PV a l'ennemi, avec 1 chance ") ;
            al_draw_textf(gameFontRegles, gameColor, width/4.8 , height/2.16, ALLEGRO_ALIGN_LEFT, " sur 10 d'echouer (et donc n'enlever aucun PV).") ;
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

    al_draw_scaled_bitmap(team, 0, 0, 1034, 704, (width/5) + (3*width/32), height/5 + height/27, 1034*1.05, 704*1.05, 0) ;
    ///ON FAIT SURBRILLER LES CASES RETURN ET LES BOUTONS SI LA SOURIS SE TROUVE DESSUS
    if ((float) mouse_x < 5*width/32 && mouse_x > width/384 && (float) mouse_y < 2*height/27 && mouse_y > height/216) {
        al_draw_filled_rectangle(width/384, height/216, 5*width/32, 2*height/27, al_map_rgb(200,200,200)) ;
    }
    else   al_draw_filled_rectangle(width/384, height/216, 5*width/32, 2*height/27, al_map_rgb(250,250,250)) ;

    ///Zelie
    al_draw_text(gameFont, gameColor, width/4 , height/5.4, ALLEGRO_ALIGN_CENTER, "Zelie") ;

    ///Nel
    al_draw_text(gameFont, gameColor, 3*width/4 , height/5.4, ALLEGRO_ALIGN_CENTER, "Nel") ;

    ///FARES
    al_draw_text(gameFont, gameColor, width / 4 , height/1.35, ALLEGRO_ALIGN_CENTER, "Fares") ;

    ///ILAYDA
    al_draw_text(gameFont, gameColor, 3*width/4 , height/1.35, ALLEGRO_ALIGN_CENTER, "Ilayda") ;

    ///BOUTON RETURN
    al_draw_text(gameFont, gameColor, (5*width/32 - width/384)/2 + police/10, (2*height/27-height/216)/2 - police/3, ALLEGRO_ALIGN_CENTER, "RETURN") ;
    al_draw_rectangle(width/384, height/216, 5*width/32, 2*height/27, gameColor, 3) ;
}

void drawMenuV2(Menu* mainMenu, ALLEGRO_FONT *gameFont) {
    float thickness1 = (float)(322*mainMenu->ecran.height/495 - 4*mainMenu->ecran.height/9) / 40 ;
    float thickness2 = (float)(38*mainMenu->ecran.height/99 - 7*mainMenu->ecran.height/80) / 40 ;
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

void menuSouris(Menu* mainMenu, InfoEcran ecran) {
    /// SI LA SOURIS LE SITUE SUR UN DES BOUTONS DU MENU, ON CHANGE L'ANGLE DE L'ARC
    if (ecran.mouse_x < 157* ecran.width/275 && ecran.mouse_x > 118*ecran.width/275 && ecran.mouse_y < 38*ecran.height/99 && ecran.mouse_y > 7*ecran.height/80) {
        mainMenu->playRect = 1 ;
        mainMenu->arc.startTheta = 4*PI/3 ;
        mainMenu->arc.endTheta = 2*PI/5 ;
    }
    else if (ecran.mouse_x < 49*ecran.width/110 && ecran.mouse_x > 21*ecran.width/110 && ecran.mouse_y < 322*ecran.height/495 && ecran.mouse_y > 4*ecran.height/9) {
        mainMenu->rulesRect = 1 ;
        mainMenu->arc.startTheta = 3*PI/4 ;
        mainMenu->arc.endTheta = 4*PI/11 ;
    }
    else if (ecran.mouse_x < 89*ecran.width/110 && ecran.mouse_x > 61*ecran.width/110 && ecran.mouse_y < 322*ecran.height/495 && ecran.mouse_y > 4*ecran.height/9) {
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