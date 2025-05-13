/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** Utils file
*/

#include "corewar.h"

static void check_same_nbr(war_t *war, int *j, int *k)
{
    if (war->champs[*j]->id == war->champs[*k]->id && *j != *k) {
        war->champs[*k]->id++;
        *j = 0;
    }
}

void war_correct_nb(war_t *war)
{
    int index_champ = war->nb_champ;

    for (int i = 0; i < index_champ - MAX_P; i++)
        free_champ(war->champs[i + index_champ]);
    for (int j = 0; j < index_champ; j++) {
        for (int k = 0; k < index_champ; k++) {
            check_same_nbr(war, &j, &k);
        }
    }
}
