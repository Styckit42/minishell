/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcabon <tcabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 19:59:53 by tcabon            #+#    #+#             */
/*   Updated: 2015/01/30 16:27:14 by tcabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnchr(char *s, size_t n, int c)
{
	int i;

	i = 0;
	while (s[i])
	{
		while (i <= n)
		{
			if (s[i] == c)
				return (&s[i]);
			i++;
		}
	}
	return (NULL);
}