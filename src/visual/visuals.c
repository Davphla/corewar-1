/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** File that handle the visualisation of the gameboard
*/

#include "corewar.h"

void ncurse_gameboard(war_t *war)
{
    static int init = 0;

    if (COLS < 200 && init == 0) {
        WINDOW *border = subwin(stdscr, 6, 26, LINES / 3, COLS / 3);
        WINDOW *error = derwin(border, 4, 24, 1, 1);
        box(border, ACS_VLINE, ACS_HLINE);
        wprintw(error, "The Terminal is too small, please resize your terminal or downsize your font");
        refresh();
        sleep(3);
        delwin(error);
        delwin(border);
    }
    if (init == 0) {
        for (int i = 0; i < MEM_SIZE; i++)
            printw("A");
        printw("Lines = %i and columns = %i\n", LINES, COLS);
        refresh();
        getch();
        clear();
        init = 1;
    }
}
