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
    war->cycle = 1;
    war->dump = -1;
    war->nb_champ = 0;
    war->visual = 0;
    war->cycle_to_die = CYCLE_TO_DIE;
    war->nbr_live = 0;
    return war;
}

// Initialize champ_pocess
static llist_t *create_process(int champ_index)
{
    llist_t *process_node = malloc(sizeof(llist_t));
    process_t *process = my_calloc(1, sizeof(process_t));

    if (process_node == NULL || process == NULL)
        return NULL;
    process->reg[0] = champ_index;
    process_node->data = process;
    process_node->next = NULL;
    return process_node;
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
        champ[i]->process_list = create_process(i + 1);
        champ[i]->clock = 0;
        champ[i]->id = i;
        champ[i]->adress = -1;
        champ[i]->to_die = 0;
        champ[i]->alive = true;
    }
    return champ;
}
