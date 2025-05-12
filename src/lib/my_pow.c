/*
** EPITECH PROJECT, 2025
** B-CPE-200-LYN-2-1-corewar-alexandre.kubiaczyk
** File description:
** my_pow.c
*/

#include "corewar.h"

unsigned int my_pow(int nb, int power)
{
    unsigned int new_nb = nb;

    if (power == 0)
        return 1;
    for (int i = 1; i < power; i++) {
        new_nb *= nb;
    }
    return new_nb;
}
