/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_launch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcabon <tcabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 20:29:20 by tcabon            #+#    #+#             */
/*   Updated: 2016/06/06 20:33:24 by tcabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_launch(char **env, t_list *list)
{
	char		c[2];
	char		*prompt;
	char		*user;
	char		*user_prompt;

	while (1)
	{
		user = ft_catch_user(list);
		prompt = (char *)malloc(sizeof(char) * 1);
		ft_bzero(prompt, ft_strlen(prompt));
		user_prompt = ft_strjoin_delete(user, "$> ");
		ft_putstr(user_prompt);
		while (1)
		{
			read(0, c, 1);
			if (c[0] == '\n')
				break ;
			c[1] = '\0';
			prompt = ft_strjoin_delete(prompt, (char *)c);
		}
		if (ft_check_prompt(prompt) == 1)
			ft_argcheck(&list, prompt, env);
		free(user_prompt);
		//free(prompt);
	}
}
