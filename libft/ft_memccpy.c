/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 16:15:03 by cdrouet           #+#    #+#             */
/*   Updated: 2015/12/02 14:58:23 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	const unsigned char	*source;
	unsigned char		*destination;
	unsigned char		d;
	size_t				i;

	d = (unsigned char)c;
	source = (const unsigned char*)src;
	destination = (unsigned char*)dest;
	i = -1;
	while (++i < n && source[i] != d)
		destination[i] = source[i];
	if (i != n)
	{
		destination[i] = source[i];
		return ((void*)&destination[i + 1]);
	}
	return (NULL);
}
