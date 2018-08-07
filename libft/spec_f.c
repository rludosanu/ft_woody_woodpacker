/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 13:35:24 by cdrouet           #+#    #+#             */
/*   Updated: 2016/02/04 13:58:25 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_lltoa(long long nbr)
{
	char				*ptr;
	unsigned long long	i;
	int					index;

	ptr = ft_strnew(30);
	index = 0;
	i = nbr;
	if (nbr < 0)
	{
		i = -nbr;
		index++;
		ptr[0] = '-';
	}
	index = recur_lltoa(i, ptr, index);
	ptr[index] = '\0';
	return (ptr);
}

int			recur_lltoa(unsigned long long nbr, char *ptr, int index)
{
	if (nbr >= 10)
	{
		index = recur_lltoa(nbr / 10, ptr, index);
		index = recur_lltoa(nbr % 10, ptr, index);
		return (index);
	}
	else
	{
		ptr[index] = nbr + '0';
		return (index + 1);
	}
	return (index);
}

int			verif_flag(const char *restrict format, int s)
{
	int		i;

	i = -1;
	while (format[++i] && format[i] != s)
		if (format[i] != '+' && format[i] != '-' && !(format[i] >= '0'
					&& format[i] <= '9') && format[i] != ' ' && format[i] != '#'
				&& format[i] != 'h' && format[i] != 'l' && format[i] != 'j'
				&& format[i] != 'z' && format[i] != '.'
				&& format[i] != '*')
			break ;
	if (format[i] != s || s == '\0')
		return (i);
	return (-1);
}

static int	init_decal(const char *restrict format, int nb1,
		char *c, int *nbrneg)
{
	int		i;

	i = -1;
	while (!(format[++i] > '0' && format[i] <= '9') && format[i] != '*')
		if (!format[i] || format[i] == '.')
			return (-1);
		else if (format[i] == '0')
			(*c) = '0';
	i = star_or_nb(format);
	if (format[i] == '*')
	{
		i = (nb1 >= 0) ? nb1 : -nb1;
		if (nb1 < 0)
			(*nbrneg)++;
	}
	else
		i = ft_atoi(&format[i]);
	return (i);
}

char		*decal_c(char **ptr, const char *restrict format, int nb1)
{
	int		i;
	int		wid;
	char	*res;
	char	c;
	int		nbrneg;

	i = -1;
	nbrneg = 0;
	c = ' ';
	if ((wid = init_decal(format, nb1, &c, &nbrneg)) == -1
		|| wid <= (int)ft_strlen(*ptr))
		return (*ptr);
	res = ft_strnew(wid - ft_strlen(*ptr) + 1);
	i = -1;
	while (++i < (wid - (int)ft_strlen(*ptr)))
		res[i] = c;
	if (ft_strchr(format, '-') || nbrneg)
		return (ft_strjoin(*ptr, res));
	else
		return (ft_strjoin(res, *ptr));
}
