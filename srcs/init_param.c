/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 12:31:02 by apopinea          #+#    #+#             */
/*   Updated: 2016/11/29 12:31:04 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lib_fdf.h"
#include "stdlib.h"

/*
**	<-- init_param_base_color -->
**		si pb dans le fichier param remise a 0 des couleurs
*/

static void		init_param_base_color(t_info *fo)
{
	int i;

	if (fo->col_spe == 0 && fo->nb_col > 0)
	{
		i = 0;
		while (i < fo->nb_col)
			free(((fo->col)[i++]));
		free((fo->col));
		fo->col_spe = 0;
		fo->nb_col = 0;
	}
}

/*
**	<-- init_param_base -->
**		complete les params manquants
**	init_param_base_color -> init_param.c
**		si pb dans le fichier param remise a 0 des couleurs
**	ft_error_0 -> libft
**		affiche message d'erreur, renvoi 0 ou quite le prog
*/

static void		init_param_base(t_info *fo)
{
	fo->mult[0] = (fo->mult[0] == 0) ? MULT_X : fo->mult[0];
	fo->mult[1] = (fo->mult[1] == 0) ? MULT_Y : fo->mult[1];
	fo->mult[2] = (fo->mult[2] == 0) ? MULT_Z : fo->mult[2];
	init_param_base_color(fo);
	if (fo->nb_col == 0)
	{
		errno = 0;
		if (!(fo->col = (int**)ft_memalloc(sizeof(int*) * 1)))
			ft_error_0(5, "malloc error dans init_base", errno);
		if (!(fo->col[0] = (int*)ft_memalloc(sizeof(int) * 2)))
			ft_error_0(5, "malloc error dans init_base", errno);
		fo->nb_col = 1;
		(fo->col)[0][0] = 0x00FFFFFF;
		(fo->col)[0][1] = 0;
		fo->col_spe = 1;
	}
}

/*
**	<-- init_param -->
**		initialise les parametres du programe
**	init_param_2 -> init_param_2.c
**		parcour la liste chainé du fichier param et recupere les info
**	ft_sucess -> libft
**		affiche message
**	ft_error_n -> libft
**		affiche message d'erreur, renvoi NULL ou quite le prog
**	init_param_base -> init_param.c
**		complete les params manquants
*/

void			init_param(t_list *beg, t_info *fo)
{
	int		ok;

	ok = 0;
	if (beg)
		ok = init_param_2(beg, fo);
	if (ok && fo->col_spe == 1)
		ft_success("Fichier param valide");
	else
		ft_error_n(1, "fichier param incorrecte ou abscent", 0);
	init_param_base(fo);
}
