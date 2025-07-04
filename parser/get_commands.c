/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarret <ancarret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 09:00:16 by ancarret          #+#    #+#             */
/*   Updated: 2025/06/09 14:28:48 by ancarret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int count_args(t_token *tokens)
{
    t_token *aux;
    int count;

    aux = tokens;
    count = 0;
    if (aux->type != TOKEN_WORD)
        aux = aux->next->next;
    while (aux && aux->type == TOKEN_WORD)
    {
        count++;
        aux = aux->next;
    }
    return (count);
}

t_command *get_next_command(t_data *data, int reset)
{
    int num_args;
    int i;
    t_command *command;
    static t_token *aux;

    if (reset)
        aux = data->tokens;
    if (!aux)
        return (NULL);
    command = create_command();
    num_args = count_args(aux);
    command->args = malloc(sizeof(char *) * (num_args + 1));
    i = 0;
    if (!command->args)
        return (NULL);
    while (aux && aux->type != TOKEN_PIPE)
    {
        if (aux->type == TOKEN_WORD)
            command->args[i++] = ft_strdup(aux->value);
        if (aux->type == TOKEN_REDIRECT_INPUT)
        {
            command->infile = ft_strdup(aux->next->value);
            aux = aux->next;
        }
        else if (aux->type == TOKEN_REDIRECT_OUTPUT)
        {
            command->outfile = ft_strdup(aux->next->value);
            aux = aux->next;
        }
        else if (aux->type == TOKEN_APPEND)
        {
            command->append = 1;
            aux = aux->next;
        }
        else if (aux->type == TOKEN_HEREDOC)
        {
            command->heredoc_limiter = ft_strdup(aux->next->value);
            aux = aux->next;
        }
        aux = aux->next;
    }
    if (aux && aux->type == TOKEN_PIPE)
        aux = aux->next;
    command->args[i] = NULL;
    return (command);
}
