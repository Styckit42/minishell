/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_catch_user.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcabon <tcabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 18:50:15 by tcabon            #+#    #+#             */
/*   Updated: 2016/05/31 21:40:15 by tcabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_catch_user(t_list *list)
{
	t_list	*tmp;
	char	*ret;

	tmp = list;
	while (tmp)
	{
		if (ft_strncmp(tmp->content, "USER=", ft_strlen("USER=")) == 0)
		{
			ret = ft_strdup(ft_strchr(tmp->content, '=') + 1);
			break ;
		}
		tmp = tmp->next;
	}
	if (tmp == NULL)
		return (NULL);
	return (ret);
}
