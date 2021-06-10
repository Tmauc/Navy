/*
** EPITECH PROJECT, 2018
** file
** File description:
** navy
*/

#include "navy.h"

int check_place(char x1, char y1, char x2, char y2)
{
	char x[] = "ABCDEFGH";
	char y[] = "12345678";
	int result = 0;

	if (x1 != x2 && y1 != y2)
		return (-1);
	for (int i = 0; x[i] != '\0'; i++) {
		if (x1 == x[i] || x2 == x[i])
			result += 1;
		if (y1 == y[i] || y2 == y[i])
			result += 1;
	}
	if (result != 3)
		return (-1);
	return (0);
}

int check_read(char *line, char i)
{
	if (line[0] != i || line[1] != ':' ||
		line[4] != ':' || (line[7] != '\n' && line[7] != '\0'))
		return (-1);
	if (check_place(line[2], line[3], line[5], line[6]) == -1)
		return (-1);
	if (line[5] - line[2] + line[6] - line[3] + 48 != i - 1)
		return (-1);
	return (0);
}

char **read_line(int fd, char i)
{
	char **space = NULL;
	char *line = malloc(sizeof(char) * 9);

	read(fd, line, 8);
	line[7] = '\0';
	if (check_read(line, i) == -1) {
		return (NULL);
	}
	space = str_to_word_array(line, ':');
	free(line);
	return (space);
}

char ***read_file(int fd)
{
	char ***all_read = malloc(sizeof(char **) * 5);
	int i = 0;

	if (all_read == NULL)
		return (NULL);
	for (; i < 4; i++) {
		all_read[i] = read_line(fd, i + 50);
		if (all_read[i] == NULL)
			return (NULL);
	}
	if (read(fd, NULL, 1) != 0)
		return (NULL);
	all_read[i] = NULL;
	return (all_read);
}
