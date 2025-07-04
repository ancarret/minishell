/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarret <ancarret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 08:00:36 by ancarret          #+#    #+#             */
/*   Updated: 2025/06/06 12:17:47 by ancarret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void print_tokens(t_token *tokens)
{
    t_token *aux;

    aux = tokens;
    while(aux != NULL)
    {
        printf("%s --- Tipo: %u\n", aux->value, aux->type);
        aux = aux->next;
    }
}

void lexer(t_data *data)
{
    t_token *token;
    int reset;

    if (data->tokens)
    {
        free_tokens(data->tokens);
        data->tokens = NULL;
    }  
    reset = 1;
    while ((token = get_next_token(data->input_line, reset)) != NULL)
    {
        add_token(&data->tokens, token);
        reset = 0;
    }
    //print_tokens(data->tokens);
}
