/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_toche.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 07:46:43 by apopinea          #+#    #+#             */
/*   Updated: 2016/12/16 07:46:44 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"
#include "lib_fdf.h"

/*
**	<-- ft_affiche_menut -->
**		affiche ou detruit keyboard
*/

void		ft_affiche_menut(t_info *fo)
{
	fo->menut_a = (fo->menut_a == 0) ? 1 : 0;
	if (fo->menut_a == 0)
		mlx_destroy_window(fo->mlx, fo->menut->win);
	if (fo->menut_a == 1)
		ft_menu_touche(fo);
}

/*
**	<-- draw_menu -->
**		couleur de fond du menu
*/

void		draw_menut(t_menu_t *tt)
{
	int i;
	int j;

	i = -1;
	j = tt->win_h * tt->win_l;
	while (++i < j)
	{
		tt->pixel_img[i] = COLOR_M_F;
	}
}

/*
**	<-- ft_init_menut -->
**		creer la struct info du menut
**	ft_error_n -> libft.h
**		affiche message d'erreur, renvoi NULL ou quite le prog
**	mlx_new_image -> mlx.h
**		ceer une nouvelle image
**	mlx_get_data_addr -> mlx
**		transforme en chaine de caraterre l'image et recup info
**	draw_menut -> menu_touche.c
**		couleur de fond du menut
*/

int			ft_init_menut(t_info *fo)
{
	t_menu_t *tt;

	errno = 0;
	if (!(tt = (t_menu_t*)ft_memalloc(sizeof(t_menu_t))))
		return (ft_error_0(5, "erreur ft_init_menu_t 1 : ", errno));
	ft_bzero(tt, sizeof(tt));
	tt->win_l = MENU_T_L;
	tt->win_h = MENU_T_H;
	fo->menut = tt;
	fo->menut->mlx = fo->mlx;
	if (!(fo->menut->img = mlx_new_image(fo->mlx, fo->menut->win_l,
			fo->menut->win_h)))
		ft_error_n(4, "erreur mlx_new_image : ", 0);
	if (!(fo->menut->pixel_img = (int*)mlx_get_data_addr(fo->menut->img,
		&(fo->menut->bpp), &(fo->menut->s_line), &(fo->menut->ed))))
		ft_error_n(4, "erreur mlx_get_data_addr : ", 0);
	draw_menut(fo->menut);
	return (1);
}

/*
**	<-- put_menut -->
**		affiche les touches
**	mlx_put_image_to_window -> mlx.h
**		affiche l'image dans une fenetre
**	mlx_string_put -> mlx.h
**		affiche texte dans une fenetre
**	put_menut_2 -> menu_touche_2.c
**		affiche les touches suite
*/

void		put_menut(t_menu_t *tt)
{
	mlx_put_image_to_window(tt->mlx, tt->win, tt->img, 0, 0);
	mlx_string_put(tt->mlx, tt->win, 30, 10, COLOR_M_T, STR_ROT);
	mlx_string_put(tt->mlx, tt->win, 10, 30, COLOR_B, STR_ROT_X);
	mlx_string_put(tt->mlx, tt->win, 10, 50, COLOR_B, STR_ROT_Y);
	mlx_string_put(tt->mlx, tt->win, 10, 70, COLOR_B, STR_ROT_Z);
	mlx_string_put(tt->mlx, tt->win, 10, 90, COLOR_B, STR_ROT_T);
	mlx_string_put(tt->mlx, tt->win, 30, 130, COLOR_M_T, STR_TRANS);
	mlx_string_put(tt->mlx, tt->win, 10, 150, COLOR_B, STR_TRANS_V);
	mlx_string_put(tt->mlx, tt->win, 10, 170, COLOR_B, STR_TRANS_H);
	mlx_string_put(tt->mlx, tt->win, 30, 210, COLOR_M_T, STR_MULT);
	mlx_string_put(tt->mlx, tt->win, 10, 230, COLOR_B, STR_MULT_X);
	mlx_string_put(tt->mlx, tt->win, 10, 250, COLOR_B, STR_MULT_Y);
	mlx_string_put(tt->mlx, tt->win, 10, 270, COLOR_B, STR_MULT_Z);
	mlx_string_put(tt->mlx, tt->win, 10, 290, COLOR_B, STR_MULT_G);
	mlx_string_put(tt->mlx, tt->win, 30, 330, COLOR_M_T, STR_OUTIL);
	mlx_string_put(tt->mlx, tt->win, 10, 350, COLOR_B, STR_TRANSP);
	mlx_string_put(tt->mlx, tt->win, 10, 370, COLOR_B, STR_CENTRE);
	mlx_string_put(tt->mlx, tt->win, 10, 390, COLOR_B, STR_ESC);
	mlx_string_put(tt->mlx, tt->win, 10, 410, COLOR_B, STR_LZOOM);
	mlx_string_put(tt->mlx, tt->win, 30, 490, COLOR_M_T, STR_CAM);
	mlx_string_put(tt->mlx, tt->win, 10, 510, COLOR_B, STR_CAMX);
	mlx_string_put(tt->mlx, tt->win, 10, 530, COLOR_B, STR_CAMY);
	mlx_string_put(tt->mlx, tt->win, 10, 550, COLOR_B, STR_CAMZ);
	put_menut_2(tt);
}

/*
**	<-- ft_menu -->
**		creer une fenetre et affiche les touches
**	mlx_new_window -> mlx.h
**		creer une fenetre
**	mouse_hook_3 -> menu_touche_2.c
**		enregistre la fermeture de keyboard
**	put_menut -> menu_tpuche.c
**		affiche les touches
*/

void		ft_menu_touche(t_info *fo)
{
	fo->menut->win = mlx_new_window(fo->menut->mlx,
		fo->menut->win_l, fo->menut->win_h, "Keyboard");
	mlx_hook(fo->menut->win, 17, (0L), mouse_hook_3, fo);
	mlx_expose_hook(fo->menut->win, expose_hook_3, fo);
	put_menut(fo->menut);
}
