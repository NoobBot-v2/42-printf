/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to_hexbase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 22:35:47 by jsoh              #+#    #+#             */
/*   Updated: 2025/06/06 23:28:35 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"
#include <stdint.h>

static void	ft_reverse(char s[], int posn)
{
	int		left;
	int		right;
	char	temp;

	left = 0;
	right = posn - 1;
	while (left < right)
	{
		temp = s[left];
		s[left] = s[right];
		s[right] = temp;
		left++;
		right--;
	}
}

char	*ft_to_hexbase(uintptr_t uptr)
{
	char	temp_str[17];
	size_t	i;

	i = 0;
	while (uptr >= 16)
	{
		if (uptr % 16 > 9)
			temp_str[i] = 'a' + ((uptr % 16) - 10);
		else
			temp_str[i] = '0' + (uptr % 16);
		uptr /= 16;
		i++;
	}
	temp_str[i] = uptr + '0';
}
