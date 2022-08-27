/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Missiles.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 18:00:27 by jtaravel          #+#    #+#             */
/*   Updated: 2022/08/27 21:21:01 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Missiles.hpp"

Missiles::Missiles(SpaceShip ally)
{
	_dir = ALLY;
	_x = ally.get_X();
	_y = ally.get_Y();
}

Missiles::Missiles(Enemy enemy)
{
	_dir = ENEMY;
	_x = enemy.get_X_E();
	_y = enemy.get_Y_E();
}

Missiles::~Missiles(void)
{
	return ;
}

int	Missiles::get_X_M(SpaceShip ally)
{
	_x = ally.get_X();
	return (_x);
}

int	Missiles::get_Y_M(SpaceShip ally)
{
	_y = ally.get_Y();
	return (_y);
}

int	Missiles::get_X_M(Enemy enemy)
{
	_x = enemy.get_X_E();
	return (_x);
}

int	Missiles::get_Y_M(Enemy enemy)
{
	_y = enemy.get_Y_E();
	return (_y);
}
