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

void		ft_setenv(t_list *list, char **arg)
{
	t_list *tmp;

	tmp = list;
	if (!arg || !*arg || !list)
		return ;
	else if (arg[2] != NULL)
	{
		ft_putstr("setenv: Too many arguments.\n");
		return ;
	}
	while (list != NULL)
	{
		if (ft_strncmp(list->content, arg[0], ft_strlen(arg[0])) == 0)
		{
			list->content = ft_strjoin(arg[0], ft_strjoin("=", arg[1]));
			printf("sa passe");
		}
		list = list->next;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = ft_lstnew(ft_strjoin(arg[0], ft_strjoin("=", arg[1])),
		ft_strlen(ft_strjoin(arg[0], ft_strjoin("=", arg[1]))));
}
