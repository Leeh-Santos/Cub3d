/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   varparse2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learodri@student.42.fr <learodri>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 19:58:48 by learodri@st       #+#    #+#             */
/*   Updated: 2023/11/23 21:20:18 by learodri@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cubed.h"

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
	printf("ta aqui : r - %d   g - %d   b - %d\n", r, g, b);
	if (f_c == 1)
		cu()->c = (r << 16) + (g << 8) + b;
	if (f_c == 2)
		cu()->f = (r << 16) + (g << 8) + b;
}

void	extract_rgb(int f_c, char *str)//cealing para 1 e floor para 2
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
			boom("problema no formato rgbt+\n"); // free aqui
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
	//printf("%d\n ", cu()->f);
	//printf("%d\n ", cu()->c);
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