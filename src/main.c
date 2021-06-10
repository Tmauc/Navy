/*
** EPITECH PROJECT, 2018
** navy
** File description:
** main
*/

#include <navy.h>

navy_t *navy;

int my_help(int ret)
{
	my_putstr("USAGE\n\t./navy [first_player_pid] navy_positions\n");
	my_putstr("DESCRIPITON\n\tfirst_player_pid: ");
	my_putstr("only for the 2nd player. pid of the first player.\n");
	my_putstr("navy_positions: file representing ");
	my_putstr("the positions of the ships.\n");
	return (ret);
}

int main(int ac, char **av)
{
	int j_one = 0;

	if (my_error(ac, av))
		return (84);
	if (ac == 2 && my_strcmp(av[1], "-h") == 0)
		return (my_help(0));
	j_one = ac - 1;
	return (begin(j_one, av));
}
