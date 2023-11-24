/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learodri@student.42.fr <learodri>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:38:20 by learodri          #+#    #+#             */
/*   Updated: 2023/11/24 16:56:22 by learodri@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cubed.h"

t_cu *cu(void)
{
    static t_cu cu;

    return (&cu);
}

int		player_ta_fixe(char **mtx)
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
			if (mtx[i][k] == 'N' || mtx[i][k] == 'S' || mtx[i][k] == 'L' || mtx[i][k] == 'O')
				p++;
			k++;
		}
		i++;
	}
	if (p != 1)
	{
		printf("more than one player meu parceiro\n");
		return (0);
	}
	return (1);
}

int		invalid_char(char *mtx)
{
	int	i;

	i = 0;
	while (mtx[i])
	{
		if ((mtx[i] != '0') && (mtx[i] != '1') && (mtx[i] != 'N') && (mtx[i] != 'S') && (mtx[i] != 'L') && (mtx[i] != 'O') && (mtx[i] != '\n') && (mtx[i] != ' '))
		{
			printf("invalid char in the map meu parceiro %c\n", mtx[i]);
			return (1);
		}
		i++;
	}
	return (0);
}

/*int		invalid_map(char **mtx)
{
	
}*/

int		check_map(char **mtx)
{
	int i;

	i = 0;

	if (!player_ta_fixe(mtx))
		return (1);
	while (mtx[i])
	{
		if (invalid_char(mtx[i]))
			return (1);
		i++;
	}
	/*if (invalid_map(mtx))
		return (1)*/
	return (0);
}

void	map_parse(char **mtx) //ate aqui nao pode ter bo com as var ou map, somente pega a parte do mapa
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
	cu()->o_mp[i] = '\0';
	print_file(cu()->map);
	free(cu()->map);
	printf("\n novo mapa abaixo \n");
	print_file(cu()->o_mp);
	
}
int	main(int argc, char *argv[])
{
	
	if (argc != 2)
		boom("deu ruim nos args");
	check_4_parse(argv[1]);
	map_parse(cu()->map);
	if (check_map(cu()->o_mp))
		boom("missconfig on the map");
	

	return 0;
}