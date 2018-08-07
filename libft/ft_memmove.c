/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 16:36:44 by cdrouet           #+#    #+#             */
/*   Updated: 2015/12/02 15:00:31 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*destination;
	const unsigned char	*source;
	unsigned char		*copy;
	size_t				i;

	copy = (unsigned char*)malloc(sizeof(unsigned char) * (n + 1));
	source = (const unsigned char*)src;
	destination = (unsigned char*)dest;
	ft_strncpy((char*)copy, (char*)source, n);
	copy[n + 1] = '\0';
	i = -1;
	while (++i < n)
		destination[i] = copy[i];
	free(copy);
	return (dest);
}
