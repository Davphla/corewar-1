/*
** EPITECH PROJECT, 2025
** B-CPE-200-LYN-2-1-robotfactory-bastien.sukiennik
** File description:
** i_st.c
*/

#include "corewar.h"

static int verify_coding_byte(coding_byte_t coding_byte)
{
    if (coding_byte.first != 1) {
        return -1;
    }
    if (coding_byte.second == 0 || coding_byte.second == 2) {
        return -1;
    }
    if (coding_byte.third != 0 || coding_byte.fourth != 0) {
        return -1;
    }
    return 0;
}

static int reset_pc_and_return(process_t *process, int begin_pc)
{
    process->PC = begin_pc + 1;
    return -1;
}

static int handle_reg(war_t *war, process_t *process, int begin_pc,
    int arg_value)
{
    unsigned char register_index = get_register(war->vm, &process->PC);

    if (verify_register(register_index) == -1)
        return reset_pc_and_return(process, begin_pc);
    process->reg[register_index - 1] = arg_value;
    return 0;
}

static int handle_ind(war_t *war, process_t *process, int begin_pc,
    int arg_value)
{
    unsigned short indirect_adress = get_ind(war->vm, &process->PC);

    write_in_vm(war->vm, arg_value, begin_pc + indirect_adress % IDX_MOD,
        REG_SIZE);
    return 0;
}

int i_st(war_t *war, __attribute_maybe_unused__ champion_t *champ,
    process_t *process)
{
    int begin_pc = process->PC;
    coding_byte_t coding_byte;
    int error = 0;
    int arg_value = 0;

    process->PC += 1;
    coding_byte.coding_byte = get_coding_byte(war->vm, &process->PC);
    if (verify_coding_byte(coding_byte) == -1)
        return reset_pc_and_return(process, begin_pc);
    arg_value = get_value(coding_byte.first, process, war, &error);
    if (error == -1)
        return reset_pc_and_return(process, begin_pc);
    if (coding_byte.second == 1) {
        return handle_reg(war, process, begin_pc, arg_value);
    } else {
        return handle_ind(war, process, begin_pc, arg_value);
    }
}
