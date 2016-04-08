/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcabon <tcabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 20:29:32 by tcabon            #+#    #+#             */
/*   Updated: 2016/04/04 20:29:34 by tcabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_cd(t_list *list, char **arg)
{
	char *curpwd;
	char *newpwd;
	char *argu;
	char *path;

	argu = arg[0];
	printf("arg[0] = %s\n", arg[0]);
	if (arg[1] != NULL)
	{
		ft_putstr("cd: Too many arguments.\n");
		return ;
	}
	/*if (argu == NULL || ft_strcmp(argu, "~") == 0)
	{
		ft_cd_to_home(list, )
		return ;
	}*/
	if (argu[0] != '/')
		argu = ft_strjoin("/", argu);
	printf("argu = %s\n", argu);
	curpwd = getcwd(NULL, 0);
	printf("curpwd = %s\n", curpwd);
	path = ft_strjoin(curpwd, argu);
	printf("path = %s\n", path);
	if (chdir(path) == -1)
		ft_cd_error(path, argu);
	newpwd = getcwd(NULL, 0);
	while (list)
	{
		if (ft_strncmp(list->content, "PWD", 3) == 0)
		{
			list->content = ft_strdup(ft_strjoin("PWD=", newpwd));
		}
		list = list->next;
	}
}
