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

static void set_rolls(div_shaders_t *shader, sfColor color, sfColor *rgba,
    sfFont *font)
{
    for (int i = 0; i < 4; i++) {
        shader->bars[i] = my_set_rectangle((sfVector2f) {250, 20},
            (sfVector2f) {820, 137 + (45 * i)});
        shader->ball[i] = my_set_circle(15, (sfVector2f)
            {830, 132 + (45 * i)}, color);
        shader->col[i] = my_set_rectangle((sfVector2f) {20, 20},
            (sfVector2f) {1101, 137 + (45 * i)});
        shader->hitbox[i] = my_set_rectangle((sfVector2f) {30, 30},
            (sfVector2f) {830, 132 + (45 * i)});
        shader->text[i] = my_set_text("0", 32, (sfVector2f)
            {1136, 127 + (45 * i)}, font);
        sfText_setFillColor(shader->text[i], sfBlack);
        sfCircleShape_setOutlineColor(shader->ball[i], sfBlack);
        sfCircleShape_setOutlineThickness(shader->ball[i], 1);
        my_custom_rectangle(shader->bars[i], 1, sfWhite, sfBlack);
        my_custom_rectangle(shader->col[i], 1, rgba[i], sfBlack);
        my_custom_rectangle(shader->hitbox[i], 2, sfTransparent,
            sfTransparent);
    }
}

static void set_background(div_shaders_t *shader, sfColor color, sfFont *font)
{
    shader->bckgrnd = my_set_rectangle((sfVector2f) {450, 200},
        (sfVector2f) {780, 117});
    my_custom_rectangle(shader->bckgrnd, 1, color, sfBlack);
    shader->display = my_set_rectangle((sfVector2f) {450, 30},
        (sfVector2f) {780, 318});
    my_custom_rectangle(shader->display, 1, color, sfBlack);
    shader->okay = my_set_rectangle((sfVector2f) {450, 30},
        (sfVector2f) {780, 349});
    my_custom_rectangle(shader->okay, 1, color, sfBlack);
    shader->validate = my_set_text("VALIDATE", 20,
        (sfVector2f) {950, 352}, font);
}

div_shaders_t *fill_shader(void)
{
    div_shaders_t *shader = malloc(sizeof(div_shaders_t));
    sfColor color = {225, 225, 225, 255};
    sfColor rgba[4] = {sfRed, sfGreen, sfBlue, sfTransparent};
    sfFont *font = sfFont_createFromFile("assets/font.ttf");

    set_background(shader, color, font);
    sfText_setFillColor(shader->validate, sfBlack);
    shader->color = (sfColor) {0, 0, 0, 255};
    shader->bars = malloc(sizeof(sfRectangleShape *) * 4);
    shader->ball = malloc(sizeof(sfCircleShape *) * 4);
    shader->col = malloc(sizeof(sfRectangleShape *) * 4);
    shader->hitbox = malloc(sizeof(sfRectangleShape *) * 4);
    shader->text = malloc(sizeof(sfText *) * 4);
    set_rolls(shader, color, rgba, font);
    return shader;
}

static void draw_redbar(paint_t *paint)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(paint->win);
    sfVector2f ha;

    if (my_hover_effect(paint->win, paint->shader->hitbox[0]) == 1 &&
        sfMouse_isButtonPressed(sfMouseLeft)
        && pos.x >= 815.5 && pos.x <= 1079.5) {
        sfCircleShape_setPosition(paint->shader->ball[0],
            (sfVector2f) {pos.x - 15, 132});
        sfRectangleShape_setPosition(paint->shader->hitbox[0],
            (sfVector2f) {pos.x - 15, 132});
    }
    ha = sfCircleShape_getPosition(paint->shader->ball[0]);
    sfText_setString(paint->shader->text[0], my_itoa(((ha.x + 15 - 815.5) /
        25500) * (25500 - 815.5)));
    paint->shader->color.r = ((ha.x + 15 - 815.5) / 25500) * (25500 - 815.5);
}

static void draw_greebar(paint_t *paint)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(paint->win);
    sfVector2f ha;

    if (my_hover_effect(paint->win, paint->shader->hitbox[1]) == 1 &&
        sfMouse_isButtonPressed(sfMouseLeft)
        && pos.x >= 815.5 && pos.x <= 1079.5) {
        sfCircleShape_setPosition(paint->shader->ball[1],
            (sfVector2f) {pos.x - 15, 177});
        sfRectangleShape_setPosition(paint->shader->hitbox[1],
            (sfVector2f) {pos.x - 15, 177});
    }
    ha = sfCircleShape_getPosition(paint->shader->ball[1]);
    sfText_setString(paint->shader->text[1], my_itoa(((ha.x + 15 - 815.5) /
        25500) * (25500 - 815.5)));
    paint->shader->color.g = ((ha.x + 15 - 815.5) / 25500) * (25500 - 815.5);
}

