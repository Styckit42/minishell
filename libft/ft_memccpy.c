/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcabon <tcabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 20:45:18 by tcabon            #+#    #+#             */
/*   Updated: 2015/02/02 17:11:48 by tcabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	char		*dest;
	const char	*src;

	dest = (char*)s1;
	src = (char*)s2;
	if (n)
	{
		while (*src != c && n--)
			*dest++ = *src++;
		if (*src == c && n > 0)
		{
			*dest++ = *src;
			return (dest);
		}
	}
	return (NULL);
}
