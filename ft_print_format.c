/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 21:49:42 by jsoh              #+#    #+#             */
/*   Updated: 2025/06/06 22:24:13 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"
#include <stdarg.h>

//This must take in va_list, width and precision will consume additional argument if specified as -1
//# define SPECIFIERS "cspdiuxX%"
//% [flags] [width] [.precision] specifier
void ft_print_format(const char **s, t_fmt *fmt, va_list *ap)
{
	char	*to_print;

	if (fmt -> specifier == 'c')
		to_print = "char";
	if (fmt -> specifier == 's')
		to_print = "string";
	if (fmt -> specifier == 'p')
		to_print = "void ptr arg";
	if (fmt -> specifier == 'd')
		to_print = "decimal base 10";
	if (fmt -> specifier == 'i')
		to_print = "integer";
	if (fmt -> specifier == 'u')
		to_print = "unsigned decimal base 10";
	if (fmt -> specifier == 'x')
		to_print = "lowercase hexadecimal";
	if (fmt -> specifier == 'X')
		to_print = "uppercase hexadecimal";
}
