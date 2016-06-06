/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcabon <tcabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 21:48:31 by tcabon            #+#    #+#             */
/*   Updated: 2016/05/10 21:48:32 by tcabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list			*ft_unsetenv2(t_list *list, char *arg, \
	t_list *tmp2, t_list *cpy)
{
	unsigned int	ct;
	t_list			*tmp;

	ct = 0;
	while (cpy)
	{
		tmp = cpy;
		if (ft_strncmp(cpy->content, arg, \
		ft_value_len(cpy->content)) == 0 && ct == 0)
		{
			list = ft_unsetenv_first(list, cpy, tmp, tmp2);
			break ;
		}
		else if (ft_strncmp(cpy->content, arg, \
		ft_value_len(cpy->content)) == 0 && ct > 0)
		{
			list = ft_unsetenv_others(list, cpy, tmp, tmp2);
			break ;
		}
		if (ct > 0)
			tmp2 = tmp2->next;
		cpy = cpy->next;
		ct++;
	}
	return (list);
}
