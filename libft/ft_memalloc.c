/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 13:52:32 by apopinea          #+#    #+#             */
/*   Updated: 2016/11/07 13:52:34 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	unsigned char	*ret;
	unsigned int	i;

	if (!(ret = (unsigned char*)malloc(sizeof(unsigned char) * size)))
		return (NULL);
	i = 0;
	while (i < size)
		ret[i++] = 0;
	return ((void*)ret);
}
