/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_fdf_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 16:47:32 by apopinea          #+#    #+#             */
/*   Updated: 2016/12/16 16:47:34 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lib_fdf.h"

/*
** 	<-- key_hook_mlt -->
**		liste des touche evenement clavier multiplicateur distance et le reste
*/

void			key_hook_mlt(int keycode, t_info *fo)
{
	if (keycode == KEY_X_MULT_P)
		fo->mult[0] += fo->grad[2];
	else if (keycode == KEY_X_MULT_N)
		fo->mult[0] -= fo->grad[2];
	else if (keycode == KEY_Y_MULT_P)
		fo->mult[1] += fo->grad[2];
	else if (keycode == KEY_Y_MULT_N)
		fo->mult[1] -= fo->grad[2];
	else if (keycode == KEY_Z_MULT_P)
		fo->mult[2] += fo->grad[2];
	else if (keycode == KEY_Z_MULT_N)
		fo->mult[2] -= fo->grad[2];
	else if (keycode == KEY_XYZ_MULT_P)
	{
		fo->mult[0] *= fo->grad[3];
		fo->mult[1] *= fo->grad[3];
		fo->mult[2] *= fo->grad[3];
	}
	else if (keycode == KEY_XYZ_MULT_N)
	{
		fo->mult[0] *= fo->grad[4];
		fo->mult[1] *= fo->grad[4];
		fo->mult[2] *= fo->grad[4];
	}
}

/*
**	<-- mouse_hook -->
**		enregistre la fermeture de la fenetre principal et quitte le prog
**	ft_exit_fdf -> exit_fdf.c
**		libere le prog et le quitte
*/

int				mouse_hook(t_info *fo)
{
	fo->f_principal = 0;
	ft_exit_fdf(fo);
	return (1);
}

/*
**	<-- mlx_expose_hook -->
**		gérer l'évènement expose
**	draw_reload -> main.c
**		creer la carte et l'affiche
*/

int				expose_hook(t_info *fo)
{
	if (fo->f_principal == 1)
		draw_reload(fo);
	return (1);
}
