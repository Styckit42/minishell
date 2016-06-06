/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_to_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcabon <tcabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 19:52:15 by tcabon            #+#    #+#             */
/*   Updated: 2016/05/03 19:52:16 by tcabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_cd_to_path(t_list *list, char *target)
{
	t_list	*tmp;
	char	*curpwd;

	tmp = list;
	curpwd = getcwd(NULL, 0);
	if (chdir(target) == -1)
		ft_cd_error(target, list);
	else
	{
		while (list)
		{
			if (ft_strncmp(list->content, "OLDPWD=", 7) == 0)
				list->content = ft_strjoin("OLDPWD=", curpwd);
			list = list->next;
		}
		list = tmp;
		curpwd = getcwd(NULL, 0);
		while (list)
		{
			if (ft_strncmp(list->content, "PWD=", 4) == 0)
				list->content = ft_strjoin("PWD=", curpwd);
			list = list->next;
		}
	}
}
