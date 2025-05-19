/*
** EPITECH PROJECT, 2025
** B-CPE-200-LYN-2-1-corewar-alexandre.kubiaczyk
** File description:
** display_winner.c
*/

#include "corewar.h"

static void display_win_ncurse(int nb_cycle, char *name, int id)
{
    WINDOW *b_win = subwin(stdscr, 7, 40, LINES / 2 - 4, COLS / 2 - 25);
    WINDOW *win = derwin(b_win, 5, 38, 1, 1);
    int x_max = 0; int y_max = 0;

    getmaxyx(win, y_max, x_max);
    for (int i = 0; i < x_max; i++)
        for (int j = 0; j < y_max; j++)
            mvwprintw(win, j, i, " ");
    wattron(b_win, COLOR_PAIR(GREEN));
    box(b_win, ACS_VLINE, ACS_HLINE);
    wattroff(b_win, COLOR_PAIR(GREEN));
    mvwprintw(b_win, 0, 13, "Congratulation");
    wattron(win, COLOR_PAIR(GREEN));
    wmove(win, 1, 0);
    wprintw(win, "Champion %s(%i), You stood up against the greatest of all in %i cycle, well done !", name, id, nb_cycle);
    wattron(win, COLOR_PAIR(COLOR_4));
    wrefresh(b_win);
    wrefresh(win);
    sleep(8);
    delwin(b_win);
    delwin(win);
}

static int display_prompt(int nb_cycle, int id, char *name)
{
    my_putstr("The player ");
    my_putnbr(id);
    my_putstr("(");
    my_putstr(name);
    my_putstr(")has won after ");
    my_putnbr(nb_cycle);
    my_putstr(".\n");
    return 0;
}

int display_winner(war_t *war)
{
    if (!war->last_to_live) {
        display_prompt(war->cycle, 0, "");
    } else {
        display_prompt(war->cycle, war->last_to_live->id,
            war->last_to_live->name);
    }
    return 0;
}

void disp_winner_ncurse(war_t *war)
{
    display_win_ncurse(war->cycle, war->last_to_live->name, war->last_to_live->id);
}
