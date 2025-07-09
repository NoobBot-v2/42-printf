/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_fmt_number.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 14:12:17 by jsoh              #+#    #+#             */
/*   Updated: 2025/07/09 21:17:05 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	ft_put_sign(char **s1, t_fmt *fmt)
{
	int	printed_count;

	printed_count = 0;
	if (**s1 == '-')
	{
		printed_count += write(1, "-", 1);
		fmt -> width --;
		(*s1)++;
	}
	else
	{
		if (fmt -> plus)
			printed_count += write(1, "+", 1);
		else if (fmt -> space)
			printed_count += write(1, " ", 1);
	}
	return (printed_count);
}

static int	ft_left_justification(char *s1, t_fmt *fmt)
{
	int	printed_count;

	printed_count = 0;
	printed_count += ft_put_sign(&s1, fmt);
	printed_count += ft_print_precision(fmt, s1, '0');
	printed_count += ft_print_string(s1);
	printed_count += ft_print_width(fmt, s1, ' ');
	return (printed_count);
}

static int	ft_print_w_fmt(char *s1, t_fmt *fmt)
{
	int	printed_count;

	printed_count = 0;
	if (fmt -> minus)
		printed_count += ft_left_justification(s1, fmt);
	else
	{
		if (fmt -> zero && fmt -> precision == -2)
		{
			printed_count += ft_put_sign(&s1, fmt);
			printed_count += ft_print_width(fmt, s1, '0');
			printed_count += ft_print_precision(fmt, s1, '0');
			printed_count += ft_print_string(s1);
		}
		else
		{
			printed_count += ft_print_width(fmt, s1, ' ');
			printed_count += ft_put_sign(&s1, fmt);
			printed_count += ft_print_precision(fmt, s1, '0');
			printed_count += ft_print_string(s1);
		}
	}
	return (printed_count);
}

int	ft_print_fmt_number(int number, t_fmt *fmt)
{
	char	*s1;
	int		printed_count;

	printed_count = 0;
	if (number == 0 && fmt->precision == 0)
	{
		if (fmt -> plus)
		{
			printed_count += ft_print_width(fmt, "", ' ');
			printed_count += write(1, "+", 1);
		}
		else
			printed_count += ft_print_width(fmt, "", ' ');
		return (printed_count);
	}
	if (number == 0)
		s1 = ft_strdup("0");
	else
		s1 = ft_itoa(number);
	printed_count = ft_print_w_fmt(s1, fmt);
	free(s1);
	return (printed_count);
}

