/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 12:20:44 by jtaravel          #+#    #+#             */
/*   Updated: 2022/08/27 14:32:12 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP

#define ENEMY_HPP

#include <iostream>
#include <string>

class	Enemy
{
	private:
		int	_x;
		int	_y;
	public:
		Enemy(void);
		Enemy(int x, int y);
		~Enemy(void);
		void	movement_E(void);
		int	get_X_E(void) const;
		int	get_Y_E(void) const;
};

#endif
