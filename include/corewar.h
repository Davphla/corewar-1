/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** Header file for the Corewar project
*/

#ifndef COREWAR_H_
    #define COREWAR_H_

    #include "op.h"
    #include "minilib.h"

    #include <unistd.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <stdbool.h>

    #define MAX_P 4
    #define MIN_P 2

// Struct for every champions personnals data //
typedef struct champion_s {
    char *name;
    char *comment;
    int reg[REG_NUMBER];
    int PC;
    int clock;
    int num_flag;
    char *adress_flag;
} champion_t;

// Struct info with every usefull global data //
typedef struct war_s {
    int cycle;
    int dump;
    int nb_champ;
    unsigned char *vm;
    champion_t **champs;
} war_t;

int corewar(war_t *war);

// Parsing functions //
war_t *init_war(int ac, char *argv[]);
war_t *init_struct_war(void);
champion_t **init_champ_array(void);
int print_help(void);
champion_t *parse_champ(char *arg, champion_t *champ);

// Utils functions //
void war_correct_nb(war_t *war);

// Free functions //
void free_war(war_t *war);
void free_champ_array(war_t *war);

#endif /* COREWAR_H_ */
