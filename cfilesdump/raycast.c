/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learodri@student.42.fr <learodri>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 16:34:05 by learodri@st       #+#    #+#             */
/*   Updated: 2023/12/14 16:41:27 by learodri@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cubed.h"


int		mlx_pixel_get2(t_img *img, int x, int y)
{
	return (*(unsigned int *)(img->addr + (y * img->line_bytes + \
		x * (img->bits_in_pixel / 8))));
}

void	mlx_pixel_put2(int x, int y, int color)
{
	char	*dst;

	dst = cu()->mlx_data + (y * cu()->size_l + x \
		* (cu()->bits_pixel / 8));
	*(unsigned int *)dst = color;
}

void	color_update(int x, int y)
{
	ray()->tex_x = (int)(ray()->wall_x * cu()->img[cu()->wall_nbr].height);
	ray()->step = 1.0 * cu()->img[cu()->wall_nbr].width / ray()->line_h;
	ray()->tex_y = (ray()->start - HEIGHT / 2 \
		+ ray()->line_h / 2) * ray()->step;
	while (y < HEIGHT)
	{
		if (y < ray()->start)
			cu()->color = cu()->c;
		else if (y >= ray()->start && y <= ray()->end)
		{
			ray()->tex_y += ray()->step;
			(cu()->color) = mlx_pixel_get2(&cu()->img[cu()->wall_nbr], \
				ray()->tex_x, ray()->tex_y);
		}
		else
			cu()->color = cu()->f;
		mlx_pixel_put2(x, y, cu()->color);
		y++;
	}
}

void	ray_calc(int x)
{
	ray()->camera = 2 * x / (double)WIDTH - 1;
	ray()->ray_x = cu()->dir_x + cu()->plane_x * ray()->camera;
	ray()->ray_y = cu()->dir_y + cu()->plane_y * ray()->camera;
	ray()->map_x = (int)cu()->pos_x;
	ray()->map_y = (int)cu()->pos_y;
	ray()->delta_x = fabs(1 / ray()->ray_x);
	ray()->delta_y = fabs(1 / ray()->ray_y);
	ray()->hit = 0;
}

void	ray_init(void)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIDTH)  
	{
		ray_calc(x);
		move_calc();
		wall_calc();
		draw_calc();
		wall_side();
		y = 0;
		color_update(x, y);
		x++;
	}
}
