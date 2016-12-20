/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 11:05:17 by apopinea          #+#    #+#             */
/*   Updated: 2016/11/07 11:05:19 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int		i;
	int		j;
	int		count;

	count = ft_strlen(little);
	i = -1;
	if (count == 0)
		return ((char*)big);
	while (big[++i] && (j = 0) == 0 && i < (int)len)
		while (big[i + j] == little[j] && (i + j) < (int)len)
			if (++j == count)
				return ((char*)big + i);
	return (NULL);
}
