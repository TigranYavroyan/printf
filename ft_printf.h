/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigran <tigran@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 01:36:15 by tigran            #+#    #+#             */
/*   Updated: 2024/02/02 02:38:21 by tigran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <limits.h>

int ft_printf(const char *str, ...);
int ft_putarg(const unsigned int nb, const char* const base);
int	ft_putnbr_signed(long long n);
int ft_putstr(const char *str);
int ft_putch(char ch);

#endif // FT_PRINTF_H