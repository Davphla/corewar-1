/*
** EPITECH PROJECT, 2025
** B-CPE-200-LYN-2-1-corewar-alexandre.kubiaczyk
** File description:
** process_dup.c
*/

#include "corewar.h"

process_t *process_dup(process_t *process, int new_pc)
{
    process_t *new_process = malloc(sizeof(process_t));

    new_process->cycle = process->cycle;
    
}
