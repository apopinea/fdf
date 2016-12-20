/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_touche_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 09:26:35 by apopinea          #+#    #+#             */
/*   Updated: 2016/12/18 09:26:37 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lib_fdf.h"
#include "mlx.h"

/*
**	<-- put_menut_2 -->
**		affiche les touches suite
**	mlx_string_put -> mlx.h
**		affiche texte dans une fenetre
*/

void			put_menut_2(t_menu_t *tt)
{
	mlx_string_put(tt->mlx, tt->win, 10, 430, COLOR_B,
		"afficher ou quitter keyboard :  ^");
	mlx_string_put(tt->mlx, tt->win, 10, 450, COLOR_B,
		"afficher ou quitter menu     :  &");
}

/*
**	<-- mouse_hook_3 -->
**		enregistre la fermeture du menu
*/

int				mouse_hook_3(t_info *fo)
{
	fo->menut_a = 0;
	return (1);
}

/*
**	<-- mlx_expose_hook_3 -->
**		gérer l'évènement expose pour menu touche
**	draw_menut -> menu_touche.c
**		couleur de fond du menut
**	put_menut -> menu_2.c
**		affiche les infos
*/

int				expose_hook_3(t_info *fo)
{
	if (fo->menut_a == 1)
	{
		draw_menut(fo->menut);
		put_menut(fo->menut);
	}
	return (1);
}
