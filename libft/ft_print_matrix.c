/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 13:53:19 by apopinea          #+#    #+#             */
/*   Updated: 2016/11/24 13:53:21 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_matrix(t_matrix *a)
{
	size_t	k;
	size_t	l;

	if (!a)
		return ;
	k = 0;
	while (k < a->i)
	{
		l = 0;
		while (l < a->j)
		{
			ft_putfloat((a->mat)[k][l++]);
			ft_putchar('\t');
		}
		ft_putchar('\n');
		++k;
	}
}
