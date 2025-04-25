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

    #define MAX_PLAYER 4
    #define MIN_PLAYER 2

// Struct for every champions personnals data //
typedef struct champion_s {
    char *name;
    int reg[REG_NUMBER];
    int PC;
    int clock;
    int num_flag;
    int adress_flag;
} champion_t;

// Struct info with every usefull global data //
typedef struct war_s {
    int cycle;
    int dump;
    int nb_champ;
    char *vm;
    champion_t *champ;
} war_t;

// Parsing functions //
war_t *init_war(int ac, char *argv[]);
int print_help(void);


#endif /* COREWAR_H_ */
