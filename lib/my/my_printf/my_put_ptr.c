/*
** EPITECH PROJECT, 2017
** my_put_ptr.c
** File description:
** my_put_ptr
*/

void my_putstr(char *);
void my_putchar(char);
void my_putnbr_base_unsigned(unsigned long int, char *);

void my_put_ptr(void *ptr)
{
	unsigned long int put_ptr = (unsigned long int)ptr;

	if (put_ptr < 0)
		put_ptr = -put_ptr;
	my_putstr("0x");
	my_putnbr_base_unsigned(put_ptr, "0123456789abcedf");
}
