#ifndef MINISHELL_H
# define MINISHELL_H

# define BUFF_SIZE 100

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <dirent.h>
# include <fcntl.h>
# include <string.h>

void			ft_argcheck(t_list *list, char *prompt);
int				ft_check_builtins(char *str);
char			**ft_cpyenv(char **env);
void			ft_env(t_list *list);
void			ft_exec(char **path_tab, char **env, char **cmd);
void			ft_exec_builtins(int ret_built, t_list *list, char **arg);
void			ft_launch(char **env);
void			ft_print_env_list(t_list *list);
char			*ft_replace_char(char *str, char c, char d);
char			*ft_reduce_path(char *path);
void			ft_setenv(t_list *list, char **arg);
void			ft_unsetenv(t_list *list, char **arg);
int				get_next_line(int const fd, char **line);

#endif