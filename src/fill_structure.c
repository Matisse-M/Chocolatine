/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-mypaint-albane.merian
** File description:
** fill_structure
*/

#include <stdarg.h>
#include <stdlib.h>
#include <stdbool.h>
#include "paint.h"
#include "csfml.h"

static void fill_structure_one(paint_t *paint)
{
    paint->saved = false;
    paint->buf = framebuffer_create(1920, 1080);
    paint->image = malloc(sizeof(sfImage *) * 5);
    paint->image[0] = sfImage_createFromColor(1280, 720, sfWhite);
    paint->texture_buf = malloc(sizeof(sfTexture *) * 5);
    paint->texture_buf[0] = sfTexture_createFromImage(paint->image[0], NULL);
    paint->sprite_buf = malloc(sizeof(sfSprite *) * 5);
    paint->sprite_buf[0] = sfSprite_create();
    for (int i = 1; i < 5; i++) {
        paint->image[i] = sfImage_createFromColor(1280, 720, sfTransparent);
        paint->texture_buf[i] = sfTexture_createFromImage
            (paint->image[i], NULL);
        paint->sprite_buf[i] = sfSprite_create();
    }
}

static void fill_structure_two(paint_t *paint, char *user, sfView *view)
{
    sfRenderTexture_setView(paint->texture, view);
    color_and_toolbar(paint, user);
    sfSprite_setPosition(paint->sprite_buf[0], (sfVector2f) {320, 220});
    sfSprite_setTexture(paint->sprite_buf[0], paint->texture_buf[0], sfTrue);
    for (int i = 1; i < 5; i++) {
        sfSprite_setPosition(paint->sprite_buf[i], (sfVector2f) {320, 220});
        sfSprite_setTexture
            (paint->sprite_buf[i], paint->texture_buf[i], sfTrue);
    }
}

paint_t *fill_structure(char *user)
{
    paint_t *paint = malloc(sizeof(paint_t));
    sfView *view = sfView_create();

    sfView_setSize(view, (sfVector2f) {1280, 720});
    sfView_setCenter(view, (sfVector2f) {960, 580});
    sfView_setRotation(view, 180);
    fill_structure_one(paint);
    paint->rename = fill_rename();
    paint->open = fill_open();
    paint->h = fill_help();
    paint->texture = sfRenderTexture_create(1280, 720, sfTrue);
    fill_structure_two(paint, user, view);
    return paint;
}
