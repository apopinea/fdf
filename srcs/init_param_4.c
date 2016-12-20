/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_param_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 08:28:06 by apopinea          #+#    #+#             */
/*   Updated: 2016/12/03 08:28:08 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lib_fdf.h"
#include <stdlib.h>

/*
**	<-- init_rx	-->
**		recupere rottation sur x du fichier param
*/

t_list	*init_rx(t_list *beg, t_info *fo)
{
	t_list	*elem;
	char	*tmp;

	if (!beg)
		return (NULL);
	elem = beg;
	(fo->rot)[0] = PI * (double)ft_atoi_f(elem->content);
	while (elem)
	{
		tmp = ft_strtrim(elem->content);
		if (ft_strcmp(tmp, "<\\ rx >") == 0)
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
**	<-- init_ry	-->
**		recupere rottation sur y du fichier param
*/

t_list	*init_ry(t_list *beg, t_info *fo)
{
	t_list	*elem;
	char	*tmp;

	if (!beg)
		return (NULL);
	elem = beg;
	(fo->rot)[1] = PI * (double)ft_atoi_f(elem->content);
	while (elem)
	{
		tmp = ft_strtrim(elem->content);
		if (ft_strcmp(tmp, "<\\ ry >") == 0)
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
**	<-- init_rz	-->
**		recupere rottation sur z du fichier param
*/

t_list	*init_rz(t_list *beg, t_info *fo)
{
	t_list	*elem;
	char	*tmp;

	if (!beg)
		return (NULL);
	elem = beg;
	(fo->rot)[2] = PI * (double)ft_atoi_f(elem->content);
	while (elem)
	{
		tmp = ft_strtrim(elem->content);
		if (ft_strcmp(tmp, "<\\ rz >") == 0)
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
**	<-- init_centrage -->
**		recupere type de centrage
*/

t_list	*init_centrage(t_list *beg, t_info *fo)
{
	t_list	*elem;
	char	*tmp;

	if (!beg)
		return (NULL);
	elem = beg;
	fo->centrage = ft_atoi(elem->content);
	while (elem)
	{
		tmp = ft_strtrim(elem->content);
		if (ft_strcmp(tmp, "<\\ centrage >") == 0)
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
**	<-- init_transparence -->
**		recupere param active ou desactive transparence
*/

t_list	*init_transparence(t_list *beg, t_info *fo)
{
	t_list	*elem;
	char	*tmp;

	if (!beg)
		return (NULL);
	elem = beg;
	fo->transparence = ft_atoi(elem->content);
	while (elem)
	{
		tmp = ft_strtrim(elem->content);
		if (ft_strcmp(tmp, "<\\ transparence >") == 0)
		{
			free(tmp);
			return (elem);
		}
		free(tmp);
		elem = elem->next;
	}
	return (NULL);
}
