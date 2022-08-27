/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spawn_enemies.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:53:59 by aweaver           #+#    #+#             */
/*   Updated: 2022/08/27 19:35:09 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shmup.hpp"
#include <vector>

int ft_spawn_phase_1(t_data *game)
{
	int	decision;

	std::srand(time(NULL));
	decision = rand() % 2 + 1;
	//if ((game->loop % (60 * 4) == 0) && g_enemies.size() <= 10)
		//g_enemies.push_back(Enemy(STAY));
	//if ((game->loop % (60 * 8) == 0) && g_enemies.size() <= 10)
		g_enemies.push_back(Enemy(PUSHER));
	//if ((game->loop % (60 * 8) == 0) && g_enemies.size() <= 10)
	//{
		//if (decision == 1)
			//g_enemies.push_back(Enemy(PATROL));
		//else
			//g_enemies.push_back(Enemy(PATROL_Z));
	//}
	return (0);
	(void)game;
}

int ft_spawn_phase_2(t_data *game)
{
	if ((game->loop % (60 * 5) == 0) && g_enemies.size() <= 10)
		g_enemies.push_back(Enemy(STAY));
	return (0);
}

int ft_spawn_phase_3()
{

	return (0);
}

int	ft_spawn_mobs(t_data &game)
{
	if (game.phase == 1)
		ft_spawn_phase_1(&game);
	if (game.phase == 2)
		ft_spawn_phase_2(&game);
	if (game.phase == 3)
		ft_spawn_phase_3();
	return (0);
}