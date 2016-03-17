#include "minishell.h"

char	**ft_cpyenv(char **env)
{
	char  **cpy_env;
	int   i;
 
	i = 0;
	if (!env[i])
		return (NULL);
	while (env[i] != NULL)
		i++;
	cpy_env = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (env[i] != NULL)
	{
    	cpy_env[i] = ft_strdup(env[i]);
    	i++;
    }
	cpy_env[i] = NULL;
	return (cpy_env);
}