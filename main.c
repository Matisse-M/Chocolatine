/*
** EPITECH PROJECT, 2023
** main
** File description:
** main()
*/

#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdarg.h>
#include "paint.h"
#include "my.h"

static int check_exist_four(char **av, int stat)
{
    sfTexture *shape = NULL;

    shape = sfTexture_createFromFile("assets/shape.png", NULL);
    if (!shape)
        return 84;
    sfTexture_destroy(shape);
    stat = open("assets/help_script.txt", O_RDONLY);
    if (stat == -1) {
        write(2, "File doesn't exist or is misplaced\n", 36);
        return 84;
    }
}

int check_exist_three(char **av, int stat)
{
    sfTexture *up = NULL;
    sfFont *font = NULL;

    up = sfTexture_createFromFile("assets/up.png", NULL);
    if (!up) {
        sfTexture_destroy(up);
        return 84;
    }
    sfTexture_destroy(up);
    font = sfFont_createFromFile("assets/font.ttf");
    if (!font) {
        sfFont_destroy(font);
        return 84;
    }
    sfFont_destroy(font);
    if (check_exist_four(av, stat) == 84)
        return 84;
}

int check_exist_two(char **av)
{
    sfTexture *up_h = NULL;
    sfTexture *pipette = NULL;
    int stat = 0;

    pipette = sfTexture_createFromFile("assets/pipette.png", NULL);
    if (!pipette) {
        sfTexture_destroy(pipette);
        return 84;
    }
    sfTexture_destroy(pipette);
    up_h = sfTexture_createFromFile("assets/up_h.png", NULL);
    if (!up_h) {
        sfTexture_destroy(up_h);
        return 84;
    }
    sfTexture_destroy(up_h);
    if (check_exist_three(av, stat) == 84)
        return 84;
}

int check_if_sprite_exist(char **av)
{
    sfTexture *down_h = sfTexture_createFromFile("assets/down_h.png", NULL);
    sfTexture *downe = NULL;

    if (!down_h) {
        sfTexture_destroy(down_h);
        return 84;
    }
    sfTexture_destroy(down_h);
    downe = sfTexture_createFromFile("assets/down.png", NULL);
    if (!downe) {
        sfTexture_destroy(downe);
        return 84;
    }
    sfTexture_destroy(downe);
    if (check_exist_two(av) == 84)
        return 84;
}

static char *get_env(char **env)
{
    char *user = NULL;

    for (int i = 0; env[i] != NULL; i++) {
        if (my_strncmp(env[i], "USER=", 5) == 0)
            user = my_strdup(&env[i][5]);
    }
    return user;
}

int main(int ac, char **av, char **env)
{
    sfEvent event;
    char *user = get_env(env);

    if (check_if_sprite_exist(av) == 84)
        return 84;
    my_paint(event, user);
    return (0);
}
