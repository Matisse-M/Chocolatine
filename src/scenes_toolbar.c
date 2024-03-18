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

static void apply_file_changes(sfRenderWindow *win, paint_t *paint, int i)
{
    if (my_hover_effect(win, paint->file->hitbox[i]) == 1)
        sfRectangleShape_setFillColor(paint->file->hitbox[i],
            (sfColor) {200, 200, 200, 255});
    else
        sfRectangleShape_setFillColor(paint->file->hitbox[i],
            (sfColor) {235, 235, 235, 255});
    sfRenderWindow_drawRectangleShape(win, paint->file->hitbox[i], NULL);
    sfRenderWindow_drawText(win, paint->file->text[i], NULL);
}

static void apply_edit_changes(sfRenderWindow *win, paint_t *paint, int i)
{
    if (my_hover_effect(win, paint->edit->hitbox[i]) == 1)
        sfRectangleShape_setFillColor(paint->edit->hitbox[i],
            (sfColor) {200, 200, 200, 255});
    else
        sfRectangleShape_setFillColor(paint->edit->hitbox[i],
            (sfColor) {235, 235, 235, 255});
    sfRenderWindow_drawRectangleShape(win, paint->edit->hitbox[i], NULL);
    sfRenderWindow_drawText(win, paint->edit->text[i], NULL);
}

static void apply_help_changes(sfRenderWindow *win, paint_t *paint, int i)
{
    if (my_hover_effect(win, paint->help->hitbox[i]) == 1)
        sfRectangleShape_setFillColor(paint->help->hitbox[i],
            (sfColor) {200, 200, 200, 255});
    else
        sfRectangleShape_setFillColor(paint->help->hitbox[i],
            (sfColor) {235, 235, 235, 255});
    sfRenderWindow_drawRectangleShape(win, paint->help->hitbox[i], NULL);
    sfRenderWindow_drawText(win, paint->help->text[i], NULL);
}

static void file_scene(sfRenderWindow *win, paint_t *paint, sfClock **clock)
{
    float f = 0;
    sfTime elapsed = sfClock_getElapsedTime(*clock);

    f = sfTime_asSeconds(elapsed);
    if (paint->scene->menu[0] == true) {
        for (int i = 0; i < 4; i++) {
            apply_file_changes(win, paint, i);
        }
        if ((my_hover_effect(win, paint->file->hitbox[0]) == 0 &&
            my_hover_effect(win, paint->file->hitbox[1]) == 0 &&
            my_hover_effect(win, paint->file->hitbox[2]) == 0 &&
            my_hover_effect(win, paint->file->hitbox[3]) == 0 &&
            my_hover_effect(win, paint->header->hitbox[0]) == 0) &&
            sfMouse_isButtonPressed(sfMouseLeft))
            paint->scene->menu[0] = false;
        my_file_buttons(paint, clock, f);
    }
}

static void edit_scene(sfRenderWindow *win, paint_t *paint, sfClock **clock)
{
    float f = 0;
    sfTime elapsed = sfClock_getElapsedTime(*clock);

    f = sfTime_asSeconds(elapsed);
    if (paint->scene->menu[1] == true) {
        for (int i = 0; i < 4; i++) {
            apply_edit_changes(win, paint, i);
        }
        if ((my_hover_effect(win, paint->edit->hitbox[0]) == 0 &&
            my_hover_effect(win, paint->edit->hitbox[1]) == 0 &&
            my_hover_effect(win, paint->edit->hitbox[2]) == 0 &&
            my_hover_effect(win, paint->edit->hitbox[3]) == 0 &&
            my_hover_effect(win, paint->header->hitbox[1]) == 0) &&
            sfMouse_isButtonPressed(sfMouseLeft))
            paint->scene->menu[1] = false;
        my_edit_buttons(paint, clock, f);
    }
}

static void help_scene(sfRenderWindow *win, paint_t *paint, sfClock **clock)
{
    float f = 0;
    sfTime elapsed = sfClock_getElapsedTime(*clock);

    f = sfTime_asSeconds(elapsed);
    if (paint->scene->menu[2] == true) {
        for (int i = 0; i < 2; i++) {
            apply_help_changes(win, paint, i);
        }
        if ((my_hover_effect(win, paint->help->hitbox[0]) == 0 &&
            my_hover_effect(win, paint->help->hitbox[1]) == 0 &&
            my_hover_effect(win, paint->header->hitbox[2]) == 0) &&
            sfMouse_isButtonPressed(sfMouseLeft))
            paint->scene->menu[2] = false;
        my_help_buttons(paint, clock, f);
    }
}

void check_toolbar_scenes(sfRenderWindow *win, paint_t *paint, sfClock **clock)
{
    file_scene(win, paint, clock);
    edit_scene(win, paint, clock);
    help_scene(win, paint, clock);
}
