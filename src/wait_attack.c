/*
** EPITECH PROJECT, 2018
** wait attack
** File description:
** navy
*/

#include "navy.h"

extern navy_t *navy;

void what_signal(int sig)
{
	if (sig == SIGUSR1 && navy->current_box[2] < 2)
		navy->current_box[navy->current_box[2]] += 1;
	else if (sig == SIGUSR2 && navy->current_box[2] < 2)
		navy->current_box[2] += 1;
	if (navy->current_box[2] >= 2) {
		if (navy->current_box[0] != 0)
			navy->turn += 1;
		else
			navy->turn = -1;
	}
}

void get_attack_signal(int sig, siginfo_t *signal, void *vo)
{
	(void)vo;

	if (signal->si_pid == navy->pd_enemy)
		what_signal(sig);
}

void get_attack(void)
{
	int x = navy->current_box[0] - 1;
	int y = navy->current_box[1] - 1;

	usleep(10000);
	my_putchar(navy->current_box[0] + 64);
	my_putchar(navy->current_box[1] + 48);
	my_putstr(": ");
	if (navy->map[y][x] != '.' && navy->map[y][x] != 'o'
	&& navy->map[y][x] != 'x') {
		my_putstr("hit\n");
		navy->map[y][x] = 'x';
		kill(navy->pd_enemy, SIGUSR1);
	} else {
		my_putstr("missed\n");
		if (navy->map[y][x] != 'x')
			navy->map[y][x] = 'o';
		kill(navy->pd_enemy, SIGUSR2);
	}
}

int wait_enemy(void)
{
	int turn = navy->turn;
	struct sigaction act;

	navy->current_box[2] = 0;
	act.sa_sigaction = get_attack_signal;
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	my_putstr("\nwaiting for enemy's attack...\n");
	while (navy->turn == turn);
	if (navy->turn == -1)
		return (-1);
	get_attack();
	return (0);
}
