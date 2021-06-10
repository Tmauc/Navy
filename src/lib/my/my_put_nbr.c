/*
** EPITECH PROJECT, 2017
** task7
** File description:
** my_put_nbr
*/

#include "my.h"

int my_put_nbr(int nb)
{
	int nombre;

	if (nb < 0) {
		my_putchar('-');
		nb = -nb;
	}
	if (nb > 9)
		my_put_nbr(nb / 10);
	nombre = nb % 10 + 48;
	my_putchar(nombre);
	return (0);
}

int my_unsigned_put_nbr(unsigned int nb)
{
	unsigned int nombre;

	if (nb > 9)
		my_put_nbr(nb / 10);
	nombre = nb % 10 + 48;
	my_putchar(nombre);
	return (0);
}
