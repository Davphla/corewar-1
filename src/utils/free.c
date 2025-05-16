/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** File that free everything it has to
*/

#include "corewar.h"

void free_champ(champion_t *champ)
{
    free_list_obj(champ->process_list);
    free(champ);
}

void free_champ_array(war_t *war)
{
    int i = 0;

    for (; i < MAX_P; i++) {
        free_champ(war->champs[i]);
    }
    free(war->champs);
}

void free_war(war_t *war)
{
    free(war->vm);
    free_champ_array(war);
    free(war);
}
