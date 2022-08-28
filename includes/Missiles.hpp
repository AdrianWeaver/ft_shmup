/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Missiles.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 17:52:56 by jtaravel          #+#    #+#             */
/*   Updated: 2022/08/28 10:28:10 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MISSILES_HPP

#define MISSILES_HPP

#include "ft_shmup.hpp"

class	Missiles: public Enemy
{
	private:
		//int	_hp;
		//int	_speed;
		//int	_pm;
		//int	_pm;
	public:
		Missiles(void);
		Missiles(int x, int y);
		~Missiles(void);
};

#endif
