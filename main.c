
#include "menu.h"
#include "map.h"
#include "sorts.h"
#include "jeu.h"
#include "personnage.h"

/// FONCTION OU TOUT LE JEU EST DESSINER SUR A L'ECRAN
void dessinerJeu(Jeux* jeu, Map map[30][30], InfoEcran ecran, Timer timerJeu[], double scalex, double scaley, ALLEGRO_FONT* gameFont, ALLEGRO_FONT* smallGameFont, ALLEGRO_BITMAP* barreSortLogo, ALLEGRO_BITMAP* shield, ALLEGRO_BITMAP* effect) {
    if(jeu->joueur[jeu->info.joueurQuiJoue].quelAnimation != MARCHER) {
        determinerDirection(*jeu);
    }
    //AFFICHAGE DU PLATEAU
    drawPlay(jeu->joueur, map, jeu->info.joueurQuiJoue, ecran.mouse_x, ecran.mouse_y, ecran.width, scalex, scaley,
              al_map_rgb(0, 0, 0), al_map_rgb(255, 0, 0));

    //DEPLACEMENT DES JOUEURS
    deplacementJoueur(jeu->joueur, map, jeu->info.joueurQuiJoue, scalex, scaley);

    //AFFICHAGE DES PORTEES DES SORTS S'ILS SONT APPUYES
    afficherPortee(map, scalex, scaley, *jeu, jeu->info.joueurQuiJoue) ;

    //AFFICHAGE DES PERSONNAGE + ANIMATIONS
    afficherPersonnage(*jeu, map, ecran, &timerJeu[1], scalex, scaley, shield, effect, smallGameFont) ;
    if(jeu->joueur[jeu->info.joueurQuiJoue].PM < 3 || jeu->joueur[jeu->info.joueurQuiJoue].PA < 6 ) {
        boutonSuivantDansPlay(ecran, gameFont, ecran.mouse_x, ecran.mouse_y);
    }

    //AFFICHAGE DES SORTS EN FONCTION DU JOUEUR
    barreSort(barreSortLogo, ecran);
    sortEnFonctionDesClasses(gameFont, smallGameFont, *jeu, ecran, jeu->info.joueurQuiJoue);
    afficherCaracteristiqueJoueur(*jeu, ecran, jeu->info.joueurQuiJoue, smallGameFont, timerJeu[0].secondes) ;
}

