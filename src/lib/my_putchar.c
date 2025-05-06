/*
** EPITECH PROJECT, 2024
** pool
** File description:
** my_putchar
*/

#include "corewar.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
