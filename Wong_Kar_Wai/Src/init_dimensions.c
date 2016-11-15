/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dimensions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaddef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 12:17:21 by jnaddef           #+#    #+#             */
/*   Updated: 2016/01/31 15:47:30 by jnaddef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

t_dimensions	*init_dimensions(void)
{
	t_dimensions	*init_dim;

	init_dim = (struct s_dimensions*)malloc(sizeof(struct s_dimensions));
	if (init_dim == NULL)
		exit(1);
	getmaxyx(stdscr, init_dim->y, init_dim->x);
	return (init_dim);
}
