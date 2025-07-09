
#include "../minishell.h"

char	*find_path(char *cmd, char **envp);
char 	*get_env_var(char **envp, char *name);
char	*find_absolute_path(char *cmd, char *env_path);

void execute_child(t_command cmd, char **envp)
{
	char *path;

	path = find_path(cmd.args[0], envp);
	execve(path, cmd.args, envp);
	perror("execve");
	exit(127);
}

char *find_path(char *cmd, char **envp)
{
	char	*env_path;
	char	*path;

	if (strchr(cmd, '/'))
	{
        if (access(cmd, X_OK) == 0)
            return strdup(cmd);
        else
            return NULL;
    }
	env_path = get_env_var(envp, "PATH");
	path = find_absolute_path(cmd, env_path);
	if (path)
		return (path);
	return (NULL);
}
char *get_env_var(char **envp, char *name)
{
	int len;
	int i;
	
	len = ft_strlen(name);
	i = 0;
	while (envp[i])
	{
		if (strncmp(envp[i], name, len) == 0 && envp[i][len] == '=')
			return (envp[i] + len + 1);
		i++;
	}
	return NULL;
}

char	*find_absolute_path(char *cmd, char *env_path)
{
	char	**paths;
	char	*aux;
	int		i;

	paths = ft_split(env_path, ':');
	i = 0;
	while (paths[i])
	{
		aux = ft_strjoin(paths[i], "/");
		aux = ft_strjoin(aux, cmd);
		if (access(aux, X_OK) == 0)
		{
			free(paths);
			return (aux);
		}
		i++;
	}
	return (NULL);
}
