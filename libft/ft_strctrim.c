/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strctrim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 09:02:01 by cdrouet           #+#    #+#             */
/*   Updated: 2017/02/27 10:59:39 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strctrim(char const *s, char c)
{
	char			*ptr;
	char			*tmp;
	unsigned long	i;
	unsigned long	j;

	ptr = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
	tmp = NULL;
	if (ptr)
	{
		i = 0;
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
		{
			ptr[0] = '\0';
			return (ptr);
		}
		j = ft_strlen(s) - 1;
		while (s[j] == c)
			j--;
		tmp = ft_strsub(s, i, j - i + 1);
		free(ptr);
		tmp[j - i + 1] = '\0';
	}
	return (tmp);
}
