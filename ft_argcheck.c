/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argcheck.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcabon <tcabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 20:29:07 by tcabon            #+#    #+#             */
/*   Updated: 2016/04/04 20:29:09 by tcabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_argcheck(t_list *list, char *prompt)
{
	t_list			*tmp;
	char			**cmd;
	char			*path;
	char			**path_tab;
	int				ret_built;

	tmp = list;
	ret_built = 0;
	prompt = ft_replace_char(prompt, ' ', '\t');
	cmd = ft_strsplit(prompt, ' ');
	if (ft_check_home_presence(list) == 1 && ft_check_tilde_presence(cmd) == 1)
	{
		cmd = ft_give_home_to_tilde(cmd, list);
	}
	else
		printf("home is not here\n");
	while (tmp)
	{
		if (ft_strncmp(tmp->content, "PATH=", ft_strlen("PATH=")) == 0)
			break ;
		tmp = tmp->next;
	}
	path = ft_strdup(tmp->content);
	path = ft_reduce_path(path);
	path_tab = ft_strsplit(path, ':');
	ret_built = ft_check_builtins(cmd[0]);
	if (ret_built > 0)
		ft_exec_builtins(ret_built, list, cmd);
	else
		ft_exec(path_tab, NULL, cmd);
}
