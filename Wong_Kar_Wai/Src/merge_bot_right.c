/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_bot_right.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 17:37:05 by fhenry            #+#    #+#             */
/*   Updated: 2016/01/31 21:46:38 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int			*merge_bot_right(int *chaine, int *move_made)
{
	int		i;

	i = SIZE - 1;
	while (i > 0)
	{
		i--;
		if (chaine[i] == chaine[i + 1])
		{
			chaine[i + 1] += chaine[i + 1];
			chaine[i] = 0;
			if (chaine[i + 1] != 0)
				*move_made = 1;
		}
	}
	return (chaine);
}
