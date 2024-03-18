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

static void draw_menu_two(sfRenderWindow *win, paint_t *paint, sfClock **clock)
{
    for (int i = 0; i < 8; i++) {
        duck_condition(paint->colo->basic_colors[i], paint);
        sfRenderWindow_drawRectangleShape(win, paint->colo->basic_colors[i],
            NULL);
    }
    for (int i = 0; i < 24; i++) {
        duck_condition(paint->colo->history_colors[i], paint);
        sfRenderWindow_drawRectangleShape(win, paint->colo->history_colors[i],
            NULL);
    }
}

void draw_shapes_menu(sfRenderWindow *win, paint_t *paint, sfClock **clock)
{
    sfRenderWindow_drawRectangleShape(win, paint->gray[1], NULL);
    draw_menu_two(win, paint, clock);
    sfRenderWindow_drawRectangleShape(win, paint->colo->area_pip, NULL);
    sfRenderWindow_drawRectangleShape(win, paint->size_pen->bar, NULL);
    draw_slidebar(paint);
    sfText_setString(paint->size_pen->text, my_itoa(paint->pen->size));
    sfRenderWindow_drawText(win, paint->size_pen->text, NULL);
    sfRenderWindow_drawCircleShape(win, paint->size_pen->btn, NULL);
    sfRenderWindow_drawRectangleShape(win, paint->size_pen->area, NULL);
    sfRenderWindow_drawSprite(win, paint->colo->sprite_pip, NULL);
    sfRenderWindow_drawRectangleShape(win, paint->area_shape, NULL);
    sfRenderWindow_drawSprite(win, paint->shape, NULL);
    put_shape(paint, clock);
}

void draw_pencil_menu(sfRenderWindow *win, paint_t *paint)
{
    sfRenderWindow_drawRectangleShape(win, paint->gray[1], NULL);
    for (int i = 0; i < 8; i++) {
        duck_condition(paint->colo->basic_colors[i], paint);
        sfRenderWindow_drawRectangleShape(win, paint->colo->basic_colors[i],
            NULL);
    }
    for (int i = 0; i < 24; i++) {
        duck_condition(paint->colo->history_colors[i], paint);
        sfRenderWindow_drawRectangleShape(win, paint->colo->history_colors[i],
            NULL);
    }
    sfRenderWindow_drawRectangleShape(win, paint->colo->area_pip, NULL);
    sfRenderWindow_drawRectangleShape(win, paint->size_pen->bar, NULL);
    draw_slidebar(paint);
    sfText_setString(paint->size_pen->text, my_itoa(paint->pen->size));
    sfRenderWindow_drawText(win, paint->size_pen->text, NULL);
    sfRenderWindow_drawCircleShape(win, paint->size_pen->btn, NULL);
    sfRenderWindow_drawRectangleShape(win, paint->size_pen->area, NULL);
    sfRenderWindow_drawSprite(win, paint->colo->sprite_pip, NULL);
}

void find_extension(paint_t *paint)
{
    if (paint->name[my_strlen(paint->name) - 1] == 'g' &&
        paint->name[my_strlen(paint->name) - 2] == 'p' &&
        paint->name[my_strlen(paint->name) - 3] == 'j')
        paint->pen->color = sfWhite;
    if (paint->name[my_strlen(paint->name) - 1] == 'g' &&
        paint->name[my_strlen(paint->name) - 2] == 'n' &&
        paint->name[my_strlen(paint->name) - 3] == 'p')
        paint->pen->color = sfTransparent;
    if (paint->name[my_strlen(paint->name) - 1] == 'p' &&
        paint->name[my_strlen(paint->name) - 2] == 'm' &&
        paint->name[my_strlen(paint->name) - 3] == 'b')
        paint->pen->color = sfWhite;
}

void draw_rubber_menu(sfRenderWindow *win, paint_t *paint)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(paint->win);
    sfVector2f ha;

    find_extension(paint);
    if (my_hover_effect(paint->win, paint->size_rub->area) == 1 &&
        sfMouse_isButtonPressed(sfMouseLeft)
        && pos.x >= 700 && pos.x <= 1300) {
        sfCircleShape_setPosition(paint->size_rub->btn,
            (sfVector2f) {pos.x - 15, 55});
        sfRectangleShape_setPosition(paint->size_rub->area,
            (sfVector2f) {pos.x - 15, 55});
    }
    ha = sfCircleShape_getPosition(paint->size_rub->btn);
    paint->pen->size = 3 + ((ha.x - 684) / 2000) * (2000 - 684);
    sfRenderWindow_drawRectangleShape(win, paint->gray[1], NULL);
    sfRenderWindow_drawRectangleShape(win, paint->size_rub->bar, NULL);
    sfText_setString(paint->size_rub->text, my_itoa(paint->pen->size));
    sfRenderWindow_drawText(win, paint->size_rub->text, NULL);
    sfRenderWindow_drawCircleShape(win, paint->size_rub->btn, NULL);
}

static void scene_check(paint_t *paint, sfClock **clock)
{
    if (paint->scene->shader == true)
        draw_shader(paint, clock);
    if (paint->scene->which_s == true)
        draw_shapes(paint, clock);
    if (paint->scene->exit == true)
        draw_exit_menu(&restart_image_jpg, paint);
    if (paint->scene->rename == true)
        draw_rename(paint, clock);
    if (paint->scene->open == true || paint->scene->import == true)
        draw_open(paint, clock);
    if (paint->scene->help == true)
        display_helper(paint, clock);
    if (paint->scene->about == true)
        display_about(paint, clock);
}

void check_scenes(paint_t *paint, sfClock **clock)
{
    if (paint->scene->pencil == true) {
        draw_pencil_menu(paint->win, paint);
        paint->scene->rubber = false;
        paint->scene->shapes = false;
    }
    if (paint->scene->rubber == true) {
        draw_rubber_menu(paint->win, paint);
        paint->scene->pencil = false;
        paint->scene->shapes = false;
    }
    if (paint->scene->shapes == true) {
        draw_shapes_menu(paint->win, paint, clock);
        paint->scene->pencil = false;
        paint->scene->rubber = false;
    }
    scene_check(paint, clock);
}
