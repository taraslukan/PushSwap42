/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukan <lukan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 13:59:49 by lukan             #+#    #+#             */
/*   Updated: 2024/08/26 16:00:34 by lukan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sa(t_mat *first)
{
	int temp;
	
	temp = first->staca[0];
	first->staca[0] = first->staca[1];
	first->staca[1] = temp;
}

void	sb(t_mat *first)
{
	int temp;
	
	temp = first->stacb[0];
	first->stacb[0] = first->stacb[1];
	first->stacb[1] = temp;
}

void	ss(t_mat *first)
{
	int temp;
	
	temp = first->staca[0];
	first->staca[0] = first->staca[1];
	first->staca[1] = temp;
	temp = first->stacb[0];
	first->stacb[0] = first->stacb[1];
	first->stacb[1] = temp;
}
