/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learodri <learodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:38:20 by learodri          #+#    #+#             */
/*   Updated: 2023/12/04 21:21:25 by learodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cubed.h"

t_cu *cu(void)
{
    static t_cu cu;

    return (&cu);
}

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

int	invalid_char(char **mtx) {
    int i;
	int j;
	
	i = 0;
    while (mtx[i] != NULL)
	{
		j = 0;
        while (mtx[i][j])
		{
            if ((mtx[i][j] != '0') && (mtx[i][j] != '1') && (mtx[i][j] != 'N') && (mtx[i][j] != 'S') && (mtx[i][j] != 'E') && (mtx[i][j] != 'W') && (mtx[i][j] != '\n') && (mtx[i][j] != ' '))
                return 1;
            j++;
        }
        i++;
    }
    return 0;
}

char not_content(char c)
{
	
	if ((c != '0') && (c != 'N') && (c != 'S') && (c != 'E') && (c != 'W') && (c != '1'))
	{
		printf("\n esse char aqui o - %c\n", c);
		return (0);
	}
	return (1);
}

int	invalid_border(char **mtx)
{
	size_t i;
	size_t j;

	i = 0;
	while (mtx[i])
	{
		j = 0;
		while (mtx[i][j])
		{
			if (mtx[i][j] == '0' || mtx[i][j] == 'N' || mtx[i][j] == 'S' || mtx[i][j] == 'E' || mtx[i][j] == 'W')
			{
				if (i == 0 || j == 0 || !mtx[i + 1] || !mtx[i][j + 1] || !mtx[i - 1] || !mtx[i][j - 1])
				{
					printf("foi aqui essa merda \n");
					return (1);
				}
				if (!not_content(mtx[i][j + 1]) || !not_content(mtx[i][j - 1]) || !not_content(mtx[i + 1][j]) || !not_content(mtx[i - 1][j]))
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int		check_map(char **mtx)
{
	if (!invalid_player(mtx))
	{
		printf("more than one player ou nenhum player meu parceiro\n");
		return (1);
	}
	if (invalid_char(mtx))
	{
		printf("invalid char in the map meu parceiro\n");
		return (1);
	}
	if (invalid_border(mtx))
	{
		printf("invalid border meu parceiro\n");
		return (1);
	}
	return (0);
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