/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukan <lukan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:57:32 by lukan             #+#    #+#             */
/*   Updated: 2024/07/10 16:00:39 by lukan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rra(t_mat *first)
{
	int	temp;
	int	i;
	
	i = first->size_na - 1;
	temp = first->staca[i];
	while (i > 0)
	{
		first->staca[i] = first->staca[i - 1];
		i--;
	}
	first->staca[0] = temp;
	write(1,"rra\n", 4);
}

void	rrb(t_mat *first)
{
	int	temp;
	int	i;

	i = first->size_nb - 1;
	temp = first->stacb[i];
	while (i > 0)
	{
		first->stacb[i] = first->stacb[i - 1];
		i--;
	}
	first->stacb[0] = temp;
	write(1,"rrb\n", 4);
}

void	rrr(t_mat *first)
{	int	temp;
	int	i;
	
	i = first->size_na - 1;
	temp = first->staca[i];
	while (i > 0)
	{
		first->staca[i] = first->staca[i - 1];
		i--;
	}
	first->staca[0] = temp;
	i = first->size_nb - 1;
	temp = first->stacb[i];
	while (i > 0)
	{
		first->stacb[i] = first->stacb[i - 1];
		i--;
	}
	first->stacb[0] = temp;
	write(1,"rrr\n", 4);
}
