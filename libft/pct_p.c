/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pct_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 09:56:50 by cdrouet           #+#    #+#             */
/*   Updated: 2017/04/05 14:03:44 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pct_p(const char *restrict format, va_list ap)
{
	char	*res;
	char	*tmp;
	int		i;

	tmp = ft_strsub(format, 0, ft_strlen(format) - 1);
	res = ft_strjoin("#", tmp);
	free(tmp);
	tmp = ft_strjoin(res, "lxp");
	free(res);
	i = pct_x(tmp, ap);
	free(tmp);
	return (i);
}
