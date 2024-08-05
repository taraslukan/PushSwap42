/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukan <lukan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 13:59:51 by tlukan            #+#    #+#             */
/*   Updated: 2024/07/24 15:17:13 by lukan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# define NUM_COLLECTABLE 5
# define MAX_XPM 5

typedef struct s_mat
{
	int			min;
	int			max;
	int			smaller;
	int			size_na;
	int			size_nb;
	char		**matr;
	int			*staca;
	int			*stacb;
	int			null;
	long int	xmap;
	long int	ymap;
}	t_mat;

#endif

// 	first->stacb = ft_calloc(first->size_n, sizeof(int *));
