/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pusher.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaravel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 16:00:13 by jtaravel          #+#    #+#             */
/*   Updated: 2022/08/27 16:14:56 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHER_HPP

#define PUSHER_HPP

#include "ft_shmup.hpp"

class	Pusher: public Enemy
{
	private:
		int	_dmg;
		int	_pm_cost;
	public:
		Pusher(int phase);
}

#endif
