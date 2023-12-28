/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   varparse3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learodri <learodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 20:06:18 by learodri@st       #+#    #+#             */
/*   Updated: 2023/12/28 20:41:14 by learodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cubed.h"

void	vars_all_good(void)
{
	int fd;
	int i;
	
	i = 0;

	while (i <= 3)
	{
		if (!cu()->vars[i])
			boom("empty textures or missconfig in file\n");
		fd = open(cu()->vars[i], O_RDONLY, 0644);
		if (fd == -1)
		{
			close(fd);
			boom("not able to open textures\n");
		}
		close(fd);
		i++;
	}

	if (cu()->c == -1 || cu()->f == -1)
		boom("missing c or f or misconfig in file\n");
}

void	check_var_rgb(int f_c)
{
	if (f_c == 1)
	{
		if (cu()->c != -1)
			boom("already var c ou f\n");
	}
	if (f_c == 2)
	{
		if (cu()->f != -1)
			boom("already var c ou f\n");
	}
}

void	check_char_rgb(char *tmp, int i)
{
	while (tmp[i])
	{
		if (tmp[i] == ',' || tmp[i] == '\n' || tmp[i] == ' ')
		{
			i++;
			continue;
		}
		if (!ft_isdigit(tmp[i]))
		{
			printf("%c", tmp[i]);
			boom("issue in format rgbtq+\n"); // free aqui talvez
		}
		i++;
	}
}

char	*subs2(int start, char *str)
{
	int	i;
	char	*newstr;
	
	i = 0;
	newstr = malloc(sizeof(char) * ft_strlen(str) - start);
	if (!newstr)
		return (NULL);
	while (str[start] && (str[start] != '\n'))
	{
		newstr[i] = str[start];
		start++;
		i++;
	}
	newstr[i] = '\0';
	return (newstr);		
}