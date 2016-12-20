/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lecture_f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 15:08:52 by apopinea          #+#    #+#             */
/*   Updated: 2016/11/11 15:08:54 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <string.h>

static char		*ft_ecriture(char *file, size_t i, int *fd, size_t max)
{
	int		j;
	char	*buf;
	char	*str;
	size_t	ret;

	i = (i < 1) ? 1 : i;
	j = i;
	if ((*fd = open(file, O_RDONLY)) == -1)
		return (NULL);
	if (!(buf = ft_strnew(j)))
		return (NULL);
	while ((ret = read(*fd, buf + (i - j), i)))
	{
		if (i > max)
			return (0);
		i *= 2;
		if (ret * 2 == i)
			if (!(buf = ft_rememalloc(buf, i - j + 1, (2 * i) + 1 - j)))
				return (NULL);
	}
	if (!(str = ft_strdup(buf)))
		return (NULL);
	ft_strdel(&buf);
	return (str);
}

char			*ft_lecture_f(char *file, size_t i, size_t max)
{
	char	*str;
	int		fd;

	max = (max == 0) ? 2147483647 : max;
	if (!file)
		return (NULL);
	str = ft_ecriture(file, i, &fd, max);
	close(fd);
	return (str);
}
