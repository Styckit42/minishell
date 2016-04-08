/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcabon <tcabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 20:30:55 by tcabon            #+#    #+#             */
/*   Updated: 2016/04/04 20:30:58 by tcabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_replace_char(char *str, char c, char d)
{
	unsigned int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == d)
			str[i] = c;
		i++;
	}
	return (str);
}

char	*ft_reduce_path(char *path)
{
	while (*path != '=')
		path++;
	if (*path == '=')
		path++;
	return (path);
}

int		ft_check_prompt(char *str)
{
	unsigned int	i;
	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			return (1);
		i++;
	}
	return (0);
}
