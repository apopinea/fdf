/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lpause.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 08:50:47 by apopinea          #+#    #+#             */
/*   Updated: 2016/11/15 08:50:55 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void	ft_lpause(void)
{
	char	buf[2];
	int		ret;
	int		i;

	i = -1;
	while (++i < 2)
		buf[i] = '\0';
	ret = read(0, buf, 1);
	buf[ret] = '\0';
}
