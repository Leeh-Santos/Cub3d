/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learodri@student.42.fr <learodri>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:36:50 by learodri@st       #+#    #+#             */
/*   Updated: 2023/12/11 14:40:48 by learodri@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cubed.h"

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