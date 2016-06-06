/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv_new_elem.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcabon <tcabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 18:31:48 by tcabon            #+#    #+#             */
/*   Updated: 2016/05/19 18:31:50 by tcabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_setenv_new_elem(t_list *tmp, char **arg)
{
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = ft_lstnew(ft_strjoin(arg[0], ft_strjoin("=", arg[1])),
		ft_strlen(ft_strjoin(arg[0], ft_strjoin("=", arg[1]))));
}
