/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_fdf_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 14:29:39 by apopinea          #+#    #+#             */
/*   Updated: 2016/12/17 14:29:41 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lib_fdf.h"
#include <stdlib.h>

/*
**	<-- fdf_free_ecran -->
**		free le double tableau ecran
*/

void		fdf_free_ecran(t_info *fo)
{
	int		i;

	i = -1;
	while (++i < fo->h)
		free(fo->ecran[i]);
	free(fo->ecran);
	fo->ecran = NULL;
}

/*
**	<-- fdf_free_grid -->
**		free le double tableau grid
*/

void		fdf_free_grid(t_info *fo)
{
	int		i;

	i = -1;
	while (++i < fo->h)
		free(fo->grid[i]);
	free(fo->grid);
	fo->grid = NULL;
}

/*
**	<-- fdf_free_col -->
**		free le double tableau col
*/

void		fdf_free_col(t_info *fo)
{
	int		i;

	i = -1;
	while (++i < fo->nb_col)
		free(fo->col[i]);
	free(fo->col);
	fo->col = NULL;
}

/*
**	<-- fdf_free_p_col -->
**		free le double tableau p_col
*/

void		fdf_free_p_col(t_info *fo)
{
	int		i;

	i = -1;
	while (++i < fo->nbz + 10 + fo->nb_col)
		free(fo->p_col[i]);
	free(fo->p_col);
	fo->col = NULL;
}

/*
**	<-- fdf_free_matrix -->
**		free les matrices
*/

void		fdf_free_matrix(t_info *fo)
{
	ft_del_matrix(&(fo->rot_x));
	ft_del_matrix(&(fo->rot_y));
	ft_del_matrix(&(fo->rot_z));
	ft_del_matrix(&(fo->rot_zoom));
	ft_del_matrix(&(fo->final));
}
