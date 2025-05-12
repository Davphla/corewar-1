/*
** EPITECH PROJECT, 2025
** lib_list
** File description:
** File for handling all about linked list
*/

#include "list.h"
#include "corewar.h"

llist_t *arr_to_list(char **arr)
{
    llist_t *list = NULL;
    int i = 1;

    if (arr == NULL)
        return NULL;
    list = create_node(arr[0]);
    while (arr[i] != NULL) {
        cat_list(&list, create_node(arr[i]), END);
        i++;
    }
    return list;
}

char **list_to_arr(llist_t **list)
{
    char **arr = malloc(sizeof(char *) * (len_list(*list)));
    int i = 0;

    if (arr == NULL)
        return NULL;
    for (llist_t *temp = *list; temp != NULL; temp = temp->next) {
        arr[i] = my_strdup(temp->data);
        i++;
    }
    arr[i] = NULL;
    return arr;
}

int len_list(llist_t *list)
{
    int len = 1;

    while (list != NULL) {
        len++;
        list = list->next;
    }
    return len;
}
