/*
** EPITECH PROJECT, 2018
** win
** File description:
** navy
*/

#include "navy.h"

int check_boat(char boat)
{
	if (boat == 'x')
		return (1);
	return (0);
}

int check_sink_boats(char **map)
{
	int sink_boats = 0;

	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			sink_boats += check_boat(map[i][j]);
	if (sink_boats == 14)
		return (1);
	return (0);
}

int is_a_winer(navy_t *navy)
{
	if (check_sink_boats(navy->enemy_map)) {
		navy->win = 1;
		my_putstr("\nI won\n");
		return (0);
	} else if (check_sink_boats(navy->map)) {
		navy->win = -1;
		my_putstr("\nenemy won\n");
		return (1);
	}
	return (-1);
}
