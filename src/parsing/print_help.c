/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** Print_help function
*/

#include "corewar.h"

int print_help(void)
{
    write(1, "USAGE\n./corewar ", 16);
    write(1, "[-dump nbr_cycle] [[-n prog_number] [-a load_adress]", 52);
    write(1, " prog_name] [-v] ...\n\n", 22);
    write(1, "DESCRIPTION\n-dump [nbr_cycle]: dumps the memory after", 54);
    write(1, "the nbr_cycle execution (if the round isn't already over)", 57);
    write(1, " with the following format: 32bytes/lines in hexadecimal\n", 57);
    write(1, "-n [prog_number]: sets the next program's number. By ", 53);
    write(1, "default, the first free number in the parameter order\n", 54);
    write(1, "-a [load_address]: sets the next program's loading ", 52);
    write(1, "address. When no address is specified, optimize the ", 53);
    write(1, "adresses so that the processes are as far away from ", 53);
    write(1, "each other as possible. The addresses are MEM_SIZE modulo", 57);
    write(1, ".\n-v: Enable the display\n", 25);
    return 0;
}
