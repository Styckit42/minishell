#include "minishell.h"

void	ft_cd_to_oldpwd(t_list *list, char **arg)
{
	char *curpwd;
	char *oldpwd;
	t_list *tmp;

	tmp = list;
	curpwd = getcwd(NULL, 0);
	while (list)
	{
		if (ft_strncmp(list->content, "OLDPWD", 6) == 0)
		{
			chdir(ft_strchr(list->content, '=') + 1);
			oldpwd = ft_strchr(list->content, '=') + 1;
			list->content = ft_strjoin("OLDPWD=", curpwd);
		}
		list = list->next;
	}
	list = tmp;
	while (list)
	{
		if (ft_strncmp(list->content, "PWD", 3) == 0)
		{
			list->content = ft_strjoin("PWD=", oldpwd);
		}
		list = list->next;
	}
}