/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_err.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learodri <learodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:00:24 by learodri@st       #+#    #+#             */
/*   Updated: 2023/12/26 21:31:45 by learodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cubed.h"

void	mlx_boom(void)
{
	if (cu()->img[0].ptr)
		mlx_destroy_image(cu()->mlx, cu()->img[0].ptr);
	if (cu()->img[1].ptr)
		mlx_destroy_image(cu()->mlx, cu()->img[1].ptr);
	if (cu()->img[2].ptr)
		mlx_destroy_image(cu()->mlx, cu()->img[2].ptr);
	if (cu()->img[3].ptr)
		mlx_destroy_image(cu()->mlx, cu()->img[3].ptr);
	if (cu()->mlx_img)
		mlx_destroy_image(cu()->mlx, cu()->mlx_img);
	//if (cu()->win)
		//mlx_destroy_image(cu()->mlx, cu()->win);
	if (cu()->mlx)
	{
		mlx_destroy_display(cu()->mlx);
		free(cu()->mlx);
	}
}

void	boom(char *str)
{
	int	i;

	i = 0;
	printf("%s\n", str);
	while (i <= 3)
	{
		if (cu()->vars[i])
			free(cu()->vars[i]);
		i++;
	}
	free_matrix(cu()->o_mp);
	mlx_boom();
	// falta o rg talvez
	exit(1);
}

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	if (!matrix)
		return ;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void	endcu(void)
{
	boom("cabou");
}