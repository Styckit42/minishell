/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_home.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcabon <tcabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 20:19:06 by tcabon            #+#    #+#             */
/*   Updated: 2016/04/08 20:19:08 by tcabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_check_home_presence(t_list *list)
{
	while (list)
	{
		if (ft_strncmp(list->content, "HOME", 4) == 0)
			return (1);
		list = list->next;
	}
	return (0);
}

int		ft_check_tilde_presence(char **cmd)
{
	unsigned int i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i][0] == '~' && cmd[i][1] == '\0')
			return (1);
		i++;
	}
	return (0);
}

char	**ft_give_home_to_tilde(char **cmd, t_list *list)
{
	unsigned int i;

	i = 0;
	while (cmd[i])
	{
		if (ft_strcmp(cmd[i], "~") == 0)
		{
			cmd[i] = ft_strdup(list->content);
			break;
		}
		i++;
	}
	while (list)
	{
		if (ft_strncmp(list->content, "HOME", 4) == 0)
		{
			cmd[i] = ft_strdup(ft_strchr(list->content, '=') + 1);
			printf("test cmd[~] = %s\n", cmd[i]);
			break;
		}
		list = list->next;
	}
	return (cmd);
}