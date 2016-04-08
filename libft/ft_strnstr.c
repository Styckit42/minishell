/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcabon <tcabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 13:09:38 by tcabon            #+#    #+#             */
/*   Updated: 2014/11/08 17:46:35 by tcabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char const *s1, char const *s2, size_t n)
{
	size_t	i;
	char	*s2cpy;
	char	*s1cpy;
	int		len;

	if (*s2 == '\0')
		return ((char *)s1);
	s2cpy = (char *)s2;
	s1cpy = (char *)s1;
	len = ft_strlen(s2cpy);
	i = 0;
	while (s1cpy[i] && (i + len) <= n)
	{
		if (ft_strncmp(s1 + i, s2, len) == 0)
			return (s1cpy + i);
		i++;
	}
	return (NULL);
}
