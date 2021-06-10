/*
** EPITECH PROJECT, 2018
** store_map
** File description:
** navy
*/

#include <navy.h>

char **init_map(void)
{
	char **map = malloc(sizeof(char *) * 9);
	int i = 0;
	int j = 0;

	if (map == NULL)
		return (NULL);
	for (i = 0; i < 8; i++) {
		map[i] = malloc(sizeof(char) * 9);
		if (map[i] == NULL)
			return (NULL);
		for (j = 0; j < 8; j++)
			map[i][j] = '.';
		map[i][j] = '\0';
	}
	map[i] = NULL;
	return (map);
}

int add_a_boat(char **map, char *box, int nb, char axe)
{
	int *place = check_box(box);

	for (int size = nb + 2, i = 0; i < size; i++) {
		if (map[place[1] - 1][place[0] - 1] != '.')
			return (-1);
		map[place[1] - 1][place[0] - 1] = size + 48;
		if (axe == 'h')
			place[1] += 1;
		else
			place[0] += 1;
	}
	free(place);
	return (0);
}

int add_boats(char **map, char ***read)
{
	char axe = 'h';

	for (int i = 0; i < 4; i++) {
		if (read[i][1][0] != read[i][2][0])
			axe = 'v';
		else
			axe = 'h';
		if (add_a_boat(map, read[i][1], i, axe) == -1)
			return (-1);
	}
	return (0);
}

void free_read(char ***read_map)
{
	for (int i = 0; read_map[i] != NULL; i++) {
		for (int j = 0; read_map[i][j] != NULL; j++)
			free(read_map[i][j]);
		free(read_map[i]);
	}
	free(read_map);
}

char **manage_map(char *file_name)
{
	int fd = open(file_name, O_RDONLY);
	char **map = NULL;
	char ***read = NULL;

	if (fd == -1)
		return (NULL);
	map = init_map();
	read = read_file(fd);
	if (map == NULL || read == NULL)
		return (NULL);
	if (add_boats(map, read) == -1)
		return (NULL);
	close(fd);
	free_read(read);
	return (map);
}
