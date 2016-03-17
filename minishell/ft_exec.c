#include "minishell.h"

void	ft_exec(char **path_tab, char **env, char **cmd)
{
	pid_t		father;
	char		*altern_path;
	unsigned int i;

	i = 0;
	father = fork();
	if (father > 0)
	{
		wait(NULL);
	}
	if (father == 0)
	{
		if (access(cmd[0], X_OK) != -1)
			execve(*cmd, cmd, env);
		else
		{
			while (path_tab[i])
			{
				altern_path = ft_strjoin(path_tab[i], "/");
				altern_path = ft_strjoin_delete(altern_path, cmd[0]);
				printf("altern_path = %s\n", altern_path);
				if (access(altern_path, X_OK) != -1)
					execve(altern_path, cmd, env);
				i++;
			}
			ft_putstr(ft_strjoin(cmd[0], ": Command not found.\n"));
			exit(1);
		}
	}
}