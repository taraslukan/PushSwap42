/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partofmekeb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukan <lukan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:11:39 by lukan             #+#    #+#             */
/*   Updated: 2024/08/29 16:07:06 by lukan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	firstpart(t_mat *first, int ia, int ib)
{
	while (ia > 0)
	{
		rr(first);
		ia--;
		ib--;
	}
	while (ib > 0)
	{
		rb(first);
		ib--;
	}
}

void	secondpart(t_mat *first, int ia, int ib)
{
	while (ib > 0)
	{
		rr(first);
		ib--;
		ia--;
	}
	while (ia > 0)
	{
		ra(first);
		ia--;
	}
}

void	thirdpart(t_mat *first, int ia, int ib)
{
	while (ia < first->size_na && ib < first->size_nb)
	{
		rrr(first);
		ia++;
		ib++;
	}
	while (ib < first->size_nb || ia < first->size_na)
	{
		if (ia == first->size_na)
		{
			rrb(first);
			ib++;
		}
		else
		{
			rra(first);
			ia++;
		}
	}
}

void	fourthpart(t_mat *first, int ia, int ib)
{
	while (ib < first->size_nb || ia > 0)
	{
		if (ia > 0)
		{
			ra(first);
			ia--;
		}
		if (ib < first->size_nb)
		{
			rrb(first);
			ib++;
		}
	}
}

void	fifthpart(t_mat *first, int ia, int ib)
{
	while (ia < first->size_na || ib > 0)
	{
		if (ib > 0)
		{
			rb(first);
			ib--;
		}
		if (ia < first->size_na)
		{
			rra(first);
			ia++;
		}
	}
}
