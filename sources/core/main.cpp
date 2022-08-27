/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 22:09:33 by aweaver           #+#    #+#             */
/*   Updated: 2022/08/27 15:02:02 by jtaravel         ###   ########.fr       */
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
	std::srand(time(NULL));
	SpaceShip Ship(5,4);
	Enemy	enemy(10, 95);
	if (ft_init_screen(&window) == 1)
	{
		std::cout << "Screen initialization went wrong" << std::endl;
		return (0);
	}
	while (1)
	{
		key = getch();
		if (key == KEY_ESC || key == 3)
			break;
		Ship.movement(key);
		enemy.movement_E();
		clear();
		mvprintw(Ship.get_X(), Ship.get_Y(), ">>|=>");
		mvprintw(enemy.get_X_E(), enemy.get_Y_E(), "<=||<<");
		printw("\nx = %d, y = %d key = %d\n", Ship.get_X(), Ship.get_Y(), key);
		//printw("x = %d, y = %d\n", enemy.get_X_E(), enemy.get_Y_E());
		refresh();			/* Print it on to the real screen */
		getch();			/* Wait for user input */
		std::this_thread::sleep_for(std::chrono::duration<double, std::ratio<1,24>>(1));
	}
	endwin();			/* End curses mode  */
	return 0;
}
