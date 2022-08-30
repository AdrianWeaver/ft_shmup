/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Boss.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 22:00:59 by aweaver           #+#    #+#             */
/*   Updated: 2022/08/28 23:25:45 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include "ft_shmup.hpp"

class	Boss:virtual public Enemy
{
	protected:
		int		_dmg;
		void	shoot(void);
		virtual void	movement(void);
		void	boss_movement(void);
		void	boss_display(void *window);
		void	boss_shoot(void);
	public:
		Boss(void);
		virtual ~Boss(void);
		void	boss_action(void *&window);
};
