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

static void put_num1(paint_t *paint, sfClock **clock, float f)
{
    if (sfKeyboard_isKeyPressed(sfKeyNumpad0) && f > 0.15)
        update_filename(paint, clock, '0');
    if (sfKeyboard_isKeyPressed(sfKeyNumpad1) && f > 0.15)
        update_filename(paint, clock, '1');
    if (sfKeyboard_isKeyPressed(sfKeyNumpad2) && f > 0.15)
        update_filename(paint, clock, '2');
    if (sfKeyboard_isKeyPressed(sfKeyNumpad3) && f > 0.15)
        update_filename(paint, clock, '3');
    if (sfKeyboard_isKeyPressed(sfKeyNumpad4) && f > 0.15)
        update_filename(paint, clock, '4');
    if (sfKeyboard_isKeyPressed(sfKeyNumpad5) && f > 0.15)
        update_filename(paint, clock, '5');
    if (sfKeyboard_isKeyPressed(sfKeyNumpad6) && f > 0.15)
        update_filename(paint, clock, '6');
    if (sfKeyboard_isKeyPressed(sfKeyNumpad7) && f > 0.15)
        update_filename(paint, clock, '7');
    if (sfKeyboard_isKeyPressed(sfKeyNumpad8) && f > 0.15)
        update_filename(paint, clock, '8');
    if (sfKeyboard_isKeyPressed(sfKeyNumpad9) && f > 0.15)
        update_filename(paint, clock, '9');
}

static void put_num2(paint_t *paint, sfClock **clock, float f)
{
    if (sfKeyboard_isKeyPressed(sfKeyNum0) &&
        !sfKeyboard_isKeyPressed(sfKeyRAlt) &&
        sfKeyboard_isKeyPressed(sfKeyRShift) && f > 0.15)
        update_filename(paint, clock, '0');
    if (sfKeyboard_isKeyPressed(sfKeyNum1) &&
        !sfKeyboard_isKeyPressed(sfKeyRAlt) &&
        sfKeyboard_isKeyPressed(sfKeyRShift) && f > 0.15)
        update_filename(paint, clock, '1');
    if (sfKeyboard_isKeyPressed(sfKeyNum2) &&
        !sfKeyboard_isKeyPressed(sfKeyRAlt) &&
        sfKeyboard_isKeyPressed(sfKeyRShift) && f > 0.15)
        update_filename(paint, clock, '2');
    if (sfKeyboard_isKeyPressed(sfKeyNum3) &&
        !sfKeyboard_isKeyPressed(sfKeyRAlt) &&
        sfKeyboard_isKeyPressed(sfKeyRShift) && f > 0.15)
        update_filename(paint, clock, '3');
    if (sfKeyboard_isKeyPressed(sfKeyNum4) &&
        !sfKeyboard_isKeyPressed(sfKeyRAlt) &&
        sfKeyboard_isKeyPressed(sfKeyRShift) && f > 0.15)
        update_filename(paint, clock, '4');
}

static void put_num3(paint_t *paint, sfClock **clock, float f)
{
    if (sfKeyboard_isKeyPressed(sfKeyNum5) &&
        !sfKeyboard_isKeyPressed(sfKeyRAlt) &&
        sfKeyboard_isKeyPressed(sfKeyRShift) && f > 0.15)
        update_filename(paint, clock, '5');
    if (sfKeyboard_isKeyPressed(sfKeyNum6) &&
        !sfKeyboard_isKeyPressed(sfKeyRAlt) &&
        sfKeyboard_isKeyPressed(sfKeyRShift) && f > 0.15)
        update_filename(paint, clock, '6');
    if (sfKeyboard_isKeyPressed(sfKeyNum7) &&
        !sfKeyboard_isKeyPressed(sfKeyRAlt) &&
        sfKeyboard_isKeyPressed(sfKeyRShift) && f > 0.15)
        update_filename(paint, clock, '7');
    if (sfKeyboard_isKeyPressed(sfKeyNum8) &&
        !sfKeyboard_isKeyPressed(sfKeyRAlt) &&
        sfKeyboard_isKeyPressed(sfKeyRShift) && f > 0.15)
        update_filename(paint, clock, '8');
    if (sfKeyboard_isKeyPressed(sfKeyNum9) &&
        !sfKeyboard_isKeyPressed(sfKeyRAlt) &&
        sfKeyboard_isKeyPressed(sfKeyRShift) && f > 0.15)
        update_filename(paint, clock, '9');
}

void my_num(paint_t *paint, sfClock **clock, float f)
{
    put_num1(paint, clock, f);
    put_num2(paint, clock, f);
    put_num3(paint, clock, f);
}
