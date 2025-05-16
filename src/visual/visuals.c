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
    sleep(5);
    delwin(error);
    delwin(border);
}

win_t init_manager(int full)
{
    win_t manager = {0};

    if (full == 0) {
        manager.b_player = subwin(stdscr, 8, COLS - 15, 0, 0);
        manager.player = derwin(manager.b_player, 6, COLS - 17, 1, 1);

        manager.b_vm = subwin(stdscr, LINES - 9, COLS - 15, 8, 0);
        manager.vm = derwin(manager.b_vm, LINES - 11, COLS - 17, 1, 1);

        manager.b_hist = subwin(stdscr, LINES - 1, 14, 0, COLS - 14);
        manager.hist = derwin(manager.b_hist, 14, LINES - 2, 1, 1);
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
    mvwprintw(manager.b_player, 0, 2, "Players");

    box(manager.b_vm, ACS_VLINE, ACS_HLINE);
    mvwprintw(manager.b_vm, 0, 2, "Arena");

    manager.tog_player = false;
    manager.pause = false;
    return manager;
}

static void print_shortcut(void)
{
    attron(COLOR_PAIR(COLOR_4));
    printw("<space>: Stop/Continue | <q>: Quit | <p>: Show Players | <s>: advance 1 cycle");
    attroff(COLOR_PAIR(COLOR_4));
}

static void print_vm(WINDOW *vm, war_t *war)
{
    unsigned char hexa[2];
    int x = 0; int y = 0;
    int x_max = 0; int y_max = 0;

    getmaxyx(vm, y_max, x_max);
    werase(vm);
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
        getyx(vm, y, x);
        if (x > x_max - 2)
            wmove(vm, y + 1, 0);
        else {
            if (x != 0)
                wprintw(vm, " ");
        }
    }
}

static void print_player(WINDOW *player, war_t *war)
{
    return;
}

static void refresh_win(int full, win_t *manager)
{
    if (full == 0) {
        wrefresh(manager->vm);
        wrefresh(manager->player);
        wrefresh(manager->hist);
    } else {
        wrefresh(manager->b_vm);
        wrefresh(manager->vm);
        if (manager->tog_player == true) {
            wrefresh(manager->b_player);
            wrefresh(manager->player);
        }
    }
    print_shortcut();
}

void ncurse_gameboard(war_t *war, win_t *manager)
{
    static int init = 0;

    if ((COLS < 250 && LINES < 45 && war->full == 0) || (COLS < 128 * 3 + 1 && LINES < 37))
        size_error();
    if (init == 0) {
        *manager = init_manager(war->full);
        init = 1;
    }
    print_player(manager->player, war);
    print_vm(manager->vm, war);
    move(LINES - 1, 0);
    event(getch(), war, manager);
    refresh_win(war->full, manager);
    getch();
    usleep(500);
}
