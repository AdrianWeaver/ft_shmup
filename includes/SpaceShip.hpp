/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SpaceShip.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 11:01:04 by jtaravel          #+#    #+#             */
/*   Updated: 2022/08/27 14:40:54 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPACESHIP_HPP

#define SPACESHIP_HPP

#include <string>
#include <iostream>

class	SpaceShip
{
	private:
		int	_x;
		int	_y;
	public:
		SpaceShip(void);
		SpaceShip(int x, int y);
		~SpaceShip(void);
		int	get_X(void) const;
		int	get_Y(void) const;
		void	movement(int input);
};

#endif
