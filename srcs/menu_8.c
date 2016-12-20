/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_8.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 08:44:15 by apopinea          #+#    #+#             */
/*   Updated: 2016/12/20 08:44:18 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lib_fdf.h"
#include "mlx.h"
#include <stdlib.h>

/*
**	<-- init_tab_f_menu_4 -->
**		init tab ptrf
**	ft_error_0 -> libft.h
**		affiche message d'erreur, renvoi 0 ou quite le prog
*/

void	init_tab_f_menu_4(t_menu *tt)
{
	t_pt_ft	*t2;

	t2 = (t_pt_ft*)tt->tab;
	t2[30].pt = &menu_grad_trans;
	t2[30].key = -2;
	t2[31].pt = &menu_grad_mult;
	t2[31].key = -3;
	t2[32].pt = &menu_grad_multg;
	t2[32].key = -4;
	t2[33].pt = &menu_grad_cam;
	t2[33].key = -5;
	t2[34].pt = NULL;
	t2[34].key = 0;
}

/*
** 	<-- menu_grad_rot -->
**		affiche la variation en rotation
**	mlx_put_image_to_window -> mlx.h
**		affiche l'image dans une fenetre
**	mlx_string_put -> mlx.h
**		affiche texte dans une fenetre
*/

void	menu_grad_rot(t_info *fo)
{
	t_menu	*tt;
	char	*tmp;

	tt = fo->menu;
	mlx_put_image_to_window(tt->mlx, tt->win, tt->img2, 115, 30);
	tmp = ft_itoa_f((fo->grad[0]), 4);
	mlx_string_put(tt->mlx, tt->win, 125, 30, COLOR_B, tmp);
	free(tmp);
}

/*
** 	<-- menu_grad_trans -->
**		affiche la variation en translation
**	mlx_put_image_to_window -> mlx.h
**		affiche l'image dans une fenetre
**	mlx_string_put -> mlx.h
**		affiche texte dans une fenetre
*/

void	menu_grad_trans(t_info *fo)
{
	t_menu	*tt;
	char	*tmp;

	tt = fo->menu;
	mlx_put_image_to_window(tt->mlx, tt->win, tt->img2, 115, 160);
	tmp = ft_itoa_f((fo->grad[1]), 1);
	mlx_string_put(tt->mlx, tt->win, 125, 160, COLOR_B, tmp);
	free(tmp);
}

/*
** 	<-- menu_grad_mult -->
**		affiche la variation en multiplication des distance
**	mlx_put_image_to_window -> mlx.h
**		affiche l'image dans une fenetre
**	mlx_string_put -> mlx.h
**		affiche texte dans une fenetre
*/

void	menu_grad_mult(t_info *fo)
{
	t_menu	*tt;
	char	*tmp;

	tt = fo->menu;
	mlx_put_image_to_window(tt->mlx, tt->win, tt->img2, 115, 260);
	tmp = ft_itoa_f((fo->grad[2]), 3);
	mlx_string_put(tt->mlx, tt->win, 125, 260, COLOR_B, tmp);
	free(tmp);
}

/*
** 	<-- menu_grad_cam -->
**		affiche la variation en deplacement cam
**	mlx_put_image_to_window -> mlx.h
**		affiche l'image dans une fenetre
**	mlx_string_put -> mlx.h
**		affiche texte dans une fenetre
*/

void	menu_grad_cam(t_info *fo)
{
	t_menu	*tt;
	char	*tmp;

	tt = fo->menu;
	mlx_put_image_to_window(tt->mlx, tt->win, tt->img2, 115, 390);
	tmp = ft_itoa_f((fo->grad[5]), 3);
	mlx_string_put(tt->mlx, tt->win, 125, 390, COLOR_B, tmp);
	free(tmp);
}
