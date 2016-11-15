/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 18:23:48 by fhenry            #+#    #+#             */
/*   Updated: 2016/01/31 19:24:35 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int		**execute_move(t_move move, int **table)
{
	if (move == TOP)
		return (execute_move_top(table));
	else if (move == BOTTOM)
		return (execute_move_bottom(table));
	else if (move == LEFT)
		return (execute_move_left(table));
	else
		return (execute_move_right(table));
}
