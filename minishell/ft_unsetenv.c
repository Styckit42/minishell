#include "minishell.h"

void		ft_unsetenv(t_list *list, char **arg)
{
	unsigned int i;
	t_list	*tmp;

	tmp = list;

	i = 0;
	if (!arg || !*arg || !list)
		return ;
	while (arg[i])
	{
		if (ft_strncmp(list->content, arg[0], ft_strlen(arg[0])) == 0)
		{
			ft_lstdel(list, ft_del_unset(list->content, list->content_size));
		}
		i++;
	}
}