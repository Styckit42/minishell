/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv_first.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcabon <tcabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 21:31:31 by tcabon            #+#    #+#             */
/*   Updated: 2016/05/10 21:31:34 by tcabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list		*ft_unsetenv_first(t_list *list, t_list *cpy, \
	t_list *tmp, t_list *tmp2)
{
	cpy = cpy->next;
	ft_lstdelone(&tmp, ft_del_unset);
	tmp2 = cpy;
	list = cpy;
	return (list);
}
