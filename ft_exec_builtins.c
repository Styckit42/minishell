#include "minishell.h"

void		ft_exec_builtins(int ret_built, t_list *list, char **arg)
{
	int		ret;

	if (ret_built == 1)
		exit(1);
	else if (ret_built == 2 || ret_built == 3 || ret_built == 4)
	{
		if (ret_built == 2)
			ft_setenv(list, arg + 1);
		else if (ret_built == 3)
			ft_unsetenv(list, arg + 1);
		else if (ret_built == 4)
			ft_env(list);
	}
	else if (ret_built == 5)
	{
		ret = chdir(arg[1]);
		if (ret == 0)
			printf("ret = 0\n");
	}
}