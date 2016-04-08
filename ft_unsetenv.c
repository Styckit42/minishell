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

void		ft_unsetenv(t_list **list, char **arg)
{
	unsigned int		i;
	unsigned int		ct;
	t_list				*cpy;
	t_list				*tmp;
	t_list				*tmp2;

	i = 0;
	if (!arg || !*arg || !list)
		return ;
	while (arg[i])
	{
		ct = 0;
		cpy = *list;
		tmp2 = *list;
		while (cpy)
		{
			tmp = cpy;
			if (ft_strncmp(cpy->content, arg[i], ft_value_len(cpy->content)) == 0 && ct == 0)
			{
				cpy = cpy->next;
				ft_lstdelone(list, ft_del_unset);
				tmp2 = cpy;
				break;
			}
			else if (ft_strncmp(cpy->content, arg[i], ft_value_len(cpy->content)) == 0 && ct > 0)
			{
				cpy = cpy->next;
				ft_lstdelone(&tmp, ft_del_unset);
				tmp2->next = cpy;
				break;
			}
			if (ct > 0)
				tmp2 = tmp2->next;
			cpy = cpy->next;
			ct++;
		}
		i++;
	}
}
