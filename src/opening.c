/*
** EPITECH PROJECT, 2023
** main
** File description:
** main()
*/

#include <stdarg.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "paint.h"
#include "csfml.h"
#include "my.h"

static void fill_buttons(paint_t *paint, char **files)
{
    sfFont *font = sfFont_createFromFile("assets/font.ttf");
    int j = 0;

    for (int i = 0; i < my_tablen(files); i++) {
        if (j == 15)
            j = 0;
        paint->open->btn[i] = my_set_rectangle((sfVector2f) {1280, 30},
            (sfVector2f) {320, 360 + (j * 31)});
        my_custom_rectangle(paint->open->btn[i], 1, sfWhite, sfBlack);
        paint->open->files[i] = my_set_text(files[i], 20,
            (sfVector2f) {330, 361 + (j * 31)}, font);
        sfText_setFillColor(paint->open->files[i], sfBlack);
        j++;
    }
}

static void file_chosen(paint_t *paint, float f, sfClock **clock, char *file)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) && f > 0.2 &&
        paint->scene->open == true) {
        restart_image_open(paint, file);
        paint->scene->open = false;
        paint->name = my_strdup(file);
        sfClock_restart(*clock);
    }
    select_import_file(paint, clock, f, file);
}

static void hover_files(paint_t *paint, sfClock **clock, char **file)
{
    sfTime elapsed = sfClock_getElapsedTime(*clock);
    float f = sfTime_asSeconds(elapsed);

    for (int i = paint->open->page * 15; i < my_tablen(file) &&
        i < 15 * (paint->open->page + 1); i++) {
        if (my_hover_effect(paint->win, paint->open->btn[i]) == 1) {
            file_chosen(paint, f, clock, file[i]);
            sfRectangleShape_setFillColor(paint->open->btn[i],
                (sfColor) {200, 200, 200, 255});
        } else {
            sfRectangleShape_setFillColor(paint->open->btn[i], sfWhite);
        }
    }
}

static void hover_arrow_up(paint_t *paint, sfClock **clock, char **files)
{
    sfTime elapsed = sfClock_getElapsedTime(*clock);
    float f = sfTime_asSeconds(elapsed);
    sfTexture *texture;

    if (my_hover_effect(paint->win, paint->open->arrow[0]) == 1 &&
        my_tablen(&files[paint->open->page * 15]) > 15) {
        if (sfMouse_isButtonPressed(sfMouseLeft) && f > 0.2) {
            paint->open->page += 1;
            sfClock_restart(*clock);
        }
        texture = sfTexture_createFromFile("assets/up_h.png", NULL);
        sfRectangleShape_setTexture(paint->open->arrow[0], texture, sfFalse);
    } else {
        texture = sfTexture_createFromFile("assets/up.png", NULL);
        sfRectangleShape_setTexture(paint->open->arrow[0], texture, sfFalse);
    }
}

static void hover_arrow(paint_t *paint, sfClock **clock, char **files)
{
    sfTime elapsed = sfClock_getElapsedTime(*clock);
    float f = sfTime_asSeconds(elapsed);
    sfTexture *texture;

    hover_arrow_up(paint, clock, files);
    if (my_hover_effect(paint->win, paint->open->arrow[1]) == 1
        && paint->open->page > 0) {
        if (sfMouse_isButtonPressed(sfMouseLeft) && f > 0.2) {
            paint->open->page -= 1;
            sfClock_restart(*clock);
        }
        texture = sfTexture_createFromFile("assets/down_h.png", NULL);
        sfRectangleShape_setTexture(paint->open->arrow[1], texture, sfFalse);
    } else {
        texture = sfTexture_createFromFile("assets/down.png", NULL);
        sfRectangleShape_setTexture(paint->open->arrow[1], texture, sfFalse);
    }
    my_free_word_array(files);
}

static void draw_arrows(char **files, paint_t *paint)
{
    if (my_tablen(&files[paint->open->page * 15]) > 15)
        sfRenderWindow_drawRectangleShape(paint->win,
            paint->open->arrow[0], NULL);
    if (paint->open->page > 0)
        sfRenderWindow_drawRectangleShape(paint->win,
            paint->open->arrow[1], NULL);
}

void draw_open(paint_t *paint, sfClock **clock)
{
    char **files = get_files(paint);

    if (files == NULL)
        return;
    paint->open->btn = malloc(sizeof(sfRectangleShape *) * my_tablen(files));
    paint->open->files = malloc(sizeof(sfText *) * my_tablen(files));
    sfRenderWindow_drawRectangleShape(paint->win, paint->open->shade, NULL);
    sfRenderWindow_drawRectangleShape(paint->win, paint->open->bckgrnd, NULL);
    sfRenderWindow_drawText(paint->win, paint->open->select, NULL);
    sfRenderWindow_drawText(paint->win, paint->open->warning, NULL);
    fill_buttons(paint, files);
    hover_files(paint, clock, files);
    for (int i = paint->open->page * 15; i < my_tablen(files) &&
        i < 15 * (paint->open->page + 1); i++) {
        sfRenderWindow_drawRectangleShape(paint->win,
            paint->open->btn[i], NULL);
        sfRenderWindow_drawText(paint->win, paint->open->files[i], NULL);
    }
    draw_arrows(files, paint);
    hover_arrow(paint, clock, files);
}
