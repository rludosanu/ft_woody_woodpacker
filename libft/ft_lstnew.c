/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 16:43:41 by cdrouet           #+#    #+#             */
/*   Updated: 2016/02/08 15:49:09 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*maillon;

	maillon = (t_list*)malloc(sizeof(maillon));
	if (maillon)
	{
		if (content)
		{
			maillon->content = (void*)content;
			maillon->content_size = content_size;
		}
		else
		{
			maillon->content = NULL;
			maillon->content_size = 0;
		}
		maillon->next = NULL;
	}
	return (maillon);
}
