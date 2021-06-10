/*
** EPITECH PROJECT, 2017
** task2
** File description:
** my.h
*/

#ifndef MY_H
#define MY_H

void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
int my_unsignedput_nbr(unsigned int nb);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char*my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int n);
char **my_str_to_word_array(char const *str);
char *my_strdup(char const *src);
int my_show_word_array(char *const *tab);
char *concat_params(int argc, char **argv);
void my_swap(int *a, int *b);
char *int_to_char(int value);
char *unsignedint_to_char(unsigned int value);
int my_putstr(char const *str);
int my_getnbr_base(char *str, char *base);
unsigned unsigned_getnbr_base(char *str, char *base);
char *my_putnbr_base(int nbr, char const *base);
char *unsigned_putnbr_base(unsigned nbr, char const *base);
char *convert_base(char *nb1, char *base_src, char *base_dest);
char *unsigned_convert_base(char *nb1, char *base_src, char *base_dest);

#endif
