/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarret <ancarret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 08:56:03 by ancarret          #+#    #+#             */
/*   Updated: 2025/07/09 16:09:08 by ancarret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void print_command(t_command *commands)
{
    t_command *aux;
    int i;

    aux = commands;
    while (aux)
    {
        i = 0;
        printf("Command:\n");
        while (aux->args && aux->args[i])
        {
            printf("  Arg[%d]: %s\n", i, aux->args[i]);
            i++;
        }
        if (aux->infile)
            printf("  Infile: %s\n", aux->infile);
        if (aux->outfile)
            printf("  Outfile: %s\n", aux->outfile);
        if (aux->append)
            printf("  Append: %d\n", aux->append);
        if (aux->heredoc_limiter)
            printf("  Heredoc: %s\n", aux->heredoc_limiter);
        printf("\n");
        aux = aux->next;
    }
}

void parser(t_data *data)
{
    t_command *command;
    int reset;

    if (data->commands)
    {
        free_commands(data->commands);
        data->commands = NULL;
    }  
    reset = 1;
    while ((command = get_next_command(data, reset)) != NULL)
    {
        add_command(&data->commands, command);
        reset = 0;
    }
    //print_command(data->commands);
}