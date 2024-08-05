/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlukan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:55:32 by tlukan            #+#    #+#             */
/*   Updated: 2024/02/06 14:55:59 by tlukan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_calcolo_ptnb(int n);

int	ft_putnbr(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
	{
		write (1, "-2147483648", 11);
		return (11);
	}
	if (n == 0)
	{
		write (1, "0", 1);
		return (1);
	}
	if (n < 0)
	{
		write (1, "-", 1);
		i++;
		n = n * -1;
	}
	return ((ft_calcolo_ptnb(n)) + i);
}

static	int	ft_calcolo_ptnb(int n)
{
	int		b;
	int		i;
	char	c;
	int		a;

	a = 0;
	b = 1000000000;
	while (n / b == 0)
		b = b / 10;
	while (b > 1)
	{
		i = n / b;
		c = i + 48;
		write (1, &c, 1);
		a++;
		n = n - (i * b);
		b = b / 10;
	}
	if (b == 1)
	{
		c = n + 48;
		write (1, &c, 1);
	}
	return (a + 1);
}
