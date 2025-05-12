/*
** EPITECH PROJECT, 2025
** B-CPE-200-LYN-2-1-robotfactory-bastien.sukiennik
** File description:
** i_aff.c
*/

#include "corewar.h"

int i_aff(war_t *war, __attribute_maybe_unused__ champion_t *champ,
    process_t *process)
{
    unsigned char register_index;

    process->PC += 2;
    register_index = war->vm[process->PC % MEM_SIZE];
    if (register_index < 1 || register_index > 16) {
        process->PC++;
        return -1;
    }
    my_putchar(process->reg[register_index - 1] % 256);
    process->PC++;
    return 0;
}
