/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** File that handle the war struct which is the parsing
*/

#include "corewar.h"

#include <stdio.h>

static int check_dump_flag(int ac, char *argv[], int *i, flags_t *flag)
{
    return 0;
}

static int check_a_flag(int ac, char *argv[], int *i, flags_t *flag)
{
    return 0;
}

static int check_n_flag(int ac, char *argv[], int *i, flags_t *flag)
{
    return 0;
}

static int print_help(void)
{
    write(1, "USAGE\n./corewar ", 16);
    write(1, "[-dump nbr_cycle] [[-n prog_number] [-a load_adress]", 52);
    write(1, " prog_name] ...\n", 16);
    write(1, "DESCRIPTION\n-dump nbr_cycle dumps the memory after", 51);
    write(1, "the nbr_cycle execution (if the round isn't already over)", 57);
    write(1, " with the following format: 32bytes/lines in hexadecimal", 56);
    write(1, " (A0BCDEFE1DD3...)\n", 19);
    write(1, "-n prog_number sets the next program's number. By default", 57);
    write(1, ", the first free number in the parameter order\n", 48);
    write(1, "-a load_address sets the next program's loading address.", 55);
    write(1, " When no address is specified, optimize the adresses so", 54);
    write(1, " that the processes are as far away from each other as", 53);
    write(1, "possible. The addresses are MEM_SIZE modulo.\n", 45);
    return -1;
}

static int parse_flags(int ac, char *argv[], int *i, flags_t *flag)
{
    if (argv[*i][1] == 'h')
        return print_help();
    if (*i == ac - 1)
        return -1;
    switch (argv[*i][1]) {
        case 'd':
            return check_dump_flag(ac, argv, i, flag);
        case 'a':
            return check_a_flag(ac, argv, i, flag);
        case 'n':
            return check_n_flag(ac, argv, i, flag);
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
            ret = parse_flags(ac, argv, &i, &champ);
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
