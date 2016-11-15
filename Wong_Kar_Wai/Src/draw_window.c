/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 22:58:06 by fhenry            #+#    #+#             */
/*   Updated: 2016/01/31 23:09:42 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void			draw_column(int hauteur_case, int largeur_case, WINDOW *vin)
{
	int				i;
	int				j;

	i = -1;
	while (++i < SIZE * hauteur_case + 1)
	{
		if (i % (hauteur_case) == 0)
		{
			j = 0;
			while (j < SIZE * largeur_case + 1)
			{
				mvwprintw(vin, i, j, "_");
				j++;
			}
		}
	}
}

static void			draw_line(int hauteur_case, int largeur_case, WINDOW *vin)
{
	int				i;
	int				j;

	i = 0;
	while (i < SIZE * hauteur_case + 1)
	{
		j = 0;
		while (j < SIZE * largeur_case + 1)
		{
			if (j % (largeur_case) == 0)
				mvwprintw(vin, i, j, "|");
			j++;
		}
		i++;
	}
}

static void			draw_numbers(WINDOW *vin, char ***grid,
		int hauteur_case, int largeur_case)
{
	int				i;
	int				j;
	int				len;

	i = 0;
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE)
		{
			len = ft_strlen(grid[i][j]);
			if (ft_strcmp(grid[i][j], "0") == 0)
				j++;
			else
			{
				mvwprintw(vin, (i + 0.5) * hauteur_case, (j + 1) *
						largeur_case - len - 1, grid[i][j]);
				j++;
			}
		}
		i++;
	}
}

void				draw_window(WINDOW *vin, char ***grid)
{
	t_dimensions	dim;
	int				hauteur_case;
	int				largeur_case;

	getmaxyx(stdscr, dim.y, dim.x);
	hauteur_case = (dim.y - 1) / SIZE;
	largeur_case = (dim.x - 1) / SIZE;
	wresize(vin, dim.y, dim.x);
	wclear(stdscr);
	wclear(vin);
	draw_column(hauteur_case, largeur_case, vin);
	draw_line(hauteur_case, largeur_case, vin);
	draw_numbers(vin, grid, hauteur_case, largeur_case);
	wrefresh(vin);
}
