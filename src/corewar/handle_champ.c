/*
** EPITECH PROJECT, 2025
** B-CPE-200-LYN-2-1-corewar-alexandre.kubiaczyk
** File description:
** exec_champ.c
*/

#include "corewar.h"

int handle_champ(war_t *war, champion_t *champ)
{
    llist_t *process = champ->process_list;

    if (!champ->alive) {
        return -1;
    }
    champ->to_die += 1;
    while (process) {
        handle_process(war, champ, (process_t *)(process->data));
        process = process->next;
    }
    if (champ->to_die >= war->cycle_to_die) {
        champ->alive = false;
    }
    return 0;
}
