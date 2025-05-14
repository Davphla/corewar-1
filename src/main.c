/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** Main file
*/

#include "corewar.h"

int main(int ac, char *argv[])
{
    war_t *war = NULL;

    if (ac == 2 && my_strcmp(argv[1], "-h") == 0)
        return print_help();
    war = init_war(ac, argv);
    if (war == NULL)
        return 84;
    war_correct_nb(war);
    for (int i = 0; i < war->nb_champ; i++)
        printf("id = %i\n", war->champs[i]->id);
    if (corewar(war) == -1) {
        free_war(war);
        return 84;
    }
    free_war(war);
    return 0;
}
