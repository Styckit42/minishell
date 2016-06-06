/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arg_builtins.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcabon <tcabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 22:30:48 by tcabon            #+#    #+#             */
/*   Updated: 2016/06/06 20:11:54 by tcabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_check_arg_setenv(char **cmd, t_list *list)
{
	unsigned int i;

	i = 0;
	if (!cmd[1])
	{
		ft_env(list);
		return (-1);
	}
	else if (cmd[3])
	{
		ft_putendl("test4");
		while (cmd[i])
		{
			ft_putendl(cmd[i]);
			i++;
		}
		ft_putendl("setenv: Too many arguments.");
		return (-1);
	}
	return (2);
}

int		ft_check_arg_unsetenv(char **cmd)
{
	if (!*cmd)
	{
		ft_putendl("unsetenv: Too few arguments.");
		return (-1);
	}
	else
		return (3);
}