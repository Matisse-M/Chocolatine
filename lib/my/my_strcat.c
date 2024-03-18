/*
** EPITECH PROJECT, 2023
** my_cat
** File description:
** Concatenates 2 strings
*/

#include "my.h"

char *my_cat(char *dest, char const *src)
{
    int i = 0;
    int len_dest = my_strlen(dest);
    int len_src = my_strlen(src);
    char *result = malloc(sizeof(char) * (len_dest + len_src + 1));

    for (; i < len_dest; i++)
        result[i] = dest[i];
    for (int j = 0; j < len_src; j++) {
        result[i] = src[j];
        i++;
    }
    result[i] = '\0';
    return (result);
}
