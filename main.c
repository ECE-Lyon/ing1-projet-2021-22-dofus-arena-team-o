#include "jeu.h"

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
    al_init_primitives_addon() ;

    ///CREATION DU DISPLAY
    al_set_new_display_flags(ALLEGRO_FULLSCREEN_WINDOW) ;

    ///CREATOON DES VARIABLES
    ALLEGRO_COLOR black = al_map_rgb(0, 0, 0);
    ALLEGRO_COLOR red = al_map_rgb(255, 0, 0);
    ALLEGRO_COLOR jauneLogo = al_map_rgb(255, 204, 51) ;
    ALLEGRO_COLOR marronLogo = al_map_rgb(102, 51, 0) ;
    int isFin = 0, draw = 0;
    int rotation = 0 ;
    Menu mainMenu ;

    mainMenu.gameMode = MENU ;
    mainMenu.playRect = 0 ;
    mainMenu.rulesRect = 0 ;
    mainMenu.teamRect = 0 ;
    mainMenu.startTheta = 0 ;
    mainMenu.endTheta = 2*PI ;
    mainMenu.currentTheta = 0 ;
    mainMenu.currentEndTheta = 2*PI ;
    int mouse_x = 0, mouse_y = 0 ;

    display = al_create_display(1300, 1000);
    float height = (float) al_get_display_height(display) ;
    float width = (float) al_get_display_width(display) ;
    al_set_window_position(display, 0, 0);

    ALLEGRO_FONT* gameFontRegles = al_load_ttf_font("../Font/Rumpi.ttf",  40, ALLEGRO_ALIGN_LEFT) ;
    ALLEGRO_COLOR gameColor = al_map_rgb(255, 0, 0) ;

    queue = al_create_event_queue();
    assert(queue);
    unsigned char alpha ;
    double gradient = 255 ;
    int page = 1 ;
    times = al_create_timer(0.02);


    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_mouse_event_source());
    al_register_event_source(queue, al_get_timer_event_source(times));


    al_clear_to_color(black);
    //al_draw_text(ttf, al_map_rgb(255, 25, 15), 875, 270, ALLEGRO_ALIGN_LEFT, "PLAY");
    ALLEGRO_BITMAP* background = al_load_bitmap("../Bitmap/BG.jpg") ;
    al_flip_display();
    al_start_timer(times);
    while(!isFin) {
        while (mainMenu.gameMode != PLAY && !isFin) {
            al_wait_for_event(queue, &event);
            switch (event.type) {
                case ALLEGRO_EVENT_KEY_DOWN : {
                    switch (event.keyboard.keycode) {
                        case ALLEGRO_KEY_ESCAPE : {
                            mainMenu.gameMode = END;
                            isFin = 1;
                            break;
                        }
                    }
                    break;
                }
                case ALLEGRO_EVENT_MOUSE_AXES : {
                    mouse_x = event.mouse.x ;
                    mouse_y = event.mouse.y ;
                    break;
                }
                case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN : {
                    if ((event.mouse.button & 1) == 1) {
                        switch (mainMenu.gameMode) {
                            case MENU : {
                                /// MENU V1 :::::::
                                /*if (mouse_x < 5*width/32 && mouse_x > 0 && mouse_y < 29*height/54 && mouse_y > 25*height/54) {
                                    mainMenu.gameMode = PLAY;
                                } else if (mouse_x < 5*width/32 && mouse_x > 0 && mouse_y < 35*height/54 && mouse_y > 31*height/54) {
                                    mainMenu.gameMode = RULES;
                                } else if (mouse_x < 5*width/32 && mouse_x > 0 && mouse_y < 41*height/54 && mouse_y > 37*height/54) {
                                    mainMenu.gameMode = TEAM;
                                }*/

                                /// MENU V2 :::::
                                if (mouse_x < 157*width/275 && mouse_x > 118*width/275 && mouse_y < 38*height/99 && mouse_y > 7*height/80) {
                                    mainMenu.gameMode = PLAY;
                                }
                                if (mouse_x < 49*width/110 && mouse_x > 21*width/110 && mouse_y < 322*height/495 && mouse_y > 4*height/9) {
                                    mainMenu.gameMode = RULES;
                                }
                                if (mouse_x < 89*width/110 && mouse_x > 61*width/110 && mouse_y < 322*height/495 && mouse_y > 4*height/9) {
                                    mainMenu.gameMode = TEAM;;
                                }

                                break ;
                            }
                            case TEAM : {
                                if (event.mouse.x < 5*width/32 && event.mouse.x > width/384 && event.mouse.y < 2*height/27 && event.mouse.y > height/216) {
                                    mainMenu.gameMode = MENU;
                                }
                                break ;
                            }
                            case RULES : {
                                if((mouse_x - 13 * width / 15) * (mouse_x - 13 * width / 15) + (mouse_y - 11 * height / 13) * (mouse_y - 11 * height / 13) < 50 * 50) {
                                    if(page + 1 <= RULESPAGEMAX) {
                                        page++;
                                    }
                                }
                                if((mouse_x - 2 * width / 15) * (mouse_x - 2 * width / 15) + (mouse_y - 11 * height / 13) * (mouse_y - 11 * height / 13) < 50 * 50) {
                                    if(page - 1 >= 1) {
                                        page--;
                                    }
                                }
                                if (event.mouse.x < 5*width/32 && event.mouse.x > width/384 && event.mouse.y < 2*height/27 && event.mouse.y > height/216) {
                                    mainMenu.gameMode = MENU;
                                    page = 1 ;
                                }
                                break ;
                            }
                        }
                    }
                    break;
                }
                case ALLEGRO_EVENT_TIMER : {
                    printf("%d,  %d\n", mouse_x, mouse_y) ;
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
                    menuClick(&mainMenu, height, width, mouse_x, mouse_y) ;
                    draw = 1;
                }
            }
            if (draw) {
                al_draw_scaled_bitmap(background, 0, 0, 7680, 4320, 0, 0, width, height, 0);
                switch (mainMenu.gameMode) {
                    case MENU : {
                        drawMenuV2(&mainMenu, height, width) ;
                        break ;
                    }
                    case TEAM : {
                        drawTeam(height, width, mouse_x, mouse_y) ;
                        break ;
                    }
                    case RULES : {
                        drawRules(&page, height, width, mouse_x, mouse_y, gameFontRegles);
                        break;
                    }
                    case PLAY : {
                        break ;
                    }
                }
                al_flip_display();
                al_clear_to_color(black);
                draw = 0;
            }
        }
    }
    return 0;
}