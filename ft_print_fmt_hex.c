/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_fmt_hex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 18:49:32 by jsoh              #+#    #+#             */
/*   Updated: 2025/06/21 22:17:02 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"

static void	ft_print_precision(t_fmt *fmt, char *uptr, char pad_char)
{
	int	precision_len;
	int	str_len;

	precision_len = fmt -> precision;
	str_len = (int)ft_strlen(uptr);
	while(precision_len > str_len)
	{
		ft_putchar_fd(pad_char, 1);
		precision_len--;
	}
}

static void	ft_print_width(t_fmt *fmt, char *uptr, char pad_char)
{
	int	pad_len;
	int	precision_len;
	int	width_len;
	int	str_len;

	precision_len = fmt -> precision;
	width_len = fmt -> width;
	str_len = (int) ft_strlen(uptr);

	if (precision_len > str_len)
		pad_len = width_len - precision_len;
	else if (width_len > str_len)
		pad_len = width_len - str_len;
	else
		pad_len = 0;
	if (fmt -> hash)
		pad_len = pad_len - 2;
	while (pad_len > 0)
	{
		ft_putchar_fd(pad_char, 1);
		pad_len--;
	}
}

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

void	ft_print_fmt_hex(t_fmt *fmt, char *uptr)
{
	if (fmt -> zero && fmt -> minus == 0 && fmt -> precision == -2)
	{
		ft_hash(fmt);
		ft_print_width(fmt, uptr, '0');
		ft_putstr_fd(uptr, 1);
	}
	else
	{
		if (fmt -> minus)
		{
			ft_hash(fmt);
			ft_print_precision(fmt, uptr, '0');
			ft_putstr_fd(uptr, 1);
			ft_print_width(fmt, uptr, ' ');
		}
		else
		{
			ft_print_width(fmt, uptr, ' ');
			ft_hash(fmt);
			ft_print_precision(fmt, uptr, '0');
			ft_putstr_fd(uptr, 1);
		}
	}
}
