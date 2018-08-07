/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pct_d3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 14:01:57 by cdrouet           #+#    #+#             */
/*   Updated: 2016/02/03 11:36:53 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*aj_zero_pos(char **ptr, const char *restrict format, int i)
{
	char	*res;
	int		l;

	l = 0;
	if (i <= (int)ft_strlen(*ptr))
		return (*ptr);
	if (ft_strchr(format, '+') != NULL
		&& (!ft_strchr(format, 'u') && !ft_strchr(format, 'U')
			&& !ft_strchr(format, 'p')))
		i++;
	res = (char*)ft_strnew(sizeof(char) * (i + 1));
	while (l < (i - (int)ft_strlen(*ptr)))
		res[l++] = '0';
	ft_strcpy(&res[l], *ptr);
	free(*ptr);
	return (res);
}

static char	*aj_zero_neg(char **ptr, int i)
{
	char	*res;
	int		l;
	int		len;

	l = 0;
	len = (int)ft_strlen(*ptr);
	if (i < len)
		return (*ptr);
	res = (char*)ft_strnew(sizeof(char) * (i + 2));
	res[l++] = '-';
	while (l <= ((i + 1) - len))
		res[l++] = '0';
	ft_strcpy(&res[l], &(*ptr)[1]);
	free(*ptr);
	return (res);
}

char		*aj_zero(char **ptr, const char *restrict format, int nb)
{
	int		i;

	i = -1;
	while (format[++i] != '.')
		if (!format[i])
			return (*ptr);
	if (format[i + 1] == '*')
	{
		if (nb >= 0)
			i = nb;
		else
			return (*ptr);
	}
	else
		i = ft_atoi(&format[++i]);
	if ((i == 0 && ft_atoi(*ptr) == 0 && (!ft_strchr(format, '#')
		|| ft_strchr(format, 'x') || ft_strchr(format, 'X')))
		|| (ft_strchr(format, 'p') && i == 0 && ft_atoi(*ptr) == 0))
		(*ptr)[0] = '\0';
	if (ft_atoi(*ptr) < 0)
		return (aj_zero_neg(ptr, i));
	else
		return (aj_zero_pos(ptr, format, i));
}

void		aj_decal_d(int i, char **ptr, char *res, char c)
{
	char	*s;
	int		j;

	j = ft_strlen(*ptr);
	j--;
	while (j >= 0)
		res[i--] = (*ptr)[j--];
	while (i >= 0)
		res[i--] = c;
	s = ft_strchr(res, '-');
	if (s != NULL)
	{
		s[0] = c;
		j = 0;
		while (res[j] == ' ')
			j++;
		if (j > 0)
			res[j - 1] = '-';
		else
			res[j] = '-';
	}
}

void		aj_decal_g(int i, const char *restrict format, char *res, char **p)
{
	int	j;

	j = ft_strlen(*p);
	ft_strcpy(res, *p);
	if (ft_strchr(format, '+') != NULL && !ft_strchr(format, 's')
		&& !ft_strchr(format, 'p'))
		i--;
	if (ft_strchr(format, ' '))
		i--;
	while (j < (i + 1))
		res[j++] = ' ';
}
