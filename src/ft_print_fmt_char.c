/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_fmt_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 22:22:18 by jsoh              #+#    #+#             */
/*   Updated: 2025/06/22 15:49:28 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_print_fmt_char(char c, t_fmt *fmt)
{
	int	printed_count;

	printed_count = 0;
	if (fmt -> minus)
	{
		ft_putchar_fd(c, 1);
		printed_count++;
	}
	while ((fmt -> width) > 1)
	{
		ft_putchar_fd(' ', 1);
		printed_count++;
		fmt -> width--;
	}
	if (!(fmt -> minus))
	{
		ft_putchar_fd(c, 1);
		printed_count++;
	}
	return (printed_count);
}
