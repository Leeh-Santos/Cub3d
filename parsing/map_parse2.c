/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learodri <learodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:40:06 by learodri@st       #+#    #+#             */
/*   Updated: 2023/12/27 21:24:55 by learodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cubed.h"

int		invalid_player(char **mtx)
{
	int	p;
	int	i;
	int	k;
	
	p = 0;
	i = 0;
	k = 0;
	while (mtx[i])
	{
		k = 0;
		while (mtx[i][k])
		{
			if (mtx[i][k] == 'N' || mtx[i][k] == 'S' || mtx[i][k] == 'E' || mtx[i][k] == 'W')
				p++;
			k++;
		}
		i++;
	}
	if (p != 1)
		return (0);
	return (1);
}

void	map_parse(char **mtx)
{
	int i;
	int tmp;
	
	i = 0;
	tmp = cu()->i_mp;
	while (mtx[tmp])
	{
		i++;
		tmp++;
	}
	if (cu()->o_mp)
		free(cu()->map);
	cu()->o_mp = malloc(sizeof(char *) * (i + 1));
	if (!cu()->o_mp)
		return (boom("not able to malloc map"));
	i = 0;
	while (mtx[cu()->i_mp])
	{
		cu()->o_mp[i] = ft_strdup(mtx[cu()->i_mp]);
		if (!cu()->o_mp[i])
			boom("failed to malloc map");
		i++;
		cu()->i_mp++;
	}
	cu()->o_mp[i] = 0;
	print_file(cu()->map);
	free_matrix(cu()->map);
	printf("\n novo mapa abaixo \n");
	print_file(cu()->o_mp);
}