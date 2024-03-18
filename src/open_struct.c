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

static void crete_arrows(open_t *open)
{
    sfTexture *up = sfTexture_createFromFile("assets/up.png", NULL);
    sfTexture *down = sfTexture_createFromFile("assets/down.png", NULL);

    open->arrow = malloc(sizeof(sfRectangleShape *) * 2);
    open->arrow[0] = sfRectangleShape_create();
    sfRectangleShape_setTexture(open->arrow[0], up, sfFalse);
    sfRectangleShape_setSize(open->arrow[0], (sfVector2f) {80, 80});
    sfRectangleShape_setPosition(open->arrow[0], (sfVector2f) {930, 830});
    open->arrow[1] = sfRectangleShape_create();
    sfRectangleShape_setTexture(open->arrow[1], down, sfFalse);
    sfRectangleShape_setSize(open->arrow[1], (sfVector2f) {80, 80});
    sfRectangleShape_setPosition(open->arrow[1], (sfVector2f) {930, 275});
}

open_t *fill_open(void)
{
    open_t *open = malloc(sizeof(open_t));
    sfFont *font = sfFont_createFromFile("assets/font.ttf");

    open->page = 0;
    open->shade = my_set_rectangle((sfVector2f) {1920, 1080},
        (sfVector2f) {0, 0});
    my_custom_rectangle(open->shade, 0, (sfColor) {0, 0, 0, 100},
        sfTransparent);
    open->bckgrnd = my_set_rectangle((sfVector2f) {1280, 720},
        (sfVector2f) {320, 200});
    my_custom_rectangle(open->bckgrnd, 1, (sfColor) {225, 225, 225, 255},
        sfBlack);
    open->select = my_set_text("Select your file:", 28,
        (sfVector2f) {330, 210}, font);
    sfText_setFillColor(open->select, sfBlack);
    open->warning = my_set_text("All changes will be permanently lost", 20,
        (sfVector2f) {330, 255}, font);
    sfText_setFillColor(open->warning, sfRed);
    crete_arrows(open);
    return open;
}
