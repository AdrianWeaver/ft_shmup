/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoudni <omoudni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 22:09:33 by aweaver           #+#    #+#             */
/*   Updated: 2022/08/28 18:51:30 by omoudni          ###   ########.fr       */
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
std::vector<Patrol>	g_patrol;

void	ft_background(void *window)
{
	for (size_t i = 0; i < g_objs.size(); i++)
	{
		g_objs[i].aff_obj();
		mvwaddch((WINDOW *)window, g_objs[i].get_X_O(), g_objs[i].get_Y_O(), g_objs[i].get_S() | COLOR_PAIR(g_objs[i].get_C() | A_BOLD));
	}
	refresh();
}

int	ft_turn(void *&window, int key, t_data *game)
{
	clear();
	(void)key;
	for (size_t i = 0; i < g_allies.size(); i++)
	{
		g_allies[i].action(key, window);
		for (size_t i = 0; i < g_pusher.size(); i++)
		{
			if (g_allies[0].get_Y() == g_pusher[i].get_Y() && g_pusher[i].get_X() == g_allies[0].get_X())
				return (1);
		}
	}
	for (size_t i = 0; i < g_weapon.size(); i++)
	{
		g_weapon[i].action(window);
		for (size_t j = 0; j < g_pusher.size(); j++)
		{
			if (g_weapon[i].get_Y() == g_pusher[j].get_Y() && g_pusher[j].get_X() == g_weapon[i].get_X())
			{
				g_weapon.erase(g_weapon.begin() + j);
				g_pusher.erase(g_pusher.begin() + j);
				game->score += 5;
				game->frags += 1;
			}
		}
		for (size_t j = 0; j < g_patrol.size(); j++)
		{
			if (g_weapon[i].get_Y() == g_patrol[j].get_Y() && g_patrol[j].get_X() == g_weapon[i].get_X())
			{
				g_weapon.erase(g_weapon.begin() + j);
				g_patrol.erase(g_patrol.begin() + j);
				game->score += 10;
				game->frags += 1;
			}
		}
	}
	for (size_t i = 0; i < g_pusher.size(); i++)
	{
		g_pusher[i].action(window);
	}
	for (size_t i = 0; i < g_patrol.size(); i++)
	{
		g_patrol[i].action(window);
		if ((game->loop % (60 * 4) == 0))
			g_patrol[i].go_front(window);
	}
	refresh();
//	wrefresh(window);
	return (0);
}

int	ft_menu(void *window)
{
	int	ch;

	cbreak();
	mvwprintw((WINDOW *)window, 0, COLS / 2 - 29, "/*");
	mvwprintw((WINDOW *)window, 1, COLS / 2 - 29, " *       __  _              _                              ");
	mvwprintw((WINDOW *)window, 2, COLS / 2 - 29, " *      / _|| |_       ___ | |__   _ __ ___   _   _  _ __  ");
	mvwprintw((WINDOW *)window, 3, COLS / 2 - 29, " *     | |_ | __|     / __|| '_ \\ | '_ ` _ \\ | | | || '_ \\ ");
	mvwprintw((WINDOW *)window, 4, COLS / 2 - 29, " *     |  _|| |_      \\__ \\| | | || | | | | || |_| || |_) |");
	mvwprintw((WINDOW *)window, 5, COLS / 2 - 29, " *     |_|   \\__|     |___/|_| |_||_| |_| |_| \\__,_|| .__/ ");
	mvwprintw((WINDOW *)window, 6, COLS / 2 - 29, " *                                                 |_|    ");
	mvwprintw((WINDOW *)window, 7, COLS / 2 - 29, " */");
	mvwprintw((WINDOW *)window, LINES / 2, COLS / 2 - 12,"press ENTER to continue");
	refresh();
	mvwprintw((WINDOW *)window, LINES / 2 + 1, COLS / 2 - 12,"press ESC to quit");
	refresh();
	while ((ch = getch()))
	{
		printf("%d\n", ch);
	if (ch == KEY_ESC)
		return (-1);
	if (ch == 10)
		return (0);
	}
	return (0);
}

void	ft_aff_ath(void *window, t_data game)
{
	(void)game;
	for (int i = 0; i <= COLS; i++)
		mvwprintw((WINDOW *)window, 10, i, "_");
	mvwprintw((WINDOW *)window, 5, 20, "Level Phase: %d\n", game.phase);
	mvwprintw((WINDOW *)window, 6, 20, "Frags: %d\n", game.frags);
	mvwprintw((WINDOW *)window, 5, 60, "SCORE: %d\n", game.score);
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

	window = NULL; 
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
	//g_objs.push_back(objs);

	if (ft_menu(window))
		return (endwin(), 0);
	raw();
	noecho();
	nodelay((WINDOW *)window, TRUE);
	keypad(stdscr, TRUE);
	//g_allies.push_back(Ship);
	//g_allies.push_back(Weapon(Ship));
	game.loop = 0;
	game.phase = 1;
	game.score = 0;
	game.frags = 0;
	while (1)
	{
		ft_spawn_mobs(game);
		ft_spawn_objs(&game);
		if (ft_turn(window, key, &game))
			break;
		ft_background(window);
		ft_aff_ath(window, game);
		key = getch();
		if (key == KEY_ESC || key == 3)
			break;
		refresh();			/* Print it on to the real screen */
		wrefresh((WINDOW *)window);
		getch();			/* Wait for user input */
		std::this_thread::sleep_for(std::chrono::duration<double, std::ratio<1,30>>(1));
		game.loop++;
	}
	endwin();			/* End curses mode  */
	return 0;
}
