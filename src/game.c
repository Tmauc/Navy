/*
** EPITECH PROJECT, 2018
** game
** File description:
** navy
*/

#include "navy.h"

extern navy_t *navy;

void send_quit(pid_t enemy_pid)
{
	kill(enemy_pid, SIGUSR2);
	usleep(10000);
	kill(enemy_pid, SIGUSR2);
	usleep(10000);
}

int get_input(void)
{
	char *input = malloc(sizeof(char));

	if (input == NULL)
		return (-1);
	while (navy->current_box == NULL || navy->current_box[0] == 0) {
		free(input);
		free(navy->current_box);
		my_putstr("\nattack: ");
		input = get_next_line(0);
		if (input == NULL) {
			send_quit(navy->pd_enemy);
			return (-1);
		}
		navy->current_box = check_box(input);
		if (navy->current_box == NULL)
			my_putstr("wrong position\n");
	}
	attack_signal(input);
	free(input);
	return (0);
}

int reinitiate_current_box(void)
{
	navy->current_box = malloc(sizeof(int) * 3);
	if (navy->current_box == NULL)
		return (-1);
	for (int i = 0; i < 3; i++)
		navy->current_box[i] = 0;
	return (0);
}

int play_turn(void)
{
	int end = 0;

	if (navy->turn % 2 == 1) {
		if (wait_enemy() == -1) {
			free(navy->current_box);
			return (84);
		}
	} else if (get_input() == -1)
		return (84);
	end = is_a_winer(navy);
	if (end != -1)
		return (end);
	return (0);
}

int manage_game(void)
{
	int turn = navy->turn;
	int end = 0;

	navy->win = 0;
	while (!navy->win) {
		if (reinitiate_current_box() == -1)
			return (84);
		else if (navy->turn % 2 == turn)
			display_pos();
		end = play_turn();
		if (end) {
			display_pos();
			return (end);
		}
	}
	return (0);
}
