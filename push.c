/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukan <lukan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:32:44 by lukan             #+#    #+#             */
/*   Updated: 2024/07/15 12:13:59 by lukan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	pushb(t_mat *first)
{
	if (first->size_nb == 0)
	{
		first->stacb = calloc((1), sizeof(int));
		first->size_nb++;
		first->stacb[0] = first->staca[0];
		first->staca = changstacminus(first->staca, first->size_na);
		first->size_na--;
		write(1,"pb\n", 3);
		return;
	}
	first->stacb = ft_strduppush(first->stacb, first->size_nb, first->staca);
	first->staca = changstacminus(first->staca, first->size_na);
	first->size_na--;
	first->size_nb++;
	write(1,"pb\n", 3);

}

void	pusha(t_mat *first)
{
	first->staca = ft_strduppush(first->staca, first->size_na, first->stacb);
	first->stacb = changstacminus(first->stacb, first->size_nb);
	first->size_na++;
	first->size_nb--;
	write(1,"pa\n", 3);

}
int	*changstacminus(int *str1, int size)
{
	int	*ris;
	int	i;

	i = 0;
	ris = ft_calloc((size - 1), sizeof(int));
	if (ris == NULL)
		return (NULL);
	while (i < size - 1)
	{
		ris [i] = str1[i + 1];
		i++;
	}
	free(str1);
	return (ris);	
}

int	*ft_strduppush(int *s1, int size, int *s2)
{
	int		*ris;
	int		len;
	int		i;

	i = 0;
	len = size;
	ris = ft_calloc((len + 1), sizeof(int));
	if (ris == NULL)
		return (NULL);
	ris[i] = s2[i];
	while (i < len)
	{
		ris[i + 1] = s1[i];
		i++;
	}
	free(s1);
	return (ris);
}
