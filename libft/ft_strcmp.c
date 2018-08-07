/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:53:34 by cdrouet           #+#    #+#             */
/*   Updated: 2016/03/16 12:47:00 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ftmemcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*src1;
	const unsigned char	*src2;
	size_t				i;

	src1 = (const unsigned char*)s1;
	src2 = (const unsigned char*)s2;
	i = -1;
	while (++i < n)
		if (src1[i] != src2[i])
			return (src1[i] - src2[i]);
	return (0);
}

int			ft_strcmp(const char *s1, const char *s2)
{
	if (!s1 && s2)
		return (1);
	else if (s1 && !s2)
		return (1);
	return (ftmemcmp((void*)s1, (void*)s2, ft_strlen(s2) + 1));
}
