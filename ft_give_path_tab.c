/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_give_path_tab.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcabon <tcabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 18:54:30 by tcabon            #+#    #+#             */
/*   Updated: 2016/06/06 19:53:03 by tcabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_give_path_tab(t_list **list)
{
	t_list		*tmp;
	char		*path;
	char		**path_tab;

	tmp = *list;
	while (tmp)
	{
		if (ft_strncmp(tmp->content, "PATH=", ft_strlen("PATH=")) == 0)
			break ;
		tmp = tmp->next;
	}
	if (tmp != NULL)
	{
		path = ft_strdup(ft_strchr(tmp->content, '=') + 1);
		path_tab = ft_strsplit(path, ':');
	}
	else
		return (NULL);
	free(path);
	return (path_tab);
}
