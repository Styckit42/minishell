#include "minishell.h"

char	*ft_replace_char(char *str, char c, char d)
{
	unsigned int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == d)
			str[i] = c;
		i++;
	}
	return (str);
}

char	*ft_reduce_path(char *path)
{
	while (*path != '=')
		path++;
	if (*path == '=')
		path++;
	return (path);
}