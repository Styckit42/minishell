/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_builtins.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcabon <tcabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 20:27:37 by tcabon            #+#    #+#             */
/*   Updated: 2016/06/06 20:09:17 by tcabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*int		ft_check_builtins(char *str)
{
	int		ret;

	ret = 0;
	if (ft_strcmp(str, "exit") == 0)
		ret = 1;
	else if (ft_strcmp(str, "setenv") == 0)
		ret = 2;
	else if (ft_strcmp(str, "unsetenv") == 0)
		ret = 3;
	else if (ft_strcmp(str, "env") == 0)
		ret = 4;
	else if (ft_strcmp(str, "cd") == 0)
		ret = 5;
	return (ret);
}*/

int		ft_check_builtins(char **cmd, t_list *list)
{
	int			ret;

	ret = 0;
	ft_putendl("test3");
	while (cmd[ret])
	{
		ft_putendl(cmd[ret]);
		ret++;
	}
	ret = 0;
	if (ft_strcmp(cmd[0], "exit") == 0)
		ret = 1;
	else if (ft_strcmp(cmd[0], "setenv") == 0)
	{
		ret = ft_check_arg_setenv(cmd, list);
	}
	else if (ft_strcmp(cmd[0], "unsetenv") == 0)
		ret = ft_check_arg_unsetenv(cmd + 1);
	else if (ft_strcmp(cmd[0], "env") == 0)
		ret = 4;
	else if (ft_strcmp(cmd[0], "cd") == 0)
		ret = 5;
	return (ret);
}

void	ft_env(t_list *list)
{
	ft_lstiter(list, ft_print_env_list);
}

void	ft_print_env_list(t_list *list)
{
	ft_putendl(list->content);
}

void	ft_del_unset(void *content, size_t content_size)
{
	(void)content_size;
	free(content);
}

int		ft_value_len(char *content)
{
	unsigned int i;

	i = 0;
	while (content[i] != '=')
		i++;
	return (i);
}
