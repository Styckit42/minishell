/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_access_home.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcabon <tcabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 19:49:08 by tcabon            #+#    #+#             */
/*   Updated: 2016/05/03 19:49:19 by tcabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_access_home(char **cmd, t_list **list)
{
	if (ft_check_home_presence(*list) == 1 && ft_check_access_home(cmd) == 1)
	{
		ft_give_home_to_cmd(cmd, *list);
		return ;
	}
}
