/*
** EPITECH PROJECT, 2025
** B-CPE-200-LYN-2-1-robotfactory-bastien.sukiennik
** File description:
** i_live.c
*/

#include "corewar.h"

static int display_prompt(int id, char *name)
{
    my_putstr("The player ");
    my_putnbr(id);
    my_putstr("(");
    my_putstr(name);
    my_putstr(")is alive.\n");
    return 0;
}

int i_live(war_t *war, champion_t *champ, process_t *process)
{
    int live_champ_id = 0;

    process->PC++;
    live_champ_id = get_direct(war->vm, &process->PC);
    war->nbr_live++;
    for (int i = 0; i < war->nb_champ; i++) {
        if (war->champs[i]->id == live_champ_id) {
            war->champs[i]->to_die = 0;
            //display_prompt(war->champs[i]->id, war->champs[i]->name);
            war->last_to_live = champ;
            return 0;
        }
    }
    //display_prompt(live_champ_id, "");
    return -1;
}
