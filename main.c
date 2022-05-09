
#include "menu.h"
#include "map.h"

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


    ///CREATION DES VARIABLES
    ALLEGRO_COLOR black = al_map_rgb(0, 0, 0);
    ALLEGRO_COLOR red = al_map_rgb(255, 0, 0);
    ALLEGRO_COLOR white = al_map_rgb(255, 255, 255);
    ALLEGRO_COLOR vert = al_map_rgba(93, 127, 51, 255);
    ALLEGRO_COLOR gris = al_map_rgb(128, 128, 128);
    ALLEGRO_COLOR gameColor = al_map_rgb(255, 0, 0);

    ///FONT
    ALLEGRO_FONT *bigGameFont = al_load_ttf_font("../Font/Nintendo.ttf", 300, ALLEGRO_ALIGN_CENTER);
    ALLEGRO_FONT *gameFont1 = al_load_ttf_font("../Font/Nintendo.ttf", 72, ALLEGRO_ALIGN_LEFT);
    ALLEGRO_FONT *gameFont = al_load_ttf_font("../Font/MagicCardsNormal.ttf", 2 * width / 55, ALLEGRO_ALIGN_LEFT);
    ALLEGRO_FONT *gameFontRegles = al_load_ttf_font("../Font/Rumpi.ttf", 40, ALLEGRO_ALIGN_LEFT);

    ///BITMAP
    ALLEGRO_BITMAP *background = al_load_bitmap("../Bitmap/BG.jpg");
    ALLEGRO_BITMAP *team = al_load_bitmap("../Bitmap/capture.PNG");

               /////////////////PERSONNAGES LOGO/////////////////////
    ALLEGRO_BITMAP *kirbyIcone = al_load_bitmap("../Bitmap/Icone/Kirby_Icone.png");
    ALLEGRO_BITMAP *pacmanIcone = al_load_bitmap("../Bitmap/Icone/PacMan_Icone.png");
    ALLEGRO_BITMAP *peachIcone = al_load_bitmap("../Bitmap/Icone/Peach_Icone.png");
    ALLEGRO_BITMAP *marioIcone = al_load_bitmap("../Bitmap/Icone/Mario_Icone.png") ;
    ALLEGRO_BITMAP *donkey_kongIcone = al_load_bitmap("../Bitmap/Icone/DonkeyKong_Icone.png") ;

               /////////////////SORTS/////////////////////

    ALLEGRO_BITMAP *sortFlemme = al_load_bitmap("../Bitmap/Sort/sortFlemme.png");
    ALLEGRO_BITMAP * sortFleur = al_load_bitmap("../Bitmap/SortFleur.png");
    ALLEGRO_BITMAP * sortCorona = al_load_bitmap("../Bitmap/sortCorona.png");
    ALLEGRO_BITMAP * sortDefence = al_load_bitmap("../Bitmap/sortDefence.png");
    ALLEGRO_BITMAP * sortSoin = al_load_bitmap("../Bitmap/sortSoin.png");



    /////////////////AFFICHAGEPVPMPA/////////////////////

    ALLEGRO_BITMAP *PVversion1 = al_load_bitmap("../Bitmap/Sort/PVversion1.png");
    ALLEGRO_BITMAP *afficherPV = al_load_bitmap("../Bitmap/Sort/afficherPV.png");
    ALLEGRO_BITMAP *afficherSort = al_load_bitmap("../Bitmap/Sort/afficherSort.png");



    queue = al_create_event_queue();
    assert(queue);

    int isFin = 0, draw = 0 ;
    Menu mainMenu;
    InfoEcran ecran;
    Map map[20][20];
    Jeux jeu;
    jeu.joueur = NULL ;
    int nbJoueur = 0;



    ///METTRE CA DANS UNE FONCTION
    double scalex = 50.0 * width / 1800.0;
    double scaley = 50.0 * height / 1800.0;
    for (int j = 0; j < mapY; j++) {
        for (int i = 0; i < mapX; i++) {
            map[i][j].x =  scalex + i * scalex + j * scalex;
            map[i][j].y = height/1.8 - i * scaley + j * scaley;
            map[i][j].obstacle=0;

        }
    }

    ///INITIALISATION DE NOS VARIABLES
    initialiserIconeClasse(pacmanIcone, kirbyIcone, peachIcone, marioIcone, donkey_kongIcone, jeu.classes);
    //initialiserSort (jeu.classes, sortFatal, sortFlemme, sortRalentir, sortSpecial, sortStop, sortReculer, afficherSort, afficherPV);



        initialiserMenu(&mainMenu, width, height);
    initialiserJeu(&jeu);
    initialiserEcran(&ecran, width, height);

    float mouse_x = 0, mouse_y = 0;
    int page = 1;


    ///INITIALISATION CLASSE
    //joueur[].classe = 0;


    ///INITIALISATION DU TIMER
    times = al_create_timer(0.02);


    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_mouse_event_source( ));
    al_register_event_source(queue, al_get_timer_event_source(times));


    al_start_timer(times);
    while (!isFin) {
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
                        drawMenuV2(&mainMenu, gameFont);
                        break;
                    }
                    case TEAM : {
                        drawTeam(height, width, mouse_x, mouse_y, gameFont1, team);
                        break;

                    }
                    case RULES : {
                        drawRules(&page, height, width, mouse_x, mouse_y, gameFontRegles, gameFont);
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
                                    mettrePseudo(&jeu.joueur,alphabet(event.keyboard.keycode,&jeu.joueur[jeu.info.joueurQuiJoue].nbLettrePseudo),jeu.info.joueurQuiJoue,&jeu.joueur[jeu.info.joueurQuiJoue].nbLettrePseudo);
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
                            case JEU : {
                                map[0][0].t = 1;
                                break;
                            }
                            case CHOIXNBJOUEUR : {
                                /// INITIALISER A ZERO SI ON REVIENT AVANT
                                if (mouse_x < 5 * width / 32 && mouse_x > width / 384 &&
                                    mouse_y < 2 * height / 27 && mouse_y > height / 216) {
                                    mainMenu.gameMode = MENU;
                                    initialiserJeu(&jeu) ;
                                }
                                if ((mouse_x - width / 4.8) * (mouse_x - width / 4.8) +
                                    (mouse_y - height / 2.16) * (mouse_y - height / 2.16) < ecran.width/19.2 * ecran.width/19.2) {
                                    jeu.info.nbJoueur = 2;
                                } else if ((mouse_x - 95 * width / 192) * (mouse_x - 95 * width / 192) +
                                           (mouse_y - height / 2.16) * (mouse_y - height / 2.16) < ecran.width/19.2 * ecran.width/19.2) {
                                    jeu.info.nbJoueur = 3;
                                } else if ((mouse_x - width / 1.28) * (mouse_x - width / 1.28) +
                                           (mouse_y - height / 2.16) * (mouse_y - height / 2.16) < ecran.width/19.2 * ecran.width/19.2) {
                                    jeu.info.nbJoueur = 4;
                                }
                                if ((float) mouse_x < 383 * width / 384 && mouse_x > width / 1.2 &&
                                    (float) mouse_y < 215 * height / 216 && mouse_y > height / 1.08) {
                                    jeu.gameMode = CHOIXCLASSE;
                                    initialiserJoueur(&jeu, map);
                                }

                                break;
                            }
                            case CHOIXCLASSE : {
                                /// INITIALISER A ZERO SI ON REVIENT AVANT
                                if (mouse_x < 5 * width / 32 && mouse_x > width / 384 && mouse_y < 2 * height / 27 && mouse_y > height / 216) {
                                    jeu.gameMode = CHOIXNBJOUEUR;
                                    initialiserJeu(&jeu) ;
                                }
                                if(jeu.info.entrerPseudo == false) {
                                    if ((float) ecran.mouse_x < ecran.width / 3.6 &&ecran.mouse_x > ecran.width / 5.76 &&(float) ecran.mouse_y < ecran.height / 1.8 &&ecran.mouse_y > 7 * ecran.height / 18) {
                                        jeu.joueur[jeu.info.joueurQuiJoue].classe = KIRBY;
                                    } else if ((float) ecran.mouse_x < 5 * ecran.width / 12 &&ecran.mouse_x > 5 * ecran.width / 16 &&(float) ecran.mouse_y < 5 * ecran.height / 9 &&ecran.mouse_y > 7 * ecran.height / 18) {
                                        jeu.joueur[jeu.info.joueurQuiJoue].classe = PACMAN;
                                    } else if ((float) ecran.mouse_x < 5 * ecran.width / 9 &&ecran.mouse_x > 65 * ecran.width / 144 &&(float) ecran.mouse_y < 5 * ecran.height / 9 &&ecran.mouse_y > 7 * ecran.height / 18) {
                                        jeu.joueur[jeu.info.joueurQuiJoue].classe = PEACH;
                                    } else if ((float) ecran.mouse_x < 25 * ecran.width / 36 &&ecran.mouse_x > 85 * ecran.width / 144 &&(float) ecran.mouse_y < 5 * ecran.height / 9 &&ecran.mouse_y > 7 * ecran.height / 18) {
                                        jeu.joueur[jeu.info.joueurQuiJoue].classe = MARIO;
                                    } else if ((float) ecran.mouse_x < 5 * ecran.width / 6 &&ecran.mouse_x > 35 * ecran.width / 48 &&(float) ecran.mouse_y < 5 * ecran.height / 9 &&ecran.mouse_y > 7 * ecran.height / 18) {
                                        jeu.joueur[jeu.info.joueurQuiJoue].classe = DONKEY_KONG;
                                    }
                                }
                                if((float) ecran.mouse_x < 3*ecran.width/5 && ecran.mouse_x > 2*ecran.width/5 && (float) ecran.mouse_y < 9*ecran.height/27 && ecran.mouse_y > 7*ecran.height/27) {
                                    if(jeu.info.entrerPseudo == false) {
                                        jeu.info.entrerPseudo = true;
                                    }
                                    else if(jeu.joueur[jeu.info.joueurQuiJoue].pseudo[0] != '\0'){
                                        if(jeu.info.joueurQuiJoue+1 != jeu.info.nbJoueur) {
                                            jeu.info.joueurQuiJoue++;
                                            jeu.info.entrerPseudo = false;
                                        }
                                    }
                                }
                                if (((float) mouse_x - 1829*ecran.width/1920)*((float) mouse_x - 1829*ecran.width/1920)  + (mouse_y - 49*ecran.height/54)*(mouse_y - 49*ecran.height/54) < ecran.width/24 * ecran.width/24){
                                    jeu.gameMode = JEU;
                                }
                                break;
                            }
                        }
                    }
                }
                case ALLEGRO_EVENT_MOUSE_BUTTON_UP:
                    if ((event.mouse.button & 1) == 1) {
                        map[0][0].t = 0;

                    }
                    break;

                case ALLEGRO_EVENT_TIMER : {
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
                        afficherPseudo(jeu, width, height, gameFont1);
                        break;
                    }
                    case JEU : {
                        drawPlay(jeu.joueur, map, mouse_x, mouse_y, width, height, scalex, scaley, display,
                                 white, black, gris, vert, red);
                        deplacementJoueur(jeu.joueur, map, scalex, scaley);
                        dessinerQuadrillage(width, height, scalex, scaley, black);
                        al_draw_circle(jeu.joueur[0].x, jeu.joueur[0].y, 50, black, 3);
                        drawSort(gameFont1, jeu, ecran);
                        break;
                    }
                }
                al_flip_display();
                al_clear_to_color(black);
                draw = 0;
            }
        }
        else isFin = 1;
    }
    return 0;
}



