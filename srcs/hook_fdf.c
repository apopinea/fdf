/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_fdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 07:49:00 by apopinea          #+#    #+#             */
/*   Updated: 2016/12/11 07:49:02 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft.h"
#include "lib_fdf.h"
#include <stdlib.h>

/*
** 	<-- key_hook_plus -->
**		liste des touche evenement clavier outil et le reste
** 	key_hook_mlt -> hook_fdf_2.c
**		liste des touche evenement clavier multiplicateur distance et le reste
**	ft_affiche_menut -> menu_touche.c
**		affiche ou detruit keyboard
**	ft_affiche_menut -> menu_6.c
**		affiche ou detruit menu
*/

static void			key_hook_plus(int keycode, t_info *fo)
{
	if (keycode == KEY_LZOOM_P)
		fo->l_zoom += 10.0;
	else if (keycode == KEY_LZOOM_N)
		fo->l_zoom -= 10.0;
	else if (keycode == KEY_TRAN)
		fo->transparence = (fo->transparence == 1) ? 0 : 1;
	else if (keycode == KEY_CENTRE)
		fo->centrage = (fo->centrage == 1) ? 0 : 1;
	else if (keycode == KEY_ROT_TYPE)
		fo->rot_type = (fo->rot_type == 1) ? 0 : 1;
	else if (keycode == KEY_A_MENU_T)
		ft_affiche_menut(fo);
	else if (keycode == KEY_A_MENU)
		ft_affiche_menu(fo);
	else
		key_hook_mlt(keycode, fo);
}

/*
** 	<-- key_hook_cam -->
**		liste des touche evenement clavier deplacement cam et le reste
** 	key_hook_plus -> hook_fdf.c
**		liste des touche evenement clavier outil et le reste
*/

static void			key_hook_cam(int keycode, t_info *fo)
{
	if (keycode == T1)
		fo->center[1] += fo->grad[5];
	else if (keycode == T2)
		fo->center[1] -= fo->grad[5];
	else if (keycode == T3)
		fo->center[0] += fo->grad[5];
	else if (keycode == T4)
		fo->center[0] -= fo->grad[5];
	else if (keycode == T5)
		fo->center[2] += fo->grad[5];
	else if (keycode == T6)
		fo->center[2] -= fo->grad[5];
	else
		key_hook_plus(keycode, fo);
}

/*
** 	<-- key_hook_rotation -->
**		liste des touche evenement clavier rotation et le reste
** 	key_hook_cam -> hook_fdf.c
**		liste des touche evenement clavier deplacement cam et le reste
*/

static void			key_hook_rotation(int keycode, t_info *fo)
{
	if (keycode == KEY_ROT_XP)
		fo->rot[0] += fo->grad[0] * PI;
	else if (keycode == KEY_ROT_XN)
		fo->rot[0] -= fo->grad[0] * PI;
	else if (keycode == KEY_ROT_YP)
		fo->rot[1] += fo->grad[0] * PI;
	else if (keycode == KEY_ROT_YN)
		fo->rot[1] -= fo->grad[0] * PI;
	else if (keycode == KEY_ROT_ZP)
		fo->rot[2] += fo->grad[0] * PI;
	else if (keycode == KEY_ROT_ZN)
		fo->rot[2] -= fo->grad[0] * PI;
	else
		key_hook_cam(keycode, fo);
}

/*
** 	<-- key_hook_translation -->
**		liste des touche evenement clavier translation et le reste
** 	key_hook_rotation -> hook_fdf.c
**		liste des touche evenement clavier rotation et le reste
*/

static void			key_hook_translation(int keycode, t_info *fo)
{
	if (keycode == KEY_TRANS_DROITE)
		fo->trans[0] += fo->grad[1];
	else if (keycode == KEY_TRANS_GAUCHE)
		fo->trans[0] -= fo->grad[1];
	else if (keycode == KEY_TRANS_HAUT)
		fo->trans[1] -= fo->grad[1];
	else if (keycode == KEY_TRANS_BAS)
		fo->trans[1] += fo->grad[1];
	else
		key_hook_rotation(keycode, fo);
}

/*
**	<-- key_hook -->
**		gere les evenement clavier
**	mlx_destroy_window ->mlx.h
**		detruit la fenetre
**	ft_exit_fdf -> exit_fdf.c
**		libere la memoire et quite le prog
** 	key_hook_translation -> hook_fdf.c
**		liste des touche evenement clavier translation et le reste
** 	key_hook_menu -> menu_2.c
**		liste des touche evenement clavier dans fenetre principal
**		effet sur menu
**	draw_reload -> main.c
**		creer la carte et l'affiche
*/

int					key_hook(int keycode, t_info *fo)
{
	if (keycode == KEY_ESC)
		ft_exit_fdf(fo);
	key_hook_translation(keycode, fo);
	if (fo->menu_a == 1)
		key_hook_menu(keycode, fo);
	draw_reload(fo);
	return (0);
}
