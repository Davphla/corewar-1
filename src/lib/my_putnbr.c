/*
** EPITECH PROJECT, 2024
** day03
** File description:
** my_put_nbr
*/

#include "corewar.h"

int my_putnbr(int nb)
{
    long nbr = nb;

    if (nbr < 0) {
        my_putchar('-');
        nbr = nbr * -1;
    }
    if (nbr > 9){
        my_putnbr(nbr / 10);
    }
    my_putchar(nbr % 10 + 48);
    return 0;
}
