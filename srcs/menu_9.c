/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_9.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 12:51:15 by apopinea          #+#    #+#             */
/*   Updated: 2016/12/20 12:51:17 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lib_fdf.h"
#include "mlx.h"
#include <stdlib.h>

/*
** 	<-- menu_grad_multg -->
**		affiche la variation en multiplication des distance general
**	mlx_put_image_to_window -> mlx.h
**		affiche l'image dans une fenetre
**	mlx_string_put -> mlx.h
**		affiche texte dans une fenetre
*/

void		menu_grad_multg(t_info *fo)
{
	t_menu	*tt;
	char	*tmp;

	tt = fo->menu;
	mlx_put_image_to_window(tt->mlx, tt->win, tt->img2, 115, 280);
	mlx_put_image_to_window(tt->mlx, tt->win, tt->img2, 220, 280);
	if (fo->grad[3] == 2)
		tmp = "double / moitie";
	else if (fo->grad[3] == 1.1)
		tmp = "10%";
	else
		tmp = "1%";
	mlx_string_put(tt->mlx, tt->win, 125, 280, COLOR_B, tmp);
}

/*
**	<-- mouse_hook_7 -->
**		evenement souris
*/

static void	mouse_hook_7(int but, int x, int y, t_info *fo)
{
	if (x > 74 && x < 91 && y > 284 && y < 300 && but == 1)
	{
		if (fo->grad[3] == 1.01)
			fo->grad[3] = 1.1;
		else if (fo->grad[3] == 1.1)
			fo->grad[3] = 2;
		if (fo->grad[4] == 0.99)
			fo->grad[4] = 0.9;
		else if (fo->grad[4] == 0.9)
			fo->grad[4] = 0.5;
		menu_grad_multg(fo);
	}
	else if (x > 94 && x < 111 && y > 394 && y < 410 && but == 1)
	{
		fo->grad[5] = (fo->grad[5] > 0.001) ? fo->grad[5] / 10 : 0.001;
		menu_grad_cam(fo);
	}
	else if (x > 74 && x < 91 && y > 394 && y < 410 && but == 1)
	{
		fo->grad[5] = (fo->grad[5] < 100) ? fo->grad[5] * 10 : 100;
		menu_grad_cam(fo);
	}
}

/*
**	<-- mouse_hook_6 -->
**		evenement souris
**	mouse_hook_7 -> menu_9.c
**		suite
*/

static void	mouse_hook_6(int but, int x, int y, t_info *fo)
{
	if (x > 94 && x < 111 && y > 264 && y < 280 && but == 1)
	{
		fo->grad[2] = (fo->grad[2] > 0.001) ? fo->grad[2] / 10 : 0.001;
		menu_grad_mult(fo);
	}
	else if (x > 74 && x < 91 && y > 264 && y < 280 && but == 1)
	{
		fo->grad[2] = (fo->grad[2] < 100) ? fo->grad[2] * 10 : 100;
		menu_grad_mult(fo);
	}
	else if (x > 94 && x < 111 && y > 284 && y < 300 && but == 1)
	{
		if (fo->grad[3] == 2)
			fo->grad[3] = 1.1;
		else if (fo->grad[3] == 1.1)
			fo->grad[3] = 1.01;
		if (fo->grad[4] == 0.5)
			fo->grad[4] = 0.9;
		else if (fo->grad[4] == 0.9)
			fo->grad[4] = 0.99;
		menu_grad_multg(fo);
	}
	else
		mouse_hook_7(but, x, y, fo);
}

/*
**	<-- mouse_hook_5 -->
**		evenement souris
**	mouse_hook_6 -> menu_9.c
**		suite
*/

void		mouse_hook_5(int but, int x, int y, t_info *fo)
{
	if (x > 94 && x < 111 && y > 33 && y < 50 && but == 1)
	{
		fo->grad[0] = (fo->grad[0] > 0.0001) ? fo->grad[0] / 10 : 0.0001;
		menu_grad_rot(fo);
	}
	else if (x > 74 && x < 91 && y > 33 && y < 50 && but == 1)
	{
		fo->grad[0] = (fo->grad[0] < 100) ? fo->grad[0] * 10 : 100;
		menu_grad_rot(fo);
	}
	else if (x > 94 && x < 111 && y > 164 && y < 180 && but == 1)
	{
		fo->grad[1] = (fo->grad[1] > 1) ? fo->grad[1] / 10 : 1;
		menu_grad_trans(fo);
	}
	else if (x > 74 && x < 91 && y > 164 && y < 180 && but == 1)
	{
		fo->grad[1] = (fo->grad[1] < 1000) ? fo->grad[1] * 10 : 1000;
		menu_grad_trans(fo);
	}
	else
		mouse_hook_6(but, x, y, fo);
}
