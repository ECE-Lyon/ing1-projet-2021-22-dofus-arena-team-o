#include "jeu.h"

void initialiserIconeClasse(ALLEGRO_BITMAP* pacman, ALLEGRO_BITMAP* kirby, ALLEGRO_BITMAP* peach, ALLEGRO_BITMAP* mario, ALLEGRO_BITMAP* donkey_kong, ALLEGRO_BITMAP* pacmanRond, ALLEGRO_BITMAP* kirbyRond, ALLEGRO_BITMAP* peachRond, ALLEGRO_BITMAP* marioRond, ALLEGRO_BITMAP* donkey_kongRond, Classe* classes) {
    classes[KIRBY].image = kirby ;
    classes[PACMAN].image = pacman ;
    classes[PEACH].image = peach ;
    classes[MARIO].image = mario ;
    classes[DONKEY_KONG].image = donkey_kong;

    classes[KIRBY].icone = kirbyRond ;
    classes[PACMAN].icone = pacmanRond ;
    classes[PEACH].icone = peachRond ;
    classes[MARIO].icone = marioRond ;
    classes[DONKEY_KONG].icone = donkey_kongRond;
}

            /// INITIALISATION DES DIFFERENTS SORTS DES CLASSES///


void initialiserSortClasseKIRBY (Classe* classe, ALLEGRO_BITMAP* coupDePied, ALLEGRO_BITMAP* sortFlemme, ALLEGRO_BITMAP* poing){
    classe->sortADisposition[FLAMME].iconeSort = sortFlemme;
    classe->sortADisposition[FLAMME].portee = 3 ;
    classe->sortADisposition[FLAMME].degatsOUsoin = 40 ;
    classe->sortADisposition[FLAMME].PA = 4 ;


    classe->sortADisposition[COUPDEPIED].iconeSort =coupDePied;
    classe->sortADisposition[COUPDEPIED].portee = 1 ;
    classe->sortADisposition[COUPDEPIED].degatsOUsoin = 20 ;
    classe->sortADisposition[COUPDEPIED].PA = 3 ;

    classe->sortADisposition[POING].iconeSort = poing;
    classe->sortADisposition[POING].portee = 1 ;
    classe->sortADisposition[POING].degatsOUsoin = 30 ;
    classe->sortADisposition[POING].PA = 2 ;

}
void initialiserSortClassePACMAN (Classe* classe, ALLEGRO_BITMAP* reculerAdversaire, ALLEGRO_BITMAP* sortFlamme, ALLEGRO_BITMAP* sortDefence){
    classe->sortADisposition[FLAMME].iconeSort = sortFlamme;
    classe->sortADisposition[FLAMME].portee = 3 ;
    classe->sortADisposition[FLAMME].degatsOUsoin = 40 ;
    classe->sortADisposition[FLAMME].PA = 4 ;

    classe->sortADisposition[RECULERADVERSAIRE].iconeSort = reculerAdversaire;
    classe->sortADisposition[RECULERADVERSAIRE].portee = 1 ;
    classe->sortADisposition[RECULERADVERSAIRE].degatsOUsoin = 10 ;
    classe->sortADisposition[RECULERADVERSAIRE].PA = 2 ;

    classe->sortADisposition[SORTDEFENCE].iconeSort = sortDefence ;
    classe->sortADisposition[SORTDEFENCE].portee = 0 ;
    classe->sortADisposition[SORTDEFENCE].degatsOUsoin = 0 ;
    classe->sortADisposition[SORTDEFENCE].PA = 6 ;


}
void initialiserSortClasseMARIO (Classe* classe, ALLEGRO_BITMAP* sortCorona, ALLEGRO_BITMAP* sortFlamme, ALLEGRO_BITMAP* poing2){
    classe->sortADisposition[FLAMME].iconeSort = sortFlamme;
    classe->sortADisposition[FLAMME].portee = 3;
    classe->sortADisposition[FLAMME].degatsOUsoin = 40 ;
    classe->sortADisposition[FLAMME].PA = 4 ;

    classe->sortADisposition[POING2].iconeSort = poing2;
    classe->sortADisposition[POING2].portee = 1 ;
    classe->sortADisposition[POING2].degatsOUsoin = 10 ;
    classe->sortADisposition[POING2].PA = 2 ;

    classe->sortADisposition[CORONA].iconeSort = sortCorona;
    classe->sortADisposition[CORONA].portee = 5;
    classe->sortADisposition[CORONA].degatsOUsoin = 40 ;
    classe->sortADisposition[CORONA].PA = 4 ;

}
void initialiserSortClassePEACH (Classe* classe, ALLEGRO_BITMAP* sortFleur, ALLEGRO_BITMAP* sortSoin, ALLEGRO_BITMAP* coupDePied){
    classe->sortADisposition[SORTFLEUR].iconeSort = sortFleur;
    classe->sortADisposition[SORTFLEUR].portee = 3 ;
    classe->sortADisposition[SORTFLEUR].degatsOUsoin = 40 ;
    classe->sortADisposition[SORTFLEUR].PA = 4 ;

    classe->sortADisposition[SORTSOIN].iconeSort = sortSoin;
    classe->sortADisposition[SORTSOIN].portee = 0 ;
    classe->sortADisposition[SORTSOIN].degatsOUsoin = 25 ;
    classe->sortADisposition[SORTSOIN].PA = 4 ;

    classe->sortADisposition[COUPDEPIED].iconeSort = coupDePied;
    classe->sortADisposition[COUPDEPIED].portee = 1 ;
    classe->sortADisposition[COUPDEPIED].degatsOUsoin = 20 ;
    classe->sortADisposition[COUPDEPIED].PA = 2 ;

}
void initialiserSortClasseDONKEYKONG (Classe* classe, ALLEGRO_BITMAP* sortMortel, ALLEGRO_BITMAP* poingGANT, ALLEGRO_BITMAP* saut){
    classe->sortADisposition[MORTEL].iconeSort = sortMortel;
    classe->sortADisposition[MORTEL].portee = 1;
    classe->sortADisposition[MORTEL].degatsOUsoin = 60 ;
    classe->sortADisposition[MORTEL].PA = 6 ;

    classe->sortADisposition[POINGGANT].iconeSort = poingGANT;
    classe->sortADisposition[POINGGANT].portee = 1;
    classe->sortADisposition[POINGGANT].degatsOUsoin = 25 ;
    classe->sortADisposition[POINGGANT].PA = 3 ;

    classe->sortADisposition[SAUT].iconeSort = saut;
    classe->sortADisposition[SAUT].portee = 5 ;
    classe->sortADisposition[SAUT].degatsOUsoin = 0 ;
    classe->sortADisposition[SAUT].PA = 3 ;
}


