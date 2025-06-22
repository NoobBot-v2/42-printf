/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 21:49:42 by jsoh              #+#    #+#             */
/*   Updated: 2025/06/22 16:19:28 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
//This must take in va_list, width and precision 
//will consume additional argument if specified as -1
//-2 means undefined for width/precision
//# define SPECIFIERS "cspdiuxX%"
//% [flags] [width] [.precision] specifier
static void	ft_check_va_width(t_fmt *fmt, va_list *ap)
{
	int	w;

	if (fmt -> width == -1)
	{
		w = va_arg(*ap, int);
		if (w < 0)
		{
			fmt -> minus = 1;
			fmt -> width = -w;
		}
		else
			fmt -> width = w;
	}
}

static void	ft_check_va_precision(t_fmt *fmt, va_list *ap)
{
	int	p;

	if (fmt -> precision == -1)
	{
		p = va_arg(*ap, int);
		if (p < 0)
			fmt -> precision = -2;
		else
			fmt -> precision = p;
	}
}

int	ft_print_format(t_fmt *fmt, va_list *ap)
{
	int	printed_count;

	ft_check_va_width(fmt, ap);
	ft_check_va_precision(fmt, ap);
	if (fmt -> specifier == 'c')
		printed_count = ft_print_fmt_char((char)va_arg(*ap, int), fmt);
	if (fmt -> specifier == 's')
		printed_count = ft_print_fmt_string(va_arg(*ap, char *), fmt);
	if (fmt -> specifier == 'p')
		printed_count = ft_print_fmt_ptr(va_arg(*ap, void *), fmt);
	if (fmt -> specifier == 'd' || fmt -> specifier == 'i')
		printed_count = ft_print_fmt_number(va_arg(*ap, int), fmt);
	if (fmt -> specifier == 'u')
		printed_count = ft_print_fmt_unsigned(va_arg(*ap, unsigned int), fmt);
	if (fmt -> specifier == 'x' || fmt -> specifier == 'X')
		printed_count = ft_print_fmt_hex(va_arg(*ap, unsigned int), fmt);
	if (fmt -> specifier == '%')
		printed_count = ft_print_string("%");
	return (printed_count);
}
