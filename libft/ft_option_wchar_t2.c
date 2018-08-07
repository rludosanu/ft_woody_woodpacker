/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option_wchar_t2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 09:57:48 by cdrouet           #+#    #+#             */
/*   Updated: 2016/02/03 08:24:31 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

wchar_t	*precis_wchar_t(wchar_t *ptr, const char *restrict format, int nb)
{
	int		i;
	int		j;
	int		prec;
	char	*pre;
	wchar_t	*res;

	if ((pre = ft_strchr(format, '.')) == NULL)
		return (ptr);
	pre++;
	if (pre[0] == '*')
		prec = nb;
	else
		prec = ft_atoi(pre);
	if (nbr_bytes_wstr(ptr) <= prec)
		return (ptr);
	i = 0;
	j = 0;
	while ((i += nbr_bytes_wchar(ptr[j])) <= prec)
		j++;
	res = (wchar_t*)malloc(sizeof(wchar_t) * (j + 2));
	i = j - 1;
	while (--j >= 0)
		res[j] = ptr[j];
	res[i + 1] = 0;
	return (res);
}

int		ft_wstrlen(wchar_t *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

int		ft_putwmem(wchar_t *str, int i)
{
	int	j;
	int	ow;

	j = -1;
	ow = 0;
	while (++j < i)
		ow += ft_putwchar_t(str[j]);
	return (ow);
}
