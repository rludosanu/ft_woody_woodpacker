/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pct_i.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 09:58:17 by cdrouet           #+#    #+#             */
/*   Updated: 2016/01/13 08:15:51 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pct_i(const char *restrict format, va_list ap)
{
	char	*str;

	str = ft_strchr(format, 'i');
	str[0] = 'd';
	return (pct_d(format, ap));
}
