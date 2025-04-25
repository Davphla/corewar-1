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
    return 0;
}
