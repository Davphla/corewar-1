/*
** EPITECH PROJECT, 2025
** Corewar
** File description:
** File that handle the parsing of the .cor file
*/

#include "corewar.h"

static int read_champ(FILE *fd, champion_t *champ, unsigned char *vm,
    int adress)
{
    header_t header;
    unsigned char data;

    fread(&header, sizeof(header_t), 1, fd);
    if (change_endians(header.magic) != COREWAR_EXEC_MAGIC)
        return -1;
    my_strcpy(champ->name, header.prog_name);
    my_strcpy(champ->comment, header.comment);
    champ->size = change_endians(header.prog_size);
    for (int i = 0; i < champ->size; i++) {
        fread(&data, sizeof(unsigned char), 1, fd);
        vm[(adress + i) % MEM_SIZE] = data;
    }
    return 0;
}

static void update_adress(champion_t *champ, int *champ_adress, int *adress)
{
    if (*champ_adress != -1)
        *adress = *champ_adress;
    else
        *champ_adress = *adress;
    ((process_t *)(champ->process_list->data))->PC = *adress;
}

int parse_champ(unsigned char *vm, int adress, char *champ_name,
    champion_t *champ)
{
    FILE *fd = NULL;

    fd = fopen(champ_name, "r");
    if (my_strlen(champ_name) < 4
        || my_strcmp(&champ_name[my_strlen(champ_name) - 4], ".cor") != 0
        || fd == NULL) {
        if (fd != NULL)
            fclose(fd);
        free_champ(champ);
        return -1;
    }
    update_adress(champ, &champ->adress, &adress);
    if (read_champ(fd, champ, vm, adress) == -1) {
        fclose(fd);
        free_champ(champ);
        return -1;
    }
    fclose(fd);
    return 0;
}
