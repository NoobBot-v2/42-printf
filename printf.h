/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 12:35:16 by jsoh              #+#    #+#             */
/*   Updated: 2025/06/15 19:06:24 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# define SPECIFIERS "cspdiuxX%"
# define FLAGS "-+ #0"
# include <stdint.h>
# include <stdarg.h>

typedef struct s_fmt {
	int minus;
	int plus;
	int space;
	int hash;
	int zero;
	int width;
	int precision;
	char specifier;
} t_fmt;
#endif