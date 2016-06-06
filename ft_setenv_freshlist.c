/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv_freshlist.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcabon <tcabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 18:00:12 by tcabon            #+#    #+#             */
/*   Updated: 2016/05/13 18:00:14 by tcabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list		*ft_setenv_freshlist(char **arg)
{
	t_list		*list;

	if (arg[2])
	{
		ft_putstr("setenv: Too many arguments.\n");
		return (NULL);
	}
	else
	{
		if (!arg[1])
			list = ft_lstnew(ft_strjoin(arg[0], "="), ft_strlen(arg[0]) + 2);
		else
			list = ft_lstnew(ft_strjoin(ft_strjoin(arg[0], "="), arg[1]), \
				ft_strlen(arg[0]) + ft_strlen(arg[1]) + 2);
	}
	return (list);
}
