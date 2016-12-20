/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_param_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 15:50:22 by apopinea          #+#    #+#             */
/*   Updated: 2016/11/29 15:50:24 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lib_fdf.h"
#include "stdlib.h"

/*
**	<-- init_param_2_lanceur_2 -->
**		lance la fonction associé aux balise du fichier param (suite)
**	init_transparence -> init_param_4.c
**		recupere param active ou desactive transparence
**	init_rot_type -> init_param_5.c
**		recup angle cardan ou euler
*/

static t_list	*init_param_2_lanceur_2(t_list *beg, t_info *fo, char *tmp)
{
	if (ft_strcmp(tmp, "< transparence >") == 0)
		return (init_transparence(beg, fo));
	else if (ft_strcmp(tmp, "< rot_type >") == 0)
		return (init_rot_type(beg, fo));
	return (beg);
}

/*
**	<-- init_param_2_lanceur -->
**		lance la fonction associé aux balise du fichier param
**	init_color -> init_param_5.c
**		recupere les couleur enregistrer dans le fichier param
**	init_lx	-> init_param_3.c
**		recupere multiplicateur de distance sur x du fichier param
**	init_ly	-> init_param_3.c
**		recupere multiplicateur de distance sur y du fichier param
**	init_lz	-> init_param_3.c
**		recupere multiplicateur de distance sur z du fichier param
**	init_rx	-> init_param_4.c
**		recupere rottation sur x du fichier param
**	init_ry	-> init_param_4.c
**		recupere rottation sur y du fichier param
**	init_rz	-> init_param_4.c
**		recupere rottation sur z du fichier param
**	init_win_size	-> init_param_3.c
**		recupere taille fenetre
**	init_l_zoom	-> init_param_3.c
**		recupere le type de projection
**	init_centrage -> init_param_4.c
**		recupere type de centrage
**	init_param_2_lanceur_2 -> init_param_2.c
**		lance la fonction associé aux balise du fichier param (suite)
*/

static t_list	*init_param_2_lanceur(t_list *beg, t_info *fo, char *tmp)
{
	if (!beg || !tmp)
		return (NULL);
	if (ft_strcmp(tmp, "< color >") == 0)
		return (init_color(beg, fo));
	else if (ft_strcmp(tmp, "< x >") == 0)
		return (init_lx(beg, fo));
	else if (ft_strcmp(tmp, "< y >") == 0)
		return (init_ly(beg, fo));
	else if (ft_strcmp(tmp, "< z >") == 0)
		return (init_lz(beg, fo));
	else if (ft_strcmp(tmp, "< rx >") == 0)
		return (init_rx(beg, fo));
	else if (ft_strcmp(tmp, "< ry >") == 0)
		return (init_ry(beg, fo));
	else if (ft_strcmp(tmp, "< rz >") == 0)
		return (init_rz(beg, fo));
	else if (ft_strcmp(tmp, "< win size >") == 0)
		return (init_win_size(beg, fo));
	else if (ft_strcmp(tmp, "< l_zoom >") == 0)
		return (init_l_zoom(beg, fo));
	else if (ft_strcmp(tmp, "< centrage >") == 0)
		return (init_centrage(beg, fo));
	else
		return (init_param_2_lanceur_2(beg, fo, tmp));
}

/*
**	<-- init_param_2 -->
**		parcour la liste chainé du fichier param et recupere les info
**	ft_strtrim -> libft
**		enleve les carractere espace, tab ... a la fin et au debut de la str
**	init_param_2_lanceur -> init_param_2.c
**		lance la fonction associé aux balise du fichier param
*/

int				init_param_2(t_list *beg, t_info *fo)
{
	t_list	*elem;
	char	*tmp;

	elem = beg;
	while (elem)
	{
		if (ft_strcmp(elem->content, "< param >") == 0)
			break ;
		elem = elem->next;
		if (elem == NULL)
			return (0);
	}
	while (elem)
	{
		if (elem->next == NULL)
			return (1);
		tmp = ft_strtrim(elem->content);
		if (!(elem = init_param_2_lanceur(elem->next, fo, tmp)))
		{
			free(tmp);
			return (0);
		}
		free(tmp);
	}
	return (1);
}
