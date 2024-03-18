/*
** EPITECH PROJECT, 2023
** paint
** File description:
** Header
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <stdbool.h>
#include "csfml.h"

#pragma once

typedef struct scene_s {
    bool pencil;
    bool rubber;
    bool shader;
    bool *menu;
    bool exit;
    bool rename;
    bool open;
    bool help;
    bool about;
    bool import;
    bool shapes;
    bool which_s;
} scene_t;

typedef struct header_s {
    sfText **text;
    sfRectangleShape **hitbox;
} header_t;

typedef struct pen_s {
    unsigned int size;
    unsigned int shape;
    sfColor color;
} pen_t;

typedef struct menu_s {
    sfText **text;
    sfRectangleShape **hitbox;
} menu_t;

typedef struct div_color_s {
    sfSprite *sprite_pip;
    sfTexture *texture_pip;
    sfRectangleShape *area_pip;
    sfRectangleShape *area_rub;
    sfRectangleShape **basic_colors;
    sfRectangleShape **history_colors;
} div_color_t;

typedef struct scroller_s {
    sfRectangleShape *bar;
    sfRectangleShape *area;
    sfCircleShape *btn;
    sfText *text;
} scroller_t;

typedef struct div_shaders_s {
    sfRectangleShape *bckgrnd;
    sfText **text;
    sfRectangleShape **bars;
    sfRectangleShape **col;
    sfCircleShape **ball;
    sfRectangleShape **hitbox;
    sfRectangleShape *display;
    sfColor color;
    sfText *validate;
    sfRectangleShape *okay;
} div_shaders_t;

typedef struct menu_save_s {
    sfRectangleShape *shade;
    sfRectangleShape *popup;
    sfRectangleShape **btn;
    sfText **text;
} menu_save_t;

typedef struct open_s {
    int page;
    int nb_file;
    sfRectangleShape *shade;
    sfRectangleShape *bckgrnd;
    sfRectangleShape **btn;
    sfText **files;
    sfText *select;
    sfText *warning;
    sfRectangleShape **arrow;
} open_t;

typedef struct rename_s {
    bool write;
    bool extension;
    int nb;
    char *filename;
    sfRectangleShape *shade;
    sfRectangleShape *bar;
    sfRectangleShape *ext;
    sfRectangleShape *bckgrnd;
    sfText *name;
    sfText *end;
    sfText *message;
    sfText *alert;
    sfText *null;
    sfText *render;
    sfRectangleShape **btn_ext;
    sfText **list_ext;
} rename_t;

typedef struct help_s {
    sfRectangleShape *shade;
    sfRectangleShape *bckgrnd;
    sfText *text;
} help_t;

typedef struct about_s {
    sfRectangleShape *shade;
    sfRectangleShape *bckgrnd;
    sfText *text;
    sfText *user;
} about_t;

typedef struct layers_s {
    bool *visible;
    sfRectangleShape **hover;
    sfRectangleShape **mask;
} layer_t;

typedef struct select_s {
    sfRectangleShape **btn;
    sfText **text;
} select_t;

typedef struct paint_s {
    char *name;
    char *login;
    int nb_color;
    int layer;
    bool saved;
    scene_t *scene;
    pen_t *pen;
    div_color_t *colo;
    framebuffer_t *buf;
    header_t *header;
    menu_t *file;
    menu_t *edit;
    menu_t *help;
    sfTexture **texture_buf;
    sfSprite **sprite_buf;
    sfRenderTexture *texture;
    sfRectangleShape **gray;
    sfRectangleShape *page;
    sfRenderWindow *win;
    sfImage **image;
    scroller_t *size_pen;
    scroller_t *size_rub;
    menu_save_t *wanna_save;
    div_shaders_t *shader;
    rename_t *rename;
    open_t *open;
    help_t *h;
    about_t *about;
    layer_t *layers;
    sfSprite *shape;
    sfRectangleShape *area_shape;
    select_t *select;
} paint_t;



paint_t *fill_structure(char *user);
void set_toolbar(paint_t *paint, char *user);
void hover_header(sfRenderWindow *win, paint_t *paint, sfClock **clock);
void check_toolbar_scenes(sfRenderWindow *win, paint_t *paint,
    sfClock **clock);
void save_that_file(paint_t *paint);
void my_file_buttons(paint_t *paint, sfClock **clock, float f);
void my_edit_buttons(paint_t *paint, sfClock **clock, float f);
sfCircleShape *set_my_cursor(void);
void my_paint(sfEvent event, char *user);
void restart_image_jpg(paint_t *paint);
void restart_image_png(paint_t *paint);
menu_save_t *fill_menu_save(void);
void draw_exit_menu(void (*ptr)(paint_t *paint), paint_t *paint);
div_shaders_t *fill_shader(void);
void draw_shader(paint_t *paint, sfClock **clock);
void draw_name(paint_t *paint);
pen_t *fill_pen(void);
rename_t *fill_rename(void);
void draw_rename(paint_t *paint, sfClock **clock);
void my_put_alphabet(paint_t *paint, sfClock **clock, float f);
void enter_character(paint_t *paint, sfClock **clock, float f);
void my_alpha(paint_t *paint, sfClock **clock, float f);
void my_num(paint_t *paint, sfClock **clock, float f);
void my_alpha_maj(paint_t *paint, sfClock **clock, float f);
void update_filename(paint_t *paint, sfClock **clock, char c);
void put_my_mouse(sfCircleShape **cursor, sfRenderWindow *win);
void draw_open(paint_t *paint, sfClock **clock);
open_t *fill_open(void);
void restart_image_open(paint_t *paint, char *filename);
void switch_pencil_colors(sfRenderWindow *win, paint_t *paint);
void update_my_framebuffer(sfRenderWindow *win, paint_t *paint);
help_t *fill_help(void);
void display_helper(paint_t *paint, sfClock **clock);
void my_help_buttons(paint_t *paint, sfClock **clock, float f);
void destroy_program(paint_t *paint, sfClock **clock);
about_t *fill_about(char *user);
void display_about(paint_t *paint, sfClock **clock);
layer_t *fill_layers(void);
void draw_layers(paint_t *paint, sfClock **clock);
void check_scenes(paint_t *paint, sfClock **clock);
void draw_rubber_menu(sfRenderWindow *win, paint_t *paint);
void find_extension(paint_t *paint);
void draw_pencil_menu(sfRenderWindow *win, paint_t *paint);
void draw_slidebar(paint_t *paint);
void hover_display(sfRenderWindow *win, paint_t *paint, sfClock **clock);
void duck_condition(sfRectangleShape *rect, paint_t *paint);
void color_and_toolbar(paint_t *paint, char *user);
void select_import_file(paint_t *paint, sfClock **clock, float f, char *file);
void hover_shapes(sfRenderWindow *win, paint_t *paint, sfClock **clock);
select_t *fill_select(void);
void draw_shapes(paint_t *paint, sfClock **clock);
void put_shape(paint_t *paint, sfClock **clock);
int write_on_page(sfRenderWindow *window, sfRectangleShape *rect, int size);
void draw_circle_on_image(sfVector2i position, paint_t *paint);
void draw_square_on_image(sfVector2i position, paint_t *paint);
char **get_files(paint_t *paint);
void draw_triangle_on_image(sfVector2i position, paint_t *paint);
