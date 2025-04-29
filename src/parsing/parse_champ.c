/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** File that handle the parsing of the .cor file
*/

#include "corewar.h"

void parse_file(FILE *fd, champion_t *champ)
{
    return;
}

champion_t *parse_champ(char *arg, champion_t *champ)
{
    FILE *fd = NULL;

    fd = fopen(arg, "r");
    if (my_strcmp(&arg[my_strlen(arg) - 4], ".cor") != 0 || fd == NULL) {
        if (fd != NULL)
            fclose(fd);
        free(champ);
        return NULL;
    }
    parse_file(fd, champ);
    fclose(fd);
    return champ == NULL ? NULL : champ;
}
