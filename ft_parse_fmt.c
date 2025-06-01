/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_fmt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 14:51:36 by jsoh              #+#    #+#             */
/*   Updated: 2025/06/01 15:54:48 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Take in a pointer to a pointer for current location of fmt

#include "libft.h"
#include "printf.h"

#include <stdio.h>

// # define SPECIFIERS "cspdiuxX%"
// # define FLAGS "-+ #0" 
// # precision flag . will be handled differently
//% [flags] [width] [.precision] [length] specifier

int	ft_parse_flag(char *c, t_fmt *parsed)
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
		parsed->hex = 1;
	if (*c == '0')
		parsed->zero = 1;
	return (1);
}

void	ft_parse_width_precision(char **str, int *ptr)
{
	if (**str == '*')
	{
		*ptr = -1;
		(*str)++;
	}
	else if (ft_isdigit(**str))
	{
		*ptr = ft_atoi(*str);
		while (ft_isdigit(**str))
			(*str)++;
	}
}

void	ft_init_fmt(t_fmt *parsed)
{
	parsed->minus = 0;
	parsed->plus = 0;
	parsed->space = 0;
	parsed->hex = 0;
	parsed->zero = 0;
	parsed->width = -2;
	parsed->precision = -2;
	parsed->specifier = '\0';
}

//% [flags] [width] [.precision] specifier
//parse fmt should move the **str accordingly
t_fmt	*ft_parse_fmt(char **str)
{
	t_fmt	*parsed;

	parsed = (t_fmt *) malloc(sizeof(t_fmt));
	if (!parsed)
		return (NULL);
	ft_init_fmt(parsed);
	if (**str == '%')//testing purposes only
		(*str)++;
	while (ft_parse_flag(ft_strchr(FLAGS, **str), parsed))
		(*str)++;
	ft_parse_width_precision(str, &parsed->width);
	if (**str == '.' )
	{
		(*str)++;
		ft_parse_width_precision(str, &parsed->precision);
	}
	if (ft_strchr(SPECIFIERS,**str))
	{
		printf("%s\n","Specifier logic accessed");
		parsed->specifier = *ft_strchr(SPECIFIERS,**str);
		(*str)++;
	}
	else
	{
		printf("%s\n","Undefined specifier");
		free(parsed);
		return (NULL);
	}
	printf("Width: %d\n",parsed->width);
	printf("Precision: %d\n",parsed->precision);
	printf("%s\n","End of ft_parse_fmt");
	return (parsed);
}
