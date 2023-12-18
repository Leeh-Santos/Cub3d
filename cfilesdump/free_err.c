/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_err.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learodri@student.42.fr <learodri>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:00:24 by learodri@st       #+#    #+#             */
/*   Updated: 2023/12/18 17:57:24 by learodri@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cubed.h"

void	boom(char *str)
{
	printf("%s\n", str);
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
	//free shit here & exit
}