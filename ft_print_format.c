/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 16:16:19 by jsoh              #+#    #+#             */
/*   Updated: 2025/05/25 16:27:59 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdarg.h>

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

//va_list is a pointer, so that after each call, it advances by 1
void ft_print_format(const char **s, t_flags parsed, va_list *ap)
{
	
}