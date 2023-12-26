/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   varparse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learodri <learodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 19:48:16 by learodri@st       #+#    #+#             */
/*   Updated: 2023/12/26 21:46:41 by learodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cubed.h"

void	print_file(char **mtx)
{
	int i = 0;
	int k = 0;

	while (mtx[i])
	{
		k = 0;
		while (mtx[i][k])
		{
			printf("%c", mtx[i][k]);
			k++;
		}
		i++;
	}
}

void 	print_var()
{
	printf("vars abaixo\n");
	if (cu()->vars[0])
		printf("no - %s\n", cu()->vars[0]);
	if (cu()->vars[1])
		printf("so - %s\n", cu()->vars[1]);
	if (cu()->vars[2])
		printf("ea - %s\n", cu()->vars[2]);
	if (cu()->vars[3])
		printf("we - %s\n", cu()->vars[3]);
	printf("_______________________________________________________\n");
}
//sempre em primeira posicao, a menos que seja espaco ou alguma var obrigatoria
int map_started(char *str)
{
	int	i;

	i = 0;
	
	if ((str[0] != 'E') && (str[0] != 'S') && (str[0] != 'N') && (str[0] != 'W') && (str[0] != ' ') && (str[0] != 'F') && (str[0] != 'C') && (str[0] != '\n'))
	{
		printf("\n\n parou aqui first %c \n", str[i]);
		return (1);
	}
	if (str[0] == ' ' || str[0] == '\n') // cuidado com os \n
	{
		i++;
		while (str[i])
		{
			if ((str[i] != ' ') && (str[i] != '\n'))
			{
				printf("\n\n parou aqui %c \n", str[i]);
				return (1);
			}
			i++;
		}
	}
	return (0);
}

char	**extract_file(char **map, int fd, int counter)
{
	
	char	*str;

	if (cu()->map)
		free(cu()->map);
	str = get_next_line(fd);
	if (str)
		map = extract_file(map, fd, counter + 1);
	if (!map && counter != 0)
		map = malloc((counter + 1) * (sizeof(char *)));
	if (!map)
		return (NULL);
	map[counter] = str;
	return (map);
}
void	init_vars()
{
 	cu()->vars[0] = NULL;
	cu()->vars[1] = NULL;
	cu()->vars[2] = NULL;
	cu()->vars[3] = NULL;
	cu()->c = -1;
	cu()->f = -1;
}
 //vamo mandando uma por uma, trava quando nao comeca por vars ou no meio tem outro char, depois se tiver faltando no vars_all_good ja era
void	search_vars(char **mtx)
{
	int i;
	
	i = 0;
	init_vars();
	while (mtx[i] && (!map_started(mtx[i])))
	{
		get_var(mtx[i]);
		i++;
	}
	cu()->i_mp = i;	//onde travou no mapa
	print_var();
	vars_all_good();
}

void	check_4_parse(char *cufile)
{
	int	i;
	int	fd;

	i = 0;
	while (cufile[i])
		i++;
	if (cufile[i - 1] != 'b' || cufile[i - 2] != 'u' || cufile[i - 3] != 'c' || cufile[i - 4] != '.')
		boom("wrong cu format");
	fd = open(cufile, O_RDONLY, 0644);
	if (fd == -1)
	{
		close(fd);
		boom("no able to open your cu           b3d file");
	}
	cu()->map = extract_file(NULL, fd, 0);
	if (!cu()->map)
		boom("mapa vaziozao\n");
	close(fd);
	search_vars(cu()->map);
	
}

