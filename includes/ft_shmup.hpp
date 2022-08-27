/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shmup.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 09:56:46 by aweaver           #+#    #+#             */
/*   Updated: 2022/08/27 15:00:06 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SHMUP_HPP
# define FT_SHMUP_HPP

#include "SpaceShip.hpp"
#include "Enemy.hpp"


# define FRAME_MS 16
//KEYS
# define KEY_ESC 27
# define KEY_CTRL_C 3
# define KEY_CTRL_D 4
int	ft_init_screen(void **window);

#endif
