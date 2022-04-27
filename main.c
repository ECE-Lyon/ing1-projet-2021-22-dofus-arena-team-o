#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>

#define RULESPAGEMAX 5

enum gameMode {PLAY, RULES, TEAM, MENU, END};

void drawRules(int* pages, float height, float width) {
    ALLEGRO_COLOR jauneLogo = al_map_rgb(255, 204, 51) ;
    ALLEGRO_COLOR marronLogo = al_map_rgb(102, 51, 0) ;
    ALLEGRO_FONT* gameFont = al_load_ttf_font("../MagicCardsNormal.ttf", 2*width/55, ALLEGRO_ALIGN_LEFT) ;
    if(*pages < RULESPAGEMAX) {
        al_draw_circle(13*width/15, 11*height/13, width/38.4, jauneLogo, 4) ;
        al_draw_line(13*width/15 - width/64 , 11*height/13, 13*width/15 + width/64, 11*height/13, jauneLogo, 3);
        al_draw_line(13*width/15 + width/64, 11*height/13, 13*width/15 + width/192, 11*height/13 - height/43.2 , jauneLogo, 3);
        al_draw_line(13*width/15 + width/64, 11*height/13, 13*width/15 + width/192, 11*height/13 + height/43.2 , jauneLogo, 3);
    }
    if(*pages > 1) {
        al_draw_circle(2*width/15, 11*height/13, 50, jauneLogo, 4) ;
        al_draw_line(2*width/15 - width/64, 11*height/13, 2*width/15 + width/64, 11*height/13, jauneLogo, 3) ;
        al_draw_line(2*width/15 - width/64, 11*height/13, 2*width/15 - width/192 , 11*height/13 - height/43.2, jauneLogo, 3) ;
        al_draw_line(2*width/15 - width/64, 11*height/13, 2*width/15 - width/192 , 11*height/13 + height/43.2, jauneLogo, 3) ;
    }
    al_draw_text(gameFont, marronLogo, width/90, height/50, ALLEGRO_ALIGN_LEFT, "RETURN") ;
    al_draw_rectangle(width/384, height/216, 2*width/13, 2*height/27, marronLogo, 3) ;
    al_draw_textf(gameFont, jauneLogo, 7.5*width/15, 11*height/13 + height/18, ALLEGRO_ALIGN_CENTER, "%d / %d", *pages, RULESPAGEMAX) ;
    al_destroy_font(gameFont) ;
}


