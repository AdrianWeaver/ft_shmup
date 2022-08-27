/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 22:09:33 by aweaver           #+#    #+#             */
/*   Updated: 2022/08/27 12:55:55 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ostream>
#include <ncurses.h>
#include <thread>
#include <chrono>
#include "ft_shmup.hpp"

int	main(void)
{
	void	*window;
	int		key;
	int		x;
	int		y;

	x = 10;
	y = 10;
	if (ft_init_screen(&window) == 1)
	{
		std::cout << "Screen initialization went wrong" << std::endl;
		return (0);
	}
	while (1)
	{
		key = wgetch((WINDOW *)window);
		if (key != ERR && (key == KEY_ESC || key == KEY_CTRL_C || key == KEY_CTRL_D))
			break;
		if (key != ERR && (key == KEY_DOWN))
			x++;
		if (key != ERR && (key == KEY_UP))
			x--;
		if (key != ERR && (key == KEY_LEFT))
			y+= 2;
		if (key != ERR && (key == KEY_RIGHT))
			y+= 2;
		clear();
		mvprintw(x,y, ">>|=>");
		refresh();
		std::this_thread::sleep_for(std::chrono::duration<double, std::ratio<1,24>>(1));
	}
	endwin();
	return (0);
}
