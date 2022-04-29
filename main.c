#include "jeu.h"

int main() {
    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_EVENT_QUEUE *queue;
    ALLEGRO_TIMER *times;

    srand(time(NULL));
    assert(al_init());
    al_install_keyboard();
    al_install_mouse();

    al_init_image_addon();
    al_init_font_addon();
    al_init_ttf_addon();
    al_init_primitives_addon() ;

    al_set_new_display_flags(ALLEGRO_FULLSCREEN_WINDOW) ;

    ALLEGRO_FONT *ttf = al_load_ttf_font("../Achafont.ttf", 145, ALLEGRO_ALIGN_LEFT) ;
    ALLEGRO_FONT *surlign = al_load_ttf_font("../Achafout.ttf", 145, ALLEGRO_ALIGN_LEFT) ;
    ALLEGRO_EVENT event = {0};

    int isFin = 0, draw = 0;
    int gameModes = MENU;
    int rotation = 0 ;

    int rect1 = 0, rect2 = 0, rect3 = 0, mouse_x = 0, mouse_y = 0 ;

    ALLEGRO_COLOR black = al_map_rgb(0, 0, 0);
    ALLEGRO_COLOR red = al_map_rgb(255, 0, 0);
    ALLEGRO_COLOR jauneLogo = al_map_rgb(255, 204, 51) ;
    ALLEGRO_COLOR marronLogo = al_map_rgb(102, 51, 0) ;

    display = al_create_display(1000, 800);
    float height = (float) al_get_display_height(display) ;
    float width = (float) al_get_display_width(display) ;


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
    ALLEGRO_BITMAP* background = al_load_bitmap("../dofus.jpg") ;
    al_flip_display();
    al_start_timer(times);
    while(!isFin) {
        while (gameModes != PLAY && !isFin) {
            al_wait_for_event(queue, &event);
            switch (event.type) {
                case ALLEGRO_EVENT_KEY_DOWN : {
                    switch (event.keyboard.keycode) {
                        case ALLEGRO_KEY_ENTER : {
                            gameModes = END;
                            isFin = 1 ;
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
                        switch (gameModes) {
                            case MENU : {
                                if (mouse_x < 5*width/32 && mouse_x > 0 && mouse_y < 29*height/54 && mouse_y > 25*height/54) {
                                    gameModes = PLAY;
                                } else if (mouse_x < 5*width/32 && mouse_x > 0 && mouse_y < 35*height/54 && mouse_y > 31*height/54) {
                                    gameModes = RULES;
                                } else if (mouse_x < 5*width/32 && mouse_x > 0 && mouse_y < 41*height/54 && mouse_y > 37*height/54) {
                                    gameModes = TEAM;
                                }
                                break ;
                            }
                            case TEAM : {
                                if (event.mouse.x < 5*width/32 && event.mouse.x > width/384 && event.mouse.y < 2*height/27 && event.mouse.y > height/216) {
                                    gameModes = MENU;
                                }
                                break ;
                            }
                            case RULES : {
                                if((event.mouse.x - 13 * width / 15) * (event.mouse.x - 13 * width / 15) + (event.mouse.y - 11 * height / 13) * (event.mouse.y - 11 * height / 13) < 50 * 50) {
                                    if(page + 1 <= RULESPAGEMAX) {
                                        page++;
                                    }
                                }
                                if((event.mouse.x - 2 * width / 15) * (event.mouse.x - 2 * width / 15) + (event.mouse.y - 11 * height / 13) * (event.mouse.y - 11 * height / 13) < 50 * 50) {
                                    if(page - 1 >= 1) {
                                        page--;
                                    }
                                }
                                if (event.mouse.x < 5*width/32 && event.mouse.x > width/384 && event.mouse.y < 2*height/27 && event.mouse.y > height/216) {
                                    gameModes = MENU;
                                    page = 1 ;
                                }
                                break ;
                            }
                        }
                    }
                    break;
                }
                case ALLEGRO_EVENT_TIMER : {
                    if (mouse_x < 5*width/32 && mouse_x > 0 && mouse_y < 29*height/54 && mouse_y > 25*height/54) {
                        rect1 = 1 ;
                    } else rect1 = 0;
                    if (mouse_x < 5*width/32 && mouse_x > 0 && mouse_y < 35*height/54 && mouse_y > 31*height/54) {
                        rect2 = 1 ;
                    } else rect2 = 0;
                    if (mouse_x < 5*width/32 && mouse_x > 0 && mouse_y < 41*height/54 && mouse_y > 37*height/54) {
                        rect3 = 1 ;
                    } else rect3 = 0;
                    draw = 1;
                }
            }
            if (draw) {
                printf("%d   %d\n", height, width) ;
                switch (gameModes) {
                    case MENU : {
                        al_draw_scaled_bitmap(background, 0, 0, 1920, 1080, 0, 0, width, height, 0);
                        drawMenu(rect1, rect2, rect3, height, width) ;
                        break ;
                    }
                    case TEAM : {
                        drawTeam(height, width) ;
                        if ((float) mouse_x < 5*width/32 && mouse_x > width/384 && (float) mouse_y < 2*height/27 && mouse_y > height/216) {
                            al_draw_rectangle(5, 5, 5*width/32, 2*height/27, al_map_rgb(155, 204, 107), 4) ;
                        }
                        break ;
                    }
                    case RULES : {
                        drawRules(&page, height, width) ;
                        if ((float) mouse_x < 5*width/32 && mouse_x > width/384 && (float) mouse_y < 2*height/27 && mouse_y > height/216) {
                            al_draw_rectangle(5, 5, 5*width/32, 2*height/27, al_map_rgb(155, 204, 107), 4) ;
                        }
                        break ;
                    }
                        /*case END : {
                            isFin = 1 ;
                            break ;
                        }*/
                }
                al_flip_display();
                al_clear_to_color(black);
                draw = 0;
            }
        }
        ALLEGRO_FONT *gameFont = al_load_ttf_font("../MagicCardsNormal.ttf", 70, ALLEGRO_ALIGN_LEFT);
        al_draw_textf(gameFont, al_map_rgb(255, 0, 0), 1920/2, 540, ALLEGRO_ALIGN_CENTER, "rien" ) ;
        al_destroy_font(gameFont) ;
        al_flip_display() ;
        al_clear_to_color(black) ;
    }
    return 0;
}