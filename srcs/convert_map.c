/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 14:04:57 by apopinea          #+#    #+#             */
/*   Updated: 2016/11/28 14:04:58 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lib_fdf.h"

/*
**	<-- ft_get_color -->
**		associ un point a une couleur
*/

static int	ft_get_color_p(double z, t_info *fo)
{
	int i;

	i = fo->nb_col;
	while (--i >= 0)
		if (z <= (fo->col)[i][1])
			return (i);
	return (0);
}

/*
**	<-- ft_regist_grid -->
**		convert fichier .fdf en grid de t_point
**	ft_atoi_next -> libft
**		atoi a partir de l'indice i
**	ft_get_color -> convert_map.c
**		associ un point a une couleur
*/

static void	ft_regist_grid(t_info *fo, t_list *map0)
{
	int		x;
	int		y;
	int		i;
	double	center[2];

	y = 0;
	center[0] = ((double)fo->h - 1) / 2;
	center[1] = ((double)fo->l - 1) / 2;
	while (map0)
	{
		x = 0;
		i = 0;
		while (((char*)map0->content)[0] && x < fo->l)
		{
			(fo->grid)[y][x].x = (x - center[1]);
			(fo->grid)[y][x].y = (y - center[0]);
			(fo->grid)[y][x].z = (ft_atoi_next(((map0->content)), &i));
			(fo->grid)[y][x].color = ft_get_color_p((fo->grid)[y][x].z, fo);
			++x;
		}
		map0 = map0->next;
		++y;
	}
}

/*
** 	<-- ft_init_grid -->
**		alloc grid double tableau de t_point
**	ft_error_n -> libft
**		affiche message d'erreur, renvoi NULL ou quite le prog
*/

static void	ft_init_grid(t_info *fo)
{
	int		y;

	errno = 0;
	if (!(fo->grid = (t_point**)ft_memalloc(sizeof(t_point*) * fo->h)))
		ft_error_n(5, "erreur ft_init_grid 1 : ", errno);
	y = 0;
	while (y < fo->h)
	{
		if (!((fo->grid)[y] = (t_point*)ft_memalloc(sizeof(t_point) * fo->l)))
			ft_error_n(5, "erreur ft_init_grid 2 : ", errno);
		++y;
	}
}

/*
**	<-- ft_convert_map -->
**		converti le fichier recue en double tableau de points
**	ft_init_grid -> convert_map.c
**		alloc grid
**	ft_regist_grid -> convert_map.c
**		convert fichier .fdf en grid de t_point
**	ft_extrem_map -> convert_map_2.c
**		enregistre les valeur les plus grande de x,y,z etverif taille win
**	ft_init_horizon -> convert_map_2.c
**		garde les 4 coin de la map a z = 0 pour utilisation ulterieur
*/

void		ft_convert_map(t_list *map0, t_info *fo)
{
	ft_init_grid(fo);
	ft_regist_grid(fo, map0);
	ft_extrem_map(fo);
	ft_init_horizon(fo);
}
