/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_param_5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 08:31:32 by apopinea          #+#    #+#             */
/*   Updated: 2016/12/13 08:31:39 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lib_fdf.h"
#include <stdlib.h>

/*
** 	<-- ft_tri_color -->
**		tri le tableau couleur en fonction de z
*/

static void		ft_tri_color(t_info *fo)
{
	int		i;
	int		j;
	int		tmp;

	i = -1;
	while (++i < fo->nb_col)
	{
		j = i;
		while (++j < fo->nb_col)
		{
			if ((fo->col)[i][1] == (fo->col)[j][1])
				fo->col_spe = 0;
			if ((fo->col)[i][1] < (fo->col)[j][1])
			{
				tmp = (fo->col)[i][1];
				(fo->col)[i][1] = (fo->col)[j][1];
				(fo->col)[j][1] = tmp;
				tmp = (fo->col)[i][0];
				(fo->col)[i][0] = (fo->col)[j][0];
				(fo->col)[j][0] = tmp;
			}
		}
	}
}

/*
**	<-- ft_record_color -->
**		enregistre dans un double tableau les couleur en leur position
**	ft_error_0 -> libft
**		affiche message d'erreur, renvoi 0 ou quite le prog
**	ft_atoi_base -> libft
**		char* en base b renvoi un int base 10
** 	ft_tri_color -> init_param_5.c
**		tri le tableau couleur en fonction de z
*/

static int		ft_record_color(t_list *beg, t_info *fo)
{
	t_list	*elem;
	int		i;
	int		j;
	char	*tmp;

	if (fo->nb_col < 1)
		return (0);
	if (!(fo->col = (int**)ft_memalloc(sizeof(int*) * fo->nb_col)))
		return (ft_error_0(1, "malloc error dans ft_record_color", 0));
	elem = beg;
	j = 0;
	while (j < fo->nb_col)
	{
		i = 0;
		if (!((fo->col)[j] = (int*)ft_memalloc(sizeof(int) * 2)))
			return (ft_error_0(1, "malloc error dans ft_record_color", 0));
		tmp = ft_strtrim(elem->content);
		(fo->col)[j][0] = ft_atoi_base(tmp, 16);
		(fo->col)[j++][1] = ft_atoi(ft_strchr(tmp, ' '));
		free(tmp);
		elem = elem->next;
	}
	ft_tri_color(fo);
	return (1);
}

/*
**	<-- init_color -->
**		recupere les couleur enregistrer dans le fichier param
**	ft_record_color -> init_param_5.c
**		enregistre dans un double tableau les couleur en leur position
*/

t_list			*init_color(t_list *beg, t_info *fo)
{
	t_list	*elem;
	char	*tmp;

	elem = beg;
	while (elem)
	{
		tmp = ft_strtrim(elem->content);
		if (ft_strcmp(tmp, "<\\ color >") == 0)
		{
			free(tmp);
			if (!(ft_record_color(beg, fo)))
				return (NULL);
			return (elem);
		}
		free(tmp);
		(fo->nb_col)++;
		elem = elem->next;
	}
	fo->nb_col = 0;
	return (NULL);
}

/*
**	<-- init_rot_type -->
**		recup angle cardan ou euler
*/

t_list			*init_rot_type(t_list *beg, t_info *fo)
{
	t_list	*elem;
	char	*tmp;

	if (!beg)
		return (NULL);
	elem = beg;
	(fo->rot_type) = ft_atoi(elem->content);
	while (elem)
	{
		tmp = ft_strtrim(elem->content);
		if (ft_strcmp(tmp, "<\\ rot_type >") == 0)
		{
			free(tmp);
			return (elem);
		}
		free(tmp);
		elem = elem->next;
	}
	return (NULL);
}
