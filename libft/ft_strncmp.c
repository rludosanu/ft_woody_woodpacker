/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 08:43:48 by cdrouet           #+#    #+#             */
/*   Updated: 2016/04/27 09:43:08 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (ft_strlen(s1) < n)
		return (ft_memcmp((void*)s1, (void*)s2, ft_strlen(s1) + 1));
	else if (ft_strlen(s2) < n)
		return (ft_memcmp((void*)s1, (void*)s2, ft_strlen(s2) + 1));
	else
		return (ft_memcmp((void*)s1, (void*)s2, n));
}
