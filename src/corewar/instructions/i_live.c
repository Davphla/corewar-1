/*
** EPITECH PROJECT, 2025
** B-CPE-200-LYN-2-1-robotfactory-bastien.sukiennik
** File description:
** i_live.c
*/

#include "corewar.h"

int i_live(war_t *war, champion_t *champ, process_t *process)
{
    int param_value = 0;

    process->PC++;
    param_value = get_direct(war->vm, &process->PC);
    war->nbr_live++;
    champ->to_die = 0;
    return 0;
}
