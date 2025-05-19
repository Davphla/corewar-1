/*
** EPITECH PROJECT, 2025
** B-CPE-200-LYN-2-1-robotfactory-bastien.sukiennik
** File description:
** i_zjmp.c
*/

#include "corewar.h"

int i_zjmp(war_t *war, __attribute_maybe_unused__ champion_t *champ,
    process_t *process)
{
    int begin_pc = process->PC;
    short index_value = 0;

    process->PC += 1;
    index_value = get_ind(war->vm, &process->PC);
    if (process->carry == 1)
        process->PC = begin_pc + index_value % IDX_MOD;
    add_history("zjump", champ->id);
    return 0;
}
