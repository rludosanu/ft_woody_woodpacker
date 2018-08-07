/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pvt_gd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 09:57:22 by cdrouet           #+#    #+#             */
/*   Updated: 2016/02/02 12:53:17 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pct_gd(const char *restrict format, va_list ap)
{
	return (pct_ld(ap, format));
}

void	init(int *nb1, int *nb2, va_list ap)
{
	if ((*nb1) == 2)
	{
		(*nb1) = va_arg(ap, int);
		(*nb2) = va_arg(ap, int);
	}
	else if ((*nb1) == 1)
	{
		(*nb1) = va_arg(ap, int);
		(*nb2) = (*nb1);
	}
	else if ((*nb1) == 0)
	{
		(*nb1) = 0;
		(*nb2) = 0;
	}
}
