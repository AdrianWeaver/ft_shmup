/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Boss.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 22:00:43 by aweaver           #+#    #+#             */
/*   Updated: 2022/08/28 23:36:49 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shmup.hpp"
#include "Boss.hpp"

Boss::Boss(void)
{
	this->_pa_cost = PUSHER_PA;
	this->_pm_cost = PUSHER_PM;
}

Boss::~Boss(void)
{
	return ;
}

void	Boss::boss_shoot(void)
{
	this->_pa -= this->_pa_cost;
	g_missiles.emplace_back(Missiles(_x, _y));
	g_missiles.emplace_back(Missiles(_x + 1, _y));
	g_missiles.emplace_back(Missiles(_x + 2, _y));
}

void	Boss::boss_display(void *window)
{
	mvwprintw((WINDOW *)window, this->_x, this->_y, "%s", BOSS_SHAPE_1);
	mvwprintw((WINDOW *)window, this->_x + 1, this->_y, "%s", BOSS_SHAPE_2);
	mvwprintw((WINDOW *)window, this->_x + 2, this->_y, "%s", BOSS_SHAPE_3);
	mvwprintw((WINDOW *)window, this->_x + 2, this->_y, "%s", BOSS_SHAPE_3);
	mvwprintw((WINDOW *)window, this->_x + 2, this->_y, "%s", BOSS_SHAPE_3);
	mvwprintw((WINDOW *)window, this->_x, this->_y, "%c", "B");
	mvwprintw((WINDOW *)window, this->_x + 1, this->_y, "%c", "B");
	mvwprintw((WINDOW *)window, this->_x + 2, this->_y, "%c", "B");
	mvwprintw((WINDOW *)window, this->_x, this->_y + 1, "%c", "B");
	mvwprintw((WINDOW *)window, this->_x + 1, this->_y + 2, "%c", "B");
	mvwprintw((WINDOW *)window, this->_x + 2, this->_y, "%c", "B");
	mvwprintw((WINDOW *)window, this->_x, this->_y, "%c", "B");
	mvwprintw((WINDOW *)window, this->_x + 1, this->_y, "%c", "B");
	mvwprintw((WINDOW *)window, this->_x + 2, this->_y, "%c", "B");
}

void	Boss::boss_action(void *&window)
{
	generate_pa_pm();
	if (this->_pa >= this->_pa_cost)
		boss_shoot();
	if (this->_pm >= this->_pm_cost)
		boss_movement();
	this->boss_display(window);
}

void	Boss::boss_movement(void)
{
	if (_pm >= _pm_cost) {
		--_y;
		_pm -= _pm_cost;
	}
}

void	Boss::movement(void)
{
	if (_pm >= _pm_cost)
	{
		--_y;
		_pm -= _pm_cost;
	}
	return ;
}

void	Boss::shoot()
{
}
