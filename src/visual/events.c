/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** File that handle the User input
*/

#include "corewar.h"

static void close_all(war_t *war, win_t *manager)
{
    free_war(war);
    delwin(manager->b_player);
    delwin(manager->player);
    delwin(manager->b_vm);
    delwin(manager->vm);
    delwin(manager->b_hist);
    delwin(manager->hist);
    endwin();
    exit(0);
}

void event(int input, war_t *war, win_t *manager)
{
    switch (input) {
    case 'q':
        close_all(war, manager);
        break;
    case ' ':
        manager->pause = manager->pause == true ? false : true;
        break;
    case KEY_UP:
        manager->speed += 1;
        break;
    case KEY_DOWN:
        manager->speed -= 1;
        break;
    }
}
