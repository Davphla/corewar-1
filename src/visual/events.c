/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** File that handle the User input
*/

#include "corewar.h"

void display_death(champion_t *champ, int id)
{
    WINDOW *b_death = subwin(stdscr, 5, 40, LINES / 2 - 4, COLS / 2 - 25);
    WINDOW *death = derwin(b_death, 3, 38, 1, 1);
    int x_max = 0; int y_max = 0;

    beep();
    getmaxyx(death, y_max, x_max);
    for (int i = 0; i < x_max; i++)
        for (int j = 0; j < y_max; j++)
            mvwprintw(death, j, i, " ");
    box(b_death, ACS_VLINE, ACS_HLINE);
    mvwprintw(b_death, 0, 13, "Death message");
    wattron(death, COLOR_PAIR(RED));
    wmove(death, 1, 0);
    wprintw(death, "The champion ");
    wattron(death, COLOR_PAIR(id));
    wprintw(death, "%s", champ->name);
    wattron(death, COLOR_PAIR(RED));
    wprintw(death, " has perished.");
    wattron(death, COLOR_PAIR(COLOR_4));
    wrefresh(b_death);
    wrefresh(death);
    sleep(3);
    delwin(b_death);
    delwin(death);
}

static void close_all(win_t *manager)
{
    delwin(manager->b_player);
    delwin(manager->player);
    delwin(manager->b_vm);
    delwin(manager->vm);
    delwin(manager->b_hist);
    delwin(manager->hist);
    endwin();
}

void ask_save(war_t *war, win_t *manager)
{
    WINDOW *b_save = subwin(stdscr, 7, 40, LINES / 2 - 4, COLS / 2 - 25);
    WINDOW *save = derwin(b_save, 5, 38, 1, 1);
    int x_max = 0; int y_max = 0;
    char input;

    nodelay(save, false);
    getmaxyx(save, y_max, x_max);
    for (int i = 0; i < x_max; i++)
        for (int j = 0; j < y_max; j++)
            mvwprintw(save, j, i, " ");
    box(b_save, ACS_VLINE, ACS_HLINE);
    wattron(b_save, COLOR_PAIR(GREEN));
    mvwprintw(b_save, 0, 1, "Save");
    wmove(save, 1, 0);
    wprintw(save, "Exiting program, would you like to dump the vm ?");
    wattron(save, COLOR_PAIR(GREEN));
    wprintw(save, " [Y]es");
    wattron(save, COLOR_PAIR(RED));
    wprintw(save, " [N]o");
    wrefresh(b_save);
    wrefresh(save);
    input = wgetch(save);
    while (input != 'y' && input != 'n')
        input = wgetch(save);
    if (input == 'y') {
        close_all(manager);
        dump(war->vm, war->vm_id);
    } else
        close_all(manager);
}

void event(int input, war_t *war, win_t *manager)
{
    switch (input) {
    case 'q':
        ask_save(war, manager);
        free_war(war);
        exit(0);
        break;
    case ' ':
        manager->pause = manager->pause == true ? false : true;
        break;
    case 'p':
        manager->tog_player = manager->tog_player == true ? false : true;
        break;
    case KEY_UP:
        manager->speed += 2;
        break;
    case KEY_DOWN:
        manager->speed -= 2;
        break;
    }
}
