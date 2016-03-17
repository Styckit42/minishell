/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcabon <tcabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 12:48:58 by tcabon            #+#    #+#             */
/*   Updated: 2014/11/10 17:30:16 by tcabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*s2;
	char	search;

	search = (char)c;
	i = 0;
	s2 = (char*)s;
	while (s2[i])
	{
		if (s2[i] == search)
			return (&s2[i]);
		i++;
	}
	if (s2[i] == search)
		return (&s2[i]);
	return (NULL);
}
