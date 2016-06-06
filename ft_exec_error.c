/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcabon <tcabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 22:28:56 by tcabon            #+#    #+#             */
/*   Updated: 2016/05/20 22:28:57 by tcabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_exec_error(char **cmd)
{
	struct stat			file;

	stat(cmd[0], &file);
	if (access(cmd[0], F_OK) == -1)
		ft_putendl(ft_strjoin(cmd[0], ": Command not found."));
	else if (access(cmd[0], X_OK) == -1)
		ft_putendl(ft_strjoin(cmd[0], ": Permission denied."));
}
