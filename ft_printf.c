/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 13:04:17 by jsoh              #+#    #+#             */
/*   Updated: 2025/06/15 15:00:32 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"
#include <stdint.h>
#include <stdarg.h>

void ft_print_format(const char **s, t_fmt parsed, va_list *ap);
t_fmt ft_parse_fmt(const char **s);

int	ft_printf(const char *fmt, ...)
{
	va_list ap;
	t_fmt parsed;

	va_start(ap, fmt);
	//va_arg does not know when ... ends, depends on the expected inputs parsed from fmt
	//va_arg(ap, int);//Depends on the type input when parsing
	while (*fmt)
	{
		if (*fmt == '%')
			ft_print_format(&fmt, ft_parse_fmt(&fmt), &ap);//Takes parsed and va_arg and prints to output
		else
		{
			ft_putchar_fd(*fmt,1);
			fmt++;//Maybe put this into ft_putchar_fd to save lines
		}
	}
	va_end(ap);
}
