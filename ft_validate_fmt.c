/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_fmt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 12:34:47 by jsoh              #+#    #+#             */
/*   Updated: 2025/06/06 22:24:23 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"

//Handle all conflicting flags
void	ft_validate_fmt(t_fmt *fmt)
{
	if (fmt -> plus)
		fmt -> space = 0;
	if (fmt -> minus)
		fmt -> zero = 0;
	if (fmt -> precision >= 0)
	{
		if (fmt -> specifier == 'd')
			fmt -> zero = 0;
		else if (fmt -> specifier == 'i')
			fmt -> zero = 0;
		else if (fmt -> specifier == 'u')
			fmt -> zero = 0;
		else if (fmt -> specifier == 'x')
			fmt -> zero = 0;
		else if (fmt -> specifier == 'X')
			fmt -> zero = 0;
	}
}
