/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 12:35:16 by jsoh              #+#    #+#             */
/*   Updated: 2025/06/22 16:20:39 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# define SPECIFIERS "cspdiuxX%"
# define FLAGS "-+ #0"
# include <stdint.h>
# include <stdarg.h>
# include <stdlib.h>
# include "libft.h"

typedef struct s_fmt
{
	int		minus;
	int		plus;
	int		space;
	int		hash;
	int		zero;
	int		width;
	int		precision;
	char	specifier;
}	t_fmt;

int		ft_print_fmt_char(char c, t_fmt *fmt);
int		ft_print_fmt_string(char *s1, t_fmt *fmt);
int		ft_print_fmt_number(int number, t_fmt *fmt);
int		ft_print_fmt_ptr(void *ptr, t_fmt *fmt);
int		ft_print_fmt_unsigned(unsigned int number, t_fmt *fmt);
int		ft_print_fmt_hex(unsigned int hex_num, t_fmt *fmt);
int		ft_print_width(t_fmt *fmt, char *s, char pad_char);
int		ft_print_precision(t_fmt *fmt, char *s, char pad_char);
int		ft_print_string(char *s);
int		ft_printf(const char *fmt, ...);
int		ft_print_format(t_fmt *fmt, va_list *ap);
t_fmt	*ft_parse_fmt(const char **str);
char	*ft_to_hexbase(unsigned int hex_num);
char	*ft_to_hexptr(uintptr_t uptr);
char	*ft_unsigned_itoa(unsigned int n);
void	ft_uppercase(char *hex_str);

#endif