/*
** EPITECH PROJECT, 2025
** B-CPE-200-LYN-2-1-corewar-alexandre.kubiaczyk
** File description:
** get_coding_byte.c
*/

#include "corewar.h"

unsigned char get_coding_byte(unsigned char *vm, int *pc)
{
    unsigned char coding_byte = vm[*pc % MEM_SIZE];

    *pc += 1;
    return coding_byte;
}
