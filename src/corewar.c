/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** File with the core program
*/

#include "corewar.h"

static void init_id(war_t *war)
{
    int start = 0;

    for (int i = 0; i < war->nb_champ; i++) {
        start = war->champs[i]->adress;
        for (int j = 0; j < war->champs[i]->size; j++)
            war->vm_id[start + j] = i + 1;
    }
}

int corewar(war_t *war)
{
    win_t manager = {0};
    init_id(war);

    while (1) {
        if (war->visual == 1)
            ncurse_gameboard(war, &manager);
        war->cycle++;
        update_vm(war, &manager);
        if (check_winner(war))
            break;
        if (war->dump != -1 && war->cycle % war->dump == 0)
            dump(war->vm);
    }
    if (war->visual == 1) {
        disp_winner_ncurse(war);
        endwin();
    }
    display_winner(war);
    return 0;
}
