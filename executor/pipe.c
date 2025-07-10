
#include "../minishell.h"

void initialize_pipe(int pipefd[2], int i, int n)
{
	if (n > 1 && i < n)
		pipe(pipefd);
}

void redirect_pipe(int pipefd[2], int i, int n, int last_pipe)
{
	if (last_pipe != -1)
	{
		if (dup2(last_pipe, STDIN_FILENO) == -1)
			exit(EXIT_FAILURE);
		close(last_pipe);
	}
	if (n > 1 && i < n - 1)
	{
		if (dup2(pipefd[1], STDOUT_FILENO) == -1)
			exit(EXIT_FAILURE);
		close(pipefd[1]);
	}
}
