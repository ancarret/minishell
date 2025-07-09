
#include "../minishell.h"

int	execute_command(t_command commands, char **envp);
int	is_built_in(char **args);
int	execute_built_in(char **args, char **envp);

int execute_commands(t_command *commands, char **envp)
{
	t_command	*aux;

	aux = commands;
	while (aux)
    {
		execute_command(*aux, envp);
		aux = aux->next;
    }
	return (0);
}

int execute_command(t_command command, char **envp)
{
	int		status;
	pid_t	pid;

	if (is_built_in(command.args))
		return execute_built_in(command.args, envp);

	pid = fork();
	if (pid == 0)
	{
		execute_child(command, envp);
	}
	else if (pid > 0)
	{
		waitpid(pid, &status, 0);
	}
	else
	{
		perror("fork");
		return 1;
	}
	return (status);
}

int is_built_in(char **args)
{
    if (!args || !args[0])
        return 0;
    if (ft_strcmp(args[0], "pwd") == 0)
        return 1;
    if (ft_strcmp(args[0], "echo") == 0)
        return 1;
    if (ft_strcmp(args[0], "env") == 0)
        return 1;
    return 0;
}

int execute_built_in(char **args, char **envp)
{
    if (ft_strcmp(args[0], "pwd") == 0)
        return ft_pwd();
    if (ft_strcmp(args[0], "echo") == 0)
        return ft_echo(args);
    if (ft_strcmp(args[0], "env") == 0)
        return ft_env(envp);
    return 0;
}