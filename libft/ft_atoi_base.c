/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <cdrouet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 08:40:41 by cdrouet           #+#    #+#             */
/*   Updated: 2016/01/25 14:40:26 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_puiss(int nbr, unsigned int p)
{
	unsigned int	i;
	int				n;

	if (p == 0)
		return (1);
	i = 1;
	n = nbr;
	while (i++ < p)
		nbr *= n;
	return (nbr);
}

int			ft_atoi_base(const char *str, int base)
{
	int	len;
	int	i;
	int	nbr;

	len = ft_strlen(str);
	i = ft_strlen(str);
	nbr = 0;
	while (--i > 0 || ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a'
		&& str[i] <= 'z') || (str[i] >= '0' && str[i] <= '9')))
		if (str[i] >= 'A' && str[i] <= 'Z')
			nbr += (ft_puiss(base, len - (i + 1)) * (str[i] - 'A' + 10));
		else if (str[i] >= 'a' && str[i] <= 'z')
			nbr += (ft_puiss(base, len - (i + 1)) * (str[i] - 'a' + 10));
		else if (str[i] >= '0' && str[i] <= '9')
			nbr += (ft_puiss(base, len - (i + 1)) * (str[i] - '0'));
	return (nbr);
}
