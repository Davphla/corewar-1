/*
** EPITECH PROJECT, 2024
** day08
** File description:
** my_strdup
*/

#include "corewar.h"

char *my_strdup(char *src)
{
    char *str;

    str = malloc((my_strlen(src) + 1) * sizeof(char));
    my_strcpy(str, src);
    return str;
}
