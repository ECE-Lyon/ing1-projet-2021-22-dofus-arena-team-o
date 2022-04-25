#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>

#define RULESPAGEMAX 10

enum gameMode {PLAY, RULES, TEAM, MENU, END};

void drawRules(int* pages, int height, int width) {
    ALLEGRO_COLOR jauneLogo = al_map_rgb(255, 204, 51) ;
    ALLEGRO_COLOR marronLogo = al_map_rgb(102, 51, 0) ;
    ALLEGRO_FONT* gameFont = al_load_ttf_font("../MagicCardsNormal.ttf", 72, ALLEGRO_ALIGN_LEFT) ;
    if(*pages < RULESPAGEMAX) {
        al_draw_circle(13 * width / 15, 11 * height / 13, 50, jauneLogo, 4) ;
        al_draw_line(13 * width / 15 - 30, 11 * height / 13, 13 * width / 15 + 30, 11 * height / 13, jauneLogo, 3);
        al_draw_line(13 * width / 15 + 30, 11 * height / 13, 13 * width / 15 + 10, 11 * height / 13 - 25, jauneLogo, 3);
        al_draw_line(13 * width / 15 + 30, 11 * height / 13, 13 * width / 15 + 10, 11 * height / 13 + 25, jauneLogo, 3);
    }
    if(*pages > 1) {
        al_draw_circle(2 * width / 15, 11 * height / 13, 50, jauneLogo, 4) ;
        al_draw_line(2 * width / 15 - 30, 11 * height / 13, 2 * width / 15 + 30, 11 * height / 13, jauneLogo, 3) ;
        al_draw_line(2 * width / 15 - 30, 11 * height / 13, 2 * width / 15 - 10 , 11 * height / 13 - 25, jauneLogo, 3) ;
        al_draw_line(2 * width / 15 - 30, 11 * height / 13, 2 * width / 15 - 10 , 11 * height / 13 + 25, jauneLogo, 3) ;
    }
    al_draw_text(gameFont, marronLogo, 15, 15, ALLEGRO_ALIGN_LEFT, "RETURN") ;
    al_draw_rectangle(5, 5, 300, 80, marronLogo, 3) ;
    al_draw_textf(gameFont, jauneLogo, 7.5 * width / 15, 11 * height / 13 + 60, ALLEGRO_ALIGN_CENTER, "%d / %d", *pages, RULESPAGEMAX) ;
    al_destroy_font(gameFont) ;
}


void drawTeam(int height, int width) {
    ALLEGRO_BITMAP* moi = al_load_bitmap("../InfoPhotoM150.PNG") ;
    ALLEGRO_BITMAP* toi = al_load_bitmap("../InfoPhotoW150.PNG") ;
    ALLEGRO_FONT *gameFont = al_load_ttf_font("../MagicCardsNormal.ttf", 70, ALLEGRO_ALIGN_LEFT);
    al_draw_filled_circle(width / 4, height / 4, 110, al_map_rgb(255, 255, 255)) ;
    al_draw_circle(width / 4, height / 4, 110, al_map_rgb(255, 0, 0), 5) ;
    al_draw_bitmap(moi, width / 4 - 75, height / 4 - 75, 0) ;
    al_draw_text(gameFont, al_map_rgb(255, 0, 0), width / 4 , height / 4 + 120, ALLEGRO_ALIGN_CENTER, "Nel") ;

    al_draw_filled_circle(3 * width / 4 , height / 4, 110, al_map_rgb(255, 255, 255)) ;
    al_draw_circle(3 * width / 4, height / 4, 110, al_map_rgb(255, 0, 0), 5) ;
    al_draw_bitmap(toi, 3 * width / 4 - 75, height / 4 - 75, ALLEGRO_FLIP_HORIZONTAL) ;
    al_draw_text(gameFont, al_map_rgb(255, 0, 0), 3 * width / 4 , height / 4 + 120, ALLEGRO_ALIGN_CENTER, "Zelie") ;

    al_draw_filled_circle(width / 4, 3 * height / 4, 110, al_map_rgb(255, 255, 255)) ;
    al_draw_circle(width / 4, 3 * height / 4, 110, al_map_rgb(255, 0, 0), 5) ;
    al_draw_bitmap(moi, width / 4 - 75, 3 * height / 4 - 75, ALLEGRO_FLIP_HORIZONTAL) ;
    al_draw_text(gameFont, al_map_rgb(255, 0, 0), width / 4 , 3 * height / 4 + 120, ALLEGRO_ALIGN_CENTER, "Fares") ;

    al_draw_filled_circle(3 * width / 4, 3 * height / 4, 110, al_map_rgb(255, 255, 255)) ;
    al_draw_circle(3 * width / 4, 3 * height / 4, 110, al_map_rgb(255, 0, 0), 5) ;
    al_draw_bitmap(toi, 3 * width / 4 - 75, 3 * height / 4 - 75, 0) ;
    al_draw_text(gameFont, al_map_rgb(255, 0, 0), 3 * width / 4 , 3 * height / 4 + 120, ALLEGRO_ALIGN_CENTER, "Ilayda") ;

    al_draw_text(gameFont, al_map_rgb(255, 0, 0), 15, 15, ALLEGRO_ALIGN_LEFT, "RETURN") ;
    al_draw_rectangle(5, 5, 300, 80, al_map_rgb(255, 0, 0), 3) ;
    al_destroy_bitmap(moi) ;
    al_destroy_bitmap(toi) ;
    al_destroy_font(gameFont) ;
}

