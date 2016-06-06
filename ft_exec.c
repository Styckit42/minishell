/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcabon <tcabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 20:27:18 by tcabon            #+#    #+#             */
/*   Updated: 2016/04/04 20:27:28 by tcabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_exec(char **path_tab, char **env, char **cmd, int i)
{
	pid_t			father;
	char			*altern_path;

	father = fork();
	if (father > 0)
		wait(NULL);
	if (father == 0)
	{
		if (path_tab)
			while (path_tab[++i])
			{
				altern_path = ft_strjoin(path_tab[i], "/");
				altern_path = ft_strjoin_delete(altern_path, cmd[0]);
				if (access(altern_path, X_OK) == 0)
				{
					execve(altern_path, cmd, env);
					break ;
				}
			}
		ft_exec_error(cmd);
		execve(cmd[0], cmd, env);
		exit(1);
	}
}
