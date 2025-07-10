
#include "../minishell.h"

int	count_commands(t_command *commands);
int	execute_command(t_command commands, char **envp, int n, int i);
int	is_built_in(char **args);
int	execute_built_in(char **args, char **envp);

int execute_commands(t_command *commands, char **envp)
{
	t_command	*aux;
	int			n;
	int			i;

	aux = commands;
	n = count_commands(commands);
	i = 0;
	while (i < n)
    {
		execute_command(*aux, envp, n, i);
		aux = aux->next;
		i++;
    }
	return (0);
}

int	count_commands(t_command *commands)
{
	int i;
	t_command *aux;

	i = 0;
	aux = commands;
	while (aux)
	{
		aux = aux -> next;
		i++;
	}
	return(i);
}

int execute_command(t_command command, char **envp, int n, int i)
{
	int			status;
	pid_t		pid;
	int			pipefd[2];
	static int	last_pipe = -1;

	if (is_built_in(command.args))
		return execute_built_in(command.args, envp);
	initialize_pipe(pipefd, i, n);
	pid = fork();
	if (pid == 0)
	{
		redirect_pipe(pipefd, i, n, last_pipe);
		execute_child(command, envp);
	}
	else if (pid > 0)
	{
		waitpid(pid, &status, 0);
		if (last_pipe != -1)
            close(last_pipe);
		if (i < n - 1)
			close(pipefd[1]);	
		if (i < n - 1)
			last_pipe = pipefd[0];
		else
			last_pipe = -1; 
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
    return 1;
}