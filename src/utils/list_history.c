/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** File for the history in ncurse
*/

#include "corewar.h"

llist_t *list_history;

void free_hist(void)
{
    free_list(&list_history);
}

void print_history(WINDOW *hist)
{
    llist_t *temp = list_history;

    werase(hist);
    for (int i = 0; temp != NULL && i < len_list(list_history); i++) {
        wmove(hist, i, 0);
        wattron(hist, COLOR_PAIR(((hist_t *)temp->data)->id));
        wprintw(hist, "%s", ((hist_t *)temp->data)->instr);
        wattroff(hist, COLOR_PAIR(((hist_t *)temp->data)->id));
        temp = temp->next;
    }
    wrefresh(hist);
}

void add_history(char *instr, int id)
{
    hist_t *hist_node = malloc(sizeof(hist_t));

    if (hist_node == NULL)
        return;
    hist_node->id = id;
    hist_node->instr = instr;

    if (list_history == NULL)
        list_history = create_node(hist_node);
    else
        cat_list(&list_history, create_node(hist_node), END);
    if (len_list(list_history) > LINES - 2) {
        llist_t *temp = list_history;
        list_history = list_history->next;
        free(temp->data);
        free(temp);
    }
}
