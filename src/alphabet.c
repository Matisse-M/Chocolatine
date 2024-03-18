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

static void del_character(paint_t *paint, sfClock **clock, float f)
{
    char *new = NULL;

    if (paint->rename->filename == NULL)
        return;
    if (sfKeyboard_isKeyPressed(sfKeyBack) && f > 0.2) {
        new = malloc(sizeof(char) * my_strlen(paint->rename->filename));
        for (int i = 0; i < my_strlen(paint->rename->filename) - 1; i++)
            new[i] = paint->rename->filename[i];
        new[my_strlen(paint->rename->filename) - 1] = '\0';
        if (new[0] != '\0')
            paint->rename->filename = my_strdup(new);
        else
            paint->rename->filename = NULL;
        free(new);
        sfText_setString(paint->rename->render, paint->rename->filename);
        paint->rename->nb--;
        sfClock_restart(*clock);
        return;
    }
}

void enter_character(paint_t *paint, sfClock **clock, float f)
{
    if (sfKeyboard_isKeyPressed(sfKeyEnter) && f > 0.2) {
        if (paint->rename->filename == NULL) {
            paint->scene->rename = false;
            return;
        }
        paint->name = my_cat(paint->rename->filename,
            sfText_getString(paint->rename->end));
        paint->rename->filename = NULL;
        paint->rename->nb = 0;
        paint->rename->write = false;
        paint->scene->rename = false;
        sfClock_restart(*clock);
    }
}

void update_filename(paint_t *paint, sfClock **clock, char c)
{
    if (paint->rename->nb < 25) {
        paint->rename->filename = my_realloc(paint->rename->filename, 1);
        paint->rename->filename[paint->rename->nb] = c;
        sfText_setString(paint->rename->render, paint->rename->filename);
        paint->rename->nb++;
        sfClock_restart(*clock);
    }
}

static void put_char(paint_t *paint, sfClock **clock, float f)
{
    if (sfKeyboard_isKeyPressed(sfKeySpace) && f > 0.15)
        update_filename(paint, clock, ' ');
    if (sfKeyboard_isKeyPressed(sfKeySlash) &&
        sfKeyboard_isKeyPressed(sfKeyRShift) && f > 0.15)
        update_filename(paint, clock, '/');
    if (sfKeyboard_isKeyPressed(sfKeyNum6) &&
        !sfKeyboard_isKeyPressed(sfKeyRAlt) &&
        !sfKeyboard_isKeyPressed(sfKeyRShift) && f > 0.15)
        update_filename(paint, clock, '-');
    if (sfKeyboard_isKeyPressed(sfKeyNum8) &&
        !sfKeyboard_isKeyPressed(sfKeyRAlt) &&
        !sfKeyboard_isKeyPressed(sfKeyRShift) && f > 0.15)
        update_filename(paint, clock, '_');
    if (sfKeyboard_isKeyPressed(sfKeySemiColon) &&
        !sfKeyboard_isKeyPressed(sfKeyRShift) && f > 0.15)
        update_filename(paint, clock, ';');
    if (sfKeyboard_isKeyPressed(sfKeySemiColon) &&
        sfKeyboard_isKeyPressed(sfKeyRShift) && f > 0.15)
        update_filename(paint, clock, '.');
}

void my_put_alphabet(paint_t *paint, sfClock **clock, float f)
{
    my_alpha(paint, clock, f);
    my_num(paint, clock, f);
    my_alpha_maj(paint, clock, f);
    put_char(paint, clock, f);
    del_character(paint, clock, f);
    enter_character(paint, clock, f);
}
