/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fmt_hexbase.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 16:16:50 by jsoh              #+#    #+#             */
/*   Updated: 2025/06/15 19:06:42 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"

// returns the hexadecimal without any formatting
char	*ft_to_hexbase(unsigned int hex_num);
char	*ft_hash_flag(char *hex, t_fmt *fmt);

static void	ft_uppercase(char *hex)
{
	while (*hex != '\0')
	{
		*hex = ft_toupper(*hex);
		hex++;
	}
}

static char	*ft_prepend_precision(char *hex, int precision_len)
{
	int hex_len;
	int padding_len;
	char *result;

	hex_len = (int)ft_strlen(hex);
	padding_len = precision_len - hex_len;
	if (padding_len > 0)
	{
		result = (char *)malloc(precision_len + 1);
		if (!result)
			return (NULL);
		ft_memset(result, '0', padding_len);
		ft_memcpy(result + padding_len, hex, hex_len);
		result[precision_len] = '\0';
		return (result);
	}
	return (ft_strdup(hex));
}

static void	ft_justify_width(char **result, char **hex, t_fmt *fmt)
{
	int	hex_len;
	int	padding_len;
	char padding_char;

	hex_len = (int)ft_strlen(*hex);
	padding_len = fmt->width - hex_len;
	if (fmt->zero && fmt->precision == -2 && !fmt->minus)
		padding_char = '0';
	else
		padding_char = ' ';
	if (fmt->minus)
	{
		ft_memcpy(*result, *hex, hex_len);
		ft_memset(*result + hex_len, padding_char, padding_len);
	}
	else
	{
		ft_memset(*result, padding_char, padding_len);
		ft_memcpy(*result + padding_len, *hex, hex_len);
	}
}

static char	*ft_add_width(char *hex, t_fmt *fmt)
{
	int hex_len;
	int width_len;
	int padding_len;
	char *result;

	hex_len = (int)ft_strlen(hex);
	width_len = fmt->width;
	padding_len = width_len - hex_len;
	if (padding_len > 0)
	{
		result = (char *)malloc(fmt->width + 1);
		if (!result)
			return (NULL);
		ft_justify_width(&result, &hex, fmt);
		result[fmt->width] = '\0';
		return result;
    }
	return (ft_strdup(hex));
}

char	*ft_fmt_hexbase(unsigned int hex_num, t_fmt *fmt)
{
	char *hex;
	char *tmp;

	tmp = ft_to_hexbase(hex_num);
	if (fmt->specifier == 'X')
		ft_uppercase(tmp);
	if (fmt->precision != -2)
		hex = ft_prepend_precision(tmp, fmt->precision);
	else
		hex = ft_strdup(tmp);
	free(tmp);
	if (fmt -> hash)
	{
		tmp = ft_hash_flag(hex, fmt);
		hex = ft_strdup(tmp);
		free(tmp);
	}
	tmp = ft_strdup(hex);
	if (fmt->width != -2)
		hex = ft_add_width(tmp, fmt);
	else
		hex = ft_strdup(tmp);
	free(tmp);
	return (hex);
}
