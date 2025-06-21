/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 22:31:04 by jsoh              #+#    #+#             */
/*   Updated: 2025/06/21 23:04:16 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"
#include <stdio.h>

void	ft_print_width(t_fmt *fmt, char *hex_str, char pad_char)
{
	int	pad_len;
	int	precision_len;
	int	width_len;
	int	str_len;

	precision_len = fmt -> precision;
	width_len = fmt -> width;
	str_len = (int) ft_strlen(hex_str);
	if (precision_len > str_len)
		pad_len = width_len - precision_len;
	else if (width_len > str_len)
		pad_len = width_len - str_len;
	else
		pad_len = 0;
	if (fmt -> hash)
		pad_len = pad_len - 2;
	if (precision_len == 0 && str_len == 1 && *hex_str == '0' && width_len > 0)
		pad_len++;
	while (pad_len > 0)
	{
		ft_putchar_fd(pad_char, 1);
		pad_len--;
	}
}

void	ft_print_precision(t_fmt *fmt, char *hex_str, char pad_char)
{
	int	precision_len;
	int	str_len;

	precision_len = fmt -> precision;
	str_len = (int)ft_strlen(hex_str);
	while (precision_len > str_len)
	{
		ft_putchar_fd(pad_char, 1);
		precision_len--;
	}
}

static void	ft_uppercase(char *hex_str)
{
	while (*hex_str)
	{
		*hex_str = ft_toupper(*hex_str);
		hex_str++;
	}
}
