/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learodri@student.42.fr <learodri>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:42:08 by learodri          #+#    #+#             */
/*   Updated: 2023/10/31 16:44:24 by learodri@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <sys/time.h>
# include <fcntl.h>
# include <unistd.h>
# include "get_next.h"

typedef enum e_vars
{
   NO,
   SO,
   EA,
   WE,
} t_vars;


typedef struct s_cu
{
    char **map;
	char *vars[4];
	int	f;
	int c;
}t_cu;


//LIBFT

char	**ft_split(char const *str, char c);
long int	ft_atoi(const char *str);
int	ft_isdigit(int c);

//FREE & ERRORS

void	free_matrix(char **matrix);
void	boom(char *str);

# endif