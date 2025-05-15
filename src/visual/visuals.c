/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** File that handle the visualisation of the gameboard
*/

#include "corewar.h"

static void size_error(void)
{
    WINDOW *border = subwin(stdscr, 6, 27, LINES / 3, COLS / 3);
    WINDOW *error = derwin(border, 4, 25, 1, 1);

    box(border, ACS_VLINE, ACS_HLINE);
    wattron(border, COLOR_PAIR(COLOR_4));
    mvwprintw(border, 0, 1, "Error");
    wattroff(border, COLOR_PAIR(COLOR_4));
    wattron(error, COLOR_PAIR(COLOR_4));
    wprintw(error, "The Terminal is too small please resize your terminal or downsize your font");
    wattron(error, COLOR_PAIR(COLOR_4));
    refresh();
    sleep(7);
    delwin(error);
    delwin(border);
}

win_t init_manager(void)
{
    win_t manager = {0};

    manager.b_player = subwin(stdscr, 8, COLS - 15, 0, 0);
    manager.player = derwin(manager.b_player, 6, COLS - 17, 1, 1);
    box(manager.b_player, ACS_VLINE, ACS_HLINE);
    mvwprintw(manager.b_player, 0, 2, "Players");

    manager.b_vm = subwin(stdscr, LINES - 9, COLS - 15, 8, 0);
    manager.vm = derwin(manager.b_vm, LINES - 10, COLS - 17, 1, 1);
    box(manager.b_vm, ACS_VLINE, ACS_HLINE);
    mvwprintw(manager.b_vm, 0, 2, "Arena");

    manager.b_hist = subwin(stdscr, LINES - 1, 14, 0, COLS - 14);
    manager.hist = derwin(manager.b_hist, 14, LINES - 2, 1, 1);
    box(manager.b_hist, ACS_VLINE, ACS_HLINE);
    mvwprintw(manager.b_hist, 0, 2, "History");
    return manager;
}

static void print_shortcut(void)
{
    attron(COLOR_PAIR(COLOR_4));
    printw("<space>: Stop/Continue | <q>: quit | <s>: advance 1 cycle");
    attroff(COLOR_PAIR(COLOR_4));
}

static void print_vm(WINDOW *vm, war_t *war)
{
    unsigned char hexa[2];

    for (int i = 0; i < MEM_SIZE; i++) {
        hexa[0] = war->vm[i] / 16;
        hexa[1] = war->vm[i] % 16;
        for (int j = 0; j < 2; j++) {
            if (hexa[j] <= 9)
                hexa[j] = hexa[j] + 48;
            else
                hexa[j] = hexa[j] + 65 - 10;
        }
        wattron(vm, COLOR_PAIR(war->vm_id[i]));
        wprintw(vm, "%s", hexa);
        wattroff(vm, COLOR_PAIR(war->vm_id[i]));
        wprintw(vm, " ");
    }
}

void ncurse_gameboard(war_t *war, win_t *manager)
{
    static int init = 0;

    if (COLS < 200)
        size_error();
    if (init == 0) {
        *manager = init_manager();
        init = 1;
    }
    move(LINES - 1, 0);
    print_vm(manager->vm, war);
    print_shortcut();
    event(getch(), war, manager);
    refresh();
    getch();
    usleep(500);
}
