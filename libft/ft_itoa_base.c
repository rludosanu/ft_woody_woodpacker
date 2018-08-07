/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 11:32:03 by cdrouet           #+#    #+#             */
/*   Updated: 2016/01/25 14:48:56 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	recur_lltoa_b(unsigned long long nb, int base, char *ptr, int index)
{
	char	*str;

	str = "0123456789abcdef";
	if (nb >= (unsigned long long)base)
	{
		index = recur_lltoa_b(nb / base, base, ptr, index);
		index = recur_lltoa_b(nb % base, base, ptr, index);
	}
	else
	{
		ptr[index] = str[nb];
		index++;
	}
	return (index);
}

char		*ft_lltoa_base(long long nb, int base)
{
	unsigned long long	i;
	char				*ptr;
	int					index;

	i = nb;
	ptr = ft_strnew(20);
	index = 0;
	if (nb < 0 && base == 10)
	{
		ptr[index++] = '-';
		i = -nb;
	}
	recur_lltoa_b(i, base, ptr, index);
	return (ptr);
}

static int	recur_itoa_b(unsigned int nb, int base, char *ptr, int index)
{
	char	*str;

	str = "0123456789abcdef";
	if (nb >= (unsigned int)base)
	{
		index = recur_itoa_b(nb / base, base, ptr, index);
		index = recur_itoa_b(nb % base, base, ptr, index);
	}
	else
	{
		ptr[index] = str[nb];
		index++;
	}
	return (index);
}

char		*ft_itoa_base(int nb, int base)
{
	unsigned int	i;
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
	recur_itoa_b(i, base, ptr, index);
	return (ptr);
}
