/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meccanicalkebab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlukan <tlukan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:25:00 by lukan             #+#    #+#             */
/*   Updated: 2024/08/05 18:35:57 by tlukan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	meccanicalkebab(t_mat *first)
{
	int	ib;
	int	ia;
	int	i;

	startpush(first);
	while (first->size_nb > 0)
	{
		ib = findlownode(first);
		ia = funzionera(first, ib);
		funzione_che_muove(first, ia, ib);
		printf("fino a qui arriva %i - %i \n", first->size_na, first->size_nb);
		pusha(first);
		printf("%i\n", first->staca[0]);
	}
	i = 0;
	//while (first->staca[i] < first->max)
	//	i++;
	//if (i > (first->size_na / 2))
	//	while (first->staca[0] < first->max)
	//		rra(first);
	//else
	//	while (first->staca[0] < first->max)
	//		ra(first);
	//i = 0;
	while (i < first->size_na)
	{
		printf("%i\n",first->staca[i]);
		i++;
	}
}
void	funzione_che_muove(t_mat *first,int ia,int ib)
{	
	if (ib < (first->size_nb / 2) && ia < (first->size_na / 2))
	{
		if (ib > ia)
			{
				while(ia > 0)
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
		else
			{
				while(ib > 0)
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
	}
	else if (ib > (first->size_nb / 2) && ia > (first->size_na / 2))
	{
		while(ia < first->size_na && ib < first->size_nb)
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
	else if (ib > (first->size_nb / 2) && ia < (first->size_na / 2))
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
					printf("Tette\n");
					ib++;
				}
			}
		}
	else
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
	int y;
	
	y = first->size_na - i;
	while (y > 0)
	{
		rra(first);
		y--;
	}
	pusha(first);
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
	    && first->staca[i] < first->stacb[indexb] 
	    && first->staca[first->size_na - 1] > first->stacb[indexb])
	        return (i);
	    else if (first->staca[i] > first->stacb[indexb] 
		&& first->staca[i + 1] < first->stacb[indexb])
	        return(i + 1);
	    i++;
	}
	return (i);	
}

