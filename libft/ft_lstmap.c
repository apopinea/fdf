/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:27:42 by apopinea          #+#    #+#             */
/*   Updated: 2016/11/10 15:27:44 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*beg;
	t_list	*prev;
	t_list	*new;

	if (!lst || !f)
		return (NULL);
	if (!(beg = ft_lstnew(lst->content, lst->content_size)))
		return (NULL);
	beg = (*f)(beg);
	prev = beg;
	lst = lst->next;
	while (lst)
	{
		if (!(new = ft_lstnew(lst->content, lst->content_size)))
			return (NULL);
		new = (*f)(new);
		prev->next = new;
		prev = new;
		lst = lst->next;
	}
	return (beg);
}
