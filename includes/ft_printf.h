/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 01:36:15 by tigran            #+#    #+#             */
/*   Updated: 2024/02/09 16:31:02 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <unistd.h>

int		ft_putnbr_signed(long long n);
int		ft_putstr(const char *str);
int		ft_putch(char ch);
int		_print(const char *str, va_list list);
int		ft_printf(const char *str, ...);
int		_print_single(const int nb, const char *const base);
int		ft_putarg(const unsigned int nb, const char *const base);
int		ft_putptrprep(unsigned long long const ptr);
size_t	ft_strlen(const char *str);

#endif // FT_PRINTF_H
