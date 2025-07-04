/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarret <ancarret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 08:50:16 by ancarret          #+#    #+#             */
/*   Updated: 2025/06/09 14:40:00 by ancarret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_command *create_command(void)
{
    t_command *new_node;

    new_node = malloc(sizeof(t_command));
    if (!new_node)
        return (NULL);
    new_node->args = NULL;
    new_node->infile = NULL;
    new_node->outfile = NULL;
    new_node->append = 0;
    new_node->heredoc_limiter = NULL;
    new_node->next = NULL;
    return (new_node);
}

void add_command(t_command **commands, t_command *new_node)
{
    t_command *aux;

    if (*commands == NULL)
    {
        *commands = new_node;
        return ;
    }
    aux = *commands;
    while (aux->next != NULL)
        aux = aux->next;
    aux->next = new_node;
}

void free_array(char **array)
{
    int i;

    i = 0;
    while (array[i])
        free(array[i++]);
    free(array);
}

void free_commands(t_command *cmd)
{
    t_command *tmp;
    while (cmd)
    {
        tmp = cmd->next;
        if (cmd->args)
            free_array(cmd->args);
        if (cmd->infile)
            free(cmd->infile);
        if (cmd->outfile)
            free(cmd->outfile);
        if (cmd->heredoc_limiter)
            free(cmd->heredoc_limiter);
        if (cmd)
            free(cmd);
        cmd = tmp;
    }
}