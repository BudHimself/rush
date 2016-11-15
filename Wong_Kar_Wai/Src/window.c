/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnaddef <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 12:14:57 by jnaddef           #+#    #+#             */
/*   Updated: 2016/01/31 22:59:50 by fhenry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include <unistd.h>
#include "game.h"

WINDOW			*init_window(void)
{
	WINDOW		*vin;

	initscr();
	cbreak();
	noecho();
	curs_set(FALSE);
	vin = newwin(0, 0, 0, 0);
	keypad(vin, TRUE);
	return (vin);
}