/// CODE DU JEU ///
void initialiserJeu(Jeux* jeu) {
    jeu->gameMode = CHOIXNBJOUEUR ;
    jeu->gameMode2 = ORDRE ;
    jeu->info.nbJoueur = 0 ;
    jeu->info.joueurQuiJoue = 0 ;
    jeu->info.compteur = 0 ;
    jeu->info.collisionSourisMap[0][0] = 0 ;
    jeu->info.collisionSourisMap[1][0] = 0 ;
    if(jeu->joueur != NULL) {
        free(jeu->joueur) ;
    }
    jeu->joueur = NULL ;
    jeu->info.entrerPseudo = false ;
}
void initialiserEcran (InfoEcran* ecran, double width, double height) {
    ecran->width = width ;
    ecran->height = height ;
}
void initialiserJoueur(Jeux* jeu, Map map[30][30]) {
    if (jeu->joueur == NULL) {
        jeu->joueur = malloc(jeu->info.nbJoueur * sizeof(Joueurs));
        for (int i = 0; i < jeu->info.nbJoueur; i++) {
            strcpy(jeu->joueur[i].pseudo, "");
            (jeu->joueur[i]).nbLettrePseudo = 0;
            jeu->joueur[i].classe = VIDE;
            jeu->joueur[i].PV = 300;
            jeu->joueur[i].PA = 6 ;
            jeu->joueur[i].PM = 3 ;
            jeu->joueur[i].sortAppuye = 3;
            jeu->joueur[i].sortSpecial = 0 ;
            jeu->joueur[i].etat = 0;   // 0 en vie
            jeu->joueur[i].quelAnimation = RESPIRATION;
            jeu->joueur[i].xArrive = 0;
            jeu->joueur[i].yArrive = 0;
            jeu->joueur[i].dep = 0;
            jeu->joueur[i].caseX = (i % 2) * 18;
            jeu->joueur[i].caseY = (i % 2) * 13;
            jeu->joueur[i].caseXDepart = jeu->joueur[i].caseX;
            jeu->joueur[i].caseYDepart = jeu->joueur[i].caseY;
            jeu->joueur[i].x = map[(i%2) * 18][(i%2) * 13].x;
            jeu->joueur[i].y = map[(i%2) * 18][(i%2) * 13].y;
            map[(i%2) * 18][(i%2) * 13].joueurPresentDessus = i+1 ;
            if (i >= 2) {
                jeu->joueur[i].caseX = ((i+1)%2) * 18;
                jeu->joueur[i].caseY = (i%2) * 13;
                jeu->joueur[i].caseXDepart = jeu->joueur[i].caseX;
                jeu->joueur[i].caseYDepart = jeu->joueur[i].caseY;
                jeu->joueur[i].x = map[((i+1)%2) * 18][(i%2) * 13].x;
                jeu->joueur[i].y = map[((i+1)%2) * 18][(i%2) * 13].y;
                map[((i+1)%2) * 18][(i%2) * 13].joueurPresentDessus = i+1 ;
            }
        }
        /*jeu->joueur[0].caseX = 0 ;
            jeu->joueur[0].caseY = 0 ;
            jeu->joueur[0].caseXDepart = jeu->joueur[0].caseX;
            jeu->joueur[0].caseYDepart = jeu->joueur[0].caseY;
            jeu->joueur[0].x = map[0][0].x;
            jeu->joueur[0].y = map[0][0].y;

        jeu->joueur[1].caseX = 0 ;
        jeu->joueur[1].caseY = 13 ;
        jeu->joueur[1].caseXDepart = jeu->joueur[1].caseX;
        jeu->joueur[1].caseYDepart = jeu->joueur[1].caseY;
        jeu->joueur[1].x = map[0][13].x;
        jeu->joueur[1].y = map[0][13].y;

        jeu->joueur[2].caseX = 19 ;
        jeu->joueur[2].caseY = 0 ;
        jeu->joueur[2].caseXDepart = jeu->joueur[2].caseX;
        jeu->joueur[2].caseYDepart = jeu->joueur[2].caseY;
        jeu->joueur[2].x = map[17][0].x;
        jeu->joueur[2].y = map[17][0].y;

        jeu->joueur[3].caseX = 19 ;
        jeu->joueur[3].caseY = 13 ;
        jeu->joueur[3].caseXDepart = jeu->joueur[3].caseX;
        jeu->joueur[3].caseYDepart = jeu->joueur[3].caseY;
        jeu->joueur[3].x = map[10][8].x;
        jeu->joueur[3].y = map[10][8].y;
        map[5][5].obstacle=1;
    */
    }

}




