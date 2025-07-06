/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:54:57 by jsoh              #+#    #+#             */
/*   Updated: 2025/05/16 23:13:40 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup_s;
	size_t	i;
	size_t	len_s;

	i = 0;
	len_s = ft_strlen(s);
	dup_s = (char *)malloc(len_s + 1);
	if (!dup_s)
		return (NULL);
	while (i < len_s)
	{
		dup_s[i] = s[i];
		i++;
	}
	dup_s[i] = '\0';
	return (dup_s);
}
