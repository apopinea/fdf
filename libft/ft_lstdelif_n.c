/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelif_n.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 12:18:42 by apopinea          #+#    #+#             */
/*   Updated: 2016/11/21 12:18:54 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void		ft_free_lst_c(t_list **elem, t_list **prev, t_list **tmp)
{
	if (*tmp == *elem)
	{
		*prev = (*tmp)->next;
		free((*tmp)->content);
		free(*tmp);
		*tmp = *prev;
		*elem = *tmp;
	}
	else
	{
		(*prev)->next = (*tmp)->next;
		free((*tmp)->content);
		free(*tmp);
		*tmp = (*prev)->next;
	}
}

void			ft_lstdelif_n(t_list **elem, size_t n)
{
	t_list	*tmp;
	t_list	*prev;

	tmp = *elem;
	prev = *elem;
	while (tmp && n)
	{
		if (tmp->content_size == n)
			ft_free_lst_c(elem, &prev, &tmp);
		else
			tmp = tmp->next;
	}
}
