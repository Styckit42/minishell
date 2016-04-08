/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcabon <tcabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 20:29:50 by tcabon            #+#    #+#             */
/*   Updated: 2016/04/04 20:29:51 by tcabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		main(int argc, char **argv, char **env)
{
	char	**cpy_env;

	(void)argc;
	(void)argv;
	cpy_env = ft_cpyenv(env);
	ft_launch(cpy_env);
	return (0);
}
