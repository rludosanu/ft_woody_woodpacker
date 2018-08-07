/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 09:16:23 by cdrouet           #+#    #+#             */
/*   Updated: 2015/11/26 12:49:38 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	size_t	i;
	char	*ret;

	len = ft_strlen(s1);
	ret = malloc(sizeof(char) * (len + 1));
	i = -1;
	while (++i < len)
		ret[i] = s1[i];
	ret[i] = '\0';
	return (ret);
}
