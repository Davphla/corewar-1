/*
** EPITECH PROJECT, 2025
** B-CPE-200-LYN-2-1-robotfactory-bastien.sukiennik
** File description:
** change_endian.c
*/

#include "corewar.h"

uint32_t change_endians(uint32_t value)
{
    unsigned int left = (value & 0xff000000) >> 24;
    unsigned int middle_left = (value & 0x00ff0000) >> 8;
    unsigned int middle_right = (value & 0x0000ff00) << 8;
    unsigned int right = (value & 0x000000ff) << 24;

    return (left | middle_left | middle_right | right);
}

uint16_t change_endians_16(uint16_t value)
{
    uint16_t left = (value & 0xff00) >> 8;
    uint16_t right = (value & 0x00ff) << 8;

    return (left | right);
}
