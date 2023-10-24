/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learodri@student.42.fr <learodri>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:38:20 by learodri          #+#    #+#             */
/*   Updated: 2023/10/24 15:29:07 by learodri@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cubed.h"

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

t_cu *cu(void)
{
    static t_cu cu;

    return (&cu);
}

char	**extract_file(char **map, int fd, int counter)
{
	if (cu()->map)
		free(cu()->map);
		
	char	*str;

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

void check_4_parse(char *cufile)
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
		boom("no able to open your cu      b3d");
	}
	cu()->map = extract_file(NULL, fd, 0);
	if (!cu()->map)
		boom("mapa vaziozao\n");
	print_file(cu()->map);
}

void	boom(char *str)
{
	printf("%s\n", str);
	exit(1);
}

int	main(int argc, char *argv[])
{
	
	if (argc != 2)
		boom("deu ruim nos args");
	check_4_parse(argv[1]);
	
	
		

	return 0;
}