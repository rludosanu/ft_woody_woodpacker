/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 09:02:35 by cdrouet           #+#    #+#             */
/*   Updated: 2016/05/31 08:26:35 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_strisdigit(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '	')
		i++;
	if (str[i] != '-' && str[i] != '+' && !ft_isdigit(str[i]))
		return (0);
	i++;
	while (str[++i])
		if (!ft_isdigit(str[i]))
			return (0);
	return (1);
}
