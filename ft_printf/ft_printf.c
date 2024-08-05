/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlukan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:54:57 by tlukan            #+#    #+#             */
/*   Updated: 2024/02/09 15:55:32 by tlukan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ctrl_type(char c, va_list *ap)
{
	if (c == 'c')
		return (ft_putchr(va_arg(*ap, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(*ap, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(*ap, int)));
	else if (c == 'u')
		return (ft_putnbruns(va_arg(*ap, unsigned int)));
	else if (c == 'x' || c == 'X')
		return (ft_putnbrbas(va_arg(*ap, unsigned int), c));
	else if (c == 'p')
		return (ft_putstr("0x") + ft_putnbrbasp(va_arg(*ap, unsigned long)));
	else
		return (ft_putchr('%'));
}

int	ft_printf(const char *string, ...)
{
	int		i;
	va_list	ap;
	int		count;

	count = 0;
	i = -1;
	va_start(ap, string);
	while (string[++i])
	{
		if (string[i] == '%')
			count += ctrl_type(string[++i], &(ap));
		else
			count += ft_putchr(string[i]);
	}
	va_end(ap);
	return (count);
}
