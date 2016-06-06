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

int		ft_check_access_home(char **cmd)
{
	unsigned int i;

	i = 1;
	if (!cmd[i])
		return (1);
	else if (ft_strcmp(cmd[i], "~") == 0)
		return (1);
	else if (ft_strcmp(cmd[i], "home") == 0)
		return (1);
	return (0);
}

void	ft_give_home_to_cmd(char **cmd, t_list *list)
{
	t_list *tmp;

	tmp = list;
	while (tmp)
	{
		if (ft_strncmp(tmp->content, "HOME", 4) == 0)
			cmd[1] = ft_strdup(ft_strchr(tmp->content, '=') + 1);
		tmp = tmp->next;
	}
	ft_cd_to_home(list, cmd + 1);
}

char	*ft_give_home_tilde(t_list *list)
{
	t_list			*tmp;
	char			*ret;

	tmp = list;
	while (tmp)
	{
		if (ft_strncmp(tmp->content, "HOME", ft_strlen("HOME")) == 0)
		{
			ret = ft_strdup(ft_strchr(tmp->content, '=') + 1);
			return (ret);
		}
		tmp = tmp->next;
	}
	return (NULL);
}
