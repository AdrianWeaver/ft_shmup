/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 22:09:33 by aweaver           #+#    #+#             */
/*   Updated: 2022/08/27 19:45:44 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include <thread>
#include <chrono>
#include <vector>
#include "ft_shmup.hpp"

std::vector<Enemy>	g_enemies;

int	ft_display(void *&window, SpaceShip &Ship)
{
	clear();
	mvwprintw((WINDOW *)window, Ship.get_X(), Ship.get_Y(), ">>|=>");
	for (size_t i = 0; i < g_enemies.size(); i++)
	{
		g_enemies[i].movement_E();
		mvwprintw((WINDOW *)window, g_enemies[i].get_X_E(), g_enemies[i].get_Y_E(), "<===<");
	}
	refresh();
	return (0);
}

int	main(void)
{
	void	*window;
	int		key;
	int		x;
	int		y;
	t_data	game;

	x = 10;
	y = 10;
	if (ft_init_screen(&window) == 1)
		return (0);
	SpaceShip Ship(5,4);
	Enemy	enemy;
//	e_list.push_back(enemy);
	Enemy	enemy2;
	game.loop = 0;
	game.phase = 1;
	while (1)
	{
		ft_spawn_mobs(game);
		key = getch();
		if (key == KEY_ESC || key == 3)
			break;
		Ship.movement(key);
		//enemy2.movement_E();
		//mvwprintw((WINDOW *)window, enemy.get_X_E(), enemy.get_Y_E(), "<=||<<");
		//mvwprintw((WINDOW *)window, enemy2.get_X_E(), enemy2.get_Y_E(), "<=||<<");
		ft_display(window, Ship);
		refresh();			/* Print it on to the real screen */
		getch();			/* Wait for user input */
		std::this_thread::sleep_for(std::chrono::duration<double, std::ratio<1,60>>(1));
		game.loop++;
	}
	endwin();			/* End curses mode  */
	return 0;
}
