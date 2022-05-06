
#include "menu.h"
#include "jeu.h"
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
    display = al_create_display(1300, 1000);
    al_set_display_flag(display, ALLEGRO_FULLSCREEN_WINDOW, true);
    float height = (float) al_get_display_height(display);
    float width = (float) al_get_display_width(display);
    al_set_window_position(display, 0, 0);


    printf("X = %d\nY = %d", al_get_display_width(display), al_get_display_height(display));

    ///CREATOON DES VARIABLES
    ALLEGRO_COLOR black = al_map_rgb(0, 0, 0);
    ALLEGRO_COLOR red = al_map_rgb(255, 0, 0);
    ALLEGRO_COLOR white = al_map_rgb(255, 255, 255);
    ALLEGRO_COLOR vert = al_map_rgba(93, 127, 51, 255);
    ALLEGRO_COLOR gris = al_map_rgb(128,128,128) ;
    ALLEGRO_COLOR gameColor = al_map_rgb(255, 0, 0);

    ///FONT
    ALLEGRO_FONT *gameFont1 = al_load_ttf_font("../Font/Nintendo.ttf", 72, ALLEGRO_ALIGN_LEFT) ;
    ALLEGRO_FONT *gameFont = al_load_ttf_font("../Font/MagicCardsNormal.ttf", 2 * width / 55, ALLEGRO_ALIGN_LEFT);
    ALLEGRO_FONT *gameFont2 = al_load_ttf_font("../Font/MagicCardsNormal.ttf", 10, ALLEGRO_ALIGN_LEFT);
    ALLEGRO_FONT *gameFontRegles = al_load_ttf_font("../Font/Rumpi.ttf", 40, ALLEGRO_ALIGN_LEFT);
    ///BITMAP
    ALLEGRO_BITMAP *background = al_load_bitmap("../Bitmap/BG.jpg");
    ALLEGRO_BITMAP *team = al_load_bitmap("../Bitmap/capture.PNG");

    queue = al_create_event_queue();
    assert(queue);

    int isFin = 0, draw = 0;
    char lettre ;
    Menu mainMenu;
    Map map[20][20];
    Joueur joueur[4];
    int nbJoueur = 0;
    int nbLettre = 0;
    int joueurQuiJoue = 0 ;


    ///INITIALISATION DE NOS VARIABLES (A FAIRE DANS UNE FONCTION)
    mainMenu.ecran.width = (float) al_get_display_width(display) ;
    mainMenu.ecran.height = (float) al_get_display_height(display) ;
    mainMenu.gameMode = MENU;
    mainMenu.playRect = 0;
    mainMenu.rulesRect = 0;
    mainMenu.teamRect = 0;
    mainMenu.arc.startTheta = 0;
    mainMenu.arc.endTheta = 2 * PI;
    mainMenu.arc.currentTheta = 0;
    mainMenu.arc.currentEndTheta = 2 * PI;
    double scalex = 50.0*width/1800.0;
    double scaley = 50.0*height/1800.0;
    for (int j=0;j<mapY;j++) {
        for (int i = 0; i < mapX; i++) {
            map[i][j].x =  scalex + i * scalex + j * scalex;
            map[i][j].y = height/1.8 - i * scaley + j * scaley;

        }
    }
    joueur[0].xp = map[0][0].x;
    joueur[0].yp = map[0][0].y;
    joueur[0].caseX=0;
    joueur[0].caseY=0;
    joueur[0].s = 0;
    InfosJoueur* joueur2 = malloc(4 * sizeof (InfosJoueur)) ;
    for(int i = 0 ; i < 4 ; i++) {
        strcpy(joueur2[i].pseudo, "");
        joueur2[i].nbLettrePseudo = 0 ;
    }
    float mouse_x = 0, mouse_y = 0;
    int page = 1;


    ///INITIALISATION CLASSE
    //joueur2->classe = VIDE;


    ///INITIALISATION DU TIMER
    times = al_create_timer(0.02);


    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_mouse_event_source());
    al_register_event_source(queue, al_get_timer_event_source(times));


    al_start_timer(times);
    while (!isFin) {
        al_wait_for_event(queue, &event);
        switch (event.type) {
            case ALLEGRO_EVENT_KEY_DOWN : {
                switch (event.keyboard.keycode) {
                    case ALLEGRO_KEY_ESCAPE : {
                        mainMenu.gameMode = END;
                        isFin = 1;
                        break;
                    }
                    case ALLEGRO_KEY_RIGHT : {
                        joueurQuiJoue++ ;
                        break ;
                    }
                    case ALLEGRO_KEY_LEFT : {
                        joueurQuiJoue-- ;
                        break ;
                    }
                    default: {
                        lettre =  alphabet(event.keyboard.keycode, &joueur2[joueurQuiJoue].nbLettrePseudo) ;
                        mettrePseudo(&joueur2, lettre , joueurQuiJoue, &joueur2[joueurQuiJoue].nbLettrePseudo) ;
                        break ;
                    }

                }
                break;
            }
            case ALLEGRO_EVENT_MOUSE_AXES : {
                mouse_x = event.mouse.x;
                mouse_y = event.mouse.y;
                mainMenu.ecran.mouse_x = event.mouse.x;
                mainMenu.ecran.mouse_y = event.mouse.y;
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
                            if (mouse_x < 49 * width / 110 && mouse_x > 21 * width / 110 && mouse_y < 322 * height / 495 && mouse_y > 4 * height / 9) {
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
                                (mouse_y - 11 * height / 13) * (mouse_y - 11 * height / 13) < 50 * 50) {
                                if (page + 1 <= RULESPAGEMAX) {
                                    page++;
                                }
                            }
                            if ((mouse_x - 2 * width / 15) * (mouse_x - 2 * width / 15) +
                                (mouse_y - 11 * height / 13) * (mouse_y - 11 * height / 13) < 50 * 50) {
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
                        case PLAY : {
                            if (mouse_x < 5 * width / 32 && mouse_x > width / 384 &&
                                    mouse_y < 2 * height / 27 && mouse_y > height / 216) {
                                mainMenu.gameMode = MENU;
                            }
                            if (((mouse_x - 400) * (mouse_x - 400)) + ((mouse_y - 500) * (mouse_y - 500)) < 100 * 100) {
                                nbJoueur = 2;
                            } else if (((mouse_x - 950) * (mouse_x - 950)) + ((mouse_y - 500) * (mouse_y - 500)) <
                                       100 * 100) {
                                nbJoueur = 3;
                            } else if (((mouse_x - 1500) * (mouse_x - 1500)) + ((mouse_y - 500) * (mouse_y - 500)) <
                                       100 * 100) {
                                nbJoueur = 4;
                            }
                        }

                    }
                }
                break;
            }
            case ALLEGRO_EVENT_MOUSE_BUTTON_UP:
                if ((event.mouse.button & 1) == 1) {
                    map[0][0].t=0;

                }
                break;

            case ALLEGRO_EVENT_TIMER : {
                    //printf("%d,  %d\n", mouse_x, mouse_y) ;
                //printf("%d,  %d\n", mouse_x, mouse_y) ;
                    /// MENU V1 ::::::
                    /*if (mouse_x < 5*width/32 && mouse_x > 0 && mouse_y < 29*height/54 && mouse_y > 25*height/54) {
                        mainMenu.playRect = 1 ;
                    } else mainMenu.playRect = 0;
                    if (mouse_x < 5*width/32 && mouse_x > 0 && mouse_y < 35*height/54 && mouse_y > 31*height/54) {
                        mainMenu.rulesRect = 1 ;
                    } else mainMenu.rulesRect = 0;
                    if (mouse_x < 5*width/32 && mouse_x > 0 && mouse_y < 41*height/54 && mouse_y > 37*height/54) {
                        mainMenu.teamRect = 1 ;
                    } else mainMenu.teamRect = 0;*/
                    /// MENU V2 :::::::
                    menuSouris(&mainMenu, height, width, mouse_x, mouse_y) ;
                    draw = 1;
                }
            }
            if (draw) {
                al_draw_scaled_bitmap(background, 0, 0, 7680, 4320, 0, 0, width, height, 0);
                switch (mainMenu.gameMode) {
                    case MENU : {
                        drawMenuV2(&mainMenu, gameFont) ;
                        break ;
                    }
                    case TEAM : {
                        drawTeam(height, width, mouse_x, mouse_y, gameFont1, team);
                        break ;

                    }
                    case RULES : {
                        drawRules(&page, height, width, mouse_x, mouse_y, gameFontRegles, gameFont);
                        break;
                    }
                    case PLAY : {
                        //drawPlay(joueur,map,event,mouse_x,mouse_y,display,white,black,gris,vert,red);
                        //deplacementJoueur(joueur,map,scalex,scaley);
                        //al_draw_circle(joueur[0].xp,joueur[0].yp,50,black,3);
                        //choixJoueur(width, height, mouse_x, mouse_y, gameFont1, &nbJoueur) ;
                        //drawChooseCharacter(height, width,joueurQuiJoue) ;
                        //afficherPseudo(joueur2, width, height, gameFont1, 4) ;
                        //drawPlay(map,event,mouse_x,mouse_y,display,white,black,gris,vert,red);
                        drawChooseCharacter(height, width, gameFont1, &nbJoueur, mouse_x, mouse_y, &joueur2) ;
                        afficherPseudo(joueur2, width, height, gameFont1, 1) ;
                        //drawPlay2(width, height, mouse_x, mouse_y, gameFont,gameFontRegles, &nbJoueur) ;
                    break;
                }

            }
            al_flip_display();
            al_clear_to_color(black);
            draw = 0;
        }
    }
    return 0;
}



