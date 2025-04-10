/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoganesy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 22:33:20 by eoganesy          #+#    #+#             */
/*   Updated: 2025/04/03 22:33:23 by eoganesy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

int	my_putstr(char *s);
int	my_putnbr(int n);
int	my_putchar(int c);
int	my_itoa(int n);
int	my_itoa_unsigned(unsigned int n);
int	my_ptr(void *ptr);
int	my_hexadecimal(unsigned long int n, char c);
int	lenint(long n);
int	check_spec(char specifier, va_list arg);
int	ft_printf(const char *str, ...);

#endif
