/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 13:21:42 by apopinea          #+#    #+#             */
/*   Updated: 2016/12/16 13:21:43 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"
#include "lib_fdf.h"
#include <stdlib.h>

/*
**	<-- init_tab_f_menu -->
**		init tab ptrf
**	ft_error_0 -> libft.h
**		affiche message d'erreur, renvoi 0 ou quite le prog
**	init_tab_f_menu_2 -> menu_2.c
**		suite
*/

static void		init_tab_f_menu(t_menu *tt)
{
	t_pt_ft	*t2;

	errno = 0;
	if (!(t2 = (t_pt_ft*)ft_memalloc(sizeof(t_pt_ft) * 35)))
		ft_error_0(5, "erreur ft_init_tab_f_menu 1 : ", errno);
	t2[0].pt = &menu_rot_x;
	t2[0].key = KEY_ROT_XP;
	t2[1].pt = &menu_rot_x;
	t2[1].key = KEY_ROT_XN;
	t2[2].pt = &menu_rot_y;
	t2[2].key = KEY_ROT_YP;
	t2[3].pt = &menu_rot_y;
	t2[3].key = KEY_ROT_YN;
	t2[4].pt = &menu_rot_z;
	t2[4].key = KEY_ROT_ZP;
	t2[5].pt = &menu_rot_z;
	t2[5].key = KEY_ROT_ZN;
	t2[6].pt = &menu_rot_type;
	t2[6].key = KEY_ROT_TYPE;
	t2[7].pt = &menu_tran_h;
	t2[7].key = KEY_TRANS_DROITE;
	t2[8].pt = &menu_tran_h;
	t2[8].key = KEY_TRANS_GAUCHE;
	tt->tab = (void*)t2;
	init_tab_f_menu_2(tt);
}

/*
**	<-- draw__init_menu -->
**		couleur de fond du menu
**	draw__init_menu -> menu_7.c
**		dessine bouton
*/

void			draw_init_menu(t_menu *tt)
{
	int i;
	int j;

	i = -1;
	j = tt->win_h * tt->win_l;
	while (++i < j)
		tt->pixel_img[i] = COLOR_M_F;
	i = -1;
	j = 22 * 120;
	while (++i < j)
		tt->pixel_img2[i] = COLOR_M_F;
	draw_init_menu_2(tt);
}

/*
**	<-- ft_init_menu -->
**		creer la struct info du menu
**	ft_error_n -> libft.h
**		affiche message d'erreur, renvoi NULL ou quite le prog
**	mlx_new_image -> mlx.h
**		ceer une nouvelle image
**	mlx_get_data_addr -> mlx
**		transforme en chaine de caraterre l'image et recup info
**	ft_init_2 -> menu_7.c
**		creer les autres images
**	draw__init_menu -> menu.c
**		couleur de fond du menu et dessine bouton
**	init_tab_f_menu -> menu.c
**		init tab ptrf
*/

int				ft_init_menu(t_info *fo)
{
	t_menu *tt;

	errno = 0;
	if (!(tt = (t_menu*)ft_memalloc(sizeof(t_menu))))
		return (ft_error_0(5, "erreur ft_init_menu 1 : ", errno));
	ft_bzero(tt, sizeof(tt));
	tt->win_l = MENU_L;
	tt->win_h = MENU_H;
	fo->menu = tt;
	fo->menu->mlx = fo->mlx;
	if (!(fo->menu->img = mlx_new_image(fo->mlx, fo->menu->win_l,
			fo->menu->win_h)))
		ft_error_n(4, "erreur mlx_new_image : ", 0);
	if (!(fo->menu->pixel_img = (int*)mlx_get_data_addr(fo->menu->img,
		&(fo->menu->bpp), &(fo->menu->s_line), &(fo->menu->ed))))
		ft_error_n(4, "erreur mlx_get_data_addr : ", 0);
	if (!(fo->menu->img2 = mlx_new_image(fo->mlx, 120, 22)))
		ft_error_n(4, "erreur mlx_new_image : ", 0);
	if (!(fo->menu->pixel_img2 = (int*)mlx_get_data_addr(fo->menu->img2,
		&(fo->menu->bpp2), &(fo->menu->s_line2), &(fo->menu->ed2))))
		ft_error_n(4, "erreur mlx_get_data_addr : ", 0);
	ft_init_menu_2(tt);
	draw_init_menu(fo->menu);
	init_tab_f_menu(tt);
	return (1);
}

/*
**	<-- ft_menu -->
**		creer une fenetre et affiche les infos
**	mlx_new_window -> mlx.h
**		creer une fenetre
**	mouse_hook_2 -> menu_6.c
**		enregistre la fermeture du menu
**	mouse_hook_4 -> menu_6.c
**		evenement souris
**	mlx_expose_hook_2 -> menu_6.c
**		gérer l'évènement expose pour menu
**	put_menut -> menu_2.c
**		affiche les infos
*/

void			ft_menu(t_info *fo)
{
	fo->menu->win = mlx_new_window(fo->menu->mlx,
		fo->menu->win_l, fo->menu->win_h, "Menu");
	mlx_hook(fo->menu->win, 17, (0L), mouse_hook_2, fo);
	mlx_expose_hook(fo->menu->win, expose_hook_2, fo);
	mlx_mouse_hook(fo->menu->win, mouse_hook_4, fo);
	put_menu(fo);
}
