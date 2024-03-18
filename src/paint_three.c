/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-mypaint-albane.merian
** File description:
** paint_three
*/

#include <stdarg.h>
#include <stdlib.h>
#include <stdbool.h>
#include "paint.h"
#include "csfml.h"
#include "my.h"

void select_import_file(paint_t *paint, sfClock **clock, float f, char *file)
{
    sfTexture *texture;
    sfVector2u size[2];

    if (sfMouse_isButtonPressed(sfMouseLeft) && f > 0.2 &&
        paint->scene->import == true) {
        texture = sfTexture_createFromFile(my_cat("gallery/", file), NULL);
        paint->image[paint->layer] = sfTexture_copyToImage(texture);
        size[0] = sfImage_getSize(paint->image[0]);
        size[1] = sfImage_getSize(paint->image[paint->layer]);
        sfSprite_setTexture(paint->sprite_buf[paint->layer], texture, sfTrue);
        paint->scene->import = false;
        sfRenderWindow_drawSprite(paint->win,
            paint->sprite_buf[paint->layer], NULL);
        sfRenderTexture_drawSprite(paint->texture,
            paint->sprite_buf[paint->layer], NULL);
        sfClock_restart(*clock);
    }
}

static void hover_disp_two(paint_t *paint, sfClock **clock, float f)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) &&
        paint->scene->rubber == false && paint->scene->shader == false
        && f > 0.2) {
        paint->scene->shader = true;
        sfClock_restart(*clock);
    } else if (sfMouse_isButtonPressed(sfMouseLeft) &&
        paint->scene->rubber == false && paint->scene->shader == true
        && f > 0.2) {
        paint->scene->shader = false;
        sfClock_restart(*clock);
    }
}

void hover_display(sfRenderWindow *win, paint_t *paint, sfClock **clock)
{
    sfColor grey = {150, 150, 150, 150};
    sfColor duck = {89, 159, 131, 255};
    sfTime elapsed = sfClock_getElapsedTime(*clock);
    float f = sfTime_asSeconds(elapsed);

    if (my_hover_effect(win, paint->colo->area_pip) == 1) {
        hover_disp_two(paint, clock, f);
        sfRectangleShape_setFillColor(paint->colo->area_pip, grey);
        sfRectangleShape_setOutlineThickness(paint->colo->area_pip, 1);
        sfRectangleShape_setOutlineColor(paint->colo->area_pip, duck);
    } else {
        sfRectangleShape_setFillColor(paint->colo->area_pip, sfTransparent);
        sfRectangleShape_setOutlineThickness(paint->colo->area_pip, 0);
    }
}

static void hover_two(paint_t *paint, sfClock **clock, int f)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) &&
        paint->scene->rubber == false && paint->scene->which_s == false
        && f > 0.2) {
        paint->scene->which_s = true;
        sfClock_restart(*clock);
    } else if (sfMouse_isButtonPressed(sfMouseLeft) &&
        paint->scene->rubber == false && paint->scene->which_s == true
        && f > 0.2) {
        paint->scene->which_s = false;
        sfClock_restart(*clock);
    }
}

void hover_shapes(sfRenderWindow *win, paint_t *paint, sfClock **clock)
{
    sfColor grey = {150, 150, 150, 150};
    sfColor duck = {89, 159, 131, 255};
    sfTime elapsed = sfClock_getElapsedTime(*clock);
    float f = sfTime_asSeconds(elapsed);

    if (my_hover_effect(win, paint->area_shape) == 1 &&
        paint->scene->shapes == true) {
        hover_two(paint, clock, f);
        sfRectangleShape_setFillColor(paint->area_shape, grey);
        sfRectangleShape_setOutlineThickness(paint->area_shape, 1);
        sfRectangleShape_setOutlineColor(paint->area_shape, duck);
    } else {
        sfRectangleShape_setFillColor(paint->area_shape, sfTransparent);
        sfRectangleShape_setOutlineThickness(paint->area_shape, 0);
    }
}

void draw_slidebar(paint_t *paint)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(paint->win);
    sfVector2f ha;

    if (my_hover_effect(paint->win, paint->size_pen->area) == 1 &&
        sfMouse_isButtonPressed(sfMouseLeft)
        && pos.x >= 1000 && pos.x <= 1300) {
        sfCircleShape_setPosition(paint->size_pen->btn,
            (sfVector2f) {pos.x - 15, 55});
        sfRectangleShape_setPosition(paint->size_pen->area,
            (sfVector2f) {pos.x - 15, 55});
    }
    ha = sfCircleShape_getPosition(paint->size_pen->btn);
    paint->pen->size = 3 + ((ha.x - 984) / 2000) * (2000 - 984);
}

void duck_condition(sfRectangleShape *rect, paint_t *paint)
{
    sfColor duck = {89, 159, 131, 255};

    if (sfRectangleShape_getFillColor(rect).a == paint->pen->color.a &&
        sfRectangleShape_getFillColor(rect).r == paint->pen->color.r &&
        sfRectangleShape_getFillColor(rect).g == paint->pen->color.g &&
        sfRectangleShape_getFillColor(rect).b == paint->pen->color.b)
        sfRectangleShape_setOutlineColor(rect, duck);
    else
        sfRectangleShape_setOutlineColor(rect, sfBlack);
}
