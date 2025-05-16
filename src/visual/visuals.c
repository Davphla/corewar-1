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
        manager.b_player = subwin(stdscr, 6, COLS - 15, 0, 0);
        manager.player = derwin(manager.b_player, 4, COLS - 17, 1, 1);

        manager.b_vm = subwin(stdscr, LINES - 7, COLS - 15, 6, 0);
        manager.vm = derwin(manager.b_vm, LINES - 9, COLS - 17, 1, 1);

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
    manager.pause = true;
    manager.speed = 50;
    return manager;
}

static void print_shortcut(void)
{
    attron(COLOR_PAIR(COLOR_4));
    printw("<space>: Stop/Continue <Up/Down>: Change Speed | <q>: Quit | <p>: Show Players | <s>: advance 1 cycle");
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
        if (x > x_max - 3)
            wmove(vm, y + 1, 0);
        else {
            if (x != 0)
                wprintw(vm, " ");
        }
    }
}

static void print_player(WINDOW *player, war_t *war, win_t *manager)
{
    int x_max = 0; int y_max = 0;

    werase(player);
    getmaxyx(player, y_max, x_max);

    wprintw(player, "   Cycle = %i", war->cycle);
    wmove(player, 1, 0);
    wprintw(player, "Cycle to die = %i", war->cycle_to_die);
    wmove(player, 2, 0);
    wprintw(player, "   Playing = ");
    if (manager->pause == false) {
        wattron(player, COLOR_PAIR(GREEN));
        wprintw(player, "YES");
        wattroff(player, COLOR_PAIR(GREEN));
    } else {
        wattron(player, COLOR_PAIR(RED));
        wprintw(player, "NO");
        wattroff(player, COLOR_PAIR(RED));
    }
    wmove(player, 3, 0);
    wprintw(player, "   Speed = %i%%", manager->speed);

    for (int i = 0; i < war->nb_champ; i++) {
        int column = 30 + (x_max / (war->nb_champ + 0.5)) * i;
        wmove(player, 0, column);
        wattron(player, COLOR_PAIR(i + 1));
        wprintw(player, "%s", war->champs[i]->name);
        wmove(player, 1, column);
        wprintw(player, "Alive: ");
        war->champs[i]->alive == true ? wattron(player, COLOR_PAIR(GREEN_BG)) : wattron(player, COLOR_PAIR(RED_BG));
        wprintw(player, "  ");
        wattron(player, COLOR_PAIR(i + 1));
        wmove(player, 2, column);
        wprintw(player, "Cycle Left = %i", war->cycle_to_die - war->champs[i]->to_die);
        wmove(player, 3, column);
        wprintw(player, "Nb_Process = %i", len_list(war->champs[i]->process_list));
        wattroff(player, COLOR_PAIR(i + 1));
    }
    wrefresh(player);
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
    int input = 0;

    if ((COLS < 250 && LINES < 45 && war->full == 0) || (COLS < 128 * 3 + 1 && LINES < 37))
        size_error();
    if (init == 0) {
        *manager = init_manager(war->full);
        init = 1;
    }
    print_player(manager->player, war, manager);
    print_vm(manager->vm, war);
    while (manager->pause == true) {
        event(input = getch(), war, manager);
        if (input == 's')
            break;
    }
    event(getch(), war, manager);
    move(LINES - 1, 0);
    refresh_win(war->full, manager);

    if (manager->speed < 1)
        manager->speed = 1;
    if (manager->speed > 100)
        manager->speed = 100;
    usleep((100 - manager->speed) * 1000);
}
