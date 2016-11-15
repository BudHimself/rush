/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_rand.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 17:48:59 by fhenry            #+#    #+#             */
/*   Updated: 2016/01/31 22:13:02 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void		rand_empty_case(int vide, int **table)
{
	int			c;
	int			l;
	int			case_vide;

	l = 0;
	case_vide = 0;
	while (l < 4)
	{
		c = 0;
		while (c < 4)
		{
			if (table[l][c] == 0)
			{
				if (case_vide == vide)
				{
					table[l][c] = rand_num();
					return ;
				}
				case_vide++;
			}
			c++;
		}
		l++;
	}
	return ;
}

static int		nbr_case_vide(int **table)
{
	int			c;
	int			l;
	int			case_vide;

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

static int		rand_case(int **table)
{
	int			i;
	int			vide;
	int			nb_empty;

	i = 0;
	srand(time(NULL));
	nb_empty = nbr_case_vide(table);
	if (nb_empty == 0)
		return (-1);
	vide = rand() % nb_empty;
	return (vide);
}

int				**add_rand(int **table)
{
	int			vide;

	vide = rand_case(table);
	if (vide != -1)
		rand_empty_case(vide, table);
	return (table);
}
