/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lukan <lukan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:39:49 by tlukan            #+#    #+#             */
/*   Updated: 2024/07/15 12:52:05 by lukan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	nonumero(const char *str);
int	control_doubles(t_mat *first);
int	valsplit(t_mat *first, char **argv);

int	validate(int argc, char **argv, t_mat *first)
{
	int		i;
	long	chec;

	i = 0;
	if (argc == 2)
		return (valsplit(first, argv));
	else
	{
		first->size_na = argc - 1;
		first->staca = malloc(first->size_na * sizeof(int *));
		first->matr = argv + 1;
		first->size_nb = 0;
		while ((int) i < first->size_na)
		{
			chec = ft_atoi(first->matr[i]);
			if (!nonumero(first->matr[i]) || chec > INT_MAX || chec < INT_MIN)
				return (0);
			first->staca[i] = chec;
			i++;
		}
		if (control_doubles(first) == 0)
			return (0);
		return (1);
	}
}

int	valsplit(t_mat *first, char **argv)
{
	size_t	i;
	long	check;
	int		retu;

	i = 0;
	retu = 1;
	first->matr = ft_split(argv[1], ' ');
	while (first->matr[i])
		i++;
	first->size_na = i;
	i = 0;
	first->staca = malloc(first->size_na * sizeof(int *));
	while ((int) i < first->size_na)
	{
		check = ft_atoi(first->matr[i]);
		if (!nonumero(first->matr[i]) || check > INT_MAX || check < INT_MIN)
			retu = 0;
		first->staca[i] = check;
		i++;
	}
	free_mat(first->matr);
	if (retu == 1 && control_doubles(first) == 0)
		retu = 0;
	return (retu);
}

int	nonumero(const char *str)
{
	size_t			i;

	i = 0;
	while (str[i] == ' ' || ((str[i] > 8) && (str[i] < 14)))
		i++;
	if (ft_strlen(str + i) >= 62)
		return (0);
	if (str[i] == 45 || str[i] == 43)
		i++;
	if (!(str[i] >= 48) && (str[i] <= 57))
		return (0);
	while ((str[i] >= 48) && (str[i] <= 57))
	{
		i++;
	}
	if (str[i] == '\0')
		return (1);
	return (0);
}

int	control_doubles(t_mat *first)
{
	int	i;
	int	j;

	i = 0;
	while (i < first->size_na)
	{
		j = i + 1;
		while (j < first->size_na)
		{
			if (first->staca[i] == first->staca[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
