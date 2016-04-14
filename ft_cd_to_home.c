#include "minishell.h"

void	ft_cd_to_home(t_list *list, char **arg)
{
	char	*curpwd;

	curpwd = getcwd(NULL, 0);
	chdir(arg[0]);
	while (list)
	{
		if (ft_strncmp(list->content, "PWD", 3) == 0)
			list->content = ft_strjoin("PWD=", arg[0]);
		else if (ft_strncmp(list->content, "OLDPWD", 6) == 0)
			list->content = ft_strjoin("OLDPWD=", curpwd);
		list = list->next;
	}
}