/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cpyenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcabon <tcabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 20:30:35 by tcabon            #+#    #+#             */
/*   Updated: 2016/04/04 20:30:36 by tcabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_cpyenv(char **env)
{
	char		**cpy_env;
	int			i;

	i = 0;
	if (!env[i])
		return (NULL);
	while (env[i] != NULL)
		i++;
	cpy_env = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (env[i] != NULL)
	{
		cpy_env[i] = ft_strdup(env[i]);
		i++;
	}
	cpy_env[i] = NULL;
	return (cpy_env);
}
