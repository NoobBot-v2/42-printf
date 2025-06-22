/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_fmt_ptr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 22:40:59 by jsoh              #+#    #+#             */
/*   Updated: 2025/06/22 13:07:44 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"

int	ft_print_fmt_ptr(void *ptr, t_fmt *fmt)
{
	char	*s1;
	int		s1_len;
	int		printed_count;

	printed_count = 0;
	s1 = ft_to_hexptr((uintptr_t) ptr);
	s1_len = ft_strlen(s1);
	if (fmt -> minus)
	{
		ft_putstr_fd(s1, 1);
		printed_count = printed_count + ft_print_width(fmt, s1, ' ');
	}
	else
	{
		printed_count = printed_count + ft_print_width(fmt, s1, ' ');
		ft_putstr_fd(s1, 1);
	}
	printed_count = printed_count + s1_len;
	free(s1);
	return (printed_count);
}
