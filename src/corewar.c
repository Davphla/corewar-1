/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** File with the core program
*/

#include "corewar.h"

void action(champion_t *champ, war_t *war)
{
    return;
}

void make_action(champion_t *champ, war_t *war)
{
    for (llist_t *tmp = champ->process_list; tmp != NULL; tmp = tmp->next) {
        if (((process_t *)tmp)->cycle == 0)
            action(champ, war);
    }
    return;
}

int corewar(war_t *war)
{
    int clock = 0;

    for (int i = 0; i < war->nb_champ; i++) {
        make_action(war->champs[i], war);
        clock++;
    }
    if (war->visual == 1)
        return 1;
    return 0;
}
