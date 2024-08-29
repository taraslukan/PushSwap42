/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukan <lukan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:06:14 by lukan             #+#    #+#             */
/*   Updated: 2024/08/28 16:40:48 by lukan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	findnull(t_mat *first)
{
	int	i;
	int	ris;

	i = 0;
	ris = 0;
	while (i < first->size_na)
	{
		if (first->staca[i] == ris)
		{
			i = 0;
			ris++;
		}
		else
			i++;
	}
	return (ris);
}

int	*initialstack(t_mat *first, size_t count, size_t size)
{
	int	*ris;

	if (count && size && (4294967295U / size <= count))
		return (0);
	ris = malloc(count * size);
	if (ris == NULL)
		return (NULL);
	ft_memset(ris, first->null, count * size);
	return (ris);
}
