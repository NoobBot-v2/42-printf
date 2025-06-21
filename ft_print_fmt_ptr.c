/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_fmt_ptr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 22:40:59 by jsoh              #+#    #+#             */
/*   Updated: 2025/06/21 20:56:35 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"

char	*ft_to_hexptr(uintptr_t uptr);

//if width is *, it will be handled externally
void	ft_print_fmt_ptr(void *ptr, t_fmt *fmt)
{
	char	*s1;
	int		s1_len;

	s1 = ft_to_hexptr((uintptr_t) ptr);
	s1_len = ft_strlen(s1);
	if (fmt -> minus)
	{
		ft_putstr_fd(s1, 1);
		while (s1_len < (fmt -> width))
		{
			ft_putchar_fd(' ', 1);
			fmt -> width--;
		}
	}
	else
	{
		while (s1_len < (fmt -> width))
		{
			ft_putchar_fd(' ', 1);
			fmt -> width--;
		}
		ft_putstr_fd(s1, 1);
	}
	free(s1);
}
