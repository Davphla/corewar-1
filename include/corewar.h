/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** Header file for the Corewar project
*/

#include "minilib.h"
#include "op.h"

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef COREWAR_H_
    #define COREWAR_H_

    #define MAX_P 4
    #define MIN_P 2

// Struct for every champions personnals data //
typedef struct champion_s {
    char name[PROG_NAME_LENGTH];
    char comment[COMMENT_LENGTH];
    int size;
    int reg[REG_NUMBER];
    int PC;
    int clock;
    int num_flag;
    int adress;
} champion_t;

// Struct info with every usefull global data //
typedef struct war_s {
    int cycle;
    int dump;
    int nb_champ;
    unsigned char *vm;
    champion_t **champs;
    int visual;
} war_t;

int corewar(war_t *war);

// Parsing functions //
war_t *init_war(int ac, char *argv[]);
war_t *init_struct_war(void);
champion_t **init_champ_array(void);
int print_help(void);
int parse_champ(unsigned char *vm, int adress, char *champ_name,
    champion_t *champ);

// Utils functions //
void war_correct_nb(war_t *war);
uint32_t change_endians(uint32_t value);
uint16_t change_endians_16(uint16_t value);
void display_vm(unsigned char *vm);

// Free functions //
void free_war(war_t *war);
void free_champ_array(war_t *war);

#endif /* COREWAR_H_ */
