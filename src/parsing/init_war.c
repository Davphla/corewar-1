/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** File that handle the war struct which is the parsing
*/

#include "corewar.h"

#include <stdio.h>

static int check_dump_flag(int ac, char *argv[], int *i)
{
    return 0;
}

static int check_a_flag(int ac, char *argv[], int *i)
{
    return 0;
}

static int check_n_flag(int ac, char *argv[], int *i)
{
    return 0;
}

static int parse_flags(int ac, char *argv[], int *i)
{
    if (*i == ac - 1)
        return -1;
    switch (argv[*i][1]) {
        case 'd':
            return check_dump_flag(ac, argv, i);
        case 'a':
            return check_a_flag(ac, argv, i);
        case 'n':
            return check_n_flag(ac, argv, i);
    }
    return 0;
}

// Parse args and check for flags //
static int parse_args(int ac, char *argv[], war_t *war)
{
    champion_t champ = {0};
    int ret = 0;
    char *champions[4] = {0};
    int index_champ = 0;

    for (int i = 0; i < ac; i++) {
        if (argv[i][0] == '-')
            ret = parse_flags(ac, argv, &i);
        else {
            champions[index_champ] = argv[i];
            index_champ++;
        }
        if (ret != 0)
            return -1;
        if (index_champ + 1 > MAX_PLAYER || index_champ + 1 < MIN_PLAYER)
            return -1;
    }
    return 1;
}

// initialize the war structure //
war_t *init_war(int ac, char *argv[])
{
    war_t *war = malloc(sizeof(war_t));
    char *vm = NULL;

    if (war == NULL)
        return NULL;
    vm = malloc(sizeof(char) * MEM_SIZE);
    if (vm == NULL) {
        free(war);
        return NULL;
    }
    war->vm = vm;
    if (parse_args(ac, argv, war) == -1) {
        free(vm);
        free(war);
        return NULL;
    }
    return war;
}
