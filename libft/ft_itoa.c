/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 22:35:47 by jsoh              #+#    #+#             */
/*   Updated: 2025/05/16 23:11:13 by jsoh             ###   ########.fr       */
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

static unsigned int	ft_check_n(int n)
{
	unsigned int	temp_n;

	if (n == INT_MIN)
		temp_n = 2147483648U;
	else if (n < 0)
		temp_n = (unsigned int)-n;
	else
		temp_n = (unsigned)n;
	return (temp_n);
}

char	*ft_itoa(int n)
{
	unsigned int	temp_n;
	char			temp_str[12];
	size_t			i;

	i = 0;
	temp_n = ft_check_n(n);
	while (temp_n >= 10)
	{
		temp_str[i] = (temp_n % 10) + '0';
		temp_n /= 10;
		i++;
	}
	temp_str[i] = temp_n + '0';
	if (n < 0)
		temp_str[++i] = '-';
	ft_reverse(temp_str, i + 1);
	temp_str[++i] = '\0';
	return (ft_to_strptr(temp_str));
}
