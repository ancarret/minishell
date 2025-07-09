/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarret <ancarret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 11:06:35 by ancarret          #+#    #+#             */
/*   Updated: 2025/07/09 12:49:25 by ancarret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void initialize_data(t_data *data, char **envp)
{
    int i;
    int count;
    
    data->commands = NULL;
    data->input_line = NULL;
    data->tokens = NULL;
    count = 0;
    while (envp[count])
        count++;
    data->envp = malloc(sizeof(char *) * (count + 1));
    i = 0;
    while (i < count)
    {
        data->envp[i] = ft_strdup(envp[i]);
        i++;
    }
    data->envp[i] = NULL;
    
}

void free_env(char **envp)
{
    int i = 0;
    if (!envp)
        return;
    while (envp[i])
    {
        free(envp[i]);
        i++;
    }
    free(envp);
}

void cleanup_iteration(t_data *data, char *prompt)
{
    if (data->input_line)
    {
        free(data->input_line);
        data->input_line = NULL;
    }
    if (prompt)
        free(prompt);
}

char *get_prompt(void)
{
    char *cwd;
    char *tmp1;
    char *tmp2;
    char *prompt;

    cwd = getcwd(NULL, 0);
    if (!cwd)
        return (ft_strdup(GREEN "$ minishell> " WHITE));
    tmp1 = ft_strjoin(BLUE, cwd);
    tmp2 = ft_strjoin(tmp1, WHITE " ");
    free(tmp1);
    tmp1 = ft_strjoin(tmp2, GREEN "$ minishell> " WHITE);
    free(tmp2);
    free(cwd);
    prompt = tmp1;
    return (prompt);
 }

int main(int argc, char **argv, char **envp)
{
    char *prompt;
    t_data data;

	(void)argc;
	(void)argv;
  initialize_data(&data, envp);
  while(1)
  {
      prompt = get_prompt();
      data.input_line = readline(prompt);
      if (!data.input_line)
      {
          cleanup_iteration(&data, prompt);
          break ;
      }
      add_history(data.input_line);
      lexer(&data);
      parser(&data);
      execute_commands(data.commands, envp);
      cleanup_iteration(&data, prompt);
  }
  free_env(data.envp);
  return (0);
}
