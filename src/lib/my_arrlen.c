/*
** EPITECH PROJECT, 2024
** c_pool_day04_task03
** File description:
** function that display the number of character in a string
*/

#include <stdio.h>

int my_arrlen(char **arr)
{
    int cmpt = 0;

    if (arr == NULL)
        return 0;
    while (arr[cmpt] != NULL)
        cmpt++;
    return cmpt;
}
