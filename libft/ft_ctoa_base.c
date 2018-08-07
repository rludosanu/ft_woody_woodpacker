/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 09:12:39 by cdrouet           #+#    #+#             */
/*   Updated: 2016/01/25 14:40:55 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	recur_ctoa_b(unsigned char nb, int base, char *ptr, int index)
{
	char	*str;

	str = "0123456789abcdef";
	if (nb >= (unsigned char)base)
	{
		index = recur_ctoa_b(nb / base, base, ptr, index);
		index = recur_ctoa_b(nb % base, base, ptr, index);
	}
	else
	{
		ptr[index] = str[nb];
		index++;
	}
	return (index);
}

char		*ft_ctoa_base(char nb, int base)
{
	unsigned char	i;
	char			*ptr;
	int				index;

	i = nb;
	ptr = ft_strnew(20);
	index = 0;
	if (nb < 0 && base == 10)
	{
		ptr[index++] = '-';
		i = -nb;
	}
	recur_ctoa_b(i, base, ptr, index);
	return (ptr);
}
