/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** Header file for the Corewar project
*/

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>

#include "minilib.h"
#include "op.h"
#include "list.h"

#ifndef COREWAR_H_
    #define COREWAR_H_

    #define MAX_P 4
    #define MIN_P 2

    #define COLOR_1 1
    #define COLOR_2 2
    #define COLOR_3 3
    #define COLOR_4 4

    #define CURSOR_1 5
    #define CURSOR_2 6
    #define CURSOR_3 7
    #define CURSOR_4 8

typedef struct win_s {
    WINDOW *b_player;
    WINDOW *player;
    WINDOW *b_vm;
    WINDOW *vm;
    WINDOW *b_hist;
    WINDOW *hist;
} win_t;

// Struct for champ process //
typedef struct process_s {
    int reg[REG_NUMBER];
    int PC;
    int cycle;
    bool carry;
} process_t;

// Struct for every champions personnals data //
typedef struct champion_s {
    char name[PROG_NAME_LENGTH];
    char comment[COMMENT_LENGTH];
    int size;
    llist_t *process_list;
    int clock;
    int id;
    int adress;
    int to_die;
    bool alive;
} champion_t;

// Struct info with every usefull global data //
typedef struct war_s {
    int cycle;
    int dump;
    int nb_champ;
    unsigned char *vm;
    champion_t **champs;
    int visual;
    int nbr_live;
    int cycle_to_die;
    champion_t *last_to_live;
} war_t;

// Coding byte union //
typedef union coding_byte_u {
    struct {
        unsigned char fourth : 2;
        unsigned char third : 2;
        unsigned char second : 2;
        unsigned char first : 2;
    };
    unsigned char coding_byte;
} coding_byte_t;

int corewar(war_t *war);

// Parsing functions //
war_t *init_war(int ac, char *argv[]);
war_t *init_struct_war(void);
champion_t **init_champ_array(void);
int print_help(void);
int parse_champ(unsigned char *vm, int adress, char *champ_name,
    champion_t *champ);

// Corewar funcions //
int update_vm(war_t *war, win_t *manager);
void dump(unsigned char *vm);
int handle_champ(war_t *war, champion_t *champ);
int handle_process(war_t *war, champion_t *champ, process_t *process);
// Instructions //
int i_add(war_t *war, champion_t *champ, process_t *process);
int i_aff(war_t *war, champion_t *champ, process_t *process);
int i_and(war_t *war, champion_t *champ, process_t *process);
int i_fork(war_t *war, champion_t *champ, process_t *process);
int i_ld(war_t *war, champion_t *champ, process_t *process);
int i_ldi(war_t *war, champion_t *champ, process_t *process);
int i_lfork(war_t *war, champion_t *champ, process_t *process);
int i_live(war_t *war, champion_t *champ, process_t *process);
int i_lld(war_t *war, champion_t *champ, process_t *process);
int i_lldi(war_t *war, champion_t *champ, process_t *process);
int i_or(war_t *war, champion_t *champ, process_t *process);
int i_st(war_t *war, champion_t *champ, process_t *process);
int i_sti(war_t *war, champion_t *champ, process_t *process);
int i_sub(war_t *war, champion_t *champ, process_t *process);
int i_xor(war_t *war, champion_t *champ, process_t *process);
int i_zjmp(war_t *war, champion_t *champ, process_t *process);

// Utils functions //
void war_correct_nb(war_t *war);
unsigned int change_endians(unsigned int value);
unsigned short change_endians_short(unsigned short value);
int check_winner(war_t *war);
int display_winner(war_t *war);
unsigned char get_coding_byte(unsigned char *vm, int *pc);
int get_direct(unsigned char *vm, int *pc);
short get_ind(unsigned char *vm, int *pc);
unsigned char get_register(unsigned char *vm, int *pc);
process_t *process_dup(process_t *process, int new_pc);
int verify_register(unsigned char register_index);
int set_carry(process_t *process, int result);
int get_value(unsigned char value_type, process_t *process, war_t *war,
    int *error);
int get_value_index(unsigned char value_type, process_t *process, war_t *war,
    int *error);
int write_in_vm(unsigned char *vm, int value, int adress, size_t size);
int normalize_vm_index(int vm_index);

// Free functions //
void free_war(war_t *war);
void free_champ_array(war_t *war);
void free_champ(champion_t *champ);

// Visual Function //
void init_screen(void);
win_t init_manager(void);
void event(char input, war_t *war, win_t *manager);
void ncurse_gameboard(war_t *war, win_t *manager);
void init_visuals(war_t *war);

#endif /* COREWAR_H_ */
