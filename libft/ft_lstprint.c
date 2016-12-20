/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 11:21:02 by apopinea          #+#    #+#             */
/*   Updated: 2016/11/27 11:21:03 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	liste op :
**	1 : lire comme une chaine jusqu'au \0.
**	2 : lire jusqu'au size.
*/

void	ft_lstprint(t_list *beg, int op)
{
	size_t	i;

	if (op == 1)
	{
		while (beg)
		{
			ft_putendl(beg->content);
			beg = beg->next;
		}
	}
	else if (op == 2)
	{
		while (beg)
		{
			i = 0;
			while (i < beg->content_size)
				ft_putchar(((char*)(beg->content))[i++]);
			ft_putchar('\n');
			beg = beg->next;
		}
	}
}
