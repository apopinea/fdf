/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 12:43:26 by apopinea          #+#    #+#             */
/*   Updated: 2016/12/17 12:43:28 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lib_fdf.h"
#include "mlx.h"
#include <stdlib.h>

/*
**	<-- fdf_free_menut -->
**		free la struct menut de type t_menu_t
*/

void		fdf_free_menut(t_info *fo)
{
	t_menu_t *tt;

	tt = fo->menut;
	mlx_destroy_image(fo->mlx, fo->menut->img);
	free(tt);
}

/*
**	<-- fdf_free_menu -->
**		free la struct menu de type t_menu
*/

void		fdf_free_menu(t_info *fo)
{
	t_menu *tt;

	tt = fo->menu;
	free(fo->menu->tab);
	mlx_destroy_image(fo->mlx, fo->menu->img);
	mlx_destroy_image(fo->mlx, fo->menu->img2);
	free(tt);
}

/*
**	<-- fdf_exit -->
**		quite le prog
*/

void		fdf_exit_f(void)
{
	ft_putendl("\n\033[31mEEEEE  N     N  DD");
	ft_putendl("E      NN    N  D  DD");
	ft_putendl("E      N N   N  D    DD");
	ft_putendl("EEEEE  N  N  N  D     D");
	ft_putendl("E      N   N N  D    DD");
	ft_putendl("E      N    NN  D  DD");
	ft_putendl("EEEEE  N     N  DD\033[0m");
	exit(0);
}

/*
**	<-- ft_exit_fdf -->
**		libere la memoire et quite le prog
**	fdf_free_ecran -> exit_fdf_2.c
**		free le double tableau ecran
**	fdf_free_grid -> exit_fdf_2.c
**		free le double tableau grid
**	fdf_free_col -> exit_fdf_2.c
**		free le double tableau col
**	fdf_free_p_col -> exit_fdf_2.c
**		free le double tableau p_col
**	fdf_free_matrix -> exit_fdf_2.c
**		free les matrices
**	fdf_free_menut -> exit_fdf.c
**		free la struct menut de type t_menu_t
**	fdf_free_menu -> exit_fdf.c
**		free la struct menu de type t_menu
**	fdf_exit -> exit_fdf.c
**		quite le prog
*/

void		ft_exit_fdf(t_info *fo)
{
	if (fo->f_principal == 1)
		mlx_destroy_window(fo->mlx, fo->win);
	if (fo->menut_a == 1)
		mlx_destroy_window(fo->mlx, fo->menut->win);
	if (fo->menu_a == 1)
		mlx_destroy_window(fo->mlx, fo->menu->win);
	fdf_free_ecran(fo);
	fdf_free_grid(fo);
	fdf_free_col(fo);
	fdf_free_p_col(fo);
	fdf_free_matrix(fo);
	free(fo->t_nbz);
	fdf_free_menut(fo);
	fdf_free_menu(fo);
	free(fo);
	fdf_exit_f();
}
