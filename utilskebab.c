/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilskebab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukan <lukan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:34:28 by lukan             #+#    #+#             */
/*   Updated: 2024/08/29 15:15:50 by lukan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	metadown(int i, t_mat *first)
{
	while (i > 0)
	{
		ra(first);
		i--;
	}
	pusha(first);
}

void	metaup(int i, t_mat *first)
{
	int	y;

	y = first->size_na - i;
	while (y > 0)
	{
		rra(first);
		y--;
	}
	pusha(first);
}

int	ft_findmin(t_mat *first)
{
	int	min;
	int	i;

	i = 0;
	min = first->staca[0];
	while (i < first->size_na)
	{
		if (first->staca[i] < min)
		{
			min = first->staca[i];
		}
		i++;
	}
	return (min);
}

int	ft_findmax(t_mat *first)
{
	int	max;
	int	i;

	i = 0;
	max = first->staca[0];
	while (i < first->size_na)
	{
		if (first->staca[i] > max)
			max = first->staca[i];
		i++;
	}
	return (max);
}

int	funzionera(t_mat *first, int indexb)
{
	int	i;

	i = 0;
	while (i < first->size_na - 1)
	{
		if (i == 0
			&& first->staca[i] > first->stacb[indexb]
			&& first->staca[first->size_na - 1] < first->stacb[indexb])
			return (i);
		else if (first->staca[i] < first->stacb[indexb]
			&& first->staca[i + 1] > first->stacb[indexb])
			return (i + 1);
		i++;
	}
	return (i);
}
