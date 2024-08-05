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

static int	ft_calcolo_ptnbu(unsigned int n);

int	ft_putnbruns(unsigned int n)
{
	int	x;

	if (n == 0)
	{
		write (1, "0", 1);
		return (1);
	}
	x = ft_calcolo_ptnbu(n);
	return (x);
}

static	int	ft_calcolo_ptnbu(unsigned int n)
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
