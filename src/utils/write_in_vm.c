/*
** EPITECH PROJECT, 2025
** B-CPE-200-LYN-2-1-corewar-alexandre.kubiaczyk
** File description:
** write_in_vm.c
*/

#include "corewar.h"

int write_in_vm(unsigned char *vm, int value, int adress, size_t size)
{
    int pos = 0;
    int normalized_adress = 0;

    for (int i = size - 1; i >= 0; i--) {
        normalized_adress = normalize_vm_index(adress + pos);
        vm[normalized_adress] = value / my_pow(256, i);
        pos += 1;
    }
    return 0;
}