void drawMenu(int rect1, int rect2, int rect3, int height, int width) {
    unsigned char alpha ;
    double gradient = 255 ;
    ALLEGRO_COLOR jauneLogo = al_map_rgb(255, 204, 51) ;
    ALLEGRO_COLOR marronLogo = al_map_rgb(102, 51, 0) ;
    ALLEGRO_FONT *gameFont = al_load_ttf_font("../MagicCardsNormal.ttf", 70, ALLEGRO_ALIGN_LEFT);
    ALLEGRO_FONT *gameFont1 = al_load_ttf_font("../MagicCardsNormal.ttf", 90, ALLEGRO_ALIGN_LEFT);
    for (int i = 0; i < 40; i++) {
        alpha = (unsigned char) gradient;
        if (!rect1) {
            al_draw_line(0, height / 2 - 40 + 2 * i, 300, height / 2 - 40 + 2 * i,
                         al_map_rgba(155, 204, 51, alpha), 2);
            al_draw_line(300, height / 2 - 40 + 2 * i, 300 + i, height / 2 - 40 + 2 * i,
                         al_map_rgba(155, 204, 51, alpha), 2);
            al_draw_line(0, 500, 300, 500, marronLogo, 6);
            al_draw_line(0, 580, 340, 580, marronLogo, 6);
            al_draw_line(0, 500, 0, 580, marronLogo, 6);
            al_draw_line(300, 500, 340, 580, marronLogo, 6);
        } else {
            al_draw_line(0, height / 2 - 60 + 3 * i, 320, height / 2 - 60 + 3 * i,
                         al_map_rgba(155, 204, 51, alpha), 3);
            al_draw_line(320, height / 2 - 60 + 3 * i, 320 + i * 1.5, height / 2 - 60 + 3 * i,
                         al_map_rgba(155, 204, 51, alpha), 3);
            al_draw_line(0, height / 2 - 60, 320, height / 2 - 60 , marronLogo, 6);
            al_draw_line(0, height / 2 + 60, 320, height / 2 + 60, marronLogo, 6);
            al_draw_line(0, height / 2 - 60, 0, height / 2 + 60, marronLogo, 6);
            al_draw_line(317, height / 2 - 60, 377, height / 2 + 60, marronLogo, 6);
            al_draw_line(320, height / 2 + 60, 380, height / 2 + 60, marronLogo, 6);
        }
        if (!rect2) {
            al_draw_line(0, height / 2 + 80 + 2 * i, 300, height / 2 + 80 + 2 * i,
                         al_map_rgba(155, 204, 51, alpha), 2);
            al_draw_line(300, height / 2 + 80 + 2 * i, 300 + i, height / 2 + 80 + 2 * i,
                         al_map_rgba(155, 204, 51, alpha), 2);
        } else {
            al_draw_line(0, height / 2 + 60 + 3 * i, 320, height / 2 + 60 + 3 * i,
                         al_map_rgba(155, 204, 51, alpha), 3);
            al_draw_line(320, height / 2 + 60 + 3 * i, 320 + i * 1.5, height / 2 + 60 + 3 * i,
                         al_map_rgba(155, 204, 51, alpha), 3);
            al_draw_line(0, 600, 320, 600, marronLogo, 6);
            al_draw_line(0, 720, 320, 720, marronLogo, 6);
            al_draw_line(0, 600, 0, 720, marronLogo, 6);
            al_draw_line(317, 600, 377, 720, marronLogo, 6);
            al_draw_line(320, 720, 380, 720, marronLogo, 6);
        }
        if (!rect3) {
            al_draw_line(0, height / 2 + 200 + 2 * i, 300, height / 2 + 200 + 2 * i,
                         al_map_rgba(155, 204, 51, alpha), 2);
            al_draw_line(300, height / 2 + 200 + 2 * i, 300 + i, height / 2 + 200 + 2 * i,
                         al_map_rgba(155, 204, 51, alpha), 2);
        } else {
            al_draw_line(0, height / 2 + 180 + 3 * i, 320, height / 2 + 180 + 3 * i,
                         al_map_rgba(155, 204, 51, alpha), 3);
            al_draw_line(320, height / 2 + 180 + 3 * i, 320 + i * 1.5, height / 2 + 180 + 3 * i,
                         al_map_rgba(155, 204, 51, alpha), 3);
            al_draw_line(0, 720, 320, 720, marronLogo, 6);
            al_draw_line(0, 840, 320, 840, marronLogo, 6);
            al_draw_line(0, 720, 0, 840, marronLogo, 6);
            al_draw_line(317, 720, 377, 840, marronLogo, 6);
            al_draw_line(320, 840, 380, 840, marronLogo, 6);
        }
        gradient -=33.5;
    }
    if (!rect1) {
        al_draw_textf(gameFont, marronLogo, 68, 512, ALLEGRO_ALIGN_LEFT, "PLAY");
    } else al_draw_textf(gameFont1, marronLogo, 60, 505, ALLEGRO_ALIGN_LEFT, "PLAY");
    if (!rect2) {
        al_draw_textf(gameFont, marronLogo, 50, 630, ALLEGRO_ALIGN_LEFT, "RULES");
    } else al_draw_textf(gameFont1, marronLogo, 34, 622, ALLEGRO_ALIGN_LEFT, "RULES");
    if (!rect3) {
        al_draw_textf(gameFont, marronLogo, 50, 754, ALLEGRO_ALIGN_LEFT, "TEAM");
    } else al_draw_textf(gameFont1, marronLogo, 45, 745, ALLEGRO_ALIGN_LEFT, "TEAM");
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

    al_set_new_display_flags(ALLEGRO_FULLSCREEN_WINDOW) ;

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

    display = al_create_display(800, 600);
    int height = al_get_display_height(display) ;
    int width = al_get_display_width(display) ;


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
                                if (mouse_x < 300 && mouse_x > 0 && mouse_y < 580 && mouse_y > 500) {
                                    gameModes = PLAY;
                                } else if (mouse_x < 300 && mouse_x > 0 && mouse_y < 700 && mouse_y > 620) {
                                    gameModes = RULES;
                                } else if (mouse_x < 300 && mouse_x > 0 && mouse_y < 820 && mouse_y > 740) {
                                    gameModes = TEAM;
                                }
                                break ;
                            }
                            case TEAM : {
                                if (event.mouse.x < 300 && event.mouse.x > 5 && event.mouse.y < 80 && event.mouse.y > 5) {
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
                                if (event.mouse.x < 300 && event.mouse.x > 5 && event.mouse.y < 80 && event.mouse.y > 5) {
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
                    if (mouse_x < 300 && mouse_x > 0 && mouse_y < height / 2 + 40 && mouse_y > height / 2 - 40) {
                        rect1 = 1;
                    } else rect1 = 0;
                    if (mouse_x < 300 && mouse_x > 0 && mouse_y < height / 2 + 160 && mouse_y > height / 2 + 80) {
                        rect2 = 1;
                    } else rect2 = 0;
                    if (mouse_x < 300 && mouse_x > 0 && mouse_y < height / 2 + 280 && mouse_y > height / 2 + 200) {
                        rect3 = 1;
                    } else rect3 = 0;
                    draw = 1;
                }
            }
            if (draw) {
                printf("%d   %d\n", height, width) ;
                switch (gameModes) {
                    case MENU : {
                        al_draw_bitmap(background, 0, 0, 0);
                        drawMenu(rect1, rect2, rect3, height, width) ;
                        break ;
                    }
                    case TEAM : {
                        drawTeam(height, width) ;
                        if (mouse_x < 300 && mouse_x > 5 && mouse_y < 80 && mouse_y > 5) {
                            al_draw_rectangle(5, 5, 300, 80, al_map_rgb(155, 204, 107), 4) ;
                        }
                        break ;
                    }
                    case RULES : {
                        drawRules(&page, height, width) ;
                        if (mouse_x < 300 && mouse_x > 5 && mouse_y < 80 && mouse_y > 5) {
                            al_draw_rectangle(5, 5, 300, 80, al_map_rgb(155, 204, 107), 4) ;
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