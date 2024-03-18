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

select_t *fill_select(void)
{
    select_t *select = malloc(sizeof(select_t));
    sfColor color = {225, 225, 225, 255};
    sfFont *font = sfFont_createFromFile("assets/font.ttf");
    char *words[4] = {"Square", "Circle", "Triangle", "Star"};

    select->btn = malloc(sizeof(sfRectangleShape *) * 4);
    select->text = malloc(sizeof(sfText *) * 4);
    for (int i = 0; i < 4; i++) {
        select->btn[i] = my_set_rectangle((sfVector2f) {100, 32},
            (sfVector2f) {890, 117 + (i * 33)});
        my_custom_rectangle(select->btn[i], 1, color, sfBlack);
        select->text[i] = my_set_text(words[i], 16, (sfVector2f)
            {900, 122 + (i * 33)}, font);
        sfText_setFillColor(select->text[i], sfBlack);
    }
    return select;
}

static void apply_hover(paint_t *paint, int i, sfClock **clock)
{
    sfTime elapsed = sfClock_getElapsedTime(*clock);
    float f = sfTime_asSeconds(elapsed);

    if (my_hover_effect(paint->win, paint->select->btn[i]) == 1) {
        if (sfMouse_isButtonPressed(sfMouseLeft) && f > 0.2) {
            paint->pen->shape = i;
            paint->scene->which_s = false;
            sfClock_restart(*clock);
        }
        sfRectangleShape_setFillColor(paint->select->btn[i],
            (sfColor) {200, 200, 200, 255});
    } else
        sfRectangleShape_setFillColor(paint->select->btn[i],
            (sfColor) {235, 235, 235, 255});
    sfRenderWindow_drawRectangleShape(paint->win, paint->select->btn[i], NULL);
    sfRenderWindow_drawText(paint->win, paint->select->text[i], NULL);
}

void draw_shapes(paint_t *paint, sfClock **clock)
{
    for (int i = 0; i < 4; i++) {
        apply_hover(paint, i, clock);
        sfRenderWindow_drawRectangleShape(paint->win,
            paint->select->btn[i], NULL);
        sfRenderWindow_drawText(paint->win, paint->select->text[i], NULL);
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

static void update_my_page(paint_t *paint, float f, sfClock **clock,
    void (*ptr)(sfVector2i position, paint_t *paint))
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(paint->win);
    sfColor sep = {150, 150, 150, 255};

    if (write_on_page(paint->win, paint->page, 10) == 1 &&
        sfMouse_isButtonPressed(sfMouseLeft) && f > 0.2) {
            ptr(pos, paint);
            sfClock_restart(*clock);
    }
    paint->texture_buf[paint->layer] = sfTexture_createFromImage(paint->image
        [paint->layer], NULL);
    sfSprite_setTexture(paint->sprite_buf[paint->layer], paint->texture_buf
        [paint->layer], sfFalse);
    for (int i = 0; i < 5; i++)
        sfRenderTexture_drawSprite(paint->texture, paint->sprite_buf[i], NULL);
    paint->saved = false;
}

void put_shape(paint_t *paint, sfClock **clock)
{
    sfTime elapsed = sfClock_getElapsedTime(*clock);
    float f = sfTime_asSeconds(elapsed);

    if (paint->pen->shape == 0 && f > 0.2)
        update_my_page(paint, f, clock, &draw_square_on_image);
    if (paint->pen->shape == 1 && f > 0.2)
        update_my_page(paint, f, clock, &draw_circle_on_image);
    if (paint->pen->shape == 2 && f > 0.2)
        update_my_page(paint, f, clock, &draw_triangle_on_image);
    if (paint->pen->shape == 3 && f > 0.2)
        update_my_page(paint, f, clock, &draw_circle_on_image);
}
