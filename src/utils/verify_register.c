/*
** EPITECH PROJECT, 2025
** B-CPE-200-LYN-2-1-corewar-alexandre.kubiaczyk
** File description:
** verify_register.c
*/

#include "corewar.h"

int verify_register(char register_index)
{
    if (register_index < 1 || register_index > 16) {
        return -1;
    }
    return 0;
}
