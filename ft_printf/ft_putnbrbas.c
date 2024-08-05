/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlukan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:10:21 by tlukan            #+#    #+#             */
/*   Updated: 2024/02/14 14:10:28 by tlukan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbrbas(unsigned int nbr, char c)
{
	char	*bas;
	int		count;

	count = 0;
	if (c == 'x')
		bas = "0123456789abcdef";
	else
		bas = "0123456789ABCDEF";
	if (nbr >= 16)
		count += ft_putnbrbas(nbr / 16, c);
	count += ft_putchr(bas[nbr % 16]);
	return (count);
}
