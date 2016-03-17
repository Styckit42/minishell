/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcabon <tcabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 14:21:48 by tcabon            #+#    #+#             */
/*   Updated: 2014/11/06 14:26:29 by tcabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*mem;
	size_t	i;
	char	*str;

	i = 0;
	mem = (void*)malloc(size);
	str = (char*)mem;
	if (mem != NULL)
	{
		while (i++ < size)
			*str++ = 0;
	}
	return (mem);
}
