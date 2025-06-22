/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 22:31:04 by jsoh              #+#    #+#             */
/*   Updated: 2025/06/22 16:15:35 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_print_width(t_fmt *fmt, char *s, char pad_char)
{
	int	pad_len;
	int	str_len;
	int	printed_count;

	printed_count = 0;
	str_len = (int) ft_strlen(s);
	if (fmt -> precision > str_len)
		pad_len = fmt -> width - fmt -> precision;
	else if (fmt -> width > str_len)
		pad_len = fmt -> width - str_len;
	else
		pad_len = 0;
	if (fmt -> hash)
		pad_len = pad_len - 2;
	if (fmt -> precision == 0 && str_len == 1 && *s == '0'
		&& fmt -> width > 0)
		pad_len++;
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
