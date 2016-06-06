/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_hub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcabon <tcabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 19:50:17 by tcabon            #+#    #+#             */
/*   Updated: 2016/05/03 19:50:20 by tcabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_cd_hub(t_list *list, char **arg)
{
	unsigned int i;

	i = 0;
	if (ft_check_access_home(arg) == 1)
	{
		if (ft_check_home_presence(list) == 1)
			ft_give_home_to_cmd(arg, list);
		else
			return ;
	}
	else if (ft_strcmp(arg[1], "-") == 0)
		ft_cd_to_oldpwd(list, arg);
	else if ((ft_strcmp(arg[1], "-") != 0) && (arg[1]))
		ft_cd_to_path(list, arg[1]);
}
