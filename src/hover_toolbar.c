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

static void close_tools(paint_t *paint, sfClock **clock, int i)
{
    for (int i = 0; i < 3; i++)
        paint->scene->menu[i] = false;
    sfRectangleShape_setFillColor(paint->header->hitbox[i], sfTransparent);
    sfText_setColor(paint->header->text[i], sfWhite);
    paint->scene->menu[i] = false;
    sfClock_restart(*clock);
}

static void button_clicked(float f, paint_t *paint, sfClock **clock, int i)
{
    sfColor color = {0, 0, 0, 35};

    if (sfMouse_isButtonPressed(sfMouseLeft) && f > 0.2 &&
        paint->scene->menu[i] == false) {
        for (int j = 0; j < 4; j++)
            paint->scene->menu[j] = false;
        sfRectangleShape_setFillColor(paint->header->hitbox[i], sfTransparent);
        sfText_setColor(paint->header->text[i], sfWhite);
        paint->scene->menu[i] = true;
        sfClock_restart(*clock);
    } else if (sfMouse_isButtonPressed(sfMouseLeft) && f > 0.2 &&
        paint->scene->menu[i] == true) {
        close_tools(paint, clock, i);
    }
    sfRectangleShape_setFillColor(paint->header->hitbox[i], color);
}

void hover_header(sfRenderWindow *win, paint_t *paint, sfClock **clock)
{
    float f = 0;
    sfTime elapsed = sfClock_getElapsedTime(*clock);

    f = sfTime_asSeconds(elapsed);
    for (int i = 0; i < 3; i++) {
        if (my_hover_effect(win, paint->header->hitbox[i]) == 1) {
            button_clicked(f, paint, clock, i);
        } else {
            sfRectangleShape_setFillColor(paint->header->hitbox[i],
                sfTransparent);
            sfText_setColor(paint->header->text[i], sfBlack);
        }
    }
}
