/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_to_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcabon <tcabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/19 20:56:12 by tcabon            #+#    #+#             */
/*   Updated: 2016/05/19 20:56:13 by tcabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_tab_to_list(char **tab)
{
	int				i;
	t_list			*newlist;

	if (tab == NULL || tab[0] == NULL)
		return (NULL);
	i = 0;
	while (tab[i])
		i++;
	i -= 1;
	newlist = ft_lstnew(tab[i], ft_strlen(tab[i]));
	i--;
	while (i >= 0)
	{
		ft_lstadd(&newlist, ft_lstnew(tab[i], ft_strlen(tab[i]) + 1));
		i--;
	}
	return (newlist);
}
