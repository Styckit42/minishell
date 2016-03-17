# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcabon <tcabon@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/24 18:02:51 by tcabon            #+#    #+#              #
#    Updated: 2016/02/24 21:26:01 by tcabon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC = 	main.c \
		ft_cpyenv.c \
		ft_launch.c \
		ft_argcheck.c \
		ft_exec.c \
		ft_exec_builtins.c \
		ft_setenv.c \
		ft_unsetenv.c \
		functions.c \
		functions_builtins.c \

OBJ = $(patsubst %.c, %.o, $(SRC))

CFLAGS = -Wall -Wextra -Werror


all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	gcc $(OBJ) -L libft -lft -o $(NAME)

proper: $(NAME) clean

clean:
	rm -f $(OBJ)
	make clean -C libft/

fclean: clean
	rm -f $(NAME)
	rm -f libft/libft.a

re: fclean all

%.o: %.c
	gcc -c $< -o $@