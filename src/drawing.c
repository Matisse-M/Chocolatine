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

pen_t *fill_pen(void)
{
    pen_t *pen = malloc(sizeof(pen_t));

    pen->color = sfBlack;
    pen->size = 0;
    pen->shape = 0;
    return pen;
}

static void middle_lines(paint_t *paint, int x, int y, int i)
{
    for (int j = 1; j < paint->pen->size - 1; j++) {
        if ((x + i >= 320 && x + i < 1600) && (y + j >= 220 && y + j < 940))
            sfImage_setPixel(paint->image[paint->layer],
                x + i - 320, y + j - 220, paint->pen->color);
    }
}

static void draw_square_rub(sfVector2i position, paint_t *paint)
{
    int x = position.x - (paint->pen->size / 2);
    int y = position.y - (paint->pen->size / 2);

    for (int i = 1; i < paint->pen->size - 1; i++) {
        if ((x + i >= 320 && x + i < 1600) && (y >= 220 && y < 940))
            sfImage_setPixel(paint->image[paint->layer], x + i - 320, y - 220,
                paint->pen->color);
    }
    for (int i = 0; i < paint->pen->size; i++)
        middle_lines(paint, x, y, i);
    for (int i = 1; i < paint->pen->size - 1; i++) {
        if ((x + i >= 320 && x + i < 1600) && (y + paint->pen->size - 1 >= 220
            && y + paint->pen->size - 1 < 940))
            sfImage_setPixel(paint->image[paint->layer], x + i - 320,
                y + paint->pen->size - 1 - 220, paint->pen->color);
    }
}

static void put_pixel_on_image(paint_t *paint, sfVector2i position, int i,
    int j)
{
    int x = position.x;
    int y = position.y;
    int radius = paint->pen->size / 2;
    sfVector2f pos = sfSprite_getPosition(paint->sprite_buf[paint->layer]);
    sfVector2u size = sfImage_getSize(paint->image[paint->layer]);

    if ((i - x) * (i - x) + (j - y) * (j - y) < radius * radius) {
        if ((i >= pos.x && i < pos.x + size.x) && (j >= pos.y &&
            j < pos.y + size.y))
            sfImage_setPixel(paint->image[paint->layer], i - pos.x, j - pos.y,
                paint->pen->color);
    }
}

static void draw_circle(sfVector2i position, paint_t *paint)
{
    for (int i = 0; i < 1920; i++) {
        for (int j = 0; j < 1080; j++) {
            put_pixel_on_image(paint, position, i, j);
        }
    }
}

int write_on_page(sfRenderWindow *window, sfRectangleShape *rect, int size)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    sfFloatRect area = sfRectangleShape_getGlobalBounds(rect);

    if (sfFloatRect_contains(&area, mouse.x - size, mouse.y - size)
        && sfFloatRect_contains(&area, mouse.x + size,
        mouse.y + size))
        return (1);
    return (0);
}

void update_my_framebuffer(sfRenderWindow *win, paint_t *paint)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(win);
    sfColor sep = {150, 150, 150, 255};

    draw_circle(pos, paint);
    paint->texture_buf[paint->layer] = sfTexture_createFromImage(paint->image
        [paint->layer], NULL);
    sfSprite_setTexture(paint->sprite_buf[paint->layer], paint->texture_buf
        [paint->layer], sfFalse);
    for (int i = 0; i < 5; i++)
        sfRenderTexture_drawSprite(paint->texture, paint->sprite_buf[i], NULL);
    paint->saved = false;
}

void put_my_mouse(sfCircleShape **cursor, sfRenderWindow *win)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(win);
    float size = sfCircleShape_getRadius(*cursor);

    sfCircleShape_setPosition(*cursor,
        (sfVector2f) {pos.x - size, pos.y - size});
    sfRenderWindow_drawCircleShape(win, *cursor, NULL);
}

void switch_pencil_colors(sfRenderWindow *win, paint_t *paint)
{
    for (int i = 0; i < 8; i++) {
        if (my_hover_effect(win, paint->colo->basic_colors[i]) == 1 &&
            sfMouse_isButtonPressed(sfMouseLeft)) {
            paint->pen->color = sfRectangleShape_getFillColor(
                paint->colo->basic_colors[i]);
        }
    }
    for (int i = 0; i < 24; i++) {
        if (my_hover_effect(win, paint->colo->history_colors[i]) == 1 &&
            sfMouse_isButtonPressed(sfMouseLeft)) {
            paint->pen->color = sfRectangleShape_getFillColor(
                paint->colo->history_colors[i]);
        }
    }
}