void choixJoueur(float width, float height, int mouse_x, int mouse_y, ALLEGRO_FONT* gameFont, InfosSurLesJoueurs* infoJoueur) {
    /// FOND D'ECRAN GRISTARE
    al_draw_filled_rectangle(0, 0, width, height, al_map_rgba(150, 150, 150, 150));

    float police = 2 * width / 55;

    ///AFFICHAGE GRIS DU HAUT STYLE
    al_draw_filled_rectangle(0, 0, width, 5 * height / 27, al_map_rgb(100, 100, 100));
    al_draw_filled_triangle(0, 0, 0, 26*height/54, width/3.84, height/7.2, al_map_rgb(100, 100, 100));
    al_draw_filled_rectangle(0, 0, width, 4 * height / 27, al_map_rgb(150, 150, 150));
    al_draw_filled_triangle(0, 0, 0, 41*height/108, 37*width/192, height/7.2, al_map_rgb(150, 150, 150));
    ///LOGO SMASH DU COIN DROITE
    al_draw_filled_circle(29*width/32, height/13.5, width/32, al_map_rgb(100, 100, 100)) ;
    al_draw_filled_rectangle(7*width/8,   height/12, 15*width/16, height/10.8, al_map_rgb(150, 150, 150)) ;
    al_draw_filled_rectangle(341*width/384,   height/54, 347*width/384, 7*height/54, al_map_rgb(150, 150, 150)) ;

    /// BOUTON RETURN
    if ((float) mouse_x < 5*width/32 && mouse_x > width/384 && (float) mouse_y < 2*height/27 && mouse_y > height/216) {
        al_draw_filled_rectangle(width/384, height/216, 5*width/32, 2*height/27, al_map_rgb(200,200,200)) ;
        al_draw_text(gameFont, al_map_rgb(0, 0, 0), (5*width/32 - width/384)/2 + police/20, (2*height/27-height/216)/2 - police/3.5, ALLEGRO_ALIGN_CENTER, "RETURN") ;
    }
    else   {
        al_draw_filled_rectangle(width/384, height/216, 5*width/32, 2*height/27, al_map_rgb(255,255,255)) ;
        al_draw_text(gameFont, al_map_rgb(0, 0, 0), (5*width/32 - width/384)/2 + police/20, (2*height/27-height/216)/2 - police/3.5, ALLEGRO_ALIGN_CENTER, "RETURN") ;
    }

    /// BOUTON SUIVANT
    if(infoJoueur->nbJoueur != 0) {
        if ((float) mouse_x < 383 * width / 384 && mouse_x > width / 1.2 && (float) mouse_y < 215 * height / 216 &&
            mouse_y > height / 1.08) {
            al_draw_filled_rectangle(width / 1.2, 215 * height / 216, 383 * width / 384, height / 1.08,al_map_rgb(200, 200, 200));
            al_draw_text(gameFont, al_map_rgb(0, 0, 0), 59 * width / 64 - police / 50, 103 * height / 108 - police / 4,ALLEGRO_ALIGN_CENTER, "SUIVANT");
        } else {
            al_draw_filled_rectangle(width / 1.2, 215 * height / 216, 383 * width / 384, height / 1.08,al_map_rgb(255, 255, 255));
            al_draw_text(gameFont, al_map_rgb(0, 0, 0), 59 * width / 64 - police / 50, 103 * height / 108 - police / 4,ALLEGRO_ALIGN_CENTER, "SUIVANT");
        }
        al_draw_textf(gameFont, al_map_rgb(0, 0, 0), 95*width/192, height/1.6,ALLEGRO_ALIGN_CENTER, "Vous avez selectionne %d joueurs", infoJoueur->nbJoueur);

    }

    /// BOUTONS 2 3 4
    al_draw_textf(gameFont, al_map_rgb(0, 0, 0), width/1.92, 13*height/216, ALLEGRO_ALIGN_CENTER, "Combien de joueurs etes vous ?");
    al_draw_filled_circle(5*width/24, height/2.16, width/19.2, al_map_rgba(219, 112, 147, 200));
    al_draw_text(gameFont, al_map_rgb(0, 0, 0), width / 4.8, 95 * height / 216, ALLEGRO_ALIGN_CENTER, "2");
    al_draw_filled_circle(95*width/192, height/2.16, width/19.2, al_map_rgba(219, 112, 147, 200));
    al_draw_text(gameFont, al_map_rgb(0, 0, 0), 95 * width / 192, 95 * height / 216, ALLEGRO_ALIGN_CENTER, "3");
    al_draw_filled_circle(width/1.28, height/2.16, width/19.2, al_map_rgba(219, 112, 147, 200));
    al_draw_text(gameFont, al_map_rgb(0, 0, 0), width / 1.28, 95 * height / 216, ALLEGRO_ALIGN_CENTER, "4");

    /// si on est sur la case, elle change de couleur
    if((mouse_x - width/4.8)*(mouse_x - width/4.8) + (mouse_y - height/2.16)*(mouse_y - height/2.16) < width/19.2 * width/19.2){
        al_draw_filled_circle(width/4.8, height/2.16, width/19.2, al_map_rgb(219, 112, 147));
        al_draw_text(gameFont, al_map_rgb(0, 0, 0), width / 4.8, 95 * height / 216, ALLEGRO_ALIGN_CENTER, "2");
    }
    else if((mouse_x - 95*width/192)*(mouse_x - 95*width/192) + (mouse_y - height/2.16)*(mouse_y - height/2.16) < width/19.2 * width/19.2){
        al_draw_filled_circle(95*width/192, height/2.16, width/19.2, al_map_rgb(219, 112, 147));
        al_draw_text(gameFont, al_map_rgb(0, 0, 0), 95 * width / 192, 95 * height / 216, ALLEGRO_ALIGN_CENTER, "3");
    }
    else if((mouse_x - width/1.28)*(mouse_x - width/1.28) + (mouse_y - height/2.16)*(mouse_y - height/2.16) < width/19.2 * width/19.2){
        al_draw_filled_circle(width/1.28, height/2.16, width/19.2, al_map_rgb(219, 112, 147));
        al_draw_text(gameFont, al_map_rgb(0, 0, 0), width / 1.28, 95 * height / 216, ALLEGRO_ALIGN_CENTER, "4");
    }
}
void drawChooseCharacter(InfoEcran ecran, ALLEGRO_FONT* gameFont, Jeux jeu, ALLEGRO_FONT* bigGameFont) {
    al_draw_filled_rectangle(0, 0, ecran.width, ecran.height, al_map_rgba(150, 150, 150, 150));

    float police = 2 * ecran.width / 55;

    ///AFFICHAGE GRIS DU HAUT STYLE
    al_draw_filled_rectangle(0, 0, ecran.width, 5*ecran.height/27, al_map_rgb(100, 100, 100));
    al_draw_filled_triangle(0, 0, 0, ecran.height/2.16, ecran.width/3.84, ecran.height/7.2, al_map_rgb(100, 100, 100));
    al_draw_filled_rectangle(0, 0, ecran.width, 4 * ecran.height / 27, al_map_rgb(150, 150, 150));
    al_draw_filled_triangle(0, 0, 0, 41*ecran.height/108, 37*ecran.width/192, ecran.height/7.2, al_map_rgb(150, 150, 150));

    al_draw_filled_circle(29*ecran.width/32, ecran.height/13.5, ecran.width/32, al_map_rgb(100, 100, 100)) ;
    al_draw_filled_rectangle(7*ecran.width/8,   ecran.height/12, 15*ecran.width/16, ecran.height/10.8, al_map_rgb(150, 150, 150)) ;
    al_draw_filled_rectangle(341*ecran.width/384,   ecran.height/54, 347*ecran.width/384, 7*ecran.height/54, al_map_rgb(150, 150, 150)) ;

    ///PASSAGE AU CHOIX DU JOUEUR SUIVANT
    al_draw_textf(gameFont, al_map_rgb(0, 0, 0), ecran.width/2, 1*ecran.height/54, ALLEGRO_ALIGN_CENTER, "Joueur %d", jeu.info.joueurQuiJoue + 1) ;
    if(jeu.info.entrerPseudo == false) {
        al_draw_text(gameFont, al_map_rgb(0, 0, 0), ecran.width/2, 5*ecran.height/54, ALLEGRO_ALIGN_CENTER, "Choisissez un personnage") ;
    }
    else if(jeu.joueur[jeu.info.ordre[jeu.info.nbJoueur - 1]].pseudo[0] != '\0') {
        if (((float) ecran.mouse_x - 1829*ecran.width/1920)*((float) ecran.mouse_x - 1829*ecran.width/1920) + ((float) ecran.mouse_y - 49*ecran.height/54)*((float) ecran.mouse_y - 49*ecran.height/54) < 80*80 ) {
            al_draw_filled_circle(1829*ecran.width/1920, 49*ecran.height/54, ecran.width/24, al_map_rgb(200, 200, 200));
            al_draw_text(gameFont, al_map_rgb(0, 0, 0), 91*ecran.width/96, 191*ecran.height/216, ALLEGRO_ALIGN_CENTER, "PLAY") ;
        }
        else {
            al_draw_filled_circle(1829*ecran.width/1920, 49*ecran.height/54, ecran.width/24, al_map_rgba(255, 255, 255, 200));
            al_draw_text(gameFont, al_map_rgb(0, 0, 0), 91*ecran.width/96, 191*ecran.height/216, ALLEGRO_ALIGN_CENTER, "PLAY") ;
        }
        al_draw_text(gameFont, al_map_rgb(0, 0, 0), ecran.width/2, 5*ecran.height/54, ALLEGRO_ALIGN_CENTER, "Entrez votre pseudo") ;
    }
    else al_draw_text(gameFont, al_map_rgb(0, 0, 0), ecran.width/2, 5*ecran.height/54, ALLEGRO_ALIGN_CENTER, "Entrez votre pseudo") ;
    if(jeu.joueur[jeu.info.ordre[jeu.info.joueurQuiJoue]].classe != VIDE) {
        if (jeu.joueur[jeu.info.ordre[jeu.info.joueurQuiJoue]].pseudo[0] == '\0') {
            if (jeu.info.entrerPseudo == false) {
                al_draw_filled_rectangle(2 * ecran.width / 5, 7 * ecran.height / 27, 3 * ecran.width / 5,9 * ecran.height / 27, al_map_rgb(100, 100, 100));
                al_draw_text(gameFont, al_map_rgb(255, 255, 255), 2.5 * ecran.width / 5, 7.4 * ecran.height / 27,ALLEGRO_ALIGN_CENTER, "CONFIRMER");
            }
        }
        else if(jeu.info.nbJoueur-1 != jeu.info.joueurQuiJoue) {
            al_draw_filled_rectangle(2 * ecran.width / 5, 7 * ecran.height / 27, 3 * ecran.width / 5,9 * ecran.height / 27, al_map_rgb(100, 100, 100));
            al_draw_text(gameFont, al_map_rgb(255, 255, 255), 2.5 * ecran.width / 5, 7.4 * ecran.height / 27,ALLEGRO_ALIGN_CENTER, "JOUEUR SUIVANT");
        }
    }



    ///4 RECTANGLES DES JOUEURS
    float tailleRectangle = 17*ecran.width/64 - 7*ecran.width/64 + 61*ecran.width/192 - 17*ecran.width/64;
    al_draw_filled_rounded_rectangle(7*ecran.width/64, 2*ecran.height/3, 17*ecran.width/64, ecran.height+15, 10, 10,al_map_rgb(255 , 0 , 0));
    al_draw_text(bigGameFont, al_map_rgb(139, 0, 0), 5*(17*ecran.width/64 - 7*ecran.width/64)/6, 3*ecran.height/4, ALLEGRO_ALIGN_LEFT, "P1") ;

    al_draw_filled_rounded_rectangle(61*ecran.width/192, 2*ecran.height/3, 91*ecran.width/192, ecran.height+15, 10, 10,al_map_rgb(200 , 200 , 0));
    al_draw_text(bigGameFont, al_map_rgb(153, 153, 0), 13*(91*ecran.width/192 - 61*ecran.width/192)/6, 3*ecran.height/4, ALLEGRO_ALIGN_LEFT, "P2") ;

                        ///AFFICHER LE BON NOMBRE DE JOUEUR
    if(jeu.info.nbJoueur > 2) {
        al_draw_filled_rounded_rectangle(101 * ecran.width / 192, 2 * ecran.height / 3, 131 * ecran.width / 192,ecran.height + 15, 10, 10, al_map_rgb(0, 255, 0));
        al_draw_text(bigGameFont, al_map_rgb(0, 139, 0), 21 * (91 * ecran.width / 192 - 61 * ecran.width / 192) / 6,3 * ecran.height / 4, ALLEGRO_ALIGN_LEFT, "P3");
        if (jeu.info.nbJoueur > 3) {
            al_draw_filled_rounded_rectangle(47 * ecran.width / 64, 2 * ecran.height / 3, 57 * ecran.width / 64,ecran.height + 15, 10, 10, al_map_rgb(0, 69, 128));
            al_draw_text(bigGameFont, al_map_rgb(21, 21, 118),29 * (91 * ecran.width / 192 - 61 * ecran.width / 192) / 6, 3 * ecran.height / 4,ALLEGRO_ALIGN_LEFT, "P4");
        }
        else al_draw_filled_rounded_rectangle(47*ecran.width/64, 2*ecran.height/3, 57*ecran.width/64, ecran.height+15, 10, 10,al_map_rgb( 100, 100, 100));
    }
    else {
        al_draw_filled_rounded_rectangle(47*ecran.width/64, 2*ecran.height/3, 57*ecran.width/64, ecran.height+15, 10, 10,al_map_rgb( 100, 100, 100));
        al_draw_filled_rounded_rectangle(47*ecran.width/64 - tailleRectangle, 2*ecran.height/3, 57*ecran.width/64 - tailleRectangle, ecran.height+15, 10, 10,al_map_rgb( 100, 100, 100));
    }


    ///BOUTON RETURN
    if ((float) ecran.mouse_x < 5*ecran.width/32 && ecran.mouse_x > ecran.width/384 && (float) ecran.mouse_y < 2*ecran.height/27 && ecran.mouse_y > ecran.height/216) {
        al_draw_filled_rectangle(ecran.width/384, ecran.height/216, 5*ecran.width/32, 2*ecran.height/27, al_map_rgb(200,200,200)) ;
        al_draw_text(gameFont, al_map_rgb(0, 0, 0), (5*ecran.width/32 - ecran.width/384)/2 + police/20, (2*ecran.height/27-ecran.height/216)/2 - police/3.5, ALLEGRO_ALIGN_CENTER, "RETURN") ;
    }
    else   {
        al_draw_filled_rectangle(ecran.width/384, ecran.height/216, 5*ecran.width/32, 2*ecran.height/27, al_map_rgb(255,255,255)) ;
        al_draw_text(gameFont, al_map_rgb(0, 0, 0), (5*ecran.width/32 - ecran.width/384)/2 + police/20, (2*ecran.height/27-ecran.height/216)/2 - police/3.5, ALLEGRO_ALIGN_CENTER, "RETURN") ;
    }


    ///CHOISIR UN PERSONNAGE :
    /// ON DETERMINE LES PROPORTIONS DE CHAQUE IMAGE AVEC LA LONGUEUR DE CHAQUE CARRE (CEUX DU MILIEU LA)
    float longueurCarre = 5 * ecran.height / 9 - 7 * ecran.height / 18 ;
    /// 1) KIRBY
    float tailleKirby = 4389 / longueurCarre ;
    al_draw_filled_rectangle(25*ecran.width/144, 7*ecran.height/18, 5*ecran.width/18, 5*ecran.height/9, al_map_rgb(246, 97, 65));
    al_draw_rectangle(25*ecran.width/144, 7*ecran.height/18, 5*ecran.width/18, 5*ecran.height/9, al_map_rgb(100, 100, 100), 10);
    al_draw_scaled_bitmap(jeu.classes[KIRBY].image, 0, 0, 4389, 4389, 25*ecran.width/144, 7*ecran.height/18, 4389/tailleKirby,4389/tailleKirby, 0) ;

    ///2) PACMAN
    float taillePacman = 1000 / longueurCarre;
    al_draw_filled_rectangle(5*ecran.width/16, 7*ecran.height/18, 5*ecran.width/12,5*ecran.height/9, al_map_rgb(168, 218, 67));
    al_draw_rectangle(5*ecran.width/16, 7*ecran.height/18, 5*ecran.width/12,5*ecran.height/9, al_map_rgb(100, 100, 100), 10);
    al_draw_scaled_bitmap(jeu.classes[PACMAN].image, 0, 0, 1000, 1000, 5*ecran.width/16, 7*ecran.height/18, 1000/taillePacman ,1000/taillePacman, 0) ;

    ///3) PEACH
    float taillePeachX = 1200 / longueurCarre ;
    float taillePeachY = 1355 / longueurCarre ;
    al_draw_filled_rectangle(65*ecran.width/144, 7*ecran.height/18, 5*ecran.width/9, 5*ecran.height/9, al_map_rgb(240, 139, 229));
    al_draw_rectangle(65*ecran.width/144, 7*ecran.height/18, 5*ecran.width/9, 5*ecran.height/9, al_map_rgb(100, 100, 100), 10);
    al_draw_scaled_bitmap(jeu.classes[PEACH].image, 0, 0, 1200, 1355, 67*ecran.width/144, 7*ecran.height/18, 1200/taillePeachX ,1355/taillePeachY, 0) ;

    ///4) MARIO
    float tailleMario = 2000 / longueurCarre ;
    al_draw_filled_rectangle(85*ecran.width/144,7*ecran.height/18, 25*ecran.width/36, 5*ecran.height/9, al_map_rgb(139, 240, 228));
    al_draw_rectangle(85*ecran.width/144,7*ecran.height/18, 25*ecran.width/36, 5*ecran.height/9, al_map_rgb(100, 100, 100), 10);
    al_draw_scaled_bitmap(jeu.classes[MARIO].image, 0, 0, 2000, 2000, 86*ecran.width/144,7*ecran.height/18, 2000/tailleMario ,2000/tailleMario, 0) ;

    ///5) DONKEY KONG
    float tailleDonkey_kong = 1200/longueurCarre;
    al_draw_filled_rectangle(35*ecran.width/48,7*ecran.height/18, 5*ecran.width/6, 5*ecran.height/9, al_map_rgb(190, 130, 200));
    al_draw_rectangle(35*ecran.width/48,7*ecran.height/18, 5*ecran.width/6, 5*ecran.height/9, al_map_rgb(100, 100, 100), 10);
    al_draw_scaled_bitmap(jeu.classes[DONKEY_KONG].image, 0, 0, 1200, 1200,35.2*ecran.width/48 , 7*ecran.height/18 , 1200/tailleDonkey_kong, 1200/tailleDonkey_kong, 0) ;

    ///AFFICHAGE DU CHOIX DES JOUEURS
    for(int i = 0 ; i < jeu.info.nbJoueur ; i++) {
        switch (jeu.joueur[jeu.info.ordre[i]].classe) {
            case KIRBY : al_draw_scaled_bitmap(jeu.classes[KIRBY].image, 0, 0, 4389, 4389, ecran.width/9 + i*tailleRectangle, 25*ecran.height/36, 17*ecran.width/64 - 7*ecran.width/64,17*ecran.width/64 - 7*ecran.width/64, 0) ; break ;
            case MARIO : al_draw_scaled_bitmap(jeu.classes[MARIO].image, 0, 0, 2000, 2000, ecran.width/9 + i*tailleRectangle,17.5*ecran.height/25, 17*ecran.width/64 - 7*ecran.width/64,17*ecran.width/64 - 7*ecran.width/64, 0); break ;
            case PACMAN : al_draw_scaled_bitmap(jeu.classes[PACMAN].image, 0, 0, 1000, 1000, ecran.width/9 + i*tailleRectangle,25 * ecran.height / 36, 17*ecran.width/64 - 7*ecran.width/64, 17*ecran.width/64 - 7*ecran.width/64, 0); break ;
            case PEACH : al_draw_scaled_bitmap(jeu.classes[PEACH].image, 0, 0, 1200, 1355, 23*ecran.width/192 + i*tailleRectangle,17.5*ecran.height/25, 17*ecran.width/64 - 8.2*ecran.width/64, 1355*(17*ecran.width/64 - 8.2*ecran.width/64)/1200, 0); break ;
            case DONKEY_KONG : al_draw_scaled_bitmap(jeu.classes[DONKEY_KONG].image, 0, 0, 1200, 1200, ecran.width/9 + i*tailleRectangle ,17.2*ecran.height/25, 17*ecran.width/64 - 7*ecran.width/64, 17*ecran.width/64 - 7*ecran.width/64, 0); break ;
        }
    }
    afficherPseudo(jeu, ecran.width, ecran.height, gameFont) ;
}


