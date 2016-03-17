#include "minishell.h"

int		main(int argc, char **argv, char **env)
{
	char	**cpy_env;

	(void)argc;
	(void)argv;
	cpy_env = ft_cpyenv(env);
	ft_launch(cpy_env);
	return (0);
}