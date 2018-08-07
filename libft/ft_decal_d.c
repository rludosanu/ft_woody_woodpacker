/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decal_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 13:21:51 by cdrouet           #+#    #+#             */
/*   Updated: 2017/04/05 15:23:18 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	inii(const char *restrict format)
{
	int	i;
	int	j;

	j = -1;
	i = -1;
	while (!(format[++i] > '0' && format[i] <= '9'))
		if (!format[i] || format[i] == '.')
			break ;
	while (format[++j] != '*')
		if (!format[j] || format[j] == '.')
			break ;
	if ((j > i && format[j] && format[j] != '.')
		|| (!format[i] && format[j] && format[j] != '.'))
		i = j;
	return (i);
}

char		*precis_d(char **ptr, const char *restrict format, int nbr)
{
	int		precision;
	int		i;
	char	*res;

	if (ft_strchr(format, '.'))
	{
		if (!ft_strchr(ft_strchr(format, '.'), '*'))
			precision = ft_atoi(ft_strchr(format, '.') + 1);
		else
			precision = nbr;
	}
	else
		return (*ptr);
	if (precision == 0 && ft_atoi(*ptr) == 0)
		(*ptr)[0] = '\0';
	if (precision <= (int)ft_strlen(*ptr))
		return (*ptr);
	res = ft_strnew(precision + 1);
	i = -1;
	while (++i < (precision - (int)ft_strlen(*ptr)))
		res[i] = '0';
	res = ft_strcat(res, *ptr);
	return (res);
}

char		*plus_d(char **ptr, const char *restrict format, long long i)
{
	if (!ft_strchr(format, '+') && i >= 0)
		return (*ptr);
	if (i >= 0)
		return (ft_strjoin("+", *ptr));
	return (ft_strjoin("-", *ptr));
}

static int	init_decal_d(const char *restrict format, int *nb1,
		char *c, int *nbrneg)
{
	int		i;

	i = -1;
	while (!(format[++i] > '0' && format[i] <= '9') && format[i] != '*')
		if (!format[i] || format[i] == '.')
			return (-1);
		else if (format[i] == '0' && (!ft_strchr(format, '.')
			|| ((ft_strchr(format, '.') + 1)[0] == '*' && nb1[2] < 0))
			&& !ft_strchr(format, '-'))
			(*c) = '0';
	i = inii(format);
	if (format[i] == '*')
	{
		i = (nb1[1] >= 0) ? nb1[1] : -nb1[1];
		if (nb1[1] < 0)
			(*nbrneg)++;
	}
	else
		i = ft_atoi(&format[i]);
	return (i);
}

char		*width_d(char **ptr, const char *restrict format, int nb1, int nb2)
{
	int		i[3];
	int		wid;
	char	*res[3];
	char	c;
	int		nbrneg;

	i[1] = nb1;
	i[2] = nb2;
	c = ' ';
	nbrneg = 0;
	if ((wid = init_decal_d(format, i, &c, &nbrneg)) == -1
		|| wid <= (int)ft_strlen(*ptr))
		return (*ptr);
	res[0] = ft_strnew(wid - ft_strlen(*ptr) + 1);
	i[0] = -1;
	while (++i[0] < (wid - (int)ft_strlen(*ptr)))
		res[0][i[0]] = c;
	if (c == '0' && ((*ptr)[0] == '+' || (*ptr)[0] == '-'))
		return (ft_strjoin_free(ft_strsub(*ptr, 0, 1),
					ft_strjoin_free(res[0], &(*ptr)[1], 1), 3));
	else if (c == '0' || (!ft_strchr(format, '-') && !nbrneg))
		return (ft_strjoin_free(res[0], *ptr, 1));
	else
		return (ft_strjoin_free(*ptr, res[0], 2));
}
