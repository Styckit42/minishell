/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcabon <tcabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 17:42:28 by tcabon            #+#    #+#             */
/*   Updated: 2014/12/09 17:13:20 by tcabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*str_nrealloc(char *dest, const char *src, size_t len)
{
	char	*cpy;

	cpy = ft_strnew(ft_strlen(dest) + len);
	cpy = ft_strcpy(cpy, dest);
	cpy = ft_strncat(cpy, src, len);
	free(dest);
	return (cpy);
}

static int		get_line(char **line, char **buf, char *p, size_t len)
{
	char	*cpy;

	*line = str_nrealloc(*line, *buf, len);
	cpy = ft_strnew(BUFF_SIZE);
	cpy = ft_strcpy(cpy, p + 1);
	free(*buf);
	*buf = cpy;
	return (1);
}

int				get_next_line(int const fd, char **line)
{
	int			ret;
	static char	*buf = NULL;
	char		*p;

	if (buf)
	{
		*line = ft_strnew(0);
		if ((p = ft_strchr(buf, '\n')))
			return (get_line(line, &buf, p, ft_strlen(p - buf)));
		*line = str_nrealloc(*line, buf, ft_strlen(buf));
	}
	else
	{
		buf = ft_strnew(BUFF_SIZE);
		*line = ft_strnew(0);
	}
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if ((p = strchr(buf, '\n')))
			return (get_line(line, &buf, p, p - buf));
		*line = str_nrealloc(*line, buf, ret);
	}
	return (ret);
}
