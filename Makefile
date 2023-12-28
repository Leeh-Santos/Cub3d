# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: learodri <learodri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/24 12:24:03 by learodri@st       #+#    #+#              #
#    Updated: 2023/12/28 20:19:43 by learodri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= main.c \
		  get_next/gnl.c \
		  get_next/gnl_utils.c \
		  cfilesdump/free_err.c \
		  cfilesdump/move.c \
		  cfilesdump/move2.c \
		  cfilesdump/position.c \
		  cfilesdump/prep_init.c \
		  cfilesdump/raycast.c \
		  cfilesdump/raycast2.c \
		  libft/libft.c \
		  parsing/varparse.c \
		  parsing/varparse2.c \
		  parsing/varparse3.c \
		  parsing/map_parse.c \
		  parsing/map_parse2.c \
		  libft/libft2.c \

OBJS	= $(SRCS:.c=.o)

NAME	= cub3D

CC		= cc

CFLAGS	= -Wall -Wextra -Werror -g -fsanitize=address

RM		= rm -rf

MLX		=	mlx_linux/libmlx_Linux.a

MLX_LIB_DIR = mlx_linux/

MLX_INCLUDE = -Imlx_linux

MLX_FLAGS = -L$(MLX_LIB_DIR) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

all: $(NAME)

$(NAME): $(OBJS) $(MLX)
		$(CC) $(CFLAGS) $^ $(MLX_FLAGS) -o $@

$(MLX):
		make -C mlx_linux

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) $(MLX_INCLUDE) -c $^ -o $@


clean: 
	$(RM) $(OBJS)
	make clean -C mlx_linux

fclean: clean
		$(RM) $(NAME) $(OBJS)

re: fclean all
	
.PHONY: all clean fclean re