/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukan <lukan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:02:07 by tlukan            #+#    #+#             */
/*   Updated: 2024/08/27 15:22:26 by lukan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int argc, char **argv)
{
	t_mat	first;
	int		i;

	if (!validate(argc, argv, &first))
		return (write(2, "Error\n", 7));
	i = 0;
	first.null = findnull(&first);
	if (!initialstack(&first, first.size_na, sizeof(int *)))
		return (write(2, "Error\n", 7));
	meccanicalkebab(&first);
	while (i < first.size_na && first.staca[i] != first.min)
		i++;
	if (i > (first.size_na / 2))
	{
		while (first.staca[0] != first.min)
			rra(&first);
	}
	else
	{
		while (first.staca[0] != first.min)
			ra(&first);
	}
	return (0);
}
