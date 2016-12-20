/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 07:51:49 by apopinea          #+#    #+#             */
/*   Updated: 2016/12/06 07:51:51 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include "lib_fdf.h"
#include <stdarg.h>
#include <fcntl.h>

#define USAGE "usage : une map .fdf avec en option un fichier paramètre \n"

/*
**	<-- ft_loop -->
**		gére mlx_loop et les evènements
**	mlx_hook -> mlx.h
**		gere les evenements
**	key_hook -> hook_fdf.c
**		action a entreperndre suivant l'evenement
**	mouse_hook -> hook_fdf_2.c
**		enregistre la fermeture de la fenetre principal et quitte le prog
**	mlx_loop -> mlx.h
**		"boucle le programe"
**	mlx_expose_hook -> hook_fdf_2.c
**		gérer l'évènement expose
**
**	//mlx_hook(fo->win, 6, (1L<<6), mouse_hook_2, fo);
**	//mlx_mouse_hook(fo->win, mouse_hook, fo);
*/

static void		ft_loop(t_info *fo)
{
	mlx_hook(fo->win, 2, 3, key_hook, fo);
	mlx_hook(fo->win, 17, (0L), mouse_hook, fo);
	mlx_expose_hook(fo->win, expose_hook, fo);
	mlx_loop(fo->mlx);
}

/*
**	<-- ft_init_info -->
**		creer et initialise la structure contenant toutes les info du prog
**	ft_error_n -> libft.h
**		affiche message d'erreur, renvoi NULL ou quite le prog
**	mlx_init -> mlx.h
**		conection avec le serveur X
**	ft_bzero ->libft.h
**		met toute la memoir a 0
*/

static t_info	*ft_init_info(void)
{
	t_info	*fo;
	void	*mlx;

	errno = 0;
	if (!(fo = (t_info*)ft_memalloc(sizeof(t_info))))
		return (ft_error_n(5, "erreur ft_init_info 1 : ", errno));
	if (!(mlx = mlx_init()))
		ft_error_n(4, "erreur mlx_init : ", 0);
	ft_bzero(fo, sizeof(t_info));
	fo->mlx = mlx;
	fo->col_spe = 1;
	fo->menut_a = 1;
	fo->menu_a = 1;
	fo->f_principal = 1;
	fo->grad[0] = 0.01;
	fo->grad[1] = 10;
	fo->grad[2] = 1;
	fo->grad[3] = 1.1;
	fo->grad[4] = 0.9;
	fo->grad[5] = 1;
	return (fo);
}

/*
**	<-- draw_reload -->
**		creer une nouvelle image, dessine dessus l'affiche et la detruit
**	mlx_new_image -> mlx.h
**		ceer une nouvelle image
**	mlx_get_data_addr -> mlx
**		transforme en chaine de caraterre l'image et recup info
**	ft_error_n -> libft.h
**		affiche message d'erreur, renvoi NULL ou quite le prog
**	draw_map -> draw_map.c
**		dessine la carte dans une image
**	mlx_put_image_to_window -> mlx.h
**		affiche l'image dans une fenetre
**	mlx_destroy_image -> mlx.h
**		detruit l'image
*/

void			draw_reload(t_info *fo)
{
	if (!(fo->img = mlx_new_image(fo->mlx, fo->win_l, fo->win_h)))
		ft_error_n(4, "erreur mlx_new_image : ", 0);
	if (!(fo->pixel_img = (int*)mlx_get_data_addr(fo->img, &(fo->bpp),
			&(fo->s_line), &(fo->ed))))
		ft_error_n(4, "erreur mlx_get_data_addr : ", 0);
	draw_map(fo);
	mlx_put_image_to_window(fo->mlx, fo->win, fo->img, 0, 0);
	mlx_destroy_image(fo->mlx, fo->img);
}

/*
**	<-- main -->
**		Debut prog
**	get_file_param -> get_file_param.c
**		lit le second fichier passer en argument contient les parrametres du
**		prog, renvoi une liste chaine du fichier
**	ft_init_info -> main.c
**		creer et initialise la structure contenant toutes les info du prog
**	ft_block_prepa_map -> ft_block_prepa_map.c
**		initialise et lance pour la premiere fois tous les actions.
**	mlx_new_window -> mlx.h
**		creer une fenetre
**	draw_reload -> main.c
**		creer la carte et l'affiche
**	ft_init_menut -> menu_touche.c
**		creer la struce info du menu touche
**	ft_menu_touche -> menu_touche.c
**		creer une fenetre et affiche les touche
**	ft_init_menu -> menu.c
**		creer la struct info du menu
**	ft_menu -> menu.c
**		creer une fenetre et affiche les infos
**	ft_loop -> main.c
**		gere mlx_loop et les evènements
*/

int				main(int argc, char **argv)
{
	t_info	*fo;
	t_list	*beg_p;

	if (argc != 2 && argc != 3)
		ft_putendl(USAGE);
	beg_p = NULL;
	if (argc == 3)
		beg_p = get_file_param(argv[2]);
	if (argc == 2 || argc == 3)
	{
		fo = ft_init_info();
		ft_block_prepa_map(argv[1], fo, beg_p);
		fo->win = mlx_new_window(fo->mlx, fo->win_l, fo->win_h, argv[1]);
		draw_reload(fo);
		if (ft_init_menut(fo))
			ft_menu_touche(fo);
		if (ft_init_menu(fo))
			ft_menu(fo);
		ft_loop(fo);
	}
	return (0);
}
