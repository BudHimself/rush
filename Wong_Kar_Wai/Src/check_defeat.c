/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_defeat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaddef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 22:12:17 by jnaddef           #+#    #+#             */
/*   Updated: 2016/01/31 23:06:54 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	static	is_full(int **grid)
{
	int	i;
	int	j;

	i = 0;
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE)
		{
			if (grid[i][j] == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	static	is_merge_possible(int **grid)
{
	int i;
	int j;

	i = 0;
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE)
		{
			if ((i > 0 && grid[i][j] == grid[i - 1][j])
				|| (i < SIZE - 1 && grid[i][j] == grid[i + 1][j])
				|| (j > 0 && grid[i][j] == grid[i][j - 1])
				|| (j < SIZE - 1 && grid[i][j] == grid[i][j + 1]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void		check_defeat(int **grid, WINDOW *vin)
{
	if (is_full(grid) == 1 && is_merge_possible(grid) == 0)
	{
		mvwprintw(vin, 20, 20, "Game Over");
		sleep(2);
		exit(0);
	}
}
