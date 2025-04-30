/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** File that handle the war struct which is the parsing
*/

#include "corewar.h"

static int verif_champ(war_t *war)
{
    int i = 0;

    for (; i < war->nb_champ; i++) {
        if (war->champs[i] == NULL)
            return -1;
    }
    return 0;
}

static int check_dump_flag(char *argv[], int *i, war_t *war)
{
    int dump_cycle = 0;

    (*i)++;
    for (int j = 0; j < my_strlen(argv[*i]); j++) {
        if (argv[*i][j] < 48 || argv[*i][j] > 57)
            return -1;
        dump_cycle = dump_cycle * 10 + (argv[*i][j] - 48);
    }
    war->dump = dump_cycle;
    return 0;
}

static int check_n_flag(char *argv[], int *i, champion_t *champ)
{
    int number = 0;

    (*i)++;
    for (int j = 0; j < my_strlen(argv[*i]); j++) {
        if (argv[*i][j] < 48 || argv[*i][j] > 57)
            return -1;
        number = number * 10 + (argv[*i][j] - 48);
    }
    champ->num_flag = number;
    return 0;
}

static int parse_flags(char *argv[], int *i, war_t *war, champion_t *champ)
{
    if (*i == my_arrlen(argv) - 1)
        return -1;
    switch (argv[*i][1]) {
        case 'd':
            return check_dump_flag(argv, i, war);
        case 'a':
            (*i)++;
            champ->adress_flag = argv[*i];
            return 0;
        case 'n':
            return check_n_flag(argv, i, champ);
        case 'v':
            war->visual = 1;
            return 0;
    }
    return 0;
}

// Parse args and check for flags //
static int parse_args(int ac, char *argv[], war_t *war)
{
    int ret = 0;
    int index_champ = 0;

    for (int i = 1; i < ac; i++) {
        if (argv[i][0] == '-')
            ret = parse_flags(argv, &i, war, war->champs[index_champ]);
        else {
            parse_champ(argv[i], war->champs[index_champ]);
            index_champ++;
            war->nb_champ++;
        }
        if (ret != 0)
            return -1;
    }
    if (MAX_P < index_champ || MIN_P > index_champ ||
        verif_champ(war) == -1)
        return -1;
    return 1;
}

// initialize the war structure //
war_t *init_war(int ac, char *argv[])
{
    war_t *war = init_struct_war();
    char *vm = NULL;

    if (war == NULL)
        return NULL;
    war->champs = init_champ_array();
    if (war->champs == NULL) {
        free(war);
        return NULL;
    }
    if (parse_args(ac, argv, war) == -1) {
        free(vm);
        free(war);
        return NULL;
    }
    return war;
}
