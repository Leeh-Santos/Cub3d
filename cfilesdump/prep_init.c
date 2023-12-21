/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learodri@student.42.fr <learodri>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:08:22 by learodri@st       #+#    #+#             */
/*   Updated: 2023/12/21 22:13:09 by learodri@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cubed.h"

void	sprite_render(char *str, int i)
{
	cu()->img[i].ptr = NULL; 
	(cu()->img[i].ptr) = mlx_xpm_file_to_image(cu()->mlx, 
			str, &cu()->img[i].width, &cu()->img[i].height);
	if (cu()->img[i].width != cu()->img[i].height)
		boom("width and height are not the same");
	if (!cu()->img[i].ptr)
		boom("not able to open IMG");
	(cu()->img[i].addr) = mlx_get_data_addr(cu()->img[i].ptr, \
		&cu()->img[i].bits_in_pixel,
			&cu()->img[i].line_bytes, &cu()->img[i].endian);
}

void	sprite_init(void) //all the 4 strutcs 
{
	sprite_render(cu()->vars[0], NO);
	sprite_render(cu()->vars[1], SO);
	sprite_render(cu()->vars[2], EA);
	sprite_render(cu()->vars[3], WE);
}

void	prep_and_init(void)
{
	cu()->mlx = mlx_init();
	cu()->mlx_img = mlx_new_image(cu()->map, WIDTH, HEIGHT);
	cu()->mlx_data = mlx_get_data_addr(cu()->mlx_img, \
		&cu()->bits_pixel, &cu()->size_l, &cu()->endian);
	player_position();
	sprite_init();
	cu()->win = mlx_new_window(cu()->mlx, WIDTH, HEIGHT, "Cub3D");
	cu()->m_speed = 0.05;
	cu()->r_speed = 0.05;
	cu()->color = 0;
	cu()->flag = 0;
	mlx_mouse_get_pos(cu()->mlx, cu()->win, &cu()->x, &cu()->y);
}

void	mouse_act(void)
{
	int	x;
	int	y;

	mlx_mouse_get_pos(cu()->mlx, cu()->win, &x, &y);
	if (x < (WIDTH / 2))
	{
		cu()->r_speed = 0.001;
		cu()->r_speed = cu()->r_speed * -(x - (WIDTH / 2));
		left_cam();
	}
	else if (x > (WIDTH / 2))
	{
		cu()->r_speed = 0.001;
		cu()->r_speed = cu()->r_speed * (x - (WIDTH / 2));
		right_cam();
	}
	mlx_mouse_move(cu()->mlx, cu()->win, (WIDTH / 2), (HEIGHT / 2));
}