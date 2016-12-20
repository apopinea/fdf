/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 09:54:00 by apopinea          #+#    #+#             */
/*   Updated: 2016/12/03 09:54:01 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lib_fdf.h"
#include <math.h>

/*
**	<-- ft_mixt_matrice -->
**		multiplie les matrice entre elle pour avoir la matrice final cardan
**	ft_error_n -> libft
**		affiche message d'erreur, renvoi NULL ou quite le prog
**	ft_opera_matrix -> libft
**		lanceur d'operation sur matrice
**	ft_del_matrice -> libft
**		suprimme matrice
*/

static void	ft_mixt_matrice(t_info *fo)
{
	t_matrix	*tmp;
	t_matrix	*tmp2;

	ft_del_matrix(&(fo->final));
	if (!(tmp = ft_opera_matrix(fo->rot_x, "*", fo->rot_y)))
		ft_error_n(4, "erreur operation sur matrice : ", 0);
	if (!(tmp2 = ft_opera_matrix(tmp, "*", fo->rot_z)))
		ft_error_n(4, "erreur operation sur matrice : ", 0);
	ft_del_matrix(&tmp);
	if (!(fo->final = ft_opera_matrix(tmp2, "*", fo->rot_zoom)))
		ft_error_n(4, "erreur operation sur matrice : ", 0);
	ft_del_matrix(&tmp2);
}

/*
**	<-- ft_matrice_value -->
**		creer la matrice final.
**	ft_mixt_matrice -> draw_map.c
**		multiplie les matrice entre elle pour avoir la matrice final cardan
**	ft_mixt_matrice_2 -> draw_map_3.c
**		multiplie les matrice entre elle pour avoir la matrice final euler
*/

static void	ft_matrice_value(t_info *fo)
{
	fo->rot_x->mat[0][0] = 1;
	fo->rot_x->mat[1][1] = cos(fo->rot[0]);
	fo->rot_x->mat[1][2] = -sin(fo->rot[0]);
	fo->rot_x->mat[2][1] = sin(fo->rot[0]);
	fo->rot_x->mat[2][2] = cos(fo->rot[0]);
	fo->rot_y->mat[1][1] = 1;
	fo->rot_y->mat[0][0] = cos(fo->rot[1]);
	fo->rot_y->mat[2][0] = -sin(fo->rot[1]);
	fo->rot_y->mat[0][2] = sin(fo->rot[1]);
	fo->rot_y->mat[2][2] = cos(fo->rot[1]);
	fo->rot_z->mat[2][2] = -1;
	fo->rot_z->mat[1][1] = cos(fo->rot[2]);
	fo->rot_z->mat[0][1] = -sin(fo->rot[2]);
	fo->rot_z->mat[1][0] = sin(fo->rot[2]);
	fo->rot_z->mat[0][0] = cos(fo->rot[2]);
	fo->rot_zoom->mat[0][0] = fo->mult[0];
	fo->rot_zoom->mat[1][1] = fo->mult[1];
	fo->rot_zoom->mat[2][2] = fo->mult[2];
	if (fo->rot_type == 0)
		ft_mixt_matrice(fo);
	else
		ft_mixt_matrice_2(fo);
}

/*
**	<-- record_pixel_2 -->
**		enregistre les position des pixel en conique
*/

static void	record_pixel_2(t_info *fo, double center[5], int x, int y)
{
	double z;

	z = (center[2] * fo->final->mat[2][0] + center[3] * fo->final->mat[2][1] +
		center[4] * fo->final->mat[2][2]);
	if ((int)z > -fo->l_zoom)
	{
		(fo->ecran)[y][x].x = (((center[2] * fo->final->mat[0][0] + center[3] *
		fo->final->mat[0][1] + center[4] * fo->final->mat[0][2]) * fo->l_zoom)
		/ (fo->l_zoom + z)) + (double)(fo->trans[0]) + center[0];
		(fo->ecran)[y][x].y = (((center[2] * fo->final->mat[1][0] + center[3] *
		fo->final->mat[1][1] + center[4] * fo->final->mat[1][2]) * fo->l_zoom)
		/ (fo->l_zoom + z)) + (double)(fo->trans[1]) + center[1];
	}
	else
	{
		(fo->ecran)[y][x].x = -4242;
	}
}

/*
**	<-- record_pixel -->
**		applique la matrice final et la translation a grid en connique
**	record_pixel_2 -> draw_map.c
**		enregistre les position des pixel en conique
*/

static void	record_pixel(t_info *fo)
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
			record_pixel_2(fo, center, x, y);
			++x;
		}
		++y;
	}
}

/*
**	<-- draw_map -->
**		calcul la carte puis la dessine
**	ft_matrice_value -> draw_map.c
**		creer la matrice final.
**	record_pixel -> draw_map.c
**		applique la matrice final et la translation a grid en connique
**	record_pixel_3 -> draw_map_2.c
**		applique la matrice final et la translation a grid en isometrique
**	ft_pixel_extrem -> draw_map_2.c
**		enregistrer les max min des position pixel
**	ft_recentre -> draw_map_2.c
**		decale l'image pour la centré
**	ft_horizon_cal -> draw_map_2.c
**		applique la matrice final au 4 coins temoins
** 	ft_trace_map -> ft_trace_map.c
**		trace la carte dans une image
*/

void		draw_map(t_info *fo)
{
	ft_matrice_value(fo);
	if (fo->l_zoom != 0)
		record_pixel(fo);
	if (fo->l_zoom == 0)
		record_pixel_3(fo);
	if (fo->centrage == 1)
	{
		ft_pixel_extrem(fo);
		ft_recentre(fo);
	}
	ft_horizon_cal(fo);
	ft_trace_map(fo);
}
