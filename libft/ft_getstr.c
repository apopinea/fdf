/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 12:40:07 by apopinea          #+#    #+#             */
/*   Updated: 2016/11/05 13:11:17 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char	*ft_getstr(int size)
{
	char	*buf;
	int		ret;
	int		i;

	if (size <= 0)
		size = 5000;
	if (!(buf = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = -1;
	while (++i < size)
		buf[i] = '\0';
	ret = read(0, buf, size);
	buf[ret] = '\0';
	return (buf);
}
