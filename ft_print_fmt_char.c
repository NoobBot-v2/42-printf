/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_fmt_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 22:22:18 by jsoh              #+#    #+#             */
/*   Updated: 2025/06/08 14:54:25 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"

//if width is *, it will be handled externally
void	ft_print_fmt_char(char c, t_fmt *fmt)
{
	if (fmt -> minus)
		ft_putchar_fd(c, 1);
	while ((fmt -> width) > 1)
	{
		ft_putchar_fd(' ', 1);
		fmt -> width--;
	}
	if (!(fmt -> minus))
		ft_putchar_fd(c, 1);
}
