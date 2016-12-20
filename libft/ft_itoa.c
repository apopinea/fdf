/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 16:17:31 by apopinea          #+#    #+#             */
/*   Updated: 2016/11/09 16:17:33 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_comp_itoa(int nb, int l, char *str)
{
	if (nb == -2147483648)
	{
		str[l - 1] = '8';
		ft_comp_itoa(nb / 10, l - 1, str);
	}
	else
	{
		if (nb < 0)
		{
			nb *= -1;
			str[0] = '-';
		}
		if (nb > 9)
			ft_comp_itoa(nb / 10, l - 1, str);
		str[l - 1] = (nb % 10) + '0';
	}
}

char		*ft_itoa(int n)
{
	int		l;
	char	*str;
	int		nb;

	nb = n;
	l = (n < 0) ? 2 : 1;
	while (n /= 10)
		l++;
	if (!(str = ft_strnew(l)))
		return (NULL);
	ft_comp_itoa(nb, l, str);
	return (str);
}

static int	ft_itoa_f2(char *str, int n)
{
	int		l;
	int		nb;

	nb = n;
	l = (n < 0) ? 2 : 1;
	while (n /= 10)
		l++;
	ft_comp_itoa(nb, l, str);
	return (l);
}

static void	ft_itoa_f3(char *str, double n, unsigned char pre)
{
	unsigned char	i;
	int				n2;

	i = 0;
	while (i < pre)
	{
		n2 = n;
		n = (n - (double)n2) * 10;
		ft_itoa_f2(str + i, n);
		++i;
	}
}

/*
**	<-- ft_itoa_f -->
**		convertie double en char*
**			pre : precision de 0 à 6
*/

char		*ft_itoa_f(double n, unsigned char pre)
{
	char	*str;
	int		n3;

	if (!(str = (char*)ft_memalloc(22)))
		return (NULL);
	pre = (pre > 6 || pre < 0) ? 0 : pre;
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
		n3 = ft_itoa_f2(str + 1, n);
		str[n3 + 1] = ',';
		ft_itoa_f3(str + 2 + n3, n, pre);
	}
	else
	{
		n3 = ft_itoa_f2(str, n);
		str[n3] = ',';
		ft_itoa_f3(str + 1 + n3, n, pre);
	}
	return (str);
}
