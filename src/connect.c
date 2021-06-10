/*
** EPITECH PROJECT, 2018
** (connect)
** File description:
** navy
*/

#include "navy.h"

extern navy_t *navy;

void receive_sig(int sig, siginfo_t *signal, void *vo)
{
	(void)vo;
	(sig == SIGUSR1) ? (navy->turn = 1) : (1);
	(sig == SIGUSR1) ? (navy->pd_enemy = signal->si_pid) : (1);
}

void wait_sig(void)
{
	struct sigaction act;

	my_putstr("waiting for enemy connection...\n");
	act.sa_sigaction = receive_sig;
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, NULL);
	while (!navy->turn);
	my_putstr("\nenemy connected\n");
	kill(navy->pd_enemy, SIGUSR1);
}

int send_sig(char *enemy_pid)
{
	struct sigaction act;
	int time = 0;

	act.sa_sigaction = receive_sig;
	act.sa_flags = SA_SIGINFO;
	navy->pd_enemy = my_getnbr(enemy_pid);
	kill(navy->pd_enemy, SIGUSR1);
	sigaction(SIGUSR1, &act, NULL);
	while (!navy->turn) {
		usleep(500);
		time++;
		if (time > 500)
			return (-1);
	}
	my_putstr("successfully connected\n");
	return (0);
}

int connect_players(int user, char **av, navy_t *navy)
{
	my_putstr("my_pid: ");
	my_put_nbr(navy->pd);
	write(1, "\n", 1);
	if (user == 1)
		wait_sig();
	else {
		return (send_sig(av[1]));
	}
	return (0);
}