void drawTeam(float height, float width) {
    ALLEGRO_BITMAP* moi = al_load_bitmap("../InfoPhotoM150.PNG") ;
    ALLEGRO_BITMAP* toi = al_load_bitmap("../InfoPhotoW150.PNG") ;
    ALLEGRO_FONT *gameFont = al_load_ttf_font("../MagicCardsNormal.ttf", 2*width/55, ALLEGRO_ALIGN_LEFT);
    al_draw_filled_circle(width/4, height/4, width/17.3, al_map_rgb(255, 255, 255)) ;
    al_draw_circle(width/4, height/4, width/17.3, al_map_rgb(255, 0, 0), 5) ;
    al_draw_scaled_bitmap(moi, 0, 0, 150, 149,width/4 - 5*width/128, height/4 - 5*height/72, width/5, 2*width/17.3 - height/27, 0) ;
    al_draw_text(gameFont, al_map_rgb(255, 0, 0), width/4 , height/4 + height/9, ALLEGRO_ALIGN_CENTER, "Nel") ;

    al_draw_filled_circle(3*width/4 , height/4, width/17.3, al_map_rgb(255, 255, 255)) ;
    al_draw_circle(3 * width / 4, height / 4, width/17.3, al_map_rgb(255, 0, 0), 5) ;
    al_draw_scaled_bitmap(toi, 0, 0, 150, 149, 3*width/4 - 5*width/128, height/4 - 5*height/72, 2*width/17.3 - width/48, 2*width/17.3 - height/27, ALLEGRO_FLIP_HORIZONTAL) ;
    al_draw_text(gameFont, al_map_rgb(255, 0, 0), 3*width/4 , height/4 + height/9, ALLEGRO_ALIGN_CENTER, "Zelie") ;

    al_draw_filled_circle(width/4, 3*height/4, width/17.3, al_map_rgb(255, 255, 255)) ;
    al_draw_circle(width/4, 3*height/4, width/17.3, al_map_rgb(255, 0, 0), 5) ;
    al_draw_scaled_bitmap(moi, 0, 0, 150, 149, width/4 - 5*width/128, 3*height/4 - 5*height/72, 2*width/17.3 - width/48, 2*width/17.3 - height/27, ALLEGRO_FLIP_HORIZONTAL) ;
    al_draw_text(gameFont, al_map_rgb(255, 0, 0), width / 4 , 3*height/4 + height/9, ALLEGRO_ALIGN_CENTER, "Fares") ;

    al_draw_filled_circle(3*width/4, 3*height/4, width/17.3, al_map_rgb(255, 255, 255)) ;
    al_draw_circle(3*width/4, 3*height/4, width/17.3, al_map_rgb(255, 0, 0), 5) ;
    al_draw_scaled_bitmap(toi, 0, 0, 150, 149, 3*width/4 - 5*width/128, 3*height/4 - 5*height/72, 2*width/17.3 - width/48, 2*width/17.3 - height/27, 0) ;
    al_draw_text(gameFont, al_map_rgb(255, 0, 0), 3*width/4 , 3*height/4 + height/9, ALLEGRO_ALIGN_CENTER, "Ilayda") ;

    al_draw_text(gameFont, al_map_rgb(255, 0, 0), width/90, height/50, ALLEGRO_ALIGN_LEFT, "RETURN") ;
    al_draw_rectangle(5, 5, 5*width/32, 2*height/27, al_map_rgb(255, 0, 0), 3) ;
    al_destroy_bitmap(moi) ;
    al_destroy_bitmap(toi) ;
    al_destroy_font(gameFont) ;
}

