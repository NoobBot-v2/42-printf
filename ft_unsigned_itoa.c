/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_itoa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 22:35:47 by jsoh              #+#    #+#             */
/*   Updated: 2025/06/21 23:00:33 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

char	*ft_unsigned_itoa(unsigned int n)
{
	char			temp_str[12];
	size_t			i;

	i = 0;
	while (n >= 10)
	{
		temp_str[i] = (n % 10) + '0';
		n /= 10;
		i++;
	}
	temp_str[i] = n + '0';
	ft_reverse(temp_str, i + 1);
	temp_str[++i] = '\0';
	return (ft_to_strptr(temp_str));
}
