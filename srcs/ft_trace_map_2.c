/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trace_map_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 13:23:55 by apopinea          #+#    #+#             */
/*   Updated: 2016/12/13 13:23:56 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lib_fdf.h"

/*
**	<-- ft_trace_x_2 -->
**		trace la droite selon l'axe x dans l'image
**			mlx_pixel_put(fo->mlx, fo->win, x, y, p1->color);
**	ft_put_color -> ft_trace_map_5.c
**		creer un tableau contenant les couleurs et quand les placer
*/

static void	ft_trace_x_2(t_info *fo, t_pixel *p1, t_pixel *p2, float r1)
{
	int		x;
	int		y;
	int		k[2];
	int		m;
	double	i;

	ft_put_color(fo, p1, p2);
	x = p1->x;
	y = p1->y;
	k[0] = (x > p2->x) ? -1 : 1;
	m = ABS((p1->x - p2->x));
	i = 0.0;
	k[1] = 0;
	while (x - k[0] != p2->x)
	{
		if (i++ >= m * fo->p_col[k[1]][0])
			++k[1];
		if (y < fo->win_h && x < fo->win_l && y >= 0 && x >= 0)
			fo->pixel_img[(x + y * fo->win_l)] = fo->p_col[k[1]][1];
		x += k[0];
		y = p1->y + ((float)x - (float)p1->x) * r1;
	}
}

/*
**	<-- ft_trace_y_2 -->
**		trace la droite selon l'axe y dans l'image
**	ft_put_color -> ft_trace_map_5.c
**		creer un tableau contenant les couleurs et quand les placer
*/

static void	ft_trace_y_2(t_info *fo, t_pixel *p1, t_pixel *p2, float r2)
{
	int		x;
	int		y;
	int		k[2];
	int		m;
	double	i;

	ft_put_color(fo, p1, p2);
	x = p1->x;
	y = p1->y;
	k[0] = (y > p2->y) ? -1 : 1;
	m = ABS((p1->y - p2->y));
	i = 0.0;
	k[1] = 0;
	while (y - k[0] != p2->y)
	{
		if (i++ >= m * fo->p_col[k[1]][0])
			++k[1];
		if (y < fo->win_h && x < fo->win_l && y >= 0 && x >= 0)
			fo->pixel_img[(x + y * fo->win_l)] = fo->p_col[k[1]][1];
		y += k[0];
		x = p1->x + ((float)y - (float)p1->y) * r2;
	}
}

/*
**	<-- ft_trace_d_2 -->
**		trace droite dans l'image
**	ft_trace_x_2 -> ft_trace_map_2.c
**		trace la droite selon l'axe x dans l'image
**	ft_trace_y_2 -> ft_trace_map_2.c
**		trace la droite selon l'axe y dans l'image
*/

static void	ft_trace_d_2(t_info *fo, t_pixel *p1, t_pixel *p2)
{
	float	r1;
	float	r2;

	r1 = (float)(p2->y - p1->y) / (float)(p2->x - p1->x);
	r2 = (float)(p2->x - p1->x) / (float)(p2->y - p1->y);
	if (ABS(r1) <= ABS(r2))
		ft_trace_x_2(fo, p1, p2, r1);
	else
		ft_trace_y_2(fo, p1, p2, r2);
}

/*
**	<-- verif_droite_in_win -->
**		verifi si la droite est dans la fenetre
*/

static int	verif_droite_in_win(t_info *fo, t_pixel *p1, t_pixel *p2)
{
	int i;

	i = 2;
	if (p1->x < 0 || p1->y < 0 || p1->x > fo->win_l || p1->y > fo->win_h)
		--i;
	if (p2->x < 0 || p2->y < 0 || p2->x > fo->win_l || p2->y > fo->win_h)
		--i;
	if (p2->x == -4242 || p1->x == -4242)
		i = 0;
	return (i);
}

/*
**	<-- ft_trac_map_4 -->
**		trace map transparence desactivé
**	verif_droite_in_win -> ft_trace_map_2.c
**		verifi si la droite est dans la fenetre
**	ft_trace_d_2 -> ft_trace_map_2.c
**		trace droite dans l'image
*/

void		ft_trace_map_4(t_info *fo)
{
	int x;
	int y;

	y = 0;
	while (y < fo->h)
	{
		x = 0;
		while (x < fo->l)
		{
			if (x + 1 < fo->l && verif_droite_in_win(fo,
					&fo->ecran[y][x], &fo->ecran[y][x + 1]))
				ft_trace_d_2(fo, &fo->ecran[y][x], &fo->ecran[y][x + 1]);
			if (y + 1 < fo->h && verif_droite_in_win(fo,
					&fo->ecran[y][x], &fo->ecran[y + 1][x]))
				ft_trace_d_2(fo, &fo->ecran[y][x], &fo->ecran[y + 1][x]);
			++x;
		}
		++y;
	}
}
