/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learodri <learodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:38:20 by learodri          #+#    #+#             */
/*   Updated: 2023/12/28 20:19:03 by learodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cubed.h"

t_cu *cu(void)
{
    static t_cu cu;
    return (&cu);
}

t_ray *ray(void)
{
	static t_ray ray;
	return (&ray);
}

void	game_loop(void)
{
	ray_init();
	mlx_put_image_to_window(cu()->mlx, cu()->win, cu()->mlx_img, 0, 0);
	if (cu()->flag == 1)
		mouse_act();
}

void	game_hook(void)
{
	mlx_loop_hook(cu()->mlx, (void *) &game_loop, NULL);
	mlx_hook(cu()->win, 17, 0L, (void *)&endcu, NULL); 
	mlx_hook(cu()->win, 02, (1L << 0), &key, NULL); //da fuck
}

int	main(int argc, char *argv[])
{
	if (argc != 2)
		boom("deu ruim nos args");
	check_4_parse(argv[1]);
	map_parse(cu()->map, 0);
	if (check_map(cu()->o_mp))
		boom("missconfig on the o_mp");
	prep_and_init();
	game_hook();
	mlx_loop(cu()->mlx);
	return (0);	
}