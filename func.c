/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoganesy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 22:31:19 by eoganesy          #+#    #+#             */
/*   Updated: 2025/04/03 22:31:22 by eoganesy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	my_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s[i])
		return (write(1, "(null)", 6));
	while (s[i])
	{
		write (1, &s[i], 1);
		i++;
	}
	return (i);
}

int	my_itoa(int n)
{
	char	*arr;
	int		len;
	int		i;
	long	c;

	len = lenint(n);
	arr = (char *)malloc(sizeof(char) * len + 1);
	if (!arr)
		return (write(1, "(null)", 6));
	i = len - 1;
	c = n;
	if (c < 0)
	{
		c = (-1) * c;
		arr[0] = '-';
	}
	while (c / 10 > 0)
	{
		arr[i--] = c % 10 + '0';
		c /= 10;
	}
	arr[i] = c % 10 + '0';
	arr[len] = '\0';
	return (my_putstr(arr));
}

int	my_itoa_unsigned(unsigned int n)
{
	char	*arr;
	int		len;
	int		i;
	int		len_arr;

	len = lenint(n);
	arr = (char *)malloc(sizeof(char) * len + 1);
	if (!arr)
		return (write(1, "(null)", 6));
	i = len - 1;
	while (n / 10 > 0)
	{
		arr[i--] = n % 10 + '0';
		n /= 10;
	}
	arr[i] = n % 10 + '0';
	arr[len] = '\0';
	len_arr = my_putstr(arr);
	return (len_arr);
}

int	my_hexadecimal(unsigned int n, char c)
{
	char	arr[15];
	int		j;
	int		i;
	char	swap;

	i = 0;
	j = 0;
	while (n > 0)
	{
		if ((n % 16) >= 10)
			arr[i++] = n % 16 - 10 + c;
		else
			arr[i++] = n % 16 + '0';
		n /= 16;
	}
	if (i == 0)
		arr[i++] = '0';
	arr[i] = '\0';
	while (i - 1 > j)
	{
		swap = arr[j];
		arr[j++] = arr[i - 1];
		arr[i-- - 1] = swap;
	}
	return (my_putstr(arr));
}

int	my_ptr(void *ptr)
{
	unsigned long	address;

	address = (unsigned long) ptr;
	write(1, "0x", 2);
	return (my_hexadecimal(address, 'a') + 2);
}
