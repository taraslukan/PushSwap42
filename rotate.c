/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukan <lukan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 14:30:51 by lukan             #+#    #+#             */
/*   Updated: 2024/08/29 14:48:07 by lukan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ra(t_mat *first)
{
	int	temp;
	int	i;

	i = 0;
	while ((int) i < first->size_na)
	{
		if (i == 0)
		{
			temp = first->staca[i];
		}
		else
			first->staca[i - 1] = first->staca[i];
		i++;
	}
	i = first->size_na - 1;
	first->staca[i] = temp;
	write(1, "ra\n", 3);
	first->move++;
}

void	rb(t_mat *first)
{
	int	temp;
	int	i;

	i = 0;
	while ((int) i < first->size_nb)
	{
		if (i == 0)
		{
			temp = first->stacb[i];
		}
		else
			first->stacb[i - 1] = first->stacb[i];
		i++;
	}
	i = first->size_nb - 1;
	first->stacb[i] = temp;
	write(1, "rb\n", 3);
	first->move++;
}

void	rr(t_mat *first)
{
	int	tempb;
	int	i;
	int	ia;

	i = 0;
	ia = 0;
	while (i < first->size_nb || ia < first->size_na)
	{
		if (i == 0)
		{
			first->tempa = first->staca[i];
			tempb = first->stacb[i];
		}
		else
		{
			if (ia < first->size_na)
				first->staca[ia - 1] = first->staca[ia];
			if (i < first->size_nb)
				first->stacb[i - 1] = first->stacb[i];
		}
		i++;
		ia++;
	}
	helprr(first, i, ia, tempb);
	first->move++;
}

void	helprr(t_mat *first, int i, int ia, int tempb)
{
	i = first->size_nb - 1;
	ia = first->size_na - 1;
	first->staca[ia] = first->tempa;
	first->stacb[i] = tempb;
	write(1, "rr\n", 3);
	first->move++;
}
