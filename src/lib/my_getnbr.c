/*
** EPITECH PROJECT, 2024
** day04
** File description:
** my_getnbr
*/

#include "corewar.h"

static void neg(char const *str, int *i, int *signe)
{
    if (str[*i] == '-') {
        *signe = *signe + 1;
    }
}

static void no_nb(char const *str, int *i, int *signe, int *stop)
{
    if (*stop / 10 == 0) {
        if (*stop % 10 == 0)
            neg(str, i, signe);
    }
    if (*stop / 10 == 1)
        *stop = 20 + *stop % 10;
}

int my_getnbr(char const *str)
{
    long long c = 0;
    int signe = 0;
    int stop = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9' && stop / 10 < 2) {
            c = c * 10;
            c += str[i] - 48;
            stop = 11;
        } else
            no_nb(str, &i, &signe, &stop);
        if (c > 2147483647 && signe % 2 == 0)
            return 0;
        if (c > 2147483648 && signe % 2 == 1)
            return 0;
    }
    if (signe % 2 == 1) {
        c = c * -1;
    }
    return c;
}
