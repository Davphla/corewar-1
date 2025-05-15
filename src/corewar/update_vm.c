/*
** EPITECH PROJECT, 2025
** B-CPE-200-LYN-2-1-corewar-alexandre.kubiaczyk
** File description:
** update_vm.c
*/

#include "corewar.h"

int update_vm(war_t *war, win_t *manager)
{
    for (int i = 0; i < war->nb_champ; i++) {
        if (war->champs[i]->alive)
            handle_champ(war, war->champs[i]);
    }
    if (war->nbr_live >= NBR_LIVE) {
        war->cycle_to_die -= CYCLE_DELTA;
        war->nbr_live %= NBR_LIVE;
    }
    return 0;
}
