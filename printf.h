/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 12:35:16 by jsoh              #+#    #+#             */
/*   Updated: 2025/06/21 23:04:09 by jsoh             ###   ########.fr       */
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

void	ft_print_fmt_char(char c, t_fmt *fmt);
void	ft_print_fmt_string(char *s1, t_fmt *fmt);
void	ft_print_fmt_number(int number, t_fmt *fmt);
void	ft_print_fmt_ptr(void *ptr, t_fmt *fmt);
void	ft_print_fmt_unsigned(unsigned int number, t_fmt *fmt);
void	ft_print_fmt_hex(t_fmt *fmt, unsigned int hex_num);
void	ft_print_width(t_fmt *fmt, char *hex_str, char pad_char);
void	ft_print_precision(t_fmt *fmt, char *hex_str, char pad_char);
char	*ft_to_hexbase(unsigned int hex_num);
char	*ft_to_hexptr(uintptr_t uptr);
char	*ft_unsigned_itoa(unsigned int n);
static void	ft_uppercase(char *hex_str);

#endif