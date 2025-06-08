/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_fmt_i_d.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 14:12:17 by jsoh              #+#    #+#             */
/*   Updated: 2025/06/08 15:42:37 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"

//handles both %i %d
//% [flags] [width] [.precision] specifier
//if width/precision is *, it will be handled externally
//Both support the same flags (+, -, 0, space, width, precision, etc.).
//space is ignored when + is present
//0 is ignored when - is present
//0 is ignored when precision is present

static void	ft_padding(char padding_char, int width)
{
	while (width > 0)
	{
		ft_putchar_fd(padding_char, 1);
		width--;
	}
}

void	ft_print_fmt_i_d(int number, t_fmt *fmt)
{
	char	*s1;
	char	padding_char;
	int		s1_len;

	padding_char = ' ';
	s1 = ft_itoa(number);
	s1_len = ft_strlen(s1);

	if (fmt -> precision == -2 && fmt -> zero)
		padding_char = '0';
	if (fmt -> precision)
	if (fmt -> minus)
	{

	}
	else
	{
		
	}
}
