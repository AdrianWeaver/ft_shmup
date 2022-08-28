/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpaceShip.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 11:01:04 by jtaravel          #+#    #+#             */
/*   Updated: 2022/08/28 12:28:17 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPACESHIP_HPP

#define SPACESHIP_HPP

#include <string>
#include <iostream>
#include "ft_shmup.hpp"
#include <ncurses.h>

class	SpaceShip
{
	protected:
		int	_x;
		int	_y;
		int	_dir;
		char _shape;
		//int	_weapon_type;
		//int	_weapon_dmg;
		//int	_weapon_speed; //fpm
		//void	display(void *&window)
		void	movement(int input);
		void	shoot(void);
		void	display(void *&window);
	public:
		SpaceShip(void);
		SpaceShip(int x, int y);
		virtual ~SpaceShip(void);
		int	get_X(void) const;
		int	get_Y(void) const;
		void	set_X(int x);
		void	set_Y(int y);
		virtual void	action(void *&window);
		virtual void	action(int input, void *&window);
};

#endif
