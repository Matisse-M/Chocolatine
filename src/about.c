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

about_t *fill_about(char *user)
{
    about_t *about = malloc(sizeof(about_t));
    sfFont *font = sfFont_createFromFile("assets/font.ttf");

    about->shade = my_set_rectangle((sfVector2f) {1920, 1080},
        (sfVector2f) {0, 0});
    my_custom_rectangle(about->shade, 0, (sfColor) {0, 0, 0, 100},
        sfTransparent);
    about->bckgrnd = my_set_rectangle((sfVector2f) {500, 50},
        (sfVector2f) {710, 50});
    my_custom_rectangle(about->bckgrnd, 1, (sfColor) {225, 225, 225, 255},
        sfBlack);
    about->text = my_set_text("Hello:", 32, (sfVector2f) {720, 55}, font);
    sfText_setFillColor(about->text, sfBlack);
    about->user = my_set_text(user, 32, (sfVector2f) {810, 55}, font);
    sfText_setFillColor(about->user, sfRed);
    return about;
}

void display_about(paint_t *paint, sfClock **clock)
{
    float f = 0;
    sfTime elapsed = sfClock_getElapsedTime(*clock);

    f = sfTime_asSeconds(elapsed);
    if (sfKeyboard_isKeyPressed(sfKeyEscape) && f > 0.2) {
        paint->scene->about = false;
    }
    sfRenderWindow_drawRectangleShape(paint->win, paint->about->shade, NULL);
    sfRenderWindow_drawRectangleShape(paint->win, paint->about->bckgrnd, NULL);
    sfRenderWindow_drawText(paint->win, paint->about->text, NULL);
    sfRenderWindow_drawText(paint->win, paint->about->user, NULL);
}
