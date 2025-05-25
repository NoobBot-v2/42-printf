/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 13:04:17 by jsoh              #+#    #+#             */
/*   Updated: 2025/05/25 16:29:25 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdarg.h>

//To be put in header file
#define SPECIFIERS "cspdiuxX%"
#define FLAGS "-+ #0."

typedef struct s_flags {
	int minus;
	int plus;
	int space;
	int hash;
	int zero;
	int width;
	int precision;
	char specifier;
} t_flags;

void ft_print_format(const char **s, t_flags parsed, va_list *ap);
t_flags ft_parse_flag(const char **s);

int	ft_printf(const char *fmt, ...)
{
	va_list ap;
	t_flags parsed;

	va_start(ap, fmt);
	//va_arg does not know when ... ends, depends on the expected inputs parsed from fmt
	//va_arg(ap, int);//Depends on the type input when parsing
	while (*fmt)
	{
		if (*fmt == '%')
			ft_print_format(&fmt, ft_parse_flag(&fmt), &ap);//Takes parsed and va_arg and prints to output
		else
		{
			ft_putchar_fd(*fmt,1);
			fmt++;//Maybe put this into ft_putchar_fd to save lines
		}
	}
	va_end(ap);
}
