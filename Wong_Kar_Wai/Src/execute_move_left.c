/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_move_left.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 15:48:05 by fhenry            #+#    #+#             */
/*   Updated: 2016/01/31 23:20:59 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static int		**rewrite_in_table(int **table, int *chaine, int ligne)
{
	int			i;

	i = 0;
	while (i < SIZE)
	{
		table[ligne][i] = chaine[i];
		i++;
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

	i = 0;
	while (i < SIZE - 1)
	{
		i++;
		if (chaine[i] != 0 && chaine[i - 1] == 0)
		{
			chaine = swap(chaine, i);
			*move_done = 1;
		}
	}
	return (chaine);
}

static int		*load_chaine(int *chaine, int **table, int ligne,
		int *move_done)
{
	int			i;

	i = 0;
	while (i < SIZE)
	{
		chaine[i] = table[ligne][i];
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

int				**execute_move_left(int **table)
{
	int			*chaine;
	int			i;
	int			ligne;
	int			move_done;

	move_done = 0;
	i = 0;
	ligne = 0;
	if (!(chaine = (int *)malloc(sizeof(int) * SIZE)))
		return (NULL);
	while (i < SIZE)
	{
		chaine = load_chaine(chaine, table, ligne, &move_done);
		chaine = merge_top_left(chaine, &move_done);
		chaine = ask_for_swap(chaine, &move_done);
		rewrite_in_table(table, chaine, ligne);
		i++;
		ligne++;
	}
	if (move_done)
		table = add_rand(table);
	return (table);
}
