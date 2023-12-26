/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learodri <learodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:42:08 by learodri          #+#    #+#             */
/*   Updated: 2023/12/26 21:57:53 by learodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CUBED_H
# define CUBED_H

# include <X11/keysym.h>
# include <X11/X.h>
# include "mlx.h"
# include <X11/Xlib.h>
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

typedef struct s_img
{
	void		*ptr;
	char		*addr;
	int			width;
	int			line_bytes;
	int			height;
	int			endian;
	int			bits_in_pixel;
}			t_img;

typedef struct s_cu
{
    char 	**map;
	char 	**o_mp;
	char 	*vars[4];
	t_img	img[4];
	void	*win;
    void	*mlx;
	void	*mlx_img;
	char	*mlx_data;
	int		size_l;
	int		wall_nbr;
	int		endian;
	int		bits_pixel;
	int		x;
	int		y;
	int		f;
	int 	c;
	int		i_mp;
	double		m_speed;
	double		r_speed;
	int			color;
	int			flag;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double				dir_y;
	double				plane_x;
	double				plane_y;
}		t_cu;

typedef struct s_ray
{
	int			hit;
	int			side;
	int			map_x;
	int			map_y;
	double		tex_x;
	double		tex_y;
	int			step_x;
	int			step_y;
	int			end;
	int			side_d;
	int			start;
	int			line_h;
	double		step;
	double		wall_x;
	double		camera;
	double		ray_x;
	double		ray_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_x;
	double		delta_y;
	double		perpendicular;
}			t_ray;


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
int		check_map(char **mtx);
int		invalid_border(char **mtx);
int		invalid_player(char **mtx);
void	map_parse(char **mtx);
//struct

//render 

void	prep_and_init(void);
void	player_position(void);

//raycast

void	ray_calc(int x);
void	game_loop(void);
void	ray_init(void);
int		key(int key);
void	endcu(void);
t_cu *cu(void);
t_ray *ray(void);
void	right_cam(void);
void	left_cam(void);
void	mouse_act(void);
void	move_calc(void);
void	wall_calc(void);
void	draw_calc(void);
void	wall_side(void);

# endif