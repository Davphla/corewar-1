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
    int begin_pc = process->PC;
    coding_byte_t coding_byte;

    process->PC += 1;
    coding_byte.coding_byte = get_coding_byte(war->vm, &process->PC);
    register_index = get_register(war->vm, &process->PC);
    if (verify_register(register_index) == -1
        || coding_byte.coding_byte != 64) {
        process->PC = begin_pc + 1;
        return -1;
    }
    my_putchar(process->reg[register_index - 1] % 256);
    my_putchar('\n');
    return 0;
}
