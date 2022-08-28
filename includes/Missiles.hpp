/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Missiles.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 17:52:56 by jtaravel          #+#    #+#             */
/*   Updated: 2022/08/28 20:22:40 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MISSILES_HPP
# define MISSILES_HPP

# include "ft_shmup.hpp"

class	Missiles: virtual public Pusher
{
	private:
		//int	_hp;
		//int	_speed;
		void	movement(void);
		void	generate_pm(void);
	public:
		Missiles(void);
		Missiles(int x, int y);
		~Missiles(void);
		void	action(void *&window);
};

#endif
