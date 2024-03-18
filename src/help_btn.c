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

static void bout_button(paint_t *paint, sfClock **clock, float f)
{
    if (my_hover_effect(paint->win, paint->help->hitbox[0]) == 1 &&
        sfMouse_isButtonPressed(sfMouseLeft) && f > 0.2) {
        paint->scene->about = true;
        paint->scene->menu[2] = false;
        sfClock_restart(*clock);
    }
}

static void help_button(paint_t *paint, sfClock **clock, float f)
{
    if (my_hover_effect(paint->win, paint->help->hitbox[1]) == 1 &&
        sfMouse_isButtonPressed(sfMouseLeft) && f > 0.2) {
        paint->scene->help = true;
        paint->scene->menu[2] = false;
        sfClock_restart(*clock);
    }
}

void my_help_buttons(paint_t *paint, sfClock **clock, float f)
{
    bout_button(paint, clock, f);
    help_button(paint, clock, f);
}
