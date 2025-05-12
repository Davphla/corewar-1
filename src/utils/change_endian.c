/*
** EPITECH PROJECT, 2025
** B-CPE-200-LYN-2-1-robotfactory-bastien.sukiennik
** File description:
** change_endian.c
*/

#include "corewar.h"

unsigned int change_endians(unsigned int value)
{
    unsigned int left = (value & 0xff000000) >> 24;
    unsigned int middle_left = (value & 0x00ff0000) >> 8;
    unsigned int middle_right = (value & 0x0000ff00) << 8;
    unsigned int right = (value & 0x000000ff) << 24;

    return (left | middle_left | middle_right | right);
}

unsigned short change_endians_16(unsigned short value)
{
    unsigned short left = (value & 0xff00) >> 8;
    unsigned short right = (value & 0x00ff) << 8;

    return (left | right);
}
