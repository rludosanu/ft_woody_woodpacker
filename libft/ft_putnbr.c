/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 08:47:15 by cdrouet           #+#    #+#             */
/*   Updated: 2017/02/15 10:29:42 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putlnbr(long long n)
{
	unsigned long long	i;

	i = (unsigned long long)n;
	if (n < 0)
	{
		write(1, "-", 1);
		i = -n;
	}
	if (i >= 10)
	{
		ft_putnbr(i / 10);
		ft_putnbr(i % 10);
	}
	else
	{
		ft_putchar(i + '0');
	}
}

void	ft_putnbr(int n)
{
	unsigned int	i;

	i = (unsigned int)n;
	if (n < 0)
	{
		write(1, "-", 1);
		i = -n;
	}
	if (i >= 10)
	{
		ft_putnbr(i / 10);
		ft_putnbr(i % 10);
	}
	else
	{
		ft_putchar(i + '0');
	}
}
