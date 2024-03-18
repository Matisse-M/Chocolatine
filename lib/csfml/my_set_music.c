/*
** EPITECH PROJECT, 2023
** my_custom_rectangle
** File description:
** Customize a rectangle
*/

#include <SFML/Audio.h>

sfMusic *my_set_music(char *name, sfBool loop, float vol)
{
    sfMusic *music = sfMusic_createFromFile(name);

    sfMusic_setLoop(music, loop);
    sfMusic_setVolume(music, vol);
    return (music);
}
