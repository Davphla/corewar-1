/*
** EPITECH PROJECT, 2024
** day04
** File description:
** my_putstr
*/

#include "corewar.h"

int my_putstr(char *str)
{
    write(1, str, my_strlen(str));
    return 0;
}
