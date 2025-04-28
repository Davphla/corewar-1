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
    char *vm = NULL;

    if (war == NULL)
        return NULL;
    vm = malloc(sizeof(unsigned char) * MEM_SIZE);
    if (vm == NULL) {
        free(war);
        return NULL;
    }
    for (int i = 0; i < MEM_SIZE; i++)
        vm[i] = '0';
    war->cycle = 0;
    war->dump = -1;
    war->nb_champ = 0;
    war->vm = vm;
    return war;
}

// Initialize the champ structure
champion_t **init_champ_array(void)
{
    champion_t **champ = malloc(sizeof(champion_t *) * MAX_P);

    if (champ == NULL)
        return NULL;
    *champ = malloc(sizeof(champion_t) * 4);
    if (*champ == NULL) {
        free(champ);
        return NULL;
    }
    for (int i = 0; i < MAX_P; i++) {
        (*champ)->name = NULL;
        (*champ)->comment = NULL;
        for (int j = 0; j < REG_NUMBER; j++)
            (*champ)->reg[j] = 0;
        (*champ)->PC = 0;
        (*champ)->clock = 0;
        (*champ)->num_flag = i;
        (*champ)->adress_flag = NULL;
    }
    return champ;
}
