/*
** EPITECH PROJECT, 2025
** B-CPE-200-LYN-2-1-corewar-alexandre.kubiaczyk
** File description:
** set_carry.c
*/

#include "corewar.h"

int set_carry(process_t *process, int result)
{
    if (result == 0) {
        process->carry = 1;
    } else {
        process->carry = 0;
    }
    return 0;
}
