/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_init_ncurse.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aweaver <aweaver@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 08:52:25 by aweaver           #+#    #+#             */
/*   Updated: 2022/08/27 12:47:31 by aweaver          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>

int	ft_init_screen(void **window)
{
	*window = initscr();
	if (*window == NULL)
		return (1);
	if (/*ft_initialise_data() ||*/ raw() || noecho()
			|| keypad((WINDOW*)*window, TRUE) || nodelay((WINDOW *)*window, TRUE))
	{
		endwin();
		delscreen((SCREEN *)*window);
		return (1);
	}
	return (0);
}
