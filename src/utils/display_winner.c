/*
** EPITECH PROJECT, 2025
** B-CPE-200-LYN-2-1-corewar-alexandre.kubiaczyk
** File description:
** display_winner.c
*/

#include "corewar.h"

static int display_prompt(int id, char *name)
{
    my_putstr("The player ");
    my_putnbr(id);
    my_putstr("(");
    my_putstr(name);
    my_putstr(")has won.\n");
    return 0;
}

int display_winner(war_t *war)
{
    for (int i = 0; i < war->nb_champ; i++) {
        if (war->champs[i]->alive) {
            display_prompt(war->champs[i]->id, war->champs[i]->name);
            return 0;
        }
    }
    display_prompt(0, "");
    return 0;
}
