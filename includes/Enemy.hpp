/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 12:20:44 by jtaravel          #+#    #+#             */
/*   Updated: 2022/08/27 23:13:44 by jtaravel         ###   ########.fr       */
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
		int	_type;
		int	_pm;
		int	_pa;
		//int	_hp;
		int	_speed;	// frame per movement
		int	_x_start;
		int	_y_start;
	public:
		Enemy(void);
		Enemy(int type);
		Enemy(int x, int y, int type);
		virtual ~Enemy(void);
		void	movement_E(void);
		int	get_X_E(void);
		int	get_Y_E(void) const;
		void	set_X_E(int x);
		void	set_Y_E(int y);
		void	setType(int type);
};

#endif
