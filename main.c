/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcabon <tcabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 20:29:50 by tcabon            #+#    #+#             */
/*   Updated: 2016/05/31 22:17:30 by tcabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		main(int argc, char **argv, char **env)
{
	char	**cpy_env;
	t_list	*list;

	(void)argc;
	(void)argv;
	cpy_env = ft_cpyenv(env);
	list = ft_tab_to_list(cpy_env);
	ft_launch(cpy_env, list);
	return (0);
}
