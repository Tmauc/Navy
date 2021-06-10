/*
** EPITECH PROJECT, 2018
** navy
** File description:
** header
*/

#ifndef NAVY
#define NAVY

#include <fcntl.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "struct.h"

void my_putchar(char c);
int my_put_nbr(int nb);
int my_strlen(char const *str);
int my_getnbr(char const *str);
int my_putstr(char const *str);
void my_puterror(char *str);
int my_strcmp(char const *s1, char const *s2);
char **str_to_word_array(char *str, char delim);

void display_pos(void);
void attack_signal(char *box);
int my_help(int ret);
int wait_enemy(void);
int manage_game(void);
int is_a_winer(navy_t *navy);
int begin(int user, char **av);
int my_error(int ac, char **av);
int connect_players(int user, char **av, navy_t *navy);
int *check_box(char *place);
char *get_next_line(int fd);
char **init_map(void);
char **manage_map(char *file_name);
char ***read_file(int fd);

#endif
