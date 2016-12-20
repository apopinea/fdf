/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 08:36:14 by apopinea          #+#    #+#             */
/*   Updated: 2016/12/13 08:36:16 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lib_fdf.h"
#include <math.h>

/*
**	<-- ft_mixt_matrice_2 -->
**		multiplie les matrice entre elle pour avoir la matrice final euler
**	ft_del_matrice -> libft
**		suprimme matrice
**	ft_vide_matrix -> libft
**		creer une matrice vide
**	ft_error_n -> libft
**		affiche message d'erreur, renvoi NULL ou quite le prog
**	ft_opera_matrix -> libft
**		lanceur d'operation sur matrice
*/

void		ft_mixt_matrice_2(t_info *fo)
{
	t_matrix	*tmp;
	double		phi;
	double		psi;
	double		theta;

	phi = fo->rot[1];
	theta = fo->rot[0];
	psi = fo->rot[2];
	ft_del_matrix(&(fo->final));
	if (!(tmp = ft_vid_matrix(3, 3)))
		ft_error_n(4, "init_matrice_rotation_x", 0);
	tmp->mat[0][0] = cos(psi) * cos(phi) - sin(psi) * cos(theta) * sin(phi);
	tmp->mat[0][1] = -cos(psi) * sin(phi) - sin(psi) * cos(theta) * cos(phi);
	tmp->mat[0][2] = -sin(psi) * sin(theta);
	tmp->mat[1][0] = sin(psi) * cos(phi) + cos(psi) * cos(theta) * sin(phi);
	tmp->mat[1][1] = -sin(psi) * sin(phi) + cos(psi) * cos(theta) * cos(phi);
	tmp->mat[1][2] = cos(psi) * sin(theta);
	tmp->mat[2][0] = sin(theta) * sin(phi);
	tmp->mat[2][1] = sin(theta) * cos(phi);
	tmp->mat[2][2] = -cos(theta);
	if (!(fo->final = ft_opera_matrix(tmp, "*", fo->rot_zoom)))
		ft_error_n(4, "erreur operation sur matrice : ", 0);
	ft_del_matrix(&tmp);
}
