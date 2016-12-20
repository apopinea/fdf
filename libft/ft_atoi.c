/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 11:19:33 by apopinea          #+#    #+#             */
/*   Updated: 2016/11/04 11:24:12 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(char *str)
{
	int nb;
	int i;
	int neg;

	if (!str)
		return (0);
	i = 0;
	nb = 0;
	neg = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
		neg = (str[i++] == '-') ? -1 : 1;
	while (str[i] >= '0' && str[i] <= '9')
		nb = (nb * 10) + (str[i++] - '0');
	return (neg * nb);
}

int		ft_atoi_next(char *str, int *i)
{
	int		nb;
	int		neg;

	if (!str || i < 0)
		return (0);
	nb = 0;
	neg = 1;
	while (str[*i] == ' ' || str[*i] == '\t' || str[*i] == '\n' ||
		str[*i] == '\v' || str[*i] == '\f' || str[*i] == '\r')
		(*i)++;
	if (str[*i] == '-' || str[*i] == '+')
		neg = (str[(*i)++] == '-') ? -1 : 1;
	while (str[*i] >= '0' && str[*i] <= '9')
		nb = (nb * 10) + ((str)[(*i)++] - '0');
	return (neg * nb);
}

double	ft_atoi_f(char *str)
{
	double	nb;
	int		i;
	int		j;
	int		neg;

	if (!str)
		return (0);
	i = 0;
	nb = 0.0;
	neg = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
		neg = (str[i++] == '-') ? -1 : 1;
	while (str[i] >= '0' && str[i] <= '9')
		nb = (nb * 10.0) + (double)(str[i++] - '0');
	if (str[i] == '.')
		i++;
	j = 0;
	while (str[i] >= '0' && str[i] <= '9' && ++j < 7)
		nb = nb + ((double)(str[i++] - '0') / ft_pow_f(10, j));
	return (neg * nb);
}
