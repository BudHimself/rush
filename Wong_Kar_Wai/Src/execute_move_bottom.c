/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_move_bottom.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 16:37:52 by fhenry            #+#    #+#             */
/*   Updated: 2016/01/31 22:13:33 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static int		**rewrite_in_table(int **table, int *chaine, int colone)
{
	int			l;

	l = 0;
	while (l < SIZE)
	{
		table[l][colone] = chaine[l];
		l++;
	}
	return (table);
}

static int		*swap(int *chaine, int index)
{
	int			tmp;

	tmp = chaine[index];
	chaine[index] = chaine[index - 1];
	chaine[index - 1] = tmp;
	return (chaine);
}

static int		*ask_for_swap(int *chaine, int *move_done)
{
	int			i;

	i = SIZE;
	while (i > 0)
	{
		i--;
		if (chaine[i - 1] != 0 && chaine[i] == 0)
		{
			chaine = swap(chaine, i);
			*move_done = 1;
		}
	}
	return (chaine);
}

static int		*load_chaine(int *chaine, int **table, int colone,
		int *move_done)
{
	int			i;

	i = 0;
	while (i < SIZE)
	{
		chaine[i] = table[i][colone];
		i++;
	}
	i = 0;
	while (i < SIZE)
	{
		chaine = ask_for_swap(chaine, move_done);
		i++;
	}
	return (chaine);
}

int				**execute_move_bottom(int **table)
{
	int			*chaine;
	int			i;
	int			colone;
	int			move_done;

	move_done = 0;
	i = 0;
	colone = 0;
	if (!(chaine = (int *)malloc(sizeof(int) * SIZE)))
		return (NULL);
	while (i < SIZE)
	{
		chaine = load_chaine(chaine, table, colone, &move_done);
		chaine = merge_bot_right(chaine, &move_done);
		chaine = ask_for_swap(chaine, &move_done);
		rewrite_in_table(table, chaine, colone);
		i++;
		colone++;
	}
	if (move_done)
		table = add_rand(table);
	return (table);
}
