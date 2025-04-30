/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** Utils file
*/

#include "corewar.h"

void war_correct_nb(war_t *war)
{
    int index_champ = war->nb_champ;

    printf("index champ = %i\n", index_champ);
    for (int i = 0; i < index_champ; i ++)
        free(war->champs[i + index_champ]);
}
