/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpaceShip.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 11:04:04 by jtaravel          #+#    #+#             */
/*   Updated: 2022/08/27 23:35:41 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shmup.hpp"
#include <ncurses.h>
#include <chrono>
#include <thread>

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

void	SpaceShip::set_X(int x)
{
	_x = x;
}

void	SpaceShip::set_Y(int y)
{
	_y = y;
}

void	ft_shoot(int x, int y, void *&window)
{
	while (y < 120)
	{
		mvwaddch((WINDOW *)window, x, y, '-');
		y++;
	}
		//clear();
}

void	SpaceShip::movement(int input, void *&window)
{

	if (input == KEY_DOWN && _x + 1 < LINES)
		this->set_X(get_X() + 1);
	if (input == KEY_UP && _x - 1 > 0)
		this->set_X(get_X() - 1);
	if (input == KEY_LEFT && _y - 1 > 0)
		this->set_Y(get_Y() - 2);
	if (input == KEY_RIGHT && _y + 1 < COLS)
		this->set_Y(get_Y() + 2);
	if (input == KEY_SPACE)
	{
		ft_shoot(get_X(), get_Y(), window);
	}
}
