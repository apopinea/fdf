/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfloat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apopinea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 13:26:13 by apopinea          #+#    #+#             */
/*   Updated: 2016/11/23 13:26:14 by apopinea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putfloat(double n)
{
	int n2;
	int i;

	if (n < 0)
		ft_putchar('-');
	n = ABS(n);
	n2 = n;
	ft_putnbr(n2);
	n = n - (double)n2;
	if (n != 0)
		ft_putchar(',');
	else
		return ;
	i = 0;
	n2 = n;
	while (i++ < 6)
	{
		n = (10.0 * n) - ((double)n2 * 10.0);
		n2 = n;
		ft_putnbr(n2);
	}
}
