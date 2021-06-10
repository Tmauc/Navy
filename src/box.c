/*
** EPITECH PROJECT, 2018
** box
** File description:
** navy
*/

#include <navy.h>

int *check_box(char *place)
{
	int *box = malloc(sizeof(int) * 3);
	char *lettres = "ABCDEFGH";
	char *numbers = "12345678";
	int i;

	box[0] = 0;
	box[1] = 0;
	if (my_strlen(place) != 2 || place[1] == '0')
		return (NULL);
	for (i = 0; i < 8; i++) {
		(place[0] == lettres[i]) ? (box[0] = i + 1) : (1);
		(place[1] == numbers[i]) ? (box[1] = i + 1) : (1);
	}
	if (box[0] == 0 || box[1] == 0)
		return (NULL);
	return (box);
}
