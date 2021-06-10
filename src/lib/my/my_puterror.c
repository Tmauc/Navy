/*
** EPITECH PROJECT, 2017
** my_puterror.c
** File description:
** print a string on error output
*/

#include "my.h"
#include <unistd.h>

void my_puterror(char *str)
{
	write(2, str, my_strlen(str));
}
