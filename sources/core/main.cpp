/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 22:09:33 by aweaver           #+#    #+#             */
/*   Updated: 2022/08/27 23:29:31 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include <thread>
#include <chrono>
#include <vector>
#include "ft_shmup.hpp"

std::vector<Enemy>	g_enemies;
std::vector<SpaceShip>	g_allies;

int	ft_display(void *&window, SpaceShip &Ship, int key)
{
	clear();
	for (size_t i = 0; i < g_allies.size(); i++)
	{
		(void)Ship;
		g_allies[i].movement(key, window);
		if (g_allies[i].get_Y() == g_enemies[i].get_Y_E() && g_enemies[i].get_X_E() == g_allies[i].get_X())
			return (1);
		mvwprintw((WINDOW *)window, g_allies[i].get_X(), g_allies[i].get_Y(), ">>|=>");
	}
	for (size_t i = 0; i < g_enemies.size(); i++)
	{
		g_enemies[i].movement_E();
		if (g_allies[i].get_Y() == g_enemies[i].get_Y_E() && g_enemies[i].get_X_E() == g_allies[i].get_X())
			return (1);
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
	key = 0;
	if (ft_init_screen(&window) == 1)
		return (0);
	SpaceShip Ship(5,4);
	g_allies.push_back(Ship);
	g_allies.push_back(Weapon(Ship));
//	Enemy	enemy;
//	e_list.push_back(enemy);
//	Enemy	enemy2;
	game.loop = 0;
	game.phase = 1;
	while (1)
	{
		ft_spawn_mobs(game);
		if (ft_display(window, Ship, key))
			break;
		key = getch();
		if (key == KEY_ESC || key == 3)
			break;
		//Ship.movement(key);
		//mvwprintw((WINDOW *)window, 0, 0, " Weapon_x = %d Weapon y = %d\n", weapon.get_X(), weapon.get_Y());
		//enemy2.movement_E();
		//mvwprintw((WINDOW *)window, enemy.get_X_E(), enemy.get_Y_E(), "<=||<<");
		//mvwprintw((WINDOW *)window, enemy2.get_X_E(), enemy2.get_Y_E(), "<=||<<");
		refresh();			/* Print it on to the real screen */
		getch();			/* Wait for user input */
		std::this_thread::sleep_for(std::chrono::duration<double, std::ratio<1,30>>(1));
		game.loop++;
	}
	endwin();			/* End curses mode  */
	return 0;
}
