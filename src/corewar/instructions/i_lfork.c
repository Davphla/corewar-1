/*
** EPITECH PROJECT, 2025
** B-CPE-200-LYN-2-1-robotfactory-bastien.sukiennik
** File description:
** i_lfork.c
*/

#include "corewar.h"

int i_lfork(war_t *war, champion_t *champ, process_t *process)
{
    int begin_pc = process->PC;
    int new_pc;

    process->PC++;
    new_pc = (begin_pc + get_ind(war->vm, &process->PC)) % MEM_SIZE;
    cat_list(&champ->process_list, create_node(process_dup(process, new_pc)),
        END);
    return 0;
}
