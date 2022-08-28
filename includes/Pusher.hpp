/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pusher.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:00:13 by jtaravel          #+#    #+#             */
/*   Updated: 2022/08/28 14:11:32 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHER_HPP

#define PUSHER_HPP

#include "ft_shmup.hpp"

class	Pusher:public Enemy
{
	private:
		int		_dmg;
		std::string	_shape;
		void	shoot(void);
		void	movement(void);
	public:
		Pusher(void);
		Pusher(int phase);
		Pusher(int x, int y);
		~Pusher(void);
};

#endif
