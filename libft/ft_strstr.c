/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 09:16:18 by apopinea          #+#    #+#             */
/*   Updated: 2016/11/07 10:25:48 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int		i;
	int		j;
	int		count;

	count = ft_strlen(little);
	i = -1;
	if (count == 0)
		return ((char*)big);
	while (big[++i] && (j = 0) == 0)
		while (big[i + j] == little[j])
			if (++j == count)
				return ((char*)big + i);
	return (NULL);
}
