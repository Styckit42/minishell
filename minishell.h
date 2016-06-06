/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcabon <tcabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 20:30:43 by tcabon            #+#    #+#             */
/*   Updated: 2016/06/03 22:53:36 by tcabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
# include <sys/types.h>
# include <sys/stat.h>

void			ft_argcheck(t_list **list, char *prompt, char **env);
void			ft_access_home(char **cmd, t_list **list);
char			*ft_catch_user(t_list *list);
void			ft_cd_hub(t_list *list, char **arg);
void			ft_cd_error(char *target, t_list *list);
void			ft_cd_to_home(t_list *list, char **arg);
void			ft_cd_to_oldpwd(t_list *list, char **arg);
void			ft_cd_to_path(t_list *list, char *target);
int				ft_check_access_home(char **cmd);
int				ft_check_arg_setenv(char **cmd, t_list *list);
int				ft_check_arg_unsetenv(char **cmd);
int				ft_check_builtins(char **cmd, t_list *list);
int				ft_check_home_presence(t_list *list);
int				ft_check_prompt(char *str);
char			**ft_cpyenv(char **env);
void			ft_del_unset(void *content, size_t content_size);
void			ft_env(t_list *list);
void			ft_exec(char **path_tab, char **env, char **cmd, int i);
void			ft_exec_builtins(int ret_built, t_list **list, char **arg);
void			ft_exec_error(char **cmd);
void			ft_free_tab(char **tab);
char			*ft_give_home_tilde(t_list *list);
void			ft_give_home_to_cmd(char **cmd, t_list *list);
char			**ft_give_path_tab(t_list **list);
void			ft_launch(char **env, t_list *list);
void			ft_print_env_list(t_list *list);
char			*ft_replace_char(char *str, char c, char d);
char			*ft_reduce_path(char *path);
t_list			*ft_setenv(t_list *list, char **arg);
t_list			*ft_setenv_freshlist(char **arg);
void			ft_setenv_new_elem(t_list *list, char **arg);
t_list			*ft_unsetenv(t_list *list, char **arg);
t_list			*ft_unsetenv2(t_list *list, char *arg, \
	t_list *tmp2, t_list *cpy);
t_list			*ft_unsetenv_first(t_list *list, t_list *cpy, \
	t_list *tmp, t_list *tmp2);
t_list			*ft_unsetenv_others(t_list *list, t_list *cpy, \
	t_list *tmp, t_list *tmp2);
int				ft_value_len(char *content);
int				get_next_line(int const fd, char **line);

#endif
