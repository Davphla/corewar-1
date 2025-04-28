/*
** EPITECH PROJECT, 2024
** c_pool_day04_task03
** File description:
** function that display the number of character in a string
*/

int my_strlen(char const *str)
{
    int cmpt = 0;

    while (str[cmpt] != '\0')
        cmpt++;
    return cmpt;
}
