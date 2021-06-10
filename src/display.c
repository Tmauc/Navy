/*
** EPITECH PROJECT, 2018
** display
** File description:
** navy
*/

#include <navy.h>

extern navy_t *navy;

void display_map(char **map)
{
	int j;

	my_putstr(" |A B C D E F G H\n");
	my_putstr("-+---------------\n");
	for (int i = 0; i < 8; i++) {
		my_putchar(i + 49);
		my_putchar('|');
		for (j = 0; j < 7; j++) {
			my_putchar(map[i][j]);
			my_putchar(' ');
		}
		my_putchar(map[i][j]);
		my_putchar('\n');
	}
}

void display_pos(void)
{
	my_putstr("\nmy positions:\n");
	display_map(navy->map);
	my_putstr("\nenemy's positions:\n");
	display_map(navy->enemy_map);
}
