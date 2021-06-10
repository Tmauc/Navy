/*
** EPITECH PROJECT, 2017
** my_getnbr
** File description:
** char to int
*/

#include "my.h"

int my_getnbr_sign(char const *str)
{
	int i = 0;
	int n = 0;

	while ((str[i] < 48 || str[i] > 57) && str[i] != '\0')
		i = i + 1;
	while (str[i - n - 1] == 45)
		n = n + 1;
	n = n % 2;
	return (n);
}

int overflow(int f, int i, char const *str, int length)
{
	int overflow = 214748364;

	if (length == 10 && i == 9) {
		if (overflow < f)
			return (1);
		if (overflow == f && str[i] >= 56 && str[i] <= 57)
			return (1);
	}
	if (length > 10)
		return (1);
	return (0);
}

int my_number(char const *str, int sign)
{
	int i = 0;
	int f = 0;
	int length;

	while ((str[i] < 48 || str[i] > 57) && str[i] != '\0')
		i = i + 1;
	length = i;
	while (str[length] != '\0' && str[length] >= 48 && str[length] <= 57)
		length = length + 1;
	while (str[i] != '\0' && str[i] >= 48 && str[i] <= 57) {
		f = (10 * f) + (str[i] - 48);
		i = i + 1;
		if (overflow(f, i, str, length) == 1)
			return (0);
	}
	if (sign == 1)
		f = -f;
	return (f);
}

int my_getnbr(char const *str)
{
	int sign = my_getnbr_sign(str);
	int f = my_number(str, sign);

	return (f);
}
