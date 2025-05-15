/*
** EPITECH PROJECT, 2025
** B-CPE-200-LYN-2-1-corewar-alexandre.kubiaczyk
** File description:
** get_indirect.c
*/

#include "corewar.h"

short get_ind(unsigned char *vm, int *pc)
{
    unsigned short indirect_value = 0;

    for (int i = IND_SIZE - 1; i >= 0; i--) {
        indirect_value += vm[(*pc) % MEM_SIZE] * my_pow(256, i);
        *pc += 1;
    }
    return (short)indirect_value;
}
