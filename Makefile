# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcabon <tcabon@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/24 18:02:51 by tcabon            #+#    #+#              #
#    Updated: 2016/06/03 22:34:14 by tcabon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC = 	main.c \
		ft_access_home.c \
		ft_argcheck.c \
		ft_catch_user.c \
		ft_cd_error.c \
		ft_cd_hub.c \
		ft_cd_to_home.c \
		ft_cd_to_oldpwd.c \
		ft_cd_to_path.c \
		ft_check_arg_builtins.c \
		ft_cpyenv.c \
		ft_give_path_tab.c \
		ft_exec.c \
		ft_exec_builtins.c \
		ft_exec_error.c \
		ft_free_tab.c \
		ft_launch.c \
		ft_setenv.c \
		ft_setenv_freshlist.c \
		ft_setenv_new_elem.c \
		ft_unsetenv.c \
		ft_unsetenv2.c \
		ft_unsetenv_first.c \
		ft_unsetenv_others.c \
		functions.c \
		functions_builtins.c \
		functions_home.c \

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
