/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:20:16 by cdrouet           #+#    #+#             */
/*   Updated: 2016/03/14 14:04:00 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*ptr;
	unsigned int	compt;

	ptr = (char*)malloc(sizeof(char) * (len + 1));
	if (ptr)
	{
		compt = start;
		while (compt < (start + len))
		{
			ptr[compt - start] = s[compt];
			compt++;
		}
		ptr[compt - start] = '\0';
	}
	return (ptr);
}
