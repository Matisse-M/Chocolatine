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

static void destroy_colo(paint_t *paint)
{
    for (int i = 0; i < 8; i++)
        sfRectangleShape_destroy(paint->colo->basic_colors[i]);
    for (int i = 0; i < 24; i++)
        sfRectangleShape_destroy(paint->colo->history_colors[i]);
    sfRectangleShape_destroy(paint->colo->area_pip);
    sfRectangleShape_destroy(paint->colo->area_rub);
    sfTexture_destroy(paint->colo->texture_pip);
    sfSprite_destroy(paint->colo->sprite_pip);
}

static void destroy_header(paint_t *paint)
{
    for (int i = 0; i < 3; i++)
        sfRectangleShape_destroy(paint->header->hitbox[i]);
    for (int i = 0; i < 3; i++)
        sfText_destroy(paint->header->text[i]);
}

static void destroy_menu(paint_t *paint)
{
    for (int i = 0; i < 4; i++)
        sfRectangleShape_destroy(paint->file->hitbox[i]);
    for (int i = 0; i < 4; i++)
        sfText_destroy(paint->file->text[i]);
    for (int i = 0; i < 4; i++)
        sfRectangleShape_destroy(paint->edit->hitbox[i]);
    for (int i = 0; i < 4; i++)
        sfText_destroy(paint->edit->text[i]);
    for (int i = 0; i < 2; i++)
        sfRectangleShape_destroy(paint->help->hitbox[i]);
    for (int i = 0; i < 2; i++)
        sfText_destroy(paint->help->text[i]);
}

static void destroy_scroller(paint_t *paint)
{
    sfRectangleShape_destroy(paint->size_pen->area);
    sfRectangleShape_destroy(paint->size_pen->bar);
    sfCircleShape_destroy(paint->size_pen->btn);
    sfText_destroy(paint->size_pen->text);
    sfRectangleShape_destroy(paint->size_rub->area);
    sfRectangleShape_destroy(paint->size_rub->bar);
    sfCircleShape_destroy(paint->size_rub->btn);
    sfText_destroy(paint->size_rub->text);
}

static void destroy_shader(paint_t *paint)
{
    for (int i = 0; i < 4; i++) {
        sfRectangleShape_destroy(paint->shader->bars[i]);
        sfRectangleShape_destroy(paint->shader->hitbox[i]);
        sfRectangleShape_destroy(paint->shader->col[i]);
        sfText_destroy(paint->shader->text[i]);
        sfCircleShape_destroy(paint->shader->ball[i]);
    }
    sfRectangleShape_destroy(paint->shader->bckgrnd);
    sfRectangleShape_destroy(paint->shader->display);
    sfRectangleShape_destroy(paint->shader->okay);
    sfText_destroy(paint->shader->validate);
}

static void destroy_save(paint_t *paint)
{
    sfRectangleShape_destroy(paint->wanna_save->popup);
    sfRectangleShape_destroy(paint->wanna_save->shade);
    for (int i = 0; i < 3; i++) {
        sfText_destroy(paint->wanna_save->text[i]);
        sfRectangleShape_destroy(paint->wanna_save->btn[i]);
    }
}

static void destroy_rename(paint_t *paint)
{
    sfRectangleShape_destroy(paint->rename->bar);
    sfRectangleShape_destroy(paint->rename->bckgrnd);
    sfRectangleShape_destroy(paint->rename->ext);
    sfRectangleShape_destroy(paint->rename->shade);
    sfText_destroy(paint->rename->alert);
    sfText_destroy(paint->rename->end);
    sfText_destroy(paint->rename->message);
    sfText_destroy(paint->rename->name);
    sfText_destroy(paint->rename->null);
    sfText_destroy(paint->rename->render);
}

static void destroy_open(paint_t *paint)
{
    sfRectangleShape_destroy(paint->open->bckgrnd);
    sfRectangleShape_destroy(paint->open->shade);
    sfText_destroy(paint->open->warning);
    sfText_destroy(paint->open->select);
}

static void destroy_structure(paint_t *paint)
{
    destroy_colo(paint);
    destroy_header(paint);
    destroy_menu(paint);
    destroy_open(paint);
    destroy_rename(paint);
    destroy_save(paint);
    destroy_scroller(paint);
    destroy_shader(paint);
    sfRectangleShape_destroy(paint->page);
    for (int i = 0; i < 3; i++)
        sfRectangleShape_destroy(paint->gray[i]);
}

void destroy_program(paint_t *paint, sfClock **clock)
{
    sfClock_destroy(*clock);
    sfRenderWindow_destroy(paint->win);
}
