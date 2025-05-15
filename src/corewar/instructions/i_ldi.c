/*
** EPITECH PROJECT, 2025
** B-CPE-200-LYN-2-1-robotfactory-bastien.sukiennik
** File description:
** i_ldi.c
*/

#include "corewar.h"

static int verify_coding_byte(coding_byte_t coding_byte)
{
    if (coding_byte.first == 0) {
        return -1;
    }
    if (coding_byte.second == 0 || coding_byte.second == 3) {
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

static int set_param_value(unsigned char *vm, int param, int begin_pc,
    unsigned char coding_byte)
{
    int ind_adress = begin_pc + param % IDX_MOD;

    switch (coding_byte) {
        case 1:
        case 2:
            return param;
        case 3:
            return get_ind(vm, &ind_adress);
        default:
            return -1;
    }
}

static int set_params(unsigned char *vm, int params[2], int begin_pc,
    coding_byte_t coding_byte)
{
    params[0] =
        set_param_value(vm, params[0], begin_pc, coding_byte.first);
    params[1] =
        set_param_value(vm, params[1], begin_pc, coding_byte.second);
    return begin_pc + (params[0] + params[1]) % IDX_MOD;
}

int i_ldi(war_t *war, __attribute_maybe_unused__ champion_t *champ,
    process_t *process)
{
    int begin_pc = process->PC;
    coding_byte_t coding_byte;
    int error = 0;
    int register_index = 0;
    int params[2] = {0};
    int S = 0;

    process->PC += 1;
    coding_byte.coding_byte = get_coding_byte(war->vm, &process->PC);
    if (verify_coding_byte(coding_byte) == -1)
        return reset_pc_and_return(process, begin_pc);
    params[0] = get_value_index(coding_byte.first, process, war, &error);
    params[1] = get_value_index(coding_byte.second, process, war, &error);
    register_index = get_register(war->vm, &process->PC);
    if (error == -1 || verify_register(register_index) == -1)
        return reset_pc_and_return(process, begin_pc);
    S = set_params(war->vm, params, begin_pc, coding_byte);
    process->reg[register_index - 1] = get_direct(war->vm, &S);
    return set_carry(process, process->reg[register_index - 1]);
}
