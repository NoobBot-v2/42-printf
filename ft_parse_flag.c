/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 14:51:36 by jsoh              #+#    #+#             */
/*   Updated: 2025/05/25 16:12:14 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Take in a pointer to a pointer for current location of fmt
/* The overall syntax of a conversion specification is:
%[flags][width][.precision] conversion specifier */

#include "libft/libft.h"

//To be put in header file
#define SPECIFIERS "cspdiuxX%"
#define FLAGS "-+ #0."

typedef struct s_flags {
	int minus;
	int plus;
	int space;
	int hash;
	int zero;
	int width;
	int precision;
	char specifier;
} t_flags;

t_flags ft_parse_flag(const char **s)
{
	t_flags parsed;
	char *start;

	start = *s;
	while (ft_strchr(FLAGS,**s))
		(*s)++;
	if (ft_strchr(SPECIFIERS,**s))
		return (parsed);//Valid specifier
	else
		return (parsed);//Invalid character for specifier
	return (parsed);
}