/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 13:42:53 by cdrouet           #+#    #+#             */
/*   Updated: 2016/02/04 09:01:21 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			star_or_nb(const char *restrict f)
{
	int	i;
	int	j;

	j = -1;
	i = -1;
	while (!(f[++i] >= '0' && f[i] <= '9'))
		if (!f[i] || f[i] == '.')
			break ;
	while (f[++j] != '*')
		if (!f[j] || f[j] == '.')
			break ;
	if ((j > i && f[j] && f[j] != '.') || (!f[i] && f[j] && f[j] != '.'))
		i = j;
	return (i);
}

static int	neg_or_pos(int nb, const char *restrict f, int i)
{
	if (f[i] == '*')
	{
		if (nb >= 0)
			return (nb);
		else
			return (-nb);
	}
	else
		return (ft_atoi(&f[i]));
}

static int	flag_ze_pl_mo(const char *restrict f, int i, char *c)
{
	if ((f[i] == '0' && ft_strchr(&f[i], '.') == NULL)
		|| (ft_strchr(&f[i], '.') != NULL
			&& (ft_atoi(ft_strchr(&f[i], '.') + 1) == 0
				&& f[i] == '0')))
		(*c) = '0';
	if (f[i + 1] == '+' || f[i + 1] == '-' || f[i + 1] == ' ')
		return (i + 2);
	return (i);
}

static int	all_flag(const char *restrict f, int i, char *c)
{
	i = star_or_nb(f);
	return (flag_ze_pl_mo(f, i, c));
}

char		*aj_decal(char **ptr, const char *restrict f, int nb)
{
	int		i;
	char	*res;
	char	c;

	i = -1;
	c = ' ';
	while (!(f[++i] >= '0' && f[i] <= '9') && f[i] != '*')
		if (!f[i] || f[i] == '.')
			return (*ptr);
	i = all_flag(f, i, &c);
	if (f[i - 1] == '.')
		return (*ptr);
	i = neg_or_pos(nb, f, i);
	if (i <= (int)ft_strlen(*ptr))
		return (*ptr);
	res = ft_strnew(sizeof(char) * (i + 1));
	if (ft_strchr(f, '-') == NULL
		&& (ft_strchr(f, '*') == NULL
			|| (ft_strchr(f, '*') != NULL
				&& (nb >= 0 || (i != nb && i != -nb)))))
		aj_decal_d(--i, ptr, res, c);
	else
		aj_decal_g(--i, f, res, ptr);
	free(*ptr);
	return (res);
}
