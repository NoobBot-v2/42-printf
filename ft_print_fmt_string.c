/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_fmt_string.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 22:37:17 by jsoh              #+#    #+#             */
/*   Updated: 2025/06/15 14:43:03 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"

static void	ft_padding(int width)
{
	while (width > 0)
	{
		ft_putchar_fd(' ', 1);
		width--;
	}
}

static void	ft_print_substring(char *s1, int print_len)
{
	while (print_len)
	{
		ft_putchar_fd(*s1, 1);
		s1++;
		print_len--;
	}
}

//if width is *, it will be handled externally
void	ft_print_fmt_string(char *s1, t_fmt *fmt)
{
	int	print_len;

	if (!s1)
		s1 = "(null)";
	if (fmt -> precision > 0 && fmt -> precision < (int)ft_strlen(s1))
		print_len = fmt -> precision;
	else
		print_len = (int)ft_strlen(s1);
	if (fmt -> minus)
	{
		ft_print_substring(s1, print_len);
		ft_padding(fmt -> width - print_len);
	}
	else
	{
		ft_padding(fmt -> width - print_len);
		ft_print_substring(s1, print_len);
	}
	free(s1);
}
