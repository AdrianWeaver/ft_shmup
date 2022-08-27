/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Missiles.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 17:52:56 by jtaravel          #+#    #+#             */
/*   Updated: 2022/08/27 18:45:24 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MISSILES_HPP

#define MISSILES_HPP

#include "ft_shmup.hpp"

class	Missiles
{
	private:
		//int	_hp;
		int	_x;
		int	_y;
		int	_dir;
		//int	_speed;
		//int	_pm;
		//int	_pm;
	public:
		Missiles(SpaceShip ally);
		Missiles(Enemy enemy);
		~Missiles(void);
		int	get_X_M(SpaceShip ally);
		int	get_Y_M(SpaceShip ally);
		int	get_X_M(Enemy enemy);
		int	get_Y_M(Enemy enemy);
};

#endif
