/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcabon <tcabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 20:30:18 by tcabon            #+#    #+#             */
/*   Updated: 2016/04/04 20:30:19 by tcabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list		*ft_unsetenv(t_list *list, char **arg)
{
	unsigned int		i;
	t_list				*cpy;
	t_list				*tmp;
	t_list				*tmp2;

	i = 0;
	if (!arg || !*arg || !list)
		return (NULL);
	while (arg[i])
	{
		cpy = list;
		tmp2 = list;
		list = ft_unsetenv2(list, arg[i], tmp2, cpy);
		i++;
	}
	return (list);
}
