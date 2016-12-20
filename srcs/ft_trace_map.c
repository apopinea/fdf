/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trace_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 10:59:23 by apopinea          #+#    #+#             */
/*   Updated: 2016/11/24 11:01:14 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "mlx.h"
#include "lib_fdf.h"
#include <unistd.h>
#include <stdlib.h>

/*
**	<-- ft_trace_map_2 -->
**		trace la carte transparence activé selon certain ordre
** 	ft_trace_losange -> ft_trace_map_3.c
**		trace un quadrilatere
*/

void		ft_trace_map_2(t_info *fo, int nb)
{
	int x;
	int y;
	int t[2];

	t[0] = (nb == 4 || nb == 3) ? -1 : 1;
	t[1] = (nb == 2 || nb == 3) ? -1 : 1;
	y = (nb == 4 || nb == 3) ? fo->h - 1 : 0;
	x = (nb == 2 || nb == 3) ? fo->l - 1 : 0;
	while (y < fo->h && y > -1)
	{
		x = (nb == 2 || nb == 3) ? fo->l - 1 : 0;
		while (x < fo->l && x > -1)
		{
			if (x + t[1] < fo->l && x + t[1] > -1 && y + t[0] < fo->h &&
					y + t[0] > -1)
				ft_trace_losange(fo, x, y, t);
			x = (nb == 2 || nb == 3) ? x - 1 : x + 1;
		}
		y = (nb == 4 || nb == 3) ? y - 1 : y + 1;
	}
}

/*
**	<-- ft_trace_map_3 -->
**		trace la carte transparence activé selon certain ordre
** 	ft_trace_losange -> ft_trace_map_3.c
**		trace un quadrilatere
*/

static void	ft_trace_map_3(t_info *fo, int nb)
{
	int x;
	int y;
	int t[2];

	t[0] = (nb == 4 || nb == 3) ? -1 : 1;
	t[1] = (nb == 2 || nb == 3) ? -1 : 1;
	y = (nb == 4 || nb == 3) ? fo->h - 1 : 0;
	x = (nb == 2 || nb == 3) ? fo->l - 1 : 0;
	while (x < fo->l && x > -1)
	{
		y = (nb == 4 || nb == 3) ? fo->h - 1 : 0;
		while (y < fo->h && y > -1)
		{
			if (x + t[1] < fo->l && x + t[1] > -1 && y + t[0] < fo->h &&
					y + t[0] > -1)
				ft_trace_losange(fo, x, y, t);
			y = (nb == 4 || nb == 3) ? y - 1 : y + 1;
		}
		x = (nb == 2 || nb == 3) ? x - 1 : x + 1;
	}
}

/*
**	<-- ft_ordre_affichage -->
**		trie les point horizon
*/

static void	ft_ordre_affichage(t_info *fo, int *a, int *b)
{
	t_point	tmp;
	int		i;
	int		j;

	i = 3;
	while (++i < 8)
	{
		j = i;
		while (++j < 8)
		{
			if (fo->horizon[i].z < fo->horizon[j].z)
			{
				tmp = fo->horizon[i];
				fo->horizon[i] = fo->horizon[j];
				fo->horizon[j] = tmp;
			}
		}
	}
	*a = fo->horizon[4].x + 1;
	*b = fo->horizon[5].x + 1;
}

/*
** 	<-- ft_trace_map -->
**		trace la carte dans une image
**	ft_ordre_affichage -> ft_trace_map.c
**		trie les point horizon
**	ft_trace_map_4 -> ft_trace_map_2.c
**		trace la carte transparence desactivé
**	ft_trace_map_2 -> ft_trace_map.c
**		trace la carte transparence activé selon certain ordre
**	ft_trace_map_3 -> ft_trace_map.c
**		trace la carte transparence activé selon certain ordre
*/

void		ft_trace_map(t_info *fo)
{
	int nb;
	int nb2;

	ft_ordre_affichage(fo, &nb, &nb2);
	if (fo->transparence == 0)
		ft_trace_map_4(fo);
	else if (((nb == 1 || nb == 4) && (nb2 == 2 || nb2 == 3)) ||
			((nb == 2 || nb == 3) && (nb2 == 1 || nb2 == 4)))
		ft_trace_map_2(fo, nb);
	else
		ft_trace_map_3(fo, nb);
}
