/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-mypaint-albane.merian
** File description:
** paint_two
*/
#include <stdarg.h>
#include <stdlib.h>
#include <stdbool.h>
#include "paint.h"
#include "csfml.h"
#include "my.h"

void draw_scene(sfRenderWindow *win, paint_t *paint, sfClock **clock)
{
    sfRenderWindow_drawRectangleShape(win, paint->gray[0], NULL);
    sfRenderWindow_drawRectangleShape(win, paint->page, NULL);
    for (int i = 0; i < 5; i++) {
        if (paint->layers->visible[i] == true)
            sfRenderWindow_drawSprite(win, paint->sprite_buf[i], NULL);
    }
    sfRenderWindow_drawRectangleShape(win, paint->gray[2], NULL);
    for (int i = 0; i < 3; i++) {
        sfRenderWindow_drawRectangleShape(win, paint->header->hitbox[i], NULL);
        sfRenderWindow_drawText(win, paint->header->text[i], NULL);
    }
    check_scenes(paint, clock);
    check_toolbar_scenes(win, paint, clock);
    draw_name(paint);
}

void drawing_on_page(paint_t *paint, sfCircleShape *cursor,
    sfClock **clock)
{
    sfTime elapsed = sfClock_getElapsedTime(*clock);
    float f = sfTime_asSeconds(elapsed);

    if (my_hover_effect(paint->win, paint->page) == 1
        && (paint->scene->pencil == true || paint->scene->rubber == true) &&
        paint->scene->shader == false && paint->scene->exit == false &&
        paint->scene->menu[0] == false && paint->scene->menu[1] == false &&
        paint->scene->menu[2] == false && paint->scene->rename == false &&
        paint->scene->open == false && paint->scene->help == false &&
        paint->scene->about == false && paint->scene->shapes == false) {
        if (sfMouse_isButtonPressed(sfMouseLeft) && f > 0.2)
            update_my_framebuffer(paint->win, paint);
        put_my_mouse(&cursor, paint->win);
    }
}

static void display_image_two(paint_t *paint, int i, sfSprite *sprite,
    sfRectangleShape **page)
{
    sfSprite_setScale(sprite, (sfVector2f) {0.05, 0.05});
    sfSprite_setPosition(sprite, (sfVector2f) {1800, 600 - (i * 60)});
    sfRenderWindow_drawRectangleShape(paint->win,
        paint->layers->hover[i], NULL);
    sfRenderWindow_drawRectangleShape(paint->win,
        paint->layers->mask[i], NULL);
    sfRenderWindow_drawRectangleShape(paint->win, page[i], NULL);
    sfRenderWindow_drawSprite(paint->win, sprite, NULL);
    sfSprite_destroy(sprite);
}

void display_image(paint_t *paint, sfClock **clock)
{
    sfSprite *sprite;
    sfRectangleShape *page[5];
    sfVector2u size = sfImage_getSize(paint->image[0]);

    draw_layers(paint, clock);
    for (int i = 0; i < 5; i++) {
        sprite = sfSprite_copy(paint->sprite_buf[i]);
        page[i] = sfRectangleShape_create();
        sfRectangleShape_setFillColor(page[i], sfWhite);
        sfRectangleShape_setSize(page[i], (sfVector2f)
            {size.x * 0.05, size.y * 0.05});
        sfRectangleShape_setPosition(page[i], (sfVector2f) {1800, 600 -
            (i * 60)});
        display_image_two(paint, i, sprite, page);
    }
}

void my_paint_two(paint_t *paint, sfClock *clock, sfCircleShape *cursor)
{
    sfRenderWindow_clear(paint->win, sfWhite);
    switch_pencil_colors(paint->win, paint);
    hover_display(paint->win, paint, &clock);
    hover_shapes(paint->win, paint, &clock);
    hover_header(paint->win, paint, &clock);
    draw_scene(paint->win, paint, &clock);
    drawing_on_page(paint, cursor, &clock);
    display_image(paint, &clock);
    sfRenderWindow_display(paint->win);
}

void my_paint(sfEvent event, char *user)
{
    paint_t *paint = fill_structure(user);
    sfCircleShape *cursor = set_my_cursor();
    sfClock *clock = sfClock_create();

    paint->win = my_set_window("MyPaint", 1920, 1080, 32);
    sfRenderWindow_setFramerateLimit(paint->win, 60);
    paint->open = fill_open();
    while (sfRenderWindow_isOpen(paint->win)) {
        sfCircleShape_setRadius(cursor, paint->pen->size / 2);
        if (my_close_button(paint->win, &event) == 0)
            sfRenderWindow_close(paint->win);
        my_paint_two(paint, clock, cursor);
    }
    destroy_program(paint, &clock);
}
