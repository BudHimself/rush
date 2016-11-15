/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaddef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 17:42:41 by jnaddef           #+#    #+#             */
/*   Updated: 2016/01/31 17:49:25 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	**atoi_table(char ***grid)
{
	int	**table;
	int	i;
	int j;

	if (!(table = (int **)malloc(sizeof(int *) * SIZE)))
		return (NULL);
	i = 0;
	while (i < SIZE)
	{
		if (!(table[i] = (int *)malloc(sizeof(int) * SIZE)))
			return (NULL);
		j = 0;
		while (j < SIZE)
		{
			table[i][j] = ft_atoi(grid[i][j]);
			j++;
		}
		i++;
	}
	return (table);
}
