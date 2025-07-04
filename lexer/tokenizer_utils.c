/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancarret <ancarret@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 08:45:29 by ancarret          #+#    #+#             */
/*   Updated: 2025/06/04 10:52:36 by ancarret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_token *create_token(char *value, t_token_type type)
{
    t_token *new_node;

    new_node = malloc(sizeof(t_token));
    if (!new_node)
        return (NULL);
    new_node->value = value;
    new_node->type = type;
    new_node->next = NULL;
    return (new_node);
}

void add_token(t_token **tokens, t_token *new_node)
{
    t_token *aux;

    if (*tokens == NULL)
    {
        *tokens = new_node;
        return ;
    }
    aux = *tokens;
    while (aux->next != NULL)
        aux = aux->next;
    aux->next = new_node;
}

void free_tokens(t_token *tokens)
{
    t_token *current;
    t_token *next;

    current = tokens;
    while (current != NULL)
    {
        next = current->next;
        free(current->value);
        free(current);
        current = next;
    }
}

int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v'
		|| c == '\f');
}

int is_token_breaker(char c)
{
    return (is_space(c) || c == '\'' || c == '"' || c == '|' || c == '<' 
        || c == '>' || c == '\0');
}