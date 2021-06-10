/*
** EPITECH PROJECT, 2017
** my_putstr
** File description:
** my_putstr
*/

#include <unistd.h>

void my_putstr(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++);
	write(1, str, i);
}
