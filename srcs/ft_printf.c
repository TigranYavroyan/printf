/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tyavroya <tyavroya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 01:32:40 by tigran            #+#    #+#             */
/*   Updated: 2024/02/09 16:16:33 by tyavroya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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

// #include <stdio.h>

// int main () {
//     char ch[] = "jan axper jan";
//     int num = INT_MIN;
//     int len = ft_printf(" NULL %s NULL ", NULL);
//     printf("%d\n", len);
//     len = printf(" NULL %s NULL ", NULL);
//     printf("%d\n", len);

// }
