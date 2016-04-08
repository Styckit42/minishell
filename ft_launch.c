/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcabon <tcabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 20:29:20 by tcabon            #+#    #+#             */
/*   Updated: 2016/04/04 20:29:22 by tcabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_launch(char **env)
{
	char		c[2];
	char		toto[1024];
	t_list		*list;

	list = ft_tab_to_list(env);
	while (1)
	{
		ft_bzero(toto, 1024);
		ft_putstr("$> ");
		while (1)
		{
			read(0, c, 1);
			if (c[0] == '\n')
				break ;
			c[1] = '\0';
			ft_strcat(toto, (char *)c);
		}
		if (ft_check_prompt(toto) == 1)
			ft_argcheck(list, toto);
	}
}
