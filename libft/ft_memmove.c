/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcabon <tcabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 17:22:48 by tcabon            #+#    #+#             */
/*   Updated: 2014/11/10 17:06:56 by tcabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	void	*temp;

	temp = NULL;
	if (n)
		temp = malloc(n);
	if (temp)
	{
		ft_memcpy(temp, src, n);
		ft_memcpy(dest, temp, n);
		free(temp);
	}
	return (dest);
}
