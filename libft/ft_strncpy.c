/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 09:45:10 by cdrouet           #+#    #+#             */
/*   Updated: 2015/11/26 15:41:52 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t	i;

	i = -1;
	while (++i < n)
	{
		if (src[i] != '\0')
			dst[i] = src[i];
		else
		{
			dst[i] = '\0';
			while (++i < n)
				dst[i] = '\0';
			return (dst);
		}
	}
	return (dst);
}
