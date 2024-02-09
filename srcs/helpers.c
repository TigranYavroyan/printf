/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:42:32 by tyavroya          #+#    #+#             */
/*   Updated: 2024/02/09 16:30:45 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	_print(const char *str, va_list list)
{
	if (*str == 'i' || *str == 'd')
		return (ft_putnbr_signed(va_arg(list, int)));
	else if (*str == 'p')
		return (ft_putptrprep(va_arg(list, long long)));
	else if (*str == '%')
		return (write(1, "%", 1));
	else if (*str == 'x')
		return (ft_putarg(va_arg(list, int), "0123456789abcdef"));
	else if (*str == 'X')
		return (ft_putarg(va_arg(list, int), "0123456789ABCDEF"));
	else if (*str == 'u')
		return (ft_putarg(va_arg(list, int), "0123456789"));
	else if (*str == 'c')
		return (ft_putch(va_arg(list, int)));
	else if (*str == 's')
		return (ft_putstr(va_arg(list, char *)));
	return (0);
}

int	ft_putnbr_signed(long long n)
{
	if (n < 0)
		return (ft_putch('-') + ft_putarg(-n, "0123456789"));
	return (ft_putarg(n, "0123456789"));
}

int	ft_putstr(const char *str)
{
	int	len;

	if (!str)
		return (ft_putstr("(null)"));
	len = 0;
	while (*str)
	{
		len += write(1, str, 1);
		++str;
	}
	return (len);
}

int	ft_putch(char ch)
{
	return (write(1, &ch, 1));
}

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (*str)
	{
		++str;
		++count;
	}
	return (count);
}