char alphabet (int keycode, int* nbLettre){
    char lettreAppuye;
    if(keycode >= ALLEGRO_KEY_A && keycode <= ALLEGRO_KEY_Z) {
        lettreAppuye = (char) (keycode+96) ;
        return lettreAppuye ;
    }
    else if(keycode == ALLEGRO_KEY_BACKSPACE) {
        if(*nbLettre > 0) {
            (*nbLettre)--;
        }
        return '\0';
    }
    else if(keycode == ALLEGRO_KEY_SPACE) {
        return ' ';
    }
    else return 0 ;
}
void mettrePseudo(Joueurs** joueur, char lettre, int quelJoueurEstSelectionne, int* nbLettre) {
    if(*nbLettre+1 < MAXNOM) {
        (*joueur)[quelJoueurEstSelectionne].pseudo[*nbLettre] = lettre ;
        (*joueur)[quelJoueurEstSelectionne].pseudo[*nbLettre+1] = '\0' ;
    }
    if(lettre != '\0' && *nbLettre < MAXNOM-1) {
        (*nbLettre)++ ;
    }
    else {
        (*joueur)[quelJoueurEstSelectionne].pseudo[*nbLettre] = '\0' ;
    }
}
void afficherPseudo(Jeux jeu, float width, float height, ALLEGRO_FONT* gameFont) {
    for (int i = 0; i < jeu.info.nbJoueur; i++) {
        al_draw_textf(gameFont, al_map_rgb(20, 20, 20), 5*(17 * width / 64 - 7.5 * width / 64)/4 + (width/4.8)*i, 46 * height / 50,
                      ALLEGRO_ALIGN_CENTER, "%s", jeu.joueur[jeu.info.ordre[i]].pseudo);
    }
}



