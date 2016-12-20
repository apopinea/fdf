/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_7.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 14:41:13 by apopinea          #+#    #+#             */
/*   Updated: 2016/12/18 14:41:15 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"
#include "lib_fdf.h"

/*
**	ft_init_2 -> menu_7.c
**		creer les autres images
**	ft_error_n -> libft.h
**		affiche message d'erreur, renvoi NULL ou quite le prog
**	mlx_new_image -> mlx.h
**		ceer une nouvelle image
**	mlx_get_data_addr -> mlx
**		transforme en chaine de caraterre l'image et recup info
*/

void			ft_init_menu_2(t_menu *tt)
{
	if (!(tt->img3 = mlx_new_image(tt->mlx, 15, 15)))
		ft_error_n(4, "erreur mlx_new_image : ", 0);
	if (!(tt->pixel_img3 = (int*)mlx_get_data_addr(tt->img3,
		&(tt->bpp3), &(tt->s_line3), &(tt->ed3))))
		ft_error_n(4, "erreur mlx_get_data_addr : ", 0);
	if (!(tt->img4 = mlx_new_image(tt->mlx, 15, 15)))
		ft_error_n(4, "erreur mlx_new_image : ", 0);
	if (!(tt->pixel_img4 = (int*)mlx_get_data_addr(tt->img4,
		&(tt->bpp4), &(tt->s_line4), &(tt->ed4))))
		ft_error_n(4, "erreur mlx_get_data_addr : ", 0);
	if (!(tt->img5 = mlx_new_image(tt->mlx, 13, 13)))
		ft_error_n(4, "erreur mlx_new_image : ", 0);
	if (!(tt->pixel_img5 = (int*)mlx_get_data_addr(tt->img5,
		&(tt->bpp5), &(tt->s_line5), &(tt->ed5))))
		ft_error_n(4, "erreur mlx_get_data_addr : ", 0);
}

/*
**	<-- draw_init_menu_3 -->
**		dessine bouton suite
*/

static void		draw_init_menu_3(t_menu *tt, int i)
{
	while (++i < 225)
	{
		tt->pixel_img4[i] = COLOR_M_F;
		tt->pixel_img3[i] = COLOR_M_F;
	}
	i = -1;
	while (++i < 15)
	{
		tt->pixel_img4[i] = COLOR_B;
		tt->pixel_img4[i + 15 * 14] = COLOR_B;
		tt->pixel_img4[i * 15] = COLOR_B;
		tt->pixel_img4[(i + 1) * 15 - 1] = COLOR_B;
		tt->pixel_img3[i] = COLOR_B;
		tt->pixel_img3[i + 15 * 14] = COLOR_B;
		tt->pixel_img3[i * 15] = COLOR_B;
		tt->pixel_img3[(i + 1) * 15 - 1] = COLOR_B;
	}
}

/*
**	<-- draw_init_menu_4 -->
**		dessine bouton suite
*/

static void		draw_init_menu_4(t_menu *tt, int i)
{
	while (++i < 11)
	{
		tt->pixel_img4[i + 32] = COLOR_B;
		tt->pixel_img4[i + 2 + 15 * 12] = COLOR_B;
		tt->pixel_img4[32 + i * 15] = COLOR_B;
		tt->pixel_img4[(i + 3) * 15 - 3] = COLOR_B;
		tt->pixel_img3[i + 32] = COLOR_B;
		tt->pixel_img3[i + 2 + 15 * 12] = COLOR_B;
		tt->pixel_img3[32 + i * 15] = COLOR_B;
		tt->pixel_img3[(i + 3) * 15 - 3] = COLOR_B;
	}
	i = -1;
	while (++i < 7)
	{
		tt->pixel_img3[7 + 15 * (i + 4)] = COLOR_GREEN;
		tt->pixel_img3[7 * 15 + 4 + i] = COLOR_GREEN;
		tt->pixel_img4[7 * 15 + 4 + i] = COLOR_RED;
	}
}

/*
**	<-- draw_init_menu_2 -->
**		dessine bouton
**	draw_init_menu_3 -> menu_7.c
**		dessine boutons suite
**	draw_init_menu_4 -> menu_7.c
**		dessine boutons suite
*/

void			draw_init_menu_2(t_menu *tt)
{
	int i;

	i = -1;
	while (++i < 169)
	{
		tt->pixel_img5[i] = COLOR_M_F;
	}
	i = -1;
	while (++i < 13)
	{
		tt->pixel_img5[i] = COLOR_B;
		tt->pixel_img5[i + 13 * 12] = COLOR_B;
		tt->pixel_img5[i * 13] = COLOR_B;
		tt->pixel_img5[(i + 1) * 13 - 1] = COLOR_B;
	}
	i = -1;
	while (++i < 9)
	{
		tt->pixel_img5[i + 28] = COLOR_B;
		tt->pixel_img5[i + 2 + 13 * 10] = COLOR_B;
		tt->pixel_img5[28 + i * 13] = COLOR_B;
		tt->pixel_img5[(i + 3) * 13 - 3] = COLOR_B;
	}
	draw_init_menu_3(tt, -1);
	draw_init_menu_4(tt, -1);
}

/*
**	<-- put_menu_3 -->
**		affiche les infos suite
**	mlx_put_image_to_window -> mlx.h
**		affiche l'image dans une fenetre
*/

void			put_menu_3(t_info *fo)
{
	mlx_put_image_to_window(fo->mlx, fo->menu->win, fo->menu->img5, 175, 575);
	mlx_put_image_to_window(fo->mlx, fo->menu->win, fo->menu->img4, 95, 34);
	mlx_put_image_to_window(fo->mlx, fo->menu->win, fo->menu->img3, 75, 34);
	mlx_put_image_to_window(fo->mlx, fo->menu->win, fo->menu->img4, 95, 165);
	mlx_put_image_to_window(fo->mlx, fo->menu->win, fo->menu->img3, 75, 165);
	mlx_put_image_to_window(fo->mlx, fo->menu->win, fo->menu->img4, 95, 265);
	mlx_put_image_to_window(fo->mlx, fo->menu->win, fo->menu->img3, 75, 265);
	mlx_put_image_to_window(fo->mlx, fo->menu->win, fo->menu->img4, 95, 285);
	mlx_put_image_to_window(fo->mlx, fo->menu->win, fo->menu->img3, 75, 285);
	mlx_put_image_to_window(fo->mlx, fo->menu->win, fo->menu->img4, 95, 395);
	mlx_put_image_to_window(fo->mlx, fo->menu->win, fo->menu->img3, 75, 395);
}
