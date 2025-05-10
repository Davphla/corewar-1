/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** Minilib
*/

#include <unistd.h>

#ifndef MINILIB_H_
    #define MINILIB_H_

int my_strcmp(char *s1, char *s2);
int my_strlen(char *str);
int my_arrlen(char **arr);
char *my_strcpy(char *dest, char *src);
char *my_strdup(char *src);
int my_getnbr(char const *str);
void my_putchar(char c);
int my_putstr(char *str);
void *my_calloc(size_t n, size_t size);
int my_putnbr(int nb);

#endif /* MINILIB_H_ */
