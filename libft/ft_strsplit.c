/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcabon <tcabon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 17:00:05 by tcabon            #+#    #+#             */
/*   Updated: 2015/05/19 18:54:44 by tcabon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wordslen(char const *s, char c)
{
	size_t i;

	i = 0;
	if (s && c)
	{
		while (s[i] && s[i] != c)
			i++;
	}
	return (i);
}

static char		**ft_splitwords(char const *s, char **freshtab, char c)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (s)
	{
		while (s[i])
		{
			if (s[i] != c)
			{
				freshtab[j] = ft_strsub(s, i, ft_wordslen(&s[i], c));
				i = i + ft_wordslen(&s[i], c);
				j++;
			}
			else
				i++;
		}
	}
	return (freshtab);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	i;
	int		j;
	char	**freshtab;

	i = 0;
	j = 0;
	if (s)
	{
		while (s[i])
		{
			if (s[i] != c && (((i != 0 && s[i - 1] == c) || i == 0)))
				j++;
			i++;
		}
	}
	freshtab = (char**)malloc(sizeof(freshtab) * (j + 1));
	if (freshtab == NULL)
		return (NULL);
	while (j != -1)
	{
		freshtab[j] = NULL;
		j--;
	}
	freshtab = ft_splitwords(s, freshtab, c);
	return (freshtab);
}
