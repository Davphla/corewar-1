/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** File that handle the war struct which is the parsing
*/

#include "corewar.h"

static int verif_champ(champion_t *champ[4], war_t *war)
{
    int i = 0;

    for (; i < MAX_P; i++)
        if (champ[i] == NULL)
            return -1;
    war->nb_champ = i;
    return 0;
}

static int check_dump_flag(int ac, char *argv[], int *i, war_t *war)
{
    int dump_cycle = 0;

    (*i)++;
    for (int j = 0; j < my_strlen(argv[*i]); j++) {
        if (argv[*i][j] < 48 || argv[*i][j] > 57)
            return -1;
        dump_cycle = dump_cycle * 10 + (argv[*i][j] - 48);
    }
    return 0;
}

static int check_a_flag(int ac, char *argv[], int *i, champion_t *champ)
{
    return 0;
}

static int check_n_flag(int ac, char *argv[], int *i, champion_t *champ)
{
    return 0;
}

static int parse_flags(char *argv[], int *i, war_t *war, champion_t *champ)
{
    int ac = my_arrlen(argv);

    if (*i == ac - 1)
        return -1;
    switch (argv[*i][1]) {
        case 'd':
            return check_dump_flag(ac, argv, i, war);
        case 'a':
            return check_a_flag(ac, argv, i, champ);
        case 'n':
            return check_n_flag(ac, argv, i, champ);
    }
    return 0;
}

// Parse args and check for flags //
static int parse_args(int ac, char *argv[], war_t *war)
{
    champion_t *champ[4] = {0};
    int ret = 0;
    int index_champ = 0;

    for (int i = 1; i < ac; i++) {
        if (argv[i][0] == '-')
            ret = parse_flags(argv, &i, war, champ[index_champ]);
        else {
            champ[index_champ] = parse_champ(argv[i]);
            index_champ++;
        }
        if (ret != 0)
            return -1;
    }
    if (MAX_P < index_champ || MIN_P > index_champ ||
        verif_champ(champ, war) == -1)
        return -1;
    return 1;
}

// initialize the war structure //
war_t *init_war(int ac, char *argv[])
{
    war_t *war = malloc(sizeof(war_t));
    char *vm = NULL;

    if (war == NULL)
        return NULL;
    vm = malloc(sizeof(unsigned char) * MEM_SIZE);
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
