/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:13:25 by apopinea          #+#    #+#             */
/*   Updated: 2016/11/10 15:13:26 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst)
{
	t_list	*begin;
	t_list	*next;

	if (alst && *alst)
	{
		begin = *alst;
		while (begin)
		{
			next = begin->next;
			ft_lstdelone(&begin);
			begin = next;
		}
		*alst = NULL;
	}
}
