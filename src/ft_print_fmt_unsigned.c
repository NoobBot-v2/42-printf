/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_fmt_unsigned.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 14:12:17 by jsoh              #+#    #+#             */
/*   Updated: 2025/07/09 21:18:19 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	ft_print_w_fmt(char *s1, t_fmt *fmt)
{
	int	printed_count;

	printed_count = 0;
	if (fmt->minus)
	{
		printed_count += ft_print_precision(fmt, s1, '0');
		printed_count += ft_print_string(s1);
		printed_count += ft_print_width(fmt, s1, ' ');
	}
	else
	{
		if (fmt->zero && fmt->precision == -2)
			printed_count += ft_print_width(fmt, s1, '0');
		else
			printed_count += ft_print_width(fmt, s1, ' ');
		printed_count += ft_print_precision(fmt, s1, '0');
		printed_count += ft_print_string(s1);
	}
	return (printed_count);
}

int	ft_print_fmt_unsigned(unsigned int number, t_fmt *fmt)
{
	char	*s1;
	int		printed_count;

	printed_count = 0;
	if (number == 0 && fmt->precision == 0)
	{
		printed_count += ft_print_width(fmt, "", ' ');
		return (printed_count);
	}
	if (number == 0)
		s1 = ft_strdup("0");
	else
		s1 = ft_unsigned_itoa(number);
	printed_count = ft_print_w_fmt(s1, fmt);
	free(s1);
	return (printed_count);
}
