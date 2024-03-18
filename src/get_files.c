/*
** EPITECH PROJECT, 2024
** B-MUL-200-NAN-2-1-mypaint-albane.merian
** File description:
** get_files
*/
#include <stdarg.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "paint.h"
#include "csfml.h"
#include "my.h"

static int check_filename(char *name)
{
    if (my_strlen(name) < 4)
        return 0;
    if ((name[my_strlen(name) - 1] == 'g' &&
        name[my_strlen(name) - 2] == 'p' &&
        name[my_strlen(name) - 3] == 'j' && name[my_strlen(name) - 4] == '.'))
        return 1;
    if ((name[my_strlen(name) - 1] == 'g' &&
        name[my_strlen(name) - 2] == 'n' &&
        name[my_strlen(name) - 3] == 'p' && name[my_strlen(name) - 4] == '.'))
        return 1;
    if ((name[my_strlen(name) - 1] == 'p' &&
        name[my_strlen(name) - 2] == 'm' &&
        name[my_strlen(name) - 3] == 'b' && name[my_strlen(name) - 4] == '.'))
        return 1;
    return 0;
}

static char **fill_word(char *file, char **array, int j)
{
    static int i = 0;

    if (j == 0)
        i = 0;
    if (check_filename(file) == 1) {
        array = my_realloc2(array, 1);
        array[i] = my_strdup(file);
        i++;
    }
    return array;
}

char **get_info(DIR *folder, struct dirent *file, paint_t *paint, char **array)
{
    int j = 0;

    while (file != NULL) {
        array = fill_word(file->d_name, array, j);
        j++;
        file = readdir(folder);
        if (file == NULL && j == 3) {
            paint->scene->open = false;
            return NULL;
        }
    }
    closedir(folder);
    return array;
}

char **get_files(paint_t *paint)
{
    DIR *folder;
    struct dirent *file;
    char **array = NULL;

    folder = opendir("./gallery/");
    if (folder == NULL) {
        paint->scene->open = false;
        return NULL;
    }
    file = readdir(folder);
    array = get_info(folder, file, paint, array);
    if (array == NULL)
        return NULL;
    return array;
}
