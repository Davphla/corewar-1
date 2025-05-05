/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** File that initialize the structures
*/

#include "corewar.h"

// Initialize the war structure
war_t *init_struct_war(void)
{
    war_t *war = malloc(sizeof(war_t));

    if (war == NULL)
        return NULL;
    war->vm = malloc(sizeof(unsigned char) * MEM_SIZE);
    if (war->vm == NULL) {
        free(war);
        return NULL;
    }
    for (int i = 0; i < MEM_SIZE; i++)
        war->vm[i] = '\0';
    war->cycle = 0;
    war->dump = -1;
    war->nb_champ = 0;
    war->visual = 0;
    return war;
}

// Initialize the champ structure
champion_t **init_champ_array(void)
{
    champion_t **champ = malloc(sizeof(champion_t *) * MAX_P);

    if (champ == NULL)
        return NULL;
    for (int i = 0; i < MAX_P; i++) {
        champ[i] = malloc(sizeof(champion_t));
        champ[i]->size = 0;
        champ[i]->reg[0] = i + 1;
        for (int j = 1; j < REG_NUMBER; j++)
            champ[i]->reg[j] = 0;
        champ[i]->PC = 0;
        champ[i]->clock = 0;
        champ[i]->num_flag = i;
        champ[i]->adress = -1;
    }
    return champ;
}
