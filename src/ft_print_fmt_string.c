/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_fmt_string.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 22:37:17 by jsoh              #+#    #+#             */
/*   Updated: 2025/07/06 14:55:31 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	ft_padding(int width)
{
	int	printed_count;

	printed_count = 0;
	while (width > 0)
	{
		ft_putchar_fd(' ', 1);
		width--;
		printed_count++;
	}
	return (printed_count);
}

static int	ft_print_substring(char *s1, int print_len)
{
	int	printed_count;

	printed_count = 0;
	while (print_len)
	{
		ft_putchar_fd(*s1, 1);
		s1++;
		print_len--;
		printed_count++;
	}
	return (printed_count);
}

int	ft_print_fmt_string(char *s1, t_fmt *fmt)
{
	int	print_len;
	int	printed_count;

	printed_count = 0;
	if (!s1)
		s1 = "(null)";
	if (fmt->precision >= 0 && fmt->precision < (int)ft_strlen(s1))
		print_len = fmt->precision;
	else
		print_len = (int)ft_strlen(s1);
	if (fmt -> minus)
	{
		printed_count += ft_print_substring(s1, print_len);
		printed_count += ft_padding(fmt -> width - print_len);
	}
	else
	{
		printed_count += ft_padding(fmt -> width - print_len);
		printed_count += ft_print_substring(s1, print_len);
	}
	return (printed_count);
}
