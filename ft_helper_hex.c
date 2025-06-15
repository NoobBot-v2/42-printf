/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 18:05:19 by jsoh              #+#    #+#             */
/*   Updated: 2025/06/15 18:23:41 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"

char	*ft_hash_flag(char *hex, t_fmt *fmt)
{
	int hex_len;
	char *result;

	hex_len = (int)ft_strlen(hex);
	char *result = (char *)malloc(hex_len + 2 + 1);
	if (!result)
		return (NULL);
	result[0] = '0';
	if (fmt -> specifier == 'X')
		result[1] = 'X';
	else
		result[1] = 'x';
	ft_memcpy(result + 2, hex, hex_len);
	result[hex_len + 2] = '\0';
	return result;
}