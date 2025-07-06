/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_fmt_hex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 18:49:32 by jsoh              #+#    #+#             */
/*   Updated: 2025/07/06 14:18:05 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	ft_hash(t_fmt *fmt)
{
	if (fmt -> hash)
	{
		if (fmt -> specifier == 'X')
			ft_putstr_fd("0X", 1);
		else
			ft_putstr_fd("0x", 1);
		return (2);
	}
	return (0);
}

static int	ft_hash_precision_putstr(t_fmt *fmt, char *hex_str)
{
	int	printed_count;

	printed_count = 0;
	printed_count += ft_hash(fmt);
	printed_count += ft_print_precision(fmt, hex_str, '0');
	printed_count += ft_print_string(hex_str);
	return (printed_count);
}

static int	ft_justification(t_fmt *fmt, char *hex_str)
{
	int	printed_count;

	printed_count = 0;
	if (fmt -> minus)
	{
		printed_count += ft_hash_precision_putstr(fmt, hex_str);
		printed_count += ft_print_width(fmt, hex_str, ' ');
	}
	else
	{
		printed_count += ft_print_width(fmt, hex_str, ' ');
		printed_count += ft_hash_precision_putstr(fmt, hex_str);
	}
	return (printed_count);
}

int	ft_print_fmt_hex(unsigned int hex_num, t_fmt *fmt)
{
	char	*hex_str;
	int		printed_count;

	printed_count = 0;
	hex_str = ft_to_hexbase(hex_num);
	if (fmt -> specifier == 'X')
		ft_uppercase(hex_str);
	if (fmt -> precision == 0 && (int)ft_strlen(hex_str)
		== 1 && *hex_str == '0')
		printed_count += ft_print_width(fmt, hex_str, ' ');
	else if (fmt -> zero && fmt -> minus == 0 && fmt -> precision == -2)
	{
		printed_count += ft_hash(fmt);
		printed_count += ft_print_width(fmt, hex_str, '0');
		printed_count += ft_print_string(hex_str);
	}
	else
		printed_count += ft_justification(fmt, hex_str);
	free(hex_str);
	return (printed_count);
}
