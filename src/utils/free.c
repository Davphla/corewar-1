/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** File that free everything it has to
*/

#include "corewar.h"

void free_champ_array(war_t *war)
{
    for (int i = 0; i < war->nb_champ; i++)
        free(war->champs[i]);
    free(war->champs);
}

void free_war(war_t *war)
{
    free(war->vm);
    free_champ_array(war);
    free(war);
}
