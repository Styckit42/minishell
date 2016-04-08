/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcabon <tcabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 13:20:34 by tcabon            #+#    #+#             */
/*   Updated: 2014/11/10 17:36:53 by tcabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char const *s1, char const *s2)
{
	size_t	pos;

	if (!*s2)
		return ((char *)s1);
	pos = ft_strlen(s2);
	while (*s1)
	{
		if (ft_strncmp(s1++, s2, pos) == 0)
			return ((char *)s1 - 1);
	}
	return (NULL);
}
