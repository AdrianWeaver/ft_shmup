/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 21:05:54 by jtaravel          #+#    #+#             */
/*   Updated: 2022/08/27 21:31:50 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP

#define WEAPON_HPP

#include "ft_shmup.hpp"

class	Weapon: public SpaceShip 
{
	protected:
		int	_x;
		int	_y;
		//int	_hp;
		//int	_speed;
		//int	_pm;
		//int	_pm;
	public:
		Weapon(SpaceShip ally);
		Weapon(Enemy enemy);
		~Weapon(void);
		int	get_X_M(SpaceShip ally);
		int	get_Y_M(SpaceShip ally);
		int	get_X_M(Enemy enemy);
		int	get_Y_M(Enemy enemy);
};

#endif
