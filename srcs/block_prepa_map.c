/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_prepa_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 12:51:33 by apopinea          #+#    #+#             */
/*   Updated: 2016/12/01 12:51:35 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lib_fdf.h"
#include <stdlib.h>

/*
** 	<-- init_pixel -->
**		creer le double tableau contenant les points poixels
**	ft_error_n -> libft
**		affiche message d'erreur, renvoi NULL ou quite le prog
*/

static void		init_pixel(t_info *fo)
{
	int		y;
	int		x;

	errno = 0;
	if (!(fo->ecran = (t_pixel**)ft_memalloc(sizeof(t_pixel*) * fo->h)))
		ft_error_n(5, "erreur ft_init_projct 1 : ", errno);
	y = 0;
	while (y < fo->h)
	{
		if (!((fo->ecran)[y] = (t_pixel*)ft_memalloc(sizeof(t_pixel) * fo->l)))
			ft_error_n(5, "erreur ft_init_projct 2 : ", errno);
		x = 0;
		while (x < fo->l)
		{
			(fo->ecran)[y][x].color = (fo->grid)[y][x].color;
			++x;
		}
		++y;
	}
}

/*
**	<-- init_matrice_rotation_zoom -->
**		creer les differente matrice utilisé par la suite
**	ft_error_n -> libft
**		affiche message d'erreur, renvoi NULL ou quite le prog
**	ft_vide_matrix -> libft
**		creer une matrice vide
*/

static void		init_matrice_rotation_zoom(t_info *fo)
{
	if (!(fo->rot_x = ft_vid_matrix(3, 3)))
		ft_error_n(4, "init_matrice_rotation_x", 0);
	if (!(fo->rot_y = ft_vid_matrix(3, 3)))
		ft_error_n(4, "init_matrice_rotation_y", 0);
	if (!(fo->rot_z = ft_vid_matrix(3, 3)))
		ft_error_n(4, "init_matrice_rotation_z", 0);
	if (!(fo->rot_zoom = ft_vid_matrix(3, 3)))
		ft_error_n(4, "init_matrice_rotation_zoom", 0);
	if (!(fo->final = ft_vid_matrix(3, 3)))
		ft_error_n(4, "init_matrice_final", 0);
}

/*
** 	<-- ft_init_nb_z_2 -->
**		suite de la fonction ft_init_nb_z coupe a cause de la norme
**	ft_error_n -> libft
**		affiche message d'erreur, renvoi NULL ou quite le prog
*/

static int		*ft_init_nb_z_2(t_info *fo, int x, int y, int *tab)
{
	int i;
	int ok;

	i = -1;
	ok = 0;
	while (++i < fo->nbz)
		if (tab[i] == fo->grid[y][x].z)
			ok = 1;
	if (ok == 0)
	{
		tab[fo->nbz] = fo->grid[y][x].z;
		++(fo->nbz);
		if (!(fo->nbz % 10))
			if (!(tab = (int*)ft_rememalloc(tab, sizeof(int) * fo->nbz,
					sizeof(int) * (fo->nbz + 10))))
				ft_error_n(4, "erreur ft_init_nb_z 2 : ", 0);
	}
	return (tab);
}

/*
**	<-- ft_init_nb_z -->
**		compte le nombre de z different dans la map
**	ft_error_n -> libft
**		affiche message d'erreur, renvoi NULL ou quite le prog
** 	ft_init_nb_z_2 -> block_prepa_map.c
**		suite de la fonction ft_init_nb_z coupe a cause de la norme
*/

static void		ft_init_nb_z(t_info *fo)
{
	int x;
	int y;
	int *tab;

	fo->nbz = 1;
	y = -1;
	errno = 0;
	if (!(tab = (int*)ft_memalloc(sizeof(int) * 10)))
		ft_error_n(5, "erreur ft_init_nb_z : ", errno);
	tab[0] = fo->grid[0][0].z;
	while (++y < fo->h)
	{
		x = -1;
		while (++x < fo->l)
		{
			tab = ft_init_nb_z_2(fo, x, y, tab);
		}
	}
	fo->t_nbz = tab;
}

/*
**	<-- ft_block_prepa_map -->
**		initialise les parametre et prepare les actions futur
**	ft_register_map -> get_map.c
**		lit un fichier .fdf et le recupere sous forme de liste chainé,
**		enregistre egalement la taille de la map
**	ft_sucess -> libft
**		affiche un message
**	init_param -> init_param.c
**		initialise les parametre du programe
**	ft_lstdel -> libft
**		suprime liste chainé
**	ft_convert_map -> convert_map.c
**		transforme la liste chainé sur le fichier .fdf en un double tableau
**		de structure contenant x,y,z et color.
**	init_matrice_rotation_zoom -> block_prepa_map.c
**		creer les matrices de zoom et de translation
**	init_pixel -> block_prepa_map.c
**		ceer un double tableau pour enregistrer la position des points
**		de la map apres la projection
**	ft_init_nb_z -> block_prepa_map.c
**		calcul le nombre de palier different dans la map
**	ft_init_p_col  -> block_prepa_map_2.c
**		init le tableau a degrader de couleur pour une droite
**	ft_affiche_nbz  -> block_prepa_map_2.c
**		affiche liste des z.
*/

void			ft_block_prepa_map(char *file, t_info *fo, t_list *beg_p)
{
	t_list	*map0;

	map0 = ft_register_map(file, fo);
	ft_success("register map");
	init_param(beg_p, fo);
	ft_lstdel(&beg_p);
	ft_convert_map(map0, fo);
	ft_success("convert map");
	ft_lstdel(&map0);
	init_matrice_rotation_zoom(fo);
	ft_success("init rottation");
	init_pixel(fo);
	ft_success("init grid_pixel");
	ft_init_nb_z(fo);
	ft_success("init nb_z");
	ft_init_p_col(fo);
	ft_success("init p_col");
	ft_putstr("Liste des differents z :");
	ft_affiche_nbz(fo);
}
