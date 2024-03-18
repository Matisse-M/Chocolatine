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

static void put_alpha1(paint_t *paint, sfClock **clock, float f)
{
    if (sfKeyboard_isKeyPressed(sfKeyA) &&
        !sfKeyboard_isKeyPressed(sfKeyRShift) && f > 0.15)
        update_filename(paint, clock, 'a');
    if (sfKeyboard_isKeyPressed(sfKeyB) &&
        !sfKeyboard_isKeyPressed(sfKeyRShift) && f > 0.15)
        update_filename(paint, clock, 'b');
    if (sfKeyboard_isKeyPressed(sfKeyC) &&
        !sfKeyboard_isKeyPressed(sfKeyRShift) && f > 0.15)
        update_filename(paint, clock, 'c');
    if (sfKeyboard_isKeyPressed(sfKeyD) &&
        !sfKeyboard_isKeyPressed(sfKeyRShift) && f > 0.15)
        update_filename(paint, clock, 'd');
    if (sfKeyboard_isKeyPressed(sfKeyE) &&
        !sfKeyboard_isKeyPressed(sfKeyRShift) && f > 0.15)
        update_filename(paint, clock, 'e');
}

static void put_alpha2(paint_t *paint, sfClock **clock, float f)
{
    if (sfKeyboard_isKeyPressed(sfKeyF) &&
        !sfKeyboard_isKeyPressed(sfKeyRShift) && f > 0.15)
        update_filename(paint, clock, 'f');
    if (sfKeyboard_isKeyPressed(sfKeyG) &&
        !sfKeyboard_isKeyPressed(sfKeyRShift) && f > 0.15)
        update_filename(paint, clock, 'g');
    if (sfKeyboard_isKeyPressed(sfKeyH) &&
        !sfKeyboard_isKeyPressed(sfKeyRShift) && f > 0.15)
        update_filename(paint, clock, 'h');
    if (sfKeyboard_isKeyPressed(sfKeyI) &&
        !sfKeyboard_isKeyPressed(sfKeyRShift) && f > 0.15)
        update_filename(paint, clock, 'i');
    if (sfKeyboard_isKeyPressed(sfKeyJ) &&
        !sfKeyboard_isKeyPressed(sfKeyRShift) && f > 0.15)
        update_filename(paint, clock, 'j');
}

static void put_alpha3(paint_t *paint, sfClock **clock, float f)
{
    if (sfKeyboard_isKeyPressed(sfKeyK) &&
        !sfKeyboard_isKeyPressed(sfKeyRShift) && f > 0.15)
        update_filename(paint, clock, 'k');
    if (sfKeyboard_isKeyPressed(sfKeyL) &&
        !sfKeyboard_isKeyPressed(sfKeyRShift) && f > 0.15)
        update_filename(paint, clock, 'l');
    if (sfKeyboard_isKeyPressed(sfKeyM) &&
        !sfKeyboard_isKeyPressed(sfKeyRShift) && f > 0.15)
        update_filename(paint, clock, 'm');
    if (sfKeyboard_isKeyPressed(sfKeyN) &&
        !sfKeyboard_isKeyPressed(sfKeyRShift) && f > 0.15)
        update_filename(paint, clock, 'n');
    if (sfKeyboard_isKeyPressed(sfKeyO) &&
        !sfKeyboard_isKeyPressed(sfKeyRShift) && f > 0.15)
        update_filename(paint, clock, 'o');
}

static void put_alpha4(paint_t *paint, sfClock **clock, float f)
{
    if (sfKeyboard_isKeyPressed(sfKeyP) &&
        !sfKeyboard_isKeyPressed(sfKeyRShift) && f > 0.15)
        update_filename(paint, clock, 'p');
    if (sfKeyboard_isKeyPressed(sfKeyQ) &&
        !sfKeyboard_isKeyPressed(sfKeyRShift) && f > 0.15)
        update_filename(paint, clock, 'q');
    if (sfKeyboard_isKeyPressed(sfKeyR) &&
        !sfKeyboard_isKeyPressed(sfKeyRShift) && f > 0.15)
        update_filename(paint, clock, 'r');
    if (sfKeyboard_isKeyPressed(sfKeyS) &&
        !sfKeyboard_isKeyPressed(sfKeyRShift) && f > 0.15)
        update_filename(paint, clock, 's');
    if (sfKeyboard_isKeyPressed(sfKeyT) &&
        !sfKeyboard_isKeyPressed(sfKeyRShift) && f > 0.15)
        update_filename(paint, clock, 't');
}

static void put_alpha5(paint_t *paint, sfClock **clock, float f)
{
    if (sfKeyboard_isKeyPressed(sfKeyU) &&
        !sfKeyboard_isKeyPressed(sfKeyRShift) && f > 0.15)
        update_filename(paint, clock, 'u');
    if (sfKeyboard_isKeyPressed(sfKeyV) &&
        !sfKeyboard_isKeyPressed(sfKeyRShift) && f > 0.15)
        update_filename(paint, clock, 'v');
    if (sfKeyboard_isKeyPressed(sfKeyW) &&
        !sfKeyboard_isKeyPressed(sfKeyRShift) && f > 0.15)
        update_filename(paint, clock, 'w');
    if (sfKeyboard_isKeyPressed(sfKeyX) &&
        !sfKeyboard_isKeyPressed(sfKeyRShift) && f > 0.15)
        update_filename(paint, clock, 'x');
    if (sfKeyboard_isKeyPressed(sfKeyY) &&
        !sfKeyboard_isKeyPressed(sfKeyRShift) && f > 0.15)
        update_filename(paint, clock, 'y');
    if (sfKeyboard_isKeyPressed(sfKeyZ) &&
        !sfKeyboard_isKeyPressed(sfKeyRShift) && f > 0.15)
        update_filename(paint, clock, 'z');
}

void my_alpha(paint_t *paint, sfClock **clock, float f)
{
    put_alpha1(paint, clock, f);
    put_alpha2(paint, clock, f);
    put_alpha3(paint, clock, f);
    put_alpha4(paint, clock, f);
    put_alpha5(paint, clock, f);
}
