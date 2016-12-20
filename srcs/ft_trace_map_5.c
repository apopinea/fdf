/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trace_map_5.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 13:51:36 by apopinea          #+#    #+#             */
/*   Updated: 2016/12/13 13:51:41 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lib_fdf.h"

/*
**	<-- ft_init_grid_losange  -->
**		creer la grid losange
*/

void	ft_init_grid_losange(t_info *fo)
{
	int i;

	errno = 0;
	if (!(fo->losange = (int**)ft_memalloc(sizeof(int*) *
			(fo->los_max[5] + 1))))
		ft_error_0(5, "malloc error dans ft_init_grid_losange", errno);
	i = -1;
	while (++i <= fo->los_max[5])
	{
		if (!(fo->losange[i] = (int*)ft_memalloc(sizeof(int) *
				(fo->los_max[4] + 1))))
			ft_error_0(5, "malloc error dans ft_init_grid_losange", errno);
	}
}

/*
**	<-- ft_verif_losange_in_win -->
**		verifi si le quadrilatere est dans la fenetre
*/

int		ft_verif_losange_in_win(t_info *fo, int x, int y, int *t)
{
	int i;

	i = 4;
	if (fo->ecran[y][x].x < 0 || fo->ecran[y][x].x > fo->win_l ||
			fo->ecran[y][x].y < 0 || fo->ecran[y][x].y > fo->win_h)
		--i;
	if (fo->ecran[y][x + t[1]].x < 0 || fo->ecran[y][x + t[1]].x > fo->win_l ||
		fo->ecran[y][x + t[1]].y < 0 || fo->ecran[y][x + t[1]].y > fo->win_h)
		--i;
	if (fo->ecran[y + t[0]][x + t[1]].x < 0 ||
		fo->ecran[y + t[0]][x + t[1]].x > fo->win_l ||
		fo->ecran[y + t[0]][x + t[1]].y < 0 ||
		fo->ecran[y + t[0]][x + t[1]].y > fo->win_h)
		--i;
	if (fo->ecran[y + t[0]][x].x < 0 || fo->ecran[y + t[0]][x].x > fo->win_l ||
		fo->ecran[y + t[0]][x].y < 0 || fo->ecran[y + t[0]][x].y > fo->win_h)
		--i;
	if (fo->ecran[y + t[0]][x].x == -4242 || fo->ecran[y][x + t[1]].x == -4242
		|| fo->ecran[y + t[0]][x + t[1]].x == -4242 ||
		fo->ecran[y][x].x == -4242)
		i = 0;
	return (i);
}

/*
**	<-- ft_put_color -->
**		creer un tableau contenant les couleurs et quand les placer
*/

void	ft_put_color(t_info *fo, t_pixel *p1, t_pixel *p2)
{
	int		t[3];
	double	l[3];

	l[0] = (double)ABS((fo->col[p1->color][1] - fo->col[p2->color][1]));
	t[2] = (p1->color > p2->color) ? -1 : 1;
	t[0] = p1->color;
	t[1] = 0;
	l[1] = 0.0;
	if (p2->color != p1->color)
	{
		while (t[0] != p2->color)
		{
			l[2] = (double)(ABS((fo->col[t[0]][1] - fo->col[t[0] +
				t[2]][1]))) / (l[0] * 2.0);
			l[1] += l[2];
			fo->p_col[t[1]][1] = fo->col[t[0]][0];
			fo->p_col[t[1]++][0] = l[1];
			l[1] += l[2];
			fo->p_col[t[1]][1] = fo->col[t[0] + t[2]][0];
			fo->p_col[t[1]++][0] = l[1];
			t[0] += t[2];
		}
	}
	fo->p_col[t[1]][0] = 10;
	fo->p_col[t[1]][1] = fo->col[p2->color][0];
}
