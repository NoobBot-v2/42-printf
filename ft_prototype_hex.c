/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prototype_hex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoh <jsoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 18:49:32 by jsoh              #+#    #+#             */
/*   Updated: 2025/06/15 19:08:04 by jsoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"

void print_fmt_hex(t_fmt *fmt)
{
	if (fmt -> zero && fmt -> minus == 0 && fmt -> precision == -2)
	{
		if (fmt -> hash)
		{
			//print 0x/0X
		}
		//print width 0 padding
		//print hex number
	}
	else
	{
		//resolve precision
		//resolve hash flag
		//resolve left/right width
		//print output accordingly
	}
}
