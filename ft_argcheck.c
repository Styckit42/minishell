/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argcheck.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcabon <tcabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 20:29:07 by tcabon            #+#    #+#             */
/*   Updated: 2016/06/06 20:36:25 by tcabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_argcheck(t_list **list, char *prompt, char **env)
{
	char			**cmd;
	char			**path_tab;
	int				ret_built;
	int				i;
	char			*tilde;

	i = 0;
	ret_built = 0;
	prompt = ft_replace_char(prompt, ' ', '\t');
	ft_putendl("test du prompt");
	ft_putendl(prompt);
	cmd = ft_strsplit(prompt, ' ');
	free(prompt);
	ft_putendl("test0");
	if (cmd[2])
	{
		ft_putendl("un gros prout !!");
		while (cmd[i])
		{
			ft_putendl(cmd[i]);
			i++;
		}
	}
	else if (cmd[3])
	{
		ft_putendl("un tres tres gros prout qui rend ouf");
		while (cmd[i])
		{
			ft_putendl(cmd[i]);
			i++;
		}
	}
	else if (!cmd[3])
		ft_putendl("un petit prout tranquil");
	i = 0;
	ft_putendl("test1");
	while (cmd[i])
	{
		ft_putendl(cmd[i]);
		i++;
	}
	i = 0; //a retirer
	while (cmd[i])
	{
		if (cmd[i][0] == '~' && cmd[i][1] == '\0')
			cmd[i] = ft_give_home_tilde(*list);
		i++;
	}
	i = 0;
	path_tab = ft_give_path_tab(list);
	ft_putendl("test2");
	while (cmd[i])
	{
		ft_putendl(cmd[i]);
		i++;
	}
	ret_built = ft_check_builtins(cmd, *list);
	i = 0; // a retirer;
	ft_putendl("test5");
	while (cmd[i])
	{
		ft_putendl(cmd[i]);
		i++;
	}
	if (ret_built > 0)
		ft_exec_builtins(ret_built, list, cmd);
	else if (ret_built == 0)
		ft_exec(path_tab, env, cmd, i - 1);
	ft_free_tab(path_tab);
}
