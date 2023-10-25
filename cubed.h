/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: learodri@student.42.fr <learodri>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:42:08 by learodri          #+#    #+#             */
/*   Updated: 2023/10/25 20:21:29 by learodri@st      ###   ########.fr       */
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

typedef enum e_type
{
	r,
	g,
	b
} t_type;



typedef struct s_cu
{
    char **map;
	char *vars[4];
	int	f[4];
	int c[4];
}t_cu;

void	boom(char *str);


# endif