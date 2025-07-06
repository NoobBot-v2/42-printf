/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 22:31:04 by jsoh              #+#    #+#             */
/*   Updated: 2025/07/06 19:43:23 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void ft_check_sign(t_fmt *fmt)
{
	if (fmt->specifier == 'd' || fmt->specifier == 'i')
	{
		if (fmt->plus)
			fmt->width--;
		else if (fmt->space)
			fmt->width--;
	}
}

int	ft_print_width(t_fmt *fmt, char *s, char pad_char)
{
	int	pad_len;
	int	str_len;
	int	printed_count;

	printed_count = 0;
	pad_len = 0;
	str_len = (int) ft_strlen(s);
	ft_check_sign(fmt);
	if (fmt -> precision > str_len)
	{
		pad_len = fmt -> width - fmt -> precision;
		if (*s == '-')
			pad_len--;
	}
	else if (fmt -> width > str_len)
		pad_len = fmt -> width - str_len;
	if (fmt -> hash && ( fmt -> specifier == 'x'|| fmt -> specifier == 'X'))
		pad_len = pad_len - 2;
	while (pad_len > 0)
	{
		ft_putchar_fd(pad_char, 1);
		pad_len--;
		printed_count++;
	}
	return (printed_count);
}

int	ft_print_precision(t_fmt *fmt, char *s, char pad_char)
{
	int	precision_len;
	int	str_len;
	int	printed_count;

	printed_count = 0;
	precision_len = fmt -> precision;
	str_len = (int)ft_strlen(s);
	while (precision_len > str_len)
	{
		ft_putchar_fd(pad_char, 1);
		precision_len--;
		printed_count++;
	}
	return (printed_count);
}

void	ft_uppercase(char *s)
{
	while (*s)
	{
		*s = ft_toupper(*s);
		s++;
	}
}

int	ft_print_string(char *s)
{
	return (write(1, s, ft_strlen(s)));
}
