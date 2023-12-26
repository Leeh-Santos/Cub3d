/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learodri <learodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:56:25 by learodri@st       #+#    #+#             */
/*   Updated: 2023/12/26 19:47:45 by learodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cubed.h"

void	right_cam(void)
{
	double	tmp_x;
	double	tmp_plane;

	tmp_x = cu()->dir_x;
	tmp_plane = cu()->plane_x;
	cu()->dir_x = cu()->dir_x * cos(-cu()->r_speed) \
		- cu()->dir_y * sin(-cu()->r_speed);
	cu()->dir_y = tmp_x * sin(-cu()->r_speed) \
		+ cu()->dir_y * cos(-cu()->r_speed);
	cu()->plane_x = cu()->plane_x * cos(-cu()->r_speed) \
		- cu()->plane_y * sin(-cu()->r_speed);
	cu()->plane_y = tmp_plane * sin(-cu()->r_speed) \
		+ cu()->plane_y * cos(-cu()->r_speed);
	cu()->r_speed = 0.05;
}

void	left_cam(void)
{
	double	tmp_x;
	double	tmp_plane;

	tmp_x = cu()->dir_x;
	tmp_plane = cu()->plane_x;
	cu()->dir_x = cu()->dir_x * cos(cu()->r_speed) \
		- cu()->dir_y * sin(cu()->r_speed);
	cu()->dir_y = tmp_x * sin(cu()->r_speed) \
		+ cu()->dir_y * cos(cu()->r_speed);
	cu()->plane_x = cu()->plane_x * cos(cu()->r_speed) \
		- cu()->plane_y * sin(cu()->r_speed);
	cu()->plane_y = tmp_plane * sin(cu()->r_speed) \
		+ cu()->plane_y * cos(cu()->r_speed);
	cu()->r_speed = 0.05;
}