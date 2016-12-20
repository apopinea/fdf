/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 16:26:46 by apopinea          #+#    #+#             */
/*   Updated: 2016/12/16 16:26:47 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"
#include "lib_fdf.h"
#include <stdlib.h>

/*
** 	<-- menu_rot_z -->
**		affiche la rot sur z en rad
**	mlx_put_image_to_window -> mlx.h
**		affiche l'image dans une fenetre
**	mlx_string_put -> mlx.h
**		affiche texte dans une fenetre
*/

void	menu_rot_z(t_info *fo)
{
	t_menu	*tt;
	char	*tmp;

	tt = fo->menu;
	mlx_put_image_to_window(tt->mlx, tt->win, tt->img2, 150, 90);
	tmp = ft_itoa_f((fo->rot[2]), 2);
	mlx_string_put(tt->mlx, tt->win, 150, 90, COLOR_B, tmp);
	free(tmp);
}

/*
** 	<-- menu_rot_y -->
**		affiche la rot sur y en rad
**	mlx_put_image_to_window -> mlx.h
**		affiche l'image dans une fenetre
**	mlx_string_put -> mlx.h
**		affiche texte dans une fenetre
*/

void	menu_rot_y(t_info *fo)
{
	t_menu	*tt;
	char	*tmp;

	tt = fo->menu;
	mlx_put_image_to_window(tt->mlx, tt->win, tt->img2, 150, 70);
	tmp = ft_itoa_f((fo->rot[1]), 2);
	mlx_string_put(tt->mlx, tt->win, 150, 70, COLOR_B, tmp);
	free(tmp);
}

/*
** 	<-- menu_rot_x -->
**		affiche la rot sur x en rad
**	mlx_put_image_to_window -> mlx.h
**		affiche l'image dans une fenetre
**	mlx_string_put -> mlx.h
**		affiche texte dans une fenetre
*/

void	menu_rot_x(t_info *fo)
{
	t_menu	*tt;
	char	*tmp;

	tt = fo->menu;
	mlx_put_image_to_window(tt->mlx, tt->win, tt->img2, 150, 50);
	tmp = ft_itoa_f((fo->rot[0]), 2);
	mlx_string_put(tt->mlx, tt->win, 150, 50, COLOR_B, tmp);
	free(tmp);
}

/*
** 	<-- menu_rot_type -->
**		affiche le type de rot
**	mlx_put_image_to_window -> mlx.h
**		affiche l'image dans une fenetre
**	mlx_string_put -> mlx.h
**		affiche texte dans une fenetre
*/

void	menu_rot_type(t_info *fo)
{
	t_menu	*tt;
	char	*tmp;

	tt = fo->menu;
	mlx_put_image_to_window(tt->mlx, tt->win, tt->img2, 150, 110);
	if (fo->rot_type == 0)
		tmp = "Cardan";
	else
		tmp = "Euler";
	mlx_string_put(tt->mlx, tt->win, 150, 110, COLOR_B, tmp);
}

/*
** 	<-- menu_tran_h -->
**		affiche la translation horizontal
**	mlx_put_image_to_window -> mlx.h
**		affiche l'image dans une fenetre
**	mlx_string_put -> mlx.h
**		affiche texte dans une fenetre
*/

void	menu_tran_h(t_info *fo)
{
	t_menu	*tt;
	char	*tmp;

	tt = fo->menu;
	mlx_put_image_to_window(tt->mlx, tt->win, tt->img2, 150, 180);
	tmp = ft_itoa((fo->trans[0]));
	mlx_string_put(tt->mlx, tt->win, 150, 180, COLOR_B, tmp);
	free(tmp);
}
