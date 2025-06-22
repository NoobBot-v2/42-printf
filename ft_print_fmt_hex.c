/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_fmt_hex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 18:49:32 by jsoh              #+#    #+#             */
/*   Updated: 2025/06/22 12:19:24 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"

static void	ft_hash(t_fmt *fmt)
{
	if (fmt -> hash)
	{
		if (fmt -> specifier == 'X')
			ft_putstr_fd("0X", 1);
		else
			ft_putstr_fd("0x", 1);
	}
}

static void	ft_hash_precision_putstr(t_fmt *fmt, char *hex_str)
{
	ft_hash(fmt);
	ft_print_precision(fmt, hex_str, '0');
	ft_putstr_fd(hex_str, 1);
}

static void	ft_justification(t_fmt *fmt, char *hex_str)
{
	if (fmt -> minus)
	{
		ft_hash_precision_putstr(fmt, hex_str);
		ft_print_width(fmt, hex_str, ' ');
	}
	else
	{
		ft_print_width(fmt, hex_str, ' ');
		ft_hash_precision_putstr(fmt, hex_str);
	}
}

void	ft_print_fmt_hex(unsigned int hex_num, t_fmt *fmt)
{
	char	*hex_str;

	hex_str = ft_to_hexbase(hex_num);
	if (fmt -> specifier == 'X')
		ft_uppercase(hex_str);
	if (fmt -> precision == 0 && (int)ft_strlen(hex_str)
		== 1 && *hex_str == '0')
		ft_print_width(fmt, hex_str, ' ');
	else if (fmt -> zero && fmt -> minus == 0 && fmt -> precision == -2)
	{
		ft_hash(fmt);
		ft_print_width(fmt, hex_str, '0');
		ft_putstr_fd(hex_str, 1);
	}
	else
		ft_justification(fmt, hex_str);
	free(hex_str);
}
