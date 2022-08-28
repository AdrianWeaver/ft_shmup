/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapons.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 21:22:07 by jtaravel          #+#    #+#             */
/*   Updated: 2022/08/28 14:26:58 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Weapon.hpp"

Weapon::Weapon(void): _pm(0)
{
	return ;
}

Weapon::Weapon(int x, int y, int dir): _pm(0), _shape('-')
{
	this->_x = x;
	this->_y = y;
	this->_dir = dir;
}

Weapon::~Weapon(void)
{
	return ;
}

void	Weapon::generate_pm(void)
{
	++this->_pm;
}

void	Weapon::movement(void)
{
	if (_pm >= _pm_cost)
	{
		++_y;
		_pm -= _pm_cost;
	}
	return ;
}

void	Weapon::action(void *&window)
{
	this->generate_pm();
	this->movement();
	this->display(window);
}
