#include "jeu.h"

void initialiserIconeClasse(ALLEGRO_BITMAP* pacman, ALLEGRO_BITMAP* kirby, ALLEGRO_BITMAP* peach, ALLEGRO_BITMAP* mario, ALLEGRO_BITMAP* donkey_kong, Classe* classes) {
    classes[KIRBY].image = kirby ;
    classes[PACMAN].image = pacman ;
    classes[PEACH].image = peach ;
    classes[MARIO].image = mario ;
    classes[DONKEY_KONG].image = donkey_kong;
}

void initialiserSortClasseKIRBY (Classe* classe, ALLEGRO_BITMAP* sortFatal, ALLEGRO_BITMAP* sortFlemme, ALLEGRO_BITMAP* sortRalentir, ALLEGRO_BITMAP* sortSpecial, ALLEGRO_BITMAP* sortStop, ALLEGRO_BITMAP* sortReculer, ALLEGRO_BITMAP* afficherSort, ALLEGRO_BITMAP* afficherPV){
    classe->sortADisposition[FLEMME].iconeSort = sortFlemme;
    classe->sortADisposition[RALENTIR].iconeSort = sortRalentir;
    classe->sortADisposition[SPECIAL].iconeSort = sortSpecial;
    classe->sortADisposition[STOP].iconeSort = sortStop;
    classe->sortADisposition[RECULER].iconeSort = sortReculer;
    classe->sortADisposition[FATAL].iconeSort = sortFatal;
    classe->sortADisposition[BARRE].iconeSort = afficherSort;
    classe->sortADisposition[PV].iconeSort = afficherPV;
}
void initialiserSortClassePACMAN (Classe* classe, ALLEGRO_BITMAP* sortFatal, ALLEGRO_BITMAP* sortFlemme, ALLEGRO_BITMAP* sortRalentir, ALLEGRO_BITMAP* sortSpecial, ALLEGRO_BITMAP* sortStop, ALLEGRO_BITMAP* sortReculer, ALLEGRO_BITMAP* afficherSort, ALLEGRO_BITMAP* afficherPV){
    classe->sortADisposition[FLEMME].iconeSort = sortFlemme;
    classe->sortADisposition[RALENTIR].iconeSort = sortRalentir;
    classe->sortADisposition[SPECIAL].iconeSort = sortSpecial;
    classe->sortADisposition[STOP].iconeSort = sortStop;
    classe->sortADisposition[RECULER].iconeSort = sortReculer;
    classe->sortADisposition[FATAL].iconeSort = sortFatal;
    classe->sortADisposition[BARRE].iconeSort = afficherSort;
    classe->sortADisposition[PV].iconeSort = afficherPV;
}
void initialiserSortClasseMARIO (Classe* classe, ALLEGRO_BITMAP* sortFatal, ALLEGRO_BITMAP* sortFlemme, ALLEGRO_BITMAP* sortRalentir, ALLEGRO_BITMAP* sortSpecial, ALLEGRO_BITMAP* sortStop, ALLEGRO_BITMAP* sortReculer, ALLEGRO_BITMAP* afficherSort, ALLEGRO_BITMAP* afficherPV){
    classe->sortADisposition[FLEMME].iconeSort = sortFlemme;
    classe->sortADisposition[RALENTIR].iconeSort = sortRalentir;
    classe->sortADisposition[SPECIAL].iconeSort = sortSpecial;
    classe->sortADisposition[STOP].iconeSort = sortStop;
    classe->sortADisposition[RECULER].iconeSort = sortReculer;
    classe->sortADisposition[FATAL].iconeSort = sortFatal;
    classe->sortADisposition[BARRE].iconeSort = afficherSort;
    classe->sortADisposition[PV].iconeSort = afficherPV;
}
void initialiserSortClassePEACH (Classe* classe, ALLEGRO_BITMAP* sortFatal, ALLEGRO_BITMAP* sortFlemme, ALLEGRO_BITMAP* sortRalentir, ALLEGRO_BITMAP* sortSpecial, ALLEGRO_BITMAP* sortStop, ALLEGRO_BITMAP* sortReculer, ALLEGRO_BITMAP* afficherSort, ALLEGRO_BITMAP* afficherPV){
    classe->sortADisposition[FLEMME].iconeSort = sortFlemme;
    classe->sortADisposition[RALENTIR].iconeSort = sortRalentir;
    classe->sortADisposition[SPECIAL].iconeSort = sortSpecial;
    classe->sortADisposition[STOP].iconeSort = sortStop;
    classe->sortADisposition[RECULER].iconeSort = sortReculer;
    classe->sortADisposition[FATAL].iconeSort = sortFatal;
    classe->sortADisposition[BARRE].iconeSort = afficherSort;
    classe->sortADisposition[PV].iconeSort = afficherPV;
}
void initialiserSortClasseDONKEYKONG (Classe* classe, ALLEGRO_BITMAP* sortFatal, ALLEGRO_BITMAP* sortFlemme, ALLEGRO_BITMAP* sortRalentir, ALLEGRO_BITMAP* sortSpecial, ALLEGRO_BITMAP* sortStop, ALLEGRO_BITMAP* sortReculer, ALLEGRO_BITMAP* afficherSort, ALLEGRO_BITMAP* afficherPV){
    classe->sortADisposition[FLEMME].iconeSort = sortFlemme;
    classe->sortADisposition[RALENTIR].iconeSort = sortRalentir;
    classe->sortADisposition[SPECIAL].iconeSort = sortSpecial;
    classe->sortADisposition[STOP].iconeSort = sortStop;
    classe->sortADisposition[RECULER].iconeSort = sortReculer;
    classe->sortADisposition[FATAL].iconeSort = sortFatal;
    classe->sortADisposition[BARRE].iconeSort = afficherSort;
    classe->sortADisposition[PV].iconeSort = afficherPV;
}


