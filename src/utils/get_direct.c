/*
** EPITECH PROJECT, 2025
** B-CPE-200-LYN-2-1-corewar-alexandre.kubiaczyk
** File description:
** get_dir.c
*/

#include "corewar.h"

int get_direct(unsigned char *vm, int *pc)
{
    unsigned int direct_value = 0;
    int normalized_index = 0;

    for (int i = DIR_SIZE - 1; i >= 0; i--) {
        normalized_index = normalize_vm_index(*pc);
        direct_value += vm[normalized_index] * my_pow(256, i);
        *pc += 1;
    }
    return (int)direct_value;
}
