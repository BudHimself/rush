/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaddef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 14:31:38 by jnaddef           #+#    #+#             */
/*   Updated: 2016/06/02 03:55:27 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

char				***process_input(int chr, char ***grid)
{
	int				**table;

	if (chr == KEY_RESIZE)
		return (grid);
	table = atoi_table(grid);
	if (chr == KEY_LEFT)
		return (itoa_table(execute_move(LEFT, table)));
	if (chr == KEY_RIGHT)
		return (itoa_table(execute_move(RIGHT, table)));
	if (chr == KEY_DOWN)
		return (itoa_table(execute_move(BOTTOM, table)));
	if (chr == KEY_UP)
		return (itoa_table(execute_move(TOP, table)));
	if (chr == 27)
	{
		endwin();
		exit(0);
	}
	return (grid);
}

int					main(void)
{
	WINDOW			*vin;
	char			***grid;
	t_dimensions	*window_dimensions;
	int				chr;
	int				vic;

	vic = 0;
	grid = init_table(SIZE);
	vin = init_window();
	window_dimensions = init_dimensions();
	draw_window(vin, grid);
	while ((chr = wgetch(vin)))
	{
		grid = process_input(chr, grid);
		draw_window(vin, grid);
		if (vic == 0)
			check_victory(atoi_table(grid), vin, &vic);
		check_defeat(atoi_table(grid), vin);
	}
	return (0);
}
