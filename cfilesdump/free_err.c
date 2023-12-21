/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_err.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learodri@student.42.fr <learodri>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:00:24 by learodri@st       #+#    #+#             */
/*   Updated: 2023/12/19 12:01:28 by learodri@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cubed.h"

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