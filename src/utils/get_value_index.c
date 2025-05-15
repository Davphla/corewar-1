/*
** EPITECH PROJECT, 2025
** B-CPE-200-LYN-2-1-corewar-alexandre.kubiaczyk
** File description:
** get_value_index.c
*/

#include "corewar.h"

int get_value_index(unsigned char value_type, process_t *process, war_t *war,
    int *error)
{
    unsigned char register_index = 0;

    switch (value_type) {
        case 1:
            register_index = get_register(war->vm, &process->PC);
            if (verify_register(register_index) == -1) {
                *error = -1;
                return 0;
            }
            return process->reg[register_index - 1];
        case 2:
        case 3:
            return get_ind(war->vm, &process->PC);
        default:
            *error = -1;
            return 0;
    }
}
