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

static void texture_size(paint_t *paint)
{
    sfVector2u size;
    sfView *view = sfView_create();

    size = sfImage_getSize(paint->image[0]);
    sfView_setSize(view, (sfVector2f) {size.x, size.y});
    sfView_setRotation(view, 180);
    sfView_setCenter(view, (sfVector2f) {1920 / 2, 1080 / 2});
    paint->texture = sfRenderTexture_create(size.x, size.y, sfTrue);
    sfRenderTexture_setView(paint->texture, view);
    sfRectangleShape_setSize(paint->page, (sfVector2f) {size.x, size.y});
    sfRectangleShape_setPosition(paint->page, (sfVector2f) {1920 / 2 -
        (size.x / 2), 1080 / 2 - (size.y / 2)});
    for (int i = 0; i < 5; i++) {
        sfSprite_setPosition(paint->sprite_buf[i], (sfVector2f) {1920 / 2 -
            (size.x / 2), 1080 / 2 - (size.y / 2)});
        sfSprite_setTexture(paint->sprite_buf[i],
            paint->texture_buf[i], sfTrue);
        sfRenderTexture_drawSprite(paint->texture, paint->sprite_buf[i], NULL);
    }
}

static void restart_image_two(paint_t *paint)
{
    sfVector2u size = sfImage_getSize(paint->image[0]);

    for (int i = 1; i < 5; i++) {
        paint->image[i] = sfImage_createFromColor(size.x, size.y,
            sfTransparent);
        paint->texture_buf[i] = sfTexture_createFromImage
            (paint->image[i], NULL);
        paint->sprite_buf[i] = sfSprite_create();
    }
    texture_size(paint);
    paint->scene->pencil = false;
    paint->scene->rubber = false;
}

void restart_image_open(paint_t *paint, char *filename)
{
    sfImage *img = sfImage_createFromFile(my_cat("./gallery/", filename));

    if (img == NULL)
        return;
    for (int i = 0; i < 5; i++) {
        sfImage_destroy(paint->image[i]);
        sfTexture_destroy(paint->texture_buf[i]);
        sfSprite_destroy(paint->sprite_buf[i]);
    }
    sfRenderTexture_destroy(paint->texture);
    paint->image = malloc(sizeof(sfImage *) * 5);
    paint->image[0] = sfImage_createFromFile(my_cat("./gallery/", filename));
    paint->texture_buf = malloc(sizeof(sfTexture *) * 5);
    paint->texture_buf[0] = sfTexture_createFromImage(paint->image[0], NULL);
    paint->sprite_buf = malloc(sizeof(sfSprite *) * 5);
    paint->sprite_buf[0] = sfSprite_create();
    restart_image_two(paint);
}

static void restar_imgae_jpg_two(paint_t *paint)
{
    for (int i = 1; i < 5; i++) {
        paint->image[i] = sfImage_createFromColor(1280, 720, sfTransparent);
        paint->texture_buf[i] = sfTexture_createFromImage
            (paint->image[i], NULL);
        paint->sprite_buf[i] = sfSprite_create();
    }
    texture_size(paint);
    paint->scene->pencil = false;
    paint->scene->rubber = false;
}

void restart_image_jpg(paint_t *paint)
{
    sfVector2u size;

    for (int i = 0; i < 5; i++) {
        sfImage_destroy(paint->image[i]);
        sfTexture_destroy(paint->texture_buf[i]);
        sfSprite_destroy(paint->sprite_buf[i]);
    }
    sfRenderTexture_destroy(paint->texture);
    paint->image = malloc(sizeof(sfImage *) * 5);
    paint->image[0] = sfImage_createFromColor(1280, 720, sfWhite);
    paint->texture_buf = malloc(sizeof(sfTexture *) * 5);
    paint->texture_buf[0] = sfTexture_createFromImage(paint->image[0], NULL);
    paint->sprite_buf = malloc(sizeof(sfSprite *) * 5);
    paint->sprite_buf[0] = sfSprite_create();
    restar_imgae_jpg_two(paint);
}

static void restart_image_png_two(paint_t *paint)
{
    for (int i = 1; i < 5; i++) {
        paint->image[i] = sfImage_createFromColor(1280, 720, sfTransparent);
        paint->texture_buf[i] = sfTexture_createFromImage
            (paint->image[i], NULL);
        paint->sprite_buf[i] = sfSprite_create();
    }
    texture_size(paint);
    paint->scene->pencil = false;
    paint->scene->rubber = false;
}

void restart_image_png(paint_t *paint)
{
    sfVector2u size;

    for (int i = 0; i < 5; i++) {
        sfImage_destroy(paint->image[i]);
        sfTexture_destroy(paint->texture_buf[i]);
        sfSprite_destroy(paint->sprite_buf[i]);
    }
    sfRenderTexture_destroy(paint->texture);
    paint->image = malloc(sizeof(sfImage *) * 5);
    paint->image[0] = sfImage_createFromColor(1280, 720, sfTransparent);
    paint->texture_buf = malloc(sizeof(sfTexture *) * 5);
    paint->texture_buf[0] = sfTexture_createFromImage(paint->image[0], NULL);
    paint->sprite_buf = malloc(sizeof(sfSprite *) * 5);
    paint->sprite_buf[0] = sfSprite_create();
    restart_image_png_two(paint);
}

void save_that_file(paint_t *paint)
{
    sfImage *image = sfTexture_copyToImage(
        sfRenderTexture_getTexture(paint->texture));

    sfImage_saveToFile(image, my_cat("./gallery/", paint->name));
    paint->saved = true;
}
