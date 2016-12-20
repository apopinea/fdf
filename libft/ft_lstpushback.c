/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 13:10:31 by apopinea          #+#    #+#             */
/*   Updated: 2016/11/14 13:10:33 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstpushback(t_list **begin, void const *content,
	size_t content_size)
{
	t_list	*tmp;

	if (!begin)
	{
		if (!(tmp = ft_lstnew(content, content_size)))
			return (NULL);
		begin = &tmp;
		return (tmp);
	}
	else if (!(*begin))
	{
		if (!(tmp = ft_lstnew(content, content_size)))
			return (NULL);
		*begin = tmp;
		return (tmp);
	}
	tmp = *begin;
	while (tmp->next)
		tmp = tmp->next;
	if (!(tmp->next = ft_lstnew(content, content_size)))
		return (NULL);
	return (tmp->next);
}
