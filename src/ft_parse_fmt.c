/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_fmt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 14:51:36 by jsoh              #+#    #+#             */
/*   Updated: 2025/06/22 16:15:42 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	ft_parse_flag(char *c, t_fmt *parsed)
{
	if (!c)
		return (0);
	if (*c == '-')
		parsed->minus = 1;
	if (*c == '+')
		parsed->plus = 1;
	if (*c == ' ')
		parsed->space = 1;
	if (*c == '#')
		parsed->hash = 1;
	if (*c == '0')
		parsed->zero = 1;
	return (1);
}

static void	ft_parse_precision(const char **str, int *precision)
{
	if (**str == '.' )
	{
		(*str)++;
		if (**str == '*')
		{
			*precision = -1;
			(*str)++;
		}
		else if (ft_isdigit(**str))
		{
			*precision = ft_atoi(*str);
			while (ft_isdigit(**str) && **str)
				(*str)++;
		}
		else
			*precision = 0;
	}
}

static void	ft_parse_width(const char **str, int *width)
{
	if (**str == '*')
	{
		*width = -1;
		(*str)++;
	}
	else if (ft_isdigit(**str))
	{
		*width = ft_atoi(*str);
		while (ft_isdigit(**str) && **str)
			(*str)++;
	}
}

static void	ft_init_fmt(t_fmt *parsed)
{
	parsed->minus = 0;
	parsed->plus = 0;
	parsed->space = 0;
	parsed->hash = 0;
	parsed->zero = 0;
	parsed->width = -2;
	parsed->precision = -2;
	parsed->specifier = '\0';
}

//% [flags] [width] [.precision] specifier
//% marker will be used externally to call this function
t_fmt	*ft_parse_fmt(const char **str)
{
	t_fmt	*parsed;

	parsed = (t_fmt *) malloc(sizeof(t_fmt));
	if (!parsed || !(*str) || !(**str))
		return (NULL);
	ft_init_fmt(parsed);
	while (**str && ft_parse_flag(ft_strchr(FLAGS, **str), parsed))
		(*str)++;
	ft_parse_width(str, &parsed->width);
	ft_parse_precision(str, &parsed->precision);
	if (ft_strchr(SPECIFIERS,**str))
	{
		parsed->specifier = *ft_strchr(SPECIFIERS,**str);
		(*str)++;
	}
	else
	{
		free(parsed);
		return (NULL);
	}
	return (parsed);
}
