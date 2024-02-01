/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigran <tigran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 01:32:40 by tigran            #+#    #+#             */
/*   Updated: 2024/02/02 02:47:34 by tigran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int _print_single(const int nb, const char* const base)
{
    return (write(1, base + nb, 1));
}

int ft_putarg(const unsigned int nb, const char* const base)
{
    size_t  base_len;

    base_len = ft_strlen(base);
    if (nb < base_len)
        return (_print_single(nb, base));
    return (ft_putarg(nb / base_len, base) + ft_putarg(nb % base_len, base));
}

int	ft_putnbr_signed(long long n)
{
	if (n < 0)
		return (ft_putch('-') + ft_putarg(-n, "0123456789"));
	return (ft_putarg(n, "0123456789"));
}

int ft_putstr(const char *str)
{
    int len;

    len = 0;
    while (*str)
    {
        len += write(1, str, 1);
        ++str;
    }
    return (len);
}

int ft_putch(char ch)
{
    return (write(1, &ch, 1));
}

static int  _print(const char *str, va_list list)
{
    if (*str == 'i' || *str == 'd')
        return (ft_putnbr_signed(va_arg(list, int)));
    // else if (*str == 'p')
    //     return (ft_putarg(str, list));
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
}


int ft_printf(const char *str, ...)
{
    va_list list;
    size_t  i;
    size_t  len;

    va_start(list, str);
    i = 0;
    len = 0;
    while (str[i] != '\0')
    {
        if (str[i] == '%')
        {
            len += _print(str + i + 1, list);
            ++i;
        }
        else
            len += write(1, str + i, 1);
        ++i;
    }
    return (len);
}

#include <stdio.h>

int main () {
    char ch[] = "jan axper jan";
    int num = INT_MIN;
    int len = ft_printf("%s %s mda %%%d\n", ch, ch, num);
    printf("%d\n", len);
    len = printf("%s %s mda %%%d\n", ch, ch, num);
    printf("%d\n", len);
}