/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:51:32 by cdrouet           #+#    #+#             */
/*   Updated: 2016/05/16 14:51:46 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int	i;
	int	j;
	int	continu;

	i = -1;
	if (s2[0] == '\0')
		return ((char*)s1);
	while (s1[++i])
	{
		j = 0;
		if (s1[i] == s2[j])
		{
			continu = 1;
			while (s2[++j])
				if (s1[i + j] != s2[j])
					continu = 0;
			if (continu == 1)
				return ((char*)&s1[i]);
		}
	}
	return (NULL);
}
