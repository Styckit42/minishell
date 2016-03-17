#include "minishell.h"

void		ft_launch(char **env)
{
	char 	c[2];
	char	toto[1024];
	t_list	*list;

	list = ft_tab_to_list(env);
	while (1)
	{
		ft_bzero(toto, 1024);
		ft_putstr("$> ");
		while (1)
		{
			read(0, c, 1);
			if (c[0] == '\n')
				break;
			c[1]='\0';
			ft_strcat(toto, (char *)c);
		}
		ft_argcheck(list, toto);
	}
}