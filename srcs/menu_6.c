/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/17 11:57:45 by apopinea          #+#    #+#             */
/*   Updated: 2016/12/17 11:57:47 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lib_fdf.h"
#include "mlx.h"

/*
** 	<-- menu_mult_g -->
**		affiche multiplicateur sur x, y et z
**	mlx_put_image_to_window -> mlx.h
**		affiche l'image dans une fenetre
**	mlx_string_put -> mlx.h
**		affiche texte dans une fenetre
*/

void		menu_mult_g(t_info *fo)
{
	menu_mult_x(fo);
	menu_mult_y(fo);
	menu_mult_z(fo);
}

/*
**	<-- ft_affiche_menut -->
**		affiche ou detruit keyboard
*/

void		ft_affiche_menu(t_info *fo)
{
	fo->menu_a = (fo->menu_a == 0) ? 1 : 0;
	if (fo->menu_a == 0)
		mlx_destroy_window(fo->mlx, fo->menu->win);
	if (fo->menu_a == 1)
		ft_menu(fo);
}

/*
**	<-- mouse_hook_2 -->
**		enregistre la fermeture de keyboard
*/

int			mouse_hook_2(t_info *fo)
{
	fo->menu_a = 0;
	return (1);
}

/*
**	<-- mlx_expose_hook_2 -->
**		gérer l'évènement expose pour menu
**	draw__init_menu -> menu.c
**		couleur de fond du menu
**	put_menut -> menu_2.c
**		affiche les infos
*/

int			expose_hook_2(t_info *fo)
{
	if (fo->menu_a == 1)
	{
		draw_init_menu(fo->menu);
		put_menu(fo);
	}
	return (1);
}

/*
**	<-- mouse_hook_4 -->
**		evenement souris
**	draw_reload -> main.c
**		creer la carte et l'affiche
**	mouse_hook_5 -> menu_9.c
**		evenement souris
*/

int			mouse_hook_4(int but, int x, int y, t_info *fo)
{
	t_pt_ft	*t2;
	int		i;

	if (x > 174 && x < 191 && y > 574 && y < 591 && but == 1)
	{
		i = -1;
		while (++i < 3)
		{
			fo->mult[i] = 1;
			fo->rot[i] = 0;
			fo->center[i] = 0;
		}
		fo->trans[0] = 0;
		fo->trans[1] = 0;
		fo->transparence = 0;
		fo->l_zoom = 0;
		draw_reload(fo);
		t2 = (t_pt_ft*)fo->menu->tab;
		i = -1;
		while (t2[++i].pt)
			(*(t2[i].pt))(fo);
	}
	else
		mouse_hook_5(but, x, y, fo);
	return (1);
}
