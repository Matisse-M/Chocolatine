/*
** EPITECH PROJECT, 2023
** main
** File description:
** main()
*/

#include <stdarg.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "paint.h"
#include "csfml.h"

static void hover_save(void (*ptr)(paint_t *paint), paint_t *paint)
{
    if (my_hover_effect(paint->win, paint->wanna_save->btn[0]) == 1) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            save_that_file(paint);
            ptr(paint);
            paint->scene->exit = false;
        }
        sfRectangleShape_setFillColor(paint->wanna_save->btn[0],
            (sfColor) {200, 200, 200, 255});
    } else {
        sfRectangleShape_setFillColor(paint->wanna_save->btn[0],
            (sfColor) {225, 225, 225, 255});
    }
}

static void hover_discard(void (*ptr)(paint_t *paint), paint_t *paint)
{
    if (my_hover_effect(paint->win, paint->wanna_save->btn[1]) == 1) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            ptr(paint);
            paint->scene->exit = false;
        }
        sfRectangleShape_setFillColor(paint->wanna_save->btn[1],
            (sfColor) {200, 200, 200, 255});
    } else {
        sfRectangleShape_setFillColor(paint->wanna_save->btn[1],
            (sfColor) {225, 225, 225, 255});
    }
}

static void hover_cancel(paint_t *paint)
{
    if (my_hover_effect(paint->win, paint->wanna_save->btn[2]) == 1) {
        if (sfMouse_isButtonPressed(sfMouseLeft))
            paint->scene->exit = false;
        sfRectangleShape_setFillColor(paint->wanna_save->btn[2],
            (sfColor) {200, 200, 200, 255});
    } else {
        sfRectangleShape_setFillColor(paint->wanna_save->btn[2],
            (sfColor) {225, 225, 225, 255});
    }
}

static void set_text(menu_save_t *save)
{
    sfFont *font = sfFont_createFromFile("assets/font.ttf");

    save->text = malloc(sizeof(sfText *) * 5);
    save->text[0] = my_set_text("Save", 36, (sfVector2f) {720, 675}, font);
    sfText_setFillColor(save->text[0], sfBlack);
    save->text[1] = my_set_text("Discard", 36, (sfVector2f) {895, 675}, font);
    sfText_setFillColor(save->text[1], sfRed);
    save->text[2] = my_set_text("Cancel", 36, (sfVector2f) {1100, 675}, font);
    sfText_setFillColor(save->text[2], sfBlack);
    save->text[3] = my_set_text("SAVE CHANGES?", 48, (sfVector2f) {790, 400},
        font);
    sfText_setFillColor(save->text[3], sfBlack);
    save->text[4] = my_set_text("\
        MyPaint contains unsaved changes. Changes which\n\
                    are not saved will be permanently lost.",
        23, (sfVector2f) {650, 500}, font);
    sfText_setFillColor(save->text[4], sfBlack);
}

static void set_buttons(menu_save_t *save)
{
    sfColor grey = {225, 225, 225, 255};

    save->btn = malloc(sizeof(sfRectangleShape *) * 3);
    save->btn[0] = my_set_rectangle((sfVector2f) {200, 100},
        (sfVector2f) {660, 650});
    my_custom_rectangle(save->btn[0], 1, grey, sfBlack);
    save->btn[1] = my_set_rectangle((sfVector2f) {200, 100},
        (sfVector2f) {860, 650});
    my_custom_rectangle(save->btn[1], 1, grey, sfBlack);
    save->btn[2] = my_set_rectangle((sfVector2f) {200, 100},
        (sfVector2f) {1060, 650});
    my_custom_rectangle(save->btn[2], 1, grey, sfBlack);
}

menu_save_t *fill_menu_save(void)
{
    menu_save_t *save = malloc(sizeof(menu_save_t));
    sfColor shade = {0, 0, 0, 100};
    sfColor grey = {225, 225, 225, 255};

    save->shade = my_set_rectangle((sfVector2f) {1920, 1080},
        (sfVector2f) {0, 0});
    my_custom_rectangle(save->shade, 0, shade, sfTransparent);
    save->popup = my_set_rectangle((sfVector2f) {600, 300},
        (sfVector2f) {660, 390});
    my_custom_rectangle(save->popup, 1, grey, sfBlack);
    set_buttons(save);
    set_text(save);
    return save;
}

void draw_exit_menu(void (*ptr)(paint_t *paint), paint_t *paint)
{
    sfRenderWindow_drawRectangleShape(paint->win,
        paint->wanna_save->shade, NULL);
    sfRenderWindow_drawRectangleShape(paint->win,
        paint->wanna_save->popup, NULL);
    sfRenderWindow_drawText(paint->win, paint->wanna_save->text[3], NULL);
    sfRenderWindow_drawText(paint->win, paint->wanna_save->text[4], NULL);
    hover_save(ptr, paint);
    hover_discard(ptr, paint);
    hover_cancel(paint);
    for (int i = 0; i < 3; i++) {
        sfRenderWindow_drawRectangleShape(paint->win,
            paint->wanna_save->btn[i], NULL);
        sfRenderWindow_drawText(paint->win, paint->wanna_save->text[i], NULL);
    }
}
