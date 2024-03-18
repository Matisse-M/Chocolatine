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

static void set_rects(rename_t *name)
{
    sfColor grey = {225, 225, 225, 255};

    name->shade = my_set_rectangle((sfVector2f) {1920, 1080},
        (sfVector2f) {0, 0});
    my_custom_rectangle(name->shade, 0, (sfColor) {0, 0, 0, 100},
        sfTransparent);
    name->bckgrnd = my_set_rectangle((sfVector2f) {800, 150},
        (sfVector2f) {560, 200});
    my_custom_rectangle(name->bckgrnd, 1, grey, sfBlack);
    name->bar = my_set_rectangle((sfVector2f) {650, 40},
        (sfVector2f) {560, 310});
    my_custom_rectangle(name->bar, 1, sfWhite, sfBlack);
    name->ext = my_set_rectangle((sfVector2f) {150, 40},
        (sfVector2f) {1210, 310});
    my_custom_rectangle(name->ext, 1, grey, sfBlack);
}

static void set_texts(rename_t *name)
{
    sfFont *font = sfFont_createFromFile("assets/font.ttf");

    name->message = my_set_text("Select your filename:", 28,
        (sfVector2f) {580, 215}, font);
    sfText_setFillColor(name->message, sfBlack);
    name->alert = my_set_text(
    "If you change the file extension, all changes will be permanently lost!",
        20, (sfVector2f) {580, 270}, font);
    sfText_setFillColor(name->alert, sfRed);
    name->end = my_set_text(".jpg", 28, (sfVector2f) {1260, 310}, font);
    sfText_setFillColor(name->end, sfBlack);
    name->null = my_set_text("Enter your filename", 16,
        (sfVector2f) {580, 320}, font);
    sfText_setFillColor(name->null, (sfColor) {200, 200, 200, 255});
    name->render = my_set_text(" ", 28, (sfVector2f) {580, 310}, font);
    sfText_setFillColor(name->render, sfBlack);
}

static void buttons_loop(rename_t *name)
{
    sfFont *font = sfFont_createFromFile("assets/font.ttf");
    sfColor grey = {225, 225, 225, 255};
    char *text[3] = {".jpg", ".bmp", ".png"};

    for (int i = 0; i < 3; i++) {
        name->btn_ext[i] = my_set_rectangle((sfVector2f) {150, 40},
            (sfVector2f) {1210, 351 + (i * 40)});
        my_custom_rectangle(name->btn_ext[i], 1, grey, sfBlack);
        name->list_ext[i] = my_set_text(text[i], 28, (sfVector2f)
            {1260, 350 + (i * 40)}, font);
        sfText_setFillColor(name->list_ext[i], sfBlack);
    }
}

rename_t *fill_rename(void)
{
    rename_t *name = malloc(sizeof(rename_t));

    name->write = false;
    name->extension = false;
    name->nb = 0;
    name->filename = NULL;
    set_rects(name);
    set_texts(name);
    name->btn_ext = malloc(sizeof(sfRectangleShape *) * 3);
    name->list_ext = malloc(sizeof(sfText *) * 3);
    buttons_loop(name);
    return name;
}

static void double_click(paint_t *paint, sfClock **clock, float f)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) &&
        paint->rename->extension == false && f > 0.2) {
        paint->rename->extension = true;
        sfClock_restart(*clock);
    } else if (sfMouse_isButtonPressed(sfMouseLeft) &&
        paint->rename->extension == true && f > 0.2) {
        paint->rename->extension = false;
        sfClock_restart(*clock);
    }
}

static void hover_ext(paint_t *paint, sfClock **clock, float f)
{
    if (my_hover_effect(paint->win, paint->rename->ext) == 1) {
        double_click(paint, clock, f);
        sfRectangleShape_setFillColor(paint->rename->ext,
            (sfColor) {200, 200, 200, 255});
    } else {
        sfRectangleShape_setFillColor(paint->rename->ext,
            (sfColor) {225, 225, 225, 255});
    }
}

static void button_extension(paint_t *paint, sfClock **clock, float f, int i)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) && f > 0.2 && i == 0) {
        sfText_setString(paint->rename->end, ".jpg");
        sfClock_restart(*clock);
        paint->rename->extension = false;
    }
    if (sfMouse_isButtonPressed(sfMouseLeft) && f > 0.2 && i == 1) {
        sfText_setString(paint->rename->end, ".bmp");
        sfClock_restart(*clock);
        paint->rename->extension = false;
    }
    if (sfMouse_isButtonPressed(sfMouseLeft) && f > 0.2 && i == 2) {
        sfText_setString(paint->rename->end, ".png");
        restart_image_png(paint);
        sfClock_restart(*clock);
        paint->rename->extension = false;
    }
}

static void menu_extension(paint_t *paint, sfClock **clock, float f)
{
    for (int i = 0; i < 3; i++) {
        sfRenderWindow_drawRectangleShape(paint->win,
            paint->rename->btn_ext[i], NULL);
        sfRenderWindow_drawText(paint->win, paint->rename->list_ext[i], NULL);
        if (my_hover_effect(paint->win, paint->rename->btn_ext[i]) == 1) {
            button_extension(paint, clock, f, i);
            sfRectangleShape_setFillColor(paint->rename->btn_ext[i],
                (sfColor) {200, 200, 200, 255});
        } else {
            sfRectangleShape_setFillColor(paint->rename->btn_ext[i],
                (sfColor) {225, 225, 225, 255});
        }
    }
}

static void rename_menu_conditions(paint_t *paint, sfClock **clock, float f)
{
    if (paint->rename->write == true)
        my_put_alphabet(paint, clock, f);
    if (my_hover_effect(paint->win, paint->rename->bar) == 1 &&
        sfMouse_isButtonPressed(sfMouseLeft) && f > 0.2) {
        paint->rename->write = true;
        sfClock_restart(*clock);
    }
    hover_ext(paint, clock, f);
    if (my_hover_effect(paint->win, paint->rename->bar) == 0 &&
        sfMouse_isButtonPressed(sfMouseLeft) && f > 0.2) {
        paint->rename->write = false;
        sfClock_restart(*clock);
    }
    if (paint->rename->write == false && paint->rename->nb == 0)
        sfRenderWindow_drawText(paint->win, paint->rename->null, NULL);
    if (paint->rename->nb > 0)
        sfRenderWindow_drawText(paint->win, paint->rename->render, NULL);
    if (paint->rename->extension == true) {
        menu_extension(paint, clock, f);
    }
}

void draw_rename(paint_t *paint, sfClock **clock)
{
    sfTime elapsed = sfClock_getElapsedTime(*clock);
    float f = sfTime_asSeconds(elapsed);

    paint->scene->menu[0] = false;
    enter_character(paint, clock, f);
    sfRenderWindow_drawRectangleShape(paint->win, paint->rename->shade, NULL);
    sfRenderWindow_drawRectangleShape(paint->win,
        paint->rename->bckgrnd, NULL);
    sfRenderWindow_drawRectangleShape(paint->win, paint->rename->bar, NULL);
    sfRenderWindow_drawRectangleShape(paint->win, paint->rename->ext, NULL);
    sfRenderWindow_drawText(paint->win, paint->rename->message, NULL);
    sfRenderWindow_drawText(paint->win, paint->rename->alert, NULL);
    sfRenderWindow_drawText(paint->win, paint->rename->end, NULL);
    rename_menu_conditions(paint, clock, f);
}
