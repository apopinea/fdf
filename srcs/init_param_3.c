/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_param_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 09:04:55 by apopinea          #+#    #+#             */
/*   Updated: 2016/11/30 09:04:56 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lib_fdf.h"
#include <stdlib.h>

/*
**	<-- init_lx	-->
**		recupere multiplicateur de distance sur x du fichier param
*/

t_list	*init_lx(t_list *beg, t_info *fo)
{
	t_list	*elem;
	char	*tmp;

	if (!beg)
		return (NULL);
	elem = beg;
	(fo->mult)[0] = ft_atoi_f(elem->content);
	if (fo->mult[0] <= 0)
		fo->mult[0] = 1;
	while (elem)
	{
		tmp = ft_strtrim(elem->content);
		if (ft_strcmp(tmp, "<\\ x >") == 0)
		{
			free(tmp);
			return (elem);
		}
		free(tmp);
		elem = elem->next;
	}
	return (NULL);
}

/*
**	<-- init_ly	-->
**		recupere multiplicateur de distance sur y du fichier param
*/

t_list	*init_ly(t_list *beg, t_info *fo)
{
	t_list	*elem;
	char	*tmp;

	if (!beg)
		return (NULL);
	elem = beg;
	(fo->mult)[1] = ft_atoi_f(elem->content);
	if (fo->mult[1] <= 0)
		fo->mult[1] = 1;
	while (elem)
	{
		tmp = ft_strtrim(elem->content);
		if (ft_strcmp(tmp, "<\\ y >") == 0)
		{
			free(tmp);
			return (elem);
		}
		free(tmp);
		elem = elem->next;
	}
	return (NULL);
}

/*
**	<-- init_lz	-->
**		recupere multiplicateur de distance sur z du fichier param
*/

t_list	*init_lz(t_list *beg, t_info *fo)
{
	t_list	*elem;
	char	*tmp;

	if (!beg)
		return (NULL);
	elem = beg;
	(fo->mult)[2] = ft_atoi_f(elem->content);
	if (fo->mult[2] <= 0)
		fo->mult[2] = 1;
	while (elem)
	{
		tmp = ft_strtrim(elem->content);
		if (ft_strcmp(tmp, "<\\ z >") == 0)
		{
			free(tmp);
			return (elem);
		}
		free(tmp);
		elem = elem->next;
	}
	return (NULL);
}

/*
**	<-- init_win_size -->
**		recupere taille fenetre
*/

t_list	*init_win_size(t_list *beg, t_info *fo)
{
	t_list	*elem;
	char	*tmp;

	if (!beg || !(beg->next))
		return (NULL);
	elem = beg;
	(fo->win_h) = ft_atoi(elem->content);
	(fo->win_l) = ft_atoi(elem->next->content);
	while (elem)
	{
		tmp = ft_strtrim(elem->content);
		if (ft_strcmp(tmp, "<\\ win size >") == 0)
		{
			free(tmp);
			return (elem);
		}
		free(tmp);
		elem = elem->next;
	}
	return (NULL);
}

/*
**	<-- init_l_zoom	-->
**		recupere le type de projection
*/

t_list	*init_l_zoom(t_list *beg, t_info *fo)
{
	t_list	*elem;
	char	*tmp;

	if (!beg || !(beg->next))
		return (NULL);
	elem = beg;
	(fo->l_zoom) = ft_atoi(elem->content);
	while (elem)
	{
		tmp = ft_strtrim(elem->content);
		if (ft_strcmp(tmp, "<\\ l_zoom >") == 0)
		{
			free(tmp);
			return (elem);
		}
		free(tmp);
		elem = elem->next;
	}
	return (NULL);
}
