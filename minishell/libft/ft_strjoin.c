/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcabon <tcabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 18:34:57 by tcabon            #+#    #+#             */
/*   Updated: 2014/11/10 17:34:09 by tcabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*strnew;
	int		tailles1;
	int		tailles2;

	if (!s1 && !s2)
		return (NULL);
	tailles1 = (s1 != NULL) ? ft_strlen(s1) : 0;
	tailles2 = (s2 != NULL) ? ft_strlen(s2) : 0;
	strnew = (char *)malloc(tailles1 + tailles2 + 1);
	if (strnew == NULL)
		return (NULL);
	strnew[tailles1 + tailles2] = 0;
	strnew[0] = 0;
	if (tailles1 != 0)
		ft_strcat(strnew, s1);
	if (tailles2 != 0)
		ft_strcat(strnew, s2);
	return (strnew);
}
