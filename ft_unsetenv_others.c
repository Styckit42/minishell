/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv_others.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcabon <tcabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 21:36:28 by tcabon            #+#    #+#             */
/*   Updated: 2016/05/10 21:36:30 by tcabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list		*ft_unsetenv_others(t_list *list, t_list *cpy, \
	t_list *tmp, t_list *tmp2)
{
	cpy = cpy->next;
	ft_lstdelone(&tmp, ft_del_unset);
	tmp2->next = cpy;
	return (list);
}
