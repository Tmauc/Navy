/*
** EPITECH PROJECT, 2018
** attack
** File description:
** navy
*/

#include "navy.h"

extern navy_t *navy;

void what_action(int sig)
{
	int x = navy->current_box[0] - 1;
	int y = navy->current_box[1] - 1;

	if (sig == SIGUSR1) {
		my_putstr("hit\n");
		navy->enemy_map[y][x] = 'x';
		navy->turn += 1;
	} else if (sig == SIGUSR2) {
		my_putstr("missed\n");
		navy->enemy_map[y][x] = 'o';
		navy->turn += 1;
	}
}

void get_action(int sig, siginfo_t *signal, void *vo)
{
	(void)vo;
	if (signal->si_pid == navy->pd_enemy)
		what_action(sig);
}

void ks_action(int usr)
{
	if (usr == 1)
		kill(navy->pd_enemy, SIGUSR1);
	else
		kill(navy->pd_enemy, SIGUSR2);
	usleep(10000);
}

void attack_signal(char *box)
{
	struct sigaction act;
	int turn = navy->turn;

	for (int i = 0; i < navy->current_box[0]; i++)
		ks_action(1);
	ks_action(2);
	for (int i = 0; i < navy->current_box[1]; i++)
		ks_action(1);
	ks_action(2);
	my_putchar(box[0]);
	my_putchar(box[1]);
	my_putstr(": ");
	act.sa_sigaction = get_action;
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (turn == navy->turn);
}
