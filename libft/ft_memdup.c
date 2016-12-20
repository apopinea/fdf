/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 11:01:05 by apopinea          #+#    #+#             */
/*   Updated: 2016/11/10 11:01:07 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memdup(const void *s1, size_t l)
{
	void	*s2;

	if (!s1)
		return (NULL);
	if (!(s2 = (void*)malloc(sizeof(unsigned char) * l)))
		return (NULL);
	return (ft_memcpy(s2, s1, l));
}
