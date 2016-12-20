/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 13:57:14 by apopinea          #+#    #+#             */
/*   Updated: 2016/11/08 13:57:16 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		l;
	char	*str;

	if (s1 && s2)
	{
		l = ft_strlen(s1) + ft_strlen(s2);
		if (!(str = ft_strnew(l)))
			return (NULL);
		while (*s1)
			*str++ = *s1++;
		while (*s2)
			*str++ = *s2++;
		return (str - l);
	}
	return (NULL);
}
