/*
** EPITECH PROJECT, 2025
** B-CPE-200-LYN-2-1-robotfactory-bastien.sukiennik
** File description:
** i_and.c
*/

#include "corewar.h"

static int verify_coding_byte(coding_byte_t coding_byte)
{
    if (coding_byte.first == 0 || coding_byte.second == 0) {
        return -1;
    }
    if (coding_byte.third != 1) {
        return -1;
    }
    if (coding_byte.fourth != 0) {
        return -1;
    }
    return 0;
}

static int reset_pc_and_return(process_t *process, int begin_pc)
{
    process->PC = begin_pc + 1;
    return -1;
}

int i_and(war_t *war, __attribute_maybe_unused__ champion_t *champ,
    process_t *process)
{
    int begin_pc = process->PC;
    coding_byte_t coding_byte;
    int error = 0;
    int register_index = 0;
    int params[2] = {0};

    process->PC += 1;
    coding_byte.coding_byte = get_coding_byte(war->vm, &process->PC);
    if (verify_coding_byte(coding_byte) == -1)
        return reset_pc_and_return(process, begin_pc);
    params[0] = get_value(coding_byte.first, process, war, &error);
    params[1] = get_value(coding_byte.second, process, war, &error);
    register_index = get_register(war->vm, &process->PC);
    if (error == -1 || verify_register(register_index) == -1)
        return reset_pc_and_return(process, begin_pc);
    process->reg[register_index - 1] = params[0] & params[1];
    set_carry(process, process->reg[register_index - 1]);
    add_history("and", champ->id);
    return 0;
}
