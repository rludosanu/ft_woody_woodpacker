/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 10:51:52 by cdrouet           #+#    #+#             */
/*   Updated: 2015/12/02 14:57:32 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void			*ret;
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char*)malloc(size);
	if (!ptr)
		return (NULL);
	i = -1;
	while (++i < size)
		ptr[i] = 0;
	ret = (void*)ptr;
	return (ret);
}
