/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_f2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 09:29:18 by cdrouet           #+#    #+#             */
/*   Updated: 2016/01/28 13:40:09 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		init_nb(int *nb1, int *nb2, const char *restrict format)
{
	while (format[++(*nb2)])
		if (format[(*nb2)] == '*')
			(*nb1)++;
}

static int	recur_ultoa_b(unsigned long nbr, int base, char *ptr, int index)
{
	char	*str;

	str = "0123456789abcdef";
	if (nbr >= (unsigned long)base)
	{
		index = recur_ultoa_b(nbr / base, base, ptr, index);
		index = recur_ultoa_b(nbr % base, base, ptr, index);
	}
	else
	{
		ptr[index] = str[nbr];
		index++;
	}
	return (index);
}

char		*ft_ultoa_base(unsigned long nbr, int base)
{
	char	*ptr;

	ptr = ft_strnew(20);
	recur_ultoa_b(nbr, base, ptr, 0);
	return (ptr);
}

static int	recur_ulltoa_b(unsigned long long nbr, int base, char *ptr, int i)
{
	char	*str;

	str = "0123456789abcdef";
	if (nbr >= (unsigned long long)base)
	{
		i = recur_ulltoa_b(nbr / base, base, ptr, i);
		i = recur_ulltoa_b(nbr % base, base, ptr, i);
	}
	else
	{
		ptr[i] = str[nbr];
		i++;
	}
	return (i);
}

char		*ft_ulltoa_base(unsigned long long nbr, int base)
{
	char	*ptr;

	ptr = ft_strnew(20);
	recur_ulltoa_b(nbr, base, ptr, 0);
	return (ptr);
}
