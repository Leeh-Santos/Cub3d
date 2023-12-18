/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learodri@student.42.fr <learodri>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:55:09 by learodri@st       #+#    #+#             */
/*   Updated: 2023/12/18 17:55:53 by learodri@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cubed.h"

void	straight(void)
{
	if (cu()->o_mp[(int)(cu()->pos_x + (cu()->dir_x \
		* cu()->m_speed))][(int)(cu()->pos_y)] != '1')
		cu()->pos_x += cu()->dir_x * cu()->m_speed;
	if (cu()->o_mp[(int)(cu()->pos_x)][(int)(cu()->pos_y \
		+ (cu()->dir_y * cu()->m_speed))] != '1')
		cu()->pos_y += cu()->dir_y * cu()->m_speed;
}

void	back(void)
{
	if (cu()->o_mp[(int)(cu()->pos_x - (cu()->dir_x \
		* cu()->m_speed))] \
		[(int)(cu()->pos_y)] != '1')
		cu()->pos_x -= cu()->dir_x * cu()->m_speed;
	if (cu()->o_mp[(int)(cu()->pos_x)] \
		[(int)(cu()->pos_y \
		- (cu()->dir_y * cu()->m_speed))] != '1')
		cu()->pos_y -= cu()->dir_y * cu()->m_speed;
}

void	left(void)
{
	if (cu()->o_mp[(int)(cu()->pos_x - (cu()->plane_x \
		* cu()->m_speed))][(int)(cu()->pos_y)] != '1')
		cu()->pos_x -= cu()->plane_x * cu()->m_speed;
	if (cu()->o_mp[(int)(cu()->pos_x)][(int)(cu()->pos_y \
		- (cu()->plane_y * cu()->m_speed))] != '1')
		cu()->pos_y -= cu()->plane_y * cu()->m_speed;
}

void	right(void)
{
	if (cu()->o_mp[(int)(cu()->pos_x + (cu()->plane_x \
		* cu()->m_speed))][(int)cu()->pos_y] != '1')
		cu()->pos_x += cu()->plane_x * cu()->m_speed;
	if (cu()->o_mp[(int)(cu()->pos_x)][(int)(cu()->pos_y \
		+ (cu()->plane_y * cu()->m_speed))] != '1')
		cu()->pos_y += cu()->plane_y * cu()->m_speed;
}

int	key(int key)
{
	if (key == 65307 || key == 113)
		endcu();
	else if (key == 65363)
		right_cam();
	else if (key == 65361)
		left_cam();
	else if (key == 119)
		straight();
	else if (key == 115)
		back();
	else if (key == 97)
		left();
	else if (key == 100)
		right();
	else if (key == 65505)
	{
		if (cu()->flag == 0)
			cu()->flag = 1;
		else
			cu()->flag = 0;
	}
	game_loop();
	return (0);
}