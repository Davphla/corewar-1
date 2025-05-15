/*
** EPITECH PROJECT, 2025
** B-CPE-200-LYN-2-1-corewar-alexandre.kubiaczyk
** File description:
** display_winner.c
*/

#include "corewar.h"

static int display_prompt(int nb_cycle, int id, char *name)
{
    my_putstr("The player ");
    my_putnbr(id);
    my_putstr("(");
    my_putstr(name);
    my_putstr(")has won after ");
    my_putnbr(nb_cycle);
    my_putstr(".\n");
    return 0;
}

int display_winner(war_t *war)
{
    if (!war->last_to_live) {
        display_prompt(war->cycle, 0, "");
    } else {
        display_prompt(war->cycle, war->last_to_live->id,
            war->last_to_live->name);
    }
    return 0;
}
