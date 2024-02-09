/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:52:20 by tyavroya          #+#    #+#             */
/*   Updated: 2024/02/09 16:30:41 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	_print_single(const int nb, const char *const base)
{
	return (write(1, base + nb, 1));
}

int	ft_putarg(const unsigned int nb, const char *const base)
{
	size_t	base_len;

	base_len = ft_strlen(base);
	if (nb < base_len)
		return (_print_single(nb, base));
	return (ft_putarg(nb / base_len, base) + ft_putarg(nb % base_len, base));
}

static int	ft_putptr(unsigned long long const nbr, char const *const base)
{
	size_t	base_length;

	base_length = ft_strlen(base);
	if (nbr < base_length)
		return (ft_putch(base[nbr]));
	return (ft_putptr(nbr / base_length, base) + ft_putptr(nbr % base_length,
			base));
}

int	ft_putptrprep(unsigned long long const ptr)
{
	return (ft_putstr("0x") + ft_putptr(ptr, "0123456789abcdef"));
}
