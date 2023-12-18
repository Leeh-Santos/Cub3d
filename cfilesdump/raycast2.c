/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learodri@student.42.fr <learodri>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:40:29 by learodri@st       #+#    #+#             */
/*   Updated: 2023/12/14 16:41:00 by learodri@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cubed.h"


void	move_calc(void)
{
	if (ray()->ray_x < 0)
	{
		ray()->step_x = -1;
		ray()->side_dist_x = (cu()->pos_x \
			- ray()->map_x) * ray()->delta_x;
	}
	else
	{
		ray()->step_x = 1;
		ray()->side_dist_x = (ray()->map_x \
			+ 1.0 - cu()->pos_x) * ray()->delta_x;
	}
	if (ray()->ray_y < 0)
	{
		ray()->step_y = -1;
		ray()->side_dist_y = (cu()->pos_y \
			- ray()->map_y) * ray()->delta_y;
	}
	else
	{
		ray()->step_y = 1;
		ray()->side_dist_y = (ray()->map_y + 1.0 \
			- cu()->pos_y) * ray()->delta_y;
	}
}

void	for_wall(void)
{
	ray()->hit = 1;
	if (ray()->side == 0)
	{
		if (ray()->step_x == -1)
			ray()->side_d = 0;
		else
			ray()->side_d= 1;
	}
	else
	{
		if (ray()->step_y == -1)
			ray()->side_d= 2;
		else
			ray()->side_d= 3;
	}
}

void	wall_calc(void)
{
	while (ray()->hit == 0)
	{
		if (ray()->side_dist_x < ray()->side_dist_y)
		{
			ray()->side_dist_x += ray()->delta_x;
			ray()->map_x += ray()->step_x;
			ray()->side = 0;
		}
		else
		{
			ray()->side_dist_y += ray()->delta_y;
			ray()->map_y += ray()->step_y;
			ray()->side = 1;
		}
		if (cu()->map[ray()->map_x][ray()->map_y] == '1')
			for_wall();
	}
}

void	draw_calc(void)
{
	if (ray()->side == 0)
		ray()->perpendicular = (ray()->map_x - cu()->pos_x \
			+ (1 - ray()->step_x) / 2) / ray()->ray_x;
	else
		ray()->perpendicular = (ray()->map_y - cu()->pos_y \
			+ (1 - ray()->step_y) / 2) / ray()->ray_y;
	ray()->line_h = (int)(HEIGHT / ray()->perpendicular);
	ray()->start = -ray()->line_h / 2 + HEIGHT / 2;
	if (ray()->start < 0)
		ray()->start = 0;
	ray()->end = ray()->line_h / 2 + HEIGHT / 2;
	if (ray()->end >= HEIGHT)
		ray()->end = HEIGHT - 1;
	if (ray()->side == 0)
		ray()->wall_x = cu()->pos_y + ray()->perpendicular \
			* ray()->ray_y;
	else
		ray()->wall_x = cu()->pos_x + ray()->perpendicular \
			* ray()->ray_x;
	ray()->wall_x -= floor(ray()->wall_x);
}

void	wall_side(void)
{
	if (ray()->side_d == 0 && cu()->map[(int)ray()->map_x] \
		[ray()->map_y] == '1')
		cu()->wall_nbr = 0;
	else if (ray()->side_d == 1 && cu()->map[(int)ray()->map_x] \
		[ray()->map_y] == '1')
		cu()->wall_nbr = 1;
	else if (ray()->side_d == 2 && cu()->map[(int)ray()->map_x] \
		[ray()->map_y] == '1')
		cu()->wall_nbr = 2;
	else if (ray()->side_d == 3 && cu()->map[(int)ray()->map_x] \
		[ray()->map_y] == '1')
		cu()->wall_nbr = 3;
}