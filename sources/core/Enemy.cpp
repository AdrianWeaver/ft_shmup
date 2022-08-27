/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 12:25:52 by jtaravel          #+#    #+#             */
/*   Updated: 2022/08/27 14:38:05 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

Enemy::Enemy(void)
{
	return ;
}

Enemy::Enemy(int x, int y)
{
	_x = x;
	_y = y;
	//std::cout << "test = " << _x << std::endl;
}

Enemy::~Enemy(void)
{
	return ;
}

int	Enemy::get_X_E(void) const
{
	//int	random = 0;

	//std::srand(time(NULL));
	//random = std::rand() % 2 + 1;
	return _x;
	
}

int	Enemy::get_Y_E(void) const
{
	return (_y - 1);
}

void	Enemy::movement_E(void)
{
	_x = get_X_E();
	_y = get_Y_E();
}
