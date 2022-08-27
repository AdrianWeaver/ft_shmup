/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpaceShip.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 11:04:04 by jtaravel          #+#    #+#             */
/*   Updated: 2022/08/27 20:57:08 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shmup.hpp"
#include <ncurses.h>

SpaceShip::SpaceShip(void):_x(0),_y(0)
{
	return ;
}

SpaceShip::SpaceShip(int x, int y):_x(x),_y(y)
{
	return ;
}

SpaceShip::~SpaceShip(void)
{
	return ;
}

int	SpaceShip::get_X(void) const
{
	return (_x);
}

int	SpaceShip::get_Y(void) const
{
	return (_y);
}

void	SpaceShip::movement(int input)
{

	if (input == KEY_DOWN && _x + 1 < LINES)
		_x = get_X() + 1;
	if (input == KEY_UP && _x - 1 > 0)
		_x = get_X() - 1;
	if (input == KEY_LEFT && _y - 1 > 0)
		_y = get_Y() - 2;
	if (input == KEY_RIGHT && _y + 1 < COLS)
		_y = get_Y() + 2;
	if (input == KEY_SPACE)
	{
		Missiles shoot(*this);
		shoot.get_X_M(*this);
		shoot.get_Y_M(*this);
		//std::cerr << "test x = " << shoot.get_X_M(*this) << std::endl;
		//std::cerr << "test y = " << shoot.get_Y_M(*this) << std::endl;
	}
	// gerer si sapceship sur bord !
}
