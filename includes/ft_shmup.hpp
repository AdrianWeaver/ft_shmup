/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shmup.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 09:56:46 by aweaver           #+#    #+#             */
/*   Updated: 2022/08/27 20:03:58 by jtaravel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SHMUP_HPP
# define FT_SHMUP_HPP

#include <vector>
#include "SpaceShip.hpp"
#include "Enemy.hpp"
#include "ncurses.h"
#include "Missiles.hpp"

// GLOBALS BECAUSE WE CAN <3
extern std::vector<Enemy>	g_enemies;


# define FRAME_MS 16
//KEYS
# define KEY_ESC 27
# define KEY_CTRL_C 3
# define KEY_CTRL_D 4
# define KEY_SPACE 32

//NAME ENEMY

#define STAY 0
#define PUSHER 1
#define PATROL 2
#define PATROL_Z 3
#define PUSHER_Z 4
#define PUSHER_UP 5
#define PUSHER_DOWN 6
#define PATROL_DOWN 7

#define ALLY 1
#define ENEMY -1

typedef struct s_data
{
	int loop;
	int phase;
}		t_data;


int	ft_init_screen(void **window);
int ft_spawn_phase_1(t_data &game);
int ft_spawn_phase_2(t_data &game);
int ft_spawn_phase_3(t_data &game);
int	ft_spawn_mobs(t_data &game);

#endif
