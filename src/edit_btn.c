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

static void pencil_button(paint_t *paint, sfClock **clock, float f)
{
    if (my_hover_effect(paint->win, paint->edit->hitbox[0]) == 1 &&
        sfMouse_isButtonPressed(sfMouseLeft) && f > 0.2) {
        paint->scene->pencil = true;
        paint->scene->rubber = false;
        paint->scene->shapes = false;
        paint->scene->import = false;
        paint->scene->menu[1] = false;
        sfClock_restart(*clock);
    }
}

static void rubber_button(paint_t *paint, sfClock **clock, float f)
{
    if (my_hover_effect(paint->win, paint->edit->hitbox[1]) == 1 &&
        sfMouse_isButtonPressed(sfMouseLeft) && f > 0.2) {
        paint->scene->pencil = false;
        paint->scene->rubber = true;
        paint->scene->shapes = false;
        paint->scene->import = false;
        paint->scene->menu[1] = false;
        sfClock_restart(*clock);
    }
}

static void shapes_button(paint_t *paint, sfClock **clock, float f)
{
    if (my_hover_effect(paint->win, paint->edit->hitbox[2]) == 1 &&
        sfMouse_isButtonPressed(sfMouseLeft) && f > 0.2) {
        paint->scene->pencil = false;
        paint->scene->rubber = false;
        paint->scene->shapes = true;
        paint->scene->import = false;
        paint->scene->menu[1] = false;
        sfClock_restart(*clock);
    }
}

static void import_button(paint_t *paint, sfClock **clock, float f)
{
    if (my_hover_effect(paint->win, paint->edit->hitbox[3]) == 1 &&
        sfMouse_isButtonPressed(sfMouseLeft) && f > 0.2) {
        paint->scene->pencil = false;
        paint->scene->rubber = false;
        paint->scene->shapes = false;
        paint->scene->import = true;
        paint->scene->menu[1] = false;
        sfClock_restart(*clock);
    }
}

void my_edit_buttons(paint_t *paint, sfClock **clock, float f)
{
    pencil_button(paint, clock, f);
    rubber_button(paint, clock, f);
    shapes_button(paint, clock, f);
    import_button(paint, clock, f);
}
