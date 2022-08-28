/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Missiles.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 18:00:27 by jtaravel          #+#    #+#             */
/*   Updated: 2022/08/28 14:52:16 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_shmup.hpp"
#include "Missiles.hpp"

Missiles::Missiles(void)
{
	return ;
}

Missiles::Missiles(int x, int y)
{
	this->_x = x;
	this->_y = y;
}

Missiles::~Missiles(void)
{
	return ;
}
