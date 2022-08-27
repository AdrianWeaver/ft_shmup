/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpaceShip.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 11:04:04 by jtaravel          #+#    #+#             */
/*   Updated: 2022/08/27 12:16:58 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SpaceShip.hpp"
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
	if (input == KEY_DOWN)
		_x = get_X() + 1;
	if (input == KEY_UP)
		_x = get_X() - 1;
	if (input == KEY_LEFT)
		_y = get_Y() - 1;
	if (input == KEY_RIGHT)
		_y = get_Y() + 1;
	// gerer si sapceship sur bord !
}
