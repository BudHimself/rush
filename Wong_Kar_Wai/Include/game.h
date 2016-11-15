/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 12:21:13 by fhenry            #+#    #+#             */
/*   Updated: 2016/01/31 23:16:59 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include <stdlib.h>
# include <time.h>
# include <ncurses.h>
# include <unistd.h>
# include "../libft/libft.h"

enum			e_const
{
	WIN_VALUE = 2048,
	SIZE = 4
};

typedef enum	e_move
{
	LEFT,
	RIGHT,
	TOP,
	BOTTOM,
	NO_MOVE
}				t_move;

typedef	struct	s_dimensions
{
	int	x;
	int	y;
}				t_dimensions;

char			***init_table(int size);
int				rand_num(void);
int				*merge_top_left(int *chaine, int *move_done);
int				*merge_bot_right(int *chaine, int *move_done);
WINDOW			*init_window();
t_dimensions	*init_dimensions(void);
char			***itoa_table(int **table);
int				**atoi_table(char ***grid);
int				**execute_move_top(int **table);
int				**execute_move_bottom(int **table);
int				**execute_move_right(int **table);
int				**execute_move_left(int **table);
int				**add_rand(int **table);
int				**execute_move(t_move move, int **table);
void			draw_window(WINDOW *vin, char ***grid);
void			check_victory(int **grid, WINDOW *vin, int *vic);
void			check_defeat(int **grid, WINDOW *vin);

#endif
