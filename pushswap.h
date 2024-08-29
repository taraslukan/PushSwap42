/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukan <lukan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 13:59:35 by tlukan            #+#    #+#             */
/*   Updated: 2024/08/28 16:42:17 by lukan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <unistd.h>
# include "struct.h"
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <fcntl.h>
# include "ft_libft/libft.h"
# include "struct.h"
# include "liberror.h"
# include "ft_printf/ft_printf.h"

int		validate(int argc, char **argv, t_mat *first);
void	free_mat(char **mat);
int		findnull(t_mat *first);
int		*initialstack(t_mat *first, size_t count, size_t size);
void	sa(t_mat *first);
void	sb(t_mat *first);
void	ss(t_mat *first);
void	ra(t_mat *first);
void	rb(t_mat *first);
void	rr(t_mat *first);
void	rra(t_mat *first);
void	rrb(t_mat *first);
void	rrr(t_mat *first);
void	pusha(t_mat *first);
void	pushb(t_mat *first);
void	meccanicalkebab(t_mat *first);
void	metadown(int i, t_mat *first);
void	metaup(int i, t_mat *first);
void	startpush(t_mat	*first);
int		ft_findmax(t_mat *first);
int		ft_findmin(t_mat *first);
int		funzionera(t_mat *first, int indexb);
int		nonumero(const char *str);
int		control_doubles(t_mat *first);
int		valsplit(t_mat *first, char **argv);
int		*changstacminus(int *str1, int size);
int		*ft_strduppush(int *s1, int size, int *s2);
int		funzionecosto(int ib, t_mat *first);
void	funzione_che_muove(t_mat *first, int ia, int ib);
int		findlownode(t_mat *first);
void	firstpart(t_mat *first, int ia, int ib);
void	secondpart(t_mat *first, int ia, int ib);
void	thirdpart(t_mat *first, int ia, int ib);
void	fourthpart(t_mat *first, int ia, int ib);
void	fifthpart(t_mat *first, int ia, int ib);
void	helprr(t_mat *first, int i, int ia, int tempb);

#endif