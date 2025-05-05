/*
** EPITECH PROJECT, 2025
** B-CPE-200-LYN-2-1-corewar-alexandre.kubiaczyk
** File description:
** display_vm.c
*/

#include "corewar.h"

void display_vm(unsigned char *vm)
{
    for (int i = 0; i < MEM_SIZE; i++) {
        printf("%02X", vm[i]);
    }
    printf("\n");
}
