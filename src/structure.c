/*
** EPITECH PROJECT, 2023
** main
** File description:
** main()
*/

#include <stdarg.h>
#include <stdlib.h>
#include <stdbool.h>
#include "paint.h"
#include "csfml.h"

static scroller_t *fill_scroller(void)
{
    scroller_t *scroll = malloc(sizeof(scroller_t));
    sfColor color = {225, 225, 225, 255};
    sfFont *font = sfFont_createFromFile("assets/font.ttf");

    scroll->bar = my_set_rectangle((sfVector2f) {300, 20},
        (sfVector2f) {1000, 60});
    my_custom_rectangle(scroll->bar, 1, sfWhite, sfBlack);
    scroll->btn = my_set_circle(15, (sfVector2f) {1010, 55}, color);
    sfCircleShape_setOutlineColor(scroll->btn, sfBlack);
    sfCircleShape_setOutlineThickness(scroll->btn, 1);
    scroll->area = my_set_rectangle((sfVector2f) {30, 30},
        (sfVector2f) {1010, 65});
    my_custom_rectangle(scroll->area, 2, sfTransparent, sfTransparent);
    scroll->text = sfText_create();
    sfText_setPosition(scroll->text, (sfVector2f) {1000, 85});
    sfText_setCharacterSize(scroll->text, 32);
    sfText_setFillColor(scroll->text, sfBlack);
    sfText_setFont(scroll->text, font);
    return scroll;
}

static scroller_t *fill_scroller2(void)
{
    scroller_t *scroll = malloc(sizeof(scroller_t));
    sfColor color = {225, 225, 225, 255};
    sfFont *font = sfFont_createFromFile("assets/font.ttf");

    scroll->bar = my_set_rectangle((sfVector2f) {600, 20},
        (sfVector2f) {700, 60});
    my_custom_rectangle(scroll->bar, 1, sfWhite, sfBlack);
    scroll->btn = my_set_circle(15, (sfVector2f) {710, 55}, color);
    sfCircleShape_setOutlineColor(scroll->btn, sfBlack);
    sfCircleShape_setOutlineThickness(scroll->btn, 1);
    scroll->area = my_set_rectangle((sfVector2f) {30, 30},
        (sfVector2f) {710, 65});
    my_custom_rectangle(scroll->area, 2, sfTransparent, sfTransparent);
    scroll->text = sfText_create();
    sfText_setPosition(scroll->text, (sfVector2f) {700, 85});
    sfText_setCharacterSize(scroll->text, 32);
    sfText_setFillColor(scroll->text, sfBlack);
    sfText_setFont(scroll->text, font);
    return scroll;
}

static sfRectangleShape **fill_shapes_background(void)
{
    sfRectangleShape **shape = malloc(sizeof(sfRectangleShape *) * 3);
    sfColor first = {200, 200, 200, 255};
    sfColor second = {225, 225, 225, 255};

    shape[0] = my_set_rectangle((sfVector2f) {1920, 1080},
        (sfVector2f) {0, 0});
    my_custom_rectangle(shape[0], 0, first, sfTransparent);
    shape[1] = my_set_rectangle((sfVector2f) {1920, 120},
        (sfVector2f) {0, 31});
    my_custom_rectangle(shape[1], 0, second, sfTransparent);
    shape[2] = my_set_rectangle((sfVector2f) {1920, 30}, (sfVector2f) {0, 0});
    my_custom_rectangle(shape[2], 1, second, first);
    return shape;
}

static sfRectangleShape **fill_basic_colors(void)
{
    sfRectangleShape **shape = malloc(sizeof(sfRectangleShape *) * 8);
    sfColor color[8] = {sfBlack, sfWhite, sfBlue, sfRed, sfYellow, sfGreen,
        sfCyan, sfMagenta};

    for (int i = 0; i < 8; i++) {
        shape[i] = my_set_rectangle((sfVector2f) {20, 20},
        (sfVector2f) {550 + (25 * i), 40});
        my_custom_rectangle(shape[i], 1, color[i], sfBlack);
    }
    return shape;
}

