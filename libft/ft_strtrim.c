/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:02:36 by cdrouet           #+#    #+#             */
/*   Updated: 2015/11/27 16:12:39 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char			*ptr;
	unsigned long	i;
	unsigned long	j;

	ptr = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (ptr)
	{
		i = 0;
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			i++;
		if (s[i] == '\0')
		{
			ptr[0] = '\0';
			return (ptr);
		}
		j = ft_strlen(s) - 1;
		while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
			j--;
		ptr = ft_strsub(s, i, j - i + 1);
		ptr[j - i + 1] = '\0';
	}
	return (ptr);
}
