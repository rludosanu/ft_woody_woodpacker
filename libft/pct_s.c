/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pct_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 09:54:51 by cdrouet           #+#    #+#             */
/*   Updated: 2017/04/05 14:11:17 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*pct_ss2(const char *restrict f, int nb2, int nb1, char *ptr)
{
	char	*str;
	char	*tmp;
	int		i;

	if (ptr == NULL)
		str = ft_strjoin("(nu", "ll)");
	else
		str = ft_strjoin("", ptr);
	if (ft_strchr(f, '.') != NULL)
	{
		i = 0;
		while (f[i] != '.')
			i++;
		i++;
		if (nb2 < 0)
			nb2 *= -1;
		if (f[i] != '*')
			tmp = ft_strsub(str, 0, ft_atoi(&f[i]));
		else
			tmp = ft_strsub(str, 0, nb2);
		free(str);
		str = tmp;
	}
	return (aj_decal(&str, f, nb1));
}

static int		pct_ss(const char *restrict format, va_list ap)
{
	char	*ptr;
	char	*str;
	int		nb1;
	int		nb2;

	nb1 = 0;
	nb2 = -1;
	while (format[++nb2])
		if (format[nb2] == '*')
			nb1++;
	init(&nb1, &nb2, ap);
	ptr = (char*)va_arg(ap, char*);
	str = pct_ss2(format, nb2, nb1, ptr);
	ft_putstr(str);
	nb1 = ft_strlen(str);
	free(str);
	return (nb1);
}

static wchar_t	*wchar_null(void)
{
	wchar_t	*res;

	res = (wchar_t*)malloc(sizeof(wchar_t) * 7);
	res[0] = '(';
	res[1] = 'n';
	res[2] = 'u';
	res[3] = 'l';
	res[4] = 'l';
	res[5] = ')';
	res[6] = 0;
	return (res);
}

int				pct_ls(const char *restrict format, va_list ap)
{
	wchar_t	*res;
	int		nb1;
	int		nb2;

	nb1 = 0;
	nb2 = -1;
	while (format[++nb2])
		if (format[nb2] == '*')
			nb1++;
	init(&nb1, &nb2, ap);
	res = (wchar_t*)va_arg(ap, wchar_t*);
	if (res == NULL)
		res = wchar_null();
	res = precis_wchar_t(res, format, (int)nb2);
	res = decal_wstr(&res, format, (int)nb1);
	nb1 = ft_putwstr_t(res);
	free(res);
	return (nb1);
}

int				pct_s(const char *restrict format, va_list ap)
{
	if (ft_strchr(format, 'l') != NULL)
		return (pct_ls(format, ap));
	else
		return (pct_ss(format, ap));
}
