/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_top_left.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 17:37:14 by fhenry            #+#    #+#             */
/*   Updated: 2016/01/31 21:46:09 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int			*merge_top_left(int *chaine, int *move_made)
{
	int		i;

	i = 0;
	while (i < SIZE - 1)
	{
		i++;
		if (chaine[i] == chaine[i - 1])
		{
			chaine[i - 1] += chaine[i - 1];
			chaine[i] = 0;
			if (chaine[i - 1] != 0)
				*move_made = 1;
		}
	}
	return (chaine);
}
