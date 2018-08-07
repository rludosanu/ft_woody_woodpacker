/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 11:18:17 by cdrouet           #+#    #+#             */
/*   Updated: 2015/12/02 10:12:46 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = size;
	j = 0;
	while (i-- > 0 && dst[j])
		j++;
	i = size - j;
	if (i == 0)
		return (j + ft_strlen(src));
	k = 0;
	while (src[k] != '\0')
	{
		if (i != 1)
		{
			dst[j + k] = src[k];
			i--;
			size = j + k + 1;
		}
		k++;
	}
	dst[size] = '\0';
	return (j + k);
}
