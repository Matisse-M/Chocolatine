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

static void create_header_buttons(header_t *head)
{
    sfFont *font = sfFont_createFromFile("assets/font.ttf");

    for (int i = 0; i < 3; i++) {
        head->text[i] = sfText_create();
        head->hitbox[i] = sfRectangleShape_create();
        sfText_setFont(head->text[i], font);
        sfText_setCharacterSize(head->text[i], 25);
        sfText_setColor(head->text[i], sfBlack);
        sfRectangleShape_setSize(head->hitbox[i], (sfVector2f) {75, 30});
        sfRectangleShape_setFillColor(head->hitbox[i], sfTransparent);
        sfText_setPosition(head->text[i], (sfVector2f) {10 + i * 75, 0});
        sfRectangleShape_setPosition(head->hitbox[i],
            (sfVector2f) {i * 75, 0});
    }
    sfFont_destroy(font);
}

static header_t *set_header(void)
{
    header_t *head = malloc(sizeof(header_t));
    sfFont *font = sfFont_createFromFile("assets/font.ttf");

    head->text = malloc(sizeof(sfText *) * 3);
    head->hitbox = malloc(sizeof(sfRectangleShape *) * 3);
    create_header_buttons(head);
    sfText_setString(head->text[0], "FILE");
    sfText_setString(head->text[1], "EDIT");
    sfText_setString(head->text[2], "HELP");
    sfFont_destroy(font);
    return head;
}

static void create_file_buttons(menu_t *menu)
{
    sfFont *font = sfFont_createFromFile("assets/font.ttf");

    for (int i = 0; i < 4; i++) {
        menu->text[i] = sfText_create();
        menu->hitbox[i] = sfRectangleShape_create();
        sfText_setFont(menu->text[i], font);
        sfText_setCharacterSize(menu->text[i], 16);
        sfText_setColor(menu->text[i], sfBlack);
        sfRectangleShape_setSize(menu->hitbox[i], (sfVector2f) {149, 32});
        sfRectangleShape_setFillColor(menu->hitbox[i], sfTransparent);
        sfRectangleShape_setOutlineThickness(menu->hitbox[i], 1);
        sfRectangleShape_setOutlineColor(menu->hitbox[i], sfBlack);
        sfText_setPosition(menu->text[i], (sfVector2f) {10, 38 + i * 33});
        sfRectangleShape_setPosition(menu->hitbox[i],
            (sfVector2f) {0, 31 + i * 33});
    }
    sfFont_destroy(font);
}

static void create_edit_buttons(menu_t *menu)
{
    sfFont *font = sfFont_createFromFile("assets/font.ttf");

    for (int i = 0; i < 4; i++) {
        menu->text[i] = sfText_create();
        menu->hitbox[i] = sfRectangleShape_create();
        sfText_setFont(menu->text[i], font);
        sfText_setCharacterSize(menu->text[i], 16);
        sfText_setColor(menu->text[i], sfBlack);
        sfRectangleShape_setSize(menu->hitbox[i], (sfVector2f) {149, 32});
        sfRectangleShape_setFillColor(menu->hitbox[i], sfTransparent);
        sfRectangleShape_setOutlineThickness(menu->hitbox[i], 1);
        sfRectangleShape_setOutlineColor(menu->hitbox[i], sfBlack);
        sfText_setPosition(menu->text[i], (sfVector2f) {86, 38 + i * 33});
        sfRectangleShape_setPosition(menu->hitbox[i],
            (sfVector2f) {76, 31 + i * 33});
    }
    sfFont_destroy(font);
}

static void create_help_buttons(menu_t *menu)
{
    sfFont *font = sfFont_createFromFile("assets/font.ttf");

    for (int i = 0; i < 2; i++) {
        menu->text[i] = sfText_create();
        menu->hitbox[i] = sfRectangleShape_create();
        sfText_setFont(menu->text[i], font);
        sfText_setCharacterSize(menu->text[i], 16);
        sfText_setColor(menu->text[i], sfBlack);
        sfRectangleShape_setSize(menu->hitbox[i], (sfVector2f) {149, 32});
        sfRectangleShape_setFillColor(menu->hitbox[i], sfTransparent);
        sfRectangleShape_setOutlineThickness(menu->hitbox[i], 1);
        sfRectangleShape_setOutlineColor(menu->hitbox[i], sfBlack);
        sfText_setPosition(menu->text[i], (sfVector2f) {161, 38 + i * 33});
        sfRectangleShape_setPosition(menu->hitbox[i],
            (sfVector2f) {151, 31 + i * 33});
    }
    sfFont_destroy(font);
}

static menu_t *fill_file_menu(void)
{
    menu_t *menu = malloc(sizeof(menu_t));

    menu->text = malloc(sizeof(sfText *) * 4);
    menu->hitbox = malloc(sizeof(sfRectangleShape *) * 4);
    create_file_buttons(menu);
    sfText_setString(menu->text[0], "New file");
    sfText_setString(menu->text[1], "Open file");
    sfText_setString(menu->text[2], "Save file");
    sfText_setString(menu->text[3], "Rename file");
    return menu;
}

static menu_t *fill_edit_menu(void)
{
    menu_t *menu = malloc(sizeof(menu_t));

    menu->text = malloc(sizeof(sfText *) * 4);
    menu->hitbox = malloc(sizeof(sfRectangleShape *) * 4);
    create_edit_buttons(menu);
    sfText_setString(menu->text[0], "Pencil");
    sfText_setString(menu->text[1], "Eraser");
    sfText_setString(menu->text[2], "Shapes");
    sfText_setString(menu->text[3], "Import");
    return menu;
}

static menu_t *fill_help_menu(void)
{
    menu_t *menu = malloc(sizeof(menu_t));

    menu->text = malloc(sizeof(sfText *) * 2);
    menu->hitbox = malloc(sizeof(sfRectangleShape *) * 2);
    create_help_buttons(menu);
    sfText_setString(menu->text[0], "About");
    sfText_setString(menu->text[1], "Help");
    return menu;
}

void set_toolbar(paint_t *paint, char *user)
{
    paint->header = set_header();
    paint->scene = malloc(sizeof(scene_t));
    paint->scene->shader = false;
    paint->scene->pencil = false;
    paint->scene->open = false;
    paint->scene->exit = false;
    paint->scene->rename = false;
    paint->scene->rubber = false;
    paint->scene->about = false;
    paint->scene->help = false;
    paint->scene->import = false;
    paint->scene->which_s = false;
    paint->scene->menu = malloc(sizeof(bool) * 3);
    paint->scene->menu[0] = false;
    paint->scene->menu[1] = false;
    paint->scene->menu[2] = false;
    paint->file = fill_file_menu();
    paint->edit = fill_edit_menu();
    paint->help = fill_help_menu();
    paint->login = user;
}

void draw_name(paint_t *paint)
{
    sfFont *font = sfFont_createFromFile("assets/font.ttf");
    sfText *name = my_set_text(paint->name, 15,
        (sfVector2f) {960 - ((my_strlen(paint->name) / 2) * 15), 5}, font);

    sfText_setFillColor(name, sfBlack);
    sfRenderWindow_drawText(paint->win, name, NULL);
    sfText_destroy(name);
    sfFont_destroy(font);
}