void drawMenu(int rect1, int rect2, int rect3, float height, float width) {
    unsigned char alpha ;
    double gradient = 255 ;
    float thickness1 = (29*height/54 - 25*height/54) / 40 ;
    float thickness2 = (5*height/9 - 4*height/9) / 40 ;
    ALLEGRO_COLOR jauneLogo = al_map_rgb(255, 204, 51) ;
    ALLEGRO_COLOR marronLogo = al_map_rgb(102, 51, 0) ;
    ALLEGRO_FONT *gameFont = al_load_ttf_font("../MagicCardsNormal.ttf", 7*width/198, ALLEGRO_ALIGN_LEFT);
    ALLEGRO_FONT *gameFont1 = al_load_ttf_font("../MagicCardsNormal.ttf", width/22, ALLEGRO_ALIGN_LEFT);
    for (float i = 0; i < 40; i++) {
        alpha = (unsigned char) gradient;
        if (!rect1) {
            al_draw_line(0, 25*height/54 + thickness1*i, 5*width/32 + (thickness1/2)*i , 25*height/54 + thickness1*i,
                         al_map_rgba(155, 204, 51, alpha), thickness1);
        } else {
            al_draw_line(0, 4*height/9 + thickness2*i, 21*width/128 + (thickness2/2)*i, 4*height/9 + thickness2*i,
                         al_map_rgba(155, 204, 51, alpha), thickness2);
            al_draw_line(0, 4*height/9, 53*width/320, 4*height/9, marronLogo, 6);
            al_draw_line(0, 5*height/9, 21*width/128 + (thickness2/2)*40, 5*height/9, marronLogo, 6);
            al_draw_line(0, 4*height/9, 0, 5*height/9, marronLogo, 6);
            al_draw_line(21*width/128, 4*height/9, 21*width/128 + (thickness2/2)*40, 5*height/9, marronLogo, 6);
        }
        if (!rect2) {
            al_draw_line(0, height/2 + 2*height/27 + thickness1*i, 5*width/32 + (thickness1/2)*i, height/2 + 2*height/27 + thickness1*i,
                         al_map_rgba(155, 204, 51, alpha), thickness1);
        } else {
            al_draw_line(0, 5*height/9 + thickness2*i, 21*width/128 + (thickness2/2)*i, 5*height/9 + thickness2*i,
                         al_map_rgba(155, 204, 51, alpha), thickness2);
            al_draw_line(0, 5*height/9, 53*width/320, 5*height/9, marronLogo, 6);
            al_draw_line(0, 2*height/3, 21*width/128 + (thickness2/2)*40, 2*height/3, marronLogo, 6);
            al_draw_line(0, 5*height/9, 0, 2*height/3, marronLogo, 6);
            al_draw_line(21*width/128, 5*height/9, 21*width/128 + (thickness2/2)*40, 2*height/3, marronLogo, 6);
        }
        if (!rect3) {
            al_draw_line(0, height/2 + 5*height/27 + thickness1*i, 5*width/32 + (thickness1/2)*i, height/2 + 5*height/27 + thickness1*i,
                         al_map_rgba(155, 204, 51, alpha), thickness1);
        } else {
            al_draw_line(0, 2*height/3 + thickness2*i, 21*width/128 + (thickness2/2)*i, 2*height/3 + thickness2*i,
                         al_map_rgba(155, 204, 51, alpha), thickness2);
            al_draw_line(0, 2*height/3, 53*width/320, 2*height/3, marronLogo, 6);
            al_draw_line(0, 7*height/9, 21*width/128 + (thickness2/2)*40, 7*height/9, marronLogo, 6);
            al_draw_line(0, 2*height/3, 0, 7*height/9, marronLogo, 6);
            al_draw_line(21*width/128, 2*height/3, 21*width/128 + (thickness2/2)*40, 7*height/9, marronLogo, 6);
        }
        gradient -=31.875;
    }
    if (!rect1) {
        al_draw_textf(gameFont, marronLogo, 17*width/480, 64*height/135, ALLEGRO_ALIGN_LEFT, "PLAY");
    } else al_draw_textf(gameFont1, marronLogo, width/38, 7*height/15, ALLEGRO_ALIGN_LEFT, "PLAY");
    if (!rect2) {
        al_draw_textf(gameFont, marronLogo, width/38.4, 7.05*height/12, ALLEGRO_ALIGN_LEFT, "RULES");
    } else al_draw_textf(gameFont1, marronLogo, width/56.5, height/1.74, ALLEGRO_ALIGN_LEFT, "RULES");
    if (!rect3) {
        al_draw_textf(gameFont, marronLogo, width/38.4, height/1.43, ALLEGRO_ALIGN_LEFT, "TEAM");
    } else al_draw_textf(gameFont1, marronLogo, 3*width/128, height/1.45, ALLEGRO_ALIGN_LEFT, "TEAM");
    gradient = 255;
    al_destroy_font(gameFont);
    al_destroy_font(gameFont1);
}

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

    //al_set_new_display_flags(ALLEGRO_FULLSCREEN_WINDOW) ;

    ALLEGRO_FONT *ttf = al_load_ttf_font("../Achafont.ttf", 145, ALLEGRO_ALIGN_LEFT) ;
    ALLEGRO_FONT *surlign = al_load_ttf_font("../Achafout.ttf", 145, ALLEGRO_ALIGN_LEFT) ;
    ALLEGRO_EVENT event = {0};

    int isFin = 0, draw = 0, nbMissiles = 0 ;
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
                                if (event.mouse.x < 5*width/32 && event.mouse.x > 5 && event.mouse.y < 2*height/27 && event.mouse.y > 5) {
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
                                if (event.mouse.x < 5*width/32 && event.mouse.x > 5 && event.mouse.y < 80 && event.mouse.y > 5) {
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
                        if ((float) mouse_x < 5*width/32 && mouse_x > 5 && (float) mouse_y < 2*height/27 && mouse_y > 5) {
                            al_draw_rectangle(5, 5, 5*width/32, 2*height/27, al_map_rgb(155, 204, 107), 4) ;
                        }
                        break ;
                    }
                    case RULES : {
                        drawRules(&page, height, width) ;
                        if ((float) mouse_x < 5*width/32 && mouse_x > 5 && (float) mouse_y < 2*height/27 && mouse_y > 5) {
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