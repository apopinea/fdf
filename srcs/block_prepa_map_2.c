/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_prepa_map_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 12:56:22 by apopinea          #+#    #+#             */
/*   Updated: 2016/12/15 12:56:24 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lib_fdf.h"
#include <stdlib.h>

/*
**	<-- ft_affiche_nbz  -->
**		affiche liste des z.
*/

void		ft_affiche_nbz(t_info *fo)
{
	int		i;
	int		j;
	int		z;

	i = -1;
	while (++i < fo->nbz)
	{
		j = i;
		while (++j < fo->nbz)
		{
			if (fo->t_nbz[i] < fo->t_nbz[j])
			{
				z = fo->t_nbz[i];
				fo->t_nbz[i] = fo->t_nbz[j];
				fo->t_nbz[j] = z;
			}
		}
	}
	i = -1;
	while (++i < fo->nbz)
	{
		ft_putstr("\nz = ");
		ft_putnbr(fo->t_nbz[i]);
	}
	ft_putchar('\n');
}

/*
**	<-- ft_init_p_col  -->
**		init le tableau a degrader de couleur pour une droite
**	ft_error_n -> libft
**		affiche message d'erreur, renvoi NULL ou quite le prog
*/

void		ft_init_p_col(t_info *fo)
{
	int i;

	if (!(fo->p_col = (double**)ft_memalloc(sizeof(double*) *
			(fo->nbz + 10 + fo->nb_col))))
		ft_error_n(5, "erreur ft_init_nb_z : ", errno);
	i = -1;
	while (++i < fo->nbz + 10 + fo->nb_col)
	{
		if (!(fo->p_col[i] = (double*)ft_memalloc(sizeof(double) * 2)))
			ft_error_n(5, "erreur ft_init_nb_z : ", errno);
	}
}
