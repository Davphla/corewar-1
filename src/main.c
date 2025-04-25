/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** Main file
*/

#include "corewar.h"

int main(int ac, char *argv[])
{
    war_t *war = init_war(ac, argv);

    if (war == NULL)
        return 84;
    return 0;
}
