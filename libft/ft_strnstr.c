/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:29:25 by cdrouet           #+#    #+#             */
/*   Updated: 2015/11/27 16:12:56 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = -1;
	if (ft_strlen(s2) == 0)
		return ((char*)s1);
	while (s1[++i] && i < n)
	{
		j = 0;
		while (s1[i + j] == s2[j] && s2[j] && (i + j) < n)
			j++;
		if (!s2[j])
			return ((char*)&s1[i]);
	}
	return (NULL);
}
