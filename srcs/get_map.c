/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:56:59 by apopinea          #+#    #+#             */
/*   Updated: 2016/11/28 13:57:01 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lib_fdf.h"
#include <fcntl.h>
#include <unistd.h>

/*
**	<-- ft_nb_word -->
**		compte le nombre de mot
*/

static int		ft_nb_word(size_t *len, char *s, char lt)
{
	char	*s1;
	char	*s2;
	int		i;
	int		c;

	if (!s)
		return (0);
	i = 0;
	s1 = s;
	c = 0;
	while (1)
	{
		if (s[i] == lt || s[i] == '\0')
		{
			s2 = s + i;
			if (s2 - s1 > 1 || *s1 != lt)
				++c;
			s1 = s2;
		}
		if (s[i++] == '\0')
			break ;
	}
	*len = i;
	return (c);
}

/*
**	<-- ft_lecture_map -->
**		lit un fichier et renvois celui ci sous forme de liste chainé
**	get_next_line -> libft
**		lit un fichier ligne par ligne
**	ft_nb_word -> get_map.c
**		compte le nombre de mot
**	ft_error_n -> libft
**		affiche un message d'erreur et renvoi NULL ou quitte le prog
**	ft_lstpusback -> libft
**		ajoute a la fin d'une liste chainé un nouveau maillon
*/

static t_list	*ft_lecture_map(t_info *fo, t_list *map0, int fd)
{
	char	*str;
	size_t	c;
	int		nb;
	int		ok;

	ok = 1;
	while (ok)
	{
		if ((ok = get_next_line(fd, &str)) == -1)
			return (ft_error_n(4, "get_next_line lecture map error", 0));
		fo->h++;
		nb = ft_nb_word(&c, str, ' ');
		if (fo->l < nb)
			fo->l = nb;
		if (!(ft_lstpushback(&map0, (void*)str, c + 1)))
			return (ft_error_n(4, "erreur register_map 1", 0));
		ft_strdel(&str);
	}
	return (map0);
}

/*
**	<-- ft_register_map -->
**		lit un fichier .fdf et le recupere sous forme de liste chainé,
**		enregistre egalement la taille de la map
**	ft_lecture_map -> get_map.c
**		lit un fichier et renvois celui ci sous forme de liste chainé
**	ft_error_n -> libft
**		affiche un message d'erreur et renvoi NULL ou quitte le prog
*/

t_list			*ft_register_map(char *file, t_info *fo)
{
	t_list	*map0;
	int		fd;

	map0 = NULL;
	errno = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
		return (ft_error_n(5, "open file : ", errno));
	map0 = ft_lecture_map(fo, map0, fd);
	fo->h = (fo->h > 1) ? fo->h - 1 : 0;
	errno = 0;
	if (close(fd) == -1)
		ft_error_n(2, "file not close : ", errno);
	return (map0);
}
