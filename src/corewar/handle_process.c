/*
** EPITECH PROJECT, 2025
** B-CPE-200-LYN-2-1-corewar-alexandre.kubiaczyk
** File description:
** handle_process.c
*/

#include "corewar.h"

static int set_new_cycle(war_t *war, process_t *process)
{
    for (int op_nb = 0; op_nb < NBR_OP; op_nb++) {
        if (war->vm[process->PC] == op_tab[op_nb].code) {
            process->cycle = op_tab[op_nb].nbr_cycles;
            return 0;
        }
    }
    process->PC++;
    process->PC %= MEM_SIZE;
    return 0;
}

static int exec_instruction(war_t *war, champion_t *champ, process_t *process)
{
    for (int op_nb = 0; op_nb < NBR_OP; op_nb++) {
        if (war->vm[process->PC] == op_tab[op_nb].code) {
            op_tab[op_nb].func(war, champ, process);
            break;
        }
    }
    return 0;
}

int handle_process(war_t *war, champion_t *champ, process_t *process)
{
    if (process->cycle == -1) {
        set_new_cycle(war, process);
        return 0;
    } else if (process->cycle == 0) {
        exec_instruction(war, champ, process);
        process->PC %= MEM_SIZE;
    }
    process->cycle--;
    return 0;
}
