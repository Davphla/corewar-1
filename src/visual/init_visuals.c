/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** File for initializing the screen
*/

#include "corewar.h"

win_t init_manager(int full)
{
    win_t manager = {0};

    if (full == 0) {
        manager.b_player = subwin(stdscr, 6, COLS - 15, 0, 0);
        manager.player = derwin(manager.b_player, 4, COLS - 17, 1, 1);

        manager.b_vm = subwin(stdscr, LINES - 7, COLS - 15, 6, 0);
        manager.vm = derwin(manager.b_vm, LINES - 9, COLS - 17, 1, 1);

        manager.b_hist = subwin(stdscr, LINES - 1, 14, 0, COLS - 14);
        manager.hist = derwin(manager.b_hist, LINES - 3, 12, 1, 1);
        box(manager.b_hist, ACS_VLINE, ACS_HLINE);
        mvwprintw(manager.b_hist, 0, 2, "History");
    } else {
        manager.b_player = subwin(stdscr, 8, COLS - 15, 0, 0);
        manager.player = derwin(manager.b_player, 6, COLS - 17, 1, 1);

        manager.b_vm = subwin(stdscr, LINES - 1, COLS, 0, 0);
        manager.vm = derwin(manager.b_vm, LINES - 3, COLS - 2, 1, 1);

        manager.b_hist = NULL;
        manager.hist = NULL;
    }
    box(manager.b_player, ACS_VLINE, ACS_HLINE);
    mvwprintw(manager.b_player, 0, 2, "Champions");

    box(manager.b_vm, ACS_VLINE, ACS_HLINE);
    mvwprintw(manager.b_vm, 0, 2, "Arena");

    manager.tog_player = false;
    manager.pause = true;
    manager.speed = 50;
    return manager;
}

void init_screen(void)
{
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
    start_color();
    nodelay(stdscr, true);
    init_pair(COLOR_0, COLOR_WHITE, COLOR_BLACK);
    init_pair(COLOR_1, COLOR_RED, COLOR_BLACK);
    init_pair(COLOR_2, COLOR_GREEN, COLOR_BLACK);
    init_pair(COLOR_3, COLOR_BLUE, COLOR_BLACK);
    init_pair(COLOR_4, COLOR_YELLOW, COLOR_BLACK);
    init_pair(CURSOR_1, COLOR_BLACK, COLOR_RED);
    init_pair(CURSOR_2, COLOR_BLACK, COLOR_GREEN);
    init_pair(CURSOR_3, COLOR_BLACK, COLOR_BLUE);
    init_pair(CURSOR_4, COLOR_BLACK, COLOR_YELLOW);
}
