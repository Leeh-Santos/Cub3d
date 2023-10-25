/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learodri@student.42.fr <learodri>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:38:20 by learodri          #+#    #+#             */
/*   Updated: 2023/10/25 20:56:16 by learodri@st      ###   ########.fr       */
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
	if (str[0] == ' ')
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
	cu()->c[0] = -1;
	cu()->c[1] = 0;
	cu()->c[2] = 0;
	cu()->c[3] = 0;
	cu()->f[0] = -1;
	cu()->f[1] = 0;
	cu()->f[2] = 0;
	cu()->f[3] = 0;
}

char	*subs(int start, char *str)
{
	int	i;
	char	*newstr;
	
	i = 0;
	newstr = malloc(sizeof(char) * ft_strlen(str) - start);
	if (!newstr)
		return (NULL);
	while (str[start])
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

void	extract_rgb(int f_c, char *str)
{
	int i;
	
	if (f_c == 1)
	{
		if (cu()->c[0] != -1)
			boom("ja tem var c ou f");
	}
	if (f_c == 2)
	{
		if (cu()->f[0] != -1)
			boom("ja tem var c ou f");
	}
	i = 2;
	while (str[i] && str[i] == ' ')
		i++;
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
	//check_vars
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
	close(fd);
	search_vars(cu()->map);
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