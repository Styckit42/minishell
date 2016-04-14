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

void		ft_exec_builtins(int ret_built, t_list *list, char **arg)
{
	int		ret;

	if (ret_built == 1)
		exit(1);
	else if (ret_built == 2 || ret_built == 3 || ret_built == 4)
	{
		if (ret_built == 2)
			ft_setenv(list, arg + 1);
		else if (ret_built == 3)
			ft_unsetenv(&list, arg + 1);
		else if (ret_built == 4)
			ft_env(list);
	}
	else if (ret_built == 5)
	{
		ft_cd_hub(list, arg + 1);
	}
}
