/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdrouet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 07:59:00 by cdrouet           #+#    #+#             */
/*   Updated: 2015/12/02 14:36:42 by cdrouet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ret;
	t_list	*retf;
	t_list	*tempo;

	ret = NULL;
	retf = NULL;
	tempo = NULL;
	if (lst)
	{
		retf = f(lst);
		ret = ft_lstnew(retf->content, retf->content_size);
	}
	else
		return (ret);
	lst = lst->next;
	tempo = ret;
	while (lst)
	{
		retf = f(lst);
		tempo->next = ft_lstnew(retf->content, retf->content_size);
		lst = lst->next;
		tempo = tempo->next;
	}
	return (ret);
}
