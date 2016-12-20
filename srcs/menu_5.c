/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 10:27:09 by apopinea          #+#    #+#             */
/*   Updated: 2016/12/17 10:27:11 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"
#include "lib_fdf.h"
#include <stdlib.h>

/*
** 	<-- menu_cam_y -->
**		affiche position cam sur y
**	mlx_put_image_to_window -> mlx.h
**		affiche l'image dans une fenetre
**	mlx_string_put -> mlx.h
**		affiche texte dans une fenetre
*/

void	menu_cam_y(t_info *fo)
{
	t_menu	*tt;
	char	*tmp;

	tt = fo->menu;
	mlx_put_image_to_window(tt->mlx, tt->win, tt->img2, 150, 430);
	tmp = ft_itoa((fo->center[1]));
	mlx_string_put(tt->mlx, tt->win, 150, 430, COLOR_B, tmp);
	free(tmp);
}

/*
** 	<-- menu_cam_z -->
**		affiche position cam sur z
**	mlx_put_image_to_window -> mlx.h
**		affiche l'image dans une fenetre
**	mlx_string_put -> mlx.h
**		affiche texte dans une fenetre
*/

void	menu_cam_z(t_info *fo)
{
	t_menu	*tt;
	char	*tmp;

	tt = fo->menu;
	mlx_put_image_to_window(tt->mlx, tt->win, tt->img2, 150, 450);
	tmp = ft_itoa((fo->center[2]));
	mlx_string_put(tt->mlx, tt->win, 150, 450, COLOR_B, tmp);
	free(tmp);
}

/*
** 	<-- menu_lzoom -->
**		affiche deformation
**	mlx_put_image_to_window -> mlx.h
**		affiche l'image dans une fenetre
**	mlx_string_put -> mlx.h
**		affiche texte dans une fenetre
*/

void	menu_lzoom(t_info *fo)
{
	t_menu	*tt;
	char	*tmp;

	tt = fo->menu;
	mlx_put_image_to_window(tt->mlx, tt->win, tt->img2, 150, 540);
	tmp = ft_itoa((fo->l_zoom));
	mlx_string_put(tt->mlx, tt->win, 150, 540, COLOR_B, tmp);
	free(tmp);
}

/*
** 	<-- menu_transparence -->
**		affiche transparence
**	mlx_put_image_to_window -> mlx.h
**		affiche l'image dans une fenetre
**	mlx_string_put -> mlx.h
**		affiche texte dans une fenetre
*/

void	menu_transparence(t_info *fo)
{
	t_menu	*tt;
	char	*tmp;

	tt = fo->menu;
	mlx_put_image_to_window(tt->mlx, tt->win, tt->img2, 150, 500);
	if (fo->transparence == 0)
		tmp = "transparent";
	else
		tmp = "opaque";
	mlx_string_put(tt->mlx, tt->win, 150, 500, COLOR_B, tmp);
}

/*
** 	<-- menu_centrage -->
**		affiche type centre
**	mlx_put_image_to_window -> mlx.h
**		affiche l'image dans une fenetre
**	mlx_string_put -> mlx.h
**		affiche texte dans une fenetre
*/

void	menu_centrage(t_info *fo)
{
	t_menu	*tt;
	char	*tmp;

	tt = fo->menu;
	mlx_put_image_to_window(tt->mlx, tt->win, tt->img2, 150, 520);
	if (fo->centrage == 0)
		tmp = "en (0,0,0)";
	else
		tmp = "image";
	mlx_string_put(tt->mlx, tt->win, 150, 520, COLOR_B, tmp);
}
