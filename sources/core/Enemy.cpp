/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 12:25:52 by jtaravel          #+#    #+#             */
/*   Updated: 2022/08/28 14:31:20 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shmup.hpp"

Enemy::Enemy(void):_x (rand() & LINES - 10),_y (COLS),_dir (ENEMY)
{
	fprintf(stderr, "Enemy constructeur par defaut\n");
	//_x = rand() % LINES - 10;
	//_y = COLS;
	//_type = rand() % 7 + 1;
	_x_start = _x;
	_y_start = _y;
	_pm = 1;
	_pa = 1;
	return ;
}

Enemy::Enemy(int type):_x(0),_y(0)
{
	_type = type;
	_x = rand() % LINES;
	_y = COLS - 6;
	//_type = rand() % 7 + 1;
	_x_start = _x;
	_y_start = _y;
	_pm = 1;
	_pa = 1;
	return ;
}

Enemy::Enemy(const std::string &shape):_shape(shape)
{
	fprintf(stderr, "Enemy constructeur shape\n");
	_x = rand() % LINES;
	_y = COLS - 5;
	//_type = rand() % 7 + 1;
	_x_start = _x;
	_y_start = _y;
	_pm = 1;
	_pa = 1;
	return ;
}

Enemy::Enemy(int x, int y, int type)
{
	_x = x;
	_y = y;
	_shape = "o";
	_type = type;
}

Enemy::Enemy(const Enemy &src)
{
	*this = src;
}

Enemy::~Enemy(void)
{
	return ;
}

int	Enemy::get_X(void) const
{
	//int	random = 0;

	//std::srand(time(NULL));
	//random = std::rand() % 2 + 1;
	if (_type == STAY)
		return (_x);
	/* Why have a move in a get?
	if (_pm >= _pm_cost)
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
	}*/
	return (_x);
}

void	Enemy::setType(int type)
{
	_type = type;
}

int	Enemy::get_Y(void) const
{
	if (_type == STAY)
		return (_y);
	if (_type == PUSHER)
		return (_y - 2);
	if (_type == PATROL)
		return (_y);
	return (_y);
}

void	Enemy::set_X(int x)
{
	_x = x;
}

void	Enemy::set_Y(int y)
{
	_y = y;
}

void	Enemy::generate_pa_pm(void)
{
	fprintf(stderr, "Enemy generate_pa_pm pa = %d pm =%d pm_cost = %d\n", this->_pa, this->_pm, _pm_cost);
	this->_pa++;
	this->_pm++;
	fprintf(stderr, "Enemy after generate_pa_pm pa = %d pm =%d pm_cost = %d\n", this->_pa, this->_pm, this->_pm_cost);
}

void	Enemy::shoot(void)
{
	return ;
}

void	Enemy::display(void *&window)
{
	mvwprintw((WINDOW *)window, this->_x, this->_y, this->_shape.c_str());
}

void	Enemy::action(void *&window)
{
	fprintf(stderr, "Enemy action\n");
	generate_pa_pm();
	if (this->_pa >= this->_pa_cost)
		shoot();
	if (this->_pm >= this->_pm_cost)
		movement();
	this->display(window);
}

void	Enemy::movement(void)
{
	return ;
}
