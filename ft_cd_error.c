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

void	ft_cd_error(char *path, char *argu)
{
	struct stat			file;

	stat(path, &file);
	if (!S_ISDIR(file.st_mode) && S_ISREG(file.st_mode))
	{
		argu++;
		ft_putstr(ft_strjoin(argu, ": Not a directory.\n"));
	}
	else if (!S_ISDIR(file.st_mode) && !S_ISREG(file.st_mode))
	{
		argu++;
		ft_putstr(ft_strjoin(argu, ": No such file or directory.\n"));
	}
}
