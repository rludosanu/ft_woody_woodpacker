/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_f4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 13:50:27 by cdrouet           #+#    #+#             */
/*   Updated: 2017/04/05 16:15:03 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			init_diese_i(char **ptr)
{
	int	i;

	i = 0;
	while ((*ptr)[i] == ' ')
		i++;
	if (!(*ptr)[i])
		i = 0;
	return (i);
}

int			put_len_free(char *ptr)
{
	int	i;

	ft_putstr(ptr);
	i = ft_strlen(ptr);
	free(ptr);
	return (i);
}

void		replace_ptr(char **ptr1, char **ptr2)
{
	free(*ptr1);
	*ptr1 = *ptr2;
}

char		*ft_strjoin_free(char *s1, char *s2, int bin)
{
	char	*tmp;

	tmp = ft_strjoin(s1, s2);
	if (bin & 1)
		free(s1);
	if (bin & 2)
		free(s2);
	return (tmp);
}

char		*all_flag_spe(long long i,
		const char *restrict format, int nb1, int nb2)
{
	char	*r;
	char	*tmp;

	if (i >= 0)
		r = ft_lltoa(i);
	else
	{
		tmp = ft_lltoa(i);
		r = ft_strsub(tmp, 1, ft_strlen(tmp) - 1);
		free(tmp);
	}
	if ((tmp = precis_d(&r, format, nb2)) != r)
		replace_ptr(&r, &tmp);
	if ((tmp = plus_d(&r, format, i)) != r)
		replace_ptr(&r, &tmp);
	if ((tmp = width_d(&r, format, nb1, nb2)) != r)
		replace_ptr(&r, &tmp);
	return (r);
}
