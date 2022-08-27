/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapons.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 21:22:07 by jtaravel          #+#    #+#             */
/*   Updated: 2022/08/27 21:35:12 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Weapon.hpp"

Weapon::Weapon(SpaceShip ally):SpaceShip(ally.get_X(), ally.get_Y())
{

}

Weapon::Weapon(Enemy enemy)
{
	(void)enemy;
}

Weapon::~Weapon(void)
{
	return ;
}
