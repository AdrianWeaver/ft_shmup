/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pusher.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 08:45:38 by aweaver           #+#    #+#             */
/*   Updated: 2022/08/28 14:21:48 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shmup.hpp"
#include "Pusher.hpp"
#include "Pusher.hpp"

Pusher::Pusher(void): Enemy("<")
{
	fprintf(stderr, "Pusher constructeur defaut\n");
	this->_shape = "<";
	this->_pa_cost = PUSHER_PA;
	this->_pm_cost = PUSHER_PM;
}

Pusher::~Pusher(void)
{
	return ;
}

/*void	Pusher::action(void *&window)
{
	generate_pa_pm();
	if (this->_pa >= this->_pa_cost)
		ft_shoot(get_X(), get_Y(), window);
	if (this->_pm >= this->_pm_cost)
		movement();
}*/

void	Pusher::shoot(void)
{
	g_enemies.emplace_back(Missiles());
	return ;
}

void	Pusher::movement(void)
{
	fprintf(stderr, "Pusher move entered\n");
	if (this->_pm >= this->_pm_cost)
	{
		--this->_y;
		this->_pm -= this->_pm_cost;
		fprintf(stderr, "Pusher move: _pm = %d _pm_cost = %d\n", this->_pm, this->_pm_cost);
	}
	return ;
}