static sfRectangleShape **fill_history_colors(void)
{
    sfRectangleShape **shape = malloc(sizeof(sfRectangleShape *) * 24);
    int x = 0;
    int y = 0;

    for (int i = 0; i < 24; i++) {
        if (i % 8 == 0 && i != 0) {
            x = 0;
            y += 25;
        }
        shape[i] = my_set_rectangle((sfVector2f) {20, 20},
        (sfVector2f) {550 + (25 * x), 70 + y});
        my_custom_rectangle(shape[i], 1, sfWhite, sfBlack);
        x++;
    }
    return shape;
}

static div_color_t *set_div_color(div_color_t *colo)
{
    sfSprite_setTexture(colo->sprite_pip, colo->texture_pip, sfTrue);
    sfSprite_setScale(colo->sprite_pip, (sfVector2f) {0.1, 0.1});
    sfSprite_setPosition(colo->sprite_pip, (sfVector2f) {780, 65});
    sfRectangleShape_setSize(colo->area_pip, (sfVector2f) {50, 50});
    sfRectangleShape_setPosition(colo->area_pip, (sfVector2f) {780, 65});
    sfRectangleShape_setSize(colo->area_rub, (sfVector2f) {50, 50});
    sfRectangleShape_setPosition(colo->area_rub, (sfVector2f) {850, 65});
    return colo;
}

static div_color_t *fill_div_color(void)
{
    div_color_t *colo = malloc(sizeof(div_color_t));

    colo->texture_pip = sfTexture_createFromFile("assets/pipette.png", NULL);
    colo->sprite_pip = sfSprite_create();
    colo->basic_colors = fill_basic_colors();
    colo->history_colors = fill_history_colors();
    colo->area_pip = sfRectangleShape_create();
    colo->area_rub = sfRectangleShape_create();
    set_div_color(colo);
    return colo;
}

sfCircleShape *set_my_cursor(void)
{
    sfCircleShape *cursor = sfCircleShape_create();

    sfCircleShape_setOutlineThickness(cursor, 1);
    sfCircleShape_setFillColor(cursor, sfTransparent);
    sfCircleShape_setOutlineColor(cursor, sfBlack);
    return cursor;
}

static void my_shape_btn(paint_t *paint)
{
    sfTexture *shp = sfTexture_createFromFile("assets/shape.png", NULL);

    paint->shape = sfSprite_create();
    paint->area_shape = sfRectangleShape_create();
    sfSprite_setTexture(paint->shape, shp, sfTrue);
    sfSprite_setScale(paint->shape, (sfVector2f) {0.1, 0.1});
    sfSprite_setPosition(paint->shape, (sfVector2f) {890, 65});
    sfRectangleShape_setFillColor(paint->area_shape, sfTransparent);
    sfRectangleShape_setSize(paint->area_shape, (sfVector2f) {50, 50});
    sfRectangleShape_setPosition(paint->area_shape, (sfVector2f) {890, 65});
}

void color_and_toolbar(paint_t *paint, char *user)
{
    paint->name = "undefined.jpg";
    paint->layer = 0;
    paint->nb_color = 0;
    paint->colo = fill_div_color();
    paint->pen = fill_pen();
    set_toolbar(paint, user);
    paint->about = fill_about(paint->login);
    paint->gray = fill_shapes_background();
    paint->page = my_set_rectangle((sfVector2f) {1280, 720},
        (sfVector2f) {320, 220});
    my_custom_rectangle(paint->page, 0, sfWhite, sfTransparent);
    paint->size_pen = fill_scroller();
    paint->size_rub = fill_scroller2();
    paint->wanna_save = fill_menu_save();
    paint->shader = fill_shader();
    paint->layers = fill_layers();
    my_shape_btn(paint);
    paint->select = fill_select();
    paint->scene->shapes = false;
}
