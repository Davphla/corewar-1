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

    for (int i = DIR_SIZE - 1; i >= 0; i--) {
        direct_value += vm[normalize_vm_index(*pc)] * my_pow(256, i);
        *pc += 1;
    }
    return (int)direct_value;
}
