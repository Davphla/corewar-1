/*
** EPITECH PROJECT, 2025
** B-CPE-200-LYN-2-1-corewar-alexandre.kubiaczyk
** File description:
** normalize_vm_index.c
*/

#include "corewar.h"

int normalize_vm_index(int vm_index)
{
    while (vm_index < 0) {
        vm_index = vm_index + MEM_SIZE;
    }
    return vm_index % MEM_SIZE;
}
