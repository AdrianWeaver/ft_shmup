/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 22:09:33 by aweaver           #+#    #+#             */
/*   Updated: 2022/08/28 16:01:33 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include <thread>
#include <chrono>
#include <vector>
#include "ft_shmup.hpp"

std::vector<Enemy>		g_enemies;
std::vector<SpaceShip>	g_allies;
std::vector<Pusher>		g_pusher;
std::vector<Objects>	g_objs;
std::vector<Missiles>	g_missiles;
std::vector<Weapon>	g_weapon;

int	ft_turn(void *&window, int key)
{
	clear();
	(void)key;
	for (size_t i = 0; i < g_allies.size(); i++)
	{
		g_allies[i].action(key, window);
		//if (g_allies[i].get_Y() == g_enemies[i].get_Y() && g_enemies[i].get_X() == g_allies[i].get_X())
			//return (1);
	}
	for (size_t i = 0; i < g_weapon.size(); i++)
	{
		g_weapon[i].action(window);
	}
	for (size_t i = 0; i < g_pusher.size(); i++)
	{
		g_pusher[i].action(window);
		//if (g_allies[i].get_Y() == g_enemies[i].get_Y() && g_enemies[i].get_X() == g_allies[i].get_X())
			//return (1);
		//mvwprintw((WINDOW *)window, g_enemies[i].get_X(), g_enemies[i].get_Y(), "<===<");
	}

	refresh();
	return (0);
}

/*void	ft_display_objs(void *&window, t_data *game)
{
	(void)game;
	for (size_t i = 0; i < g_objs.size(); i++)
	{
		mvwaddch((WINDOW *)window, g_objs[i].get_X_O(), g_objs[i].get_Y_O(), g_objs[i].get_S());
	}
	refresh();
}*/

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
	std::srand(time(NULL));
	if (ft_init_screen(&window) == 1)
		return (0);
	g_allies.emplace_back(SpaceShip(5,4));
//	g_objs.push_back(Objects(STAR));
//	Enemy	enemy;
//	e_list.push_back(enemy);
//	Enemy	enemy2;
	game.loop = 0;
	game.phase = 1;
	while (1)
	{
		ft_spawn_mobs(game);
		//ft_spawn_objs(&game);
		if (ft_turn(window, key))
			break;
		key = getch();
		if (key == KEY_ESC || key == 3)
			break;
		//ft_display_objs(window, &game);
		//Ship.movement(key);
		//mvwprintw((WINDOW *)window, 0, 0, " Weapon_x = %d Weapon y = %d\n", weapon.get_X(), weapon.get_Y());
		//enemy2.movement_E();
		//mvwprintw((WINDOW *)window, enemy.get_X(), enemy.get_Y(), "<=||<<");
		//mvwprintw((WINDOW *)window, enemy2.get_X(), enemy2.get_Y(), "<=||<<");
		refresh();			/* Print it on to the real screen */
		getch();			/* Wait for user input */
		std::this_thread::sleep_for(std::chrono::duration<double, std::ratio<1,30>>(1));
		game.loop++;
	}
	endwin();			/* End curses mode  */
	return 0;
}
