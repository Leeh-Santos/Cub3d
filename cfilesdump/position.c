/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learodri@student.42.fr <learodri>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:34:55 by learodri@st       #+#    #+#             */
/*   Updated: 2023/12/12 14:57:47 by learodri@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cubed.h"

void	get_pos(char **str) 
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'N' || str[i][j] == 'S' \
				|| str[i][j] == 'E' || str[i][j] == 'W')
			{
				cu()->pos_x = (i + 0.5);
				cu()->pos_y = (j + 0.5);
				return ;
			}
			j++;
		}
		i++;
	}
	boom("exit in get_pos func \n");
}

void	north_south(void)
{
	if (cu()->o_mp[(int)cu()->pos_x][(int)cu()->pos_y] == 'N') 
	{
		cu()->dir_x = 0;
		cu()->dir_y = -1;
		cu()->plane_x = -0.66;
		cu()->plane_y = 0;
	}
	if (cu()->o_mp[(int)cu()->pos_x][(int)cu()->pos_y] == 'S') 
	{
		cu()->dir_x = 0;
		cu()->dir_y = 1;
		cu()->plane_x = 0.66;
		cu()->plane_y = 0;
	}
}

void east_oeste(void)
{
	if (cu()->o_mp[(int)cu()->pos_x][(int)cu()->pos_y] == 'W')
	{
		cu()->dir_x = -1;
		cu()->dir_y = 0;
		cu()->plane_x = 0;
		cu()->plane_y = 0.66;
	}
	if (cu()->o_mp[(int)cu()->pos_x][(int)cu()->pos_y] == 'E')
	{
		cu()->dir_x = 1;
		cu()->dir_y = 0;
		cu()->plane_x = 0;
		cu()->plane_y = -0.66;
	}
}

void	player_position(void)
{
	get_pos(cu()->o_mp);
	if (cu()->o_mp[(int)cu()->pos_x][(int)cu()->pos_y] == 'N' //fez para norte sul o start
		|| cu()->o_mp[(int)cu()->pos_x][(int)cu()->pos_y] == 'S')
		north_south();
	else if (cu()->o_mp[(int)cu()->pos_x][(int)cu()->pos_y] == 'W' //fez para norte sul o start
		|| cu()->o_mp[(int)cu()->pos_x][(int)cu()->pos_y] == 'E')
		east_oeste();
}