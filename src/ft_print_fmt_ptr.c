/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_fmt_ptr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 22:40:59 by jsoh              #+#    #+#             */
/*   Updated: 2025/06/22 16:54:42 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

//Only for right justification and with zero flag
int	ft_print_pad_zero(t_fmt *fmt, char *s1)
{
	int	printed_count;

	printed_count = 0;
	printed_count += write(1, "0x", 2);
	printed_count += ft_print_width(fmt, s1, '0');
	printed_count += ft_print_string(s1 + 2);
	return (printed_count);
}

int	ft_print_fmt_ptr(void *ptr, t_fmt *fmt)
{
	char	*s1;
	int		printed_count;

	printed_count = 0;
	if (!ptr)
		return (ft_print_string("(nil)"));
	s1 = ft_to_hexptr((uintptr_t) ptr);
	if (fmt -> minus)
	{
		printed_count += ft_print_string(s1);
		printed_count += ft_print_width(fmt, s1, ' ');
	}
	else
	{
		if (fmt -> zero)
			printed_count += ft_print_pad_zero(fmt, s1);
		else
		{
			printed_count += ft_print_width(fmt, s1, ' ');
			printed_count += ft_print_string(s1);
		}
	}
	return (printed_count);
}
