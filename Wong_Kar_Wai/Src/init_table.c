/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 12:01:01 by fhenry            #+#    #+#             */
/*   Updated: 2016/01/31 23:24:01 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void	rand_empty_case(int vide, int **table)
{
	int		c;
	int		l;
	int		case_vide;

	l = 0;
	case_vide = 0;
	while (l < 4)
	{
		c = 0;
		while (c < 4)
		{
			if (table[l][c] == 0)
			{
				case_vide++;
				if (case_vide == vide)
				{
					table[l][c] = rand_num();
					return ;
				}
			}
			c++;
		}
		l++;
	}
	return ;
}

static int	nbr_case_vide(int **table)
{
	int		c;
	int		l;
	int		case_vide;

	l = 0;
	case_vide = 0;
	while (l < 4)
	{
		c = 0;
		while (c < 4)
		{
			if (table[l][c] == 0)
				case_vide++;
			c++;
		}
		l++;
	}
	return (case_vide);
}

void		rand_case(int **table)
{
	int		i;
	int		vide;

	i = 0;
	srand(time(NULL));
	while (i < 2)
	{
		vide = (rand() % (nbr_case_vide(table)));
		while (vide == 0)
			vide = (rand() % (nbr_case_vide(table)));
		rand_empty_case(vide, table);
		i++;
	}
	return ;
}

char		***init_table(int size)
{
	int		c;
	int		l;
	int		**table;

	l = 0;
	if (!(table = (int **)malloc(sizeof(int *) * size)))
		return (NULL);
	while (l < size)
	{
		if (!(table[l] = (int *)malloc(sizeof(int) * size)))
			return (NULL);
		l++;
	}
	l = -1;
	while (++l < size)
	{
		c = 0;
		while (c < size)
		{
			table[l][c] = 0;
			c++;
		}
	}
	rand_case(table);
	return (itoa_table(table));
}
