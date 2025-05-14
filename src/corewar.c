/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** File with the core program
*/

#include "corewar.h"

int corewar(war_t *war)
{
    while (1) {
        if (war->visual == 1)
            ncurse_gameboard(war);
        war->cycle++;
        update_vm(war);
        if (check_winner(war))
            break;
        if (war->dump != -1 && war->cycle % war->dump == 0) {
            dump(war->vm);
    }
    display_winner(war);
    return 0;
}
