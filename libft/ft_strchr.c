/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:18:17 by cdrouet           #+#    #+#             */
/*   Updated: 2016/01/25 14:50:51 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (c == 0)
		return ((char*)&s[ft_strlen(s)]);
	else
	{
		i = -1;
		while (s[++i] != '\0')
		{
			if (s[i] == c)
				return ((char*)&s[i]);
		}
	}
	return (NULL);
}
