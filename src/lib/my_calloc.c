/*
** EPITECH PROJECT, 2025
** B-PSU-200-LYN-2-1-minishell1-bastien.sukiennik
** File description:
** my_calloc
*/

#include "corewar.h"

void *my_calloc(size_t n, size_t size)
{
    void *ptr = NULL;
    char *str;

    ptr = malloc(size * n);
    if (ptr == NULL)
        return NULL;
    str = (char *)(ptr);
    for (int i = 0; (size_t)i < size * n; i++) {
        str[i] = '\0';
    }
    return ptr;
}
