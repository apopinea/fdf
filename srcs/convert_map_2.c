/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_map_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 13:44:42 by apopinea          #+#    #+#             */
/*   Updated: 2016/12/01 13:44:44 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lib_fdf.h"
#include <math.h>

/*
**	<-- ft_verif_win -->
**		verifie la validité de la taille de la fenetre.
*/

static void	ft_verif_win(t_info *fo)
{
	int nb1;
	int nb2;
	int nb3;

	if (fo->win_h < 30 || fo->win_l < 30)
	{
		nb1 = (fo->mult[0] * fo->l);
		nb2 = (fo->mult[1] * fo->h);
		nb3 = (fo->extrem[0] - fo->extrem[1]) * (fo->mult[2]);
		if (nb2 > nb1)
			nb1 = nb2;
		if (nb3 > nb1)
			nb1 = nb3;
		fo->win_h = sqrt(1.7 * (double)nb1 * (double)nb1);
		if (fo->win_h > 1400)
			fo->win_h = MAX_WIN;
		fo->win_l = fo->win_h;
	}
}

/*
**	<-- ft_extrem_map -->
**		enregistre les valeur les plus grande de x,y,z etverif taille win
**	ft_verif_win -> convert_map_2.c
**		verifie la validité de la taille de la fenetre.
*/

void		ft_extrem_map(t_info *fo)
{
	int		y;
	int		x;

	y = -1;
	fo->extrem[0] = (fo->grid)[0][0].z;
	fo->extrem[1] = (fo->grid)[0][0].z;
	while (++y < fo->h)
	{
		x = -1;
		while (++x < fo->l)
		{
			fo->extrem[0] = ((fo->grid)[y][x].z > fo->extrem[0]) ?
				(fo->grid)[y][x].z : fo->extrem[0];
			fo->extrem[1] = ((fo->grid)[y][x].z < fo->extrem[1]) ?
				(fo->grid)[y][x].z : fo->extrem[1];
		}
	}
	ft_verif_win(fo);
}

/*
**	<-- ft_init_horizon -->
**		garde les 4 coin de la map a z = 0 pour utilisation ulterieur
*/

void		ft_init_horizon(t_info *fo)
{
	(fo->horizon)[0].x = (fo->grid)[0][0].x;
	(fo->horizon)[0].y = (fo->grid)[0][0].y;
	(fo->horizon)[0].z = 0;
	(fo->horizon)[4].x = 1;
	(fo->horizon)[1].x = (fo->grid)[0][fo->l - 1].x;
	(fo->horizon)[1].y = (fo->grid)[0][fo->l - 1].y;
	(fo->horizon)[1].z = 0;
	(fo->horizon)[5].x = 2;
	(fo->horizon)[2].x = (fo->grid)[fo->h - 1][fo->l - 1].x;
	(fo->horizon)[2].y = (fo->grid)[fo->h - 1][fo->l - 1].y;
	(fo->horizon)[2].z = 0;
	(fo->horizon)[6].x = 3;
	(fo->horizon)[3].x = (fo->grid)[fo->h - 1][0].x;
	(fo->horizon)[3].y = (fo->grid)[fo->h - 1][0].y;
	(fo->horizon)[3].z = 0;
	(fo->horizon)[7].x = 4;
}
