/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pct_d2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 10:26:05 by cdrouet           #+#    #+#             */
/*   Updated: 2017/04/05 15:52:55 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pct_jd(va_list ap, const char *restrict f)
{
	intmax_t	i;
	char		*r;
	int			nb1;
	int			nb2;

	nb1 = 0;
	nb2 = -1;
	init_nb(&nb1, &nb2, f);
	init(&nb1, &nb2, ap);
	i = va_arg(ap, intmax_t);
	r = all_flag_spe(i, f, nb1, nb2);
	if (i >= 0 && (ft_strchr(f, '+') == NULL)
		&& (ft_strchr(f, ' ') != NULL))
	{
		if (!ft_strchr(f, '.') && (r[0] == '0' || r[0] == ' ') && r[1] != '\0')
			r[0] = ' ';
		else
			r = ft_strjoin_free(" ", r, 2);
	}
	ft_putstr(r);
	nb1 = ft_strlen(r);
	free(r);
	return (nb1);
}

int		pct_zd(va_list ap, const char *restrict f)
{
	ssize_t	i;
	char	*r;
	int		nb1;
	int		nb2;

	nb1 = 0;
	nb2 = -1;
	init_nb(&nb1, &nb2, f);
	init(&nb1, &nb2, ap);
	i = va_arg(ap, ssize_t);
	r = all_flag_spe(i, f, nb1, nb2);
	if (i >= 0 && (ft_strchr(f, '+') == NULL)
		&& (ft_strchr(f, ' ') != NULL))
	{
		if (!ft_strchr(f, '.') && (r[0] == '0' || r[0] == ' ') && r[1] != '\0')
			r[0] = ' ';
		else
			r = ft_strjoin_free(" ", r, 2);
	}
	ft_putstr(r);
	nb1 = ft_strlen(r);
	free(r);
	return (nb1);
}

int		pct_dd(va_list ap, const char *restrict f)
{
	int		i;
	char	*r;
	int		nb1;
	int		nb2;

	nb1 = 0;
	nb2 = -1;
	init_nb(&nb1, &nb2, f);
	init(&nb1, &nb2, ap);
	i = va_arg(ap, int);
	r = all_flag_spe(i, f, nb1, nb2);
	if (i >= 0 && (ft_strchr(f, '+') == NULL)
		&& (ft_strchr(f, ' ') != NULL))
	{
		if (!ft_strchr(f, '.') && (r[0] == '0' || r[0] == ' ') && r[1] != '\0')
			r[0] = ' ';
		else if (!ft_strchr(f, '.'))
			r = ft_strjoin_free(" ", r, 2);
	}
	ft_putstr(r);
	nb1 = ft_strlen(r);
	free(r);
	return (nb1);
}
