/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukan <lukan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 13:59:49 by lukan             #+#    #+#             */
/*   Updated: 2024/08/29 15:19:54 by lukan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sa(t_mat *first)
{
	int	temp;

	temp = first->staca[0];
	first->staca[0] = first->staca[1];
	first->staca[1] = temp;
	first->move++;
	write(1, "sa\n", 3);
}

void	sb(t_mat *first)
{
	int	temp;

	temp = first->stacb[0];
	first->stacb[0] = first->stacb[1];
	first->stacb[1] = temp;
	first->move++;
	write(1, "sb\n", 3);
}

void	ss(t_mat *first)
{
	int	temp;

	temp = first->staca[0];
	first->staca[0] = first->staca[1];
	first->staca[1] = temp;
	temp = first->stacb[0];
	first->stacb[0] = first->stacb[1];
	first->stacb[1] = temp;
	first->move++;
	write(1, "ss\n", 3);
}
