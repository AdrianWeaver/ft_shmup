/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpaceShip.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 11:01:04 by jtaravel          #+#    #+#             */
/*   Updated: 2022/08/27 23:02:54 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPACESHIP_HPP

#define SPACESHIP_HPP

#include <string>
#include <iostream>

class	SpaceShip
{
	protected:
		int	_x;
		int	_y;
		//int	_weapon_type;
		//int	_weapon_dmg;
		//int	_weapon_speed; //fpm
	public:
		SpaceShip(void);
		SpaceShip(int x, int y);
		~SpaceShip(void);
		int	get_X(void) const;
		int	get_Y(void) const;
		void	set_X(int x);
		void	set_Y(int y);
		void	movement(int input, void *&window);
		//void	ft_shoot(int x, int y, void *&window);
};

#endif
