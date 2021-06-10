/*
** EPITECH PROJECT, 2018
** navy
** File description:
** handle error
*/

#include <navy.h>

int is_num(char *str)
{
	for (int i = 0; str[i] != '\0'; i++)
		if (str[i] < '0' || str[i] > '9')
			return (0);
	return (1);
}

int my_error(int ac, char **av)
{
	if (ac != 2 && ac != 3)
		return (my_help(-1));
	if (ac == 3 && !is_num(av[1]))
		return (my_help(-1));
	return (0);
}
