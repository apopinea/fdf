/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 11:59:28 by apopinea          #+#    #+#             */
/*   Updated: 2016/11/22 15:07:46 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

static int	ft_lecture(const int fd, t_list **elem, char *buf, int l)
{
	int		j;
	int		k;
	int		ret;
	t_list	*tmp;

	k = 1;
	while ((ret = read(fd, buf + l, BUFF_SIZE)) && k)
	{
		if (ft_strlen(buf) == 0)
			break ;
		j = l;
		while (buf[j])
			if (buf[j++] == '\n')
				k = 0;
		l += BUFF_SIZE;
		if (!(buf = ft_rememalloc(buf, l + 1, l + BUFF_SIZE + 1)))
			return (-1);
	}
	if (!(tmp = ft_lstpushback(elem, buf, l + ret + 1)))
		return (-1);
	tmp->content_size = (size_t)fd;
	free(buf);
	return (ret);
}

static int	ft_cut(int fd, t_list **elem, char **line, int ret)
{
	t_list	*tmp;

	if (ret == -1)
		return (-1);
	tmp = *elem;
	while (tmp->content_size != (size_t)fd)
		tmp = tmp->next;
	if (!(*line = (ft_strscut((char**)&(tmp->content), "\n", 4))))
		return (-1);
	ret = (ret > 0 || ((char*)(tmp->content))[0] != '\0') ? 1 : 0;
	ret = ((*line)[0] != '\0') ? 1 : ret;
	if (((char*)(tmp->content))[0] == '\0')
		ft_lstdelif_n(elem, fd);
	return (ret);
}

static int	ft_rappel(t_list **elem, size_t fd, char **line, int i)
{
	t_list	*tmp;
	char	*buf;

	tmp = *elem;
	while (tmp)
	{
		if (tmp->content_size == fd)
		{
			i = 0;
			while (((char*)tmp->content)[i])
				if (((char*)tmp->content)[i++] == '\n')
					return (ft_cut(fd, elem, line, 1));
			if (!(buf = ft_rememalloc(ft_strdup(tmp->content),
					i + 1, i + BUFF_SIZE + 1)))
				return (0);
			ft_lstdelif_n(elem, fd);
			return (ft_cut(fd, elem, line, ft_lecture(fd, elem, buf, i)));
		}
		tmp = tmp->next;
	}
	if (!(buf = ft_strnew(BUFF_SIZE)))
		return (-1);
	return (ft_cut(fd, elem, line, ft_lecture(fd, elem, buf, 0)));
}

int			get_next_line(const int fd, char **line)
{
	static t_list	*begin = NULL;
	int				j;
	char			*buf;

	if (fd < 0 || !line || BUFF_SIZE < 1)
		return (-1);
	j = -1;
	if (begin)
	{
		if ((j = ft_rappel(&begin, fd, line, 0)) == -1)
			return (-1);
	}
	else
	{
		if (!(buf = ft_strnew(BUFF_SIZE)))
			return (-1);
		j = ft_cut(fd, &begin, line, ft_lecture(fd, &begin, buf, 0));
	}
	return (j);
}
