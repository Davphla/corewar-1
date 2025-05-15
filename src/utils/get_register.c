/*
** EPITECH PROJECT, 2025
** B-CPE-200-LYN-2-1-corewar-alexandre.kubiaczyk
** File description:
** get_register.c
*/

#include "corewar.h"

unsigned char get_register(unsigned char *vm, int *pc)
{
    unsigned char register_value = 0;
    int normalized_adress = normalize_vm_index(*pc);

    register_value = vm[normalized_adress];
    *pc += 1;
    return register_value;
}
