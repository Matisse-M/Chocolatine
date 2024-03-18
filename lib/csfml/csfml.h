/*
** EPITECH PROJECT, 2023
** my_custom_rectangle
** File description:
** Customize a rectangle
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>

#pragma once

typedef struct framebuffer_s {
    unsigned int height;
    unsigned int width;
    sfUint8 *pixels;
} framebuffer_t;


framebuffer_t *framebuffer_create(unsigned int width, unsigned int height);
sfRenderWindow *my_set_window(char *title, unsigned int width,
    unsigned int height, unsigned int bits);
sfSprite *my_set_sprite(sfTexture *texture, sfVector2f pos, sfVector2f size);
sfRectangleShape *my_set_rectangle(sfVector2f size, sfVector2f pos);
sfMusic *my_set_music(char *name, sfBool loop, float vol);
sfText *my_set_text(char *str, int size, sfVector2f pos, sfFont *font);
sfCircleShape *my_set_circle(float radius, sfVector2f pos, sfColor color);

int my_close_button(sfRenderWindow *window, sfEvent *event);
int my_hover_effect(sfRenderWindow *window, sfRectangleShape *rect);

void my_put_pixel(framebuffer_t *framebuffer, unsigned x, unsigned y,
    sfColor color);
void framebuffer_destroy(framebuffer_t *framebuffer);
void my_custom_rectangle(sfRectangleShape *rect, float thickness,
    sfColor color, sfColor outline_color);
void my_custom_text(sfText *text, float thickness, sfColor color,
    sfColor outline_color);
void draw_square(framebuffer_t *framebuffer, sfVector2i position,
    unsigned int size, sfColor color);
void draw_horizontal_line(framebuffer_t *framebuffer, sfVector2i position,
    unsigned int size, sfColor color);
