/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoganesy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 20:51:47 by eoganesy          #+#    #+#             */
/*   Updated: 2025/03/27 20:51:50 by eoganesy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	lenint(long n)
{
	int		l;
	long	c;

	l = 0;
	c = n;
	if (n < 0)
	{
		c = (-1) * c ;
		l++;
	}
	while (c / 10 > 0)
	{
		l++;
		c /= 10;
	}
	l++;
	return (l);
}

int	my_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	check_spec(char specifier, va_list arg)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += my_putchar(va_arg(arg, int));
	else if (specifier == 's')
		count += my_putstr(va_arg(arg, char *));
	else if (specifier == 'd' || specifier == 'i')
		count += my_itoa(va_arg(arg, int));
	else if (specifier == '%')
		count += my_putchar('%');
	else if (specifier == 'u')
		count += my_itoa_unsigned(va_arg(arg, unsigned int));
	else if (specifier == 'x')
		count += my_hexadecimal(va_arg(arg, unsigned int), 'a');
	else if (specifier == 'X')
		count += my_hexadecimal(va_arg(arg, unsigned int), 'A');
	else if (specifier == 'p')
		count += my_ptr(va_arg(arg, void *));
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		count;

	count = 0;
	va_start(arg, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			count += check_spec(*str, arg);
		}
		else
			count += my_putchar(*str);
		str++;
	}
	va_end(arg);
	return (count);
}
// #include <stdio.h>
// #include <limits.h>
// int main()
// {

// 	printf(" %x %x \n", INT_MIN, INT_MAX);
// 	ft_printf(" %x %x\n", INT_MIN, INT_MAX);
// 	printf(" %x %x\n", ULONG_MAX, -ULONG_MAX);
// 	ft_printf(" %x %x\n", ULONG_MAX, -ULONG_MAX);
// 	printf(" %x %x\n", LONG_MIN, LONG_MAX);
// 	ft_printf(" %x %x\n", LONG_MIN, LONG_MAX);
// }