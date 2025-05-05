/*
** EPITECH PROJECT, 2024
** day06
** File description:
** my_strcpy
*/

#include "corewar.h"

char *my_strcpy(char *dest, char *src)
{
    int len = my_strlen(src);
    int i = 0;

    for (i = 0; i < len; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
    return dest;
}
