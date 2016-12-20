/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outil_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 10:42:48 by apopinea          #+#    #+#             */
/*   Updated: 2016/12/12 10:42:55 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lib_fdf.h"

/*
**	choix du tableau a afficher
*/

static void	ft_print_grid_2(t_info *fo, int i, int x, int y)
{
	if (i == 0)
		ft_putfloat((fo->grid)[y][x].x);
	if (i == 1)
		ft_putfloat((fo->grid)[y][x].y);
	if (i == 2)
		ft_putfloat((fo->grid)[y][x].z);
	if (i == 3)
		ft_putfloat((fo->grid)[y][x].color);
	if (i == 4)
		ft_putfloat((fo->ecran)[y][x].x);
	if (i == 5)
		ft_putfloat((fo->ecran)[y][x].y);
}

/*
**	OUTIL DEBUG AFICE TABLEAU
*/

void		ft_print_grid(t_info *fo, int i)
{
	int x;
	int y;

	y = 0;
	while (y < fo->h)
	{
		x = 0;
		while (x < fo->l)
		{
			ft_print_grid_2(fo, i, x, y);
			ft_putchar(' ');
			++x;
		}
		ft_putendl("");
		++y;
	}
}
