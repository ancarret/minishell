/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarret <ancarret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 11:06:35 by ancarret          #+#    #+#             */
/*   Updated: 2025/07/07 10:50:45 by ancarret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void initialize_data(t_data *data)
{
    data->commands = NULL;
    data->input_line = NULL;
    data->tokens = NULL;
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
}

void is_built_in(char **args)
{
    if (ft_strcmp(args[0], "pwd") == 0)
        return (ft_pwd());
}

int main(int argc, char **argv, char **envp)
{
    char *cwd;
    char *prompt;
	t_data data;
    t_command *aux;

	(void)argc;
	(void)argv;
	(void)envp;

    initialize_data(&data);
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
            is_built_in(aux->args);
            aux = aux->next;
        }
        cleanup_iteration(&data, cwd, prompt);
    }
    return (0);
}
