/*
** EPITECH PROJECT, 2023
** my_set_sprite
** File description:
** Create a sprite
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>

sfText *my_set_text(char *str, int size, sfVector2f pos, sfFont *font)
{
    sfText *text = sfText_create();

    sfText_setFont(text, font);
    sfText_setCharacterSize(text, size);
    sfText_setPosition(text, pos);
    sfText_setString(text, str);
    return (text);
}
