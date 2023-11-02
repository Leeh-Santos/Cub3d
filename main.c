/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learodri@student.42.fr <learodri>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:38:20 by learodri          #+#    #+#             */
/*   Updated: 2023/11/02 15:11:13 by learodri@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cubed.h"

t_cu *cu(void)
{
    static t_cu cu;

    return (&cu);
}

int map_started(char *str)
{
	int	i;

	i = 0;
	//printf("%s\n", str);
	//printf("%c\n", str[i]);
	if ((str[0] != 'E') && (str[0] != 'S') && (str[0] != 'N') && (str[0] != 'W') && (str[0] != ' ') && (str[0] != 'F') && (str[0] != 'C') && (str[0] != '\n'))
	{
		printf("\n\n parou aqui first %c \n", str[i]);
		return (1);
	}
	if (str[0] == ' ') // cuidado com os \n
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

void	init_vars()
{
 	cu()->vars[0] = NULL;
	cu()->vars[1] = NULL;
	cu()->vars[2] = NULL;
	cu()->vars[3] = NULL;
	cu()->c = -1;
	cu()->f = -1;
}

char	*subs(int start, char *str)// \n aqui
{
	int	i;
	char	*newstr;
	
	i = 0;
	newstr = malloc(sizeof(char) * ft_strlen(str) - start);
	if (!newstr)
		return (NULL);
	while (str[start] && (str[start] != '\n')) //nmb\n aqui
	{
		newstr[i] = str[start];
		start++;
		i++;
	}
	newstr[i] = '\0';
	return (newstr);		
}

void		extract_var(char *str, int var)
{
	int i;
	
	if (cu()->vars[var])
		boom("ja tem var"); // com free depois para vars ja alocadas NO WE e tambem o cu->mapa
	i = 3;
	while (str[i] && str[i] == ' ')
		i++;
	cu()->vars[var] = subs(i, str);
	
}

void	check_rgbt(char **mtx, int f_c)
{
	int	r;
	int	g;
	int	b;
	
	r = ft_atoi(mtx[0]);
	g = ft_atoi(mtx[1]);
	b = ft_atoi(mtx[2]);
	
	if (r < 0 || g < 0 || b < 0 || r > 255 || g > 255 || b > 255)
	{
		free_matrix(mtx);
		printf("r - %d   g - %d   b - %d\n", r, g, b);
		boom("valor rgbt maior ou menor\n");
	}
	
	if (f_c == 1)
		cu()->c = (r << 16) + (g << 8) + b;
	if (f_c == 2)
		cu()->f = (r << 16) + (g << 8) + b;
}

void	extract_rgb(int f_c, char *str)
{
	int		i;
	char	*tmp;
	char	**rg;
	
	if (f_c == 1)
	{
		if (cu()->c != -1)
			boom("ja tem var c ou f\n");
	}
	if (f_c == 2)
	{
		if (cu()->f != -1)
			boom("ja tem var c ou f\n");
	}
	i = 2;
	while (str[i] && str[i] == ' ')
		i++;
	tmp = subs(i, str);
	printf(" esse foi de antes%s '/n' ", tmp);
	i = 0;
	while (tmp[i])
	{
		if (tmp[i] == ',' || tmp[i] == '\n')
		{
			i++;
			continue;
		}
		if (!ft_isdigit(tmp[i]))
		{
			printf("%c", tmp[i]);
			boom("numero no rgbt+\n");
		}
		i++;
	}
	rg = ft_split(tmp, ',');
	free (tmp);
	i = 0;
	while (rg[i])
		i++;
	if (i != 3)
	{
		boom("rgbt ta diferente de tres\n");
		free_matrix(rg);
	}
	check_rgbt(rg, f_c);
	
}

void	get_var(char *str)
{
	if ((str[0] == 'N') && (str[1] == 'O') && (str[2] == ' '))
		return (extract_var(str, NO));
	if ((str[0] == 'S') && (str[1] == 'O') && (str[2] == ' '))
		return (extract_var(str, SO));
	if ((str[0] == 'E') && (str[1] == 'A') && (str[2] == ' '))
		return (extract_var(str, EA));
	if ((str[0] == 'W') && (str[1] == 'E') && (str[2] == ' '))
		return (extract_var(str, WE));
	if ((str[0] == 'F') && (str[1] == ' '))
		return(extract_rgb(1, str));
	if ((str[0] == 'C') && (str[1] == ' '))
		return(extract_rgb(2, str));
}

void 	print_var()
{
	printf("\n");
	if (cu()->vars[0])
		printf("no - %s\n", cu()->vars[0]);
	if (cu()->vars[1])
		printf("so - %s\n", cu()->vars[1]);
	if (cu()->vars[2])
		printf("ea - %s\n", cu()->vars[2]);
	if (cu()->vars[3])
		printf("we - %s\n", cu()->vars[3]);
}

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
	print_var();
	//check_vars se null as 3
}

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
		boom("no able to open your cu           b3d file");
	}
	cu()->map = extract_file(NULL, fd, 0);
	if (!cu()->map)
		boom("mapa vaziozao\n");
	close(fd);
	search_vars(cu()->map);
	print_file(cu()->map);
}


int	main(int argc, char *argv[])
{
	
	if (argc != 2)
		boom("deu ruim nos args");
	check_4_parse(argv[1]);
	

	return 0;
}