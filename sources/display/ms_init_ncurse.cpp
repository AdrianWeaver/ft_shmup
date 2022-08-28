/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_init_ncurse.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoudni <omoudni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 08:52:25 by aweaver           #+#    #+#             */
/*   Updated: 2022/08/28 18:50:44 by omoudni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ostream>
#include <iostream>
#include <ncurses.h>

int	ft_init_screen(void **window)
{
	*window = initscr();
	cbreak();
	keypad(stdscr, TRUE);
	refresh();
	if (*window == NULL)
		return (1);
	if (noecho())
	{
		endwin();
		delscreen((SCREEN *)*window);
		std::cout << "Screen initialization went wrong" << std::endl;
		exit (1);
	}
	curs_set(0);
	return (0);
}
