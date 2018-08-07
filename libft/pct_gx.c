/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pct_gx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 10:22:48 by cdrouet           #+#    #+#             */
/*   Updated: 2016/01/13 08:17:53 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pct_gx(const char *restrict format, va_list ap)
{
	if ((ft_strchr(format, 'h') != NULL)
		&& (ft_strchr(format, 'h') != ft_strrchr(format, 'h')))
		return (pct_hho(ap, format, 16, 1));
	else if (ft_strchr(format, 'h') != NULL)
		return (pct_ho(ap, format, 16, 1));
	else if ((ft_strchr(format, 'l') != NULL)
		&& (ft_strchr(format, 'l') != ft_strrchr(format, 'l')))
		return (pct_llo(ap, format, 16, 1));
	else if (ft_strchr(format, 'l'))
		return (pct_lo(ap, format, 16, 1));
	else if (ft_strchr(format, 'j'))
		return (pct_jo(ap, format, 16, 1));
	else if (ft_strchr(format, 'z'))
		return (pct_zo(ap, format, 16, 1));
	else
		return (pct_oo(ap, format, 16, 1));
}
