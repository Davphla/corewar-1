/*
** EPITECH PROJECT, 2025
** B-CPE-200-LYN-2-1-corewar-alexandre.kubiaczyk
** File description:
** check_winner.c
*/

#include "corewar.h"

int check_winner(war_t *war)
{
    int nb_alive = 0;
    static bool alive[4];

    for (int i = 0; i < war->nb_champ; i++) {
        if (war->champs[i]->alive) {
            alive[i] = true;
            nb_alive++;
        }
        if (war->visual == 1 && war->champs[i]->alive == false && alive[i] == true) {
            alive[i] = false;
            display_death(war->champs[i], i + 1);
        }
    }
    if (nb_alive > 1) {
        return 0;
    } else {
        return 1;
    }
}
