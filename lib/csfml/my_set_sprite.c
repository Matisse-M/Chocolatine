/*
** EPITECH PROJECT, 2023
** my_set_sprite
** File description:
** Create a sprite
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>

sfSprite *my_set_sprite(sfTexture *texture, sfVector2f pos, sfVector2f size)
{
    sfSprite *sprite = sfSprite_create();

    sfSprite_setPosition(sprite, pos);
    sfSprite_setScale(sprite, size);
    sfSprite_setTexture(sprite, texture, sfTrue);
    return (sprite);
}
