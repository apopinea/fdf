/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:23:03 by apopinea          #+#    #+#             */
/*   Updated: 2016/11/10 15:23:05 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*elem;
	t_list	*tmp;

	if (lst && *f)
	{
		elem = lst;
		while (elem)
		{
			tmp = elem->next;
			(*f)(elem);
			elem = tmp;
		}
	}
}
