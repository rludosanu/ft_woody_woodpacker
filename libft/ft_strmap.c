/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 13:49:14 by cdrouet           #+#    #+#             */
/*   Updated: 2015/11/27 16:31:43 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*ptr;

	i = -1;
	ptr = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
	while (s[++i])
		ptr[i] = f(s[i]);
	ptr[i] = '\0';
	return (ptr);
}
