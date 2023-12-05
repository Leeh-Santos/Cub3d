/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learodri <learodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:42:08 by learodri          #+#    #+#             */
/*   Updated: 2023/12/05 21:15:06 by learodri         ###   ########.fr       */
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

# define WIDTH 1080
# define HEIGHT 720

typedef enum e_vars
{
   NO,
   SO,
   EA,
   WE,
} t_vars;


typedef struct s_cu
{
    char 	**map;
	char 	**o_mp;
	char 	*vars[4];
	void	*win;
    void	*mlx;
	void	*mlx_img;
	char	*mlx_data;
	int		size_l;
	int		endian;
	int		bits_pixel;
	int		x;
	int		y;
	int		f;
	int 	c;
	int		i_mp;
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
void    extract_var(char *str, int var);
int		player_ta_fixe(char **mtx);
int		invalid_char(char **mtx);
//struct

t_cu *cu(void);

# endif