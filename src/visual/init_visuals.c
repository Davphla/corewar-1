/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** File for initializing the screen
*/

#include "corewar.h"

void init_screen(void)
{
    initscr();
    start_color();
    nodelay(stdscr, true);
    init_pair(COLOR_1, COLOR_RED, COLOR_BLACK);
    init_pair(COLOR_2, COLOR_GREEN, COLOR_BLACK);
    init_pair(COLOR_3, COLOR_BLUE, COLOR_BLACK);
    init_pair(COLOR_4, COLOR_YELLOW, COLOR_BLACK);
    init_pair(CURSOR_1, COLOR_BLACK, COLOR_RED);
    init_pair(CURSOR_2, COLOR_BLACK, COLOR_GREEN);
    init_pair(CURSOR_3, COLOR_BLACK, COLOR_BLUE);
    init_pair(CURSOR_4, COLOR_BLACK, COLOR_YELLOW);
}
