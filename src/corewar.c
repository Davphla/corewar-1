/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** File with the core program
*/

#include "corewar.h"

int corewar(war_t *war)
{
    dump(war->vm);
    if (war->visual == 1)
        return 1;
    return 0;
}
