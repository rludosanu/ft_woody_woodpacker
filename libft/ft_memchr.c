/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 08:27:59 by cdrouet           #+#    #+#             */
/*   Updated: 2015/12/02 14:58:32 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*tempo;
	size_t			i;

	i = -1;
	tempo = (unsigned char*)s;
	while (++i < n)
		if (tempo[i] == (unsigned char)c)
			return ((void*)&tempo[i]);
	return (NULL);
}
