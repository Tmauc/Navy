/*
** EPITECH PROJECT, 2018
** begin
** File description:
** navy
*/

#include <navy.h>

extern navy_t *navy;

void free_navy_t(void)
{
	for (int i = 0; i < 8; i++) {
		free(navy->map[i]);
		free(navy->enemy_map[i]);
	}
	free(navy->map);
	free(navy->enemy_map);
	free(navy);
}

int create_navy_values(int user, char **av)
{
	navy = malloc(sizeof(navy_t));
	if (navy == NULL)
		return (-1);
	navy->turn = 0;
	navy->pd = getpid();
	navy->map = manage_map(av[user]);
	navy->enemy_map = init_map();
	if (navy->map == NULL || navy->enemy_map == NULL) {
		my_puterror("invalid navy positions.\n");
		return (-1);
	}
	return (0);
}

int begin(int user, char **av)
{
	int end = 0;

	if (create_navy_values(user, av) == -1)
		return (84);
	if (connect_players(user, av, navy) == -1) {
		my_puterror("Connection failed.\n");
		return (84);
	}
	navy->turn = user - 1;
	end = manage_game();
	free_navy_t();
	return (end);
}