void boutonSuivantDansPlay(InfoEcran ecran, ALLEGRO_FONT* gameFont, int mouse_x, int mouse_y){
    float police = 2 * ecran.width / 55;
    if ((float) mouse_x < 383 * ecran.width / 384 && mouse_x > ecran.width / 1.2 && (float) mouse_y < ecran.height/13.5 && mouse_y >ecran.height/216) {
        al_draw_filled_rectangle(ecran.width / 1.2, ecran.height/216, 383 * ecran.width / 384, ecran.height/13.5,al_map_rgb(200, 200, 200));
        al_draw_text(gameFont, al_map_rgb(20, 20, 20), 59 * ecran.width / 64 - police / 50, ecran.height/54,ALLEGRO_ALIGN_CENTER, "SUIVANT");
    } else {
        al_draw_filled_rectangle(ecran.width / 1.2, ecran.height/216, 383 * ecran.width / 384, ecran.height/13.5,al_map_rgb(240, 240, 240));
        al_draw_text(gameFont, al_map_rgb(20, 20, 20), 59 * ecran.width / 64 - police / 50, ecran.height/54,ALLEGRO_ALIGN_CENTER, "SUIVANT");
    }
}
void afficherCaracteristiqueJoueur(Jeux jeu, InfoEcran ecran, int joueurQuiJoue, ALLEGRO_FONT* gameFont) {
    for(int i = 0 ; i < jeu.info.nbJoueur ; i++) {
        if(i != joueurQuiJoue) {
            if (i <=  joueurQuiJoue) {
                al_draw_textf(gameFont, al_map_rgb(20, 20, 20), 17*ecran.width/192, 19*ecran.height/216 + i*5*ecran.height/36, ALLEGRO_ALIGN_LEFT, "%s", jeu.joueur[i].pseudo) ;
                al_draw_filled_rectangle(5*ecran.width/96, ecran.height/8 + i*5*ecran.height/36, 5*ecran.width/32, ecran.height/8 + i*5*ecran.height/36 + 7 * ecran.height / 108,al_map_rgb(50, 50, 50) ) ;
                al_draw_textf(gameFont, al_map_rgb(150, 150, 150), 11*ecran.width/96, ecran.height/8 + (7 * ecran.height / 108)/4 + i*5*ecran.height/36, ALLEGRO_ALIGN_CENTER, "%d", jeu.joueur[i].PV );
                al_draw_filled_rectangle(5*ecran.width/96, 7*ecran.height/54 + i*5*ecran.height/36, jeu.joueur[i].PV*(59*ecran.width/384)/300, 7*ecran.height/54 + i*5*ecran.height/36 + ecran.height / 18,al_map_rgb(0, 255, 128) ) ;
                al_draw_filled_circle(5*ecran.width/96,ecran.height/8 + i*5*ecran.height/36, 7 * ecran.width / 192, al_map_rgb(50, 50, 50));
                al_draw_scaled_bitmap(jeu.classes[jeu.joueur[i].classe].icone, 0, 0, 979, 977, ecran.width/48,5*ecran.height/72 + i*5*ecran.height/36, ecran.width / 16, ecran.width / 16, 0);
            }
            else {
                al_draw_textf(gameFont, al_map_rgb(20, 20, 20), 17*ecran.width/192, 19*ecran.height/216 + (i-1)*5*ecran.height/36, ALLEGRO_ALIGN_LEFT, "%s", jeu.joueur[i].pseudo) ;
                al_draw_filled_rectangle(5*ecran.width/96, ecran.height/8 + (i-1)*5*ecran.height/36, 5*ecran.width/32, ecran.height/8 + (i-1)*5*ecran.height/36 + 7 * ecran.height / 108,al_map_rgb(50, 50, 50) ) ;
                al_draw_textf(gameFont, al_map_rgb(150, 150, 150), 11*ecran.width/96, ecran.height/8 + (7 * ecran.height / 108)/4 + (i-1)*5*ecran.height/36, ALLEGRO_ALIGN_CENTER, "%d", jeu.joueur[i].PV );
                al_draw_filled_rectangle(5*ecran.width/96, 7*ecran.height/54 + (i-1)*5*ecran.height/36, jeu.joueur[i].PV*(59*ecran.width/384)/300, 7*ecran.height/54 + (i-1)*5*ecran.height/36 + ecran.height / 18,al_map_rgb(0, 255, 128) ) ;
                al_draw_filled_circle(5*ecran.width/96,ecran.height/8 + (i-1)*5*ecran.height/36, 7 * ecran.width / 192, al_map_rgb(50, 50, 50));
                al_draw_scaled_bitmap(jeu.classes[jeu.joueur[i].classe].icone, 0, 0, 979, 977, ecran.width/48 ,5*ecran.height/72 + (i-1)*5*ecran.height/36, ecran.width / 16, ecran.width / 16, 0);
            }
        }
    }

    al_draw_filled_circle(35*ecran.width/384, 64*ecran.height/72, 5*ecran.width/96 , al_map_rgb(0, 0, 0)) ;
    al_draw_scaled_bitmap(jeu.classes[jeu.joueur[jeu.info.joueurQuiJoue].classe].icone, 0, 0, 979, 977, 5*ecran.width/96, 59*ecran.height/72, 5*ecran.width/64, 5*ecran.width/64, 0) ;
    al_draw_arc(35*ecran.width/384, 64*ecran.height/72, 17*ecran.width/384, PI/2, jeu.joueur[joueurQuiJoue].PV*(3*PI/2)/300, al_map_rgb(0, 255, 128), ecran.width/96) ;
    al_draw_textf(gameFont, al_map_rgb(50, 50, 50), 65*ecran.width/384, 65*ecran.height/72, ALLEGRO_ALIGN_LEFT, "PA   %d", jeu.joueur[jeu.info.joueurQuiJoue].PA) ;
    al_draw_textf(gameFont, al_map_rgb(50, 50, 50), 65*ecran.width/384, 68*ecran.height/72, ALLEGRO_ALIGN_LEFT, "PM   %d", jeu.joueur[jeu.info.joueurQuiJoue].PM) ;
    al_draw_textf(gameFont, al_map_rgb(50, 50, 50), 85*ecran.width/384, 66.5*ecran.height/72, ALLEGRO_ALIGN_LEFT, "PV   %d", jeu.joueur[jeu.info.joueurQuiJoue].PV) ;

}


