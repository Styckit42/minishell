/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcabon <tcabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 13:15:25 by tcabon            #+#    #+#             */
/*   Updated: 2014/11/10 17:36:39 by tcabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char const *s, int c)
{
	int		i;
	char	*s2;
	char	search;
	int		mem;

	search = (char)c;
	i = 0;
	mem = -1;
	s2 = (char*)s;
	while (s2[i])
	{
		if (s2[i] == search)
			mem = i;
		i++;
	}
	if (s2[i] == search)
		mem = i;
	if (mem == -1)
		return (NULL);
	return (&s2[mem]);
}
