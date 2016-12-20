/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trace_map_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 13:30:37 by apopinea          #+#    #+#             */
/*   Updated: 2016/12/13 13:30:39 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lib_fdf.h"

/*
**	<-- ft_losange_extrem_2 ->
**		enregistre valeur max min du quadrilatere (suite)
*/

static void	ft_losange_extrem_2(t_info *fo, int x, int y, int *t)
{
	if (fo->los_max[0] < fo->ecran[y + t[0]][x].x)
		fo->los_max[0] = fo->ecran[y + t[0]][x].x;
	if (fo->los_max[1] > fo->ecran[y + t[0]][x].x)
		fo->los_max[1] = fo->ecran[y + t[0]][x].x;
	if (fo->los_max[2] < fo->ecran[y + t[0]][x].y)
		fo->los_max[2] = fo->ecran[y + t[0]][x].y;
	if (fo->los_max[3] > fo->ecran[y + t[0]][x].y)
		fo->los_max[3] = fo->ecran[y + t[0]][x].y;
	fo->los_max[4] = (fo->los_max[0] - fo->los_max[1]) + 2;
	fo->los_max[5] = (fo->los_max[2] - fo->los_max[3]) + 2;
	if (fo->los_max[4] < 1)
		fo->los_max[4] = 1;
	if (fo->los_max[5] < 1)
		fo->los_max[5] = 1;
}

/*
**	<-- ft_losange_extrem ->
**		enregistre valeur max min du quadrilatere
** 	ft_losange_extrem_2 -> ft_trace_map_3.c
**		enregistre valeur max min du quadrilatere (suite)
*/

static void	ft_losange_extrem(t_info *fo, int x, int y, int *t)
{
	fo->los_max[0] = fo->ecran[y][x].x;
	fo->los_max[1] = fo->ecran[y][x].x;
	fo->los_max[2] = fo->ecran[y][x].y;
	fo->los_max[3] = fo->ecran[y][x].y;
	if (fo->los_max[0] < fo->ecran[y][x + t[1]].x)
		fo->los_max[0] = fo->ecran[y][x + t[1]].x;
	if (fo->los_max[1] > fo->ecran[y][x + t[1]].x)
		fo->los_max[1] = fo->ecran[y][x + t[1]].x;
	if (fo->los_max[2] < fo->ecran[y][x + t[1]].y)
		fo->los_max[2] = fo->ecran[y][x + t[1]].y;
	if (fo->los_max[3] > fo->ecran[y][x + t[1]].y)
		fo->los_max[3] = fo->ecran[y][x + t[1]].y;
	if (fo->los_max[0] < fo->ecran[y + t[0]][x + t[1]].x)
		fo->los_max[0] = fo->ecran[y + t[0]][x + t[1]].x;
	if (fo->los_max[1] > fo->ecran[y + t[0]][x + t[1]].x)
		fo->los_max[1] = fo->ecran[y + t[0]][x + t[1]].x;
	if (fo->los_max[2] < fo->ecran[y + t[0]][x + t[1]].y)
		fo->los_max[2] = fo->ecran[y + t[0]][x + t[1]].y;
	if (fo->los_max[3] > fo->ecran[y + t[0]][x + t[1]].y)
		fo->los_max[3] = fo->ecran[y + t[0]][x + t[1]].y;
	ft_losange_extrem_2(fo, x, y, t);
}

/*
**	<-- ft_efface_int_losange_2  -->
**		efface selon colone
*/

static void	ft_efface_int_losange_2(t_info *fo)
{
	int i;
	int j;
	int **t;

	t = fo->losange;
	j = -1;
	while (++j < fo->los_max[4])
	{
		i = -1;
		while (++i < fo->los_max[5] && (t[i][j] == 0 || t[i][j] == -1))
			t[i][j] = -1;
	}
	j = fo->los_max[4];
	while (--j >= 0)
	{
		i = fo->los_max[5];
		while (--i >= 0 && (t[i][j] == 0 || t[i][j] == -1))
			t[i][j] = -1;
	}
}

/*
**	<-- ft_efface_int_losange -->
**		effce selon ligne
**	ft_efface_int_losange_2  -> ft_trace_map_3.c
**		efface selon colone
*/

static void	ft_efface_int_losange(t_info *fo)
{
	int i;
	int j;
	int **t;

	i = -1;
	t = fo->losange;
	while (++i < fo->los_max[5])
	{
		j = -1;
		while (++j < fo->los_max[4] && (t[i][j] == 0 || t[i][j] == -1))
			t[i][j] = -1;
	}
	i = fo->los_max[5];
	while (--i >= 0)
	{
		j = fo->los_max[4];
		while (--j >= 0 && (t[i][j] == 0 || t[i][j] == -1))
			t[i][j] = -1;
	}
	ft_efface_int_losange_2(fo);
}

/*
** 	<-- ft_trace_losange -->
**		trace un quadrilatere
**	ft_verif_losange_in_win -> ft_trace_map_5.c
**		verifi si le quadrilatere est dans la fenetre
** 	ft_losange_extrem -> ft_trace_map_3.c
**		enregistre valeur max min du quadrilatere
**	ft_init_grid_losange  -> ft_trace_map_5.c
**		creer la grid losange
**	ft_trace_d  -> ft_trace_map_4.c
**		trace les cotes du quadrilatere
**	ft_efface_int_losange  -> ft_trace_map_3.c
**		rempli le quadrilatere de noir
**	ft_fusion_losange  -> ft_trace_map_4.c
**		fusione le quad dnas l'image
**	ft_del_losange -> ft_trace_map_4
**		suprime losange
*/

void		ft_trace_losange(t_info *fo, int x, int y, int *t)
{
	if (ft_verif_losange_in_win(fo, x, y, t))
	{
		ft_losange_extrem(fo, x, y, t);
		ft_init_grid_losange(fo);
		ft_trace_d(fo, &(fo->ecran[y][x]), &(fo->ecran[y][x + t[1]]));
		ft_trace_d(fo, &(fo->ecran[y][x]), &(fo->ecran[y + t[0]][x]));
		ft_trace_d(fo, &(fo->ecran[y][x + t[1]]),
			&(fo->ecran[y + t[0]][x + t[1]]));
		ft_trace_d(fo, &(fo->ecran[y + t[0]][x]),
			&(fo->ecran[y + t[0]][x + t[1]]));
		ft_efface_int_losange(fo);
		ft_fusion_losange(fo);
		ft_del_losange(fo);
	}
}
