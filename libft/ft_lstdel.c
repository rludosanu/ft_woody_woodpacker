/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 09:48:12 by cdrouet           #+#    #+#             */
/*   Updated: 2015/12/02 08:33:50 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	if (*alst)
	{
		if ((*alst)->next)
			ft_lstdel(&((*alst)->next), del);
		if (!(*alst)->next)
			ft_lstdelone(alst, del);
	}
}
