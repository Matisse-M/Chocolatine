/*
** EPITECH PROJECT, 2023
** my_set_window
** File description:
** Create a window
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>

sfRenderWindow *my_set_window(char *title, unsigned int width,
    unsigned int height, unsigned int bits)
{
    sfVideoMode video = {width, height, 32};
    sfRenderWindow *window = sfRenderWindow_create(video, title,
        sfResize | sfClose, NULL);

    return (window);
}
