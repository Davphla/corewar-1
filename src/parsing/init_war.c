/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** File that handle the war struct which is the parsing
*/

#include "corewar.h"

static int verif_champ(war_t *war)
{
    for (int i = 0; i < war->nb_champ; i++) {
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
    int id = 0;

    (*i)++;
    for (int j = 0; j < my_strlen(argv[*i]); j++) {
        if (argv[*i][j] < 48 || argv[*i][j] > 57)
            return -1;
        id = id * 10 + (argv[*i][j] - 48);
    }
    champ->id = id;
    ((process_t *)(champ->process_list->data))->reg[0] = id;
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
            champ->adress = my_getnbr(argv[*i]) % MEM_SIZE;
            return 0;
        case 'n':
            return check_n_flag(argv, i, champ);
        case 'v':
            war->visual = 1;
            return 0;
    }
    return 0;
}

static int write_in_vm_and_verify(war_t *war, char *champ_name[])
{
    for (int i = 0; i < war->nb_champ; i++)
        if (parse_champ(war->vm, i * (MEM_SIZE / war->nb_champ), champ_name[i],
            war->champs[i]) == -1)
            return -1;
    for (int i = 0; i < MAX_P && champ_name[i]; i++)
        free(champ_name[i]);
    if (MAX_P < war->nb_champ || MIN_P > war->nb_champ
        || verif_champ(war) == -1)
        return -1;
    return 1;
}

// Parse args and check for flags //
static int parse_args(int ac, char *argv[], war_t *war)
{
    int ret = 0;
    char *champ_name[4] = {NULL};

    for (int i = 1; i < ac; i++) {
        if (war->nb_champ == 4)
            return -1;
        if (argv[i][0] == '-') {
            ret = parse_flags(argv, &i, war, war->champs[war->nb_champ]);
        } else {
            champ_name[war->nb_champ] = my_strdup(argv[i]);
            war->nb_champ++;
        }
        if (ret != 0)
            return -1;
    }
    return write_in_vm_and_verify(war, champ_name);
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
