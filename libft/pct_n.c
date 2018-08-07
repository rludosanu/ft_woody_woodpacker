/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pct_n.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 14:34:53 by cdrouet           #+#    #+#             */
/*   Updated: 2016/02/01 09:41:17 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	pct_n3(int n, va_list ap, const char *restrict format)
{
	intmax_t	*imt;
	ssize_t		*prout;

	if (ft_strchr(format, 'j'))
	{
		imt = (intmax_t*)va_arg(ap, intmax_t*);
		(*imt) = (intmax_t)n;
	}
	else if (ft_strchr(format, 'z'))
	{
		prout = (ssize_t*)va_arg(ap, ssize_t*);
		(*prout) = (ssize_t)n;
	}
}

static void	pct_n2(int n, va_list ap, const char *restrict format)
{
	long		*l;
	long long	*ll;

	if (ft_strchr(format, 'l'))
		if (ft_strrchr(format, 'l') == ft_strchr(format, 'l'))
		{
			ll = (long long*)va_arg(ap, long long*);
			(*ll) = (long long)n;
		}
		else
		{
			l = (long*)va_arg(ap, long*);
			(*l) = (long)n;
		}
	else if (ft_strchr(format, 'j') || ft_strchr(format, 'z'))
		pct_n3(n, ap, format);
}

void		pct_n(int n, va_list ap, const char *restrict format)
{
	int		*j;
	short	*k;
	char	*l;

	if (ft_strchr(format, 'h') != NULL)
		if (ft_strrchr(format, 'h') == ft_strchr(format, 'h'))
		{
			l = (char*)va_arg(ap, char*);
			(*l) = (char)n;
		}
		else
		{
			k = (short*)va_arg(ap, short*);
			(*k) = (short)n;
		}
	else if (ft_strchr(format, 'l') || ft_strchr(format, 'j')
		|| ft_strchr(format, 'z'))
		pct_n2(n, ap, format);
	else
	{
		j = (int*)va_arg(ap, int*);
		(*j) = n;
	}
}