void dessinerChrono ();
/// Ordre aléatoire des joueurs

int getRandomInteger(int min, int max){
    int nbAleatoire = rand()%(max-min+1)+min;
    return nbAleatoire;
}
int verifierValeurTableau(int tab[], int valeurAverifier, int cbDeValeur) {
    int i, j = 0;
    for (i = 0; i < cbDeValeur; i++) {
        if (tab[i] == valeurAverifier) {
            j = 1;
        }
    }
    return j;
}
int ordreDesJoueurs(InfosSurLesJoueurs* joueurs, int nbJoueur){
    int i, valeur;
    int tab[4] = {10, 10, 10, 10};
    for(i = 0; i < nbJoueur; i++){
        valeur = getRandomInteger(0, nbJoueur-1);
        if(verifierValeurTableau(tab, valeur, nbJoueur) == 0){
            joueurs->ordre[i] = valeur;
            tab[i] = valeur;
        }
        else {
            i--;
        }
    }
}

void afficherOrdre(Jeux jeu, InfoEcran ecran, ALLEGRO_FONT* gameFont) {
    /// FOND D'ECRAN GRISTARE
    al_draw_filled_rectangle(0, 0, ecran.width, ecran.height, al_map_rgba(150, 150, 150, 150));
    al_draw_filled_rounded_rectangle(ecran.width/3, ecran.height/6, 2*ecran.width/3, 5*ecran.height/6, 15, 15,al_map_rgb(150, 150, 150)) ;

    al_draw_filled_circle(ecran.width/2, ecran.height/2, ecran.height/4, al_map_rgba(100, 100, 100, 140)) ;
    al_draw_filled_rectangle(20*ecran.width/48, ecran.height/2-ecran.height/4, 23*ecran.width/48, ecran.height/2+ecran.height/4, al_map_rgb(150, 150, 150)) ;
    al_draw_filled_rectangle(ecran.width/2-ecran.height/4, 30*ecran.height/54, ecran.width/2+ecran.height/4, 33*ecran.height/54, al_map_rgb(150, 150, 150)) ;

    al_draw_text(gameFont, al_map_rgb(250, 250, 250), ecran.width/2, 2*ecran.height/11, ALLEGRO_ALIGN_CENTER, "ORDRE DES JOUEURS") ;
    for(int i = 0 ; i < jeu.info.nbJoueur ; i++) {
        al_draw_textf(gameFont, al_map_rgb(250, 250, 250), 16.5*ecran.width/48, 2*ecran.height/7 + (5*ecran.width/96)*i, ALLEGRO_ALIGN_LEFT, "%d", i+1);
        al_draw_scaled_bitmap(jeu.classes[jeu.joueur[i].classe].icone, 0, 0, 979, 977, 17.5*ecran.width/48 ,2*ecran.height/7 + (5*ecran.width/96)*i - (5*ecran.width/350), (5*ecran.width/96), (5*ecran.width/96), 0) ;
        al_draw_textf(gameFont, al_map_rgb(250, 250, 250), 21*ecran.width/48, 2*ecran.height/7 + (5*ecran.width/96)*i, ALLEGRO_ALIGN_LEFT, "%s", jeu.joueur[i].pseudo);
    }
    if((ecran.mouse_x - 9 * ecran.width / 15) * (ecran.mouse_x - 9 * ecran.width / 15) + (ecran.mouse_y - 10 * ecran.height / 13) * (ecran.mouse_y - 10 * ecran.height / 13) < ecran.width / 38.4 * ecran.width / 38.4) {
        al_draw_filled_circle(9 * ecran.width / 15, 10 * ecran.height / 13, ecran.width / 38.4, al_map_rgb(100, 100, 100));
    }

    al_draw_circle(9*ecran.width/15, 10*ecran.height/13, ecran.width/38.4, al_map_rgb(250, 250, 250), 4) ;
    al_draw_line(9*ecran.width/15 - ecran.width/64 , 10*ecran.height/13, 9*ecran.width/15 + ecran.width/64, 10*ecran.height/13, al_map_rgb(250, 250, 250), 3);
    al_draw_line(9*ecran.width/15 + ecran.width/64, 10*ecran.height/13, 9*ecran.width/15 + ecran.width/192, 10*ecran.height/13 - ecran.height/43.2 , al_map_rgb(250, 250, 250), 3);
    al_draw_line(9*ecran.width/15 + ecran.width/64, 10*ecran.height/13, 9*ecran.width/15 + ecran.width/192, 10*ecran.height/13 + ecran.height/43.2 , al_map_rgb(250, 250, 250), 3);


}


