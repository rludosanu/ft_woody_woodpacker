/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 09:59:06 by cdrouet           #+#    #+#             */
/*   Updated: 2016/02/15 10:35:06 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int	i;
	int j;

	if (!s1)
		return (NULL);
	else if (!s2)
		return (s1);
	j = ft_strlen(s1);
	i = -1;
	while (s2[++i] != '\0')
	{
		s1[j] = s2[i];
		j++;
	}
	s1[j] = '\0';
	return (s1);
}
