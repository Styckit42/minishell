/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_builtins.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcabon <tcabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 20:28:55 by tcabon            #+#    #+#             */
/*   Updated: 2016/04/04 20:28:57 by tcabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_exec_builtins(int ret_built, t_list **list, char **arg)
{
	int		ret;
	int		exit_ret;

	if (ret_built == 1)
	{
		if (arg[1])
			exit_ret = ft_atoi(arg[1]);
		else
			exit_ret = 0;
		exit(exit_ret);
	}
	else if (ret_built == 2 || ret_built == 3 || ret_built == 4)
	{
		if (ret_built == 2)
			if (!*list)
				*list = ft_setenv_freshlist(arg + 1);
			else
				*list = ft_setenv(*list, arg + 1);
		else if (ret_built == 3)
			*list = ft_unsetenv(*list, arg + 1);
		else if (ret_built == 4)
			ft_env(*list);
	}
	else if (ret_built == 5)
		ft_cd_hub(*list, arg);
}
