/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_victory.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaddef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 22:47:12 by jnaddef           #+#    #+#             */
/*   Updated: 2016/01/31 23:37:33 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int		is_power_two(int i)
{
	if (i < 2)
		return (0);
	while (i != 1)
	{
		if (i % 2 == 1)
			return (0);
		i /= 2;
	}
	return (1);
}

void	check_victory(int **grid, WINDOW *vin, int *vic)
{
	int	i;
	int j;
	int	ch;

	if (!is_power_two(WIN_VALUE))
		return ;
	i = 0;
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE)
		{
			if (grid[i][j] == WIN_VALUE)
			{
				ch = wgetch(vin);
				if (ch == 89)
					*vic = 1;
				else
					exit(0);
			}
			j++;
		}
		i++;
	}
}
