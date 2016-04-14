#include "minishell.h"

void		ft_cd_hub(t_list *list, char **arg)
{
	if (ft_strcmp(arg[0], "-") == 0)
		ft_cd_to_oldpwd(list, arg);
	//else

	

}