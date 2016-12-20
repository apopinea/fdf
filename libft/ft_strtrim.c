/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 11:51:04 by apopinea          #+#    #+#             */
/*   Updated: 2016/11/09 11:51:06 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		l1;
	int		l2;
	int		l3;
	char	*str;

	if (s)
	{
		l1 = 0;
		while (s[l1] == ' ' || s[l1] == '\t' || s[l1] == '\n')
			l1++;
		l3 = ft_strlen(s);
		l2 = 0;
		while (s[l3 - 1 - l2] == ' ' || s[l3 - 1 - l2] == '\t' ||
				s[l3 - 1 - l2] == '\n')
			l2++;
		if (l3 - l2 - l1 <= 0)
			return (ft_strnew(0));
		if ((str = ft_strsub(s, l1, (size_t)(l3 - l2 - l1))))
			return (str);
	}
	return (NULL);
}
