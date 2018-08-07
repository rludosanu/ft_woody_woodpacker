/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 08:56:53 by cdrouet           #+#    #+#             */
/*   Updated: 2017/03/30 10:30:40 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putindex(const char *str, int *i)
{
	while (str[*i] == ' ' || str[*i] == '\n' || str[*i] == '\t'
		|| str[*i] == '\v' || str[*i] == '\f' || str[*i] == '\r')
		*i += 1;
}

int			ft_atoi(const char *str)
{
	int		i;
	int		compteur;
	int		result;

	i = 0;
	ft_putindex(str, &i);
	if ((str[i] != '-' && str[i] != '+' && !ft_isdigit(str[i]))
		|| ((str[i] == '-' || str[i] == '+') && !ft_isdigit(str[i + 1])))
		return (0);
	else
		i++;
	compteur = 1;
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	while (--i > 0 && (str[i] >= '0' && str[i] <= '9'))
	{
		result += (str[i] - '0') * compteur;
		compteur *= 10;
	}
	if (ft_isdigit(str[i]))
		result += (str[i] - '0') * compteur;
	else if (str[i] == '-')
		result *= -1;
	return (result);
}

long		ft_atol(const char *str)
{
	int		i;
	long	compteur;
	long	result;

	i = 0;
	ft_putindex(str, &i);
	if ((str[i] != '-' && str[i] != '+' && !ft_isdigit(str[i]))
		|| ((str[i] == '-' || str[i] == '+') && !ft_isdigit(str[i + 1])))
		return (0);
	else
		i++;
	compteur = 1;
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	while (--i > 0 && (str[i] >= '0' && str[i] <= '9'))
	{
		result += (str[i] - '0') * compteur;
		compteur *= 10;
	}
	if (ft_isdigit(str[i]))
		result += (str[i] - '0') * compteur;
	else if (str[i] == '-')
		result *= -1;
	return (result);
}
