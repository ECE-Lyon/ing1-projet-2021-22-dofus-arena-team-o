#include "jeu.h"

void initialiserEcran (InfoEcran* ecran, double width, double height) {
    ecran->width = width ;
    ecran->height = height ;
}

void initialiserJoueur(Joueurs* joueur, InfosSurLesJoueurs* infoJoueur) {
    for(int i = 0 ; i < 4 ; i++) {
        strcpy(joueur[i].pseudo, "");
        joueur[i].nbLettrePseudo = 0 ;
    }
    infoJoueur->nbJoueur = 0 ;
    infoJoueur->joueurQuiJoue = 0 ;
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

    ///LOGO SMASH DU COIN
    al_draw_filled_circle(29*width/32, height/13.5, width/32, al_map_rgb(100, 100, 100)) ;
    al_draw_filled_rectangle(7*width/8,   height/12, 15*width/16, height/10.8, al_map_rgb(150, 150, 150)) ;
    al_draw_filled_rectangle(341*width/384,   height/54, 347*width/384, 7*height/54, al_map_rgb(150, 150, 150)) ;

    /// BOUTON RETURN
    if ((float) mouse_x < 5*width/32 && mouse_x > width/384 && (float) mouse_y < 2*height/27 && mouse_y > height/216) {
        al_draw_filled_rectangle(width/384, height/216, 5*width/32, 2*height/27, al_map_rgb(200,200,200)) ;
        al_draw_text(gameFont, al_map_rgb(0, 0, 0), (5*width/32 - width/384)/2 + police/10, (2*height/27-height/216)/2 - police/3, ALLEGRO_ALIGN_CENTER, "RETURN") ;
    }
    else   {
        al_draw_filled_rectangle(width/384, height/216, 5*width/32, 2*height/27, al_map_rgb(255,255,255)) ;
        al_draw_text(gameFont, al_map_rgb(0, 0, 0), (5*width/32 - width/384)/2 + police/10, (2*height/27-height/216)/2 - police/3, ALLEGRO_ALIGN_CENTER, "RETURN") ;
    }

    /// BOUTON SUIVANT
    if ((float) mouse_x < 383*width/384 && mouse_x > width/1.2 && (float) mouse_y < 215*height/216 && mouse_y > height/1.08) {
        al_draw_filled_rectangle(width/1.2, 215*height/216, 383*width/384, height/1.08, al_map_rgb(200,200,200)) ;
        al_draw_text(gameFont, al_map_rgb(0, 0, 0), 59*width/64 + police/10, 103*height/108 - police/3, ALLEGRO_ALIGN_CENTER, "SUIVANT") ;
    }
    else   {
        al_draw_filled_rectangle(width/1.2, 215*height/216, 383*width/384, height/1.08, al_map_rgb(255,255,255)) ;
        al_draw_text(gameFont, al_map_rgb(0, 0, 0), 59*width/64 + police/10, 103*height/108 - police/3, ALLEGRO_ALIGN_CENTER, "SUIVANT") ;
    }

    /// BOUTONS 2 3 4
    al_draw_textf(gameFont, al_map_rgb(0, 0, 0), 1000, 75, ALLEGRO_ALIGN_CENTER, "Combien de joueurs etes vous ?");
    al_draw_filled_circle(5*width/24, height/2.16, 100, al_map_rgba(219, 112, 147, 200));
    al_draw_text(gameFont, al_map_rgb(0, 0, 0), width / 4.8, 95 * height / 216, ALLEGRO_ALIGN_CENTER, "2");
    al_draw_filled_circle(95*width/192, height/2.16, 100, al_map_rgba(219, 112, 147, 200));
    al_draw_text(gameFont, al_map_rgb(0, 0, 0), 95 * width / 192, 95 * height / 216, ALLEGRO_ALIGN_CENTER, "3");
    al_draw_filled_circle(width/1.28, height/2.16, 100, al_map_rgba(219, 112, 147, 200));
    al_draw_text(gameFont, al_map_rgb(0, 0, 0), width / 1.28, 95 * height / 216, ALLEGRO_ALIGN_CENTER, "4");
    al_draw_textf(gameFont, al_map_rgb(0, 0, 0), 95*width/192, height/1.6,ALLEGRO_ALIGN_CENTER, "Vous avez selectionne %d joueurs", infoJoueur->nbJoueur);

    // si on est sur la case, elle change de couleur
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

void drawChooseCharacter(InfoEcran ecran, ALLEGRO_FONT* gameFont, int* nbJoueur, Joueurs** joueur, ALLEGRO_BITMAP* kirby, ALLEGRO_BITMAP* pacman) {
    al_draw_filled_rectangle(0, 0, ecran.width, ecran.height, al_map_rgba(150, 150, 150, 150));

    float police = 2 * ecran.width / 55;

    al_draw_filled_rectangle(0, 0, ecran.width, 5 * ecran.height / 27, al_map_rgb(100, 100, 100));
    al_draw_filled_triangle(0, 0, 0, ecran.height/2.16, ecran.width/3.84, ecran.height/7.2, al_map_rgb(100, 100, 100));
    al_draw_filled_rectangle(0, 0, ecran.width, 4 * ecran.height / 27, al_map_rgb(150, 150, 150));
    al_draw_filled_triangle(0, 0, 0, 41*ecran.height/108, 37*ecran.width/192, ecran.height/7.2, al_map_rgb(150, 150, 150));

    al_draw_filled_circle(29*ecran.width/32, ecran.height/13.5, ecran.width/32, al_map_rgb(100, 100, 100)) ;
    al_draw_filled_rectangle(7*ecran.width/8,   ecran.height/12, 15*ecran.width/16, ecran.height/10.8, al_map_rgb(150, 150, 150)) ;
    al_draw_filled_rectangle(341*ecran.width/384,   ecran.height/54, 347*ecran.width/384, 7*ecran.height/54, al_map_rgb(150, 150, 150)) ;

    /** Met pas cet merde la
    for(int i = 0 ; i < 4 ; i++) {
        al_draw_filled_rounded_rectangle(width/2 - width/3.2 - width/7.68 + i*width/3.84, 2*height/3, (width/2 - width/3.2 - width/7.68 + i*width/3.84) + width/6.4, height+height/15, 10, 10,
                                         al_map_rgb(105-10*i, 60*i , 100 + 50*i)) ;
        al_draw_filled_rounded_rectangle(width/2 - 600 - 150 + i*400, 2*height/3, (width/2 - 600 - 150 + i*400) + 300, height+15, 10, 10,
                                         al_map_rgb(255 - i*255, 0 + 128*i , 0 + 128/2*i + 50*i)) ;
    }**/
    al_draw_filled_rounded_rectangle(7*ecran.width/64, 2*ecran.height/3, 17*ecran.width/64, ecran.height+15, 10, 10,
                                     al_map_rgb(255 , 0 , 0));
    al_draw_filled_rounded_rectangle(61*ecran.width/192, 2*ecran.height/3, 91*ecran.width/192, ecran.height+15, 10, 10,
                                     al_map_rgb(200 , 200 , 0));
    al_draw_filled_rounded_rectangle(101*ecran.width/192, 2*ecran.height/3, 131*ecran.width/192, ecran.height+15, 10, 10,
                                     al_map_rgb( 0, 255, 0));
    al_draw_filled_rounded_rectangle(47*ecran.width/64, 2*ecran.height/3, 57*ecran.width/64, ecran.height+15, 10, 10,
                                     al_map_rgb( 0, 69, 128));

    ////////////bouton return/////////////
    if ((float) ecran.mouse_x < 5*ecran.width/32 && ecran.mouse_x > ecran.width/384 && (float)ecran.mouse_y < 2*ecran.height/27 && ecran.mouse_y > ecran.height/216) {
        al_draw_filled_rectangle(ecran.width/384, ecran.height/216, 5*ecran.width/32, 2*ecran.height/27, al_map_rgb(200,200,200)) ;
        al_draw_text(gameFont, al_map_rgb(0, 0, 0), (5*ecran.width/32 - ecran.width/384)/2 + police/10, (2*ecran.height/27-ecran.height/216)/2 - police/3, ALLEGRO_ALIGN_CENTER, "RETURN") ;
    }
    else   {
        al_draw_filled_rectangle(ecran.width/384, ecran.height/216, 5*ecran.width/32, 2*ecran.height/27, al_map_rgb(255,255,255));
        al_draw_text(gameFont, al_map_rgb(0, 0, 0), (5*ecran.width/32 - ecran.width/384)/2 + police/10, (2*ecran.height/27-ecran.height/216)/2 - police/3, ALLEGRO_ALIGN_CENTER, "RETURN") ;
    }


/////////////Choisir un personnage/////////////////

    al_draw_filled_rectangle(25*ecran.width/144, 7*ecran.height/18, 5*ecran.width/18, 5*ecran.height/9, al_map_rgb(246, 97, 65));
    al_draw_scaled_bitmap(kirby, 0, 0, 4389, 4389, 25*ecran.width/144, 7*ecran.height/18, 4389/24.383,4389/24.383, 0) ;

    al_draw_filled_rectangle(5*ecran.width/16, 7*ecran.height/18, 5*ecran.width/12,5*ecran.height/9, al_map_rgb(168, 218, 67));
    al_draw_scaled_bitmap(pacman, 0, 0, 1000, 1000, 5*ecran.width/16, 7*ecran.height/18, 1000/5.6 ,1000/5.6, 0) ;


    al_draw_filled_rectangle(65*ecran.width/144, 7*ecran.height/18, 5*ecran.width/9, 5*ecran.height/9, al_map_rgb(240, 139, 229));
    al_draw_filled_rectangle(85*ecran.width/144,7*ecran.height/18, 25*ecran.width/36, 5*ecran.height/9, al_map_rgb(139, 240, 228));
    al_draw_filled_rectangle(35*ecran.width/48,7*ecran.height/18, 5*ecran.width/6, 5*ecran.height/9, al_map_rgb(190, 130, 200));

    al_draw_filled_rectangle(ecran.width/8, 37*ecran.height/40, 143*ecran.width/576, 589*ecran.height/600, al_map_rgb(216, 216, 216));
    al_draw_filled_rectangle(ecran.width/3, 37*ecran.height/40, 263*ecran.width/576, 589*ecran.height/600, al_map_rgb(216, 216, 216));
    al_draw_filled_rectangle(13*ecran.width/24, 37*ecran.height/40, 383*ecran.width/576, 589*ecran.height/600, al_map_rgb(216, 216, 216));
    al_draw_filled_rectangle(3*ecran.width/4, 37*ecran.height/40, 503*ecran.width/576, 589*ecran.height/600, al_map_rgb(216, 216, 216)) ;

    // classe[MARIO] = (float) mouse_x < 800 && mouse_x > 500 && (float) mouse_y < 1000 && mouse_y > 700;

    //switch ((*joueur)->classe){
        //case MARIO :
            if ((float) ecran.mouse_x < ecran.width/3.6 && ecran.mouse_x > ecran.width/5.76 && (float) ecran.mouse_y < ecran.height/1.8 && ecran.mouse_y > 7*ecran.height/18) {
            al_draw_filled_rectangle(7 * ecran.width / 64 + ecran.width/38.4, 2 * (ecran.height / 3) + ecran.height/18, 7 * ecran.width / 64 + 37*ecran.width/288 , 2 * (ecran.height / 3) + 19*ecran.height/90,
                                     al_map_rgb(246, 97, 65));

            }

            //case pacman

            else if ((float) ecran.mouse_x < 5*ecran.width/12 && ecran.mouse_x > 5*ecran.width/16 && (float) ecran.mouse_y < 5*ecran.height/9 && ecran.mouse_y >7*ecran.height/18) {
            al_draw_filled_rectangle(7 * ecran.width / 64 + ecran.width/38.4, 2 * (ecran.height / 3) + ecran.height/18, 7 * ecran.width / 64 + 37*ecran.width/288 , 2 * (ecran.height / 3) + 19*ecran.height/90,
                                     al_map_rgb(168, 218, 67));
            }

            //case  rose

            else if ((float) ecran.mouse_x < 5*ecran.width/12 && ecran.mouse_x > 5*ecran.width/9 && (float) ecran.mouse_y < 5*ecran.height/9 && ecran.mouse_y >7*ecran.height/18) {
                al_draw_filled_rectangle(7 * ecran.width / 64 + ecran.width / 38.4,
                                         2 * (ecran.height / 3) + ecran.height / 18,
                                         7 * ecran.width / 64 + 37 * ecran.width / 288,
                                         2 * (ecran.height / 3) + 19 * ecran.height / 90,
                                         al_map_rgb(168, 218, 67));
            }







    //for(int i = 0; i<=nbJoueur; i++){
}

void attribuerBitmapPersonnage(Joueurs** joueurActuel, ALLEGRO_FONT* gameFont){
    /*(*joueurActuel)->classe.personnage[VIDE].image  = gameFont;
    (*joueurActuel)->classe.personnage[MARIO].image = gameFont;
    (*joueurActuel)->classe.personnage[LUIGI].image = gameFont;
    (*joueurActuel)->classe.personnage[KIRBY].image = gameFont;
    (*joueurActuel)->classe.personnage[PEACH].image = gameFont;
    (*joueurActuel)->classe.personnage[ZELDA].image = gameFont; */
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



*/

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

void afficherPseudo(Joueurs* joueur, float width, float height, ALLEGRO_FONT* gameFont, int nbJoueur) {
    for (int i = 0; i < nbJoueur; i++) {
        al_draw_textf(gameFont, al_map_rgb(20, 20, 20), (17 * width / 64 - 7.5 * width / 64) / 0.8 + (width/4.8)*i, 46 * height / 50,
                      ALLEGRO_ALIGN_CENTER, "%s", joueur[i].pseudo);
    }
}

/*void remplirDonneeJoueur (Joueurs** UnMaillonJoueur){
    (*UnMaillonJoueur)->pseudo = getPseudo();
}*/
