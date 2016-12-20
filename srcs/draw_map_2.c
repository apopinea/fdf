/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 13:48:00 by apopinea          #+#    #+#             */
/*   Updated: 2016/12/03 13:48:04 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lib_fdf.h"

/*
**	<-- record_pixel_4 -->
**		enregistre les position des pixel en isometrique
*/

static void		record_pixel_4(t_info *fo, double center[2], int x, int y)
{
	(fo->ecran)[y][x].x = center[2] * fo->final->mat[0][0] + center[3] *
		fo->final->mat[0][1] + center[4] * fo->final->mat[0][2]
		+ (double)(fo->trans[0]) + center[0];
	(fo->ecran)[y][x].y = center[2] * fo->final->mat[1][0] + center[3] *
		fo->final->mat[1][1] + center[4] * fo->final->mat[1][2]
		+ (double)(fo->trans[1]) + center[1];
}

/*
**	<-- record_pixel_3 -->
**		applique la matrice final et la translation a grid en isometrique
**	record_pixel_4 ->draw_map_2.c
**		enregistre les position des pixel en isometrique
*/

void			record_pixel_3(t_info *fo)
{
	int		y;
	int		x;
	double	center[5];

	y = 0;
	center[0] = (double)fo->win_l / 2.0;
	center[1] = (double)fo->win_h / 2.0;
	while (y < fo->h)
	{
		x = 0;
		while (x < fo->l)
		{
			center[2] = (fo->grid)[y][x].x + fo->center[0];
			center[3] = (fo->grid)[y][x].y + fo->center[1];
			center[4] = (fo->grid)[y][x].z + fo->center[2];
			record_pixel_4(fo, center, x, y);
			++x;
		}
		++y;
	}
}

/*
**	<-- ft_recenter -->
**		transale les pixels pour recentrer l'image
*/

void			ft_recentre(t_info *fo)
{
	int		y;
	int		x;
	double	recenter[2];

	y = 0;
	recenter[0] = fo->extrem2[0] - (double)fo->win_l + fo->extrem2[1];
	recenter[1] = fo->extrem2[2] - (double)fo->win_h + fo->extrem2[3];
	while (y < fo->h)
	{
		x = 0;
		while (x < fo->l)
		{
			(fo->ecran)[y][x].x = (fo->ecran)[y][x].x - (recenter[0] / 2)
				+ fo->trans[0];
			(fo->ecran)[y][x].y = (fo->ecran)[y][x].y + (recenter[1] / 2)
				+ fo->trans[1];
			++x;
		}
		++y;
	}
}

/*
**	<-- ft_pixel_extrem -->
**		enregistrer les max min des position pixel
*/

void			ft_pixel_extrem(t_info *fo)
{
	int y;
	int x;

	fo->extrem2[0] = (fo->ecran)[0][0].x;
	fo->extrem2[1] = (fo->ecran)[0][0].x;
	fo->extrem2[2] = (fo->ecran)[0][0].y;
	fo->extrem2[3] = (fo->ecran)[0][0].y;
	y = -1;
	while (++y < fo->h)
	{
		x = -1;
		while (++x < fo->l)
		{
			fo->extrem2[0] = ((fo->ecran)[y][x].x > fo->extrem2[0]) ?
				(fo->ecran)[y][x].x : fo->extrem2[0];
			fo->extrem2[1] = ((fo->ecran)[y][x].x < fo->extrem2[1]) ?
				(fo->ecran)[y][x].x : fo->extrem2[1];
			fo->extrem2[2] = ((fo->ecran)[y][x].y > fo->extrem2[2]) ?
				(fo->ecran)[y][x].y : fo->extrem2[2];
			fo->extrem2[3] = ((fo->ecran)[y][x].y < fo->extrem2[3]) ?
				(fo->ecran)[y][x].y : fo->extrem2[3];
		}
	}
}

/*
**	<-- ft_horizon_cal -->
**		applique la matrice final au 4 coins temoins
*/

void			ft_horizon_cal(t_info *fo)
{
	int i;

	i = 0;
	while (i < 4)
	{
		fo->horizon[i + 4].x = i;
		fo->horizon[i + 4].z = (fo->horizon[i].x + fo->center[0]) *
			fo->final->mat[2][0] + (fo->horizon[i].y + fo->center[1]) *
			fo->final->mat[2][1] + (fo->horizon[i].z + fo->center[2]) *
			fo->final->mat[2][2];
		++i;
	}
}
