/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_param.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 07:44:54 by apopinea          #+#    #+#             */
/*   Updated: 2016/11/29 07:44:55 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lib_fdf.h"
#include <fcntl.h>
#include <unistd.h>

/*
**	<-- register_file_param -->
**		lit un fichier et renvois celui ci sous forme de liste chainé
**	get_next_line -> libft
**		lit un fichier ligne par ligne
**	ft_lstpusback -> libft
**		ajoute a la fin d'une liste chainé un nouveau maillon
*/

static t_list	*register_file_param(int fd)
{
	t_list	*param;
	char	*str;
	int		ok;

	ok = 1;
	param = NULL;
	while (ok)
	{
		ok = get_next_line(fd, &str);
		if (!(ft_lstpushback(&param, (void*)str, ft_strlen(str) + 1)))
			return (ft_error_n(1, "erreur param", 0));
		ft_strdel(&str);
	}
	return (param);
}

/*
**	<-- get_file_param -->
**		ouvre le fichier param et en registre info
**	ft_error_n -> libft
**		affiche un message d'erreur et renvoi NULL ou quitte le prog
**	register_file_param -> get_file_param.c
**		lit un fichier et renvois celui ci sous forme de liste chainé
*/

t_list			*get_file_param(char *file)
{
	t_list	*beg;
	int		fd;

	errno = 0;
	if ((fd = open(file, O_RDONLY)) == -1)
		return (ft_error_n(2, "open file param : ", errno));
	if (!(beg = register_file_param(fd)))
		return (NULL);
	if (close(fd) == -1)
		ft_error_n(2, "file not close : ", errno);
	return (beg);
}
