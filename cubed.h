/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learodri@student.42.fr <learodri>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:42:08 by learodri          #+#    #+#             */
/*   Updated: 2023/11/02 21:15:32 by learodri@st      ###   ########.fr       */
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
	char **o_mp;
	char *vars[4];
	int	f;
	int c;
	int	i_mp;
}t_cu;


//LIBFT

char	**ft_split(char const *str, char c);
long int	ft_atoi(const char *str);
int	ft_isdigit(int c);
char	*ft_strdup(char *s1);

//FREE & ERRORS

void	free_matrix(char **matrix);
void	boom(char *str);
void	print_file(char **mtx);

//PARSING

void	check_4_parse(char *cufile);
void	vars_all_good(void);
void	get_var(char *str);
char	*subs(int start, char *str);
void		extract_var(char *str, int var);
//struct

t_cu *cu(void);

# endif