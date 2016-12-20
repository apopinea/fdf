/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 11:30:13 by apopinea          #+#    #+#             */
/*   Updated: 2016/11/04 11:45:38 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		count;

	count = ft_strlen(s1);
	if (!(s2 = (char*)malloc(sizeof(char) * (count + 1))))
		return (NULL);
	s2[count] = '\0';
	while (--count >= 0)
		s2[count] = s1[count];
	return (s2);
}
