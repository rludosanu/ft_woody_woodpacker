/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pct_b.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 14:05:42 by cdrouet           #+#    #+#             */
/*   Updated: 2016/01/26 14:08:20 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pct_b(const char *restrict format, va_list ap)
{
	if ((ft_strchr(format, 'h') != NULL)
		&& (ft_strchr(format, 'h') != ft_strrchr(format, 'h')))
		return (pct_hho(ap, format, 2, 0));
	else if (ft_strchr(format, 'h') != NULL)
		return (pct_ho(ap, format, 2, 0));
	else if ((ft_strchr(format, 'l') != NULL)
		&& (ft_strchr(format, 'l') != ft_strrchr(format, 'l')))
		return (pct_llo(ap, format, 2, 0));
	else if (ft_strchr(format, 'l'))
		return (pct_lo(ap, format, 2, 0));
	else if (ft_strchr(format, 'j'))
		return (pct_jo(ap, format, 2, 0));
	else if (ft_strchr(format, 'z'))
		return (pct_zo(ap, format, 2, 0));
	else
		return (pct_oo(ap, format, 2, 0));
}
