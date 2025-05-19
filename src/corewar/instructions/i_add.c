/*
** EPITECH PROJECT, 2025
** B-CPE-200-LYN-2-1-robotfactory-bastien.sukiennik
** File description:
** i_add.c
*/

#include "corewar.h"

static int verify_args(unsigned char coding_byte, char arg_register1,
    char arg_register2, char tot_register)
{
    if (coding_byte != 84 || verify_register(arg_register1) == -1
        || verify_register(arg_register2) == -1
        || verify_register(tot_register) == -1) {
        return -1;
    }
    return 0;
}

int i_add(war_t *war, __attribute_maybe_unused__ champion_t *champ,
    process_t *process)
{
    int begin_pc = process->PC;
    coding_byte_t coding_byte = {0};
    char arg_register1 = 0;
    char arg_register2 = 0;
    char tot_register = 0;

    process->PC += 1;
    coding_byte.coding_byte = get_coding_byte(war->vm, &process->PC);
    arg_register1 = get_register(war->vm, &process->PC);
    arg_register2 = get_register(war->vm, &process->PC);
    tot_register = get_register(war->vm, &process->PC);
    if (verify_args(coding_byte.coding_byte, arg_register1, arg_register2,
            tot_register) == -1) {
        process->PC = begin_pc + 1;
        return -1;
    }
    process->reg[tot_register - 1] =
        process->reg[arg_register1 - 1] + process->reg[arg_register2 - 1];
    set_carry(process, process->reg[tot_register - 1]);
    add_history("add", champ->id);
    return 0;
}
