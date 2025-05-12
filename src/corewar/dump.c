/*
** EPITECH PROJECT, 2025
** B-CPE-200-LYN-2-1-corewar-alexandre.kubiaczyk
** File description:
** display_vm.c
*/

#include "corewar.h"

void display_hexa(unsigned char c)
{
    unsigned char hexa[2];

    hexa[0] = c / 16;
    hexa[1] = c % 16;
    for (int i = 0; i < 2; i++) {
        if (hexa[i] <= 9) {
            my_putchar(hexa[i] + 48);
        } else {
            my_putchar(hexa[i] + 65 - 10);
        }
    }
}

void dump(unsigned char *vm)
{
    for (int i = 0; i < MEM_SIZE; i++) {
        display_hexa(vm[i]);
        if ((i + 1) % (32 * 8) == 0)
            my_putchar('\n');
    }
}
