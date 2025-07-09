/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarret <ancarret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 11:06:35 by ancarret          #+#    #+#             */
/*   Updated: 2025/07/09 12:26:29 by ancarret         ###   ########.fr       */
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

void cleanup_iteration(t_data *data, char *cwd, char *prompt)
{
    if (data->input_line)
    {
        free(data->input_line);
        data->input_line = NULL;
    }
    if (cwd)
        free(cwd);
    if (prompt)
        free(prompt);
    if (data->envp)
        free_env(data->envp);
}

int is_built_in(char **args, char **envp)
{
    if (ft_strcmp(args[0], "pwd") == 0)
        return (ft_pwd());
    else if (ft_strcmp(args[0], "echo") == 0)
        return (ft_echo(args));
    else if (ft_strcmp(args[0], "env") == 0)
        return (ft_env(envp));
    return (0);
}

int main(int argc, char **argv, char **envp)
{
    char *cwd;
    char *prompt;
	t_data data;
    t_command *aux;

	(void)argc;
	(void)argv;
    initialize_data(&data, envp);
    while(1)
    {
        cwd = getcwd(NULL, 0);
        prompt = ft_strjoin(cwd, "$ minishell> ");
        data.input_line = readline(prompt);
        if (!data.input_line)
        {
            cleanup_iteration(&data, cwd, prompt);
            break ;
        }
        add_history(data.input_line);
		lexer(&data);
        parser(&data);
        aux = data.commands;
        while (aux) //Aqui imagino que tendras que recorrer los comandos para ejecutarlos, no se
        { //He hecho esto para comprobar si alguno de los comandos es un built in
            is_built_in(aux->args, data.envp);
            aux = aux->next;
        }
        cleanup_iteration(&data, cwd, prompt);
    }
    return (0);
}
