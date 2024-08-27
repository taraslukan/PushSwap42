/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meccanicalkebab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukan <lukan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:25:00 by lukan             #+#    #+#             */
/*   Updated: 2024/08/27 14:51:39 by lukan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	meccanicalkebab(t_mat *first)
{
	int	ib;
	int	ia;

	startpush(first);
	if (first->staca[0] == first->max)
		ra(first);
	while (first->size_nb > 0)
	{
		ib = findlownode(first);
		ia = funzionera(first, ib);
		funzione_che_muove(first, ia, ib);
		pusha(first);
	}
	
}

void	funzione_che_muove(t_mat *first,int ia,int ib)
{	
	if (ib < (first->size_nb / 2) && ia < (first->size_na / 2))
	{
		if (ib > ia)
			firstpart(first, ia, ib);
		else
			secondpart(first, ia, ib);
	}
	else if (ib > (first->size_nb / 2) && ia > (first->size_na / 2))
		thirdpart(first, ia, ib);
	else if (ib > (first->size_nb / 2) && ia < (first->size_na / 2))
		fourthpart(first, ia, ib);
	else
		fifthpart(first, ia, ib);
}

/*deve ritornare lindice di B RELATIVO al costo piu basso*/
int	findlownode(t_mat	*first)
{
	int	ib;
	int	cost;
	int	ret;
	
	cost = INT_MAX;
	ib = 0;
	while (ib < first->size_nb)
	{
		if (funzionecosto(ib, first) < cost)
		{
			cost = funzionecosto(ib, first);
			ret = ib;
		}
		ib++;
	}
	return (ret);
}

int	funzionecosto(int ib, t_mat *first)
{
	int	indexa;
	
	indexa = funzionera(first, ib);
	if (ib < (first->size_nb / 2) && indexa < (first->size_na / 2))
	{
		if (ib > indexa)
			return (ib);
		else
			return (indexa);
	}
	else if (ib > (first->size_nb / 2) && indexa > (first->size_na / 2))
	{
		if (first->size_nb - ib > first->size_na - indexa)
			return (first->size_nb - ib);
		else
			return (first->size_na - indexa);
	}
	else if (ib > (first->size_nb / 2) && indexa < (first->size_na / 2))
		return((first->size_nb - ib) + indexa);
	else
		return ((first->size_na - indexa) + ib);
}

void	startpush(t_mat *first)
{	
	first->min = ft_findmin(first);
	first->max = ft_findmax(first);
	while (first->size_na > 2)
	{
		if (first->staca[0] == first->min || first->staca[0] == first->max)
			ra(first);
		if (first->staca[0] == first->min || first->staca[0] == first->max)
			ra(first);
		pushb(first);
	}
}
 