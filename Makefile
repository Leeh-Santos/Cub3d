# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: learodri@student.42.fr <learodri>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/24 12:24:03 by learodri@st       #+#    #+#              #
#    Updated: 2023/11/02 21:07:59 by learodri@st      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= main.c \
		  get_next/gnl.c \
		  get_next/gnl_utils.c \
		  cfilesdump/free_err.c \
		  libft/libft.c \
		  parsing/varparse.c \
		  parsing/varparse2.c \
		  parsing/varparse3.c \
		  libft/libft2.c \

OBJS	= $(SRCS:.c=.o)

NAME	= cub3D

CC		= cc

CFLAGS	= -Wall -Wextra -Werror -g 

RM		= rm -rf

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $^ -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME) $(OBJS)

re: fclean all

r:
	make re && make clean && clear && ./philo 5 800 200 200

.PHONY: all clean fclean re