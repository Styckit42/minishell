#include "minishell.h"

int		ft_check_builtins(char *str)
{
	int		ret;

	ret = 0;
	if (ft_strcmp(str, "exit") == 0)
		ret = 1;
	else if (ft_strcmp(str, "setenv") == 0)
		ret = 2;
	else if (ft_strcmp(str, "unsetenv") == 0)
		ret = 3;
	else if (ft_strcmp(str, "env") == 0)
		ret = 4;
	else if (ft_strcmp(str, "cd") == 0)
		ret = 5;
	return (ret);
}

void	ft_env(t_list *list)
{
	ft_lstiter(list, ft_print_env_list);
}

void	ft_print_env_list(t_list *list)
{
	ft_putendl(list->content);
}

void	ft_del_unset()
{
	free()
}