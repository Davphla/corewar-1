/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** Main file
*/

#include "corewar.h"

int main(int ac, char *argv[])
{
    war_t *war = NULL;

    if (ac == 2 && my_strcmp(argv[1], "-h") == 0)
        return print_help();
    war = init_war(ac, argv);
    if (war == NULL)
        return 84;
    return 0;
}
