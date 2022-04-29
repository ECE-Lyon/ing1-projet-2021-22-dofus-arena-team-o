#include "jeu.h"

void drawRules(int* pages, float height, float width) {
    int police = 2*width/55 ;
    ALLEGRO_COLOR jauneLogo = al_map_rgb(255, 204, 51) ;
    ALLEGRO_COLOR marronLogo = al_map_rgb(102, 51, 0) ;
    ALLEGRO_FONT* gameFont = al_load_ttf_font("../MagicCardsNormal.ttf", police, ALLEGRO_ALIGN_LEFT) ;
    if(*pages < RULESPAGEMAX) {
        al_draw_circle(13*width/15, 11*height/13, width/38.4, jauneLogo, 4) ;
        al_draw_line(13*width/15 - width/64 , 11*height/13, 13*width/15 + width/64, 11*height/13, jauneLogo, 3);
        al_draw_line(13*width/15 + width/64, 11*height/13, 13*width/15 + width/192, 11*height/13 - height/43.2 , jauneLogo, 3);
        al_draw_line(13*width/15 + width/64, 11*height/13, 13*width/15 + width/192, 11*height/13 + height/43.2 , jauneLogo, 3);
    }
    if(*pages > 1) {
        al_draw_circle(2*width/15, 11*height/13, width/38.4, jauneLogo, 4) ;
        al_draw_line(2*width/15 - width/64, 11*height/13, 2*width/15 + width/64, 11*height/13, jauneLogo, 3) ;
        al_draw_line(2*width/15 - width/64, 11*height/13, 2*width/15 - width/192 , 11*height/13 - height/43.2, jauneLogo, 3) ;
        al_draw_line(2*width/15 - width/64, 11*height/13, 2*width/15 - width/192 , 11*height/13 + height/43.2, jauneLogo, 3) ;
    }
    al_draw_text(gameFont, al_map_rgb(255, 0, 0), (5*width/32 - width/384)/2 + police/10, (2*height/27-height/216)/2 - police/3, ALLEGRO_ALIGN_CENTER, "RETURN") ;
    al_draw_rectangle(width/384, height/216, 5*width/32, 2*height/27, al_map_rgb(255, 0, 0), 3) ;
    al_draw_textf(gameFont, jauneLogo, 7.5*width/15, 11*height/13 + height/18, ALLEGRO_ALIGN_CENTER, "%d / %d", *pages, RULESPAGEMAX) ;
    al_destroy_font(gameFont) ;
}


void drawTeam(float height, float width) {
    float police = 2*width/55 ;
    ALLEGRO_BITMAP* moi = al_load_bitmap("../InfoPhotoM150.PNG") ;
    ALLEGRO_BITMAP* toi = al_load_bitmap("../InfoPhotoW150.PNG") ;
    ALLEGRO_FONT *gameFont = al_load_ttf_font("../MagicCardsNormal.ttf", police, ALLEGRO_ALIGN_LEFT);
    al_draw_filled_circle(width/4, height/4, width*150/1920, al_map_rgb(255, 255, 255)) ;
    al_draw_circle(width/4, height/4, width*150/1920, al_map_rgb(255, 0, 0), 5) ;
    al_draw_scaled_bitmap(moi, 0, 0, 150, 149,width/4 - 5*width/128, height/4 - 5*height/72, width*150/1920, height*149/1080, 0) ;
    al_draw_text(gameFont, al_map_rgb(255, 0, 0), width/4 , height/4 + height/9, ALLEGRO_ALIGN_CENTER, "Nel") ;

    al_draw_filled_circle(3*width/4 , height/4, width*150/1920, al_map_rgb(255, 255, 255)) ;
    al_draw_circle(3 * width / 4, height / 4, width*150/1920, al_map_rgb(255, 0, 0), 5) ;
    al_draw_scaled_bitmap(toi, 0, 0, 150, 149, 3*width/4 - 5*width/128, height/4 - 5*height/72, width*150/1920, height*149/1080, ALLEGRO_FLIP_HORIZONTAL) ;
    al_draw_text(gameFont, al_map_rgb(255, 0, 0), 3*width/4 , height/4 + height/9, ALLEGRO_ALIGN_CENTER, "Zelie") ;

    al_draw_filled_circle(width/4, 3*height/4, width*150/1920, al_map_rgb(255, 255, 255)) ;
    al_draw_circle(width/4, 3*height/4, width*150/1920, al_map_rgb(255, 0, 0), 5) ;
    al_draw_scaled_bitmap(moi, 0, 0, 150, 149, width/4 - 5*width/128, 3*height/4 - 5*height/72, width*150/1920, height*149/1080, ALLEGRO_FLIP_HORIZONTAL) ;
    al_draw_text(gameFont, al_map_rgb(255, 0, 0), width / 4 , 3*height/4 + height/9, ALLEGRO_ALIGN_CENTER, "Fares") ;

    al_draw_filled_circle(3*width/4, 3*height/4, width*150/1920, al_map_rgb(255, 255, 255)) ;
    al_draw_circle(3*width/4, 3*height/4, width*150/1920, al_map_rgb(255, 0, 0), 5) ;
    al_draw_scaled_bitmap(toi, 0, 0, 150, 149, 3*width/4 - 5*width/128, 3*height/4 - 5*height/72, width*150/1920, height*149/1080, 0) ;
    al_draw_text(gameFont, al_map_rgb(255, 0, 0), 3*width/4 , 3*height/4 + height/9, ALLEGRO_ALIGN_CENTER, "Ilayda") ;

    al_draw_text(gameFont, al_map_rgb(255, 0, 0), (5*width/32 - width/384)/2 + police/10, (2*height/27-height/216)/2 - police/3, ALLEGRO_ALIGN_CENTER, "RETURN") ;
    al_draw_rectangle(width/384, height/216, 5*width/32, 2*height/27, al_map_rgb(255, 0, 0), 3) ;
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