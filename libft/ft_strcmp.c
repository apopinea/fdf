/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 12:11:13 by apopinea          #+#    #+#             */
/*   Updated: 2016/11/06 14:21:39 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int i;

	i = 0;
	while (!(s1[i] ^ s2[i]))
		if (s1[i++] == '\0')
			return (0);
	return (((unsigned char*)s1)[i] - ((unsigned char*)s2)[i]);
}
