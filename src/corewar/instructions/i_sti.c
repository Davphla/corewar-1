/*
** EPITECH PROJECT, 2025
** B-CPE-200-LYN-2-1-robotfactory-bastien.sukiennik
** File description:
** i_sti.c
*/

#include "corewar.h"

static int verify_coding_byte(coding_byte_t coding_byte)
{
    if (coding_byte.first != 1) {
        return -1;
    }
    if (coding_byte.second == 0 || coding_byte.third == 0) {
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

static int handle_param(unsigned char *vm, int param, int begin_pc,
    unsigned char coding_byte)
{
    int ind_adress = begin_pc + param % IDX_MOD;

    switch (coding_byte) {
        case 1:
        case 2:
            return param;
        case 3:
            return (int) get_ind(vm, &ind_adress);
        default:
            return -1;
    }
}

static int set_adress(unsigned char *vm, int params[2], int begin_pc,
    coding_byte_t coding_byte)
{
    int st_adress = 0;

    st_adress += handle_param(vm, params[0], begin_pc, coding_byte.second);
    st_adress += handle_param(vm, params[1], begin_pc, coding_byte.third);
    return st_adress;
}

int i_sti(war_t *war, __attribute_maybe_unused__ champion_t *champ,
    process_t *process)
{
    int begin_pc = process->PC;
    coding_byte_t coding_byte;
    int error = 0;
    int arg_value = 0;
    int params[2] = {0};
    int st_adress = 0;

    process->PC += 1;
    coding_byte.coding_byte = get_coding_byte(war->vm, &process->PC);
    if (verify_coding_byte(coding_byte) == -1)
        return reset_pc_and_return(process, begin_pc);
    arg_value = get_value(coding_byte.first, process, war, &error);
    params[0] = get_value_index(coding_byte.second, process, war, &error);
    params[1] = get_value_index(coding_byte.third, process, war, &error);
    if (error == -1)
        return reset_pc_and_return(process, begin_pc);
    st_adress = set_adress(war->vm, params, begin_pc, coding_byte);
    write_in_vm(war->vm, arg_value, begin_pc + st_adress % IDX_MOD, REG_SIZE);
    return 0;
}
