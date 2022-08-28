/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 22:09:33 by aweaver           #+#    #+#             */
/*   Updated: 2022/08/28 16:19:59 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include <thread>
#include <chrono>
#include <vector>
#include "ft_shmup.hpp"
#include <string.h>

std::vector<SpaceShip>	g_allies;
std::vector<Weapon>	g_weapon;
std::vector<Pusher>	g_pusher;
std::vector<Missiles>	g_missiles;
std::vector<Objects>	g_objs;

void	ft_background(void *window)
{
	for (size_t i = 0; i < g_objs.size(); i++)
	{
		g_objs[i].aff_obj();
		mvwaddch((WINDOW *)window, g_objs[i].get_X_O(), g_objs[i].get_Y_O(), g_objs[i].get_S() | COLOR_PAIR(g_objs[i].get_C() | A_BOLD));
	}
	//clear();
	refresh();
}

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

void	ft_aff_ath(void *window, t_data game)
{
	(void)game;
	for (int i = 0; i <= COLS; i++)
		mvwprintw((WINDOW *)window, 10, i, "_");
	mvwprintw((WINDOW *)window, 5, 20, "Level Phase: %d\n", game.phase);
	mvwprintw((WINDOW *)window, 6, 20, "Frags: A DEFINIR\n");
	mvwprintw((WINDOW *)window, 5, 60, "SCORE: A DEFINIR\n");
	int w = 60;
	const char *str = "CPP INVADER\n";
	for (int j = 0; j <= 11; j++)
	{
		mvwaddch((WINDOW *)window, 1, w, str[j] | COLOR_PAIR(RED_STAR) | A_BOLD);
		w++;
	}

}

int	main(void)
{
	void		*window;
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
	g_allies.emplace_back(SpaceShip(20, 20));
	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_YELLOW, COLOR_BLACK);
	init_pair(3, COLOR_BLUE, COLOR_BLACK);

	Objects objs(STAR);
	//g_allies.push_back(Weapon(Ship));
	g_objs.push_back(objs);

	game.loop = 0;
	game.phase = 1;
	while (1)
	{
		ft_spawn_mobs(game);
		ft_spawn_objs(&game);
		if (ft_turn(window, key))
			break;
		ft_background(window);
		ft_aff_ath(window, game);
		key = getch();
		if (key == KEY_ESC || key == 3)
			break;
		//Ship.movement(key);
		//mvwprintw((WINDOW *)window, 0, 0, "%d\n", key);
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
