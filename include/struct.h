/*
** EPITECH PROJECT, 2018
** navy
** File description:
** struct
*/

#ifndef STRUCT
#define STRUCT

struct navy {
	pid_t pd;
	pid_t pd_enemy;
	char **map;
	char **enemy_map;
	int *current_box;
	int turn;
	int win;
};

typedef struct navy navy_t;

#endif
