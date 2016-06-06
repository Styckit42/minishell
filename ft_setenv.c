/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcabon <tcabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 20:29:43 by tcabon            #+#    #+#             */
/*   Updated: 2016/04/04 20:29:44 by tcabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list		*ft_setenv(t_list *list, char **arg)
{
	t_list *ret;

	ret = list;
	if (!arg || !*arg)
		return (list);
	else if (arg[2] != NULL)
	{
		ft_putstr("setenv: Too many arguments.\n");
		return (list);
	}
	while (list != NULL)
	{
		if (ft_strncmp(list->content, arg[0], ft_strlen(arg[0])) == 0)
		{
			if (!arg[1])
				list->content = ft_strjoin(arg[0], "=");
			else
				list->content = ft_strjoin(arg[0], ft_strjoin("=", arg[1]));
			return (ret);
		}
		list = list->next;
	}
	list = ret;
	ft_setenv_new_elem(list, arg);
	return (ret);
}
