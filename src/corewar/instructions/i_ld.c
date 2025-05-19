/*
** EPITECH PROJECT, 2025
** B-CPE-200-LYN-2-1-robotfactory-bastien.sukiennik
** File description:
** i_ld.c
*/

#include "corewar.h"

static int verify_coding_byte(coding_byte_t coding_byte)
{
    if (coding_byte.first == 0 || coding_byte.first == 1) {
        return -1;
    }
    if (coding_byte.second != 1) {
        return -1;
    }
    if (coding_byte.third != 0 || coding_byte.fourth != 0) {
        return -1;
    }
    return 0;
}

static int set_register_value(int begin_pc, int arg_value, war_t *war,
    unsigned char codin_byte_first)
{
    int adress_to_load = 0;

    if (codin_byte_first == 2) {
        return arg_value;
    } else {
        adress_to_load = begin_pc + arg_value % IDX_MOD;
        return get_direct(war->vm, &adress_to_load);
    }
}

static int reset_pc_and_return(process_t *process, int begin_pc)
{
    process->PC = begin_pc + 1;
    return -1;
}

int i_ld(war_t *war, __attribute_maybe_unused__ champion_t *champ,
    process_t *process)
{
    int begin_pc = process->PC;
    coding_byte_t coding_byte;
    unsigned char register_index;
    int error = 0;
    int arg_value = 0;

    process->PC += 1;
    coding_byte.coding_byte = get_coding_byte(war->vm, &process->PC);
    if (verify_coding_byte(coding_byte) == -1)
        return reset_pc_and_return(process, begin_pc);
    arg_value = get_value(coding_byte.first, process, war, &error);
    register_index = get_register(war->vm, &process->PC);
    if (error == -1 || verify_register(register_index) == -1)
        return reset_pc_and_return(process, begin_pc);
    process->reg[register_index - 1] =
        set_register_value(begin_pc, arg_value, war, coding_byte.first);
    set_carry(process, process->reg[register_index - 1]);
    add_history("ld", champ->id);
    return 0;
}
