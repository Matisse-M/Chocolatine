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
        sfKeyboard_isKeyPressed(sfKeyRShift) && f > 0.15)
        update_filename(paint, clock, 'A');
    if (sfKeyboard_isKeyPressed(sfKeyB) &&
        sfKeyboard_isKeyPressed(sfKeyRShift) && f > 0.15)
        update_filename(paint, clock, 'B');
    if (sfKeyboard_isKeyPressed(sfKeyC) &&
        sfKeyboard_isKeyPressed(sfKeyRShift) && f > 0.15)
        update_filename(paint, clock, 'C');
    if (sfKeyboard_isKeyPressed(sfKeyD) &&
        sfKeyboard_isKeyPressed(sfKeyRShift) && f > 0.15)
        update_filename(paint, clock, 'D');
    if (sfKeyboard_isKeyPressed(sfKeyE) &&
        sfKeyboard_isKeyPressed(sfKeyRShift) && f > 0.15)
        update_filename(paint, clock, 'E');
}

static void put_alpha2(paint_t *paint, sfClock **clock, float f)
{
    if (sfKeyboard_isKeyPressed(sfKeyF) &&
        sfKeyboard_isKeyPressed(sfKeyRShift) && f > 0.15)
        update_filename(paint, clock, 'F');
    if (sfKeyboard_isKeyPressed(sfKeyG) &&
        sfKeyboard_isKeyPressed(sfKeyRShift) && f > 0.15)
        update_filename(paint, clock, 'G');
    if (sfKeyboard_isKeyPressed(sfKeyH) &&
        sfKeyboard_isKeyPressed(sfKeyRShift) && f > 0.15)
        update_filename(paint, clock, 'H');
    if (sfKeyboard_isKeyPressed(sfKeyI) &&
        sfKeyboard_isKeyPressed(sfKeyRShift) && f > 0.15)
        update_filename(paint, clock, 'I');
    if (sfKeyboard_isKeyPressed(sfKeyJ) &&
        sfKeyboard_isKeyPressed(sfKeyRShift) && f > 0.15)
        update_filename(paint, clock, 'J');
}

static void put_alpha3(paint_t *paint, sfClock **clock, float f)
{
    if (sfKeyboard_isKeyPressed(sfKeyK) &&
        sfKeyboard_isKeyPressed(sfKeyRShift) && f > 0.15)
        update_filename(paint, clock, 'K');
    if (sfKeyboard_isKeyPressed(sfKeyL) &&
        sfKeyboard_isKeyPressed(sfKeyRShift) && f > 0.15)
        update_filename(paint, clock, 'L');
    if (sfKeyboard_isKeyPressed(sfKeyM) &&
        sfKeyboard_isKeyPressed(sfKeyRShift) && f > 0.15)
        update_filename(paint, clock, 'M');
    if (sfKeyboard_isKeyPressed(sfKeyN) &&
        sfKeyboard_isKeyPressed(sfKeyRShift) && f > 0.15)
        update_filename(paint, clock, 'N');
    if (sfKeyboard_isKeyPressed(sfKeyO) &&
        sfKeyboard_isKeyPressed(sfKeyRShift) && f > 0.15)
        update_filename(paint, clock, 'O');
}

static void put_alpha4(paint_t *paint, sfClock **clock, float f)
{
    if (sfKeyboard_isKeyPressed(sfKeyP) &&
        sfKeyboard_isKeyPressed(sfKeyRShift) && f > 0.15)
        update_filename(paint, clock, 'P');
    if (sfKeyboard_isKeyPressed(sfKeyQ) &&
        sfKeyboard_isKeyPressed(sfKeyRShift) && f > 0.15)
        update_filename(paint, clock, 'Q');
    if (sfKeyboard_isKeyPressed(sfKeyR) &&
        sfKeyboard_isKeyPressed(sfKeyRShift) && f > 0.15)
        update_filename(paint, clock, 'R');
    if (sfKeyboard_isKeyPressed(sfKeyS) &&
        sfKeyboard_isKeyPressed(sfKeyRShift) && f > 0.15)
        update_filename(paint, clock, 'S');
    if (sfKeyboard_isKeyPressed(sfKeyT) &&
        sfKeyboard_isKeyPressed(sfKeyRShift) && f > 0.15)
        update_filename(paint, clock, 'T');
}

static void put_alpha5(paint_t *paint, sfClock **clock, float f)
{
    if (sfKeyboard_isKeyPressed(sfKeyU) &&
        sfKeyboard_isKeyPressed(sfKeyRShift) && f > 0.15)
        update_filename(paint, clock, 'U');
    if (sfKeyboard_isKeyPressed(sfKeyV) &&
        sfKeyboard_isKeyPressed(sfKeyRShift) && f > 0.15)
        update_filename(paint, clock, 'V');
    if (sfKeyboard_isKeyPressed(sfKeyW) &&
        sfKeyboard_isKeyPressed(sfKeyRShift) && f > 0.15)
        update_filename(paint, clock, 'W');
    if (sfKeyboard_isKeyPressed(sfKeyX) &&
        sfKeyboard_isKeyPressed(sfKeyRShift) && f > 0.15)
        update_filename(paint, clock, 'X');
    if (sfKeyboard_isKeyPressed(sfKeyY) &&
        sfKeyboard_isKeyPressed(sfKeyRShift) && f > 0.15)
        update_filename(paint, clock, 'Y');
    if (sfKeyboard_isKeyPressed(sfKeyZ) &&
        sfKeyboard_isKeyPressed(sfKeyRShift) && f > 0.15)
        update_filename(paint, clock, 'Z');
}

void my_alpha_maj(paint_t *paint, sfClock **clock, float f)
{
    put_alpha1(paint, clock, f);
    put_alpha2(paint, clock, f);
    put_alpha3(paint, clock, f);
    put_alpha4(paint, clock, f);
    put_alpha5(paint, clock, f);
}
