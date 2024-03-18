/*
** EPITECH PROJECT, 2023
** main
** File description:
** main()
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/stat.h>
#include "paint.h"
#include "csfml.h"
#include "my.h"

static char *the_text(void)
{
    char *text = "MyPaint\n\n\
    MyPaint is a poorly executed imitation of Paint (a counterfeit)!\n\
    With this software, you can choose from various tools to manipulate\n\
    a file, such as a brush, eraser, or stamps. You can also rename your\n\
    file, open a new one, and, of course, save your work. Navigating this\n\
    software involves three menus:\n\
        - FILE: to create a new file, open a file, save your work, and\n\
        rename it.\n\
        - EDIT: to select your tool: brush, eraser, shapes.\n\
        - HELP: to access this menu and get information.";

    return text;
}

help_t *fill_help(void)
{
    help_t *help = malloc(sizeof(help_t));
    sfFont *font = sfFont_createFromFile("assets/font.ttf");
    char *text = the_text();

    help->shade = my_set_rectangle((sfVector2f) {1920, 1080},
        (sfVector2f) {0, 0});
    my_custom_rectangle(help->shade, 0, (sfColor) {0, 0, 0, 100},
        sfTransparent);
    help->bckgrnd = my_set_rectangle((sfVector2f) {1280, 720},
        (sfVector2f) {320, 200});
    my_custom_rectangle(help->bckgrnd, 1, (sfColor) {225, 225, 225, 255},
        sfBlack);
    help->text = my_set_text(text, 32, (sfVector2f) {420, 350}, font);
    sfText_setFillColor(help->text, sfBlack);
    return help;
}

void display_helper(paint_t *paint, sfClock **clock)
{
    float f = 0;
    sfTime elapsed = sfClock_getElapsedTime(*clock);

    f = sfTime_asSeconds(elapsed);
    if (sfKeyboard_isKeyPressed(sfKeyEscape) && f > 0.2) {
        paint->scene->help = false;
    }
    sfRenderWindow_drawRectangleShape(paint->win, paint->h->shade, NULL);
    sfRenderWindow_drawRectangleShape(paint->win, paint->h->bckgrnd, NULL);
    sfRenderWindow_drawText(paint->win, paint->h->text, NULL);
}
