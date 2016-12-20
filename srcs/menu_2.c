/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 16:22:46 by apopinea          #+#    #+#             */
/*   Updated: 2016/12/16 16:22:48 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"
#include "lib_fdf.h"
#include <stdlib.h>

/*
**	<-- init_tab_f_menu_3 -->
**		init tab ptrf
**	ft_error_0 -> libft.h
**		affiche message d'erreur, renvoi 0 ou quite le prog
**	init_tab_f_menu_4 -> menu_8.c
**		suite
*/

static void	init_tab_f_menu_3(t_menu *tt)
{
	t_pt_ft	*t2;

	t2 = (t_pt_ft*)tt->tab;
	t2[19].key = T1;
	t2[20].pt = &menu_cam_y;
	t2[20].key = T2;
	t2[21].pt = &menu_cam_z;
	t2[21].key = T5;
	t2[22].pt = &menu_cam_z;
	t2[22].key = T6;
	t2[23].pt = &menu_transparence;
	t2[23].key = KEY_TRAN;
	t2[24].pt = &menu_centrage;
	t2[24].key = KEY_CENTRE;
	t2[25].pt = &menu_lzoom;
	t2[25].key = KEY_LZOOM_P;
	t2[26].pt = &menu_lzoom;
	t2[26].key = KEY_LZOOM_N;
	t2[27].pt = &menu_mult_g;
	t2[27].key = KEY_XYZ_MULT_P;
	t2[28].pt = &menu_mult_g;
	t2[28].key = KEY_XYZ_MULT_N;
	t2[29].pt = &menu_grad_rot;
	t2[29].key = -1;
	init_tab_f_menu_4(tt);
}

/*
**	<-- init_tab_f_menu_2 -->
**		init tab ptrf
**	ft_error_0 -> libft.h
**		affiche message d'erreur, renvoi 0 ou quite le prog
**	init_tab_f_menu_3 -> menu_2.c
**		suite
*/

void		init_tab_f_menu_2(t_menu *tt)
{
	t_pt_ft	*t2;

	t2 = (t_pt_ft*)tt->tab;
	t2[9].pt = &menu_tran_v;
	t2[9].key = KEY_TRANS_HAUT;
	t2[10].pt = &menu_tran_v;
	t2[10].key = KEY_TRANS_BAS;
	t2[11].pt = &menu_mult_x;
	t2[11].key = KEY_X_MULT_P;
	t2[12].pt = &menu_mult_x;
	t2[12].key = KEY_X_MULT_N;
	t2[13].pt = &menu_mult_y;
	t2[13].key = KEY_Y_MULT_P;
	t2[14].pt = &menu_mult_y;
	t2[14].key = KEY_Y_MULT_N;
	t2[15].pt = &menu_mult_z;
	t2[15].key = KEY_Z_MULT_P;
	t2[16].pt = &menu_mult_z;
	t2[16].key = KEY_Z_MULT_N;
	t2[17].pt = &menu_cam_x;
	t2[17].key = T3;
	t2[18].pt = &menu_cam_x;
	t2[18].key = T4;
	t2[19].pt = &menu_cam_y;
	init_tab_f_menu_3(tt);
}

/*
**	<-- put_menu_2 -->
**		affiche les infos suite
**	mlx_put_image_to_window -> mlx.h
**		affiche l'image dans une fenetre
**	mlx_string_put -> mlx.h
**		affiche texte dans une fenetre
*/

static void	put_menu_2(t_info *fo)
{
	t_pt_ft	*t2;

	t2 = (t_pt_ft*)fo->menu->tab;
	mlx_put_image_to_window(fo->mlx, fo->menu->win, fo->menu->img, 0, 0);
	mlx_string_put(fo->mlx, fo->menu->win, 30, 10, COLOR_M_T, STR_ROT2);
	mlx_string_put(fo->mlx, fo->menu->win, 10, 50, COLOR_M_T, T_ROT_X);
	mlx_string_put(fo->mlx, fo->menu->win, 10, 70, COLOR_M_T, T_ROT_Y);
	mlx_string_put(fo->mlx, fo->menu->win, 10, 90, COLOR_M_T, T_ROT_Z);
	mlx_string_put(fo->mlx, fo->menu->win, 10, 110, COLOR_M_T, T_ROT_T);
	mlx_string_put(fo->mlx, fo->menu->win, 30, 140, COLOR_M_T, STR_TRANS);
	mlx_string_put(fo->mlx, fo->menu->win, 10, 180, COLOR_M_T, T_TRANH);
	mlx_string_put(fo->mlx, fo->menu->win, 10, 200, COLOR_M_T, T_TRANV);
	mlx_string_put(fo->mlx, fo->menu->win, 30, 240, COLOR_M_T, STR_MULT);
}

/*
**	<-- put_menu -->
**		affiche les infos
**	put_menu_2 -> menu_2.c
**		affiche les infos suite
**	put_menu_3 -> menu_7.c
**		affiche les infos suite
**	mlx_string_put -> mlx.h
**		affiche texte dans une fenetre
*/

void		put_menu(t_info *fo)
{
	t_pt_ft	*t2;
	int		i;

	t2 = (t_pt_ft*)fo->menu->tab;
	put_menu_2(fo);
	put_menu_3(fo);
	mlx_string_put(fo->mlx, fo->menu->win, 10, 300, COLOR_M_T, T_MULTX);
	mlx_string_put(fo->mlx, fo->menu->win, 10, 320, COLOR_M_T, T_MULTY);
	mlx_string_put(fo->mlx, fo->menu->win, 10, 340, COLOR_M_T, T_MULTZ);
	mlx_string_put(fo->mlx, fo->menu->win, 30, 370, COLOR_M_T, STR_CAM);
	mlx_string_put(fo->mlx, fo->menu->win, 10, 410, COLOR_M_T, T_CAM_X);
	mlx_string_put(fo->mlx, fo->menu->win, 10, 430, COLOR_M_T, T_CAM_Y);
	mlx_string_put(fo->mlx, fo->menu->win, 10, 450, COLOR_M_T, T_CAM_Z);
	mlx_string_put(fo->mlx, fo->menu->win, 30, 480, COLOR_M_T, STR_OUTIL);
	mlx_string_put(fo->mlx, fo->menu->win, 10, 500, COLOR_M_T, T_TRANSP);
	mlx_string_put(fo->mlx, fo->menu->win, 10, 520, COLOR_M_T, T_CENTRE);
	mlx_string_put(fo->mlx, fo->menu->win, 10, 540, COLOR_M_T, T_LZOOM);
	mlx_string_put(fo->mlx, fo->menu->win, 10, 570, COLOR_M_T, T_RE_INIT);
	i = -1;
	while (t2[++i].pt)
		(*(t2[i].pt))(fo);
}

/*
** 	<-- key_hook_menu -->
**		liste des touche evenement clavier dans fenetre principal
**		effet sur menu, rafraichi l'infos
**		liste des fonctions:
**			--> menu_3.c
**			à
**			--> menu_9.c
*/

void		key_hook_menu(int key, t_info *fo)
{
	int		i;
	t_pt_ft	*t2;

	if (fo->menu_a == 1)
	{
		t2 = (t_pt_ft*)fo->menu->tab;
		i = -1;
		while (t2[++i].pt)
		{
			if (t2[i].key == key)
			{
				(*(t2[i].pt))(fo);
				break ;
			}
		}
	}
}
