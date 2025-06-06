/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_fmt_string.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 22:37:17 by jsoh              #+#    #+#             */
/*   Updated: 2025/06/06 22:39:24 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"

//if width is *, it will be handled externally
void	ft_print_fmt_char(char *s1, t_fmt *fmt)
{
	if (fmt -> minus)
		ft_putstr_fd(s1, 1);
	while ((fmt -> width) > ft_strlen(s1))
	{
		ft_putchar_fd(' ',1);
		fmt -> width--;
	}
	if (!(fmt -> minus))
		ft_putstr_fd(s1, 1);
}
