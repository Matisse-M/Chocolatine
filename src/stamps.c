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

static void middle_lines(paint_t *paint, int x, int y, int i)
{
    for (int j = 1; j < paint->pen->size * 4 - 1; j++) {
        if ((x + i >= 320 && x + i < 1600) && (y + j >= 220 && y + j < 940))
            sfImage_setPixel(paint->image[paint->layer],
                x + i - 320, y + j - 220, paint->pen->color);
    }
}

void draw_square_on_image(sfVector2i position, paint_t *paint)
{
    int x = position.x - (paint->pen->size / 2);
    int y = position.y - (paint->pen->size / 2);

    for (int i = 1; i < paint->pen->size * 4 - 1; i++) {
        if ((x + i >= 320 && x + i < 1600) && (y >= 220 && y < 940))
            sfImage_setPixel(paint->image[paint->layer], x + i - 320, y - 220,
                paint->pen->color);
    }
    for (int i = 0; i < paint->pen->size * 4; i++)
        middle_lines(paint, x, y, i);
    for (int i = 1; i < paint->pen->size * 4 - 1; i++) {
        if ((x + i >= 320 && x + i < 1600) && (y + paint->pen->size * 4 - 1
            >= 220 && y + paint->pen->size * 4 - 1 < 940))
            sfImage_setPixel(paint->image[paint->layer], x + i - 320,
                y + paint->pen->size * 4 - 1 - 220, paint->pen->color);
    }
}

static void put_circle_pixel(paint_t *paint, sfVector2i position, int i,
    int j)
{
    int x = position.x;
    int y = position.y;
    int radius = paint->pen->size * 2;
    sfVector2f pos = sfSprite_getPosition(paint->sprite_buf[paint->layer]);
    sfVector2u size = sfImage_getSize(paint->image[paint->layer]);

    if ((i - x) * (i - x) + (j - y) * (j - y) < radius * radius) {
        if ((i >= pos.x && i < pos.x + size.x) && (j >= pos.y &&
            j < pos.y + size.y))
            sfImage_setPixel(paint->image[paint->layer], i - pos.x, j - pos.y,
                paint->pen->color);
    }
}

void draw_circle_on_image(sfVector2i position, paint_t *paint)
{
    for (int i = 0; i < 1920; i++) {
        for (int j = 0; j < 1080; j++) {
            put_circle_pixel(paint, position, i, j);
        }
    }
}

void draw_triangle_on_image(sfVector2i position, paint_t *paint)
{
    int x = position.x - (paint->pen->size / 2);
    int y = position.y - (paint->pen->size / 2);
    int size = 0;

    for (int i = 0; i < paint->pen->size * 2; i++) {
        for (int j = 0; j < paint->pen->size * 2 - i; j++)
            size++;
        for (int j = 0; j < i * 2 + 1; j++) {
            sfImage_setPixel(paint->image[paint->layer],
                x + size - 320, y - 220 + i, paint->pen->color);
            size++;
        }
        sfImage_setPixel(paint->image[paint->layer],
            x + size - 320, y - 220 + i, paint->pen->color);
        size = 0;
    }
}
