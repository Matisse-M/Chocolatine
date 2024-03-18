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
#include "my.h"

static void fill_layer_two(layer_t *lay, int *i)
{
        sfRectangleShape_setOutlineColor(lay->hover[*i], (sfBlack));
        sfRectangleShape_setOutlineThickness(lay->hover[*i], 1);
        sfRectangleShape_setSize(lay->mask[*i], (sfVector2f) {24, 24});
        sfRectangleShape_setPosition(lay->mask[*i], (sfVector2f)
        {1760, 605 - ((*i) * 60)});
        sfRectangleShape_setFillColor(lay->mask[*i], sfYellow);
        sfRectangleShape_setOutlineColor(lay->mask[*i], sfBlack);
        sfRectangleShape_setOutlineThickness(lay->mask[*i], 1);
}

layer_t *fill_layers(void)
{
    layer_t *lay = malloc(sizeof(layer_t));

    lay->hover = malloc(sizeof(sfRectangleShape *) * 5);
    lay->mask = malloc(sizeof(sfRectangleShape *) * 5);
    lay->visible = malloc(sizeof(bool) * 5);
    for (int i = 0; i < 5; i++) {
        lay->hover[i] = sfRectangleShape_create();
        lay->mask[i] = sfRectangleShape_create();
        lay->visible[i] = true;
        sfRectangleShape_setFillColor(lay->hover[i], sfTransparent);
        sfRectangleShape_setSize(lay->hover[i], (sfVector2f) {128, 54});
        sfRectangleShape_setPosition(lay->hover[i], (sfVector2f)
        {1742, 591 - (i * 60)});
        fill_layer_two(lay, &i);
    }
    return lay;
}

static void find_if_layer_pressed(paint_t *paint, sfClock **clock, int *i,
    int f)
{
        if (sfMouse_isButtonPressed(sfMouseLeft) && paint->layers->visible[*i]
            == true && f > 0.2) {
            sfRectangleShape_setFillColor(paint->layers->mask[*i], sfWhite);
            paint->layers->visible[*i] = false;
            sfClock_restart(*clock);
        } else if (sfMouse_isButtonPressed(sfMouseLeft) &&
            paint->layers->visible[*i] == false && f > 0.2) {
            sfRectangleShape_setFillColor(paint->layers->mask[*i], sfYellow);
            paint->layers->visible[*i] = true;
            sfClock_restart(*clock);
        }
}

static void draw_layers_one(paint_t *paint, sfClock **clock, int *i, float f)
{
    if (my_hover_effect(paint->win, paint->layers->hover[*i]) == 1 && *i !=
        paint->layer && my_hover_effect(paint->win,
        paint->layers->mask[*i]) == 0) {
        if (sfMouse_isButtonPressed(sfMouseLeft) && f > 0.2) {
            paint->layer = *i;
            sfClock_restart(*clock);
        }
        sfRectangleShape_setFillColor(paint->layers->hover[*i], (sfColor)
            {175, 175, 175, 255});
    } else {
        sfRectangleShape_setFillColor(paint->layers->hover[*i], sfTransparent);
    }
    if (*i != paint->layer && my_hover_effect(paint->win,
        paint->layers->mask[*i]) == 1) {
        find_if_layer_pressed(paint, clock, i, f);
    }
}

void draw_layers(paint_t *paint, sfClock **clock)
{
    sfTime elapsed = sfClock_getElapsedTime(*clock);
    float f = sfTime_asSeconds(elapsed);

    for (int i = 0; i < 5; i++) {
        draw_layers_one(paint, clock, &i, f);
    }
    sfRectangleShape_setFillColor(paint->layers->hover[paint->layer],
        (sfColor) {150, 150, 150, 255});
}
