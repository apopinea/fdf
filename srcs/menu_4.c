/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 07:34:18 by apopinea          #+#    #+#             */
/*   Updated: 2016/12/17 07:34:20 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"
#include "lib_fdf.h"
#include <stdlib.h>

/*
** 	<-- menu_tran_v -->
**		affiche la translation vertical
**	mlx_put_image_to_window -> mlx.h
**		affiche l'image dans une fenetre
**	mlx_string_put -> mlx.h
**		affiche texte dans une fenetre
*/

void	menu_tran_v(t_info *fo)
{
	t_menu	*tt;
	char	*tmp;

	tt = fo->menu;
	mlx_put_image_to_window(tt->mlx, tt->win, tt->img2, 150, 200);
	tmp = ft_itoa((-fo->trans[1]));
	mlx_string_put(tt->mlx, tt->win, 150, 200, COLOR_B, tmp);
	free(tmp);
}

/*
** 	<-- menu_mult_x -->
**		affiche multiplicateur sur x
**	mlx_put_image_to_window -> mlx.h
**		affiche l'image dans une fenetre
**	mlx_string_put -> mlx.h
**		affiche texte dans une fenetre
*/

void	menu_mult_x(t_info *fo)
{
	t_menu	*tt;
	char	*tmp;

	tt = fo->menu;
	mlx_put_image_to_window(tt->mlx, tt->win, tt->img2, 150, 300);
	tmp = ft_itoa_f((fo->mult[0]), 2);
	mlx_string_put(tt->mlx, tt->win, 150, 300, COLOR_B, tmp);
	free(tmp);
}

/*
** 	<-- menu_mult_y -->
**		affiche multiplicateur sur y
**	mlx_put_image_to_window -> mlx.h
**		affiche l'image dans une fenetre
**	mlx_string_put -> mlx.h
**		affiche texte dans une fenetre
*/

void	menu_mult_y(t_info *fo)
{
	t_menu	*tt;
	char	*tmp;

	tt = fo->menu;
	mlx_put_image_to_window(tt->mlx, tt->win, tt->img2, 150, 320);
	tmp = ft_itoa_f((fo->mult[1]), 2);
	mlx_string_put(tt->mlx, tt->win, 150, 320, COLOR_B, tmp);
	free(tmp);
}

/*
** 	<-- menu_mult_z -->
**		affiche multiplicateur sur z
**	mlx_put_image_to_window -> mlx.h
**		affiche l'image dans une fenetre
**	mlx_string_put -> mlx.h
**		affiche texte dans une fenetre
*/

void	menu_mult_z(t_info *fo)
{
	t_menu	*tt;
	char	*tmp;

	tt = fo->menu;
	mlx_put_image_to_window(tt->mlx, tt->win, tt->img2, 150, 340);
	tmp = ft_itoa_f((fo->mult[2]), 2);
	mlx_string_put(tt->mlx, tt->win, 150, 340, COLOR_B, tmp);
	free(tmp);
}

/*
** 	<-- menu_cam_x -->
**		affiche position cam sur x
**	mlx_put_image_to_window -> mlx.h
**		affiche l'image dans une fenetre
**	mlx_string_put -> mlx.h
**		affiche texte dans une fenetre
*/

void	menu_cam_x(t_info *fo)
{
	t_menu	*tt;
	char	*tmp;

	tt = fo->menu;
	mlx_put_image_to_window(tt->mlx, tt->win, tt->img2, 150, 410);
	tmp = ft_itoa((fo->center[0]));
	mlx_string_put(tt->mlx, tt->win, 150, 410, COLOR_B, tmp);
	free(tmp);
}
