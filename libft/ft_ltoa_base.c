/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 09:07:53 by cdrouet           #+#    #+#             */
/*   Updated: 2017/02/16 14:56:17 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	recur_ltoa_b(unsigned long nb, int base, char *ptr, int index)
{
	char	*str;

	str = "0123456789abcdef";
	if (nb >= (unsigned long)base)
	{
		index = recur_ltoa_b(nb / base, base, ptr, index);
		index = recur_ltoa_b(nb % base, base, ptr, index);
	}
	else
	{
		ptr[index] = str[nb];
		index++;
	}
	return (index);
}

char		*ft_ltoa_base(long nb, int base)
{
	unsigned long	i;
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
	recur_ltoa_b(i, base, ptr, index);
	return (ptr);
}

static int	recur_stoa_b(unsigned short nb, int base, char *ptr, int index)
{
	char	*str;

	str = "0123456789abcdef";
	if (nb >= (unsigned short)base)
	{
		index = recur_stoa_b(nb / base, base, ptr, index);
		index = recur_stoa_b(nb % base, base, ptr, index);
	}
	else
	{
		ptr[index] = str[nb];
		index++;
	}
	return (index);
}

char		*ft_stoa_base(short nb, int base)
{
	unsigned short	i;
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
	recur_stoa_b(i, base, ptr, index);
	return (ptr);
}
