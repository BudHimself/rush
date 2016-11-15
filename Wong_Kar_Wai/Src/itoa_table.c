/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaddef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 13:57:28 by jnaddef           #+#    #+#             */
/*   Updated: 2016/01/31 22:23:49 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

char		***itoa_table(int **table)
{
	char	***grid;
	int		i;
	int		j;

	if (!(grid = (char ***)malloc(sizeof(char **) * SIZE)))
		return (NULL);
	i = 0;
	while (i < SIZE)
	{
		if (!(grid[i] = (char **)malloc(sizeof(char *) * SIZE)))
			return (NULL);
		j = 0;
		while (j < SIZE)
		{
			grid[i][j] = ft_itoa(table[i][j]);
			j++;
		}
		i++;
	}
	return (grid);
}
