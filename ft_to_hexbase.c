/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to_hexbase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 18:49:39 by jsoh              #+#    #+#             */
/*   Updated: 2025/06/21 22:22:34 by jsoh             ###   ########.fr       */
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

char	*ft_to_hexbase(unsigned int hex_num)
{
	char	temp_str[19];
	size_t	i;

	i = 0;
	while (hex_num >= 16)
	{
		if (hex_num % 16 > 9)
			temp_str[i] = 'a' + ((hex_num % 16) - 10);
		else
			temp_str[i] = '0' + (hex_num % 16);
		hex_num /= 16;
		i++;
	}
	if (hex_num >= 10)
		temp_str[i] = 'a' + (hex_num - 10);
	else
		temp_str[i] = '0' + hex_num;
	ft_reverse(temp_str, i + 1);
	temp_str[++i] = '\0';
	return (ft_to_strptr(temp_str));
}
