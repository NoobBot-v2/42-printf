/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 22:31:04 by jsoh              #+#    #+#             */
/*   Updated: 2025/07/09 22:24:48 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	ft_check_sign(t_fmt *fmt, char *s1)
{
	if (fmt->specifier == 'd' || fmt->specifier == 'i')
	{
		if ( *s1 != '-')
		{
			if (fmt->plus)
				fmt->width--;
			else if (fmt->space)
				fmt->width--;	
		}
	}
}

static int	ft_check_hex_value(t_fmt *fmt, char *hex_str)
{
	int	should_hex;

	should_hex = 0;
	if (fmt -> hash && (fmt -> specifier == 'x' || fmt -> specifier == 'X'))
	{
		should_hex = 1;
		if ((int) ft_strlen(hex_str) == 1 && *hex_str == '0')
			should_hex = 0;
	}
	if ((int) ft_strlen(hex_str) == 1
		&& *hex_str == '0' && fmt -> precision == 0)
		fmt -> width ++;
	return (should_hex);
}

int	ft_print_width(t_fmt *fmt, char *s, char pad_char)
{
	int	pad_len;
	int	str_len;
	int	printed_count;

	printed_count = 0;
	pad_len = 0;
	str_len = (int) ft_strlen(s);
	ft_check_sign(fmt, s);
	if (fmt -> precision > str_len)
	{
		pad_len = fmt -> width - fmt -> precision;
		if (*s == '-')
			pad_len--;
	}
	else if (fmt -> width > str_len)
		pad_len = fmt -> width - str_len;
	if (ft_check_hex_value(fmt, s))
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
