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

static void new_button(paint_t *paint, sfClock **clock, float f)
{
    if (my_hover_effect(paint->win, paint->file->hitbox[0]) == 1 &&
        sfMouse_isButtonPressed(sfMouseLeft) && f > 0.2) {
        if (paint->saved == false) {
            paint->scene->exit = true;
            paint->scene->menu[0] = false;
            return;
        }
        restart_image_jpg(paint);
        paint->scene->menu[0] = false;
        sfClock_restart(*clock);
    }
}

static void open_button(paint_t *paint, sfClock **clock, float f)
{
    if (my_hover_effect(paint->win, paint->file->hitbox[1]) == 1 &&
        sfMouse_isButtonPressed(sfMouseLeft) && f > 0.2) {
        paint->scene->open = true;
        paint->scene->menu[0] = false;
        sfClock_restart(*clock);
    }
}

static void save_button(paint_t *paint, sfClock **clock, float f)
{
    if (my_hover_effect(paint->win, paint->file->hitbox[2]) == 1 &&
        sfMouse_isButtonPressed(sfMouseLeft) && f > 0.2) {
        save_that_file(paint);
        paint->scene->menu[0] = false;
        sfClock_restart(*clock);
    }
}

static void rename_button(paint_t *paint, sfClock **clock, float f)
{
    if (my_hover_effect(paint->win, paint->file->hitbox[3]) == 1 &&
        sfMouse_isButtonPressed(sfMouseLeft) && f > 0.2) {
        paint->scene->rename = true;
        sfClock_restart(*clock);
    }
}

void my_file_buttons(paint_t *paint, sfClock **clock, float f)
{
    new_button(paint, clock, f);
    open_button(paint, clock, f);
    save_button(paint, clock, f);
    rename_button(paint, clock, f);
}
