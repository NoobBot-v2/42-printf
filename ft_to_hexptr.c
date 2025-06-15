/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to_hexptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 22:35:47 by jsoh              #+#    #+#             */
/*   Updated: 2025/06/15 16:08:30 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"

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

static char	*ft_to_strptr(char s[])
{
	size_t	i;
	char	*strptr;

	i = ft_strlen(s);
	strptr = (char *)malloc(i + 1);
	if (!strptr)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		strptr[i] = s[i];
		i++;
	}
	strptr[i] = '\0';
	return (strptr);
}

char	*ft_to_hexptr(uintptr_t uptr)
{
	char	temp_str[19];
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
	if (uptr >= 10)
		temp_str[i] = 'a' + (uptr - 10);
	else
		temp_str[i] = '0' + uptr;
	temp_str[++i] = 'x';
	temp_str[++i] = '0';
	ft_reverse(temp_str, i + 1);
	temp_str[++i] = '\0';
	return (ft_to_strptr(temp_str));
}