static void draw_bluebar(paint_t *paint)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(paint->win);
    sfVector2f ha;

    if (my_hover_effect(paint->win, paint->shader->hitbox[2]) == 1 &&
        sfMouse_isButtonPressed(sfMouseLeft)
        && pos.x >= 815.5 && pos.x <= 1079.5) {
        sfCircleShape_setPosition(paint->shader->ball[2],
            (sfVector2f) {pos.x - 15, 222});
        sfRectangleShape_setPosition(paint->shader->hitbox[2],
            (sfVector2f) {pos.x - 15, 222});
    }
    ha = sfCircleShape_getPosition(paint->shader->ball[2]);
    sfText_setString(paint->shader->text[2], my_itoa(((ha.x + 15 - 815.5) /
        25500) * (25500 - 815.5)));
    paint->shader->color.b = ((ha.x + 15 - 815.5) / 25500) * (25500 - 815.5);
}

static void draw_transbar(paint_t *paint)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(paint->win);
    sfVector2f ha;

    if (my_hover_effect(paint->win, paint->shader->hitbox[3]) == 1 &&
        sfMouse_isButtonPressed(sfMouseLeft)
        && pos.x >= 815.5 && pos.x <= 1079.5) {
        sfCircleShape_setPosition(paint->shader->ball[3],
            (sfVector2f) {pos.x - 15, 267});
        sfRectangleShape_setPosition(paint->shader->hitbox[3],
            (sfVector2f) {pos.x - 15, 267});
    }
    ha = sfCircleShape_getPosition(paint->shader->ball[3]);
    sfText_setString(paint->shader->text[3], my_itoa(((ha.x + 15 - 815.5) /
        25500) * (25500 - 815.5)));
    paint->shader->color.a = ((ha.x + 15 - 815.5) / 25500) * (25500 - 815.5);
}

static void hover_validate(paint_t *paint, sfClock **clock)
{
    sfColor color = {225, 225, 225, 255};
    sfColor hover = {200, 200, 200, 255};
    sfTime elapsed = sfClock_getElapsedTime(*clock);
    float f = sfTime_asSeconds(elapsed);

    if (my_hover_effect(paint->win, paint->shader->okay) == 1) {
        if (sfMouse_isButtonPressed(sfMouseLeft) && f > 0.2) {
            sfRectangleShape_setFillColor(
                paint->colo->history_colors[paint->nb_color],
                paint->shader->color);
            paint->nb_color++;
            sfClock_restart(*clock);
            paint->scene->shader = false;
        }
        sfRectangleShape_setFillColor(paint->shader->okay, hover);
    } else {
        sfRectangleShape_setFillColor(paint->shader->okay, color);
    }
}

static void draw_bars(paint_t *paint)
{
    for (int i = 0; i < 4; i++) {
        sfRenderWindow_drawRectangleShape(paint->win,
            paint->shader->bars[i], NULL);
        sfRenderWindow_drawCircleShape(paint->win,
            paint->shader->ball[i], NULL);
        sfRenderWindow_drawRectangleShape(paint->win,
            paint->shader->col[i], NULL);
        sfRenderWindow_drawRectangleShape(paint->win, paint->shader->hitbox[i],
            NULL);
        sfRenderWindow_drawText(paint->win, paint->shader->text[i], NULL);
    }
}

void draw_shader(paint_t *paint, sfClock **clock)
{
    draw_redbar(paint);
    draw_greebar(paint);
    draw_bluebar(paint);
    draw_transbar(paint);
    hover_validate(paint, clock);
    if (paint->nb_color > 24)
        paint->nb_color = 0;
    sfRenderWindow_drawRectangleShape(paint->win, paint->shader->bckgrnd,
        NULL);
    draw_bars(paint);
    sfRectangleShape_setFillColor(paint->shader->display,
        paint->shader->color);
    sfRenderWindow_drawRectangleShape(paint->win, paint->shader->display,
        NULL);
    sfRenderWindow_drawRectangleShape(paint->win, paint->shader->okay, NULL);
    sfRenderWindow_drawText(paint->win, paint->shader->validate, NULL);
}
