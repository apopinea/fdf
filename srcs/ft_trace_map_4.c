/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trace_map_4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 13:32:58 by apopinea          #+#    #+#             */
/*   Updated: 2016/12/13 13:33:00 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lib_fdf.h"
#include <stdlib.h>

/*
**	<-- ft_trace_x -->
**		trace la droite selon l'axe x dans losange
**	ft_put_color -> ft_trace_map_5.c
**		creer un tableau contenant les couleurs et quand les placer
*/

static void	ft_trace_x(t_info *fo, t_pixel *p1, t_pixel *p2, float r1)
{
	int		x1;
	int		y1;
	int		l[4];
	int		m;
	double	i;

	ft_put_color(fo, p1, p2);
	l[0] = fo->los_max[3] - 1;
	l[1] = fo->los_max[1] - 1;
	x1 = p1->x;
	y1 = p1->y;
	l[3] = (x1 > p2->x) ? -1 : 1;
	m = ABS((p1->x - p2->x));
	i = 0.0;
	l[2] = 0;
	while (x1 - l[3] != p2->x)
	{
		if (i++ >= m * fo->p_col[l[2]][0])
			++l[2];
		fo->losange[y1 - l[0]][x1 - l[1]] = fo->p_col[l[2]][1];
		x1 += l[3];
		y1 = p1->y + ((float)x1 - (float)p1->x) * r1;
	}
}

/*
**	<-- ft_trace_y -->
**		trace la droite selon l'axe y dans losange
**	ft_put_color -> ft_trace_map_5.c
**		creer un tableau contenant les couleurs et quand les placer
*/

static void	ft_trace_y(t_info *fo, t_pixel *p1, t_pixel *p2, float r2)
{
	int		x;
	int		y;
	int		l[4];
	int		m;
	double	i;

	ft_put_color(fo, p1, p2);
	x = p1->x;
	y = p1->y;
	l[0] = fo->los_max[3] - 1;
	l[1] = fo->los_max[1] - 1;
	l[3] = (y > p2->y) ? -1 : 1;
	m = ABS((p1->y - p2->y));
	i = 0.0;
	l[2] = 0;
	while (y - l[3] != p2->y)
	{
		if (i++ >= m * fo->p_col[l[2]][0])
			++l[2];
		fo->losange[y - l[0]][x - l[1]] = fo->p_col[l[2]][1];
		y += l[3];
		x = p1->x + ((float)y - (float)p1->y) * r2;
	}
}

/*
**	<-- ft_trace_d  -->
**		trace les cotes du quadrilatere
**	ft_trace_x -> ft_trace_map_4.c
**		trace la droite selon l'axe x dans losange
**	ft_trace_y -> ft_trace_map_4.c
**		trace la droite selon l'axe y dans losange
*/

void		ft_trace_d(t_info *fo, t_pixel *p1, t_pixel *p2)
{
	float	r1;
	float	r2;

	r1 = (float)(p2->y - p1->y) / (float)(p2->x - p1->x);
	r2 = (float)(p2->x - p1->x) / (float)(p2->y - p1->y);
	if (ABS(r1) <= ABS(r2))
		ft_trace_x(fo, p1, p2, r1);
	else
		ft_trace_y(fo, p1, p2, r2);
}

/*
**	<-- ft_del_losange -->
**		suprime losange
*/

void		ft_del_losange(t_info *fo)
{
	int i;

	if (fo && fo->losange)
	{
		i = -1;
		while (++i < fo->los_max[5])
			free(fo->losange[i]);
		free(fo->losange);
		fo->losange = NULL;
	}
}

/*
**	<-- ft_fusion_losange  ->
**		fusione le quad dnas l'image
*/

void		ft_fusion_losange(t_info *fo)
{
	int i;
	int j;
	int t[2];
	int l;
	int h;

	t[1] = fo->los_max[1];
	t[0] = fo->los_max[3];
	i = -1;
	while (++i < fo->los_max[5])
	{
		j = -1;
		while (++j < fo->los_max[4])
		{
			l = (j + t[1]);
			h = (t[0] + i);
			if (fo->losange[i][j] != -1 && l < fo->win_l && h < fo->win_h &&
					l > -1 && h > -1)
				fo->pixel_img[l + h * fo->win_l] = fo->losange[i][j];
		}
	}
}
