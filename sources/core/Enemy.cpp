/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 12:25:52 by jtaravel          #+#    #+#             */
/*   Updated: 2022/08/27 23:26:06 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shmup.hpp"

Enemy::Enemy(void)
{
	std::srand(time(NULL));
	_x = rand() % LINES - 10;
	_y = COLS - 5;
	_type = rand() % 7 + 1;
	_x_start = _x;
	_y_start = _y;
	_pm = 1;
	_pa = 1;
	_speed = 0;
	return ;
}

Enemy::Enemy(int type):_x(0),_y(0)
{
	_type = type;
	std::srand(time(NULL));
	_x = rand() % LINES - 10;
	_y = COLS - 6;
	//_type = rand() % 7 + 1;
	_x_start = _x;
	_y_start = _y;
	_pm = 1;
	_pa = 1;
	_speed = 0;
	return ;
}

Enemy::Enemy(int x, int y, int type)
{
	_x = x;
	_y = y;
	_type = type;
}

Enemy::~Enemy(void)
{
	return ;
}

int	Enemy::get_X_E(void)
{
	//int	random = 0;

	//std::srand(time(NULL));
	//random = std::rand() % 2 + 1;
	if (_type == STAY)
		return (_x);
	if (_pm >= _speed)
	{
		if (_type == PUSHER)
			return _x;
		if (_type == PATROL && _x >= _x_start - 8)
			return (_x - 1);
		else if (_type == PATROL && _x < _x_start - 8)
			this->setType(PATROL_DOWN);
		if (_type == PATROL_DOWN && _x <= _x_start + 8)
			return (_x + 1);
		else if (_type == PATROL_DOWN && _x > _x_start + 8)
			this->setType(PATROL);
	}
	return (_x);
	
}

void	Enemy::setType(int type)
{
	_type = type;
}

int	Enemy::get_Y_E(void) const
{
	if (_type == STAY)
		return (_y);
	if (_type == PUSHER)
		return (_y - 2);
	if (_type == PATROL)
		return (_y);
	return (_y);
}

void	Enemy::set_X_E(int x)
{
	_x = x;
}

void	Enemy::set_Y_E(int y)
{
	_y = y;
}

void	Enemy::movement_E(void)
{
	this->set_X_E(get_X_E());
	this->set_Y_E(get_Y_E());
}
