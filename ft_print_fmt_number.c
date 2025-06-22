/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_fmt_number.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 14:12:17 by jsoh              #+#    #+#             */
/*   Updated: 2025/06/22 13:11:46 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"

static void	ft_pad_width(char padding_char, int width)
{
	while (width > 0)
	{
		ft_putchar_fd(padding_char, 1);
		width--;
	}
}

static int	ft_signed_precision(int precision, char **s1, t_fmt *fmt)
{
	int	printed_count;

	printed_count = 0;
	if (**s1 == '-')
	{
		printed_count = write(1, '-', 1);
		(*s1)++;
	}
	else
	{
		if (fmt -> plus)
			printed_count = write(1, '+', 1);
		else if (fmt -> space)
			printed_count = write(1, ' ', 1);
	}
	while (precision > (int)ft_strlen(*s1))
	{
		printed_count += write(1, '0', 1);
		precision--;
	}
	return (printed_count);
}

static void	ft_print_w_fmt(char *s1, t_fmt *fmt, int pad_width)
{
	if (fmt->minus)
	{
		ft_signed_precision(fmt->precision, &s1, fmt);
		ft_putstr_fd(s1, 1);
		ft_pad_width(' ', pad_width);
	}
	else
	{
		if (fmt->zero && fmt->precision <= 0)
			ft_pad_width('0', pad_width);
		else
			ft_pad_width(' ', pad_width);
		ft_signed_precision(fmt->precision, &s1, fmt);
		ft_putstr_fd(s1, 1);
	}
}

static void	ft_width_precision(char *s1, t_fmt *fmt, int number)
{
	int	pad_len;
	int	pad_width;

	if (fmt->precision > (int)ft_strlen(s1))
		pad_len = fmt->precision;
	else
		pad_len = (int)ft_strlen(s1);
	if (fmt->width > pad_len)
		pad_width = fmt->width - pad_len;
	else
		pad_width = 0;
	if (pad_width > 0 && number < 0)
		pad_width--;
	else if (pad_width > 0 && number >= 0 && (fmt -> plus || fmt -> space))
		pad_width--;
	ft_print_w_fmt(s1, fmt, pad_width);
}

void	ft_print_fmt_number(int number, t_fmt *fmt)
{
	char	*s1;

	if (number == 0)
		s1 = "\0";
	else
		s1 = ft_itoa(number);
	ft_width_precision(s1, fmt, number);
	free(s1);
}
