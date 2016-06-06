/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcabon <tcabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 20:30:00 by tcabon            #+#    #+#             */
/*   Updated: 2016/04/04 20:30:01 by tcabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_cd_error(char *target, t_list *list)
{
	struct stat			file;

	stat(target, &file);
	if (!S_ISDIR(file.st_mode) && S_ISREG(file.st_mode))
		ft_putstr(ft_strjoin(target, ": Not a directory.\n"));
	else if (!S_ISDIR(file.st_mode) && !S_ISREG(file.st_mode))
		ft_putstr(ft_strjoin(target, ": No such file or directory.\n"));
	else if ((S_ISDIR(file.st_mode) || S_ISREG(file.st_mode)) && \
		access(target, R_OK) == -1)
		ft_putstr(ft_strjoin(target, ": Permission denied.\n"));
}
