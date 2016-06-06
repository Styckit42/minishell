/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcabon <tcabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 18:08:36 by tcabon            #+#    #+#             */
/*   Updated: 2014/11/06 18:09:45 by tcabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*cpy;

	if (!s)
		return (NULL);
	cpy = ft_strnew(len + 1);
	if (!cpy)
		return (NULL);
	s += start;
	cpy = ft_strncpy(cpy, s, len);
	cpy[len] = 0;
	return (cpy);
}
