/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 13:04:17 by jsoh              #+#    #+#             */
/*   Updated: 2025/06/22 13:41:27 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"
#include <stdint.h>
#include <stdarg.h>

int	ft_print_format(t_fmt *fmt, va_list *ap);
t_fmt	*ft_parse_fmt(char **str);

//fmt here refers to the string to be printed
int	ft_printf(const char *fmt, ...)
{
	va_list ap;
	int	printed_count;

	printed_count = 0;
	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
			printed_count += ft_print_format(ft_parse_fmt(&fmt), &ap);
		else
		{
			printed_count += write(1, *fmt, 1);
			fmt++;
		}
	}
	va_end(ap);
	return (printed_count);
}
