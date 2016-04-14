/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcabon <tcabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 20:30:43 by tcabon            #+#    #+#             */
/*   Updated: 2016/04/04 20:30:44 by tcabon           ###   ########.fr       */
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

void			ft_argcheck(t_list *list, char *prompt);
void			ft_cd(t_list *list, char **arg);
void			ft_cd_hub(t_list *list, char **arg);
void			ft_cd_error(char *path, char *argu);
void			ft_cd_to_home(t_list *list, char **arg);
void			ft_cd_to_oldpwd(t_list *list, char **arg);
int				ft_check_access_home(char **cmd);
int				ft_check_builtins(char *str);
int				ft_check_home_presence(t_list *list);
int				ft_check_prompt(char *str);
char			**ft_cpyenv(char **env);
void			ft_del_unset(void *content, size_t content_size);
void			ft_env(t_list *list);
void			ft_exec(char **path_tab, char **env, char **cmd);
void			ft_exec_builtins(int ret_built, t_list *list, char **arg);
void			ft_give_home_to_cmd(char **cmd, t_list *list);
void			ft_launch(char **env);
void			ft_print_env_list(t_list *list);
char			*ft_replace_char(char *str, char c, char d);
char			*ft_reduce_path(char *path);
void			ft_setenv(t_list *list, char **arg);
void			ft_unsetenv(t_list **list, char **arg);
int				ft_value_len(char *content);
int				get_next_line(int const fd, char **line);

#endif