int main() {
    ///INITIALISATION DU DISPLAY ET DU TIMER
    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_EVENT_QUEUE *queue;
    ALLEGRO_TIMER *times;
    ALLEGRO_EVENT event = {0};

    srand(time(NULL));

    ///INITIALISATION D'ALLEGRO
    assert(al_init());
    al_install_keyboard();
    al_install_mouse();
    al_init_image_addon();
    al_init_font_addon();
    al_init_ttf_addon();
    al_init_primitives_addon();

    ///CREATION DU DISPLAY
    al_set_new_display_flags(ALLEGRO_FULLSCREEN_WINDOW);
    display = al_create_display(800, 600);
    //al_set_display_flag(display, ALLEGRO_FULLSCREEN_WINDOW, true);
    double height = al_get_display_height(display);
    double width = al_get_display_width(display);
    al_set_window_position(display, 0, 0);

    ///COULEUR
    ALLEGRO_COLOR black = al_map_rgb(0, 0, 0);
    ALLEGRO_COLOR white = al_map_rgb(255, 255, 255);

    ///FONT
    ALLEGRO_FONT *bigGameFont = al_load_ttf_font("../Font/Nintendo.ttf", 300, ALLEGRO_ALIGN_CENTER);
    ALLEGRO_FONT *gameFont1 = al_load_ttf_font("../Font/Nintendo.ttf", 3*width/80, ALLEGRO_ALIGN_LEFT);
    ALLEGRO_FONT *smallGameFont = al_load_ttf_font("../Font/Nintendo.ttf", 5 * width / 192, ALLEGRO_ALIGN_LEFT);
    ALLEGRO_FONT *gameFont = al_load_ttf_font("../Font/MagicCardsNormal.ttf", 2 * width / 55, ALLEGRO_ALIGN_LEFT);
    ALLEGRO_FONT *gameFontRegles = al_load_ttf_font("../Font/Rumpi.ttf", 40, ALLEGRO_ALIGN_LEFT);

                    /////////////BITMAP DU JEU EN GENERAL///////////
    ALLEGRO_BITMAP *background = al_load_bitmap("../Bitmap/BG.jpg");
    ALLEGRO_BITMAP *team = al_load_bitmap("../Bitmap/capture.PNG");
    ALLEGRO_BITMAP *carte = al_load_bitmap("../Bitmap/map4.PNG");


               /////////////////PERSONNAGES LOGO/////////////////////
    ALLEGRO_BITMAP *kirbyIcone = al_load_bitmap("../Bitmap/Icone/Kirby_Icone.png");
    ALLEGRO_BITMAP *pacmanIcone = al_load_bitmap("../Bitmap/Icone/PacMan_Icone.png");
    ALLEGRO_BITMAP *peachIcone = al_load_bitmap("../Bitmap/Icone/Peach_Icone.png");
    ALLEGRO_BITMAP *marioIcone = al_load_bitmap("../Bitmap/Icone/Mario_Icone.png") ;
    ALLEGRO_BITMAP *donkey_kongIcone = al_load_bitmap("../Bitmap/Icone/DonkeyKong_Icone.png") ;
    ALLEGRO_BITMAP *kirbyR = al_load_bitmap("../Bitmap/Icone/KirbyRond.png");
    ALLEGRO_BITMAP *pacmanR = al_load_bitmap("../Bitmap/Icone/PacmanRond.png");
    ALLEGRO_BITMAP *peachR = al_load_bitmap("../Bitmap/Icone/PeachRond.png");
    ALLEGRO_BITMAP *marioR = al_load_bitmap("../Bitmap/Icone/MarioRond.png") ;
    ALLEGRO_BITMAP *donkey_kongR = al_load_bitmap("../Bitmap/Icone/DKRond.png") ;

               /////////////////SORTS/////////////////////
    ALLEGRO_BITMAP *sortFlemme = al_load_bitmap("../Bitmap/Sort/sortUtilisé/sortFlemme.png");
    ALLEGRO_BITMAP *sortFleur = al_load_bitmap("../Bitmap/Sort/sortUtilisé/sortFleur.png");
    ALLEGRO_BITMAP *sortCorona = al_load_bitmap("../Bitmap/Sort/sortUtilisé/sortCorona.png");
    ALLEGRO_BITMAP *sortDefence = al_load_bitmap("../Bitmap/Sort/sortUtilisé/sortDefence.png");
    ALLEGRO_BITMAP *sortSoin = al_load_bitmap("../Bitmap/Sort/sortUtilisé/sortSoin.png");
    ALLEGRO_BITMAP *sortSaut = al_load_bitmap("../Bitmap/Sort/sortUtilisé/saut.png");
    ALLEGRO_BITMAP *reculerAdversaire = al_load_bitmap("../Bitmap/Sort/sortUtilisé/reculerAdversaire.png");
    ALLEGRO_BITMAP *couDePoingGant = al_load_bitmap("../Bitmap/Sort/sortUtilisé/poingGant.png");
    ALLEGRO_BITMAP *poing2 = al_load_bitmap("../Bitmap/Sort/sortUtilisé/Poing2.png");
    ALLEGRO_BITMAP *poing = al_load_bitmap("../Bitmap/Sort/sortUtilisé/poing.png");
    ALLEGRO_BITMAP *coupDePied = al_load_bitmap("../Bitmap/Sort/sortUtilisé/coupDePied.png");
    ALLEGRO_BITMAP *sortMortel = al_load_bitmap("../Bitmap/Sort/sortUtilisé/sortMortel.png");
    ALLEGRO_BITMAP *afficherSort = al_load_bitmap("../Bitmap/Sort/afficherSort.png");
    ALLEGRO_BITMAP *shield = al_load_bitmap("../Bitmap/Sprite_Sheet/spr_shield.png");
    ALLEGRO_BITMAP *effect = al_load_bitmap("../Bitmap/Sprite_Sheet/effect.png");
    ALLEGRO_BITMAP *fond = al_load_bitmap("../Bitmap/fond.png");
    FILE* lec=fopen("../Bitmap/MatriceObstacle.txt", "r");

    ///CREATION DES DONNEES DU JEU
    int isFin = 0, draw = 0;
    float endScreenX = 0, endScreenY = 0;
    float mouse_x = 0, mouse_y = 0;
    int page = 1, tour = 0;
    Menu mainMenu;
    InfoEcran ecran;
    Map map[30][30];
    Jeux jeu;
    jeu.joueur = NULL ;
    jeu.classes[PACMAN].SpriteSheet = al_load_bitmap("../Bitmap/Sprite_Sheet/Pacman_Sprite.png") ;
    jeu.classes[KIRBY].SpriteSheet = al_load_bitmap("../Bitmap/Sprite_Sheet/Kirby_Sprite.png") ;
    jeu.classes[MARIO].SpriteSheet = al_load_bitmap("../Bitmap/Sprite_Sheet/Mario_Sprite.png") ;
    jeu.classes[PEACH].SpriteSheet = al_load_bitmap("../Bitmap/Sprite_Sheet/Peach_Sprite.png") ;
    jeu.classes[DONKEY_KONG].SpriteSheet = al_load_bitmap("../Bitmap/Sprite_Sheet/DK_Sprite.png") ;

    ///COORDONNEES DE LA MAP
    double scalex = 8 * width/ 296 ;
    double scaley = 4 * height / 149;
    for (int j = 0; j < mapY; j++) {
        for (int i = 0; i < mapX; i++) {
            map[i][j].x = width/12 +scalex + i * scalex + j * scalex;
            map[i][j].y = height/1.7 - i * scaley + j * scaley;
            map[i][j].joueurPresentDessus = 0 ;
            fscanf(lec, "%d", &map[i][j].obstacle);

        }
    }

    fclose(lec);
    al_install_audio();
    al_init_acodec_addon();
    ALLEGRO_SAMPLE *musique = al_load_sample("../Bitmap/musique1.flac");
    al_reserve_samples(1);
    ///INITIALISATION DE NOS VARIABLES
    //ANIMATIONS
    initialiserImageAnimationsMario(jeu.classes[MARIO].animations) ;
    initialiserImageAnimationsPeach(jeu.classes[PEACH].animations) ;
    initialiserImageAnimationsDK(jeu.classes[DONKEY_KONG].animations) ;
    initialiserImageAnimationsKirby(jeu.classes[KIRBY].animations) ;
    initialiserImageAnimationsPacman(jeu.classes[PACMAN].animations) ;

    //IMAGE
    initialiserIconeClasse(pacmanIcone, kirbyIcone, peachIcone, marioIcone, donkey_kongIcone, pacmanR, kirbyR, peachR, marioR, donkey_kongR, jeu.classes) ;
    initialiserSortClasseKIRBY (&jeu.classes[KIRBY], coupDePied, sortFlemme, poing);
    initialiserSortClassePACMAN (&jeu.classes[PACMAN], reculerAdversaire, sortFlemme, sortDefence);
    initialiserSortClasseMARIO (&jeu.classes[MARIO], sortCorona, sortFlemme, poing2);
    initialiserSortClassePEACH (&jeu.classes[PEACH], sortFleur, sortSoin, coupDePied);
    initialiserSortClasseDONKEYKONG (&jeu.classes[DONKEY_KONG], sortMortel, couDePoingGant, sortSaut);

    //JEU
    initialiserMenu(&mainMenu, width, height);
    initialiserJeu(&jeu);
    initialiserEcran(&ecran, width, height);

    ///INITIALISATION DU TIMER
    Timer timerJeu[3] ;
    initialiserTimer(timerJeu) ;
    times = al_create_timer(0.02);

    queue = al_create_event_queue();
    assert(queue);
    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_mouse_event_source( ));
    al_register_event_source(queue, al_get_timer_event_source(times));
    al_start_timer(times);

    while (!isFin) {
        al_play_sample(musique, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, 0);
        while (mainMenu.gameMode != PLAY && mainMenu.gameMode != END) {
            al_wait_for_event(queue, &event);
            switch (event.type) {
                case ALLEGRO_EVENT_KEY_DOWN : {
                    switch (event.keyboard.keycode) {
                        case ALLEGRO_KEY_ESCAPE : {
                            mainMenu.gameMode = END;
                            break;
                        }
                    }
                    break;
                }
                case ALLEGRO_EVENT_MOUSE_AXES : {
                    mouse_x = event.mouse.x;
                    mouse_y = event.mouse.y;
                    ecran.mouse_x = event.mouse.x;
                    ecran.mouse_y = event.mouse.y;
                    break;
                }
                case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN : {
                    if ((event.mouse.button & 1) == 1) {
                        map[0][0].t = 1;
                        switch (mainMenu.gameMode) {
                            case MENU : {
                                if (mouse_x < 157 * width / 275 && mouse_x > 118 * width / 275 &&
                                    mouse_y < 38 * height / 99 && mouse_y > 7 * height / 80) {
                                    mainMenu.gameMode = PLAY;
                                }
                                if (mouse_x < 49 * width / 110 && mouse_x > 21 * width / 110 &&
                                    mouse_y < 322 * height / 495 && mouse_y > 4 * height / 9) {
                                    mainMenu.gameMode = RULES;
                                }
                                if (mouse_x < 89 * width / 110 && mouse_x > 61 * width / 110 &&
                                    mouse_y < 322 * height / 495 && mouse_y > 4 * height / 9) {
                                    mainMenu.gameMode = TEAM;;
                                }

                                break;
                            }
                            case TEAM : {
                                if (mouse_x < 5 * width / 32 && mouse_x > width / 384 &&
                                    mouse_y < 2 * height / 27 && mouse_y > height / 216) {
                                    mainMenu.gameMode = MENU;
                                }
                                break;
                            }
                            case RULES : {
                                if ((mouse_x - 13 * width / 15) * (mouse_x - 13 * width / 15) +
                                    (mouse_y - 11 * height / 13) * (mouse_y - 11 * height / 13) < width/38.4 * width/38.4) {
                                    if (page + 1 <= RULESPAGEMAX) {
                                        page++;
                                    }
                                }
                                if ((mouse_x - 2 * width / 15) * (mouse_x - 2 * width / 15) +
                                    (mouse_y - 11 * height / 13) * (mouse_y - 11 * height / 13) < width/38.4 * width/38.4) {
                                    if (page - 1 >= 1) {
                                        page--;
                                    }
                                }
                                if (mouse_x < 5 * width / 32 && mouse_x > width / 384 &&
                                    mouse_y < 2 * height / 27 && mouse_y > height / 216) {
                                    mainMenu.gameMode = MENU;
                                    page = 1;
                                }
                                break;
                            }
                        }
                    }
                    break;
                }
                case ALLEGRO_EVENT_TIMER : {
                    menuSouris(&mainMenu, ecran);
                    draw = 1;
                }
            }
            if (draw) {
                al_draw_scaled_bitmap(background, 0, 0, 7680, 4320, 0, 0, width, height, 0);
                switch (mainMenu.gameMode) {
                    case MENU : {
                        drawMenuV2(&mainMenu, gameFont1);
                        break;
                    }
                    case TEAM : {
                        drawTeam(height, width, mouse_x, mouse_y, gameFont1, team);
                        break;

                    }
                    case RULES : {
                        drawRules(&page, height, width, mouse_x, mouse_y, gameFontRegles, gameFont, gameFont1, kirbyIcone, pacmanIcone, peachIcone, marioIcone, donkey_kongIcone);
                        break;
                    }
                }
                al_flip_display();
                al_clear_to_color(black);
                draw = 0;
            }
        }


        //// ON APPUIE SUR LE BOUTON JOUER
        if (mainMenu.gameMode == PLAY) {
            al_wait_for_event(queue, &event);
            switch (event.type) {
                case ALLEGRO_EVENT_KEY_DOWN : {
                    switch (event.keyboard.keycode) {
                        case ALLEGRO_KEY_ESCAPE : {
                            mainMenu.gameMode = END;
                            break;
                        }
                        default: {
                            if (jeu.gameMode == CHOIXCLASSE) {
                                if (jeu.info.entrerPseudo == true) {
                                    mettrePseudo(&jeu.joueur,alphabet(event.keyboard.keycode, &jeu.joueur[jeu.info.ordre[jeu.info.joueurQuiJoue]].nbLettrePseudo),jeu.info.ordre[jeu.info.joueurQuiJoue],&jeu.joueur[jeu.info.ordre[jeu.info.joueurQuiJoue]].nbLettrePseudo);
                                }
                                break;
                            }
                        }
                    }
                    break;
                }
                case ALLEGRO_EVENT_MOUSE_AXES : {
                    mouse_x = event.mouse.x;
                    mouse_y = event.mouse.y;
                    ecran.mouse_x = event.mouse.x;
                    ecran.mouse_y = event.mouse.y;
                    break;
                }
                case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN : {
                    if ((event.mouse.button & 1) == 1) {
                        switch (jeu.gameMode) {
                            case CHOIXNBJOUEUR : {
                                /// INITIALISER A ZERO SI ON REVIENT AVANT
                                if (mouse_x < 5 * width / 32 && mouse_x > width / 384 &&mouse_y < 2 * height / 27 && mouse_y > height / 216) {
                                    mainMenu.gameMode = MENU;
                                    initialiserJeu(&jeu);
                                }
                                ///CHOIX DU NOMBRE DE JOUEUR
                                if ((mouse_x - width / 4.8) * (mouse_x - width / 4.8) +(mouse_y - height / 2.16) * (mouse_y - height / 2.16) <ecran.width / 19.2 * ecran.width / 19.2) {
                                    jeu.info.nbJoueur = 2;
                                } else if ((mouse_x - 95 * width / 192) * (mouse_x - 95 * width / 192) +(mouse_y - height / 2.16) * (mouse_y - height / 2.16) <ecran.width / 19.2 * ecran.width / 19.2) {
                                    jeu.info.nbJoueur = 3;
                                } else if ((mouse_x - width / 1.28) * (mouse_x - width / 1.28) +(mouse_y - height / 2.16) * (mouse_y - height / 2.16) <ecran.width / 19.2 * ecran.width / 19.2) {
                                    jeu.info.nbJoueur = 4;
                                }
                                ///PASSER SUR LE MENU SUIVANT
                                if ((float) mouse_x < 383 * width / 384 && mouse_x > width / 1.2 &&(float) mouse_y < 215 * height / 216 && mouse_y > height / 1.08) {
                                    jeu.gameMode = CHOIXCLASSE;
                                    initialiserJoueur(&jeu, map);
                                    ordreDesJoueurs(&jeu.info, jeu.info.nbJoueur);
                                }

                                break;
                            }
                            case CHOIXCLASSE : {
                                /// INITIALISER A ZERO SI ON REVIENT AVANT
                                if (mouse_x < 5 * width / 32 && mouse_x > width / 384 && mouse_y < 2 * height / 27 &&mouse_y > height / 216) {
                                    jeu.gameMode = CHOIXNBJOUEUR;
                                    initialiserJeu(&jeu);
                                }
                                ///CHOIX DE LA CLASSE
                                if (jeu.info.entrerPseudo == false) {
                                    if ((float) ecran.mouse_x < ecran.width / 3.6 &&ecran.mouse_x > ecran.width / 5.76 &&(float) ecran.mouse_y < ecran.height / 1.8 &&ecran.mouse_y > 7 * ecran.height / 18) {
                                        jeu.joueur[jeu.info.ordre[jeu.info.joueurQuiJoue]].classe = KIRBY;
                                    } else if ((float) ecran.mouse_x < 5 * ecran.width / 12 &&ecran.mouse_x > 5 * ecran.width / 16 &&(float) ecran.mouse_y < 5 * ecran.height / 9 &&ecran.mouse_y > 7 * ecran.height / 18) {
                                        jeu.joueur[jeu.info.ordre[jeu.info.joueurQuiJoue]].classe = PACMAN;
                                    } else if ((float) ecran.mouse_x < 5 * ecran.width / 9 &&ecran.mouse_x > 65 * ecran.width / 144 &&(float) ecran.mouse_y < 5 * ecran.height / 9 &&ecran.mouse_y > 7 * ecran.height / 18) {
                                        jeu.joueur[jeu.info.ordre[jeu.info.joueurQuiJoue]].classe = PEACH;
                                    } else if ((float) ecran.mouse_x < 25 * ecran.width / 36 &&ecran.mouse_x > 85 * ecran.width / 144 &&(float) ecran.mouse_y < 5 * ecran.height / 9 &&ecran.mouse_y > 7 * ecran.height / 18) {
                                        jeu.joueur[jeu.info.ordre[jeu.info.joueurQuiJoue]].classe = MARIO;
                                    } else if ((float) ecran.mouse_x < 5 * ecran.width / 6 &&ecran.mouse_x > 35 * ecran.width / 48 &&(float) ecran.mouse_y < 5 * ecran.height / 9 &&ecran.mouse_y > 7 * ecran.height / 18) {
                                        jeu.joueur[jeu.info.ordre[jeu.info.joueurQuiJoue]].classe = DONKEY_KONG;
                                    }
                                }
                                if ((float) ecran.mouse_x < 3 * ecran.width / 5 &&ecran.mouse_x > 2 * ecran.width / 5 &&(float) ecran.mouse_y < 9 * ecran.height / 27 &&ecran.mouse_y > 7 * ecran.height / 27 &&jeu.joueur[jeu.info.ordre[jeu.info.joueurQuiJoue]].classe != VIDE) {
                                    if (jeu.info.entrerPseudo == false) {
                                        jeu.info.entrerPseudo = true;
                                    } else if (jeu.joueur[jeu.info.ordre[jeu.info.joueurQuiJoue]].pseudo[0] != '\0') {
                                        if (jeu.info.joueurQuiJoue + 1 != jeu.info.nbJoueur) {
                                            jeu.info.joueurQuiJoue++;
                                            jeu.info.entrerPseudo = false;
                                        }
                                    }
                                }
                                ///PASSER SUR LE JEU
                                if (((float) mouse_x - 1829 * ecran.width / 1920) *((float) mouse_x - 1829 * ecran.width / 1920) +(mouse_y - 49 * ecran.height / 54) * (mouse_y - 49 * ecran.height / 54) <ecran.width / 24 * ecran.width / 24 && jeu.joueur[jeu.info.ordre[jeu.info.nbJoueur - 1]].pseudo[0] != '\0') {
                                    jeu.gameMode = JEU;
                                    jeu.info.joueurQuiJoue = 0;
                                }
                                break;
                            }
                            case JEU : {
                                if (jeu.gameMode2 == JOUER) {
                                    if (jeu.joueur[jeu.info.joueurQuiJoue].sortAppuye == 3) {
                                        map[0][0].t = 1;
                                    }
                                    jeu.info.clickSouris = 1;
                                    if (jeu.joueur[jeu.info.joueurQuiJoue].quelAnimation == RESPIRATION) {
                                        sortChoisi(ecran, &jeu.joueur[jeu.info.joueurQuiJoue].sortAppuye);
                                    }
                                    if (jeu.joueur[jeu.info.joueurQuiJoue].PM < 3 ||jeu.joueur[jeu.info.joueurQuiJoue].PA < 6 &&jeu.joueur[jeu.info.joueurQuiJoue].sortAppuye == 3 &&jeu.joueur[jeu.info.joueurQuiJoue].dep == 0) {
                                        if ((float) mouse_x < 383 * ecran.width / 384 - 6 * ecran.width / 48 &&mouse_x > ecran.width / 1.2 - 6 * ecran.width / 48 &&(float) mouse_y < ecran.height / 13.5 && mouse_y > ecran.height / 216) {
                                            nextPlayer(&jeu, timerJeu);
                                        }
                                    }
                                    if (jeu.joueur[jeu.info.joueurQuiJoue].sortAppuye != 3 &&jeu.joueur[jeu.info.joueurQuiJoue].quelAnimation == RESPIRATION) {
                                        if ((float) ecran.mouse_x < 11 * ecran.width / 13 &&ecran.mouse_x > 6 * ecran.width / 8 &&(float) ecran.mouse_y < 80 * ecran.height / 90 &&ecran.mouse_y > 75 * ecran.height / 90) {
                                            jeu.joueur[jeu.info.joueurQuiJoue].sortAppuye = 3;
                                        }
                                    }
                                }
                                else if (jeu.gameMode2 == ORDRE) {
                                    if ((ecran.mouse_x - 9 * ecran.width / 15) *(ecran.mouse_x - 9 * ecran.width / 15) +(ecran.mouse_y - 10 * ecran.height / 13) *(ecran.mouse_y - 10 * ecran.height / 13) <ecran.width / 38.4 * ecran.width / 38.4) {
                                        jeu.gameMode2 = JOUER;
                                    }
                                }
                                else if (jeu.gameMode2 == FINJEU) {
                                    if ((float) ecran.mouse_x < 79 * ecran.width / 96 &&ecran.mouse_x > 2 * ecran.width / 3 &&(float) ecran.mouse_y < 5 * ecran.height / 6 &&ecran.mouse_y > 3 * ecran.height / 4) {
                                        initialiserTimer(timerJeu) ;
                                        for (int j = 0; j < mapY; j++) {
                                            for (int i = 0; i < mapX; i++) {
                                                map[i][j].joueurPresentDessus = 0 ;
                                            }
                                        }
                                        initialiserJeu(&jeu);
                                        mainMenu.gameMode = MENU;
                                    }
                                }
                                if ((ecran.mouse_x - 95*ecran.width/96) * (ecran.mouse_x - 95*ecran.width/96) + (ecran.mouse_y - ecran.height/54) * (ecran.mouse_y - ecran.height/54) < ecran.width/96 * ecran.width/96) {
                                    remiseAzero(&jeu, map) ;
                                }
                                break;
                            }
                        }
                    }
                    break;
                }
                case ALLEGRO_EVENT_MOUSE_BUTTON_UP: {
                    if ((event.mouse.button & 1) == 1) {
                        switch (jeu.gameMode) {
                            case JEU : {
                                map[0][0].t = 0;
                                jeu.info.clickSouris = 0 ;
                            }

                        }
                    }
                    break;
                }
                case ALLEGRO_EVENT_TIMER : {
                    ///SAVOIR OU L'ON CLIQUE SUR LA MAP
                    if (jeu.info.clickSouris == 1) {
                        for (int j = 0; j < mapY; j++) {
                            for (int i = 0; i < mapX; i++) {
                                if (collisionCercle(mouse_x, mouse_y, map, i, j, width) == true) {
                                    jeu.info.collisionSourisMap[0][0] = i;
                                    jeu.info.collisionSourisMap[1][0] = j;
                                    jeu.info.xClick = jeu.info.collisionSourisMap[0][0];
                                    jeu.info.yClick = jeu.info.collisionSourisMap[1][0];
                                }
                            }
                        }
                    }
                    else {
                        jeu.info.collisionSourisMap[0][0] = 30;
                        jeu.info.collisionSourisMap[1][0] = 30;
                    }
                    ///POUR LES ANIMATIONS
                    if (tour % 5 == 0) {
                        jeu.info.compteur++;
                    }
                    tour++;

                    ///CHRONO DU JEU
                    if(jeu.gameMode2 == JOUER) {
                        timerJeu[0].secondes = (float) timerJeu[0].compteur / (float) 50;
                        if (timerJeu[0].secondes > 15 && jeu.joueur[jeu.info.joueurQuiJoue].quelAnimation == RESPIRATION) {
                            nextPlayer(&jeu, timerJeu);
                        }
                        timerJeu[0].compteur++;
                    }
                    if(timerJeu[2].startTimer == 1) {
                        timerJeu[2].secondes = (float) timerJeu[2].compteur / (float) 50;
                        if (timerJeu[2].secondes > 2) {
                            jeu.gameMode2 = FINJEU ;
                            jeu.info.joueurGagnant = verifierFinDuJeu(jeu) - 1 ;
                        }
                       if(timerJeu[2].secondes > 4) {
                            endScreenX += 3.2f * timerJeu[2].secondes/2 ;
                            endScreenY += 2.25f * timerJeu[2].secondes/2;
                        }
                        timerJeu[2].compteur++;
                    }

                    /// VERIFIER LA FIN DU JEU
                    if(verifierFinDuJeu(jeu) != 0) {
                        timerJeu[2].startTimer = 1 ;
                    }
                    draw = 1;
                    break;
                }
            }
            if (draw) {
                switch (jeu.gameMode) {
                    case CHOIXNBJOUEUR : {
                        al_draw_scaled_bitmap(background, 0, 0, 7680, 4320, 0, 0, width, height, 0);
                        choixJoueur(width, height, mouse_x, mouse_y, gameFont1, &jeu.info);
                        break;
                    }
                    case CHOIXCLASSE : {
                        al_draw_scaled_bitmap(background, 0, 0, 7680, 4320, 0, 0, width, height, 0);
                        drawChooseCharacter(ecran, gameFont1, jeu, bigGameFont);
                        break;
                    }
                    case JEU : {
                        al_draw_scaled_bitmap(fond, 0, 0, 1920, 1054, 0, 0, width, height, 0) ;
                        if(jeu.gameMode2 == FINJEU) {
                            afficherFinGagnant(jeu, ecran, endScreenX, endScreenY, gameFont1, bigGameFont) ;
                        }
                        else {
                            al_draw_scaled_bitmap(carte, 0, 0, 296, 149, 50, 50, width, height, 0);
                            appuyerSortSurMap(&jeu, map, &timerJeu[1]);
                            dessinerJeu(&jeu, map, ecran, timerJeu, scalex, scaley, gameFont1, smallGameFont, afficherSort, shield, effect);
                            if (jeu.gameMode2 == ORDRE) {
                                afficherOrdre(jeu, ecran, gameFont1);
                            }
                            al_draw_filled_circle(95*ecran.width/96, ecran.height/54, ecran.width/96, al_map_rgb(100, 100, 100)) ;
                        }
                        break;
                    }
                }
                al_flip_display();
                al_clear_to_color(white);
                draw = 0;
            }
        }
        else isFin = 1;
    }

    ///DESTRUCTION DES ELEMENTS DU JEU
    al_destroy_sample(musique);

    al_destroy_font(bigGameFont) ;
    al_destroy_font(gameFont1) ;
    al_destroy_font(smallGameFont) ;
    al_destroy_font(gameFont) ;
    al_destroy_font(gameFontRegles) ;

    al_destroy_bitmap(background) ;
    al_destroy_bitmap(team) ;
    al_destroy_bitmap(carte) ;
    al_destroy_bitmap(kirbyIcone) ;
    al_destroy_bitmap(pacmanIcone) ;
    al_destroy_bitmap(peachIcone) ;
    al_destroy_bitmap(marioIcone) ;
    al_destroy_bitmap(donkey_kongIcone) ;
    al_destroy_bitmap(kirbyR) ;
    al_destroy_bitmap(pacmanR) ;
    al_destroy_bitmap(peachR) ;
    al_destroy_bitmap(marioR) ;
    al_destroy_bitmap(donkey_kongR) ;
    al_destroy_bitmap(sortFlemme) ;
    al_destroy_bitmap(sortFleur) ;
    al_destroy_bitmap(sortCorona) ;
    al_destroy_bitmap(sortDefence) ;
    al_destroy_bitmap(sortSoin) ;
    al_destroy_bitmap(sortSaut) ;
    al_destroy_bitmap(reculerAdversaire) ;
    al_destroy_bitmap(couDePoingGant) ;
    al_destroy_bitmap(poing2) ;
    al_destroy_bitmap(poing) ;
    al_destroy_bitmap(coupDePied) ;
    al_destroy_bitmap(sortMortel) ;
    al_destroy_bitmap(afficherSort) ;
    al_destroy_bitmap(shield) ;
    al_destroy_bitmap(effect) ;
    al_destroy_bitmap(fond) ;
    al_destroy_bitmap(jeu.classes[PACMAN].SpriteSheet) ;
    al_destroy_bitmap(jeu.classes[KIRBY].SpriteSheet) ;
    al_destroy_bitmap(jeu.classes[MARIO].SpriteSheet) ;
    al_destroy_bitmap(jeu.classes[PEACH].SpriteSheet) ;
    al_destroy_bitmap(jeu.classes[DONKEY_KONG].SpriteSheet) ;
    return 0;
}