void initialiserJeu(Jeux* jeu) {
    jeu->gameMode = CHOIXNBJOUEUR ;
    jeu->info.nbJoueur = 0 ;
    jeu->info.joueurQuiJoue = 0 ;
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

void initialiserJoueur(Jeux* jeu, Map map[20][20]) {
    if(jeu->joueur == NULL) {
        jeu->joueur = malloc(jeu->info.nbJoueur * sizeof(Joueurs));
        for (int i = 0; i < jeu->info.nbJoueur; i++) {
            strcpy(jeu->joueur[i].pseudo, "");
            (jeu->joueur[i]).nbLettrePseudo = 0;
            jeu->joueur[i].classe = VIDE ;
        }
        jeu->joueur[0].x = map[0][0].x;
        jeu->joueur[0].y = map[0][0].y;
        jeu->joueur[0].caseX = 0;
        jeu->joueur[0].caseY = 0;
        jeu->joueur[0].caseXDepart = jeu->joueur[0].caseX;
        jeu->joueur[0].caseYDepart = jeu->joueur[0].caseY;
        jeu->joueur[0].dep = 0;
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
    al_draw_textf(gameFont, al_map_rgb(0, 0, 0), 1000, 75, ALLEGRO_ALIGN_CENTER, "Combien de joueurs etes vous ?");
    al_draw_filled_circle(5*width/24, height/2.16, 100, al_map_rgba(219, 112, 147, 200));
    al_draw_text(gameFont, al_map_rgb(0, 0, 0), width / 4.8, 95 * height / 216, ALLEGRO_ALIGN_CENTER, "2");
    al_draw_filled_circle(95*width/192, height/2.16, 100, al_map_rgba(219, 112, 147, 200));
    al_draw_text(gameFont, al_map_rgb(0, 0, 0), 95 * width / 192, 95 * height / 216, ALLEGRO_ALIGN_CENTER, "3");
    al_draw_filled_circle(width/1.28, height/2.16, 100, al_map_rgba(219, 112, 147, 200));
    al_draw_text(gameFont, al_map_rgb(0, 0, 0), width / 1.28, 95 * height / 216, ALLEGRO_ALIGN_CENTER, "4");

    /// si on est sur la case, elle change de couleur
    if((mouse_x - width/4.8)*(mouse_x - width/4.8) + (mouse_y - height/2.16)*(mouse_y - height/2.16) < 100*100){
        al_draw_filled_circle(width/4.8, height/2.16, 100, al_map_rgb(219, 112, 147));
        al_draw_text(gameFont, al_map_rgb(0, 0, 0), width / 4.8, 95 * height / 216, ALLEGRO_ALIGN_CENTER, "2");
    }
    else if((mouse_x - 95*width/192)*(mouse_x - 95*width/192) + (mouse_y - height/2.16)*(mouse_y - height/2.16) < 100*100){
        al_draw_filled_circle(95*width/192, height/2.16, 100, al_map_rgb(219, 112, 147));
        al_draw_text(gameFont, al_map_rgb(0, 0, 0), 95 * width / 192, 95 * height / 216, ALLEGRO_ALIGN_CENTER, "3");
    }
    else if((mouse_x - width/1.28)*(mouse_x - width/1.28) + (mouse_y - height/2.16)*(mouse_y - height/2.16) < 100*100){
        al_draw_filled_circle(width/1.28, height/2.16, 100, al_map_rgb(219, 112, 147));
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
    else if(jeu.joueur[jeu.info.nbJoueur-1].pseudo[0] != '\0') {
        if (((float) ecran.mouse_x - 1829*ecran.width/1920)*((float) ecran.mouse_x - 1829*ecran.width/1920) + ((float) ecran.mouse_y - 49*ecran.height/54)*((float) ecran.mouse_y - 49*ecran.height/54) < 80*80 ) {
            al_draw_filled_circle(1829*ecran.width/1920, 49*ecran.height/54, 80, al_map_rgb(200, 200, 200));
            al_draw_text(gameFont, al_map_rgb(0, 0, 0), 91*ecran.width/96, 191*ecran.height/216, ALLEGRO_ALIGN_CENTER, "PLAY") ;
        }
        else {
            al_draw_filled_circle(1829*ecran.width/1920, 49*ecran.height/54, 80, al_map_rgba(255, 255, 255, 200));
            al_draw_text(gameFont, al_map_rgb(0, 0, 0), 91*ecran.width/96, 191*ecran.height/216, ALLEGRO_ALIGN_CENTER, "PLAY") ;
        }
        al_draw_text(gameFont, al_map_rgb(0, 0, 0), ecran.width/2, 5*ecran.height/54, ALLEGRO_ALIGN_CENTER, "Entrez votre pseudo") ;
    }
    else al_draw_text(gameFont, al_map_rgb(0, 0, 0), ecran.width/2, 5*ecran.height/54, ALLEGRO_ALIGN_CENTER, "Entrez votre pseudo") ;
    if(jeu.joueur[jeu.info.joueurQuiJoue].classe != VIDE) {
        if (jeu.joueur[jeu.info.joueurQuiJoue].pseudo[0] == '\0') {
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
        switch (jeu.joueur[i].classe) {
            case KIRBY : al_draw_scaled_bitmap(jeu.classes[KIRBY].image, 0, 0, 4389, 4389, ecran.width/9 + i*tailleRectangle, 25*ecran.height/36, 17*ecran.width/64 - 7*ecran.width/64,17*ecran.width/64 - 7*ecran.width/64, 0) ; break ;
            case MARIO : al_draw_scaled_bitmap(jeu.classes[MARIO].image, 0, 0, 2000, 2000, ecran.width/9 + i*tailleRectangle,17.5*ecran.height/25, 17*ecran.width/64 - 7*ecran.width/64,17*ecran.width/64 - 7*ecran.width/64, 0); break ;
            case PACMAN : al_draw_scaled_bitmap(jeu.classes[PACMAN].image, 0, 0, 1000, 1000, ecran.width/9 + i*tailleRectangle,25 * ecran.height / 36, 17*ecran.width/64 - 7*ecran.width/64, 17*ecran.width/64 - 7*ecran.width/64, 0); break ;
            case PEACH : al_draw_scaled_bitmap(jeu.classes[PEACH].image, 0, 0, 1200, 1355, 23*ecran.width/192 + i*tailleRectangle,17.5*ecran.height/25, 17*ecran.width/64 - 8.2*ecran.width/64, 1355*(17*ecran.width/64 - 8.2*ecran.width/64)/1200, 0); break ;
            case DONKEY_KONG : al_draw_scaled_bitmap(jeu.classes[DONKEY_KONG].image, 0, 0, 1200, 1200, ecran.width/9 + i*tailleRectangle ,17.2*ecran.height/25, 17*ecran.width/64 - 7*ecran.width/64, 17*ecran.width/64 - 7*ecran.width/64, 0); break ;
        }
    }
}


int getRandomInteger(int min, int max){
    int nbAleatoire = rand()%(max-min+1)+min;
    return nbAleatoire;
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
                      ALLEGRO_ALIGN_CENTER, "%s", jeu.joueur[i].pseudo);
    }
}




// autre methode pour entrer un nom
/*
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
}*/



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

