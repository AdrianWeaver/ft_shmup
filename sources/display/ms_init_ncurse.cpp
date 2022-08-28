/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_init_ncurse.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 08:52:25 by aweaver           #+#    #+#             */
/*   Updated: 2022/08/28 15:55:25 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ostream>
#include <iostream>
#include <ncurses.h>

int	ft_init_screen(void **window)
{
	*window = initscr();
	if (*window == NULL)
		return (1);
	if (/*ft_initialise_data() ||*/ raw() || noecho()
			|| keypad((WINDOW*)*window, TRUE) || nodelay((WINDOW *)*window, TRUE))
	{
		endwin();
		delscreen((SCREEN *)*window);
		std::cout << "Screen initialization went wrong" << std::endl;
		exit (1);
	}
	curs_set(0);
	return (0);
}
